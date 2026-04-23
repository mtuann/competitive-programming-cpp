# competitive-programming-cpp

A C++ algorithms and competitive programming curriculum that ties together theory, clean implementation, and deliberate practice.

This repo is meant to be more than a template dump and more than a solutions archive. The goal is a source-backed learning path shaped by strong university algorithms courses, major contest systems, and practical community references.

Project site: [mtuann.github.io/competitive-programming-cpp](https://mtuann.github.io/competitive-programming-cpp/)

## Start Here

| If you are... | Start with | Goal |
| --- | --- | --- |
| New to competitive programming | [Foundations](topics/foundations/README.md) | Build C++ fluency, asymptotics, and the core toolkit |
| Comfortable with basics but inconsistent in contests | [Data Structures](topics/data-structures/README.md), [Graphs](topics/graphs/README.md), [Dynamic Programming](topics/dp/README.md) | Build the standard contest toolbox and learn when to use it |
| Preparing for `USACO` / olympiad-style contests | [Topics](topics/README.md) + [Practice](practice/README.md) | Train topic by topic with stronger modeling and proof habits |
| Preparing for `ICPC` / team contests | [Practice](practice/README.md) + [Notebook](notebook/README.md) | Build breadth, workflow, and contest-ready references |
| Contributing content later | [Topic Template](docs/topic-template.md) + [Content Blueprint](docs/content-blueprint.md) | Follow one stable teaching format instead of adding ad hoc notes |

## Curriculum Map

The repo uses `stages` as the main progression language.

| Stage | Main focus | Typical folders |
| --- | --- | --- |
| `Stage 0` | Foundations: C++ workflow, STL, asymptotics, proof habits, sorting, binary search, prefix ideas | `topics/foundations/` |
| `Stage 1` | Core data structures and query/update tools | `topics/data-structures/` |
| `Stage 2` | Graphs and dynamic programming as contest core | `topics/graphs/`, `topics/dp/` |
| `Stage 3` | Math, combinatorics, strings, and geometry for broader coverage | `topics/math/`, `topics/combinatorics/`, `topics/strings/`, `topics/geometry/` |
| `Stage 4` | Advanced algorithms and theory | `topics/advanced/` |
| `Stage 5` | Contest engineering: notebooks, drills, workflows, and upsolving discipline | `notebook/`, `practice/contest-playbooks/` |

Contest tracks such as `USACO`, `IOI/OI`, and `ICPC` sit on top of these stages. They change emphasis, not the core learning path.

## How This Repo Works

- [Topics](topics/README.md): concise teaching pages and area hubs
- [Practice](practice/README.md): topic-first ladders, mixed rounds, and contest playbooks
- [Problem Index](docs/problem-index.md): current solved problem notes mapped back to their learning hubs
- [External Problem Index](docs/external-problem-index.md): curated official and trusted problems grouped by topic, microtopic, and contest track
- [Topic Maps](docs/topic-maps/index.md): trusted learning sources, official practice sources, and repo coverage for each subtopic
- [Templates](template-library.md): reusable contest-ready code
- [Notebook](notebook/README.md): dense reference material for contest use
- [Source Map](docs/source-map.md): the research appendix behind the curriculum choices

Each mature topic page should help a reader answer four questions quickly:

1. `When should I think of this idea?`
2. `Why is it correct?`
3. `What is the clean C++ pattern?`
4. `What should I solve next?`

The source of truth for finished topic pages is [docs/topic-template.md](docs/topic-template.md).

## Catalog Maintenance

When you change topic metadata, problem overrides, ladder notes, or external pools, run the catalog checks before pushing:

```bash
python3 scripts/generate_problem_catalog.py --validate-only
python3 scripts/generate_problem_catalog.py --check
python3 scripts/build_site_docs.py
mkdocs build --strict
```

`--validate-only` checks the raw data schema and note metadata. `--check` regenerates the tracked catalog outputs and fails if anything needs to be committed.

## References And Standards

The curriculum is grounded in public official sources current through `April 22, 2026`, including university algorithms syllabi, official contest documents, and major CP references.

- Research appendix: [docs/source-map.md](docs/source-map.md)
- Maintainer plan: [docs/content-blueprint.md](docs/content-blueprint.md)
- Topic-page contract: [docs/topic-template.md](docs/topic-template.md)

This repo is still growing from scaffold to full curriculum, so the highest-value work is not adding more philosophy pages. It is writing stronger topic pages, cleaner templates, and better practice ladders.
