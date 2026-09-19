n lines.join('\n');
}
async function checksums(dir) {
  const rows = [];
  async function walk(p) {
    for (const entry of await fs.readdir(p, { withFileTypes:true })) {
      const f = path.join(p, entry.name);
      if (entry.isDirectory()) await walk(f);
      else if (!f.endsWith('checksums.sha256')) { const b = await fs.readFile(f); rows.push(`${hash(b)}  ${path.relative(dir,f).replaceAll('\\','/')}`); }
    }
  }
  await walk(dir); rows.sort(); await fs.writeFile(path.join(dir,'checksums.sha256'), rows.join('\n') + '\n');
}
async function main() {
  await fs.rm(OUT, { recursive:true, force:true }); await mkdir(`${OUT}/pages`); await discover();
  const browser = await chromium.launch({ headless:true });
  while (queue.length && results.length < maxPages) {
    const url = queue.shift(); queued.delete(url); if (seen.has(url)) continue; seen.add(url);
    const dir = path.join(OUT,'pages',slug(url)); await mkdir(dir);
    try {
      const desktop = await capture(browser, false, url, dir);
      const mobile = await capture(browser, true, url, dir);
      for (const l of desktop.links) enqueue(l.href, desktop.finalUrl);
      const record = { url, slug:slug(url), status:desktop.status, finalUrl:desktop.finalUrl, title:desktop.title, textCharacters:desktop.text.length, links:desktop.links.length, images:desktop.images.length, embeds:desktop.embeds.length, desktop:desktop.dimensions, mobile:mobile.dimensions };
      results.push(record);
      await fs.writeFile(path.join(dir,'content.md'), markdown(desktop,url));
      await fs.writeFile(path.join(dir,'metadata.json'), JSON.stringify({ requestedUrl:url, capturedAt:new Date().toISOString(), desktop, mobile:{status:mobile.status,finalUrl:mobile.finalUrl,dimensions:mobile.dimensions} },null,2)+'\n');
      console.log(`[${results.length}] ${desktop.status} ${url} -> ${desktop.title}`);
    } catch (e) { failures.push({ stage:'capture', url, error:String(e?.stack || e) }); console.error(`FAIL ${url}`, e); }
  }
  await browser.close();
  const inventory = [...resources.values()].sort((a,b)=>a.url.localeCompare(b.url));
  await fs.writeFile(`${OUT}/resources.json`, JSON.stringify(inventory,null,2)+'\n');
  await fs.writeFile(`${OUT}/manifest.json`, JSON.stringify({ schema:'lorenzomontarese-public-site-backup/v1', root:ROOT, snapshotDate:DATE, capturedAt:new Date().toISOString(), pageCount:results.length, resourceCount:inventory.length, pages:results, failures },null,2)+'\n');
  await fs.writeFile(`${OUT}/urls.txt`, results.map(x=>x.url).join('\n')+'\n');
  await fs.writeFile(`${OUT}/SITE_MAP.md`, ['# Site map','',...results.sort((a,b)=>a.url.localeCompare(b.url)).map(x=>`- [${x.title || x.url}](${x.url}) — \`${x.slug}/\` — HTTP ${x.status}`),'', failures.length ? '## Failures\n\n```json\n'+JSON.s