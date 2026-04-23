# Graphs -> Minimum Spanning Tree

Use cut and cycle properties to build minimum spanning forests with Kruskal or Prim.

- Topic slug: `graphs/mst`
- Tutorial page: [Open tutorial](../../../topics/graphs/mst/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/graphs/mst/README.md)
- Repo problems currently tagged here: `1`
- Curated external problems: `6`

## Microtopics

- kruskal
- prim
- dsu
- cut-property
- cycle-property
- minimum-spanning-forest

## Learning Sources

| Source | Type |
| --- | --- |
| [Princeton MST](https://algs4.cs.princeton.edu/43mst/index.php) | `course` |
| [cp-algorithms Kruskal](https://cp-algorithms.com/graph/mst_kruskal.html) | `trusted guide` |
| [cp-algorithms Prim](https://cp-algorithms.com/graph/mst_prim.html) | `trusted guide` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Problem Set](https://cses.fi/problemset/) | `problem set` |
| [USACO contest archive](https://usaco.org/index.php?page=contests) | `contest archive` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Minimum Spanning Tree](https://open.kattis.com/problems/minspantree) | `Kattis` | `Easy` | - | - | - | Kruskal; Classic | A standard trusted MST practice problem. |

### Coordinate MST

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Built?](https://atcoder.jp/contests/abc065/tasks/arc076_b) | `AtCoder` | `Medium` | Geometry | Sorting By Coordinate; Candidate Edge Pruning; Kruskal | DSU; Sorting; Greedy MST | Coordinate Graph; Sparse Edges | A classic geometry-to-graph reduction before running Kruskal. |

### Kruskal

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Minimum Spanning Tree](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A) | `AOJ` | `Medium` | DSU | Edge Sorting; Union-Find; Weight Accumulation | Sorting; Tree Connectivity | MST Sum; Weighted Graph; Kruskal; Weighted Undirected | The canonical official MST verification problem from AOJ. |
| [Road Reparation](https://cses.fi/problemset/task/1675) | `CSES` | `Medium` | DSU | Edge Sorting; DSU Merges; Component Counting | Sorting; Greedy Choice | Minimum Spanning Tree; Connectivity | The standard MST warm-up with a clean connectivity check. |

### MST Variants

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Minimum spanning tree for each edge](https://codeforces.com/problemset/problem/609/E) | `Codeforces` | `Hard` | - | Kruskal Base Tree; Max-Edge Queries On Path; Replacement Reasoning | MST; LCA Or HLD; Tree Path Maximum | Replacement Edge; MST Variants; Binary Lifting | A strong follow-up to plain MST that asks for edge-wise replacement analysis. |

### MST Verification

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Minimum Spanning Tree](https://judge.yosupo.jp/problem/minimum_spanning_tree) | `Library Checker` | `Medium` | - | Kruskal Template; Edge Index Handling; DSU | MST Basics; DSU; Weighted Edges | Sparse Graph; DSU; Verify | A clean judge problem for checking a production-ready MST implementation. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `ROADREPARATION` | Road Reparation | `primary` | `medium` | kruskal mst; connectivity check; cut property greedy | [Note](../../../practice/ladders/graphs/mst/roadreparation.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/mst/roadreparation.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
