# Data Structures -> DSU

Union-find for component maintenance, offline connectivity, and Kruskal-style structure building.

- Topic slug: `data-structures/dsu`
- Tutorial page: [Open tutorial](../../../topics/data-structures/dsu/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/data-structures/dsu/README.md)
- Repo problems currently tagged here: `3`
- Repo companion pages: `0`
- Curated external problems: `5`

## Microtopics

- union-find
- path-compression
- union-by-size
- component-query
- kruskal-ready
- rollback-prep

## Learning Sources

| Source | Type |
| --- | --- |
| [AtCoder ACL DSU](https://atcoder.github.io/ac-library/production/document_en/dsu.html) | `Primary` |
| [cp-algorithms DSU](https://cp-algorithms.com/data_structures/disjoint_set_union.html) | `Reference` |
| [USACO Guide DSU](https://usaco.guide/gold/dsu) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [AtCoder Library Practice Contest](https://atcoder.jp/contests/practice2/tasks?lang=en) | `Practice` |
| [CSES Problem Set](https://cses.fi/problemset) | `Practice` |

## Curated External Problems

### Warm-Up

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Disjoint Set Union I](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=en) | `AOJ` | `Easy` | - | Implementation-Heavy | DSU Basics; Component Representatives | Intro; Online-Judge | A classic AOJ DSU starter that is ideal for practicing the raw union-find interface. |

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Building Roads](https://cses.fi/problemset/task/1666) | `CSES` | `Easy` | - | Data-Structure-Heavy; Implementation-Heavy | Connected Components; Union-Find Basics; Graphs | Components; Connectivity | A friendly first DSU problem for merging components and counting how many remain. |
| [Road Construction](https://cses.fi/problemset/task/1676) | `CSES` | `Easy` | - | Data-Structure-Heavy | DSU; Component Sizes; Amortized Complexity | Dynamic-Connectivity; Largest-Component; Component-Size | A classic DSU exercise with incremental edge additions and size tracking. |

### Classics

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Road Reparation](https://cses.fi/problemset/task/1675) | `CSES` | `Medium` | - | Greedy-Heavy; Data-Structure-Heavy | DSU; MST; Sorting Edges | Minimum-Spanning-Tree; Kruskal; MST | A canonical Kruskal benchmark that shows DSU in its most common graph role. |
| [Union Find](https://judge.yosupo.jp/problem/unionfind) | `Library Checker` | `Medium` | - | Data-Structure-Heavy | Path Compression; Union By Size; Online Queries | Connectivity | A clean official benchmark for validating a DSU implementation against a trusted judge. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `C11XU` | Bộ sưu tập đồng xu | `primary` | `hard` | xor-independence; forest selection; augmenting exchange | [Note](../../../practice/ladders/data-structures/dsu/c11xu.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/dsu/c11xu.cpp) |
| `DYNAMICCONNECTIVITY` | Dynamic Connectivity | `secondary` | `hard` | dsu rollback; segment tree over time; offline dynamic connectivity | [Note](../../../practice/ladders/data-structures/dsu-rollback/dynamicconnectivity.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/dsu-rollback/dynamicconnectivity.cpp) |
| `MCQUERY` | MinCut Query | `secondary` | `hard` | all-pairs min-cut; cut tree; count pairs by threshold | [Note](../../../practice/ladders/graphs/gomory-hu/mcquery.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/flow/mcquery.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
