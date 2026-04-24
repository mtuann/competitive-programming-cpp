import json
import subprocess
import tempfile
import unittest
from pathlib import Path

import scripts.generate_problem_catalog as gpc


def write_json(path: Path, payload) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(payload, indent=2) + "\n", encoding="utf-8")


def write_text(path: Path, text: str) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text, encoding="utf-8")


class GenerateProblemCatalogTests(unittest.TestCase):
    def setUp(self) -> None:
        self.original_root = gpc.ROOT
        self.tempdir = tempfile.TemporaryDirectory()
        self.root = Path(self.tempdir.name)
        self.addCleanup(self.tempdir.cleanup)
        self.addCleanup(gpc.configure_repo_root, self.original_root)

    def configure_repo(self) -> None:
        gpc.configure_repo_root(self.root)

    def minimal_topic_resources(self) -> dict:
        return {
            "foundations/cpp-language": {
                "title": "Foundations -> C++ Language",
                "topic_path": "topics/foundations/cpp-language/README.md",
                "ladder_path": "practice/ladders/foundations/cpp-language/README.md",
                "microtopics": [],
                "learning_sources": [],
                "practice_sources": [],
            }
        }

    def minimal_note_text(self, *, include_main_topic: bool = False) -> str:
        lines = [
            "# Demo Problem",
            "",
            "- Title: `DEMO - Demo Problem`",
            "- Judge / source: `CSES`",
            "- Original URL: [https://example.com/problem](https://example.com/problem)",
            "- Secondary topics: `Warm-up`",
            "- Difficulty: `easy`",
            "- Status: `solved`",
            "- Solution file: [demo.cpp](https://example.com/demo.cpp)",
        ]
        if include_main_topic:
            lines.append("- Main topic: `Manual Value`")
        lines += [
            "",
            "## Why Practice This",
            "",
            "Tiny fixture note.",
        ]
        return "\n".join(lines) + "\n"

    def prepare_minimal_repo(self, *, include_main_topic: bool = False) -> Path:
        note_path = self.root / "practice" / "ladders" / "foundations" / "cpp-language" / "demo.md"
        write_text(note_path, self.minimal_note_text(include_main_topic=include_main_topic))
        write_text(self.root / "practice" / "ladders" / "foundations" / "cpp-language" / "README.md", "# Ladder\n")
        write_text(self.root / "topics" / "foundations" / "cpp-language" / "README.md", "# Topic\n")
        write_json(self.root / "data" / "topic-resources.json", self.minimal_topic_resources())
        write_json(self.root / "data" / "problem-overrides.json", {"DEMO": {"topic_tags": [], "patterns": [], "tracks": []}})
        write_json(self.root / "data" / "external-problem-pools.json", {"foundations/cpp-language": []})
        return note_path

    def test_parse_metadata_stops_at_first_section_heading(self) -> None:
        path = self.root / "note.md"
        write_text(
            path,
            "\n".join(
                [
                    "- Title: `DEMO - Demo`",
                    "- Judge / source: `CSES`",
                    "## Why Practice This",
                    "- Difficulty: `should not be read`",
                ]
            )
            + "\n",
        )

        meta = gpc.parse_metadata(path)
        self.assertEqual(meta["Title"], "DEMO - Demo")
        self.assertEqual(meta["Judge / source"], "CSES")
        self.assertNotIn("Difficulty", meta)

    def test_collect_note_records_rejects_deprecated_main_topic_field(self) -> None:
        self.configure_repo()
        self.prepare_minimal_repo(include_main_topic=True)

        topic_resources = gpc.load_json(gpc.TOPIC_RESOURCES)
        issues: list[str] = []
        records = gpc.collect_note_records(topic_resources, issues)

        self.assertEqual(len(records), 1)
        self.assertTrue(any("deprecated metadata field 'Main topic'" in issue for issue in issues))

    def test_build_problem_rows_uses_canonical_topic_title(self) -> None:
        self.configure_repo()
        self.prepare_minimal_repo(include_main_topic=False)

        rows = gpc.build_problem_rows()

        self.assertEqual(len(rows), 1)
        self.assertEqual(rows[0]["code"], "DEMO")
        self.assertEqual(rows[0]["primary_slug"], "foundations/cpp-language")
        self.assertEqual(rows[0]["main_topic"], "Foundations -> C++ Language")

    def test_check_detects_untracked_generated_outputs(self) -> None:
        self.configure_repo()
        subprocess.run(["git", "init"], cwd=self.root, check=True, capture_output=True, text=True)
        write_text(gpc.PROBLEM_JSON, "[]\n")

        with self.assertRaises(gpc.ValidationError) as ctx:
            gpc.ensure_generated_outputs_are_in_sync()

        self.assertIn("untracked files", str(ctx.exception).lower())
        self.assertIn("data/problem-catalog.json", str(ctx.exception))


if __name__ == "__main__":
    unittest.main()
