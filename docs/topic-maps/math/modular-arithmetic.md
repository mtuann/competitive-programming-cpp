# Math -> Modular Arithmetic

Safe modular computation: powers, inverses, congruences, and the algebra needed to avoid overflow and mistakes.

- Topic slug: `math/modular-arithmetic`
- Tutorial page: [Open tutorial](../../../topics/math/modular-arithmetic/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/math/modular-arithmetic/README.md)
- Repo problems currently tagged here: `4`
- Repo companion pages: `2`
- Curated external problems: `8`

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
| [MIT 6.857 modular arithmetic review](https://courses.csail.mit.edu/6.857/current/) | `Course` |
| [USACO Guide modular arithmetic](https://usaco.guide/gold/modular) | `Reference` |
| [cp-algorithms modular inverse](https://cp-algorithms.com/algebra/module-inverse.html) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Exponentiation](https://cses.fi/problemset/task/1095/) | `Practice` |
| [CSES Exponentiation II](https://cses.fi/problemset/task/1712/) | `Practice` |
| [Kattis Modular Arithmetic](https://open.kattis.com/problems/modulararithmetic) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Number theory cheatsheet](../../../notebook/number-theory-cheatsheet.md) | `quick reference` |
| [Templates overview](../../../template-library.md) | `template guide` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Exponentiation](https://cses.fi/problemset/task/1095) | `CSES` | `Easy` | Fast-Exponentiation, Mod Arithmetic | Implementation; Math | Modular Arithmetic; Binary Exponentiation | Binary Exponentiation; Pow | Canonical modular fast-power warmup. |
| [Distributing Apples](https://cses.fi/problemset/task/1716) | `CSES` | `Easy-Medium` | Stars And Bars, Mod Arithmetic | - | - | Combinations; Distributions | Simple counting with modular binomial coefficients. |
| [Binomial Coefficients](https://cses.fi/problemset/task/1079) | `CSES` | `Medium` | Combinatorics/Counting-Basics, Mod Inverses, Combinatorics | Math; Precomputation | Factorials; Modular Inverse; Combinations | Ncr; Factorials; Modular Inverse; Inverse Factorials | Standard modular combinations with precomputation. |
| [Creating Strings II](https://cses.fi/problemset/task/1715) | `CSES` | `Medium` | Factorials, Mod Inverses | - | - | Multiset Permutations; Combinatorics; Mod Arithmetic | Distinct-string counting via modular combinatorics. |
| [Exponentiation II](https://cses.fi/problemset/task/1712) | `CSES` | `Medium` | Fast-Exponentiation, Mod-Inverse, Totient Tricks | Implementation; Number Theory | Binary Exponentiation; Modular Arithmetic; Fermat's Little Theorem | Tower Exponentiation; Fermats-Little-Theorem; Mod Arithmetic; Phi | Adds exponent towers and modulus reduction logic. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Counting Grids](https://cses.fi/problemset/task/2210) | `CSES` | `Hard` | Combinatorics/Bracelet-Counting | Combinatorics; Algebra | Modular Arithmetic; Symmetry Counting | Burnside; Pólya Counting; Mod Arithmetic | A stronger symmetry-counting problem that rewards comfortable modular evaluation. |
| [Counting Necklaces](https://cses.fi/problemset/task/2209) | `CSES` | `Hard` | Combinatorics/Burnside | Combinatorics; Number Theory | Modular Arithmetic; Group Actions; GCD/LCM Basics | Burnside; Group Actions; Mod Arithmetic | A canonical advanced counting problem where modular arithmetic sits inside Burnside's lemma. |
| [Graph Paths I](https://cses.fi/problemset/task/1723) | `CSES` | `Hard` | Matrix-Exponentiation | Graphs; Math | Modular Arithmetic; Matrix Multiplication; DP On Walks | Graph Walks; Mod Arithmetic | A classic matrix-exponentiation application where the answer is required modulo a prime. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `COUNTINGNECKLACES` | Counting Necklaces | `secondary` | `hard` | burnside lemma; rotation symmetry; orbit counting | [Note](../../../practice/ladders/combinatorics/burnside-polya/countingnecklaces.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/combinatorics/burnside-polya/countingnecklaces.cpp) |
| `DISTRIBUTINGAPPLES` | Distributing Apples | `secondary` | `medium` | stars and bars; single binomial query; factorial precompute | [Note](../../../practice/ladders/combinatorics/counting-basics/distributingapples.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/combinatorics/counting-basics/distributingapples.cpp) |
| `EXPONENTIATION` | Exponentiation | `primary` | `easy` | binary exponentiation; repeated squaring; modular fast power | [Note](../../../practice/ladders/math/modular-arithmetic/exponentiation.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/modular-arithmetic/exponentiation.cpp) |
| `EXPONENTIATION2` | Exponentiation II | `primary` | `medium` | binary exponentiation; fermat exponent reduction; zero exponent edge case | [Note](../../../practice/ladders/math/modular-arithmetic/exponentiation2.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/modular-arithmetic/exponentiation2.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
