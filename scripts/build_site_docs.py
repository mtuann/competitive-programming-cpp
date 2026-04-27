from pathlib import Path
import shutil


ROOT = Path(__file__).resolve().parents[1]
SITE_DOCS = ROOT / "site-docs"

STATIC_FILES = {
    "README.md": "project-readme.md",
    "docs/site-home.md": "index.md",
    "template-library.md": "template-library.md",
}

DIRECTORIES = [
    "data",
    "docs",
    "topics",
    "practice",
    "notebook",
    "templates",
]

ASSET_DIRECTORIES = {
    "docs-assets/stylesheets": "assets/stylesheets",
    "docs-assets/javascripts": "assets/javascripts",
}


def copy_file(src_rel: str, dst_rel: str) -> None:
    src = ROOT / src_rel
    dst = SITE_DOCS / dst_rel
    dst.parent.mkdir(parents=True, exist_ok=True)
    shutil.copy2(src, dst)


def main() -> None:
    if SITE_DOCS.exists():
        shutil.rmtree(SITE_DOCS)

    for src_rel, dst_rel in STATIC_FILES.items():
        copy_file(src_rel, dst_rel)

    for src_rel, dst_rel in ASSET_DIRECTORIES.items():
        shutil.copytree(ROOT / src_rel, SITE_DOCS / dst_rel)

    for directory in DIRECTORIES:
        src_dir = ROOT / directory
        dst_dir = SITE_DOCS / directory
        if directory == "docs":
            shutil.copytree(src_dir, dst_dir, ignore=shutil.ignore_patterns("site-home.md"))
        else:
            shutil.copytree(src_dir, dst_dir)


if __name__ == "__main__":
    main()
