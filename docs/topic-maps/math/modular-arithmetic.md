# Math -> Modular Arithmetic

Safe modular computation: powers, inverses, congruences, and the algebra needed to avoid overflow and mistakes.

- Topic slug: `math/modular-arithmetic`
- Tutorial page: [Open tutorial](../../../topics/math/modular-arithmetic/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/math/modular-arithmetic/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `0`
- Curated external problems: `10`

## Microtopics

- modpow
- modinv
- Fermat
- Euler-theorem
- congruences
- mod-division

## Learning Sources

| Source | Type |
| --- | --- |
| [MIT 6.857 modular arithmetic review](https://courses.csail.mit.edu/6.857/current/) | `course` |
| [USACO Guide modular arithmetic](https://usaco.guide/gold/modular) | `trusted guide` |
| [cp-algorithms modular inverse](https://cp-algorithms.com/algebra/module-inverse.html) | `trusted guide` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Exponentiation](https://cses.fi/problemset/task/1095/) | `problem` |
| [CSES Exponentiation II](https://cses.fi/problemset/task/1712/) | `problem` |
| [Kattis Modular Arithmetic](https://open.kattis.com/problems/modulararithmetic) | `problem` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Exponentiation](https://cses.fi/problemset/task/1095) | `CSES` | `Easy` | Fast-Exponentiation, Mod Arithmetic | Implementation; Math | Modular Arithmetic; Binary Exponentiation | Binary Exponentiation; Pow | Canonical modular fast-power warmup. |
| [Distributing Apples](https://cses.fi/problemset/task/1716) | `CSES` | `Easy-Medium` | Stars And Bars, Mod Arithmetic | - | - | Combinations; Distributions | Simple counting with modular binomial coefficients. |
| [Binomial Coefficients](https://cses.fi/problemset/task/1079) | `CSES` | `Medium` | Combinatorics/Counting-Basics, Mod Inverses, Combinatorics | Math; Precomputation | Factorials; Modular Inverse; Combinations | Ncr; Factorials; Modular Inverse; Inverse Factorials | Standard modular combinations with precomputation. |
| [Creating Strings II](https://cses.fi/problemset/task/1715) | `CSES` | `Medium` | Factorials, Mod Inverses | - | - | Multiset Permutations; Combinatorics; Mod Arithmetic | Distinct-string counting via modular combinatorics. |
| [Exponentiation II](https://cses.fi/problemset/task/1712) | `CSES` | `Medium` | Fast-Exponentiation, Mod-Inverse, Totient Tricks | Implementation; Number Theory | Binary Exponentiation; Modular Arithmetic; Fermat's Little Theorem | Tower Exponentiation; Fermats-Little-Theorem; Mod Arithmetic; Phi | Adds exponent towers and modulus reduction logic. |
| [Fibonacci Numbers](https://cses.fi/problemset/task/1722) | `CSES` | `Medium` | Recurrences, Matrix/Recurrence, Mod Arithmetic | DP; Math | Modular Arithmetic | Matrix Exponentiation; Recurrence; Linear Recurrence; Doubling | Classic recurrence computation under a modulus. |

### Practice

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Throwing Dice](https://cses.fi/problemset/task/1096) | `CSES` | `Medium` | DP/Recurrences | Dynamic Programming; Implementation | Basic DP; Modular Arithmetic | Combinatorics; DP; Mod Arithmetic | A compact recurrence with large n that reinforces modulo-safe DP transitions. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Counting Grids](https://cses.fi/problemset/task/2210) | `CSES` | `Hard` | Combinatorics/Bracelet-Counting | Combinatorics; Algebra | Modular Arithmetic; Symmetry Counting | Burnside; Pólya Counting; Mod Arithmetic | A stronger symmetry-counting problem that rewards comfortable modular evaluation. |
| [Counting Necklaces](https://cses.fi/problemset/task/2209) | `CSES` | `Hard` | Combinatorics/Burnside | Combinatorics; Number Theory | Modular Arithmetic; Group Actions; GCD/LCM Basics | Burnside; Group Actions; Mod Arithmetic | A canonical advanced counting problem where modular arithmetic sits inside Burnside's lemma. |
| [Graph Paths I](https://cses.fi/problemset/task/1723) | `CSES` | `Hard` | Matrix-Exponentiation | Graphs; Math | Modular Arithmetic; Matrix Multiplication; DP On Walks | Graph Walks; Mod Arithmetic | A classic matrix-exponentiation application where the answer is required modulo a prime. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `EXPONENTIATION2` | Exponentiation II | `primary` | `medium` | binary exponentiation; fermat exponent reduction; zero exponent edge case | [Note](../../../practice/ladders/math/modular-arithmetic/exponentiation2.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/modular-arithmetic/exponentiation2.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
