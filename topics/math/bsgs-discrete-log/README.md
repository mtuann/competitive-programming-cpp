# BSGS / Discrete Log

This lane starts when a modular-arithmetic problem stops being:

```text
compute a^k mod m
```

and becomes:

```text
recover the exponent x from a^x ≡ b (mod m)
```

That is the **discrete logarithm** problem.

For contest work, the first exact route is usually:

- use `gcd`-reduction until the base is coprime with the modulus
- then run **baby-step giant-step** (BSGS)
- and accept the `O(sqrt(m))` time and memory bill when that is still contest-safe

This page is intentionally narrow.

It does **not** try to teach:

- [primitive roots](../primitive-root/README.md) as a separate lane
- [discrete roots](../modular-square-root-discrete-root/README.md)
- index calculus or cryptographic-scale discrete log

It teaches the exact route that still appears in competitive programming:

```text
solve a^x ≡ b (mod m) for one contest-sized modulus
```

## At A Glance

- **Use when:** the task is literally or structurally `a^x ≡ b (mod m)` and `O(sqrt(m))` memory is still acceptable
- **Core worldview:** discrete log is a meet-in-the-middle problem after the right modular normalization
- **Main tools:** `gcd` reduction, modular inverse, baby-step giant-step hash table
- **Typical complexity:** `O(sqrt(m))` time and memory after `O(log^2 m)`-style arithmetic overhead
- **Main trap:** forgetting that this route is only practical when the modulus or group size is small enough for a square-root table

Strong contest signals:

- the unknown is in the exponent, not in the base
- the statement asks for the smallest `x` such that:

$$
a^x \equiv b \pmod m
$$

- the modulus is not necessarily prime, so Fermat-only thinking is too weak
- the intended solution is meet-in-the-middle rather than one deeper algebraic theorem

Strong anti-cues:

- the real task is only modular exponentiation or inverse computation
- the modulus is so large that `O(sqrt(m))` memory is obviously impossible
- the intended lane is [Primitive Root](../primitive-root/README.md) or [Modular Square Root / Discrete Root](../modular-square-root-discrete-root/README.md) rather than plain discrete log
- the arithmetic domain is not one ordinary modular multiplicative setting at all

## Prerequisites

- [Modular Arithmetic](../modular-arithmetic/README.md)
- [Number Theory Basics](../number-theory-basics/README.md)

Helpful nearby anchors:

- [Chinese Remainder / Linear Congruences](../chinese-remainder/README.md)
- [Modular Arithmetic hot sheet](../../../notebook/modular-arithmetic-hot-sheet.md)
- [Number Theory cheatsheet](../../../notebook/number-theory-cheatsheet.md)

## Problem Model And Notation

We want the smallest nonnegative integer `x` such that:

$$
a^x \equiv b \pmod m
$$

for given integers `a`, `b`, and `m`.

Unlike ordinary logarithms over the reals:

- a solution may not exist
- the solution need not be unique
- the structure depends strongly on `gcd(a, m)`

So the contest question is usually:

```text
return one minimum x, or report that no solution exists
```

## From Brute Force To The Right Idea

### Brute Force

The naive route is:

- compute `a^0, a^1, a^2, ... mod m`
- stop when the value becomes `b`

That costs `O(m)` or worse, which is too slow once `m` reaches contest-sized limits.

### The Meet-In-The-Middle Shift

Suppose first that:

$$
\gcd(a, m) = 1
$$

Write:

$$
x = p n + q
$$

where:

$$
n \approx \lceil \sqrt{m} \rceil
$$

Then:

$$
a^{pn+q} \equiv b \pmod m
$$

which rearranges to:

$$
a^q \equiv b \cdot a^{-pn} \pmod m
$$

Now:

- `q` is the **baby step**
- `p` is the **giant step**

So instead of searching over all `x`, we search two square-root-sized spaces and match them with a hash table.

### Why GCD Reduction Comes First

If `gcd(a, m) > 1`, the inverse `a^{-1}` does not exist modulo `m`, so the clean meet-in-the-middle form is blocked.

The standard fix is:

- peel off common gcd factors
- detect impossible cases early
- reduce to one coprime instance

That is why the production contest route is really:

```text
gcd reduction -> coprime BSGS
```

## Core Invariants And Why They Work

## 1. Coprime BSGS Invariant

Once `gcd(a, m) = 1`, the inverse exists modulo `m`.

So if:

$$
x = pn + q
$$

then:

$$
a^q \equiv b \cdot a^{-pn} \pmod m
$$

The invariant is:

- store all baby steps `a^q`
- walk all giant steps `b \cdot a^{-pn}`
- any collision reconstructs one valid exponent

That is the meet-in-the-middle core of BSGS.

## 2. Minimum-Answer Invariant

Contest problems usually ask for the minimum nonnegative solution.

So the route in this repo is:

- keep the earliest baby step for each residue
- scan giant steps in increasing `p`
- track the minimum `pn + q` among collisions

This avoids quietly returning a valid but non-minimal exponent.

## 3. GCD-Reduction Invariant

When:

$$
g = \gcd(a, m) > 1
$$

the equation:

$$
a^x \equiv b \pmod m
$$

forces divisibility conditions on `b`.

The standard loop maintains:

```text
current equation has been reduced by "add" forced exponent steps,
and k tracks the prefix multiplier already committed on the left side
```

If at some stage:

- `b == k`, then the current `add` is already the minimum answer
- `b % g != 0`, no solution exists
- otherwise divide by `g`, update the state, and continue

After the loop, the remaining instance is coprime and BSGS applies cleanly.

## 4. Practical Boundary Invariant

This lane is only correct as an *algorithmic fit* when:

```text
sqrt(modulus or group size) is still small enough to store
```

That is not a proof invariant, but it is a crucial contest invariant.

If `m` is too large for a square-root hash table, the route is wrong even if the math is correct.

## Exact First Route In This Repo

The repo's first exact route is intentionally narrow:

- solve one general discrete log:

$$
a^x \equiv b \pmod m
$$

- return the minimum nonnegative `x`
- support the usual `gcd`-reduction before the coprime BSGS stage

The starter exposes:

- `pow_mod(a, e, m)`
- `mod_inverse(a, m)` for the coprime stage
- `bsgs_coprime(a, b, m)`
- `discrete_log(a, b, m)` as the top-level route

This exact starter is **not** a promise of:

- [primitive-root finding](../primitive-root/README.md)
- [discrete roots](../modular-square-root-discrete-root/README.md)
- subgroup-order optimizations
- cryptographic-scale performance

## Variant Chooser

### Use BSGS / Discrete Log When

- the unknown is the exponent
- one modular equation is the real bottleneck
- `O(sqrt(m))` memory is acceptable

### Reopen Modular Arithmetic Instead When

- you only need `powmod`, inverse, or one congruence solve
- the unknown is not in the exponent

### Reopen Chinese Remainder / Linear Congruences When

- the task is about residue-system consistency rather than exponent recovery
- you are solving `a x ≡ b (mod m)` or merged residue classes, not discrete log

### Push This Lane Later When

- [Primitive Root](../primitive-root/README.md), [Modular Square Root / Discrete Root](../modular-square-root-discrete-root/README.md), or deeper number-theory structure are the real goal
- the modulus is so large that square-root memory obviously kills the route

## Practice Archetypes

The most common contest shapes are:

- direct verifier-style `a^x ≡ b (mod m)`
- a modeling step that reduces some exponent question to one discrete log query
- composite modulus instances where plain prime-mod intuition fails

The strongest smell is:

```text
I can compute a^x mod m quickly, but now I need to recover x.
```

## References And Repo Anchors

Research sweep refreshed on `2026-04-25`.

Reference:

- [CP-Algorithms: Discrete Logarithm](https://cp-algorithms.com/algebra/discrete-log.html)
- [OI Wiki: BSGS](https://en.oi-wiki.org/math/bsgs/)

Practice / verifier:

- [Library Checker: Discrete Logarithm Mod](https://judge.yosupo.jp/problem/discrete_logarithm_mod)

Repo anchors:

- practice ladder: [BSGS / Discrete Log ladder](../../../practice/ladders/math/bsgs-discrete-log/README.md)
- practice note: [Discrete Logarithm Mod](../../../practice/ladders/math/bsgs-discrete-log/discretelogarithmmod.md)
- starter template: [discrete-log-bsgs.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/discrete-log-bsgs.cpp)
- notebook refresher: [Discrete Log hot sheet](../../../notebook/discrete-log-hot-sheet.md)

## Related Topics

- [Modular Arithmetic](../modular-arithmetic/README.md)
- [Chinese Remainder / Linear Congruences](../chinese-remainder/README.md)
- [Number Theory Basics](../number-theory-basics/README.md)
- [Primitive Root](../primitive-root/README.md)
