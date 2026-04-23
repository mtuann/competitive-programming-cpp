# Combinatorics -> Counting Basics

Factorials, binomials, arrangements, stars and bars, and the basic models that recur across counting problems.

- Topic slug: `combinatorics/counting-basics`
- Tutorial page: [Open tutorial](../topics/combinatorics/counting-basics/README.md)
- Ladder page: [Open ladder](../practice/ladders/combinatorics/counting-basics/README.md)
- Repo problems currently tagged here: `1`
- Curated external problems: `13`

## Microtopics

- permutations
- combinations
- binomial
- factorials
- pascal-triangle
- catalan

## Learning Sources

| Source | Type |
| --- | --- |
| [MIT Mathematics for Computer Science](https://courses.csail.mit.edu/6.042/spring18/mcs.pdf) | `textbook` |
| [cp-algorithms binomial coefficients](https://cp-algorithms.com/combinatorics/binomial-coefficients.html) | `trusted guide` |
| [OI Wiki combinations](https://en.oi-wiki.org/math/combinatorics/combination/) | `trusted guide` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Binomial Coefficients](https://cses.fi/problemset/task/1079/) | `problem` |
| [CSES Distributing Apples](https://cses.fi/problemset/task/1716/) | `problem` |
| [USACO Guide Catalan Numbers](https://usaco.guide/gold/combo?lang=cpp) | `trusted guide` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Bit Strings](https://cses.fi/problemset/task/1617) | `CSES` | `Easy` | Basic Counting, Mod Arithmetic | - | - | Powers Of Two | The simplest counting-by-choices starter. |
| [Choose Cards 1](https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_s) | `AtCoder` | `Easy` | Pair-Counting | Implementation; Counting | Basic Counting; Frequency Arrays | Pairs | A very direct counting warm-up with only frequency bookkeeping. |
| [Choose Cards 3](https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_v) | `AtCoder` | `Easy` | Pair-Counting | Implementation; Counting | Frequency Arrays; Complement Counting | Two-Sum; Frequency Counting | A great basic complement-counting exercise with a fixed target sum. |
| [Combination Easy](https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_u) | `AtCoder` | `Easy` | Binomial-Coefficients | Math | Factorials; Combinations | Ncr | A pure combinatorics starter that isolates nCr without any hidden twists. |
| [Two Knights](https://cses.fi/problemset/task/1072) | `CSES` | `Easy` | - | - | - | Board Counting; Pair Counting; Formula | Classic counting-by-cases on a board. |
| [Binomial Coefficients](https://cses.fi/problemset/task/1079) | `CSES` | `Medium` | Modular-Arithmetic | Math; Precomputation | Factorials; Modular Inverse | Ncr; Factorials; Modular Inverse | The standard modular-combinatorics benchmark for factorial precomputation. |
| [Choose Cards 2](https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_t) | `AtCoder` | `Medium` | Subset-Counting | Search; Counting | Subset Enumeration; Sum Constraints | Meet-In-The-Middle | A classic counting-by-subsets problem that sits between brute force and combinatorics. |
| [Creating Strings II](https://cses.fi/problemset/task/1715) | `CSES` | `Medium` | Multiset Permutations | Math; Precomputation | Multiset Counting; Modular Arithmetic | Factorials | A textbook multinomial-counting problem with duplicate letters. |
| [Two Sets II](https://cses.fi/problemset/task/1093) | `CSES` | `Medium` | DP | - | - | Partitions; Subset Sum; Mod Arithmetic | Nice introductory partition-counting problem. |

### Practice

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Christmas Party](https://cses.fi/problemset/task/1717) | `CSES` | `Medium` | Derangements | Combinatorics; DP | Basic Counting; Inclusion-Exclusion | Derangements; Inclusion-Exclusion | A classic derangement/counting problem that is good practice for constrained permutations. |
| [Distributing Apples](https://cses.fi/problemset/task/1716) | `CSES` | `Medium` | Stars-And-Bars | Math; Combinatorics | Combinations | Compositions; Combinations; Mod Arithmetic | A canonical stars-and-bars problem and a clean step toward distributions with constraints. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Counting Necklaces](https://cses.fi/problemset/task/2209) | `CSES` | `Hard` | Group-Actions | Combinatorics | Modular Arithmetic | Burnside; Pólya | A more advanced counting benchmark that moves from raw counting into symmetry. |
| [Counting Permutations](https://cses.fi/problemset/task/1075) | `CSES` | `Hard` | Permutation-Counting, Inclusion-Style Counting | DP; Combinatorics | Inclusion-Exclusion Mindset | Permutations; Adjacency Constraints; Adjacency Restriction; Beautiful Permutations | A stronger permutation-counting problem with a clean but nontrivial constraint. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `VOSFENCE` | Xay hang rao | `secondary` | `hard` | bounded compositions; run decomposition; gap distribution | [Note](../practice/ladders/combinatorics/bounded-compositions/vosfence.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/combinatorics/bounded-compositions/vosfence.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
