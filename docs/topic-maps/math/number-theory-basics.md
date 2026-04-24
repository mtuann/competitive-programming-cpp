# Math -> Number Theory Basics

Divisibility, primes, totients, divisor functions, and the standard multiplicative toolbox of contest number theory.

- Topic slug: `math/number-theory-basics`
- Tutorial page: [Open tutorial](../../../topics/math/number-theory-basics/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/math/number-theory-basics/README.md)
- Repo problems currently tagged here: `7`
- Repo companion pages: `0`
- Curated external problems: `13`

## Microtopics

- divisibility
- primes
- coprime
- totient
- multiplicative-functions
- divisor-functions

## Learning Sources

| Source | Type |
| --- | --- |
| [MIT Mathematics for Computer Science](https://courses.csail.mit.edu/6.042/spring18/mcs.pdf) | `textbook` |
| [OI Wiki number theory basics](https://en.oi-wiki.org/math/number-theory/basic/) | `trusted guide` |
| [Competitive Programmer's Handbook](https://usaco.guide/CPH.pdf) | `reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Counting Divisors](https://cses.fi/problemset/task/1713/) | `problem` |
| [CSES Common Divisors](https://cses.fi/problemset/task/1081/) | `problem` |
| [CSES Counting Coprime Pairs](https://cses.fi/problemset/task/2417/) | `problem` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Calculate GCD](https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_o) | `AtCoder` | `Easy` | GCD/LCM | Implementation; Math | Euclid's Algorithm | GCD; Euclid | A minimal Euclidean-algorithm exercise with no extra machinery. |
| [Divisor Enumeration](https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_m) | `AtCoder` | `Easy` | Divisors | Implementation; Math | Divisibility; Sqrt Factorization | Enumeration | A basic divisor-enumeration drill that teaches the square-root loop pattern. |
| [Factorization](https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_n) | `AtCoder` | `Easy` | Primes, Factorization | Implementation; Math | Division | Prime Factorization; Trial Division | The standard first factorization problem before jumping into sieve-heavy tasks. |
| [Greatest Common Divisor of N Integers](https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_p) | `AtCoder` | `Easy` | GCD/LCM | Implementation; Math | Euclid's Algorithm; Iterative Reduction | GCD; Fold/Reduce | A natural follow-up that checks whether you can fold gcd across many values. |
| [Least Common Multiple of N Integers](https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_q) | `AtCoder` | `Easy` | GCD/LCM | Implementation; Math | GCD; Safe Multiplication | LCM; GCD; Overflow Avoidance | A very standard lcm problem that also reinforces overflow-safe formulas. |
| [Primality Test](https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_l) | `AtCoder` | `Easy` | Primes | Implementation; Math | Divisibility; Prime Numbers | Primality; Trial Division | A direct, foundational prime-checking exercise with clear constraints. |
| [Prime Multiples](https://cses.fi/problemset/task/2185) | `CSES` | `Medium` | Inclusion-Exclusion, Primes | - | - | Subset Enumeration; LCM; Counting Multiples | Counts multiples of prime sets with inclusion-exclusion. |
| [Counting Coprime Pairs](https://cses.fi/problemset/task/2417) | `CSES` | `Medium-Hard` | Mobius Inversion, GCD | - | - | Coprime Pairs; Number Theory; Inclusion-Exclusion | A stronger gcd/Mobius counting exercise. |

### Practice

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Counting Divisors](https://cses.fi/problemset/task/1713) | `CSES` | `Easy` | Divisors, Factorization, Prime Factorization, Divisor Counting | Math; Implementation | Exponent Counting | Divisor-Count; Sieve; Tau(n) | Direct divisor-counting from prime exponents. |
| [Next Prime](https://cses.fi/problemset/task/3396) | `CSES` | `Easy-Medium` | Primes, Sieving, Primality Testing | Implementation; Number Theory | Search Over Integers | Prime Search; Miller-Rabin-Style Thinking; Next Prime; Miller-Rabin; Trial Division | Good basic prime-search / primality practice. |
| [Common Divisors](https://cses.fi/problemset/task/1081) | `CSES` | `Medium` | GCD/LCM, Frequency-Ideas | Number Theory; Sieving | GCD; Divisor Counting | GCD; Max-Frequency Divisor | A classic gcd-frequency problem that pushes beyond one-off Euclid calls. |
| [Sum of Divisors](https://cses.fi/problemset/task/1082) | `CSES` | `Medium` | Divisors, Prefix-Sums, Divisor Sums, Arithmetical Functions | Math; Optimization | Floor-Division Grouping | Sigma Function; Divisor Summatory Function; Sigma(n); Floor Division; Mod Arithmetic | Core multiplicative-function summation. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Divisor Analysis](https://cses.fi/problemset/task/2182) | `CSES` | `Medium` | Divisors, Modular-Arithmetic, Prime Factorization, Multiplicative Functions | Math; Precomputation | Geometric Series | Number Of Divisors; Sum Of Divisors; Product Of Divisors | Bundle of the three textbook divisor-function formulas. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `COMMONDIVISORS` | Common Divisors | `secondary` | `medium` | divisor frequency scan; count multiples; maximize pair gcd | [Note](../../../practice/ladders/math/gcd-lcm/commondivisors.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/gcd-lcm/commondivisors.cpp) |
| `COUNTINGDIVISORS` | Counting Divisors | `primary` | `easy` | divisor sieve; many queries preprocessing; divisor counting | [Note](../../../practice/ladders/math/number-theory-basics/countingdivisors.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/number-theory-basics/countingdivisors.cpp) |
| `CRYPTKEY` | Chìa khóa mã số | `secondary` | `hard` | gcd-lcm closure; prime-power characterization; constructibility | [Note](../../../practice/ladders/math/gcd-lcm/cryptkey.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/gcd-lcm/cryptkey.cpp) |
| `GCDONBLACKBOARD` | GCD on Blackboard | `secondary` | `medium` | prefix suffix gcd; remove one element; maximize array gcd | [Note](../../../practice/ladders/math/gcd-lcm/gcdonblackboard.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/gcd-lcm/gcdonblackboard.cpp) |
| `LAMP` | Dàn đèn màu | `primary` | `hard` | density formula; pairwise coprime products; big integer fractions | [Note](../../../practice/ladders/math/number-theory-basics/lamp.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/number-theory-basics/lamp.cpp) |
| `PRIMEMULTIPLES` | Prime Multiples | `secondary` | `medium` | subset inclusion exclusion; overflow safe lcm product; count divisible numbers | [Note](../../../practice/ladders/combinatorics/inclusion-exclusion/primemultiples.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/combinatorics/inclusion-exclusion/primemultiples.cpp) |
| `VMSCALE` | Chiếc cân kỳ diệu | `secondary` | `hard` | budget dp; balanced ternary; decision-tree optimization | [Note](../../../practice/ladders/dp/foundations/vmscale.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/foundations/vmscale.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
