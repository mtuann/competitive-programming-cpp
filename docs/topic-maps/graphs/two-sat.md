# Graphs -> Two-SAT

Boolean variables, implication graphs, and SCC-based feasibility plus assignment extraction.

- Topic slug: `graphs/two-sat`
- Tutorial page: [Open tutorial](../../../topics/graphs/two-sat/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/graphs/two-sat/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `3`
- Curated external problems: `4`

## Microtopics

- literal
- implication-graph
- clause-rewrite
- assignment-extraction
- not-both
- exactly-one

## Learning Sources

| Source | Type |
| --- | --- |
| [Aspvall, Plass, Tarjan - A Linear-Time Algorithm for Testing the Truth of Certain Quantified Boolean Formulas](https://www.cs.princeton.edu/courses/archive/fall13/cos521/Handouts/2SAT.pdf) | `Primary` |
| [cp-algorithms 2-SAT](https://cp-algorithms.com/graph/2SAT.html) | `Reference` |
| [OI Wiki 2-SAT](https://en.oi-wiki.org/graph/2-sat/) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Library Checker Two SAT](https://judge.yosupo.jp/problem/two_sat) | `Practice` |
| [CSES Problem Set](https://cses.fi/problemset/) | `Practice` |
| [Codeforces problemset](https://codeforces.com/problemset) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Two-SAT hot sheet](../../../notebook/two-sat-hot-sheet.md) | `quick reference` |
| [Giant Pizza note](../../../practice/ladders/graphs/two-sat/giantpizza.md) | `anchor note` |
| [Topological Sort And SCC tutorial](../../../topics/graphs/scc-toposort/README.md) | `adjacent tutorial` |

## Curated External Problems

### Warm-Up

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Two SAT](https://judge.yosupo.jp/problem/two_sat) | `Library Checker` | `Medium` | 2-SAT | Implication Graph; SCC Check; Witness Recovery | SCC; Directed Graphs; Boolean Variables | Implication Graph; SCC; Assignment Extraction | The cleanest exact verifier for a reusable 2-SAT starter. |

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Giant Pizza](https://cses.fi/problemset/task/1684) | `CSES` | `Medium` | 2-SAT, Assignment | Clause Rewrite; Implication Graph; Assignment Extraction | SCC; Literal Encoding; Boolean Modeling | Implication Graph; Clause Modeling; SCC; Witness | The cleanest contest-format 2-SAT modeling problem with one recovered assignment. |

### Classics

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Wedding](https://onlinejudge.org/external/112/11294.pdf) | `UVa` | `Medium` | 2-SAT, Classic | Boolean Modeling; Complement Pairs; SCC Assignment | 2-SAT Basics; SCC; Logical Modeling | Seating Constraints; Implication Graph | A classic 2-SAT reduction where statement semantics matter more than SCC code. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [The Door Problem](https://codeforces.com/problemset/problem/776/D) | `Codeforces` | `Hard` | 2-SAT, Modeling | Constraint Reframing; Implication Graph; Witness Recovery | 2-SAT Basics; Clause Rewriting; SCC | Boolean Constraints; Parity-Like Modeling; Assignment | A strong next step once the implication-graph route itself is trusted. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `GIANTPIZZA` | Giant Pizza | `primary` | `medium` | 2-sat; implication graph; assignment extraction | [Note](../../../practice/ladders/graphs/two-sat/giantpizza.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/two-sat/giantpizza.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
