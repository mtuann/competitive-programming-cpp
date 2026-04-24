# Math -> GCD And LCM

Euclidean algorithm, Bézout identities, and the way gcd/lcm structure propagates through arrays and constructions.

- Topic slug: `math/gcd-lcm`
- Tutorial page: [Open tutorial](../../../topics/math/number-theory-basics/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/math/gcd-lcm/README.md)
- Repo problems currently tagged here: `3`
- Repo companion pages: `0`
- Curated external problems: `11`

## Microtopics

- euclid
- extended-gcd
- bezout
- lcm-formula
- coprime
- prefix-suffix-gcd

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms Euclidean Algorithm](https://cp-algorithms.com/algebra/euclid-algorithm.html) | `trusted guide` |
| [OI Wiki GCD](https://en.oi-wiki.org/math/number-theory/gcd/) | `trusted guide` |
| [Principles of Algorithmic Problem Solving](https://usaco.guide/PAPS.pdf) | `reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Common Divisors](https://cses.fi/problemset/task/1081/) | `problem` |
| [USACO Guide GCD on Blackboard](https://usaco.guide/problems/cf-gcd-on-blackboard/solution) | `problem writeup` |
| [USACO Guide Orac and LCM](https://usaco.guide/problems/cf-orac-and-lcm/solution) | `problem writeup` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Calculate GCD](https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_o) | `AtCoder` | `Easy` | Euclid | Implementation | Euclid's Algorithm | GCD; Euclid | The simplest gcd-only exercise and a good starting point for the track. |
| [Greatest Common Divisor of N Integers](https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_p) | `AtCoder` | `Easy` | Euclid | Implementation | Euclid's Algorithm | GCD; Reduce | Shows how gcd scales from pairs to arrays without adding extra theory. |
| [Least Common Multiple of N Integers](https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_q) | `AtCoder` | `Easy` | Overflow-Safety | Implementation | GCD; Safe Multiplication | LCM; GCD; Overflow | A direct lcm task that reinforces the gcd-based formula and overflow control. |
| [GCD and LCM](https://open.kattis.com/problems/gcdandlcm) | `Kattis` | `Easy-Medium` | - | - | - | GCD Formula; LCM Formula; Integer Arithmetic | Straightforward gcd/lcm arithmetic practice. |
| [GCD Pairs](https://open.kattis.com/problems/gcdpairs) | `Kattis` | `Medium` | GCD Counting, Mobius | - | - | Pair Counting; Divisors; Coprime | Uses gcd counting ideas at a pair-of-values level. |
| [GCD on Blackboard](https://atcoder.jp/contests/abc125/tasks/abc125_c) | `AtCoder` | `Medium` | Prefix/Suffix GCD | - | - | Remove-One; GCD Array; Prefix Suffix | Classic one-removal gcd optimization. |
| [Orac and LCM](https://codeforces.com/contest/1349/problem/A) | `Codeforces` | `Medium` | Number Theory | Math; Implementation | Prime Factorization; GCD/LCM Identities | GCD; LCM; Prime Exponents | A classic pairwise-lcm/gcd identity problem and a strong conceptual checkpoint. |
| [GCD Harmony](https://open.kattis.com/problems/gcdharmony) | `Kattis` | `Hard` | GCD Constraints, Optimization | - | - | GCD Reasoning; Integer Transform; Number Theory | A deeper gcd-flavored optimization problem. |

### Practice

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Common Divisors](https://cses.fi/problemset/task/1081) | `CSES` | `Medium` | Frequency-Ideas, Divisibility | Number Theory | GCD; Divisor Counting | GCD; Divisor Frequency; Maximum GCD; Frequency Over Divisors; Array GCD | Directly about maximizing gcd structure in an array. |
| [LCM on Whiteboard](https://atcoder.jp/contests/abc259/tasks/abc259_e) | `AtCoder` | `Medium` | Prime-Factorization | Number Theory; Implementation | LCM Via Maximum Exponents | LCM; Prime Exponents; Set Cover | A richer lcm problem that rewards exponent-level reasoning across many numbers. |
| [Large LCM](https://atcoder.jp/contests/typical90/tasks/typical90_al) | `AtCoder` | `Medium` | Overflow-Safety | Implementation; Math | GCD; Overflow-Safe Arithmetic | LCM; Overflow; Large Integers | A standard large-lcm variation where the answer must be capped safely. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `COUNTINGDIVISORS` | Counting Divisors | `secondary` | `easy` | divisor sieve; many queries preprocessing; divisor counting | [Note](../../../practice/ladders/math/number-theory-basics/countingdivisors.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/number-theory-basics/countingdivisors.cpp) |
| `CRYPTKEY` | Chìa khóa mã số | `primary` | `hard` | gcd-lcm closure; prime-power characterization; constructibility | [Note](../../../practice/ladders/math/gcd-lcm/cryptkey.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/gcd-lcm/cryptkey.cpp) |
| `LAMP` | Dàn đèn màu | `secondary` | `hard` | density formula; pairwise coprime products; big integer fractions | [Note](../../../practice/ladders/math/number-theory-basics/lamp.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/number-theory-basics/lamp.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
