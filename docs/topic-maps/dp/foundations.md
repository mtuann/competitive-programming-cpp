# DP -> Foundations

State design, transitions, and the discipline of converting brute force recurrence thinking into efficient DP.

- Topic slug: `dp/foundations`
- Tutorial page: [Open tutorial](../../../topics/dp/foundations/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/dp/foundations/README.md)
- Repo problems currently tagged here: `2`
- Repo companion pages: `0`
- Curated external problems: `12`

## Microtopics

- state-definition
- transition-design
- base-cases
- memoization
- tabulation
- push-vs-pull
- counting-dp

## Learning Sources

| Source | Type |
| --- | --- |
| [USACO Guide intro DP](https://usaco.guide/gold/intro-dp) | `Reference` |
| [cp-algorithms intro to DP](https://cp-algorithms.com/dynamic_programming/intro-to-dp.html) | `Reference` |
| [OI Wiki DP basics](https://en.oi-wiki.org/dp/basic/) | `Reference` |

## Practice And Follow-Up Sources

| Source | Type |
| --- | --- |
| [AtCoder DP Contest](https://atcoder.jp/contests/dp?lang=en) | `Practice` |
| [CSES Grid Paths I](https://cses.fi/problemset/task/1638/) | `Practice` |
| [CSES Array Description](https://cses.fi/problemset/task/1746/) | `Practice` |

## Curated External Problems

### Warm-Up

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Grid 1](https://atcoder.jp/contests/dp/tasks/dp_h) | `AtCoder DP Contest` | `Easy-Medium` | Grid DP | Tabulation | 2D Arrays; Basic Counting | Path Counting | Warm-up grid counting DP before harder path variants. |
| [LCS](https://atcoder.jp/contests/dp/tasks/dp_f) | `AtCoder DP Contest` | `Medium` | String DP | Tabulation | 2D Arrays; String Indexing | 2D DP | Warm-up 2D string DP before richer edit-style transitions. |

### Base Recurrence

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Climbing Stairs](https://leetcode.com/problems/climbing-stairs) | `LeetCode` | `Easy` | Linear DP | Memoization; Tabulation | Basic Recursion; Arrays | Recurrence; 1D | The canonical one-state recurrence: each step depends only on the previous one or two states. |

### Choice States

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Vacation](https://atcoder.jp/contests/dp/tasks/dp_c) | `AtCoder DP Contest` | `Easy` | State DP | Tabulation | Arrays; Basic Recurrence | Choices; Day-By-Day; 2D DP; Daily Choice | Introduces multi-state DP where each day carries a small fixed set of options. |

### Choose Or Skip

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [House Robber](https://leetcode.com/problems/house-robber) | `LeetCode` | `Medium` | Linear DP | Tabulation; Rolling-Array | Arrays; Max/Min Reasoning | Skip-Take; Optimization | A compact skip-take DP that is easy to derive and easy to optimize to O(1) space. |

### Counting Ways

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Dice Combinations](https://cses.fi/problemset/task/1633) | `CSES` | `Easy` | Counting DP | Tabulation | Basic Recursion; Modular Arithmetic | Counting; Mod | Shows how counting DP turns a simple last-move recurrence into an efficient linear solution. |

### Grid Paths

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Unique Paths](https://leetcode.com/problems/unique-paths) | `LeetCode` | `Medium` | Grid DP | Tabulation | 2D Arrays; Basic Counting | Grid; Combinatorics | The standard grid-counting DP that teaches how to propagate answers from left and up. |

### Pairwise String DP

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Longest Common Subsequence](https://cses.fi/problemset/task/3403) | `CSES` | `Medium` | String DP | Tabulation | 2D Arrays; String Indexing | 2D | A classic 2D DP over prefixes with match-vs-skip transitions. |

### Prefix String Transforms

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Edit Distance](https://cses.fi/problemset/task/1639) | `CSES` | `Hard` | String DP | Tabulation | LCS; 2D Arrays | Transformations | A foundational edit DP that generalizes prefix transitions to insert/delete/replace. |

### Segment Partitioning

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Teamwork](https://usaco.org/index.php?cpid=863&page=viewproblem2) | `USACO Gold` | `Easy` | Segmented DP | Tabulation | Prefix Sums; Arrays | Partitioning; Bounded-Lookback | A classic segmented DP where each position considers a short backward range of choices. |

### Small Transition Window

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Frog 2](https://atcoder.jp/contests/dp/tasks/dp_b) | `AtCoder DP Contest` | `Easy` | Linear DP | Tabulation | Frog 1; Arrays | Min-Cost; Windowed-Transition; 1D DP; Bounded Jump | Builds the same recurrence idea with a wider jump window, which is a common DP stepping stone. |

### State Transition Basics

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Frog 1](https://atcoder.jp/contests/dp/tasks/dp_a) | `AtCoder DP Contest` | `Easy` | Linear DP | Tabulation; Memoization | Arrays; Absolute Difference | Min-Cost; Recurrence; 1D DP | A perfect first min-cost DP with a very small transition set and clear base cases. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `QOS` | Chất lượng dịch vụ | `secondary` | `hard` | shortest path plus dp; kth lexicographic path; bounded slack states | [Note](../../../practice/ladders/graphs/shortest-paths/qos.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/shortest-paths/qos.cpp) |
| `VMSCALE` | Chiếc cân kỳ diệu | `primary` | `hard` | budget dp; balanced ternary; decision-tree optimization | [Note](../../../practice/ladders/dp/foundations/vmscale.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/foundations/vmscale.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
