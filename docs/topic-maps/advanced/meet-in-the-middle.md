# Advanced -> Meet-In-The-Middle

Split a subset-like exact search into two halves, enumerate exact half summaries, and merge them faster than full 2^n brute force.

- Topic slug: `advanced/meet-in-the-middle`
- Tutorial page: [Open tutorial](../../../topics/advanced/meet-in-the-middle/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/advanced/meet-in-the-middle/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `3`
- Curated external problems: `3`

## Microtopics

- half-enumeration
- subset-sums
- sort-and-merge
- hash-merge
- n-around-40
- sqrt-state-space

## Learning Sources

| Source | Type |
| --- | --- |
| [USACO Guide meet in the middle](https://usaco.guide/gold/meet-in-the-middle?lang=cpp) | `Reference` |
| [Competitive Programmer's Handbook](https://www.cses.fi/book/book.pdf) | `Reference` |
| [Jeff Erickson - Algorithms](https://jeffe.cs.illinois.edu/teaching/algorithms/index.html) | `Course` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Meet in the Middle](https://cses.fi/problemset/task/1628) | `Practice` |
| [SPOJ SUBSUMS](https://www.spoj.com/problems/SUBSUMS/) | `Practice` |
| [AtCoder ABC184 F](https://atcoder.jp/contests/abc184/tasks/abc184_f) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Meet-In-The-Middle hot sheet](../../../notebook/meet-in-the-middle-hot-sheet.md) | `quick reference` |
| [Meet in the Middle note](../../../practice/ladders/advanced/meet-in-the-middle/meetinthemiddle.md) | `anchor note` |
| [Discrete Log note](../../../practice/ladders/math/bsgs-discrete-log/discretelogarithmmod.md) | `algebraic compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Meet in the Middle](https://cses.fi/problemset/task/1628) | `CSES` | `Medium-Hard` | Mitm | Exact Search; Sort-And-Merge | Subset Enumeration; Binary Search | Subset-Sum; Counting | The cleanest internal anchor for the classic half-sum enumeration route. |
| [Programming Contest](https://atcoder.jp/contests/abc184/tasks/abc184_f) | `AtCoder` | `Medium-Hard` | Mitm | Exact Search; Optimization | Subset Enumeration; Binary Search | Best-Feasible-Sum; Binary Search | A standard best-sum-no-more-than-S route where the merge is about best feasible complement rather than multiplicity. |

### Classics

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [SUBSUMS](https://www.spoj.com/problems/SUBSUMS/) | `SPOJ` | `Medium-Hard` | Mitm | Exact Search; Counting | Subset Enumeration; Sorting | Subset-Sum; Range Counting | A classic SPOJ benchmark for half-sum generation with a counting-flavored merge. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `MEETINTHEMIDDLE` | Meet in the Middle | `primary` | `medium-hard` | - | [Note](../../../practice/ladders/advanced/meet-in-the-middle/meetinthemiddle.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/meet-in-the-middle/meetinthemiddle.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
