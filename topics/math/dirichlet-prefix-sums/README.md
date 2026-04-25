# Dirichlet Convolution / Prefix Sums Of Number-Theoretic Functions

This lane starts when a number-theory problem stops being:

```text
compute one arithmetic function value at n
```

and becomes:

```text
sum that function over every k <= n, then exploit divisor structure
```

The first exact route in this repo is intentionally narrow:

- rewrite the divisor-sum function as:

$$
\sigma = 1 * \operatorname{id}
$$

- expand the summatory form:

$$
\sum_{k \le n} \sigma(k) = \sum_{d \le n} d \left\lfloor \frac{n}{d} \right\rfloor
$$

- group equal quotients `floor(n / d)` into `O(sqrt(n))` blocks

This page does **not** try to start with:

- Min_25 / Du Jiao
- prime-counting prefix sums
- arbitrary multiplicative-prefix recurrences

It teaches the clean first contest route where Dirichlet convolution is visible and quotient grouping is enough to finish.

## At A Glance

- **Use when:** the answer is a summatory arithmetic function and the clean expansion depends only on `floor(n / d)`
- **Core worldview:** open the Dirichlet convolution first, then compress equal quotients into large divisor blocks
- **Main tools:** arithmetic functions, Dirichlet convolution, arithmetic progression sums, harmonic-lemma / quotient grouping
- **Typical complexity:** `O(sqrt(n))` quotient blocks once the right convolution identity is exposed
- **Main trap:** memorizing floor-division grouping without first deriving the exact divisor-side expansion

Strong contest signals:

- the statement asks for a sum over all divisors across `1..n`
- the brute-force form looks like:

$$
\sum_{k \le n} f(k)
$$

for an arithmetic function `f`

- the direct divisor expansion collapses into terms weighted by:

$$
\left\lfloor \frac{n}{d} \right\rfloor
$$

- the quotient stays constant on long ranges of `d`

Strong anti-cues:

- you need gcd-layer inclusion-exclusion over bounded array values; that is still [Mobius And Multiplicative Counting](../mobius-multiplicative/README.md)
- you only need one value like `sigma(n)` or `d(n)` for one factored `n`
- the intended lane is prime counting / Min_25 / Du Jiao rather than one direct convolution expansion
- the dominant work is modular equation solving, not arithmetic-function summation

## Prerequisites

- [Number Theory Basics](../number-theory-basics/README.md)
- [Modular Arithmetic](../modular-arithmetic/README.md)

Helpful nearby anchors:

- [Mobius And Multiplicative Counting](../mobius-multiplicative/README.md)
- [Number theory cheatsheet](../../../notebook/number-theory-cheatsheet.md)
- [Mobius hot sheet](../../../notebook/mobius-hot-sheet.md)

## Problem Model And Notation

Dirichlet convolution of arithmetic functions `f` and `g` is:

$$
(f * g)(n) = \sum_{d \mid n} f(d) g(n / d)
$$

For this first route, the important identity is:

$$
\sigma(n) = \sum_{d \mid n} d = (1 * \operatorname{id})(n)
$$

where:

- `1(n) = 1` for every positive integer `n`
- `id(n) = n`

The summatory function we want is:

$$
S(n) = \sum_{k = 1}^{n} \sigma(k)
$$

## From Brute Force To The Right Idea

### Brute Force

The naive path is:

- compute every `sigma(k)` separately
- add them up

That immediately dies when `n` becomes large.

### First Structural Observation

Open the convolution:

$$
\sigma(k) = \sum_{d \mid k} d
$$

Then exchange the order of summation:

$$
\sum_{k \le n} \sigma(k)
=
\sum_{k \le n} \sum_{d \mid k} d
=
\sum_{d \le n} d \cdot \#\{k \le n : d \mid k\}
$$

But:

$$
\#\{k \le n : d \mid k\} = \left\lfloor \frac{n}{d} \right\rfloor
$$

So:

$$
S(n) = \sum_{d \le n} d \left\lfloor \frac{n}{d} \right\rfloor
$$

Now the problem is no longer "sum divisors of each number."

It is:

```text
sum one weighted floor-division expression over all d <= n
```

### Second Structural Observation

The quotient:

$$
q = \left\lfloor \frac{n}{d} \right\rfloor
$$

stays constant on whole intervals of `d`.

If the current block starts at `l`, then:

$$
q = \left\lfloor \frac{n}{l} \right\rfloor
$$

and the last index with the same quotient is:

$$
r = \left\lfloor \frac{n}{q} \right\rfloor
$$

So we can add:

$$
q \sum_{d=l}^{r} d
$$

in one step and jump directly to `r + 1`.

That is the whole reason the route drops to `O(sqrt(n))`.

## Core Invariants And Why They Work

## 1. Convolution Expansion Invariant

The first invariant is not algorithmic.

It is structural:

$$
\sigma = 1 * \operatorname{id}
$$

If you do not open the convolution correctly, the floor-grouping trick appears magical and easy to misuse.

## 2. Summatory Exchange Invariant

Once the convolution is expanded, every divisor `d` contributes to exactly the multiples of `d`.

So:

$$
\sum_{k \le n} \sigma(k)
=
\sum_{d \le n} d \left\lfloor \frac{n}{d} \right\rfloor
$$

The invariant is:

```text
every divisor d is paid once for each multiple of d up to n
```

## 3. Quotient-Block Invariant

For every block `[l, r]`,

$$
\left\lfloor \frac{n}{d} \right\rfloor = q
\quad \text{for all } d \in [l, r]
$$

where:

$$
q = \left\lfloor \frac{n}{l} \right\rfloor,
\qquad
r = \left\lfloor \frac{n}{q} \right\rfloor
$$

So the whole block contributes:

$$
q \sum_{d=l}^{r} d
$$

and the arithmetic progression sum is easy.

## 4. Complexity Invariant

The number of distinct values of:

$$
\left\lfloor \frac{n}{d} \right\rfloor
$$

is only `O(sqrt(n))`.

That is the contest boundary that makes this route practical.

## Exact First Route In This Repo

The repo's first exact route is:

- one summatory divisor-function task
- one direct convolution identity:

$$
\sigma = 1 * \operatorname{id}
$$

- one quotient-grouping loop

The starter exposes:

- `sum_range_mod(l, r, mod)` for arithmetic progression blocks
- `sum_of_divisors_prefix(n, mod)` for:

$$
\sum_{k \le n} \sigma(k)
$$

It does **not** expose:

- general multiplicative prefix-sum machinery
- Mobius-based recursive summatory formulas
- Min_25 / Du Jiao

Those belong to later lanes once this exact route feels ordinary.

## Variant Chooser

### Use This Route When

- the arithmetic function expands into one easy divisor-side sum
- the block contribution needs only a simple prefixable helper like:
  - `sum d`
  - maybe later `sum d^2`, `sum 1`, and similar
- `floor(n / d)` is the only expensive-looking part

### Reopen Mobius Instead When

- the statement is about exact gcd layers over bounded values
- you need divisor-side inclusion-exclusion, not one direct summatory expansion
- the central object is `mu` or divisor frequencies across an array

### Defer To Later Prefix-Sum Number-Theory Lanes When

- the target is `sum phi`, `sum mu`, or a more implicit multiplicative recurrence
- the intended solution is really Du Jiao / Min_25
- the lane has crossed from "open one convolution and group quotients" into "build a generic prime-aware prefix-sum engine"

## Exact Starter In This Repo

- Starter template: [dirichlet-convolution-sigma-sum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/dirichlet-convolution-sigma-sum.cpp)
- Hot sheet: [Dirichlet prefix sums hot sheet](../../../notebook/dirichlet-prefix-sums-hot-sheet.md)
- Flagship note: [Sum of Divisors](../../../practice/ladders/math/dirichlet-prefix-sums/sumofdivisors.md)

## In-Repo Compare Points

- [Mobius And Multiplicative Counting](../mobius-multiplicative/README.md): divisor-side inclusion-exclusion and exact gcd layers
- [Min_25 / Du Jiao](../min25-du-jiao/README.md): implicit prefix sums of `phi` / `mu` on `Q_n` once direct divisor-side expansion stops being enough
- [Linear Recurrence / Matrix Exponentiation](../linear-recurrence/README.md): another lane where a summatory-looking brute force is replaced by one compact algebraic transform
- [Chinese Remainder / Linear Congruences](../chinese-remainder/README.md): math-heavy, but not an arithmetic-function prefix-sum lane

## Exit Criteria

You are ready to move on when you can:

- derive:

$$
\sum_{k \le n} \sigma(k) = \sum_{d \le n} d \left\lfloor \frac{n}{d} \right\rfloor
$$

without looking it up

- explain why quotient grouping is correct
- compute the right block end:

$$
r = \left\lfloor \frac{n}{\lfloor n/l \rfloor} \right\rfloor
$$

- say clearly why this starter is narrower than Min_25 / Du Jiao
- distinguish "direct convolution expansion" from "Mobius inversion over divisors"

## External Practice

- [CSES - Sum of Divisors](https://cses.fi/problemset/task/1082)
- [USACO Guide - Prefix Sums of Number-Theoretic Functions (Part 1)](https://usaco.guide/adv/prefix-sums-nt-1)

## Tutorial Link

- [Math overview](../README.md)
