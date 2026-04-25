# Math -> Dirichlet Convolution / Prefix Sums Of Number-Theoretic Functions

Summatory arithmetic functions opened through one direct Dirichlet convolution, then compressed with quotient grouping on equal floor-division blocks.

- Topic slug: `math/dirichlet-prefix-sums`
- Tutorial page: [Open tutorial](../../../topics/math/dirichlet-prefix-sums/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/math/dirichlet-prefix-sums/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `4`
- Curated external problems: `2`

## Microtopics

- dirichlet-convolution
- summatory-sigma
- sigma-equals-one-convolution-id
- floor-division-blocks
- quotient-grouping
- harmonic-lemma

## Learning Sources

| Source | Type |
| --- | --- |
| [USACO Guide Prefix Sums of Number-Theoretic Functions (Part 1)](https://usaco.guide/adv/prefix-sums-nt-1) | `Reference` |
| [cp-algorithms Number of divisors / sum of divisors](https://cp-algorithms.com/algebra/divisors.html) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Sum of Divisors](https://cses.fi/problemset/task/1082) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Dirichlet prefix sums hot sheet](../../../notebook/dirichlet-prefix-sums-hot-sheet.md) | `quick reference` |
| [Sum of Divisors](../../../practice/ladders/math/dirichlet-prefix-sums/sumofdivisors.md) | `flagship note` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |
| [Mobius And Multiplicative Counting](../../../topics/math/mobius-multiplicative/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Sum of Divisors](https://cses.fi/problemset/task/1082) | `CSES` | `Medium` | Summatory Arithmetic Functions | Math; Implementation | Number Theory Basics; Arithmetic Progression Sums; Floor Division Grouping | Dirichlet Convolution; Sigma Function; Quotient Grouping; Harmonic Lemma | The cleanest first benchmark where sigma = 1 * id opens a divisor-side sum and equal floor(n / d) quotients collapse the runtime to O(sqrt(n)). |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Totient sums](https://cses.fi/ioi17/task/947) | `CSES` | `Hard` | Summatory Arithmetic Functions | Math; Implementation | Dirichlet Convolution; Quotient Grouping; Euler Totient | Totient; Prefix Sums; Quotient Grouping; Follow-Up | A useful compare point once the first direct sigma-prefix route is trusted; the same quotient-grouping worldview survives, but the arithmetic function is no longer available by one immediate convolution expansion. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `SUMOFDIVISORS` | Sum of Divisors | `primary` | `medium` | - | [Note](../../../practice/ladders/math/dirichlet-prefix-sums/sumofdivisors.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/dirichlet-prefix-sums/sumofdivisors.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
