# Data Structures -> Segment Tree

General range query/update structure built on monoids and lazy propagation, with tree walking for advanced queries.

- Topic slug: `data-structures/segment-tree`
- Tutorial page: [Open tutorial](../../../topics/data-structures/segment-tree/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/data-structures/segment-tree/README.md)
- Repo problems currently tagged here: `3`
- Repo companion pages: `0`
- Curated external problems: `8`

## Microtopics

- monoid
- build
- point-update
- range-query
- lazy-propagation
- tree-walking
- max_right

## Learning Sources

| Source | Type |
| --- | --- |
| [AtCoder ACL Segtree](https://atcoder.github.io/ac-library/production/document_en/segtree.html) | `official docs` |
| [cp-algorithms segment tree](https://cp-algorithms.com/data_structures/segment_tree.html) | `trusted guide` |
| [OI Wiki segment tree](https://en.oi-wiki.org/ds/seg/) | `trusted guide` |

## Practice Sources

| Source | Type |
| --- | --- |
| [AtCoder Library Practice Contest](https://atcoder.jp/contests/practice2/tasks?lang=en) | `problem set` |
| [CSES Problem Set](https://cses.fi/problemset) | `problem set` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Dynamic Range Minimum Queries](https://cses.fi/problemset/task/1649) | `CSES` | `Medium` | - | Data-Structure-Heavy | Segment Tree Basics; Min Monoid; Updates | Range-Min; Point-Update | A direct min-query counterpart to the range-sum baseline. |
| [Dynamic Range Sum Queries](https://cses.fi/problemset/task/1648) | `CSES` | `Medium` | - | Data-Structure-Heavy; Query-Heavy | Segment Tree Basics; Range Aggregation; Updates | Point-Update; Range-Sum | A standard point-update/range-query baseline for segment trees. |

### Classics

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Hotel Queries](https://cses.fi/problemset/task/1143) | `CSES` | `Medium` | - | Data-Structure-Heavy; Greedy-Heavy | Segment Tree; Binary Search On Tree; Greedy Assignment | First-Fit; Prefix-Max; Max-Query | A classic first-position query problem that is very segment-tree friendly. |
| [Prefix Sum Queries](https://cses.fi/problemset/task/2166) | `CSES` | `Hard` | - | Query-Heavy; Data-Structure-Heavy | Segment Trees; Prefix Sums; Max-Prefix Maintenance | Prefix-Max; Range-Query | A strong benchmark for maintaining multiple aggregate values per segment. |

### Advanced

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Point Set Range Composite](https://judge.yosupo.jp/problem/point_set_range_composite) | `Library Checker` | `Hard` | - | Query-Heavy; Data-Structure-Heavy | Segment Tree; Monoids; Function Composition | Function-Composition | A strong official benchmark for monoid segment trees beyond numeric aggregates. |
| [Polynomial Queries](https://cses.fi/problemset/task/1736) | `CSES` | `Hard` | - | Data-Structure-Heavy; Math-Heavy | Lazy Propagation; Segment Trees; Range Arithmetic | Lazy-Propagation; Range-Add; Arithmetic-Progression; Range-Update | A memorable advanced benchmark for non-uniform range updates and sum queries. |
| [Range Updates and Sums](https://cses.fi/problemset/task/1735) | `CSES` | `Hard` | - | Data-Structure-Heavy | Lazy Propagation; Segment Tree Merges; Range Updates | Lazy-Propagation; Range-Add; Range-Assign | A high-value lazy-propagation benchmark with both add and assign operations. |
| [Subarray Sum Queries](https://cses.fi/problemset/task/1190) | `CSES` | `Hard` | - | Data-Structure-Heavy; Query-Heavy | Segment Trees; Kadane-Style Merging; Point Updates | Max-Subarray; Point-Update | A classic advanced segment-tree problem for storing subarray summary states. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `DYNAMICRANGESUMQUERIES` | Dynamic Range Sum Queries | `primary` | `medium` | iterative segment tree; point assignment; range sum query | [Note](../../../practice/ladders/data-structures/segment-tree/dynamicrangesumqueries.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/segment-tree/dynamicrangesumqueries.cpp) |
| `PATHQUERIES2` | Path Queries II | `secondary` | `medium` | heavy light decomposition; path query decomposition; segment tree on base array | [Note](../../../practice/ladders/graphs/hld/pathqueries2.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/hld/pathqueries2.cpp) |
| `VMWTREE` | Lại là cây khung | `secondary` | `hard` | path reverse; path sequence queries; heavy-light decomposition | [Note](../../../practice/ladders/graphs/trees/vmwtree.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/trees/vmwtree.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
