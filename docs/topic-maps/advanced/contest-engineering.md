# Advanced -> Contest Engineering

Operational discipline for contests: local testing, checkers, interactive handling, notebook curation, and environment parity.

- Topic slug: `advanced/contest-engineering`
- Tutorial page: [Open tutorial](../../../topics/advanced/contest-engineering/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/advanced/contest-engineering/README.md)
- Repo problems currently tagged here: `0`
- Repo companion pages: `5`
- Curated external problems: `6`

## Microtopics

- stress-testing
- local-judging
- interactive-io
- checkers-graders
- notebook-templates
- build-flags
- profiling
- submission-workflow

## Learning Sources

| Source | Type |
| --- | --- |
| [ICPC World Finals Programming Environment](https://docs.icpc.global/worldfinals-programming-environment/) | `official docs` |
| [ICPC Tools](https://tools.icpc.global/) | `official docs` |
| [ICPC Contest Utilities](https://tools.icpc.global/contest-utils/) | `official docs` |

## Practice Sources

| Source | Type |
| --- | --- |
| [ICPC Foundation Problem Archive](https://foundation.icpc.global/archive/) | `contest archive` |
| [AtCoder Introduction to Heuristics](https://atcoder.jp/contests/intro-heuristics/tasks/intro_heuristics_a) | `practice` |
| [IOI tasks archive](https://stats.ioinformatics.org/tasks/) | `contest archive` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Contest checklist](../../../notebook/contest-checklist.md) | `checklist` |
| [Contest playbooks](../../../practice/contest-playbooks/README.md) | `process guide` |
| [Stress testing workflow](../../../notebook/stress-testing-workflow.md) | `verification guide` |
| [Local judge workflow](../../../notebook/local-judge-workflow.md) | `interactive guide` |
| [Templates overview](../../../template-library.md) | `template guide` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Hidden Integer](https://cses.fi/problemset/task/3112) | `CSES` | `Easy-Medium` | Interactive | - | - | Binary Search; Query Budget; Flushing | Excellent first interactive problem for disciplined I/O and query budgeting. |
| [Colored Chairs](https://cses.fi/problemset/task/3273) | `CSES` | `Medium` | Interactive | - | - | Parity; Binary Search; Query Budget | Small-query interactive problem that trains calm invariant tracking. |
| [Hidden Permutation](https://cses.fi/problemset/task/3139) | `CSES` | `Medium` | Interactive | - | - | Comparison Oracle; Reconstruction; Query Strategy | A clean interactive reconstruction problem that trains protocol handling and comparison-based strategy. |
| [K-th Highest Score](https://cses.fi/problemset/task/3305) | `CSES` | `Medium` | Interactive | - | - | Merge Logic; Query Strategy; Two Sorted Sources | Good practice for interactive strategy design under a global query cap. |
| [Permuted Binary Strings](https://cses.fi/problemset/task/3228) | `CSES` | `Medium` | Interactive | - | - | Bit Probing; Reconstruction; Query Design | A reconstruction problem that rewards careful experiment design. |
| [Inversion Sorting](https://cses.fi/problemset/task/3140) | `CSES` | `Hard` | Interactive | - | - | Sorting By Feedback; Adaptive Strategy; Interaction Protocol | Great later-stage interactive practice where the judge feedback is indirect. |

## Repo Problems

_No repo problem note is attached yet. Use the repo companion material above for this theory/process-heavy topic._

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
