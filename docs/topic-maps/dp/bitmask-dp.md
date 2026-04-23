# DP -> Bitmask DP

Compress small subsets into bitmasks and reason about transitions over subsets, submasks, or profiles.

- Topic slug: `dp/bitmask-dp`
- Tutorial page: [Open tutorial](../topics/dp/bitmask-dp/README.md)
- Ladder page: [Open ladder](../practice/ladders/dp/bitmask-dp/README.md)
- Repo problems currently tagged here: `1`
- Curated external problems: `11`

## Microtopics

- subset-dp
- submask-enumeration
- hamiltonian-dp
- matching-dp
- profile-dp
- sos-dp

## Learning Sources

| Source | Type |
| --- | --- |
| [USACO Guide Bitmask DP](https://usaco.guide/gold/dp-bitmasks) | `trusted guide` |
| [OI Wiki state compression DP](https://en.oi-wiki.org/dp/state/) | `trusted guide` |
| [USACO Guide broken profile](https://usaco.guide/adv/dp-broken-profile) | `trusted guide` |

## Practice Sources

| Source | Type |
| --- | --- |
| [AtCoder DP O](https://atcoder.jp/contests/dp/tasks/dp_o) | `problem` |
| [CSES Elevator Rides](https://cses.fi/problemset/task/1653/) | `problem` |
| [CSES Counting Tilings](https://cses.fi/problemset/task/2181/) | `problem` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Travelling Salesman Problem](https://atcoder.jp/contests/abc406/tasks/abc406_g) | `AtCoder Beginner Contest 406` | `Hard` | - | - | - | TSP | canonical TSP with visited-set state |

### Covering With Subsets

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Moovie Mooving](https://usaco.org/index.php?cpid=515&page=viewproblem2) | `USACO Gold` | `Medium` | Coverage-DP | Tabulation | Bitmask States; Interval Reasoning | Interval-Coverage | Uses subset state to model which movies have been chosen and how far coverage extends. |

### Gift Reassignment

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Redistributing Gifts](https://usaco.org/index.php?cpid=1209&page=viewproblem2) | `USACO Gold` | `Hard` | Assignment-DP | Tabulation | Matching DP; Subset Transitions | Permutations | A strong bitmask assignment problem where feasibility is driven by subset reachability. |

### Hamiltonian Path Counting

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Hamiltonian Flights](https://cses.fi/problemset/task/1690) | `CSES` | `Hard` | Graph-Subset-DP | Tabulation | Graph Basics; Subset Iteration | Graph; State Compression; Hamiltonian Path | visit-every-node exactly once |

### Merge Subsets

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Grouping](https://atcoder.jp/contests/dp/tasks/dp_u) | `AtCoder DP Contest` | `Hard` | Subset-Partition | Tabulation | Subset Iteration; Memoization | Partition | A clean example of combining masks by iterating over all strict subsets. |

### Minimum Cover

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Smallest Sufficient Team](https://leetcode.com/problems/smallest-sufficient-team) | `LeetCode` | `Hard` | Cover-DP | Tabulation | Bitmask States; Set Cover Intuition | Set-Cover | A compact bitmask cover DP that is excellent for practicing subset-to-solution reconstruction. |

### Perfect Matching Count

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Matching](https://atcoder.jp/contests/dp/tasks/dp_o) | `AtCoder DP Contest` | `Medium` | Assignment-DP | Tabulation | Bitmask States; Combinatorics | Matching; Assignment; State Compression; Perfect Matching | A textbook assignment DP where masks naturally represent assigned rows or columns. |

### Safety Constrained Subset

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Guard Mark](https://usaco.org/index.php?cpid=494&page=viewproblem2) | `USACO Gold` | `Medium` | Subset-Selection | Tabulation | Subset DP; Sorting | Stacking | A classic small-n bitmask problem where each subset carries a summary of feasibility and quality. |

### Small N Graph Editing

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Friendship Editing](https://usaco.org/index.php?cpid=1499&page=viewproblem2) | `USACO Gold` | `Hard` | Graph-Subset-DP | Tabulation | Graph States; Subset Enumeration | Graphs | A good hard-level subset graph DP where every candidate structure is evaluated on masks. |

### State Compressed Traversal

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Shortest Path Visiting All Nodes](https://leetcode.com/problems/shortest-path-visiting-all-nodes) | `LeetCode` | `Hard` | Graph-Search | BFS; State-Compression | Graph Traversal; Shortest Path Basics | BFS | A very common state-compressed shortest-path problem that pairs naturally with bitmask DP thinking. |

### Subset Packing

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Elevator Rides](https://cses.fi/problemset/task/1653) | `CSES` | `Hard` | Subset-Packaging | Tabulation | Subset Sum; State Compression | Packing; Subset DP | classic compressed-state packing DP |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `VMMARBLE` | Phân loại bi | `primary` | `medium` | final-color assignment; residual-state dp; capacity-2 moves | [Note](../practice/ladders/dp/bitmask-dp/vmmarble.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/bitmask-dp/vmmarble.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
