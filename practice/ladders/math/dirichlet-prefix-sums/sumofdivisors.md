# Sum of Divisors

- Title: `Sum of Divisors`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1082](https://cses.fi/problemset/task/1082)
- Secondary topics: `Dirichlet convolution`, `Summatory sigma`, `Quotient grouping`
- Difficulty: `medium`
- Subtype: `Summatory divisor function via sigma = 1 * id`
- Status: `solved`
- Solution file: [sumofdivisors.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/dirichlet-prefix-sums/sumofdivisors.cpp)

## Why Practice This

This is the cleanest in-repo anchor for the first exact `Dirichlet Convolution / Prefix Sums Of Number-Theoretic Functions` lane.

The statement looks like:

```text
sum the divisor sum function over every k <= n
```

but the reusable lesson is:

- open the arithmetic-function identity first
- swap the summation order
- compress all equal `floor(n / d)` quotients into one block at a time

It is the first problem in this repo where Dirichlet convolution is the right doorway into a fast prefix-sum formula.

## Recognition Cue

Reach for this lane when:

- the statement asks for a summatory arithmetic function, not one value at one `n`
- divisor contributions repeat across all multiples up to `n`
- the clean transformed formula depends on:

$$
\left\lfloor \frac{n}{d} \right\rfloor
$$

- you can see that the same quotient survives on intervals of `d`

The strongest smell here is:

```text
the brute-force divisor loop repeats the same quotient for many consecutive d
```

## Problem-Specific Transformation

Use the identity:

$$
\sigma = 1 * \operatorname{id}
$$

Then:

$$
\sum_{k \le n} \sigma(k)
=
\sum_{k \le n} \sum_{d \mid k} d
=
\sum_{d \le n} d \left\lfloor \frac{n}{d} \right\rfloor
$$

Now the problem is:

- iterate over divisor blocks
- for each block `[l, r]` with constant quotient:

$$
q = \left\lfloor \frac{n}{l} \right\rfloor,
\qquad
r = \left\lfloor \frac{n}{q} \right\rfloor
$$

- add:

$$
q \sum_{d=l}^{r} d
$$

## Core Idea

Do not compute `sigma(k)` separately.

Instead:

1. expand the summatory function on divisors
2. interpret `floor(n / d)` as the number of multiples of `d`
3. group all `d` that share the same quotient
4. use the arithmetic progression sum for the whole block

The invariant is:

```text
after finishing one block [l, r], every divisor d in that block has contributed
exactly d * floor(n / d), and no quotient value inside the block was split incorrectly
```

That is why the algorithm is both fast and exact.

## Complexity

- number of quotient blocks: `O(sqrt(n))`
- arithmetic per block: `O(1)`
- total: `O(sqrt(n))`

This is fast enough for very large `n`.

## Pitfalls / Judge Notes

- Do not confuse `sigma(n)` with the number of divisors `d(n)`.
- The transformed sum is over divisors `d`, not over `k`.
- The block end is:

$$
r = \left\lfloor \frac{n}{\lfloor n/l \rfloor} \right\rfloor
$$

not `n / l + 1` or another heuristic.
- Use `__int128` or careful modular arithmetic in the arithmetic-progression helper.
- If you forget to normalize modulo after subtraction, the range-sum helper can go negative.

## Reusable Pattern

- Topic page: [Dirichlet Convolution / Prefix Sums Of Number-Theoretic Functions](../../../../topics/math/dirichlet-prefix-sums/README.md)
- Practice ladder: [Dirichlet Convolution / Prefix Sums Of Number-Theoretic Functions ladder](README.md)
- Starter template: [dirichlet-convolution-sigma-sum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/dirichlet-convolution-sigma-sum.cpp)
- Notebook refresher: [Dirichlet prefix sums hot sheet](../../../../notebook/dirichlet-prefix-sums-hot-sheet.md)
- Compare points:
  - [Counting Coprime Pairs](../mobius-multiplicative/countingcoprimepairs.md)
  - [Mobius And Multiplicative Counting](../../../../topics/math/mobius-multiplicative/README.md)
- This note adds: the first exact in-repo route where Dirichlet convolution plus quotient grouping solves one summatory arithmetic-function task in `O(sqrt(n))`.

## Solutions

- Code: [sumofdivisors.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/dirichlet-prefix-sums/sumofdivisors.cpp)
