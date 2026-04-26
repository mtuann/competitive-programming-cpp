# Graphs -> Hungarian / Assignment Problem

Dense square weighted assignment via Hungarian's O(n^3) primal-dual algorithm, with direct recovery of one minimum-cost perfect matching.

- Topic slug: `graphs/hungarian-assignment`
- Tutorial page: [Open tutorial](../../../topics/graphs/hungarian-assignment/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/graphs/hungarian-assignment/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `3`

## Microtopics

- assignment-matrix
- weighted-bipartite-matching
- potentials
- reduced-slack
- tight-edges
- primal-dual

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms Hungarian algorithm](https://cp-algorithms.com/graph/hungarian-algorithm.html) | `Reference` |
| [KACTL WeightedMatching / Hungarian](https://pages.cs.wisc.edu/~dieter/ICPC/21-22/kactl.pdf) | `Reference` |
| [OI Wiki weighted bipartite matching](https://en.oi-wiki.org/graph/graph-matching/bigraph-weight-match/) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Task Assignment](https://cses.fi/problemset/task/2129) | `Practice` |
| [SPOJ ASSIGN4](https://www.spoj.com/problems/ASSIGN4/) | `Practice` |
| [The Great Wall Game](https://www.cs.cmu.edu/~eugene/teach/acm06a/hard/05.pdf) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Hungarian hot sheet](../../../notebook/hungarian-hot-sheet.md) | `quick reference` |
| [Hungarian starter route](../../../template-library.md) | `starter route` |
| [Task Assignment note](../../../practice/ladders/graphs/hungarian-assignment/taskassignment.md) | `anchor note` |
| [Matching tutorial](../../../topics/graphs/matching/README.md) | `compare point` |
| [Min-Cost Flow tutorial](../../../topics/graphs/min-cost-flow/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Task Assignment](https://cses.fi/problemset/task/2129) | `CSES` | `Hard` | Weighted Matching | Dense Cost Matrix; Weighted Bipartite Matching | Bipartite Matching Basics; Minimum Total Cost Modeling | Cost Matrix; Perfect Matching | The cleanest square assignment benchmark with explicit witness output. |

### Practice

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Another Assignment Problem](https://www.spoj.com/problems/ASSIGN4/) | `SPOJ` | `Medium` | - | Weighted Bipartite Matching; Assignment Matrix | Assignment Matrix; Perfect Matching | Weighted Matching; Optimization | Direct costed assignment practice after the flagship matrix-first route. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [The Great Wall Game](https://www.cs.cmu.edu/~eugene/teach/acm06a/hard/05.pdf) | `ACM regional archive` | `Hard` | Geometry | Geometry To Cost Matrix; Minimum Cost Perfect Matching | Distance Cost Modeling; Hungarian Basics | Manhattan Distance; Modeling | A strong modeling extension where coordinates collapse cleanly into an assignment-cost matrix. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `TASKASSIGNMENT` | Task Assignment | `primary` | `hard` | - | [Note](../../../practice/ladders/graphs/hungarian-assignment/taskassignment.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/hungarian-assignment/taskassignment.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
