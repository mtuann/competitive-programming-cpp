# Foundations -> Complexity And Invariants

Reasoning tools for contests: estimate time honestly, define loop invariants, and learn to justify greedy and implementation choices before coding.

- Topic slug: `foundations/complexity-and-invariants`
- Tutorial page: [Open tutorial](../../../topics/foundations/reasoning/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/foundations/complexity-and-invariants/README.md)
- Repo problems currently tagged here: `3`
- Repo companion pages: `1`
- Curated external problems: `8`

## Microtopics

- asymptotic-estimation
- worst-case-thinking
- amortized-analysis
- loop-invariants
- exchange-arguments
- counterexamples
- proof-by-induction

## Learning Sources

| Source | Type |
| --- | --- |
| [MIT 6.006](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/) | `course` |
| [Principles of Algorithmic Problem Solving](https://usaco.guide/PAPS.pdf) | `reference` |
| [Competitive Programmer's Handbook](https://usaco.guide/CPH.pdf) | `reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Problem Set](https://cses.fi/problemset) | `problem set` |
| [USACO contest archive](https://usaco.org/index.php?page=contests) | `contest archive` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Foundations cheatsheet](../../../notebook/foundations-cheatsheet.md) | `quick reference` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Collecting Numbers](https://cses.fi/problemset/task/2216) | `CSES` | `Easy` | - | Proof-Heavy; Implementation-Heavy | Permutations; Index Mapping; Loop Invariants | Permutations; Position-Mapping; Positions | Good practice for turning a process into a simple invariant over positions. |
| [Missing Coin Sum](https://cses.fi/problemset/task/2183) | `CSES` | `Medium` | - | - | - | Sorting | Classic smallest-unreachable-sum invariant. |
| [Stick Lengths](https://cses.fi/problemset/task/1074) | `CSES` | `Medium` | - | - | - | Median; Absolute-Deviation; Sorting | Shows why the median is optimal. |
| [Collecting Numbers II](https://cses.fi/problemset/task/2217) | `CSES` | `Hard` | - | - | - | Updates; Swap-Delta | Same invariant, but maintained under swaps. |

### Variants

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Distinct Values Subarrays](https://cses.fi/problemset/task/3420) | `CSES` | `Medium` | - | Proof-Heavy; Implementation-Heavy | Two Pointers; Frequency Counts; Subarray Reasoning | Two-Pointers; Distinctness; Subarrays | A good bridge from basic sliding windows to counting arguments based on a maintained invariant. |
| [Playlist](https://cses.fi/problemset/task/1141) | `CSES` | `Medium` | - | Proof-Heavy; Data-Structure-Heavy | Two Pointers; Hash Maps; Amortized Analysis | Sliding-Window; Distinctness; Amortized-Analysis | A neat amortized two-pointer invariant problem with a clean linear-time proof. |

### Classics

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Towers](https://cses.fi/problemset/task/1073) | `CSES` | `Medium` | - | Proof-Heavy; Data-Structure-Heavy | Greedy Reasoning; Binary Search; Sorted Containers | Patience-Sorting; Lower Bound | A classic proof-oriented greedy where the invariant is the sorted tower tops. |

### Theory / Course

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Increasing Array](https://cses.fi/problemset/task/1094) | `CSES` | `Easy` | - | Proof-Heavy; Greedy-Heavy | Greedy Reasoning; Prefix Invariants; Arrays | Prefix-Maintenance; Prefix-Max | A compact proof-by-invariant problem that rewards understanding why the greedy step is optimal. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `FACTORYMACHINES` | Factory Machines | `secondary` | `medium` | answer binary search; monotone feasibility; production rate accumulation | [Note](../../../practice/ladders/foundations/binary-search/factorymachines.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/binary-search/factorymachines.cpp) |
| `INCREASINGARRAY` | Increasing Array | `primary` | `easy` | loop invariant scan; greedy repair; running maximum maintenance | [Note](../../../practice/ladders/foundations/complexity-and-invariants/increasingarray.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/complexity-and-invariants/increasingarray.cpp) |
| `MOVIEFESTIVAL` | Movie Festival | `secondary` | `easy` | finish-time sorting; interval scheduling; exchange argument greedy | [Note](../../../practice/ladders/foundations/sorting/moviefestival.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/sorting/moviefestival.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
