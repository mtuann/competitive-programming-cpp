# Math -> Min_25 / Du Jiao

Implicit prefix sums of phi or mu recovered on the quotient set Q_n from one Dirichlet relation, with full Min_25 kept as the next boundary rather than the first implementation.

- Topic slug: `math/min25-du-jiao`
- Tutorial page: [Open tutorial](../../../topics/math/min25-du-jiao/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/math/min25-du-jiao/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `4`
- Curated external problems: `2`

## Microtopics

- du-jiao-sieve
- quotient-set
- prefix-phi
- prefix-mu
- dirichlet-inverse-recurrence
- min25-boundary

## Learning Sources

| Source | Type |
| --- | --- |
| [USACO Guide Prefix Sums of Number-Theoretic Functions (Part 1)](https://usaco.guide/adv/prefix-sums-nt-1) | `Reference` |
| [USACO Guide Prefix Sums of Number-Theoretic Functions (Part 2)](https://usaco.guide/adv/prefix-sums-nt-2) | `Reference` |
| [Library Checker Sum of Totient Function](https://judge.yosupo.jp/problem/sum_of_totient_function) | `Practice` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Totient sums](https://cses.fi/ioi17/task/947) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Min_25 / Du Jiao hot sheet](../../../notebook/min25-du-jiao-hot-sheet.md) | `quick reference` |
| [Sum of Totient Function](../../../practice/ladders/math/min25-du-jiao/sumoftotientfunction.md) | `flagship note` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |
| [Dirichlet Convolution / Prefix Sums Of Number-Theoretic Functions](../../../topics/math/dirichlet-prefix-sums/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Sum of Totient Function](https://judge.yosupo.jp/problem/sum_of_totient_function) | `Library Checker` | `Hard` | Prefix Sums | Math; Implementation | Dirichlet Convolution; Euler Totient; Quotient Grouping | Du Jiao Sieve; Euler Totient; Quotient Set; Dirichlet Convolution | The cleanest first benchmark where phi * 1 = id stops being one direct divisor-side expansion and instead becomes a quotient-set recurrence for the prefix sum itself. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Totient sums](https://cses.fi/ioi17/task/947) | `CSES` | `Hard` | Prefix Sums | Math; Implementation | Du Jiao Sieve; Euler Totient; Quotient Grouping | Totient; Quotient Set; Follow-Up | A natural compare point after the first Du Jiao verifier route is trusted; it asks for the same implicit prefix-sum recovery worldview without forcing the lane to overclaim full Min_25 as the starter. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `SUMOFTOTIENTFUNCTION` | Sum of Totient Function | `primary` | `hard` | - | [Note](../../../practice/ladders/math/min25-du-jiao/sumoftotientfunction.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/min25-du-jiao/sumoftotientfunction.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
