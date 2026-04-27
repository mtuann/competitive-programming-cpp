from __future__ import annotations

from pathlib import Path
import subprocess
import sys


ROOT = Path(__file__).resolve().parents[1]
SOURCE_DIR = ROOT / "docs-assets" / "mermaid"
OUTPUT_DIR = ROOT / "docs" / "assets" / "figures" / "mermaid"
MERMAID_CLI_VERSION = "11.12.0"


def render_file(source: Path, output: Path) -> None:
    output.parent.mkdir(parents=True, exist_ok=True)
    cmd = [
        "npx",
        "-y",
        f"@mermaid-js/mermaid-cli@{MERMAID_CLI_VERSION}",
        "-i",
        str(source),
        "-o",
        str(output),
        "-t",
        "neutral",
        "-b",
        "transparent",
    ]
    subprocess.run(cmd, check=True)


def main() -> int:
    if not SOURCE_DIR.exists():
        print(f"No Mermaid source directory found at {SOURCE_DIR}")
        return 0

    sources = sorted(SOURCE_DIR.rglob("*.mmd"))
    if not sources:
        print(f"No Mermaid source files found under {SOURCE_DIR}")
        return 0

    for source in sources:
        relative = source.relative_to(SOURCE_DIR).with_suffix(".svg")
        render_file(source, OUTPUT_DIR / relative)
        print(f"Rendered {relative}")

    return 0


if __name__ == "__main__":
    sys.exit(main())
