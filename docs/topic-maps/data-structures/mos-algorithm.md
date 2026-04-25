# Data Structures -> Mo's Algorithm

Offline range-query ordering for static arrays when one current active interval can be updated cheaply by moving endpoints.

- Topic slug: `data-structures/mos-algorithm`
- Tutorial page: [Open tutorial](../../../topics/data-structures/mos-algorithm/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/data-structures/mos-algorithm/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `4`

## Microtopics

- block-ordering
- snake-order
- current-range
- frequency-maintenance
- symmetric-add-remove
- sqrt-decomposition-order

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms sqrt decomposition / Mo's algorithm](https://cp-algorithms.com/data_structures/sqrt_decomposition.html) | `Reference` |
| [OI Wiki Mo's algorithm intro](https://en.oi-wiki.org/misc/mo-algo-intro/) | `Reference` |
| [USACO Guide square root decomposition](https://usaco.guide/plat/sqrt) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Codeforces problemset](https://codeforces.com/problemset) | `Practice` |
| [Library Checker Static Range Count Distinct](https://judge.yosupo.jp/problem/static_range_count_distinct) | `Practice` |
| [SPOJ DQUERY](https://www.spoj.com/problems/DQUERY/) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Mo's hot sheet](../../../notebook/mos-hot-sheet.md) | `quick reference` |
| [Mo starter route](../../../template-library.md) | `starter route` |
| [Powerful Array note](../../../practice/ladders/data-structures/mos-algorithm/powerfularray.md) | `anchor note` |
| [Offline Tricks tutorial](../../../topics/data-structures/offline-tricks/README.md) | `compare point` |
| [Distinct Values Queries note](../../../practice/ladders/data-structures/offline-tricks/distinctvaluesqueries.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Powerful Array](https://codeforces.com/problemset/problem/86/D) | `Codeforces` | `Hard` | Frequency Maintenance | Query-Heavy; Data-Structure-Heavy | Offline Query Ordering; Current Range Invariant | Range-Frequency; Offline | A famous Mo benchmark where the current answer is one frequency-weighted score and add/remove are true local updates. |

### Practice

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Static Range Count Distinct](https://judge.yosupo.jp/problem/static_range_count_distinct) | `Library Checker` | `Hard` | - | Query-Heavy; Data-Structure-Heavy | Mo's Algorithm; Frequency Counts; Coordinate Compression | Distinct-Count; Offline | An official verifier-style Mo benchmark once ordinary current-range maintenance is trusted. |

### Classics

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [D-query](https://www.spoj.com/problems/DQUERY/) | `SPOJ` | `Hard` | Classic | Query-Heavy; Data-Structure-Heavy | Mo's Algorithm; Frequency Counts; Coordinate Compression | Distinct-Count; Offline Range Queries | The classic static distinct-count Mo problem and a good second rep after one frequency-score benchmark. |

### Bridge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Distinct Values Queries](https://cses.fi/problemset/task/1734) | `CSES` | `Hard` | Compare Point | Query-Heavy; Compare-Point | Mo's Algorithm; Offline Sweeps; Frequency Counts | Distinct-Count; Offline | A deliberate compare point: Mo works, but the monotone right-endpoint sweep is cleaner and should still be preferred. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `POWERFULARRAY` | Powerful Array | `primary` | `hard` | - | [Note](../../../practice/ladders/data-structures/mos-algorithm/powerfularray.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/mos-algorithm/powerfularray.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
