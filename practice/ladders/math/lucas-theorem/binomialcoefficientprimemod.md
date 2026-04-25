# Binomial Coefficient (Prime Mod)

- Title: `Binomial Coefficient (Prime Mod)`
- Judge / source: `Library Checker`
- Original URL: [https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod](https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod)
- Secondary topics: `Lucas theorem`, `Binomial coefficients`, `Prime modulus`
- Difficulty: `medium`
- Subtype: `Choose between factorial-table binomial and Lucas digit decomposition under one prime modulus`
- Status: `solved`
- Solution file: [binomialcoefficientprimemod.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/lucas-theorem/binomialcoefficientprimemod.cpp)

## Why Practice This

This is the cleanest in-repo anchor for the `Lucas theorem / large binomial mod prime` lane because it does **not** let you blur together two different routes.

Under one prime modulus `p`, there are really two cases:

- if every query satisfies `n < p`, one ordinary factorial table is enough
- if some query crosses `n >= p`, Lucas becomes the exact route

So the lesson here is not just "write Lucas."

It is:

- recognize the boundary
- choose the lighter route when it is enough
- fall back to digit decomposition only when needed

## Recognition Cue

Reach for Lucas-safe thinking when:

- the statement asks for many values of `C(n, k) mod p`
- the modulus `p` is prime
- some `n` may be large enough that one factorial table no longer covers the query range

The strongest smell is:

- "same prime modulus for all queries, but `n` can cross `p`"

That is exactly when ordinary precompute stops being the whole story.

## Problem-Specific Transformation

Each query asks for:

$$
\binom{n}{k} \bmod p
$$

Because `p` is prime, the digit route is available:

$$
\binom{n}{k} \equiv \prod_i \binom{n_i}{k_i} \pmod p
$$

where `n_i, k_i` are the base-`p` digits.

So the implementation split is:

1. read all queries first
2. if every `n < p`, answer with one ordinary factorial table up to `max_n`
3. otherwise, if `p` is still precompute-safe, build `0..p-1` and answer with Lucas

That split is the real reusable pattern.

## Core Idea

Use one prime-mod binomial helper in the easy regime and one Lucas wrapper in the large-`n` regime.

For Lucas:

1. precompute `fact[i]` and `inv_fact[i]` for `0 <= i < p`
2. for each query, repeatedly take:
   - `ni = n % p`
   - `ki = k % p`
3. multiply by `C(ni, ki)`
4. if any digit has `ki > ni`, return `0`
5. divide `n` and `k` by `p` and continue

The invariant is:

```text
the current product already accounts for every processed base-p digit pair
```

## Complexity

Two possible branches:

- ordinary factorial table:
  - build `O(max_n)`
  - query `O(1)`
- Lucas route:
  - build `O(p)`
  - query `O(log_p n)`

That is exactly why the route chooser matters.

## Pitfalls / Judge Notes

- Do not force Lucas if `max_n < p`; that is just extra code and memory.
- Do not force the ordinary factorial table if queries cross `n >= p`.
- Lucas only applies because the modulus is prime.
- A digit with `ki > ni` makes the whole answer `0`.
- The Lucas starter assumes `p` is small enough for one `0..p-1` table.

## Reusable Pattern

- Topic page: [Lucas Theorem / Large Binomial Mod Prime](../../../../topics/math/lucas-theorem/README.md)
- Practice ladder: [Lucas Theorem / Large Binomial Mod Prime ladder](README.md)
- Starter template: [lucas-binomial.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/lucas-binomial.cpp)
- Notebook refresher: [Lucas Theorem hot sheet](../../../../notebook/lucas-hot-sheet.md)
- Compare points:
  - [Distributing Apples](../../../../practice/ladders/combinatorics/counting-basics/distributingapples.md)
  - [Modular Arithmetic hot sheet](../../../../notebook/modular-arithmetic-hot-sheet.md)
- This note adds: the route chooser between ordinary prime-mod binomial precompute and Lucas digit decomposition.

## Solutions

- Code: [binomialcoefficientprimemod.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/lucas-theorem/binomialcoefficientprimemod.cpp)
