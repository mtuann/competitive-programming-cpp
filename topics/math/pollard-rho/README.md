# Pollard-Rho

This lane starts when ordinary factorization stops being:

```text
trial divide up to sqrt(n)
```

and becomes:

```text
factor one 64-bit integer into prime factors fast enough for contest constraints
```

The repo keeps the first exact route deliberately narrow.

It starts with:

- one integer `n` with:

$$
1 \le n \le 10^{18}
$$

- one target:

```text
return the prime multiset of n
```

- one contest-clean stack:
  - deterministic Miller-Rabin for 64-bit primality
  - Pollard-Rho to split composites
  - recursion until every piece is prime

This page does **not** start with:

- general-purpose symbolic factorization
- ECM or very large integer factorization
- factorization of arbitrary bignums beyond 64-bit contest arithmetic

The first reusable move is:

```text
test 64-bit primality fast, then recursively split composites with Pollard-Rho until only primes remain
```

That is the doorway the repo uses when the factorization layer itself becomes the bottleneck.

## At A Glance

- **Use when:** you need prime factors of one 64-bit integer, or a nearby lane such as [Primitive Root](../primitive-root/README.md) starts failing because factoring `p - 1` is no longer cheap
- **Core worldview:** factorization becomes "quickly separate prime from composite, then probabilistically split the composite"
- **Main tools:** deterministic Miller-Rabin on `uint64_t`, Pollard-Rho cycle finding, recursion, final sorting
- **Typical complexity:** heuristic and fast enough for contest-sized 64-bit inputs; no simple worst-case bound that matters more than the judge reality
- **Main trap:** thinking Pollard-Rho is the whole story and skipping the primality gate, or forgetting that the returned prime multiset still needs sorting / multiplicity handling

Strong contest signals:

- the statement literally asks you to factor numbers up to `1e18`
- trial division to `sqrt(n)` is obviously too slow
- a nearby number-theory route is mathematically right but `p - 1` or `n` is too large for naive factorization
- the output wants primes in ascending order with multiplicity

Strong anti-cues:

- `n` is small enough for SPF / trial division and that simpler route is already fine
- you only need one divisor count or small-prime sieve facts -> [Number Theory Basics](../number-theory-basics/README.md)
- the real task is exponent recovery -> [BSGS / Discrete Log](../bsgs-discrete-log/README.md)
- the real task is primitive-root testing after the factorization layer is already available -> [Primitive Root](../primitive-root/README.md)

## Prerequisites

- [Modular Arithmetic](../modular-arithmetic/README.md)
- [Number Theory Basics](../number-theory-basics/README.md)

Helpful nearby anchors:

- [Primitive Root](../primitive-root/README.md)
- [BSGS / Discrete Log](../bsgs-discrete-log/README.md)
- [Number Theory cheatsheet](../../../notebook/number-theory-cheatsheet.md)

## Problem Model And Notation

The first exact task is:

```text
given one 64-bit integer n, output its prime factor multiset in ascending order
```

That means:

$$
n = p_1 p_2 \cdots p_k
$$

where each `p_i` is prime and multiplicity matters.

The first question is not:

```text
which divisor should I try next?
```

It is:

```text
is this number already prime, or do I still need to split it?
```

That is why Miller-Rabin comes first in the exact route.

## From Brute Force To The Right Idea

### Brute Force: Trial Division

The naive route is:

- try every divisor up to:

$$
\lfloor \sqrt{n} \rfloor
$$

- peel factors as they appear

That collapses as soon as `n` gets close to `10^{18}`.

### The Split-Test Recursion Shift

The contest-grade route changes the question:

1. quickly detect whether `n` is prime
2. if not, find **one nontrivial factor** `d`
3. recurse on `d` and `n / d`

This is exactly the Pollard-Rho worldview:

```text
prime test -> split one composite -> recurse
```

### Why Pollard-Rho Helps

Pollard-Rho generates a pseudorandom sequence modulo `n`, usually:

$$
f(x) = x^2 + c \pmod n
$$

and watches when two iterates collide modulo some hidden prime factor of `n`.

That collision leaks a nontrivial gcd with `n`.

So the algorithm does not need to "guess the factor directly".
It only needs to force enough modular structure that:

$$
\gcd(|x-y|, n)
$$

reveals one proper divisor.

## Core Invariants

## 1. Prime-Test-First Invariant

The recursive factorizer only stops cleanly if it can decide:

```text
this subproblem is already prime
```

So deterministic Miller-Rabin for 64-bit integers is not optional glue.
It is the gate that turns Pollard-Rho from a loop into a factorizer.

## 2. Nontrivial-Split Invariant

Pollard-Rho is only successful when it returns:

$$
1 < d < n
$$

If it returns `n`, that run failed, and the polynomial / seed must be restarted.

This restart rule is a core part of the exact route, not an edge-case patch.

## 3. Recursive-Multiset Invariant

Once one composite `n` is split into:

$$
n = d \cdot \frac{n}{d}
$$

the prime factors of `n` are exactly the union of the prime factors of those two parts.

So the full algorithm is:

```text
factor(left) + factor(right)
```

until every leaf is prime.

## 4. Sorted-Output Invariant

Verifier-style factorization problems usually require ascending prime factors.

The splitting order is not sorted, so the exact route ends with:

```text
sort the accumulated prime multiset
```

## Exact First Route In This Repo

The repo's first exact route is intentionally narrow:

- one `uint64_t` integer
- one sorted prime-factor multiset
- one 64-bit Miller-Rabin
- one Pollard-Rho splitter

The starter exposes:

- `mul_mod(a, b, mod)`
- `pow_mod(a, e, mod)`
- `is_prime_u64(n)`
- `pollard_rho(n)`
- `factorize_u64(n)`

This exact starter is **not** a promise of:

- bignum factorization
- ECM or other advanced integer-factorization machinery
- special algebraic factorizations beyond one contest-ready 64-bit route

## Variant Chooser

### Use Pollard-Rho When

- you need prime factors of 64-bit integers
- naive factorization is the real bottleneck
- a nearby route is mathematically right but blocked by large-factorization cost

### Reopen Primitive Root Instead When

- you already know how to factor `p - 1` cheaply enough
- the real lesson is generator testing, not factorization

### Reopen Number Theory Basics Instead When

- ordinary trial division or SPF sieve is already enough
- the numbers are too small to justify the heavier machinery

### Push This Lane Later When

- factorization is not the bottleneck at all
- the modulus or integer size is outside the 64-bit contest setting

## Practice Archetypes

The most common contest shapes are:

- direct verifier-style factorization of `n <= 1e18`
- supporting machinery for primitive-root or discrete-root problems
- one implementation-heavy number-theory subroutine where trial division TLEs

The strongest smell is:

```text
the math is easy once I know the prime factors, but sqrt(n) trial division is dead
```

## References And Repo Anchors

Research sweep refreshed on `2026-04-25`.

Reference:

- [cp-algorithms: Integer factorization](https://cp-algorithms.com/algebra/factorization.html)
- [CP-Algorithms Library: Factorize](https://lib.cp-algorithms.com/verify/number_theory/factorize.test.cpp.html)

Practice / verifier:

- [Library Checker: Factorize](https://judge.yosupo.jp/problem/factorize)

Repo anchors:

- practice ladder: [Pollard-Rho ladder](../../../practice/ladders/math/pollard-rho/README.md)
- practice note: [Factorize](../../../practice/ladders/math/pollard-rho/factorize.md)
- starter template: [pollard-rho-factorize.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/pollard-rho-factorize.cpp)
- notebook refresher: [Pollard-Rho hot sheet](../../../notebook/pollard-rho-hot-sheet.md)

## Related Topics

- [Number Theory Basics](../number-theory-basics/README.md)
- [Primitive Root](../primitive-root/README.md)
- [BSGS / Discrete Log](../bsgs-discrete-log/README.md)
