# Data Structures -> Fenwick Tree

Low-level prefix structure for point updates, range sums, compressed coordinates, and order statistics.

- Topic slug: `data-structures/fenwick-tree`
- Tutorial page: [Open tutorial](../../../topics/data-structures/fenwick-tree/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/data-structures/fenwick-tree/README.md)
- Repo problems currently tagged here: `3`
- Curated external problems: `6`

## Microtopics

- lowbit
- point-add
- prefix-sum
- range-sum
- coordinate-compression
- kth-order-statistic

## Learning Sources

| Source | Type |
| --- | --- |
| [AtCoder ACL Fenwick](https://atcoder.github.io/ac-library/production/document_en/fenwicktree.html) | `official docs` |
| [cp-algorithms Fenwick](https://cp-algorithms.com/data_structures/fenwick.html) | `trusted guide` |
| [OI Wiki Fenwick](https://en.oi-wiki.org/ds/fenwick/) | `trusted guide` |

## Practice Sources

| Source | Type |
| --- | --- |
| [AtCoder Library Practice Contest](https://atcoder.jp/contests/practice2/tasks?lang=en) | `problem set` |
| [CSES Problem Set](https://cses.fi/problemset) | `problem set` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Dynamic Range Sum Queries](https://cses.fi/problemset/task/1648) | `CSES` | `Medium` | - | Data-Structure-Heavy; Query-Heavy | Prefix Sums; Point Updates; Binary Indexed Tree | Point-Update; Range-Sum | A standard first Fenwick-tree task with point updates and range sums. |
| [Range Update Queries](https://cses.fi/problemset/task/1651) | `CSES` | `Medium` | - | Data-Structure-Heavy | Difference Arrays; Prefix Sums; Fenwick Tree Basics | Difference Array; Range-Update; Range-Add | A good bridge between difference arrays and Fenwick-style prefix maintenance. |

### Classics

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Point Add Range Sum](https://judge.yosupo.jp/problem/point_add_range_sum) | `Library Checker` | `Medium` | - | Query-Heavy; Data-Structure-Heavy | Fenwick Tree; Point Updates; Prefix Sums | Range-Sum | A concise official benchmark for the core Fenwick use case. |
| [Salary Queries](https://cses.fi/problemset/task/1144) | `CSES` | `Medium` | - | Query-Heavy; Data-Structure-Heavy | Fenwick Tree; Coordinate Compression; Frequency Counting | Coordinate-Compression; Range-Count; Compression; Rank-Query | A canonical frequency-query problem where Fenwick trees shine after compression. |

### Advanced

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Forest Queries II](https://cses.fi/problemset/task/1739) | `CSES` | `Hard` | - | Data-Structure-Heavy; Cross-Topic | Fenwick Tree; 2D Grids; Rectangle Sums | 2D-Fenwick; Rectangle-Query; Grid-Updates; Grid; Point-Update | A strong advanced benchmark for extending Fenwick ideas into two dimensions. |
| [Range Add Range Sum](https://judge.yosupo.jp/problem/range_add_range_sum) | `Library Checker` | `Hard` | - | Query-Heavy; Data-Structure-Heavy | Fenwick Tree Tricks; Difference Arrays; Range Sums | Range-Update | A strong benchmark for the classic two-Fenwick range-add/range-sum pattern. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `CVP00001` | Ô ăn quan | `primary` | `hard` | circular updates; range-add point-query; query-from-initial-state | [Note](../../../practice/ladders/data-structures/fenwick-tree/cvp00001.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/fenwick-tree/cvp00001.cpp) |
| `DISTINCTVALUESQUERIES` | Distinct Values Queries | `secondary` | `hard` | offline right-endpoint sweep; last occurrence activation; fenwick range count | [Note](../../../practice/ladders/data-structures/offline-tricks/distinctvaluesqueries.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/offline-tricks/distinctvaluesqueries.cpp) |
| `RANGEUPDATEQUERIES` | Range Update Queries | `secondary` | `medium` | difference array updates; fenwick on diff; range add point query | [Note](../../../practice/ladders/foundations/difference-arrays/rangeupdatequeries.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/difference-arrays/rangeupdatequeries.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
