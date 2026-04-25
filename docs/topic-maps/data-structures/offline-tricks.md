# Data Structures -> Offline Tricks

Sort events, reorder queries, and use rollback or CDQ to trade interactivity for structure.

- Topic slug: `data-structures/offline-tricks`
- Tutorial page: [Open tutorial](../../../topics/data-structures/offline-tricks/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/data-structures/offline-tricks/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `0`
- Curated external problems: `7`

## Microtopics

- offline-sort
- sweep-line
- event-processing
- cdq
- rollback-dsu
- compress-coordinates

## Learning Sources

| Source | Type |
| --- | --- |
| [USACO Guide offline deletion](https://usaco.guide/adv/offline-del) | `Reference` |
| [USACO Guide range queries with sweep line](https://usaco.guide/plat/range-sweep) | `Reference` |
| [OI Wiki CDQ divide and conquer](https://en.oi-wiki.org/misc/cdq-divide/) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Problem Set](https://cses.fi/problemset) | `Practice` |
| [CSES Range Interval Queries](https://cses.fi/problemset/task/3163) | `Practice` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Static Range Count Distinct](https://judge.yosupo.jp/problem/static_range_count_distinct) | `Library Checker` | `Hard` | - | - | - | Mo's Algorithm; Distinct-Count | Official Mo's algorithm benchmark. |
| [Point Add Rectangle Sum](https://judge.yosupo.jp/problem/point_add_rectangle_sum) | `Library Checker` | `Very Hard` | - | - | - | Sweep Line; Fenwick | Canonical offline sweep-line plus BIT. |

### Classics

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Distinct Values Queries](https://cses.fi/problemset/task/1734) | `CSES` | `Hard` | - | Query-Heavy; Data-Structure-Heavy | Mo's Algorithm; Frequency Counts; Offline Query Ordering | Mo's Algorithm; Range-Distinct; Frequency | A canonical offline range-query problem and one of the best Mo's algorithm benchmarks. |
| [Powerful Array](https://codeforces.com/problemset/problem/86/D) | `Codeforces` | `Hard` | - | Query-Heavy; Data-Structure-Heavy | Mo's Algorithm; Frequency Maintenance; Range Queries | Mo's Algorithm; Range-Frequency | A famous Mo's algorithm benchmark with a memorable scoring function. |

### Advanced

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Rectangle Sum](https://judge.yosupo.jp/problem/rectangle_sum) | `Library Checker` | `Medium` | - | Query-Heavy; Modeling-Heavy | Offline Sweeps; Fenwick Tree; 2D Range Counting | Sweep Line; 2D-Queries; Fenwick | A clean official benchmark for offline sweep-line style query processing. |
| [Distinct Values Queries II](https://cses.fi/problemset/task/3356) | `CSES` | `Hard` | - | Query-Heavy; Data-Structure-Heavy | Offline Thinking; Fenwick Tree; Last-Occurrence Reasoning | Updates; Distinctness; Query-Processing | A stronger follow-up that pushes the same distinctness theme into a dynamic setting. |

### Cross-Topic

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Salary Queries](https://cses.fi/problemset/task/1144) | `CSES` | `Medium` | - | Query-Heavy; Data-Structure-Heavy | Coordinate Compression; Fenwick Tree; Range Counting | Coordinate-Compression; Range-Count; Updates; Fenwick | A very teachable query problem that often becomes much easier once values are compressed. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `DISTINCTVALUESQUERIES` | Distinct Values Queries | `primary` | `hard` | offline right-endpoint sweep; last occurrence activation; fenwick range count | [Note](../../../practice/ladders/data-structures/offline-tricks/distinctvaluesqueries.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/offline-tricks/distinctvaluesqueries.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
