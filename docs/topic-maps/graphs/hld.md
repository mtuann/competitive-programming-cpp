# Graphs -> Heavy-Light Decomposition

Decompose tree paths into logarithmically many chains so path queries and updates reduce to range structures.

- Topic slug: `graphs/hld`
- Ladder page: [Open ladder](../practice/ladders/graphs/trees/README.md)
- Repo problems currently tagged here: `1`
- Curated external problems: `8`

## Microtopics

- heavy-edge
- light-edge
- chain-head
- base-array
- segment-tree
- path-query
- path-update

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms HLD](https://cp-algorithms.com/graph/hld.html) | `trusted guide` |
| [OI Wiki HLD](https://en.oi-wiki.org/graph/hld/) | `trusted guide` |
| [USACO Guide HLD](https://usaco.guide/plat/hld?lang=cpp) | `trusted guide` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Library Checker vertex_add_path_sum](https://judge.yosupo.jp/problem/vertex_add_path_sum) | `problem` |
| [CSES Problem Set](https://cses.fi/problemset/) | `problem set` |
| [USACO contest archive](https://usaco.org/index.php?page=contests) | `contest archive` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Path Queries II](https://cses.fi/problemset/task/2134) | `CSES` | `Medium` | Path Max Query | Path Decomposition; Node Updates | LCA; Segment Tree | Trees; Updates; Segment Tree; Path Max; Point Update | A modern, clean HLD benchmark with updates and path maximums. |
| [Vertex Add Path Sum](https://judge.yosupo.jp/problem/vertex_add_path_sum) | `Library Checker` | `Medium` | - | - | - | Path Sum; Verify | Trusted path-sum benchmark for HLD implementations. |
| [Vertex Set Path Composite](https://judge.yosupo.jp/problem/vertex_set_path_composite) | `Library Checker` | `Hard` | - | - | - | Non-Commutative; Path Queries; Verify | Great stress test for HLD with non-commutative merges. |

### Classics

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [QTREE2](https://www.spoj.com/problems/QTREE2) | `SPOJ` | `Medium` | Path Queries | Path Distance; K-Th Node | LCA; Binary Lifting Or HLD | Trees; Distance; K-Th Node | Adds distance and k-th-node queries on paths. |
| [QTREE3](https://www.spoj.com/problems/QTREE3) | `SPOJ` | `Medium` | Dynamic Path Query | Toggle Queries; Path Prefix Search | HLD; Segment Tree With Colors | Trees; Toggle; Nearest Black Node | Dynamic toggles on a root-to-node path are a classic HLD extension. |
| [QTREE](https://www.spoj.com/problems/QTREE) | `SPOJ` | `Hard` | Heavy-Light Decomposition, Path Queries | Edge Path Queries; Segment Tree | LCA; Segment Trees | Trees; Segment Tree | The canonical tree path-query problem for HLD. |

### Advanced

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [QTREE4](https://www.spoj.com/problems/QTREE4) | `SPOJ` | `Hard` | Dynamic Tree Queries | Color Toggles; Global Path Aggregate | HLD; Lazy Propagation | Trees; Toggle; Path Aggregate | A tougher variant with nontrivial global maintenance. |
| [Water Tree](https://codeforces.com/problemset/problem/343/D) | `Codeforces` | `Hard` | Subtree Updates | Subtree Update / Ancestor Query; Lazy Propagation | Euler/HLD; Lazy Segment Tree | Trees; Range Updates; Online Queries | Subtree filling and ancestor clearing is a famous HLD/lazy-seg hybrid. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `VMWTREE` | Lại là cây khung | `secondary` | `hard` | path reverse; path sequence queries; heavy-light decomposition | [Note](../practice/ladders/graphs/trees/vmwtree.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/trees/vmwtree.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
