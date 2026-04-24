# Foundations -> Prefix Sums

Turn many range questions into subtraction of precomputed aggregates, then layer counting tricks on top.

- Topic slug: `foundations/prefix-sums`
- Tutorial page: [Open tutorial](../../../topics/foundations/patterns/prefix-sums/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/foundations/prefix-sums/README.md)
- Repo problems currently tagged here: `3`
- Repo companion pages: `3`
- Curated external problems: `6`

## Microtopics

- 1d-prefix
- 2d-prefix
- prefix-xor
- subarray-sum
- frequency-prefix
- mod-prefix

## Learning Sources

| Source | Type |
| --- | --- |
| [USACO Guide intro prefix sums](https://usaco.guide/silver/prefix-sums) | `Reference` |
| [USACO Guide more prefix sums](https://usaco.guide/silver/more-prefix-sums) | `Reference` |
| [OI Wiki prefix sum and adjacent difference](https://en.oi-wiki.org/basic/prefix-sum/) | `Reference` |

## Practice And Follow-Up Sources

| Source | Type |
| --- | --- |
| [CSES Problem Set](https://cses.fi/problemset) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Foundations cheatsheet](../../../notebook/foundations-cheatsheet.md) | `quick reference` |
| [Static Range Sum Queries note](../../../practice/ladders/foundations/prefix-sums/staticrangesumqueries.md) | `anchor note` |
| [Templates overview](../../../template-library.md) | `template guide` |

## Curated External Problems

### Warm-Up

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Static Range Sum Queries](https://cses.fi/problemset/task/1646) | `CSES` | `Easy` | - | Implementation-Heavy | Prefix Sums; Indexing; Arrays | Range-Sum; Prefix-Sum; Range-Query; Precompute | The simplest possible range-sum baseline for learning prefix preprocessing. |

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Range Xor Queries](https://cses.fi/problemset/task/1650) | `CSES` | `Easy` | - | - | - | Prefix-XOR; Range-Query; Bitwise | Same template, but with xor accumulation. |
| [Subarray Sums I](https://cses.fi/problemset/task/1660) | `CSES` | `Medium` | - | Implementation-Heavy | Prefix Sums; Positive Arrays; Sliding Window | Two-Pointers; Subarrays | A classic positive-array sliding-window problem that is really prefix sums in disguise. |
| [Subarray Sums II](https://cses.fi/problemset/task/1661) | `CSES` | `Medium` | - | Implementation-Heavy; Math-Heavy | Prefix Sums; Hash Maps; Counting | Hash-Map; Subarrays | A standard prefix-sum counting problem that generalizes the idea beyond positive numbers. |

### Classics

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Subarray Divisibility](https://cses.fi/problemset/task/1662) | `CSES` | `Medium` | - | Math-Heavy | Prefix Sums; Modular Arithmetic; Frequency Counting | Mod Arithmetic; Counting | A canonical prefix-sum-plus-modulo benchmark that shows why equal remainders matter. |

### Cross-Topic

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Forest Queries](https://cses.fi/problemset/task/1652) | `CSES` | `Medium` | - | Modeling-Heavy; Query-Heavy | Prefix Sums; 2D Grids; Rectangle Inclusion-Exclusion | 2D Prefix Sums; Rectangles; Rectangle-Query; Grid | A great 2D prefix-sum benchmark with a very reusable inclusion-exclusion pattern. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `CVP00001` | Ô ăn quan | `secondary` | `hard` | circular updates; range-add point-query; query-from-initial-state | [Note](../../../practice/ladders/data-structures/fenwick-tree/cvp00001.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/fenwick-tree/cvp00001.cpp) |
| `PREFIXSUMADDICTS` | Prefix Sum Addicts | `secondary` | `medium` | suffix prefix differences; sorted sequence feasibility; first block capacity bound | [Note](../../../practice/ladders/greedy/prefix-constraints/prefixsumaddicts.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/greedy/prefix-constraints/prefixsumaddicts.cpp) |
| `STATICRANGESUMQUERIES` | Static Range Sum Queries | `primary` | `easy` | prefix sum build; range sum by subtraction; immutable array queries | [Note](../../../practice/ladders/foundations/prefix-sums/staticrangesumqueries.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/prefix-sums/staticrangesumqueries.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
