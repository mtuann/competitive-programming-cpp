# Dirichlet Prefix Sums Hot Sheet

Use this page when the statement has already collapsed into:

```text
open one arithmetic-function convolution,
then group equal floor(n / d) quotients
```

and the real choice is whether one direct divisor-side summation is enough or the task has crossed into a later `Du Jiao / Min_25` lane.

## Do Not Use When

- you need exact gcd layers over bounded array values; that is still [Mobius hot sheet](mobius-hot-sheet.md)
- you only need one value like `sigma(n)` after factorizing `n`
- the target is already an implicit prefix sum like `sum phi` or `sum mu`
- the intended route needs prime-aware recursion, not one direct quotient-grouped sum

## Choose By Signal

- summatory divisor function:

$$
\sum_{k \le n} \sigma(k)
$$

-> open `sigma = 1 * id`, then group equal `floor(n / d)` blocks -> [`dirichlet-convolution-sigma-sum.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/dirichlet-convolution-sigma-sum.cpp)
- divisor-side inclusion-exclusion over bounded values -> compare [Mobius hot sheet](mobius-hot-sheet.md)
- plain divisibility / factorization only -> compare [Number theory cheatsheet](number-theory-cheatsheet.md)
- later multiplicative-prefix recursion -> reopen the topic; this first starter is intentionally narrower than `Min_25 / Du Jiao`

## Core Invariants

- Dirichlet convolution:

$$
(f * g)(n) = \sum_{d \mid n} f(d) g(n/d)
$$

- first exact identity in this repo:

$$
\sigma = 1 * \operatorname{id}
$$

- summatory transform:

$$
\sum_{k \le n} \sigma(k) = \sum_{d \le n} d \left\lfloor \frac{n}{d} \right\rfloor
$$

- quotient block:

$$
q = \left\lfloor \frac{n}{l} \right\rfloor,
\qquad
r = \left\lfloor \frac{n}{q} \right\rfloor
$$

- block contribution:

$$
q \sum_{d=l}^{r} d
$$

## Main Traps

- jumping straight to quotient grouping without first deriving the divisor-side sum
- off-by-one on the block end `r`
- doing arithmetic-progression sums in 64-bit without thinking about overflow or modulo discipline
- overclaiming this route as a general prefix-sum multiplicative-function engine

## Exact Starter In This Repo

- exact starter -> [`dirichlet-convolution-sigma-sum.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/dirichlet-convolution-sigma-sum.cpp)
- flagship in-lane rep -> [Sum of Divisors](../practice/ladders/math/dirichlet-prefix-sums/sumofdivisors.md)
- compare points:
  - [Mobius hot sheet](mobius-hot-sheet.md)
  - [Number theory cheatsheet](number-theory-cheatsheet.md)

## Reopen Paths

- full lesson and boundary -> [Dirichlet Convolution / Prefix Sums Of Number-Theoretic Functions](../topics/math/dirichlet-prefix-sums/README.md)
- implicit-prefix next step -> [Min_25 / Du Jiao](../topics/math/min25-du-jiao/README.md)
- divisor-side inclusion-exclusion compare -> [Mobius And Multiplicative Counting](../topics/math/mobius-multiplicative/README.md)
- broader chooser -> [Number theory cheatsheet](number-theory-cheatsheet.md)
- snippet chooser -> [Template Library](../template-library.md)
