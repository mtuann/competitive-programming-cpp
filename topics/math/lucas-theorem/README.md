# Lucas Theorem / Large Binomial Mod Prime

This lane starts when a binomial coefficient problem stops being:

```text
precompute factorials once, answer nCk mod p in O(1)
```

and becomes:

```text
n is too large relative to p, so one factorial table no longer covers the query
```

The key shift is:

- stop treating `n` and `k` as one huge pair
- write them in base `p`
- reduce the large query into many tiny digit-level binomials

For contest work, this is the exact route for:

- `C(n, k) mod p` with `p` prime
- some queries where `n >= p`, so ordinary `fact / inv_fact` tables stop being enough
- special cases like parity of binomial coefficients when `p = 2`

## At A Glance

- **Use when:** the task is really `nCk mod p` for a prime modulus, and `n` can be too large for one factorial table below `p`
- **Core worldview:** write `n` and `k` in base `p`, then multiply small digit-level binomials
- **Main tools:** Lucas theorem, factorial / inverse-factorial table for `0..p-1`, Fermat inverse
- **Typical complexity:** `O(p)` precompute, then `O(log_p n)` per query
- **Main trap:** reaching for Lucas when `p` is huge, so `O(p)` precompute is not actually contest-safe

Strong contest signals:

- many `nCk mod p` queries under one fixed prime modulus
- at least some queries cross the boundary `n >= p`
- the statement is still about one prime modulus, not a composite reconstruction
- parity or small-prime residue patterns in Pascal-like objects matter

Strong anti-cues:

- every query satisfies `max_n < p`, so one ordinary factorial table is enough
- the modulus is composite, so CRT / generalized Lucas would be needed instead
- the real problem is counting-model setup, not binomial evaluation itself
- `p` is so large that `O(p)` precompute is already a non-starter

## Prerequisites

- [Modular Arithmetic](../modular-arithmetic/README.md)
- [Chinese Remainder / Linear Congruences](../chinese-remainder/README.md) only as a future compare point for composite-mod extensions
- [Counting Basics](../../combinatorics/counting-basics/README.md) if the combinatorial meaning of `nCk` is still shaky

Helpful nearby anchors:

- [factorial-binomial-mod.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/factorial-binomial-mod.cpp)
- [Distributing Apples](../../../practice/ladders/combinatorics/counting-basics/distributingapples.md)

## Problem Model And Notation

We want:

$$
\binom{n}{k} \bmod p
$$

where:

- `p` is prime
- `n` and `k` may be much larger than `p`

Write the base-`p` expansions:

$$
n = n_0 + n_1 p + n_2 p^2 + \dots
$$

$$
k = k_0 + k_1 p + k_2 p^2 + \dots
$$

with:

$$
0 \le n_i, k_i < p
$$

Lucas theorem says:

$$
\binom{n}{k} \equiv \prod_i \binom{n_i}{k_i} \pmod p
$$

So the large query is reduced to many small binomial queries where the arguments are below `p`.

## From Brute Force To The Right Idea

### Brute Force

The ordinary contest route for one prime modulus is:

- precompute `fact[i]` and `inv_fact[i]` up to some `max_n`
- answer:

$$
\binom{n}{k} = \frac{n!}{k!(n-k)!}
$$

in `O(1)` time

That is excellent when:

$$
\max n < p
$$

and the precompute limit is small enough.

### Where It Breaks

If:

$$
n \ge p
$$

then `n! mod p` is already `0`, because `p` appears as a factor.

So the ordinary factorial-table formula no longer behaves the way it did for `n < p`.

That is the real boundary.

The problem is not:

- "how do I optimize factorials more?"

It is:

- "how do I rewrite the large binomial in a way that respects base-`p` digit structure?"

### Structural Observation

The prime modulus `p` does not only control inversion.

It also controls the digit system that breaks the problem apart.

Once `n` and `k` are expressed in base `p`, Lucas theorem turns one huge binomial into a product of tiny ones.

That is why the theorem belongs in this repo as its own lane, not just as a footnote under modular arithmetic.

## Core Invariant And Why It Works

## 1. Digit Decomposition Is The Real State

The large pair `(n, k)` is processed digit by digit:

```text
current answer = product of all processed base-p digit binomials
```

At each step:

- `ni = n % p`
- `ki = k % p`
- multiply by `C(ni, ki) mod p`
- divide both `n` and `k` by `p`

That loop is the whole computational invariant.

## 2. Small Binomials Are Ordinary Again

Each digit pair satisfies:

$$
0 \le n_i, k_i < p
$$

So the subproblem:

$$
\binom{n_i}{k_i} \bmod p
$$

is back in the easy regime.

That is exactly where one factorial / inverse-factorial table for:

$$
0,1,\dots,p-1
$$

becomes useful.

## 3. Why Zero Appears Early

If for some digit:

$$
k_i > n_i
$$

then:

$$
\binom{n_i}{k_i} = 0
$$

and therefore the entire product is `0 mod p`.

This is one of the most useful implementation payoffs:

```text
one impossible digit is enough to kill the whole answer
```

## 4. Boundary With Ordinary Factorial Tables

If every query satisfies:

$$
\max n < p
$$

then Lucas adds no value.

The lighter route is still:

- precompute to `max_n`
- answer with one factorial formula

That is why the right chooser is:

- ordinary table first when `max_n < p`
- Lucas when the query range crosses `p`

## Variant Chooser

### Use Ordinary Prime-Mod Binomial Precompute When

- the modulus `p` is prime
- all queries satisfy `max_n < p`
- one table up to `max_n` is cheap

That is the route in:

- [factorial-binomial-mod.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/factorial-binomial-mod.cpp)

### Use Lucas Theorem When

- the modulus is still one prime `p`
- some queries have `n >= p`
- `p` is small enough that `O(p)` precompute is acceptable

That is this lane.

### Do Not Use Lucas For Composite Modulus

If the modulus is composite, the prime-mod digit theorem is no longer enough.

That becomes a future lane involving:

- generalized Lucas
- prime powers
- CRT reconstruction

This repo is **not** shipping that extension in this page.

## Worked Examples

### Example 1. Tiny Lucas Merge

Compute:

$$
\binom{10}{3} \bmod 5
$$

Write numbers in base `5`:

$$
10 = (2,0)_5,\qquad 3 = (0,3)_5
$$

Lucas gives:

$$
\binom{10}{3}
\equiv
\binom{2}{0}\binom{0}{3}
\pmod 5
$$

But:

$$
\binom{0}{3}=0
$$

so:

$$
\binom{10}{3}\equiv 0 \pmod 5
$$

The important lesson is not the number `0`.

It is:

- one impossible digit kills the whole product immediately

### Example 2. Query Range Boundary

Suppose the modulus is:

$$
p = 13
$$

and the queries are:

$$
\binom{12}{4}, \binom{11}{3}, \binom{9}{2}
$$

Then `max_n < p`, so Lucas is unnecessary.

The clean route is one factorial table up to `12`.

But if one query becomes:

$$
\binom{100}{20}
$$

then the ordinary single table no longer explains the large-`n` jump.

That is the point where Lucas becomes the exact lane.

### Example 3. Library Checker Binomial Coefficient (Prime Mod)

The clean reusable split is:

1. read all queries under one prime modulus `p`
2. if every query has `n < p`, use one ordinary factorial table to `max_n`
3. otherwise, if `p` is still precompute-safe, build `0..p-1` and answer with Lucas digit decomposition

That is why this problem is such a good repo anchor:

- it teaches the chooser, not just the theorem

## Pseudocode

```text
build fact[0..p-1], inv_fact[0..p-1]

small_binom(n, k):
    if k < 0 or k > n:
        return 0
    return fact[n] * inv_fact[k] * inv_fact[n-k] mod p

lucas(n, k):
    ans = 1
    while n > 0 or k > 0:
        ni = n % p
        ki = k % p
        if ki > ni:
            return 0
        ans = ans * small_binom(ni, ki) mod p
        n /= p
        k /= p
    return ans
```

## Implementation Notes

- Lucas needs `p` prime.
- The starter in this repo assumes:
  - `p` is small enough for `O(p)` precompute
  - one digit table `0..p-1` is feasible
- If `p` is huge but every query still has `n < p`, ordinary factorial precompute to `max_n` is usually cleaner.
- Use `long long` for `n` and `k`, even if the digit table is indexed by `int`.
- Return `0` immediately on the first digit where `ki > ni`.

## Worked Compare Points In This Repo

- [Distributing Apples](../../../practice/ladders/combinatorics/counting-basics/distributingapples.md): ordinary factorial-table binomial route under a large prime modulus
- [Chinese Remainder / Linear Congruences](../chinese-remainder/README.md): future compare point when the modulus stops being prime
- [Modular Arithmetic](../modular-arithmetic/README.md): inverse discipline and prime-mod arithmetic layer

## In This Repo

- [Lucas Theorem / Large Binomial Mod Prime ladder](../../../practice/ladders/math/lucas-theorem/README.md)
- [Lucas Theorem hot sheet](../../../notebook/lucas-hot-sheet.md)
- [Binomial Coefficient (Prime Mod) note](../../../practice/ladders/math/lucas-theorem/binomialcoefficientprimemod.md)
- [starter template](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/lucas-binomial.cpp)
- compare points:
  - [Modular Arithmetic](../modular-arithmetic/README.md)
  - [Chinese Remainder / Linear Congruences](../chinese-remainder/README.md)

## References

- Reference: [cp-algorithms - Binomial Coefficients](https://cp-algorithms.com/combinatorics/binomial-coefficients.html)
- Essay / Blog: [AtCoder ABC251 editorial (Lucas theorem section)](https://atcoder.jp/contests/abc251/editorial/3995)
- Practice: [Library Checker - Binomial Coefficient (Prime Mod)](https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod)
- Practice: [Kattis - Odd Binomial Coefficients](https://open.kattis.com/problems/oddbinom)
