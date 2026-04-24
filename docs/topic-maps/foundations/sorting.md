# Foundations -> Sorting

Sorting as a modeling tool: order data to expose monotonicity, simplify sweeps, or make greedy decisions provable.

- Topic slug: `foundations/sorting`
- Tutorial page: [Open tutorial](../../../topics/foundations/patterns/sorting/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/foundations/sorting/README.md)
- Repo problems currently tagged here: `3`
- Repo companion pages: `0`
- Curated external problems: `7`

## Microtopics

- custom-comparator
- stable-sort
- pair-sorting
- event-sorting
- coordinate-compression

## Learning Sources

| Source | Type |
| --- | --- |
| [OI Wiki sorting intro](https://en.oi-wiki.org/basic/sort-intro/) | `trusted guide` |
| [cppreference std::sort](https://en.cppreference.com/w/cpp/algorithm/sort) | `official docs` |
| [Competitive Programmer's Handbook](https://usaco.guide/CPH.pdf) | `reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Problem Set](https://cses.fi/problemset) | `problem set` |
| [Codeforces sortings tag](https://codeforces.com/problemset?tags=sortings) | `problem set` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Apartments](https://cses.fi/problemset/task/1084) | `CSES` | `Easy` | - | Greedy-Heavy; Implementation-Heavy | Sorting; Two Pointers; Greedy Matching | Two-Pointers; Matching; Sort | A classic sorted two-pointer matching problem with a very clean greedy proof. |
| [Movie Festival](https://cses.fi/problemset/task/1629) | `CSES` | `Easy` | - | Greedy-Heavy | Sorting; Interval Scheduling; Greedy | Intervals; Sort | A textbook interval-scheduling problem that rewards sorting by finish time. |
| [Reading Books](https://cses.fi/problemset/task/1631) | `CSES` | `Easy` | - | Greedy-Heavy | Sorting; Greedy Scheduling; Prefix Sums | Scheduling | A nice example of sorting plus a simple optimization argument. |
| [Tasks and Deadlines](https://cses.fi/problemset/task/1630) | `CSES` | `Medium` | - | - | - | Sort; Ordering | A very standard sort-by-duration optimization. |

### Classics

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Ferris Wheel](https://cses.fi/problemset/task/1090) | `CSES` | `Easy` | - | Greedy-Heavy | Sorting; Pairing; Two Pointers | Two-Pointers; Pairing; Sort | One of the most recognizable introductory sorting-and-greedy pairings. |
| [Stick Lengths](https://cses.fi/problemset/task/1074) | `CSES` | `Medium` | - | Math-Heavy; Greedy-Heavy | Sorting; Median; Absolute Deviations | Median; Absolute-Deviation | A classic benchmark for the median-minimizes-L1-cost idea after sorting. |

### Advanced

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Nested Ranges Check](https://cses.fi/problemset/task/2168) | `CSES` | `Medium` | - | Proof-Heavy; Greedy-Heavy | Sorting; Interval Containment; Sweep-Line Ideas | Intervals; Containment | A strong sorting problem where handling interval order and ties is the main challenge. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `APARTMENTS` | Apartments | `secondary` | `easy-medium` | two sorted pointers; tolerance matching; greedy monotone scan | [Note](../../../practice/ladders/foundations/two-pointers/apartments.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/two-pointers/apartments.cpp) |
| `MOVIEFESTIVAL` | Movie Festival | `primary` | `easy` | finish-time sorting; interval scheduling; exchange argument greedy | [Note](../../../practice/ladders/foundations/sorting/moviefestival.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/sorting/moviefestival.cpp) |
| `SUMOFTWOVALUES` | Sum of Two Values | `secondary` | `medium` | sort and scan; opposite end pointers; index restoration | [Note](../../../practice/ladders/foundations/two-pointers/sumoftwovalues.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/two-pointers/sumoftwovalues.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
