# Min_25 / Du Jiao

This lane starts when a number-theory prefix-sum problem stops being:

```text
open one direct divisor-side sum and group floor(n / d)
```

and becomes:

```text
the target function is only known implicitly through a Dirichlet relation,
so the prefix sum itself must be recovered recursively on the quotient set Q_n
```

The first exact route in this repo is intentionally narrower than the title.

It starts with the **Du Jiao worldview** for:

- prefix sums of `phi`
- prefix sums of `mu`

using:

- the quotient set:

$$
Q_n = \left\{ \left\lfloor \frac{n}{i} \right\rfloor : 1 \le i \le n \right\}
$$

- one Dirichlet relation such as:

$$
\varphi * 1 = id
$$

or:

$$
\mu * 1 = e
$$

- one recurrence over `Q_n`

This page does **not** start with:

- full prime-counting machinery
- the full Min_25 sieve as the first implementation
- arbitrary multiplicative-function black boxes

It teaches the first reusable step after the direct `sigma`-prefix lane:

```text
recover an implicit prefix sum on Q_n by grouping equal quotients
and using previously solved smaller quotient states
```

## At A Glance

- **Use when:** the target is `sum phi` or `sum mu` for one huge `n`, and sieving all the way to `n` is too large
- **Core worldview:** the prefix sum is not opened by one direct divisor-side sum; instead, one Dirichlet identity gives a recurrence on `Q_n`
- **Main tools:** quotient set `Q_n`, Dirichlet convolution, grouped floor-division blocks, memoized or tabled prefix states
- **Typical complexity:** sublinear in `n`; the repo's first starter works on `Q_n` directly and is meant as the clean introductory route, not the final asymptotic frontier
- **Main trap:** jumping to Min_25 language before the learner can derive the Du Jiao recurrence for `phi` or `mu`

Strong contest signals:

- the statement asks for:
  - `sum_{k <= n} phi(k)` or
  - `sum_{k <= n} mu(k)`
- `n` is too large for a straight sieve to `n`
- direct convolution expansion like the `sigma` lane is no longer enough
- the repeated subproblems are values of:

$$
\left\lfloor \frac{n}{i} \right\rfloor
$$

not arbitrary unrelated integers

Strong anti-cues:

- the arithmetic function opens immediately into one direct sum like:

$$
\sum_{d \le n} d \left\lfloor \frac{n}{d} \right\rfloor
$$

which is still the [Dirichlet Convolution / Prefix Sums Of Number-Theoretic Functions](../dirichlet-prefix-sums/README.md) lane

- the task is still array-side gcd counting over bounded values, which is [Mobius And Multiplicative Counting](../mobius-multiplicative/README.md)
- the real target is prime counting or a prime-side multiplicative formula; that is where full Min_25 becomes the next step

## Prerequisites

- [Dirichlet Convolution / Prefix Sums Of Number-Theoretic Functions](../dirichlet-prefix-sums/README.md)
- [Number Theory Basics](../number-theory-basics/README.md)

Helpful nearby anchors:

- [Number theory cheatsheet](../../../notebook/number-theory-cheatsheet.md)
- [Dirichlet prefix sums hot sheet](../../../notebook/dirichlet-prefix-sums-hot-sheet.md)
- [Mobius And Multiplicative Counting](../mobius-multiplicative/README.md) only as a later compare route when the real story turns back into bounded-value inclusion-exclusion

## Problem Model And Notation

Let:

$$
\Phi(n) = \sum_{k \le n} \varphi(k),
\qquad
M(n) = \sum_{k \le n} \mu(k)
$$

The key identities are:

$$
\varphi * 1 = id
$$

and:

$$
\mu * 1 = e
$$

Summing the first identity over all `m <= n` gives:

$$
\sum_{m \le n} \sum_{d \mid m} \varphi(d)
=
\sum_{m \le n} m
$$

which becomes:

$$
\sum_{k=1}^{n} \Phi\!\left(\left\lfloor \frac{n}{k} \right\rfloor\right)
=
\frac{n(n+1)}{2}
$$

Likewise for `mu`:

$$
\sum_{k=1}^{n} M\!\left(\left\lfloor \frac{n}{k} \right\rfloor\right)
= 1
$$

These are the exact starting recurrences of this lane.

## From Brute Force To The Right Idea

### Brute Force

For `sum phi` or `sum mu`, the most direct route is:

- sieve every value up to `n`
- take the prefix sum

That is fine when `n <= 10^7` or so, but not when `n` is much larger.

### First Structural Observation

The prefix sum is still tied to a Dirichlet relation.

For `phi`:

$$
\varphi * 1 = id
$$

So summing over `m <= n` yields:

$$
\sum_{k=1}^{n} \Phi\!\left(\left\lfloor \frac{n}{k} \right\rfloor\right)
=
\frac{n(n+1)}{2}
$$

Now isolate the `k = 1` term:

$$
\Phi(n)
=
\frac{n(n+1)}{2}
-
\sum_{k=2}^{n} \Phi\!\left(\left\lfloor \frac{n}{k} \right\rfloor\right)
$$

That is already a usable recurrence.

For `mu`, the same idea gives:

$$
M(n)
=
1
-
\sum_{k=2}^{n} M\!\left(\left\lfloor \frac{n}{k} \right\rfloor\right)
$$

### Second Structural Observation

The values:

$$
\left\lfloor \frac{n}{k} \right\rfloor
$$

repeat.

So we do not solve the recurrence on every `k`.

We solve it on the quotient set:

$$
Q_n = \left\{ \left\lfloor \frac{n}{i} \right\rfloor \right\}
$$

and group equal quotients into blocks:

$$
q = \left\lfloor \frac{x}{l} \right\rfloor,
\qquad
r = \left\lfloor \frac{x}{q} \right\rfloor
$$

This turns the recurrence into one grouped transition over already-known smaller states.

That is the core Du Jiao mental move.

## Core Invariants And Why They Work

## 1. Quotient-Set Invariant

If:

$$
x \in Q_n
$$

then:

$$
Q_x \subseteq Q_n
$$

So once the lane is restricted to `Q_n`, every recursive or DP dependency stays inside the same small state set.

That is why one huge prefix-sum query can be handled with only `O(sqrt(n))` distinct arguments.

## 2. Dirichlet-Identity Invariant

For `phi`, the recurrence is not guessed.

It comes from:

$$
\varphi * 1 = id
$$

and for `mu`, from:

$$
\mu * 1 = e
$$

If the statement is not tied to one such identity, then this lane may not be the right one.

## 3. Block-Grouping Invariant

For one current state `x`, every `k` inside a block `[l, r]` shares the same quotient:

$$
\left\lfloor \frac{x}{k} \right\rfloor = q
$$

So the whole block contributes:

$$
(r-l+1) \cdot F(q)
$$

where `F` is either `Phi` or `M`.

This is the same floor-grouping geometry as the previous lane, but the unknown object is now the prefix sum itself.

## 4. Boundary Invariant Between Du Jiao And Min_25

The first repo route is:

- recover `sum phi`
- recover `sum mu`

from one Dirichlet relation on `Q_n`.

The next lane boundary is:

- the function is more naturally described on primes or prime powers
- the intended engine is full Min_25 or prime counting

So in this repo:

- **Du Jiao first**
- **Min_25 second**

## Exact First Route In This Repo

The starter exposes a quotient-set DP / memo route for:

- `prefix_phi(n)`
- `prefix_mu(n)`

under one modulus.

It is intentionally honest about what it does **not** try to be:

- not a generic Min_25 library
- not a prime-counting engine
- not a one-size-fits-all multiplicative-prefix framework

It is the clean first bridge from the direct `sigma`-prefix lane into implicit prefix-sum recurrences.

## Variant Chooser

### Use This Route When

- `sum phi` or `sum mu` is the target
- one huge `n` is the bottleneck
- the relevant subproblems are values in `Q_n`
- one Dirichlet identity gives the recurrence immediately

### Stay In The Previous Dirichlet Lane When

- the function still opens by one direct divisor-side expansion
- the block contribution is a simple arithmetic progression or another easy prefixable helper
- no implicit prefix recurrence is needed

### Defer To Full Min_25 When

- the task is closer to prime counting
- the useful formula is naturally expressed through prime values of the function
- the Du Jiao `phi / mu` worldview is already trusted, but the function family has moved beyond it

## Exact Starter In This Repo

- Starter template: [du-jiao-prefix-phi-mu.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/du-jiao-prefix-phi-mu.cpp)
- Hot sheet: [Min_25 / Du Jiao hot sheet](../../../notebook/min25-du-jiao-hot-sheet.md)
- Flagship note: [Sum of Totient Function](../../../practice/ladders/math/min25-du-jiao/sumoftotientfunction.md)

## In-Repo Compare Points

- [Dirichlet Convolution / Prefix Sums Of Number-Theoretic Functions](../dirichlet-prefix-sums/README.md): direct divisor-side floor sums like `sum sigma`
- [Mobius And Multiplicative Counting](../mobius-multiplicative/README.md): array-side divisor inclusion-exclusion, not one huge prefix `n`
- [BSGS / Discrete Log](../bsgs-discrete-log/README.md): another advanced math lane where the bottleneck is structural rather than algebraic formula memorization

## Exit Criteria

You are ready to move on when you can:

- derive the `Phi(n)` recurrence from:

$$
\varphi * 1 = id
$$

- derive the `M(n)` recurrence from:

$$
\mu * 1 = e
$$

- explain why `Q_x subseteq Q_n` is the key state-space fact
- group equal quotient blocks without off-by-one mistakes
- say clearly when the next step is full Min_25 rather than more Du Jiao practice

## External Practice

- [Library Checker - Sum of Totient Function](https://judge.yosupo.jp/problem/sum_of_totient_function)
- [CSES - Totient sums](https://cses.fi/ioi17/task/947)
- [USACO Guide - Prefix Sums of Number-Theoretic Functions (Part 2)](https://usaco.guide/adv/prefix-sums-nt-2)

## Tutorial Link

- [Math overview](../README.md)
