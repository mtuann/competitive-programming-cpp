# Foundations -> STL Basics

Container and algorithm fluency: build the habit of reaching for `vector`, `set`, `map`, iterators, and standard algorithms before writing custom machinery.

- Topic slug: `foundations/stl`
- Tutorial page: [Open tutorial](../../../topics/foundations/cpp-language/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/foundations/stl/README.md)
- Repo problems currently tagged here: `0`
- Curated external problems: `8`

## Microtopics

- vector
- pair-and-tuple
- iterators
- sort
- lower_bound
- set-and-multiset
- map
- priority_queue

## Learning Sources

| Source | Type |
| --- | --- |
| [cppreference containers](https://en.cppreference.com/w/cpp/container) | `official docs` |
| [cppreference algorithms](https://en.cppreference.com/w/cpp/algorithm) | `official docs` |
| [USACO Guide](https://usaco.guide/) | `trusted guide` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Problem Set](https://cses.fi/problemset) | `problem set` |
| [Codeforces data structures tag](https://codeforces.com/problemset?tags=data+structures) | `problem set` |

## Curated External Problems

### Warm-Up

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Distinct Numbers](https://cses.fi/problemset/task/1621) | `CSES` | `Easy` | - | Data-Structure-Heavy; Implementation-Heavy | Arrays; Sets; Hashing Basics | Set; Deduplication; Frequency; Sort; Unique | A straightforward entry point for seeing why a set or hash set is useful. |

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Restaurant Customers](https://cses.fi/problemset/task/1619) | `CSES` | `Easy` | - | Modeling-Heavy; Implementation-Heavy | Sorting; Event Processing; Prefix Counts | Events; Sweep Line; Sorting | Useful for learning to model arrivals and departures as events and process them cleanly. |
| [Towers](https://cses.fi/problemset/task/1073) | `CSES` | `Medium` | - | - | - | Multiset; Lower Bound; Patience | Teaches the lower_bound pattern on a multiset. |

### Classics

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Concert Tickets](https://cses.fi/problemset/task/1091) | `CSES` | `Medium` | - | Data-Structure-Heavy; Greedy-Heavy | Sorting; Ordered Multiset Ideas; Greedy Matching | Multiset; Lower Bound | A canonical ordered-container problem that rewards knowing lower_bound-style queries. |
| [Room Allocation](https://cses.fi/problemset/task/1164) | `CSES` | `Medium` | - | Data-Structure-Heavy; Greedy-Heavy | Sorting; Priority Queues; Interval Scheduling | Priority-Queue; Intervals; Assignment | A strong multiset/priority-queue assignment problem that feels very STL-native. |
| [Traffic Lights](https://cses.fi/problemset/task/1163) | `CSES` | `Medium` | - | Data-Structure-Heavy | Ordered Sets; Interval Reasoning; Sorting | Ordered-Set; Intervals; Updates; Neighbors | A classic ordered-set exercise with dynamic insertions and interval maintenance. |

### Advanced

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Sliding Window Cost](https://cses.fi/problemset/task/1077) | `CSES` | `Hard` | - | Data-Structure-Heavy | Multisets; Two Pointers; Median Reasoning | Median; Sliding-Window; Absolute-Deviation | A deeper ordered-container problem that pairs median maintenance with cost accounting. |
| [Sliding Window Median](https://cses.fi/problemset/task/1076) | `CSES` | `Hard` | - | Data-Structure-Heavy; Query-Heavy | Multisets; Two Pointers; Balanced Data Structures | Multiset; Median; Sliding-Window | A demanding but standard STL benchmark for maintaining order statistics over a moving window. |

## Repo Problems

_No repo note has been tagged to this topic yet._

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
