# Math -> Lucas Theorem And Large Binomial Mod Prime

Prime-mod binomial coefficients beyond one factorial table, using base-p digit decomposition and Lucas theorem when n crosses p.

- Topic slug: `math/lucas-theorem`
- Tutorial page: [Open tutorial](../../../topics/math/lucas-theorem/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/math/lucas-theorem/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `3`
- Curated external problems: `2`

## Microtopics

- lucas-theorem
- base-p-digits
- large-binomial
- prime-mod-binomial
- digit-product
- factorial-table-boundary

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms binomial coefficients](https://cp-algorithms.com/combinatorics/binomial-coefficients.html) | `Reference` |
| [AtCoder ABC251 editorial](https://atcoder.jp/contests/abc251/editorial/3995) | `Reference` |
| [Competitive Programmer's Handbook](https://usaco.guide/CPH.pdf) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Library Checker Binomial Coefficient (Prime Mod)](https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod) | `Practice` |
| [Kattis Odd Binomial Coefficients](https://open.kattis.com/problems/oddbinom) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Lucas Theorem hot sheet](../../../notebook/lucas-hot-sheet.md) | `quick reference` |
| [Binomial Coefficient (Prime Mod)](../../../practice/ladders/math/lucas-theorem/binomialcoefficientprimemod.md) | `flagship note` |
| [Templates overview](../../../template-library.md) | `template guide` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Binomial Coefficient (Prime Mod)](https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod) | `Library Checker` | `Medium` | Binomial Coefficients | Math; Implementation | Modular Arithmetic; Factorial Binomial; Base Conversion | Binomial Coefficient; Prime Modulus | A clean benchmark for the route split between one ordinary factorial table and Lucas digit decomposition under one prime modulus. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Odd Binomial Coefficients](https://open.kattis.com/problems/oddbinom) | `Kattis` | `Hard` | Binomial Coefficients, Pascal Structure | Math; Observation | Lucas Theorem; Bitwise Reasoning | Parity; Bitwise Pattern | A strong compare point where Lucas with p = 2 exposes a structural parity pattern instead of only answering one binomial query. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `BINOMIALCOEFFICIENTPRIMEMOD` | Binomial Coefficient (Prime Mod) | `primary` | `medium` | - | [Note](../../../practice/ladders/math/lucas-theorem/binomialcoefficientprimemod.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/lucas-theorem/binomialcoefficientprimemod.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
