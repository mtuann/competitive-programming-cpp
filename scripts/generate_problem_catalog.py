from __future__ import annotations

import csv
import json
import re
from collections import Counter, defaultdict
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
NOTES_ROOT = ROOT / "practice" / "ladders"
DATA_DIR = ROOT / "data"
DOCS_DIR = ROOT / "docs"

PROBLEM_OVERRIDES = DATA_DIR / "problem-overrides.json"
TOPIC_RESOURCES = DATA_DIR / "topic-resources.json"
EXTERNAL_PROBLEM_POOLS = DATA_DIR / "external-problem-pools.json"

PROBLEM_JSON = DATA_DIR / "problem-catalog.json"
EXTERNAL_PROBLEM_JSON = DATA_DIR / "external-problem-catalog.json"
OUTPUT_CSV = DOCS_DIR / "repo-problem-catalog.csv"
OUTPUT_MD = DOCS_DIR / "problem-index.md"
EXTERNAL_OUTPUT_CSV = DOCS_DIR / "external-problem-catalog.csv"
EXTERNAL_OUTPUT_MD = DOCS_DIR / "external-problem-index.md"
TOPIC_MAPS_DIR = DOCS_DIR / "topic-maps"
TOPIC_MAPS_INDEX = TOPIC_MAPS_DIR / "index.md"


AREA_ORDER = [
    "foundations",
    "data-structures",
    "graphs",
    "dp",
    "greedy",
    "math",
    "combinatorics",
    "strings",
    "geometry",
    "advanced",
]

AREA_LABELS = {
    "foundations": "Foundations",
    "data-structures": "Data Structures",
    "graphs": "Graphs",
    "dp": "DP",
    "greedy": "Greedy",
    "math": "Math",
    "combinatorics": "Combinatorics",
    "strings": "Strings",
    "geometry": "Geometry",
    "advanced": "Advanced",
}

BUCKET_ORDER = [
    "warm-up",
    "core",
    "practice",
    "variants",
    "classic",
    "stretch",
    "advanced",
    "challenge",
    "cross-topic",
    "theory",
]

BUCKET_LABELS = {
    "warm-up": "Warm-Up",
    "core": "Core",
    "practice": "Practice",
    "variants": "Variants",
    "classic": "Classics",
    "stretch": "Stretch",
    "advanced": "Advanced",
    "challenge": "Challenge",
    "cross-topic": "Cross-Topic",
    "theory": "Theory / Course",
}

LADDER_TO_TUTORIAL_OVERRIDES = {
    "math/gcd-lcm": "topics/math/number-theory-basics/README.md",
    "math/fft": "topics/math/fft-ntt/README.md",
    "geometry/right-triangles": "topics/geometry/counting-geometry/README.md",
    "graphs/tree-dp": "topics/dp/tree-dp/README.md",
    "dp/sliding-window": "topics/foundations/patterns/two-pointers/README.md",
    "greedy/prefix-constraints": "",
}

METADATA_RE = re.compile(r"^- ([^:]+):\s*(.*)$")
MD_LINK_RE = re.compile(r"\[([^\]]+)\]\(([^)]+)\)")


SOURCE_ALIASES = {
    "csesproblemset": "CSES",
    "atcodereducationaldpcontest": "AtCoder DP Contest",
    "uvaonlinejudge": "UVa",
}

BUCKET_ALIASES = {
    "warmup": "warm-up",
    "warm-up": "warm-up",
    "warm up": "warm-up",
    "classics": "classic",
    "variant": "variants",
}

WORD_LABEL_OVERRIDES = {
    "#p": "#P",
    "1d": "1D",
    "2d": "2D",
    "apsp": "APSP",
    "bfs": "BFS",
    "cses": "CSES",
    "cf": "CF",
    "dag": "DAG",
    "dfs": "DFS",
    "dp": "DP",
    "dsu": "DSU",
    "fft": "FFT",
    "gcd": "GCD",
    "hld": "HLD",
    "imo": "Imos",
    "imos": "Imos",
    "inf": "INF",
    "kmp": "KMP",
    "lca": "LCA",
    "lcm": "LCM",
    "lcp": "LCP",
    "lcs": "LCS",
    "lp": "LP",
    "mst": "MST",
    "ntt": "NTT",
    "pcp": "PCP",
    "pspace": "PSPACE",
    "ptas": "PTAS",
    "sat": "SAT",
    "scc": "SCC",
    "sssp": "SSSP",
    "stl": "STL",
    "tsp": "TSP",
    "uva": "UVa",
    "xor": "XOR",
    "mos": "Mo's",
}

TRACK_ALIASES = {
    "binarysearch": "binary search",
    "bipartitematching": "bipartite matching",
    "countingdp": "counting dp",
    "dagdp": "dag dp",
    "dictionarymatching": "dictionary matching",
    "distinctsubstrings": "distinct substrings",
    "dsuontree": "dsu on tree",
    "dynamicqueries": "dynamic queries",
    "gcdlcm": "gcd/lcm",
    "grids": "grid",
    "modarithmetic": "mod arithmetic",
    "griddp": "grid dp",
    "librarychecker": "library checker",
    "lineardp": "linear dp",
    "multisetpermutations": "multiset permutations",
    "numbertheory": "number theory",
    "pathreconstruction": "path reconstruction",
    "pathmaxquery": "path max query",
    "prefixsumdp": "prefix dp",
    "rankunrank": "permutation ranking",
    "rankunrankcounting": "ranking and counting",
    "rankingunranking": "permutation ranking",
    "rollinghash": "rolling hash",
    "segmenteddp": "segmented dp",
    "shortestpaths": "shortest paths",
    "statedp": "state dp",
    "subsetsum": "subset sum",
    "stringdp": "string dp",
    "substringcomparison": "substring comparison",
    "treedp": "tree dp",
}

STYLE_ALIASES = {
    "datastructures": "data-structure-heavy",
    "divideandconquer": "divide-and-conquer",
    "dynamicdatastructures": "dynamic data structures",
    "numbertheory": "number theory",
    "sweepline": "sweep-line",
    "twopointers": "two-pointers",
}

TAG_ALIASES = {
    "2dprefixsum": "2d prefix sums",
    "2dprefixsums": "2d prefix sums",
    "benchmark": "verification",
    "differencearray": "difference array",
    "dynamicprogramming": "dp",
    "failurelinks": "failure links",
    "factorialnumbersystem": "factoradic",
    "factoradics": "factoradic",
    "fenwicktree": "fenwick",
    "flows": "flow",
    "groupaction": "group actions",
    "mosalgorithm": "mos algorithm",
    "multiplepatterns": "multi-pattern matching",
    "multisetpermutations": "multiset permutations",
    "mod1e97": "mod arithmetic",
    "modulo": "mod arithmetic",
    "palindromes": "palindrome",
    "permutationranking": "permutation ranking",
    "permutation": "permutations",
    "permutationsofmultiset": "multiset permutations",
    "permutationswithduplicates": "duplicate permutations",
    "pathreconstruction": "path reconstruction",
    "rootedtrees": "rooted tree",
    "segmenttree": "segment tree",
    "substringhash": "substring comparison",
    "sweepline": "sweep line",
    "textscan": "text scanning",
    "trieorhash": "hash or trie",
    "valuemaximize": "value maximization",
    "valuemaximization": "value maximization",
}

PREREQUISITE_ALIASES = {
    "euclidsalgorithm": "euclid's algorithm",
    "failurelinks": "failure links",
    "gcdlcmbasics": "gcd/lcm basics",
    "hashmaps": "hash maps",
    "lexicographiccomparison": "lexicographic order",
    "lexicographicordering": "lexicographic order",
    "modarithmetic": "modular arithmetic",
    "moduloarithmetic": "modular arithmetic",
    "modulobasics": "modular arithmetic",
    "modularreduction": "modular arithmetic",
    "multisethandling": "multisets",
    "outputlinkpropagation": "output links",
    "pointupdates": "point updates",
    "prefixfunction": "prefix function",
    "rootedtrees": "rooted tree",
    "setmapdedup": "set or map deduplication",
    "subsetsums": "subset sum",
    "treerooting": "rooted tree",
}

GENERIC_CONTEXT_KEYS = {
    "course",
    "intro",
    "verification",
}

GENERIC_TAG_KEYS = {
    "benchmark",
    "constraints",
    "official",
    "practice",
    "reference",
    "verification",
}

TAG_REDUNDANCY_EXCEPTIONS_BY_SLUG = {
    "combinatorics/counting-basics": {"derangements"},
    "math/gcd-lcm": {"euclid", "gcd", "lcm"},
}

CONTEXT_SUPPRESSION_BY_SLUG = {
    "data-structures/heaps-and-ordered-sets": {"ordered set"},
    "foundations/complexity-and-invariants": {"greedy"},
    "foundations/sorting": {"greedy"},
    "graphs/flow": {"flow", "max flow"},
    "graphs/gomory-hu": {"flow"},
    "graphs/hld": {"trees"},
    "graphs/lca": {"trees"},
    "graphs/min-cost-flow": {"flow"},
    "graphs/mst": {"trees"},
    "graphs/tree-dp": {"trees"},
}

DIFFICULTY_LABELS = {
    "easy": "Easy",
    "easy-medium": "Easy-Medium",
    "medium": "Medium",
    "medium-hard": "Medium-Hard",
    "hard": "Hard",
    "very-hard": "Very Hard",
    "theory": "Theory",
}

DIFFICULTY_ORDER = [
    "easy",
    "easy-medium",
    "medium",
    "medium-hard",
    "hard",
    "very-hard",
    "theory",
]


def clean_value(value: object) -> str:
    if value is None:
        return ""
    return str(value).strip().replace("`", "").strip()


def split_csvish(value: str) -> list[str]:
    if not value:
        return []
    return [part.strip() for part in value.split(",") if part.strip()]


def unique(items: list[str]) -> list[str]:
    seen: set[str] = set()
    out: list[str] = []
    for item in items:
        if item and item not in seen:
            seen.add(item)
            out.append(item)
    return out


def comparison_key(value: object) -> str:
    text = clean_value(value).lower()
    text = text.replace("&", " and ")
    return re.sub(r"[^a-z0-9]+", "", text)


def normalize_phrase(value: object, aliases: dict[str, str] | None = None) -> str:
    text = clean_value(value)
    if not text or text.lower() == "none":
        return ""
    text = text.replace("_", " ")
    text = re.sub(r"\s+", " ", text).strip()
    if aliases:
        alias = aliases.get(comparison_key(text))
        if alias:
            return alias
    return text.lower()


def format_display_label(value: object) -> str:
    text = clean_value(value)
    if not text:
        return ""

    parts = re.split(r"([ /+-])", text)
    out: list[str] = []
    for part in parts:
        if not part:
            continue
        if re.fullmatch(r"[ /+-]", part):
            out.append(part)
            continue
        token = part.lower()
        out.append(WORD_LABEL_OVERRIDES.get(token, token.capitalize()))
    return re.sub(r"\s+", " ", "".join(out)).strip()


def normalize_descriptor_list(
    items: list[str], *, aliases: dict[str, str] | None = None, humanize: bool = False
) -> list[str]:
    out: list[str] = []
    seen: set[str] = set()
    for item in items:
        canonical = normalize_phrase(item, aliases)
        key = comparison_key(canonical)
        if not key or key in seen:
            continue
        seen.add(key)
        out.append(format_display_label(canonical) if humanize else canonical)
    return out


def descriptor_redundant_keys(slug: str, source: str = "", extra_labels: list[str] | None = None) -> set[str]:
    area, subtopic = slug.split("/", 1)
    words = [word for word in re.split(r"[-/ ]+", f"{area} {subtopic}") if word]
    keys = {
        comparison_key(area),
        comparison_key(subtopic),
        comparison_key(subtopic.replace("-", " ")),
        comparison_key(slug),
        comparison_key(slug.replace("/", " ")),
        comparison_key(source),
    }
    for word in words:
        keys.add(comparison_key(word))
        if word.endswith("s"):
            keys.add(comparison_key(word[:-1]))
        else:
            keys.add(comparison_key(word + "s"))

    for label in extra_labels or []:
        keys.add(comparison_key(label))

    return keys


def normalize_source(value: object) -> str:
    text = clean_value(value)
    if not text:
        return ""
    if re.fullmatch(r"Codeforces\s+\d+[A-Z]?", text):
        return "Codeforces"
    return SOURCE_ALIASES.get(comparison_key(text), text)


def normalize_bucket(value: object) -> str:
    text = clean_value(value).lower()
    if not text or text == "none":
        return "core"

    text = text.replace("_", " ")
    text = re.sub(r"\s+", " ", text).strip()
    aliased = BUCKET_ALIASES.get(text)
    if aliased:
        return aliased

    slug = re.sub(r"[^a-z0-9]+", "-", text).strip("-")
    return slug or "core"


def normalize_difficulty(value: object) -> str:
    text = clean_value(value).lower()
    if not text or text == "none":
        return ""

    rating_match = re.search(r"\b(\d{3,4})\b", text)
    if rating_match:
        rating = int(rating_match.group(1))
        if rating <= 1200:
            return "easy"
        if rating <= 1600:
            return "medium"
        if rating <= 1800:
            return "medium-hard"
        if rating <= 2100:
            return "hard"
        return "very-hard"

    text = text.replace("_", " ")
    text = re.sub(r"\s+", " ", text).strip()
    aliases = {
        "very easy": "easy",
        "easy medium": "easy-medium",
        "normal": "medium",
        "medium hard": "medium-hard",
        "very hard": "very-hard",
        "advanced": "very-hard",
        "theory": "theory",
    }
    aliased = aliases.get(text, text)
    return aliased.replace(" ", "-")


def difficulty_sort_key(difficulty: str) -> tuple[int, str]:
    if difficulty in DIFFICULTY_ORDER:
        return DIFFICULTY_ORDER.index(difficulty), difficulty
    if not difficulty:
        return len(DIFFICULTY_ORDER), ""
    return len(DIFFICULTY_ORDER), difficulty


def difficulty_label(difficulty: str) -> str:
    if difficulty in DIFFICULTY_LABELS:
        return DIFFICULTY_LABELS[difficulty]
    if not difficulty:
        return "-"
    return format_display_label(difficulty.replace("-", " "))


def drop_contexts(contexts: list[str], keys_to_drop: set[str]) -> list[str]:
    return [context for context in contexts if comparison_key(context) not in keys_to_drop]


def upsert_context(contexts: list[str], label: str) -> list[str]:
    key = comparison_key(label)
    if any(comparison_key(context) == key for context in contexts):
        return contexts
    return contexts + [label]


def prune_contexts(slug: str, contexts: list[str]) -> list[str]:
    cleaned = list(contexts)
    context_keys = {comparison_key(context) for context in cleaned}

    cleaned = drop_contexts(
        cleaned,
        {comparison_key(value) for value in CONTEXT_SUPPRESSION_BY_SLUG.get(slug, set())},
    )
    context_keys = {comparison_key(context) for context in cleaned}

    if "dagdp" in context_keys:
        cleaned = drop_contexts(cleaned, {"dag"})
        context_keys = {comparison_key(context) for context in cleaned}

    if "dag" in context_keys and "dp" in context_keys:
        cleaned = drop_contexts(cleaned, {"dag", "dp"})
        cleaned = upsert_context(cleaned, "DAG DP")
        context_keys = {comparison_key(context) for context in cleaned}

    if "gridbfs" in context_keys or ("grid" in context_keys and "bfs" in context_keys):
        cleaned = drop_contexts(cleaned, {"grids", "grid", "bfs", "gridbfs"})
        cleaned = upsert_context(cleaned, "Grid BFS")
        context_keys = {comparison_key(context) for context in cleaned}

    if "griddfs" in context_keys or ("grid" in context_keys and "dfs" in context_keys):
        cleaned = drop_contexts(cleaned, {"grids", "grid", "dfs", "griddfs"})
        cleaned = upsert_context(cleaned, "Grid DFS")
        context_keys = {comparison_key(context) for context in cleaned}

    if "grid" in context_keys and "grids" in context_keys:
        cleaned = drop_contexts(cleaned, {"grids"})
        context_keys = {comparison_key(context) for context in cleaned}

    if "dp" in context_keys and len(cleaned) > 1:
        cleaned = drop_contexts(cleaned, {"dp"})
        context_keys = {comparison_key(context) for context in cleaned}

    if "counting" in context_keys and any(key != "counting" and "count" in key for key in context_keys):
        cleaned = drop_contexts(cleaned, {"counting"})

    return cleaned


def drop_descriptors(items: list[str], keys_to_drop: set[str]) -> list[str]:
    return [item for item in items if comparison_key(item) not in keys_to_drop]


def prune_tags(tags: list[str]) -> list[str]:
    cleaned = list(tags)
    tag_keys = {comparison_key(tag) for tag in cleaned}

    if "greedy" in tag_keys and len(cleaned) > 1:
        cleaned = drop_descriptors(cleaned, {"greedy"})
        tag_keys = {comparison_key(tag) for tag in cleaned}

    if "counting" in tag_keys and any(key != "counting" and "count" in key for key in tag_keys):
        cleaned = drop_descriptors(cleaned, {"counting"})
        tag_keys = {comparison_key(tag) for tag in cleaned}

    if "queries" in tag_keys and len(cleaned) > 1:
        cleaned = drop_descriptors(cleaned, {"queries"})
        tag_keys = {comparison_key(tag) for tag in cleaned}

    if "strings" in tag_keys and len(cleaned) > 1:
        cleaned = drop_descriptors(cleaned, {"strings"})
        tag_keys = {comparison_key(tag) for tag in cleaned}

    if "flow" in tag_keys and any(key != "flow" and "flow" in key for key in tag_keys):
        cleaned = drop_descriptors(cleaned, {"flow"})
        tag_keys = {comparison_key(tag) for tag in cleaned}

    if "modarithmetic" in tag_keys and "modulo" in tag_keys:
        cleaned = drop_descriptors(cleaned, {"modulo"})

    return cleaned


def normalize_tag_list(slug: str, source: str, contexts: list[str], tags: list[str]) -> list[str]:
    redundant_keys = descriptor_redundant_keys(slug, source, contexts)
    redundant_keys -= {comparison_key(tag) for tag in TAG_REDUNDANCY_EXCEPTIONS_BY_SLUG.get(slug, set())}
    out: list[str] = []
    seen: set[str] = set()
    for tag in tags:
        canonical = normalize_phrase(tag, TAG_ALIASES)
        key = comparison_key(canonical)
        if not key or key in seen or key in redundant_keys or key in GENERIC_TAG_KEYS:
            continue
        seen.add(key)
        out.append(format_display_label(canonical))
    return prune_tags(out)


def normalize_prerequisite_list(slug: str, contexts: list[str], prerequisites: list[str]) -> list[str]:
    redundant_keys = {comparison_key(context) for context in contexts}
    out: list[str] = []
    seen: set[str] = set()
    for prerequisite in prerequisites:
        canonical = normalize_phrase(prerequisite, PREREQUISITE_ALIASES)
        key = comparison_key(canonical)
        if not key or key in seen or key in redundant_keys:
            continue
        seen.add(key)
        out.append(format_display_label(canonical))
    return out


def normalize_track_list(slug: str, source: str, tracks: list[str]) -> list[str]:
    area, subtopic = slug.split("/", 1)
    subtopic_words = [word for word in re.split(r"[-/ ]+", subtopic) if word]
    redundant_keys = {
        comparison_key(area),
        comparison_key(subtopic),
        comparison_key(subtopic.replace("-", " ")),
        comparison_key(slug),
        comparison_key(slug.replace("/", " ")),
        comparison_key(source),
    }
    for word in subtopic_words:
        redundant_keys.add(comparison_key(word))
        if word.endswith("s"):
            redundant_keys.add(comparison_key(word[:-1]))
        else:
            redundant_keys.add(comparison_key(word + "s"))

    out: list[str] = []
    seen: set[str] = set()
    for track in tracks:
        canonical = normalize_phrase(track, TRACK_ALIASES)
        key = comparison_key(canonical)
        if not key or key in seen or key in redundant_keys or key in GENERIC_CONTEXT_KEYS:
            continue
        seen.add(key)
        out.append(format_display_label(canonical))
    return prune_contexts(slug, out)


def load_json(path: Path) -> dict:
    if not path.exists():
        return {}
    return json.loads(path.read_text(encoding="utf-8"))


def parse_metadata(note_path: Path) -> dict[str, str]:
    meta: dict[str, str] = {}
    for line in note_path.read_text(encoding="utf-8").splitlines():
        if line.startswith("## "):
            break
        match = METADATA_RE.match(line)
        if not match:
            continue
        key = match.group(1).strip()
        value = clean_value(match.group(2))
        meta[key] = value
    return meta


def extract_url(value: str) -> str:
    match = MD_LINK_RE.search(value)
    if match:
        return match.group(2)
    return value


def relative_for_docs(path: str) -> str:
    return "../" + path


def relative_for_topic_maps(path: str) -> str:
    return "../../../" + path


def primary_slug_from_note(note_rel: Path) -> str:
    parts = note_rel.parts
    return f"{parts[2]}/{parts[3]}"


def default_tutorial_path(slug: str) -> str:
    if slug in LADDER_TO_TUTORIAL_OVERRIDES:
        return LADDER_TO_TUTORIAL_OVERRIDES[slug]

    area, subtopic = slug.split("/", 1)
    candidate = Path("topics") / area / subtopic / "README.md"
    if (ROOT / candidate).exists():
        return candidate.as_posix()
    return ""


def note_title_fields(title_value: str, note_path: Path) -> tuple[str, str]:
    title_value = clean_value(title_value)
    if " - " in title_value:
        _, title = title_value.split(" - ", 1)
        return note_path.stem.upper(), title.strip()
    return note_path.stem.upper(), title_value


def display_label_for_slug(slug: str, topic_resources: dict[str, dict]) -> str:
    if slug in topic_resources and topic_resources[slug].get("title"):
        return topic_resources[slug]["title"]
    area, sub = slug.split("/", 1)
    return f"{AREA_LABELS.get(area, area.title())} -> {sub.replace('-', ' ').title()}"


def build_problem_rows() -> list[dict]:
    overrides = load_json(PROBLEM_OVERRIDES)
    topic_resources = load_json(TOPIC_RESOURCES)
    rows: list[dict] = []

    for note_path in sorted(NOTES_ROOT.rglob("*.md")):
        if note_path.name == "README.md":
            continue

        meta = parse_metadata(note_path)
        note_rel = note_path.relative_to(ROOT)
        primary_slug = primary_slug_from_note(note_rel)
        ladder_path = (note_rel.parent / "README.md").as_posix()
        tutorial_path = topic_resources.get(primary_slug, {}).get("topic_path", default_tutorial_path(primary_slug))

        code, short_title = note_title_fields(meta.get("Title", note_path.stem.upper()), note_path)
        entry_override = overrides.get(code, {})

        topic_tags = unique([primary_slug] + entry_override.get("topic_tags", []))
        patterns = unique(entry_override.get("patterns", []))
        tracks = unique(entry_override.get("tracks", []))
        secondary_topics = split_csvish(meta.get("Secondary topics", ""))

        rows.append(
            {
                "code": code,
                "title": short_title,
                "full_title": meta.get("Title", f"{code} - {short_title}"),
                "judge": clean_value(meta.get("Judge / source", "")),
                "judge_url": extract_url(meta.get("Original URL", "")),
                "main_topic": clean_value(meta.get("Main topic", "")),
                "secondary_topics": secondary_topics,
                "difficulty": clean_value(meta.get("Difficulty", "")),
                "status": clean_value(meta.get("Status", "")),
                "primary_slug": primary_slug,
                "topic_tags": topic_tags,
                "patterns": patterns,
                "tracks": tracks,
                "note_path": note_rel.as_posix(),
                "ladder_path": ladder_path,
                "tutorial_path": tutorial_path,
                "solution_url": extract_url(meta.get("Solution file", "")),
            }
        )

    rows.sort(key=lambda row: (row["primary_slug"], row["code"]))
    return rows


def write_problem_catalog_json(rows: list[dict]) -> None:
    DATA_DIR.mkdir(parents=True, exist_ok=True)
    PROBLEM_JSON.write_text(json.dumps(rows, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")


def normalize_external_problem(slug: str, problem: dict) -> dict:
    source = normalize_source(problem.get("source", ""))
    difficulty = normalize_difficulty(problem.get("difficulty", ""))
    tracks = normalize_track_list(slug, source, problem.get("tracks", []))
    styles = normalize_descriptor_list(problem.get("styles", []), aliases=STYLE_ALIASES, humanize=True)
    return {
        "title": problem["title"],
        "url": problem["url"],
        "source": source,
        "difficulty": difficulty,
        "tracks": tracks,
        "tags": normalize_tag_list(slug, source, tracks, problem.get("tags", [])),
        "styles": styles,
        "prerequisites": normalize_prerequisite_list(slug, tracks, problem.get("prerequisites", [])),
        "bucket": normalize_bucket(problem.get("bucket", "core")),
        "why_fit": clean_value(problem.get("why_fit", "")),
    }


def bucket_sort_key(bucket: str) -> tuple[int, str]:
    if bucket in BUCKET_ORDER:
        return BUCKET_ORDER.index(bucket), bucket
    return len(BUCKET_ORDER), bucket


def bucket_label(bucket: str) -> str:
    return BUCKET_LABELS.get(bucket, format_display_label(bucket.replace("-", " ")))


def flatten_external_problem_rows(topic_resources: dict[str, dict], external_problem_pools: dict[str, list[dict]]) -> list[dict]:
    rows: list[dict] = []
    for slug, problems in external_problem_pools.items():
        title = display_label_for_slug(slug, topic_resources)
        for problem in problems:
            normalized = normalize_external_problem(slug, problem)
            rows.append(
                {
                    "slug": slug,
                    "topic": title,
                    "title": normalized["title"],
                    "url": normalized["url"],
                    "source": normalized["source"],
                    "difficulty": normalized["difficulty"],
                    "tracks": normalized["tracks"],
                    "tags": normalized["tags"],
                    "styles": normalized["styles"],
                    "prerequisites": normalized["prerequisites"],
                    "bucket": normalized["bucket"],
                    "why_fit": normalized["why_fit"],
                }
            )
    rows.sort(
        key=lambda row: (
            row["slug"],
            bucket_sort_key(row["bucket"]),
            difficulty_sort_key(row["difficulty"]),
            row["title"],
        )
    )
    return rows


def write_external_problem_catalog_json(rows: list[dict]) -> None:
    DATA_DIR.mkdir(parents=True, exist_ok=True)
    EXTERNAL_PROBLEM_JSON.write_text(json.dumps(rows, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")


def write_csv(rows: list[dict]) -> None:
    OUTPUT_CSV.parent.mkdir(parents=True, exist_ok=True)
    with OUTPUT_CSV.open("w", encoding="utf-8", newline="") as fh:
        writer = csv.DictWriter(
            fh,
            fieldnames=[
                "code",
                "title",
                "full_title",
                "judge",
                "judge_url",
                "main_topic",
                "primary_slug",
                "topic_tags",
                "secondary_topics",
                "patterns",
                "tracks",
                "difficulty",
                "status",
                "note_path",
                "ladder_path",
                "tutorial_path",
                "solution_url",
            ],
        )
        writer.writeheader()
        for row in rows:
            writer.writerow(
                {
                    **row,
                    "topic_tags": " | ".join(row["topic_tags"]),
                    "secondary_topics": " | ".join(row["secondary_topics"]),
                    "patterns": " | ".join(row["patterns"]),
                    "tracks": " | ".join(row["tracks"]),
                }
            )


def write_external_csv(rows: list[dict]) -> None:
    EXTERNAL_OUTPUT_CSV.parent.mkdir(parents=True, exist_ok=True)
    with EXTERNAL_OUTPUT_CSV.open("w", encoding="utf-8", newline="") as fh:
        writer = csv.DictWriter(
            fh,
            fieldnames=[
                "slug",
                "topic",
                "title",
                "url",
                "source",
                "difficulty",
                "bucket",
                "tracks",
                "tags",
                "styles",
                "prerequisites",
                "why_fit",
            ],
        )
        writer.writeheader()
        for row in rows:
            writer.writerow(
                {
                    **row,
                    "tracks": " | ".join(row["tracks"]),
                    "tags": " | ".join(row["tags"]),
                    "styles": " | ".join(row["styles"]),
                    "prerequisites": " | ".join(row["prerequisites"]),
                }
            )


def write_problem_index(rows: list[dict], topic_resources: dict[str, dict]) -> None:
    area_counts = Counter(AREA_LABELS.get(row["primary_slug"].split("/", 1)[0], row["primary_slug"]) for row in rows)
    grouped: dict[str, list[dict]] = defaultdict(list)
    for row in rows:
        grouped[row["primary_slug"].split("/", 1)[0]].append(row)

    lines: list[str] = []
    lines.append("# Repo Problem Index")
    lines.append("")
    lines.append("This page lists every current solved problem note in the repo and maps it back to the learning structure.")
    lines.append("")
    lines.append(f"- Total tracked problem notes: `{len(rows)}`")
    lines.append(f"- Data files: [problem-catalog.json](../data/problem-catalog.json), [repo-problem-catalog.csv](repo-problem-catalog.csv)")
    lines.append("- External companion index: [external-problem-index.md](external-problem-index.md)")
    lines.append("- Topic maps: [topic-maps/index.md](topic-maps/index.md)")
    lines.append("- Recommended use: start from the `Primary topic`, open the `Topic map`, then solve from the linked notes.")
    lines.append("")
    lines.append("## Coverage Snapshot")
    lines.append("")
    lines.append("| Area | Count |")
    lines.append("| --- | ---: |")
    for area in AREA_ORDER:
        label = AREA_LABELS[area]
        if label in area_counts:
            lines.append(f"| {label} | {area_counts[label]} |")
    lines.append("")
    lines.append("## Current Catalog")
    lines.append("")

    for area in AREA_ORDER:
        if area not in grouped:
            continue
        lines.append(f"### {AREA_LABELS[area]}")
        lines.append("")
        lines.append("| Code | Title | Primary | Also Fits | Pattern | Difficulty | Track | Learn | Note | Solution |")
        lines.append("| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |")
        for row in sorted(grouped[area], key=lambda item: (item["primary_slug"], item["code"])):
            extra_tags = [display_label_for_slug(slug, topic_resources) for slug in row["topic_tags"] if slug != row["primary_slug"]]
            topic_map_link = f"[Map](topic-maps/{row['primary_slug']}.md)"
            learn_parts = [topic_map_link, f"[Ladder]({relative_for_docs(row['ladder_path'])})"]
            if row["tutorial_path"]:
                learn_parts.append(f"[Tutorial]({relative_for_docs(row['tutorial_path'])})")
            note_link = f"[Note]({relative_for_docs(row['note_path'])})"
            solution_link = f"[Code]({row['solution_url']})" if row["solution_url"] else "-"
            lines.append(
                f"| `{row['code']}` | {row['title']} | `{display_label_for_slug(row['primary_slug'], topic_resources)}` | "
                f"{'; '.join(extra_tags) if extra_tags else '-'} | "
                f"{'; '.join(row['patterns']) if row['patterns'] else '-'} | "
                f"`{row['difficulty']}` | "
                f"{', '.join(row['tracks']) if row['tracks'] else '-'} | "
                f"{' / '.join(learn_parts)} | {note_link} | {solution_link} |"
            )
        lines.append("")

    lines.append("## Maintenance")
    lines.append("")
    lines.append("Regenerate the catalog and topic maps with:")
    lines.append("")
    lines.append("```bash")
    lines.append("python3 scripts/generate_problem_catalog.py")
    lines.append("```")
    lines.append("")
    OUTPUT_MD.write_text("\n".join(lines), encoding="utf-8")


def write_external_problem_index(rows: list[dict]) -> None:
    grouped: dict[str, list[dict]] = defaultdict(list)
    for row in rows:
        grouped[row["slug"]].append(row)

    lines: list[str] = []
    lines.append("# External Problem Index")
    lines.append("")
    lines.append("This page lists curated external problems imported into the topic-map system.")
    lines.append("")
    lines.append(f"- Total curated external problems: `{len(rows)}`")
    lines.append(f"- Data files: [external-problem-catalog.json](../data/external-problem-catalog.json), [external-problem-catalog.csv](external-problem-catalog.csv)")
    lines.append("- Best use: open a topic map first, then pick from the external problems table that matches your current subtopic and difficulty.")
    lines.append("")

    for area in AREA_ORDER:
        area_rows = [row for row in rows if row["slug"].split("/", 1)[0] == area]
        if not area_rows:
            continue
        lines.append(f"## {AREA_LABELS[area]}")
        lines.append("")
        lines.append("| Topic | Bucket | Problem | Source | Difficulty | Context | Style | Tags |")
        lines.append("| --- | --- | --- | --- | --- | --- | --- | --- |")
        for row in sorted(
            area_rows,
            key=lambda row: (row["topic"], bucket_sort_key(row["bucket"]), difficulty_sort_key(row["difficulty"]), row["title"]),
        ):
            lines.append(
                f"| `{row['topic']}` | `{bucket_label(row['bucket'])}` | "
                f"[{row['title']}]({row['url']}) | `{row['source']}` | `{difficulty_label(row['difficulty'])}` | "
                f"{', '.join(row['tracks']) if row['tracks'] else '-'} | "
                f"{'; '.join(row['styles']) if row['styles'] else '-'} | "
                f"{'; '.join(row['tags']) if row['tags'] else '-'} |"
            )
        lines.append("")

    lines.append("## Maintenance")
    lines.append("")
    lines.append("Regenerate the catalog and topic maps with:")
    lines.append("")
    lines.append("```bash")
    lines.append("python3 scripts/generate_problem_catalog.py")
    lines.append("```")
    lines.append("")
    EXTERNAL_OUTPUT_MD.write_text("\n".join(lines), encoding="utf-8")


def write_topic_maps(rows: list[dict], topic_resources: dict[str, dict], external_problem_pools: dict[str, list[dict]]) -> None:
    if TOPIC_MAPS_DIR.exists():
        for path in TOPIC_MAPS_DIR.rglob("*.md"):
            path.unlink()
    TOPIC_MAPS_DIR.mkdir(parents=True, exist_ok=True)

    grouped_by_slug: dict[str, list[dict]] = defaultdict(list)
    for row in rows:
        for slug in row["topic_tags"]:
            grouped_by_slug[slug].append(row)

    index_lines = [
        "# Topic Maps",
        "",
        "These pages collect trusted learning sources, official practice sources, curated external problems, and all currently tagged repo problems for each topic/subtopic.",
        "",
        "| Topic | Repo Problems | External Problems | Map |",
        "| --- | ---: | ---: | --- |",
    ]

    def sort_key(item: tuple[str, dict]) -> tuple[int, str]:
        slug = item[0]
        area = slug.split("/", 1)[0]
        area_rank = AREA_ORDER.index(area) if area in AREA_ORDER else len(AREA_ORDER)
        return area_rank, slug

    for slug, entry in sorted(topic_resources.items(), key=sort_key):
        title = entry["title"]
        problems = sorted(grouped_by_slug.get(slug, []), key=lambda row: row["code"])
        external_problems = [normalize_external_problem(slug, problem) for problem in external_problem_pools.get(slug, [])]
        rel_path = Path(slug + ".md")
        out_path = TOPIC_MAPS_DIR / rel_path
        out_path.parent.mkdir(parents=True, exist_ok=True)

        lines: list[str] = []
        lines.append(f"# {title}")
        lines.append("")
        summary = entry.get("summary", "")
        if summary:
            lines.append(summary)
            lines.append("")
        lines.append(f"- Topic slug: `{slug}`")
        if entry.get("topic_path"):
            lines.append(f"- Tutorial page: [Open tutorial]({relative_for_topic_maps(entry['topic_path'])})")
        if entry.get("ladder_path"):
            lines.append(f"- Ladder page: [Open ladder]({relative_for_topic_maps(entry['ladder_path'])})")
        lines.append(f"- Repo problems currently tagged here: `{len(problems)}`")
        lines.append(f"- Curated external problems: `{len(external_problems)}`")
        lines.append("")

        microtopics = entry.get("microtopics", [])
        if microtopics:
            lines.append("## Microtopics")
            lines.append("")
            for item in microtopics:
                lines.append(f"- {item}")
            lines.append("")

        learning_sources = entry.get("learning_sources", [])
        if learning_sources:
            lines.append("## Learning Sources")
            lines.append("")
            lines.append("| Source | Type |")
            lines.append("| --- | --- |")
            for source in learning_sources:
                lines.append(f"| [{source['label']}]({source['url']}) | `{source['kind']}` |")
            lines.append("")

        practice_sources = entry.get("practice_sources", [])
        if practice_sources:
            lines.append("## Practice Sources")
            lines.append("")
            lines.append("| Source | Type |")
            lines.append("| --- | --- |")
            for source in practice_sources:
                lines.append(f"| [{source['label']}]({source['url']}) | `{source['kind']}` |")
            lines.append("")

        lines.append("## Curated External Problems")
        lines.append("")
        if not external_problems:
            lines.append("_No curated external problems have been attached to this topic yet._")
            lines.append("")
        else:
            grouped_external: dict[str, list[dict]] = defaultdict(list)
            for problem in external_problems:
                grouped_external[problem["bucket"]].append(problem)

            for bucket in sorted(grouped_external, key=bucket_sort_key):
                bucket_rows = grouped_external.get(bucket, [])
                if not bucket_rows:
                    continue
                lines.append(f"### {bucket_label(bucket)}")
                lines.append("")
                lines.append("| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |")
                lines.append("| --- | --- | --- | --- | --- | --- | --- | --- |")
                for problem in sorted(bucket_rows, key=lambda item: (difficulty_sort_key(item["difficulty"]), item["title"])):
                    lines.append(
                        f"| [{problem['title']}]({problem['url']}) | `{problem['source']}` | `{difficulty_label(problem['difficulty'])}` | "
                        f"{', '.join(problem.get('tracks', [])) if problem.get('tracks') else '-'} | "
                        f"{'; '.join(problem.get('styles', [])) if problem.get('styles') else '-'} | "
                        f"{'; '.join(problem.get('prerequisites', [])) if problem.get('prerequisites') else '-'} | "
                        f"{'; '.join(problem.get('tags', [])) if problem.get('tags') else '-'} | "
                        f"{problem.get('why_fit', '-')} |"
                    )
                lines.append("")

        lines.append("## Repo Problems")
        lines.append("")
        if not problems:
            lines.append("_No repo note has been tagged to this topic yet._")
            lines.append("")
        else:
            lines.append("| Code | Title | Fit | Difficulty | Pattern | Note | Solution |")
            lines.append("| --- | --- | --- | --- | --- | --- | --- |")
            for row in problems:
                fit = "primary" if row["primary_slug"] == slug else "secondary"
                note_link = f"[Note]({relative_for_topic_maps(row['note_path'])})"
                code_link = f"[Code]({row['solution_url']})" if row["solution_url"] else "-"
                lines.append(
                    f"| `{row['code']}` | {row['title']} | `{fit}` | `{row['difficulty']}` | "
                    f"{'; '.join(row['patterns']) if row['patterns'] else '-'} | {note_link} | {code_link} |"
                )
            lines.append("")

        lines.append("## Regeneration")
        lines.append("")
        lines.append("```bash")
        lines.append("python3 scripts/generate_problem_catalog.py")
        lines.append("```")
        lines.append("")

        out_path.write_text("\n".join(lines), encoding="utf-8")
        index_lines.append(f"| {title} | {len(problems)} | {len(external_problems)} | [Open]({slug}.md) |")

    TOPIC_MAPS_INDEX.write_text("\n".join(index_lines) + "\n", encoding="utf-8")


def main() -> None:
    rows = build_problem_rows()
    topic_resources = load_json(TOPIC_RESOURCES)
    external_problem_pools = load_json(EXTERNAL_PROBLEM_POOLS)
    external_rows = flatten_external_problem_rows(topic_resources, external_problem_pools)
    write_problem_catalog_json(rows)
    write_external_problem_catalog_json(external_rows)
    write_csv(rows)
    write_external_csv(external_rows)
    write_problem_index(rows, topic_resources)
    write_external_problem_index(external_rows)
    write_topic_maps(rows, topic_resources, external_problem_pools)


if __name__ == "__main__":
    main()
