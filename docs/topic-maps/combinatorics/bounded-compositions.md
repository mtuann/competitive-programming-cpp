# Combinatorics -> Bounded Compositions

Distribute sums under lower and upper bounds using stars and bars, generating functions, or inclusion-exclusion.

- Topic slug: `combinatorics/bounded-compositions`
- Tutorial page: [Open tutorial](../../../topics/combinatorics/bounded-compositions/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/combinatorics/bounded-compositions/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `0`
- Curated external problems: `6`

## Microtopics

- stars-and-bars
- lower-bounds
- upper-bounds
- bounded-sums
- compositions
- generating-functions
- PIE

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms stars and bars](https://cp-algorithms.com/combinatorics/stars_and_bars.html) | `trusted guide` |
| [OI Wiki combinations](https://en.oi-wiki.org/math/combinatorics/combination/) | `trusted guide` |
| [OI Wiki PIE](https://en.oi-wiki.org/math/combinatorics/inclusion-exclusion/) | `trusted guide` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Distributing Apples](https://cses.fi/problemset/task/1716/) | `problem` |
| [AtCoder DP M](https://atcoder.jp/contests/dp/tasks/dp_m) | `problem` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Coins](https://atcoder.jp/contests/abc087/tasks/abc087_b) | `AtCoder` | `Easy` | Coin-Change | Brute Force; Counting | Nested Loops; Case Analysis | Bounded Composition; Coin Sums | A tiny bounded-composition problem where all constraints are small enough to enumerate. |
| [Distributing Apples](https://cses.fi/problemset/task/1716) | `CSES` | `Easy-Medium` | Stars-And-Bars, Bounded Counting | Math; Combinatorics | Combinations | Nonnegative Parts; Combinations | The cleanest unconstrained composition baseline. |
| [M - Candies](https://atcoder.jp/contests/dp/tasks/dp_m) | `AtCoder` | `Medium` | Prefix DP | - | - | Upper Bounds; Children And Candies; DP | A canonical bounded-distribution DP. |
| [D - Between Two Arrays](https://atcoder.jp/contests/abc222/tasks/abc222_d) | `AtCoder` | `Hard` | Prefix DP | - | - | Nondecreasing Arrays; Range Bounds; Mod 998244353 | Counting bounded monotone sequences with DP. |

### Practice

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [How Many Ways?](https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_br) | `AtCoder` | `Medium` | Triple-Counting | Counting; Brute Force | Case Analysis; Sum Constraints | Triples; Sum Constraint | A small but useful constrained-composition style problem over ordered triples. |
| [Tak and Cards](https://atcoder.jp/contests/abc044/tasks/arc060_a) | `AtCoder` | `Medium` | Subset Sum | DP; Counting | Cardinality Constraints | Sum Constraints; Card Selection | A good bridge from composition thinking to constrained subset counting. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `VOSFENCE` | Xay hang rao | `primary` | `hard` | bounded compositions; run decomposition; gap distribution | [Note](../../../practice/ladders/combinatorics/bounded-compositions/vosfence.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/combinatorics/bounded-compositions/vosfence.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
