# competitive-programming-cpp

A C++ algorithms and competitive programming curriculum that ties together theory, clean implementation, and deliberate practice.

This repo is meant to be more than a template dump and more than a solutions archive. The goal is a source-backed learning path shaped by strong university algorithms courses, major contest systems, and practical community references.

Project site: [mtuann.github.io/competitive-programming-cpp](https://mtuann.github.io/competitive-programming-cpp/)

If you want one guided first door instead of browsing sections, start with [Start Here](docs/start-here.md).
If you want the repo organized by routes instead of folders, open the [Route Map](docs/route-map.md).

## Start Here

| If you are... | Start with | Goal |
| --- | --- | --- |
| New to competitive programming | [Start Here](docs/start-here.md) | Build C++ fluency, asymptotics, and the core toolkit without self-routing too early |
| Comfortable with basics but inconsistent in contests | [Route Map](docs/route-map.md) + [Practice](practice/README.md) | Turn weak topics into focused ladder/note loops and start retrieval work |
| Preparing for `USACO` / olympiad-style contests | [Contest Playbooks](practice/contest-playbooks/README.md) + [Practice](practice/README.md) | Train topic by topic, then move into solo-track drills and archive follow-up |
| Preparing for `ICPC` / team contests | [Contest Playbooks](practice/contest-playbooks/README.md) + [Practice](practice/README.md) | Build breadth, switching, and one-machine/team workflows |
| Contributing content later | [Topic Template](docs/topic-template.md) + [Content Blueprint](docs/content-blueprint.md) | Follow one stable teaching format instead of adding ad hoc notes |

## Curriculum Map By Level

The repo uses `curriculum levels` as the content-progression language.

This is separate from the learner `Stage 1-4` route model used in [Start Here](docs/start-here.md) and the [Route Map](docs/route-map.md).

| Curriculum level | Main focus | Typical folders |
| --- | --- | --- |
| `Level 0` | Foundations: C++ workflow, STL, asymptotics, proof habits, sorting, binary search, prefix ideas | `topics/foundations/` |
| `Level 1` | Core data structures and query/update tools | `topics/data-structures/` |
| `Level 2` | Graphs and dynamic programming as contest core | `topics/graphs/`, `topics/dp/` |
| `Level 3` | Math, combinatorics, strings, and geometry for broader coverage | `topics/math/`, `topics/combinatorics/`, `topics/strings/`, `topics/geometry/` |
| `Level 4` | Advanced algorithms and theory | `topics/advanced/` |
| `Level 5` | Contest engineering: notebooks, drills, workflows, and upsolving discipline | `notebook/`, `practice/contest-playbooks/` |

Contest tracks such as `USACO`, `IOI/OI`, and `ICPC` sit on top of these levels. They change emphasis, not the core learning path.

## How This Repo Works

- [Learning Areas](topics/README.md): layered topic tutorials and area hubs
- [Practice](practice/README.md): topic-first ladders, mixed rounds, and contest playbooks
- [Route Map](docs/route-map.md): pick the next door by level, bottleneck, or contest goal
- [Explore](docs/explore.md): topic maps, indexes, and research-backed coverage lookup
- [Problem Index](docs/problem-index.md): current solved problem notes mapped back to their learning hubs
- [External Problem Index](docs/external-problem-index.md): curated official and trusted problems grouped by topic, microtopic, and contest track
- [Topic Maps](docs/topic-maps/index.md): trusted learning sources, practice and follow-up sources, and repo coverage for each subtopic
- [Build Kit](docs/build-kit.md): templates, notebook pages, and debugging workflows
- [Templates](template-library.md): reusable contest-ready code
- [Notebook](notebook/README.md): dense reference material for contest use
- [Source Map](docs/source-map.md): the research appendix behind the curriculum choices

Each mature topic page should help a reader answer the whole learning loop, not just the definition:

1. `When should I think of this idea?`
2. `What is the naive baseline, and why is it too slow or too weak?`
3. `Why is the optimized algorithm correct?`
4. `Which variant should I choose?`
5. `What is the clean C++ pattern?`
6. `What should I solve next?`

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

Freshness-sensitive external links and workflow recommendations in learner-facing docs were last reviewed on `April 24, 2026`.

- Research appendix: [docs/source-map.md](docs/source-map.md)
- Maintainer plan: [docs/content-blueprint.md](docs/content-blueprint.md)
- Topic-page contract: [docs/topic-template.md](docs/topic-template.md)
- Roadmap and backlog: [docs/roadmap.md](docs/roadmap.md)

This repo is still growing from scaffold to full curriculum, so the highest-value work is not adding more philosophy pages. It is writing stronger topic pages, cleaner templates, and better practice ladders.
