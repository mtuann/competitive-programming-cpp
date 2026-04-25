# Foundations -> Difference Arrays

A range-update perspective on prefix sums: store changes at boundaries, then recover the real array by taking prefixes.

- Topic slug: `foundations/difference-arrays`
- Tutorial page: [Open tutorial](../../../topics/foundations/patterns/difference-arrays/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/foundations/difference-arrays/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `0`
- Curated external problems: `5`

## Microtopics

- difference-array
- range-add
- point-query
- restore-by-prefix
- 2d-difference
- imos

## Learning Sources

| Source | Type |
| --- | --- |
| [OI Wiki prefix sum and adjacent difference](https://en.oi-wiki.org/basic/prefix-sum/) | `Reference` |
| [USACO Guide more prefix sums](https://usaco.guide/silver/more-prefix-sums) | `Reference` |
| [cppreference adjacent_difference](https://en.cppreference.com/w/cpp/algorithm/adjacent_difference) | `Primary` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Range Update Queries](https://cses.fi/problemset/task/1651/) | `Practice` |
| [CSES Problem Set](https://cses.fi/problemset) | `Practice` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [D - Water Heater](https://atcoder.jp/contests/abc183/tasks/abc183_d) | `AtCoder` | `Medium` | Imos | - | - | Difference Array; Sweep Line; Events | A clean event-sweep difference-array problem. |
| [Range Update Queries](https://cses.fi/problemset/task/1651) | `CSES` | `Medium` | Difference Array | Implementation-Heavy | Difference Arrays; Prefix Sums; Range Updates | Range-Add; Point-Query | The standard entry point for using a difference array to turn range updates into prefix scans. |
| [D - Snuke Prime](https://atcoder.jp/contests/abc188/tasks/abc188_d) | `AtCoder` | `Hard` | Imos | - | - | Difference Array; Sweep Line; Interval-Cost | Sparse endpoints, then prefix accumulation. |

### Classics

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Greg and Array](https://codeforces.com/problemset/problem/295/A) | `Codeforces` | `Medium` | - | Modeling-Heavy; Implementation-Heavy | Difference Arrays; Prefix Sums; Offline Processing | Difference Array; Offline; Range-Operations | A strong benchmark for applying difference arrays both on operations and on the final array. |
| [Little Girl and Maximum Sum](https://codeforces.com/problemset/problem/276/C) | `Codeforces` | `Medium` | - | Greedy-Heavy; Math-Heavy | Difference Arrays; Sorting; Prefix Counts | Difference Array; Sorting; Frequency | A classic frequency-by-intervals problem where the difference array makes the key idea obvious. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `RANGEUPDATEQUERIES` | Range Update Queries | `primary` | `medium` | difference array updates; fenwick on diff; range add point query | [Note](../../../practice/ladders/foundations/difference-arrays/rangeupdatequeries.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/difference-arrays/rangeupdatequeries.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
