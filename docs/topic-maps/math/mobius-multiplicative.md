# Math -> Mobius And Multiplicative Counting

Divisor-structured inclusion-exclusion, Mobius cancellation, and multiplicative counting over multiples using one linear sieve plus one divisor-frequency sweep.

- Topic slug: `math/mobius-multiplicative`
- Tutorial page: [Open tutorial](../../../topics/math/mobius-multiplicative/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/math/mobius-multiplicative/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `3`
- Curated external problems: `1`

## Microtopics

- mobius-function
- mobius-inversion
- divisor-frequency
- coprime-pair-counting
- linear-sieve
- multiplicative-counting

## Learning Sources

| Source | Type |
| --- | --- |
| [OI Wiki Mobius inversion formula](https://en.oi-wiki.org/math/mobius/) | `Reference` |
| [cp-algorithms Linear Sieve](https://cp-algorithms.com/algebra/prime-sieve-linear.html) | `Reference` |
| [cp-algorithms Inclusion-Exclusion Principle](https://cp-algorithms.com/combinatorics/inclusion-exclusion.html) | `Reference` |
| [Competitive Programmer's Handbook](https://usaco.guide/CPH.pdf) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Counting Coprime Pairs](https://cses.fi/problemset/task/2417/) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Mobius hot sheet](../../../notebook/mobius-hot-sheet.md) | `quick reference` |
| [Counting Coprime Pairs](../../../practice/ladders/math/mobius-multiplicative/countingcoprimepairs.md) | `flagship note` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Counting Coprime Pairs](https://cses.fi/problemset/task/2417) | `CSES` | `Medium` | Coprime Pair Counting | Math; Implementation | Number Theory Basics; Inclusion-Exclusion; Linear Sieve | Mobius Function; Divisor Frequency; Coprime Pairs; Linear Sieve | The cleanest first benchmark where divisor frequencies plus Mobius cancellation replace pairwise gcd checks entirely. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `COUNTINGCOPRIMEPAIRS` | Counting Coprime Pairs | `primary` | `medium` | - | [Note](../../../practice/ladders/math/mobius-multiplicative/countingcoprimepairs.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/mobius-multiplicative/countingcoprimepairs.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
