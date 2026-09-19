tringify(failures,null,2)+'\n```\n' : '## Failures\n\nNone.\n'].join('\n'));
  await fs.writeFile(`${OUT}/RESTORE.md`, `# Restore guide\n\nThis is a public, reconstruction-oriented snapshot of ${ROOT} captured on ${DATE}.\n\n## Recovery order\n\n1. Read \`SITE_MAP.md\` and every \`pages/*/content.md\`.\n2. Recreate navigation, page hierarchy and copy in Google Sites or another CMS.\n3. Use desktop/mobile full-page screenshots as the visual reference.\n4. Use \`rendered.html\` and \`source.html\` for markup, embeds and link recovery.\n5. Match network resources through \`resources.json\`; files are stored by SHA-256 in \`resources/\`.\n6. Verify the archive with \`sha256sum -c checksums.sha256\`.\n\n## Boundary\n\nThis preserves the published public site, not Google Sites' private editor state, permissions, revision history or unpublished drafts. Those require a native Google Sites copy or Google Takeout. Font binaries are intentionally excluded.\n`);
  await fs.writeFile(`${OUT}/README.md`, `# lorenzomontarese.com — public snapshot ${DATE}\n\n- Pages captured: **${results.length}**\n- Network resources archived (fonts excluded): **${inventory.length}**\n- Capture failures: **${failures.length}**\n- Per page: desktop/mobile full-page screenshot, rendered HTML, source HTML, extracted content and metadata.\n\nStart with [SITE_MAP.md](SITE_MAP.md), [RESTORE.md](RESTORE.md) and [manifest.json](manifest.json).\n`);
  await checksums(OUT);
  const indexPath = 'areas/personal-site/backups/README.md';
  await mkdir(path.dirname(indexPath));
  const index = `# Public-site backups\n\n- [${DATE} live snapshot](./${DATE}-live/README.md) — ${results.length} pages, ${inventory.length} non-font resources, ${failures.length} failures.\n`;
  await fs.writeFile(indexPath,index);
  const readmePath = 'areas/personal-site/README.md';
  let readme = await fs.readFile(readmePath,'utf8');
  const marker = '\n## Backup pubblico\n';
  const block = `\n## Backup pubblico\n\nSnapshot ricostruibile del sito pubblicato: [${DATE}](backups/${DATE}-live/README.md). Include struttura, testo, HTML, schermate desktop/mobile, risorse di rete non-font, manifest e checksum.\n`;
  readme = readme.includes(marker) ? readme.replace(/\n## Backup pubblico\n[\s\S]*?(?=\n## |$)/,block.trimEnd()) : readme.replace('\n## Decision\n',block+'\n## Decision\n');
  await fs.writeFile(readmePath,readme);
  console.log(JSON.stringify({ pageCount:results.length, resourceCount:inventory.length, failures:failures.length, output:OUT }));
}
main().catch(e => { console.error(e); process.exitCode=1; });
