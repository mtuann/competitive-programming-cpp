# DP -> Interval DP

Reason over contiguous ranges and split points when the optimal structure is built by merging intervals.

- Topic slug: `dp/interval-dp`
- Tutorial page: [Open tutorial](../../../topics/dp/interval-dp/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/dp/interval-dp/README.md)
- Repo problems currently tagged here: `0`
- Curated external problems: `12`

## Microtopics

- interval-state
- split-point-enumeration
- merge-cost
- prefix-sum-cost
- game-dp
- circular-interval-dp

## Learning Sources

| Source | Type |
| --- | --- |
| [USACO Guide Range DP](https://usaco.guide/gold/dp-ranges) | `trusted guide` |
| [OI Wiki Interval DP](https://en.oi-wiki.org/dp/interval/) | `trusted guide` |

## Practice Sources

| Source | Type |
| --- | --- |
| [AtCoder DP N](https://atcoder.jp/contests/dp/tasks/dp_n) | `problem` |
| [CSES Removal Game](https://cses.fi/problemset/task/1097/) | `problem` |
| [USACO Guide range DP problems](https://usaco.guide/gold/dp-ranges) | `problem bank` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Deque](https://atcoder.jp/contests/dp/tasks/dp_l) | `AtCoder DP Contest` | `Medium` | - | - | - | Game DP | interval game with optimal play |
| [Zuma](https://codeforces.com/problemset/problem/607/B) | `Codeforces` | `Hard` | - | - | - | Palindrome Removal | canonical hard interval DP |

### Color Mixing

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Mixtures](https://www.spoj.com/problems/MIXTURES) | `SPOJ` | `Hard` | Merge-DP | Tabulation | Prefix Sums; Subarray DP | Color-Merge | A very common merge-style interval DP that reinforces the split-at-k pattern. |

### Extra Carried State

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Remove Boxes](https://leetcode.com/problems/remove-boxes) | `LeetCode` | `Hard` | Compressed-State-DP | Memoization | Interval DP; State Augmentation | Memoization | A harder interval DP that shows why one extra carried parameter can unlock the optimal recurrence. |

### Interval Repainting

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Modern Art 3](https://usaco.org/index.php?cpid=1114&page=viewproblem2) | `USACO Gold` | `Hard` | String-Like-Intervals | Tabulation | Subarray DP; State Merging | Painting | A great interval DP where repeated colors create the key merging opportunities. |

### Last Burst Split

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Burst Balloons](https://leetcode.com/problems/burst-balloons) | `LeetCode` | `Hard` | Split-DP | Tabulation | Interval Splitting; Recurrence Design | Maximize | The most famous interval DP for learning how choosing the last action simplifies the recurrence. |

### Merge Intervals

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Slimes](https://atcoder.jp/contests/dp/tasks/dp_n) | `AtCoder DP Contest` | `Hard` | Range-DP | Tabulation | Prefix Sums; Subarray DP | Merge-Cost | The standard interval-merging DP: split a range at every point and minimize the merge cost. |

### Optimal Cut Ordering

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Minimum Cost to Cut a Stick](https://leetcode.com/problems/minimum-cost-to-cut-a-stick) | `LeetCode` | `Medium` | Cut-DP | Tabulation | Interval DP Basics; Sorting Cut Points | Cuts | A clean cut-ordering problem that is ideal for practicing interval split transitions. |

### Palindrome Like Merging

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Strange Printer](https://leetcode.com/problems/strange-printer) | `LeetCode` | `Hard` | String DP | Tabulation | Subproblem Splitting | Strings | A subtle interval/string DP that rewards spotting repeated characters that can be merged. |

### Polygon Splitting

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Minimum Score Triangulation of Polygon](https://leetcode.com/problems/minimum-score-triangulation-of-polygon) | `LeetCode` | `Medium` | Polygon-DP | Tabulation | Triangle Decomposition; Interval Splitting | Geometry | A classic polygon interval DP that is often the first geometry-flavored range DP. |

### Sorted Interval Expansion

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [The Cow Run](https://usaco.org/index.php?cpid=265&page=viewproblem2) | `USACO Gold` | `Hard` | Ordered-Intervals | Tabulation | Sorting; Prefix Sums | Path | An interval DP where the visited cows always form a contiguous block in sorted order. |

### Take From Ends Game

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Removal Game](https://cses.fi/problemset/task/1097) | `CSES` | `Medium` | Game-DP | Tabulation | Minimax Thinking; Prefix Sums | Game-Theory; Minimax | classic take-left-or-right DP |

## Repo Problems

_No repo note has been tagged to this topic yet._

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
