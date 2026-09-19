import { chromium } from 'playwright';
import fs from 'node:fs/promises';
import path from 'node:path';
import crypto from 'node:crypto';

const ROOT = 'https://www.lorenzomontarese.com/';
const DATE = process.env.SNAPSHOT_DATE || new Date().toISOString().slice(0, 10);
const OUT = `areas/personal-site/backups/${DATE}-live`;
const host = new URL(ROOT).hostname.replace(/^www\./, '');
const maxPages = Number(process.env.MAX_PAGES || 250);
const results = [], failures = [], resources = new Map();
const queue = [], queued = new Set(), seen = new Set();

const mkdir = p => fs.mkdir(p, { recursive: true });
const hash = b => crypto.createHash('sha256').update(b).digest('hex');
const clean = s => String(s || '').replace(/\r/g, '').replace(/[\t\u00a0]+/g, ' ').replace(/ *\n/g, '\n').replace(/\n{3,}/g, '\n\n').trim();
const slug = u => {
  const p = new URL(u).pathname.replace(/^\/+|\/+$/g, '');
  return p ? p.split('/').map(x => x.normalize('NFKD').replace(/[\u0300-\u036f]/g, '').replace(/[^a-zA-Z0-9]+/g, '-').replace(/^-|-$/g, '').toLowerCase() || 'page').join('--') : 'home';
};
function normalize(value, base = ROOT) {
  try {
    let u = new URL(value, base);
    if (!/^https?:$/.test(u.protocol)) return null;
    const h = u.hostname.replace(/^www\./, '').toLowerCase();
    if (h === 'sites.google.com' && u.pathname.startsWith('/view/lorenzomontarese')) u = new URL(u.pathname.slice('/view/lorenzomontarese'.length) || '/', ROOT);
    else if (h !== host) return null;
    u.protocol = 'https:'; u.hostname = `www.${host}`; u.port = ''; u.hash = '';
    for (const k of [...u.searchParams.keys()]) if (/^utm_/i.test(k) || ['gclid','fbclid','authuser'].includes(k)) u.searchParams.delete(k);
    if (u.pathname.length > 1) u.pathname = u.pathname.replace(/\/+$/, '');
    if (/\.(pdf|docx?|pptx?|xlsx?|zip|jpe?g|png|gif|webp|svg|mp4|mp3)$/i.test(u.pathname)) return null;
    return u.href;
  } catch { return null; }
}
function enqueue(value, base) {
  const u = normalize(value, base);
  if (u && !queued.has(u) && !seen.has(u) && queued.size < maxPages * 4) { queued.add(u); queue.push(u); }
}
function ext(type, url) {
  const t = (type || '').split(';')[0];
  const byType = {'image/jpeg':'.jpg','image/png':'.png','image/gif':'.gif','image/webp':'.webp','image/svg+xml':'.svg','text/css':'.css','text/javascript':'.js','application/javascript':'.js','application/json':'.json','application/pdf':'.pdf'};
  return byType[t] || (new URL(url).pathname.match(/\.[a-z0-9]{1,6}$/i)?.[0] || '.bin');
}
async function discover() {
  const probes = [
    new URL('/robots.txt', ROOT).href,
    new URL('/sitemap.xml', ROOT).href,
    'https://sites.google.com/view/lorenzomontarese/sitemap.xml',
    'https://sites.google.com/site/lorenzomontarese/system/feeds/sitemap/',
  ];
  await mkd