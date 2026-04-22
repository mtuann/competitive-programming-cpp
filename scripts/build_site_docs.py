from pathlib import Path
import shutil


ROOT = Path(__file__).resolve().parents[1]
SITE_DOCS = ROOT / "site-docs"

# This mirrors the source markdown tree into `site-docs/`, which MkDocs uses
# as its docs root. Keep these paths aligned with `mkdocs.yml`.
FILES = {
    "README.md": "project-readme.md",
    "docs/site-home.md": "index.md",
    "docs/source-map.md": "docs/source-map.md",
    "docs/content-blueprint.md": "docs/content-blueprint.md",
    "docs/topic-template.md": "docs/topic-template.md",
    "topics/README.md": "topics/README.md",
    "topics/foundations/README.md": "topics/foundations/README.md",
    "topics/data-structures/README.md": "topics/data-structures/README.md",
    "topics/graphs/README.md": "topics/graphs/README.md",
    "topics/dp/README.md": "topics/dp/README.md",
    "topics/math/README.md": "topics/math/README.md",
    "topics/strings/README.md": "topics/strings/README.md",
    "topics/geometry/README.md": "topics/geometry/README.md",
    "topics/advanced/README.md": "topics/advanced/README.md",
    "practice/README.md": "practice/README.md",
    "practice/ladders/README.md": "practice/ladders/README.md",
    "practice/ladders/graphs/matching/qbflower.md": "practice/ladders/graphs/matching/qbflower.md",
    "practice/ladders/graphs/flow/fflow.md": "practice/ladders/graphs/flow/fflow.md",
    "practice/ladders/geometry/right-triangles/pravo.md": "practice/ladders/geometry/right-triangles/pravo.md",
    "practice/mixed-rounds/README.md": "practice/mixed-rounds/README.md",
    "practice/contest-playbooks/README.md": "practice/contest-playbooks/README.md",
    "template-library.md": "template-library.md",
    "notebook/README.md": "notebook/README.md",
    "docs-assets/stylesheets/extra.css": "assets/stylesheets/extra.css",
}


def main() -> None:
    if SITE_DOCS.exists():
        shutil.rmtree(SITE_DOCS)

    for src_rel, dst_rel in FILES.items():
        src = ROOT / src_rel
        dst = SITE_DOCS / dst_rel
        dst.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(src, dst)


if __name__ == "__main__":
    main()
