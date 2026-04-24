# Data Structures -> Heaps And Ordered Sets

Use heaps, sets, and multisets to maintain online minima/maxima, medians, and active sets.

- Topic slug: `data-structures/heaps-and-ordered-sets`
- Tutorial page: [Open tutorial](../../../topics/data-structures/heaps-and-ordered-sets/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/data-structures/heaps-and-ordered-sets/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `0`
- Curated external problems: `7`

## Microtopics

- max-heap
- min-heap
- multiset
- lower_bound
- erase-one
- ordered-iteration
- median-maintenance

## Learning Sources

| Source | Type |
| --- | --- |
| [cppreference priority_queue](https://en.cppreference.com/w/cpp/container/priority_queue) | `official docs` |
| [cppreference set](https://en.cppreference.com/w/cpp/container/set) | `official docs` |
| [USACO Guide sorted sets](https://usaco.guide/gold/intro-sorted-sets) | `trusted guide` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Codeforces data structures tag](https://codeforces.com/problemset?tags=data+structures) | `problem set` |
| [CSES Problem Set](https://cses.fi/problemset) | `problem set` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Restaurant Customers](https://cses.fi/problemset/task/1619) | `CSES` | `Easy` | - | Modeling-Heavy | Sorting; Event Sweeps; Prefix Counts | Events; Sweep Line; Maximum-Overlap | A simple and popular event-processing problem that pairs naturally with ordered scans. |
| [Room Allocation](https://cses.fi/problemset/task/1164) | `CSES` | `Medium` | - | Greedy-Heavy; Data-Structure-Heavy | Priority Queues; Sorting; Interval Scheduling | Priority-Queue; Interval-Scheduling; Assignment | A classic heap-based assignment problem with a very practical greedy pattern. |
| [Movie Festival II](https://cses.fi/problemset/task/1632) | `CSES` | `Hard` | - | - | - | Multiset; K-Members | A canonical multi-assign scheduling problem. |

### Classics

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Concert Tickets](https://cses.fi/problemset/task/1091) | `CSES` | `Medium` | - | Data-Structure-Heavy; Greedy-Heavy | Ordered Sets; Greedy Matching; Lower Bound | Multiset; Predecessor-Query; Lower Bound | A classic ordered-set exercise for predecessor queries under deletions. |
| [Traffic Lights](https://cses.fi/problemset/task/1163) | `CSES` | `Medium` | - | Data-Structure-Heavy | Ordered Sets; Interval Maintenance; Multisets | Ordered-Set; Intervals; Max-Gap; Neighbors | A well-known benchmark for maintaining gaps between ordered points. |

### Advanced

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Sliding Window Cost](https://cses.fi/problemset/task/1077) | `CSES` | `Hard` | - | Data-Structure-Heavy | Median Maintenance; Multisets; Sliding Windows | Median; Absolute-Deviation | A more demanding ordered-structure problem that extends median maintenance into cost tracking. |
| [Sliding Window Median](https://cses.fi/problemset/task/1076) | `CSES` | `Hard` | - | Data-Structure-Heavy | Priority Queues; Multisets; Window Maintenance | Median; Sliding-Window | A strong benchmark for maintaining order statistics with heap-like containers. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `CONCERTTICKETS` | Concert Tickets | `primary` | `medium` | multiset predecessor; erase one occurrence; greedy ticket assignment | [Note](../../../practice/ladders/data-structures/heaps-and-ordered-sets/concerttickets.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/heaps-and-ordered-sets/concerttickets.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
