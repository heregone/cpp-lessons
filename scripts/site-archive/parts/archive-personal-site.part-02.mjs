.title, language: document.documentElement.lang || '', canonical: document.querySelector('link[rel=canonical]')?.href || '',
      description: document.querySelector('meta[name=description]')?.content || '',
      headings: [...document.querySelectorAll('h1,h2,h3,h4,h5,h6')].map(h => ({ level: Number(h.tagName.slice(1)), text: (h.innerText || '').trim() })).filter(x => x.text),
      text: (document.querySelector('main,[role=main]')?.innerText || document.body?.innerText || '').trim(), links,
      images: [...document.images].map(i => ({ src: abs(i.currentSrc || i.src), alt: i.alt || '', width: i.naturalWidth, height: i.naturalHeight })),
      embeds: [...document.querySelectorAll('iframe,video[src],audio[src],source[src]')].map(e => ({ tag: e.tagName.toLowerCase(), src: abs(e.src || e.getAttribute('src')) })),
      dimensions: { width: innerWidth, height: innerHeight, scrollWidth: Math.max(document.body?.scrollWidth || 0, document.documentElement.scrollWidth || 0), scrollHeight: Math.max(document.body?.scrollHeight || 0, document.documentElement.scrollHeight || 0) }
    };
  });
}
async function capture(browser, mobile, url, dir) {
  const ctx = await browser.newContext(mobile ? { viewport:{width:390,height:844}, deviceScaleFactor:1, isMobile:true, hasTouch:true } : { viewport:{width:1440,height:900}, deviceScaleFactor:1 });
  const page = await ctx.newPage();
  page.on('response', saveResource);
  const response = await page.goto(url, { waitUntil:'domcontentloaded', timeout:60000 });
  await settle(page);
  const info = await data(page);
  await fs.writeFile(path.join(dir, mobile ? 'mobile-full.jpg' : 'desktop-full.jpg'), await page.screenshot({ fullPage:true, type:'jpeg', quality:78, animations:'disabled', caret:'hide', timeout:90000 }));
  if (!mobile) {
    await fs.writeFile(path.join(dir, 'rendered.html'), await page.content());
    const raw = await fetch(url, { redirect:'follow' }).then(r => r.text()).catch(() => '');
    await fs.writeFile(path.join(dir, 'source.html'), raw);
  }
  const out = { status: response?.status() || null, finalUrl: page.url(), ...info };
  await ctx.close();
  return out;
}
function markdown(info, url) {
  const lines = [`# ${info.title || url}`, '', `- URL: ${url}`, `- Final URL: ${info.finalUrl}`, `- HTTP: ${info.status}`, `- Captured: ${new Date().toISOString()}`, ''];
  if (info.headings.length) { lines.push('## Structure','',...info.headings.map(h => `${'  '.repeat(Math.max(0,h.level-1))}- H${h.level}: ${h.text}`),''); }
  lines.push('## Visible text','',clean(info.text) || '_No visible text extracted._','', '## Links','', ...info.links.map(l => `- [${clean(l.text) || l.href}](${l.href})`), '');
  if (info.embeds.length) lines.push('## Embeds','',...info.embeds.map(e => `- ${e.tag}: ${e.src}`),'');
  retur