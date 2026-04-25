# Factorize

- Title: `Factorize`
- Judge / source: `Library Checker`
- Original URL: [https://judge.yosupo.jp/problem/factorize](https://judge.yosupo.jp/problem/factorize)
- Secondary topics: `Miller-Rabin`, `Pollard-Rho`, `64-bit factorization`
- Difficulty: `hard`
- Subtype: `Factor one 64-bit integer into prime factors in ascending order`
- Status: `solved`
- Solution file: [factorize.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/pollard-rho/factorize.cpp)

## Why Practice This

This is the cleanest verifier-style anchor for the repo's first exact `Pollard-Rho` lane.

The route is deliberately narrow:

- one integer `a_i`
- one output: all prime factors in ascending order
- one reusable stack:
  - deterministic 64-bit Miller-Rabin
  - Pollard-Rho for one nontrivial split
  - recursion plus final sorting

So the lesson is not a broad survey of factorization algorithms.

It is:

- separate prime from composite quickly
- split composites without trial division
- recurse until the whole factor multiset is prime

## Recognition Cue

Reach for this lane when:

- inputs reach up to `10^18`
- trial division to `sqrt(n)` is obviously dead
- the output wants prime factors with multiplicity
- a nearby number-theory route is fine mathematically but blocked by large-factorization cost

The strongest smell is:

```text
the whole problem becomes easy if I can factor n fast enough
```

## Problem-Specific Transformation

For each query `a_i`:

1. if `a_i = 1`, the factor list is empty
2. if the current subproblem is prime, keep it
3. otherwise run Pollard-Rho until you get one proper factor `d`
4. recurse on `d` and `a_i / d`
5. sort the resulting prime multiset
6. print:

```text
k x0 x1 ... x(k-1)
```

with ascending primes

## Core Idea

The implementation separates the lane into two exact layers.

### 1. Primality Layer

Before trying to split, check whether the current number is already prime.

For 64-bit contest integers, deterministic Miller-Rabin with a fixed witness set is the standard exact route.

### 2. Splitting Layer

If the number is composite, Pollard-Rho tries to reveal one hidden factor through gcds of differences between iterates in a pseudorandom polynomial sequence.

Once one proper factor appears, the rest is just recursion:

```text
factor(left) + factor(right)
```

That is the whole contest pattern.

## Complexity

- deterministic Miller-Rabin is cheap for 64-bit inputs
- Pollard-Rho is heuristic but fast enough in the standard contest regime

The important contest takeaway is not a formal asymptotic headline.
It is:

```text
this route is practical for 64-bit factorization where sqrt(n) trial division is not
```

## Solution Sketch

1. Read `Q`.
2. For each query `n`:
   - if `n = 1`, print `0`
   - otherwise recursively factor it
3. In the recursive function:
   - return if `n = 1`
   - if `n` is prime, append it
   - otherwise get one proper factor `d` from Pollard-Rho and recurse on both parts
4. Sort the factor list.
5. Print the count and the factors in ascending order.

## Common Pitfalls

- forgetting the empty-factor case for `n = 1`
- not retrying when Pollard-Rho returns `n`
- using signed overflow instead of safe 128-bit modular multiplication
- printing factors in discovery order instead of ascending order

## Related Paths

- Bigger theory step: [Pollard-Rho](../../../../topics/math/pollard-rho/README.md)
- Compare point: [Primitive Root](../../../../topics/math/primitive-root/README.md)
- Retrieval page: [Pollard-Rho hot sheet](../../../../notebook/pollard-rho-hot-sheet.md)
