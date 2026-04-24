# DP -> Knapsack Family

Choose the state dimension and transition order that matches 0-1, complete, bounded, or value-based knapsack.

- Topic slug: `dp/knapsack-family`
- Tutorial page: [Open tutorial](../../../topics/dp/knapsack-family/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/dp/knapsack-family/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `0`
- Curated external problems: `15`

## Microtopics

- 0-1-knapsack
- complete-knapsack
- bounded-knapsack
- value-dp
- weight-dp
- rolling-array

## Learning Sources

| Source | Type |
| --- | --- |
| [USACO Guide Knapsack](https://usaco.guide/gold/knapsack) | `Reference` |
| [cp-algorithms knapsack](https://cp-algorithms.com/dynamic_programming/knapsack.html) | `Reference` |
| [OI Wiki knapsack DP](https://en.oi-wiki.org/dp/knapsack/) | `Reference` |

## Practice And Follow-Up Sources

| Source | Type |
| --- | --- |
| [AtCoder DP D](https://atcoder.jp/contests/dp/tasks/dp_d) | `Practice` |
| [CSES Money Sums](https://cses.fi/problemset/task/1745/) | `Practice` |
| [CSES Problem Set](https://cses.fi/problemset) | `Practice` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Book Shop II](https://cses.fi/problemset/task/1159) | `CSES` | `Medium-Hard` | - | - | - | Bounded Knapsack; Multi-Copy | bounded-multiplicity knapsack variant |

### 0 1 Capacity DP

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Book Shop](https://cses.fi/problemset/task/1158) | `CSES` | `Easy` | 0-1-Knapsack | Tabulation; Rolling-Array | Arrays; Maximization DP | Capacity; Value Maximization; Budget | The cleanest 0/1 knapsack template: maximize value under a budget with each item usable once. |

### 0 1 Knapsack

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Knapsack 1](https://atcoder.jp/contests/dp/tasks/dp_d) | `AtCoder DP Contest` | `Medium` | 0-1-Knapsack | Tabulation | Book Shop; Nested Loops | Capacity; Value Maximization | The standard 0/1 knapsack formulation in its pure contest form. |

### Equal Partition Counting

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Two Sets II](https://cses.fi/problemset/task/1093) | `CSES` | `Easy` | Subset Sum | Tabulation | Modular Arithmetic | Partition; Combinatorics | A classic partition-counting twist on subset-sum that reinforces exact-sum DP. |

### Knapsack With A Toggle

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Fruit Feast](https://usaco.org/index.php?cpid=574&page=viewproblem2) | `USACO Gold` | `Easy` | State-Augmented-Knapsack | Tabulation | Unbounded Knapsack; State Expansion | Unbounded; One-Time-State | A memorable knapsack twist where one optional action changes the reachable state space. |

### Minimum Coin Count

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Minimizing Coins](https://cses.fi/problemset/task/1634) | `CSES` | `Easy` | Unbounded-Knapsack | Tabulation | Basic Recurrence; Arrays | Min-Coins; Unbounded; Min-Count | The simplest unbounded knapsack variant: minimize items while hitting an exact sum. |

### Minimum Coins With Repetition

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Coin Change](https://leetcode.com/problems/coin-change) | `LeetCode` | `Medium` | Unbounded-Knapsack | Tabulation | Minimizing Coins; Arrays | Min-Coins; Unbounded | The interview-friendly version of unbounded knapsack with the same core recurrence. |

### Ordered Unbounded Counting

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Coin Combinations I](https://cses.fi/problemset/task/1635) | `CSES` | `Easy` | Unbounded-Knapsack | Tabulation | Modular Arithmetic; Basic Counting | Counting; Order-Matters | Classic counting knapsack where the order of coins matters and the state is one-dimensional. |

### Ratio Knapsack

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Talent Show](https://usaco.org/index.php?cpid=839&page=viewproblem2) | `USACO Gold` | `Hard` | Ratio-Optimization | Tabulation; Binary-Search-Check | 0/1 Knapsack; Binary Search On Answer | Binary-Search-On-Answer | A classic knapsack variant that combines DP with an optimization ratio objective. |

### Reachable Sums

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Money Sums](https://cses.fi/problemset/task/1745) | `CSES` | `Easy` | Subset Sum | Tabulation | Set Thinking; Boolean DP | Reachable-Sums; Bitset-Friendly | A classic subset-sum reachability problem that prepares you for bitset optimization later. |

### Signed Subset Sum

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Target Sum](https://leetcode.com/problems/target-sum) | `LeetCode` | `Medium` | Counting-Knapsack | Tabulation | Subset Sum; Algebraic Transformation | Sign-Assignments; Counting | A classic transform-from-signs to subset-sum problem that rewards good state reframing. |

### Subset Partition

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum) | `LeetCode` | `Medium` | Subset Sum | Tabulation | Parity Checks | Partition; Boolean | A direct yes/no subset-sum target that helps cement knapsack as reachability. |

### Two Dimensional Capacity

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Ones and Zeroes](https://leetcode.com/problems/ones-and-zeroes) | `LeetCode` | `Medium` | 2D-Knapsack | Tabulation | 0/1 Knapsack; Counting Items | Dual-Capacity; 0-1 | A useful multi-capacity knapsack that extends the standard single-budget template. |

### Unordered Counting

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Coin Combinations II](https://cses.fi/problemset/task/1636) | `CSES` | `Easy` | Subset-Knapsack | Tabulation | Coin Combinations I; Modular Arithmetic | Counting; Order-Does-Not-Matter | Teaches the coin-ordering pitfall that distinguishes the two classic coin-change DPs. |

### Value Indexed Knapsack

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Knapsack 2](https://atcoder.jp/contests/dp/tasks/dp_e) | `AtCoder DP Contest` | `Hard` | Value-Based-DP | Tabulation | 0/1 Knapsack; State Redesign | Capacity; Value-State; Value-Based Knapsack; Large W | Shows the key trick of flipping the DP dimension when weights are too large. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `BOOKSHOP` | Book Shop | `primary` | `easy` | 0 1 knapsack; downward capacity loop; budget value maximization | [Note](../../../practice/ladders/dp/knapsack-family/bookshop.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/knapsack-family/bookshop.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
