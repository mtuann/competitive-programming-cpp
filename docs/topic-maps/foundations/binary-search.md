# Foundations -> Binary Search

Search on sorted data and on monotone answers: learn the invariant-first template before memorizing implementations.

- Topic slug: `foundations/binary-search`
- Tutorial page: [Open tutorial](../../../topics/foundations/patterns/binary-search/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/foundations/binary-search/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `0`
- Curated external problems: `6`

## Microtopics

- lower_bound
- upper_bound
- first-true
- last-true
- answer-search
- overflow
- continuous-bsearch

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms binary search](https://cp-algorithms.com/num_methods/binary_search.html) | `trusted guide` |
| [USACO Guide binary search](https://usaco.guide/silver/binary-search) | `trusted guide` |
| [Codeforces EDU binary search](https://codeforces.com/blog/entry/81729) | `course` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Codeforces binary-search tag](https://codeforces.com/problemset?tags=binary+search) | `problem set` |
| [CSES Problem Set](https://cses.fi/problemset) | `problem set` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [032 - Binary Search](https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_ad) | `AtCoder` | `Easy` | - | - | - | Membership; Sorted-Array | Official warmup for binary search on sorted data. |
| [C - Buy an Integer](https://atcoder.jp/contests/abc146/tasks/abc146_c) | `AtCoder` | `Medium` | - | - | - | Digit-Length; Math | Search over a monotone price function. |

### Classics

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Array Division](https://cses.fi/problemset/task/1085) | `CSES` | `Medium` | - | Proof-Heavy; Greedy-Heavy | Binary Search; Greedy Feasibility Checks; Arrays | Binary-Search-On-Answer; Partitioning; Greedy-Check; Partition | A standard partitioning benchmark that teaches how to build a monotone check. |
| [Factory Machines](https://cses.fi/problemset/task/1620) | `CSES` | `Medium` | - | Proof-Heavy; Math-Heavy | Binary Search; Monotone Predicates; Prefix Counting | Binary-Search-On-Answer; Monotonicity; Counting; Monotone-Predicate; Minimize-Answer | A canonical binary-search-on-answer problem with a clean monotone feasibility check. |
| [Magic Powder - 2](https://codeforces.com/problemset/problem/670/D) | `Codeforces` | `Medium` | - | Proof-Heavy; Greedy-Heavy | Binary Search; Greedy Checks; Resource Counting | Binary-Search-On-Answer; Resource-Feasibility | A popular feasibility-search problem with a very reusable binary-search pattern. |
| [Maximum Median](https://codeforces.com/problemset/problem/1201/C) | `Codeforces` | `Medium` | - | Proof-Heavy; Math-Heavy | Binary Search; Median Reasoning; Greedy | Binary-Search-On-Answer; Median | A classic binary-search benchmark where the objective is to maximize a median value. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `FACTORYMACHINES` | Factory Machines | `primary` | `medium` | answer binary search; monotone feasibility; production rate accumulation | [Note](../../../practice/ladders/foundations/binary-search/factorymachines.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/binary-search/factorymachines.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
