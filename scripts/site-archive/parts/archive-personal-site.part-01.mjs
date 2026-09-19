ir(`${OUT}/discovery`);
  for (let i = 0; i < probes.length; i++) {
    try {
      const r = await fetch(probes[i], { redirect: 'follow' });
      const text = await r.text();
      await fs.writeFile(`${OUT}/discovery/probe-${String(i + 1).padStart(2,'0')}.txt`, text);
      for (const m of text.matchAll(/https?:\/\/[^\s<>'"]+/g)) enqueue(m[0].replace(/&amp;/g, '&'));
    } catch (e) { failures.push({ stage: 'discovery', url: probes[i], error: String(e) }); }
  }
  [
    '/', '/work', '/works', '/teaching', '/studies', '/about', '/passions', '/curriculum-vitae', '/backpic', '/project-management',
    '/studies/exam-list', '/studies/thesis-eng', '/works/sketchup-projects', '/works/photos', '/works/java-app-for-view-management'
  ].forEach(p => enqueue(p));
}
async function saveResource(response) {
  try {
    const req = response.request(), type = req.resourceType();
    if (type === 'font' || !response.ok()) return;
    const url = response.url();
    if (!/^https?:/.test(url) || resources.has(url)) return;
    const body = await response.body();
    if (!body.length || body.length > 20 * 1024 * 1024) return;
    const id = hash(body), file = `resources/${id}${ext(response.headers()['content-type'], url)}`;
    resources.set(url, { url, file, bytes: body.length, sha256: id, contentType: response.headers()['content-type'] || '', type });
    await mkdir(path.join(OUT, 'resources'));
    await fs.writeFile(path.join(OUT, file), body);
  } catch {}
}
async function settle(page) {
  await page.waitForLoadState('domcontentloaded').catch(() => {});
  await page.waitForLoadState('networkidle', { timeout: 10000 }).catch(() => {});
  for (const name of [/reject all/i,/rifiuta tutto/i,/decline/i,/no thanks/i]) {
    const b = page.getByRole('button', { name }).first();
    if (await b.isVisible({ timeout: 250 }).catch(() => false)) { await b.click().catch(() => {}); break; }
  }
  await page.evaluate(async () => {
    for (let i = 0, last = 0, stable = 0; i < 120 && stable < 4; i++) {
      const h = Math.max(document.body?.scrollHeight || 0, document.documentElement.scrollHeight || 0);
      window.scrollTo(0, Math.min(h, window.scrollY + Math.max(700, innerHeight * .85)));
      await new Promise(r => setTimeout(r, 75));
      stable = h === last && scrollY + innerHeight >= h - 5 ? stable + 1 : 0; last = h;
    }
    window.scrollTo(0,0); await new Promise(r => setTimeout(r, 200));
  }).catch(() => {});
}
async function data(page) {
  return page.evaluate(() => {
    const abs = x => { try { return new URL(x, document.baseURI).href; } catch { return x || ''; } };
    const links = [...document.querySelectorAll('a[href]')].map(a => ({ href: abs(a.getAttribute('href')), text: (a.innerText || a.textContent || '').trim() }));
    return {
      title: document