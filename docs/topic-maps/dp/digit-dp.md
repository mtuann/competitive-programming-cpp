# DP -> Digit DP

Count or optimize over numeric ranges by scanning digits left-to-right with tight and leading-zero flags.

- Topic slug: `dp/digit-dp`
- Tutorial page: [Open tutorial](../../../topics/dp/digit-dp/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/dp/digit-dp/README.md)
- Repo problems currently tagged here: `0`
- Curated external problems: `15`

## Microtopics

- tight-flag
- leading-zero
- position-dp
- digit-sum-mod
- range-f(b)-f(a-1)
- state-augmentation

## Learning Sources

| Source | Type |
| --- | --- |
| [USACO Guide Digit DP](https://usaco.guide/gold/digit-dp) | `trusted guide` |
| [OI Wiki Digit DP](https://en.oi-wiki.org/dp/number/) | `trusted guide` |

## Practice Sources

| Source | Type |
| --- | --- |
| [AtCoder DP S](https://atcoder.jp/contests/dp/tasks/dp_s) | `problem` |
| [CSES Counting Numbers](https://cses.fi/problemset/task/2220/) | `problem` |
| [USACO Guide digit DP problems](https://usaco.guide/gold/digit-dp) | `problem bank` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Almost Everywhere Zero](https://atcoder.jp/contests/abc154/tasks/abc154_e) | `AtCoder Beginner Contest 154` | `Medium` | - | - | - | Tight DP; Count Digits | count numbers by non-zero digit count |
| [Digit Sum](https://atcoder.jp/contests/dp/tasks/dp_s) | `AtCoder DP Contest` | `Medium` | - | - | - | Tight DP; Mod Sum | classic tight digit DP |
| [Digit Products](https://atcoder.jp/contests/abc208/tasks/abc208_e) | `AtCoder Beginner Contest 208` | `Hard` | - | - | - | Tight DP; Digit Product | digit DP with product constraint |
| [Digit Sum Divisible](https://atcoder.jp/contests/abc336/tasks/abc336_e) | `AtCoder Beginner Contest 336` | `Hard` | - | - | - | Tight DP; Sum+Remainder | strong digit-DP state compression |

### Adjacent Digit Constraints

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Counting Numbers](https://cses.fi/problemset/task/2220) | `CSES` | `Medium` | Tight-DP | Memoization; Tabulation | Leading Zeros; State Compression | Tight; Adjacency Constraint | tight DP with forbidden adjacent equals |

### Binary Digit DP

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Find Integers](https://leetcode.com/problems/find-integers) | `LeetCode` | `Medium` | Binary-DP | Memoization | Binary Representation; State Transition | Binary; Fibonacci-Like | A nice non-decimal digit DP that shows the same idea works on binary digits too. |

### Bounded Digit Set

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Numbers At Most N Given Digit Set](https://leetcode.com/problems/numbers-at-most-n-given-digit-set) | `LeetCode` | `Medium` | Counting | Memoization | Place-Value Reasoning; Combinatorics | Combinatorics | A very approachable digit-style counting problem that is often solved with a digit DP mindset. |

### Complement Counting

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Numbers With Repeated Digits](https://leetcode.com/problems/numbers-with-repeated-digits) | `LeetCode` | `Hard` | Unique-Digits | Memoization | Count Special Integers; Combinatorics | Combinatorics | A standard follow-up that reinforces counting the complement via digit-state enumeration. |

### Digit DP With Divisibility Masks

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Beautiful Numbers](https://codeforces.com/problemset/problem/55/D) | `Codeforces` | `Very Hard` | Prime-Mask-DP | Memoization | Digit DP Basics; Number Theory | Number Theory | A harder digit DP classic that adds a strong arithmetic twist to the usual tight-state structure. |

### Digit DP With Sums

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Segment Sum](https://codeforces.com/problemset/problem/1073/E) | `Codeforces` | `Very Hard` | Range-Aggregation | Memoization | Digit DP Basics; Prefix Sums | Sum | A stronger range-counting digit DP that mixes digit states with numeric aggregation. |

### No Repeated Digits

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Count Special Integers](https://leetcode.com/problems/count-special-integers) | `LeetCode` | `Hard` | Unique-Digits | Memoization | Tight State; Bitmasking | Bitmask | A great bridge between digit DP and bitmasking because the repeated-digit constraint matters. |

### Range Digit Count

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Digit Sum](https://www.spoj.com/problems/DIGSUM) | `SPOJ` | `Medium` | Range-Counting | Memoization | Tight State; Prefix Digit Reasoning | Sum | A classic range-counting digit DP that makes the tight-bound idea feel concrete. |

### Restricted Digit Patterns

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Magic Numbers](https://codeforces.com/problemset/problem/628/D) | `Codeforces` | `Medium-Hard` | Mod-Constraint | Memoization | Modular Arithmetic; Leading Zeros | Mod | A canonical digit DP where the digit choices are constrained by both adjacency and divisibility rules. |

### Special Number Counting

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Travelling Salesman and Special Numbers](https://codeforces.com/problemset/problem/914/C) | `Codeforces` | `Medium-Hard` | Counting | Memoization | Tight State; Digit Enumeration | - | A very common digit DP problem that reinforces how to count objects with digit-based restrictions. |

### Valid Digit Transforms

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Rotated Digits](https://leetcode.com/problems/rotated-digits) | `LeetCode` | `Medium` | Counting | Memoization | Digit Filtering; State Encoding | Rotation | Useful for learning how to track a small property of each digit while counting up to a bound. |

## Repo Problems

_No repo note has been tagged to this topic yet._

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
