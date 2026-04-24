# DP -> Sliding Window And Window DP

Problems where a moving window carries state, costs, or feasibility information that updates incrementally.

- Topic slug: `dp/sliding-window`
- Tutorial page: [Open tutorial](../../../topics/foundations/patterns/two-pointers/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/dp/sliding-window/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `0`
- Curated external problems: `16`

## Microtopics

- window-cost
- monotone-window
- two-multiset-maintenance
- amortized-updates
- window-dp-state
- nested-intervals

## Learning Sources

| Source | Type |
| --- | --- |
| [USACO Guide two pointers](https://usaco.guide/silver/two-pointers) | `trusted guide` |
| [Competitive Programmer's Handbook](https://usaco.guide/CPH.pdf) | `reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Problem Set](https://cses.fi/problemset) | `problem set` |
| [Codeforces two-pointers tag](https://codeforces.com/problemset?tags=two+pointers) | `problem set` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Dice Combinations](https://cses.fi/problemset/task/1633) | `CSES` | `Easy` | - | - | - | 1D DP; Window Size 6 | bounded-width transition window |
| [Array Description](https://cses.fi/problemset/task/1746) | `CSES` | `Medium` | - | - | - | Bounded Transition DP; Prefix Sums | local-value window on adjacent states |
| [Candies](https://atcoder.jp/contests/dp/tasks/dp_m) | `AtCoder DP Contest` | `Medium-Hard` | - | - | - | Prefix-Sum DP; Bounded Range | windowed transitions via prefix sums |

### At Most K Distinct

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Fruit Into Baskets](https://leetcode.com/problems/fruit-into-baskets) | `LeetCode` | `Medium` | Frequency-Window | Two-Pointers | Hash Maps; Window Invariants | Distinct-Count; Two-Pointers | A classic at-most-two-distinct window that teaches how to expand and shrink correctly. |

### Distinct Count Window

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Sliding Window Distinct Values](https://cses.fi/problemset/task/3222) | `CSES` | `Easy` | Frequency-Window | Two-Pointers; Hash-Map | Hash Maps; Two Pointers | Frequency-Map; Distinct | A clean frequency-based window problem that teaches how to maintain a moving constraint. |

### Fixed Length Frequency Match

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Permutation in String](https://leetcode.com/problems/permutation-in-string) | `LeetCode` | `Easy` | Frequency-Window | Two-Pointers | Frequency Arrays; Strings | Anagram; Frequency-Array | A crisp fixed-window frequency problem that is perfect for learning sliding updates. |

### Median Cost

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Sliding Window Cost](https://cses.fi/problemset/task/1077) | `CSES` | `Medium` | Order-Statistics | Balanced-Multiset | Sliding Window Median; Prefix Sums | Median; Cost | A natural companion to median maintenance that adds aggregate cost tracking. |

### Median Maintenance

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Sliding Window Median](https://cses.fi/problemset/task/1076) | `CSES` | `Medium` | Order-Statistics | Balanced-Multiset | Multisets; Heap Balancing | Median; Multiset | A classic sliding-window problem that upgrades basic window maintenance to order statistics. |

### Minimum Covering Window

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring) | `LeetCode` | `Hard` | Frequency-Window | Two-Pointers; Hash-Map | Hash Maps; Substring Counting | Substring; Frequency-Map | The classic minimum-cover window that shows how to shrink only after a valid window is found. |

### Monotonic Minimum

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Sliding Window Minimum](https://cses.fi/problemset/task/3221) | `CSES` | `Easy` | Window-Maintenance | Deque | Queues; Amortized Analysis | Deque; Minimum | The standard monotonic-deque template for maintaining a window minimum in O(n). |

### Product Constraint

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Subarray Product Less Than K](https://leetcode.com/problems/subarray-product-less-than-k) | `LeetCode` | `Medium` | Product-Window | Two-Pointers | Multiplication Invariants; Arrays | Multiplicative; Two-Pointers | A canonical positive-array sliding window where the product constraint controls window growth. |

### Single Character Dominance

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement) | `LeetCode` | `Medium` | Frequency-Window | Two-Pointers | Frequency Counting; Window Invariants | Frequency; Replacement | A very common window problem where a simple count invariant unlocks the maximum length. |

### Unique Character Window

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters) | `LeetCode` | `Medium` | Two-Pointers | Two-Pointers | Hash Maps; Strings | Hash-Map; Substring | The most recognizable variable-length window problem for maintaining a uniqueness invariant. |

### Unique Sum Window

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Maximum Erasure Value](https://leetcode.com/problems/maximum-erasure-value) | `LeetCode` | `Medium` | Frequency-Window | Two-Pointers | Hash Maps; Prefix Sums | Unique-Window; Prefix-Sums | A good combination of uniqueness maintenance and rolling aggregate sums. |

### Window Inversion Count

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Sliding Window Inversions](https://cses.fi/problemset/task/3223) | `CSES` | `Hard` | Inversion-Counting | Fenwick-Tree | Coordinate Compression; Order Statistics | Inversions; Fenwick | A strong advanced window problem that combines local maintenance with inversion counting. |

### Windowed Histogram

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Sliding Window Advertisement](https://cses.fi/problemset/task/3227) | `CSES` | `Medium` | Monotonic-Window | Deque; Prefix-Scan | Monotonic Queue; Prefix Sums | Deque; Max-Area | A nice windowed maximization problem where subarray-maintenance meets a geometric interpretation. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `TFIELD` | Ruộng bậc thang | `primary` | `hard` | nested polygons; weighted sliding window; shoelace preprocessing | [Note](../../../practice/ladders/dp/sliding-window/tfield.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/sliding-window/tfield.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
