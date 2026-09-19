# Restore guide

This is a public, reconstruction-oriented snapshot of https://www.lorenzomontarese.com/ captured on 2026-09-19.

## Recovery order

1. Read `SITE_MAP.md` and every `pages/*/content.md`.
2. Recreate navigation, page hierarchy and copy in Google Sites or another CMS.
3. Use desktop/mobile full-page screenshots as the visual reference.
4. Use `rendered.html` and `source.html` for markup, embeds and link recovery.
5. Match network resources through `resources.json`; files are stored by SHA-256 in `resources/`.
6. Verify the archive with `sha256sum -c checksums.sha256`.

## Boundary

This preserves the published public site, not Google Sites' private editor state, permissions, revision history or unpublished drafts. Those require a native Google Sites copy or Google Takeout. Font binaries are intentionally excluded.
