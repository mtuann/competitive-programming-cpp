# Primitive Root

This lane starts when modular arithmetic stops being:

```text
compute powers, inverses, or one root
```

and becomes:

```text
find one generator of the multiplicative group modulo p
```

The repo keeps the first exact route deliberately narrow.

It starts with:

- one prime modulus `p`
- one task of the form:

$$
\text{find } g \text{ such that } \operatorname{ord}_p(g) = p-1
$$

- one contest-clean test:
  - factor `p - 1`
  - reject a candidate `g` if:

$$
g^{(p-1)/q} \equiv 1 \pmod p
$$

for any distinct prime divisor `q` of `p - 1`

This page does **not** start with:

- arbitrary composite moduli that happen to admit primitive roots
- full discrete-root solving as the starter implementation
- cryptographic-scale factorization as the main lesson

The first reusable move is:

```text
for prime p, factor p-1 and test candidate generators against the prime divisors of p-1
```

That is the doorway the repo uses before later lanes such as general discrete roots.

## At A Glance

- **Use when:** the modulus is prime, you need one generator of the nonzero residues, or a later reduction wants a primitive root first
- **Core worldview:** modulo a prime, the nonzero residues form a cyclic group of size `p - 1`, so generator testing is really order testing
- **Main tools:** fast power, distinct prime divisors of `p - 1`, order divisibility
- **Typical complexity:** after factorizing `p - 1`, each candidate test costs `O(k log p)` where `k` is the number of distinct prime divisors
- **Main trap:** overextending the prime-mod generator test to composite moduli, or forgetting that the factorization layer can be the real bottleneck

Strong contest signals:

- the statement asks for a primitive root or generator modulo a prime
- the next step wants to rewrite nonzero residues as powers of one base
- a later `x^k ≡ a (mod p)` reduction clearly needs generator language first
- the judge accepts **any** valid primitive root

Strong anti-cues:

- the unknown is in the exponent -> [BSGS / Discrete Log](../bsgs-discrete-log/README.md)
- the task is only `x^2 ≡ a (mod p)` -> [Modular Square Root / Discrete Root](../modular-square-root-discrete-root/README.md)
- the modulus is composite and you were about to reuse the prime-only generator test unchanged
- the true bottleneck is 64-bit factorization rather than the generator test itself

## Prerequisites

- [Modular Arithmetic](../modular-arithmetic/README.md)
- [Number Theory Basics](../number-theory-basics/README.md)

Helpful nearby anchors:

- [BSGS / Discrete Log](../bsgs-discrete-log/README.md)
- [Modular Square Root / Discrete Root](../modular-square-root-discrete-root/README.md)
- [Pollard-Rho](../pollard-rho/README.md)
- [Modular Arithmetic hot sheet](../../../notebook/modular-arithmetic-hot-sheet.md)
- [Number Theory cheatsheet](../../../notebook/number-theory-cheatsheet.md)

## Problem Model And Notation

For a prime `p`, a **primitive root modulo p** is a number `g` such that every nonzero residue modulo `p` is some power of `g`.

Equivalently:

$$
\operatorname{ord}_p(g) = p - 1
$$

because the multiplicative group of nonzero residues modulo `p` has size `p - 1`.

So the first exact contest question is:

```text
given prime p, output one g whose order modulo p is p-1
```

The special case `p = 2` is trivial:

- the only nonzero residue is `1`
- so the answer is `1`

## From Brute Force To The Right Idea

### Brute Force: Test All Powers

The naive test for one candidate `g` is:

- compute:

$$
g^1, g^2, \dots, g^{p-1} \pmod p
$$

- check whether all nonzero residues appear

That is far too slow once `p` becomes contest-sized.

### The Order Test Shift

For prime `p`, every candidate order divides `p - 1`.

So instead of testing every smaller exponent, we factor:

$$
p - 1 = \prod q_i^{e_i}
$$

and only check the distinct prime divisors `q_i`.

The key theorem is:

$$
g \text{ is primitive mod } p
\iff
g^{(p-1)/q_i} \not\equiv 1 \pmod p
\quad \text{for every distinct prime divisor } q_i \mid (p-1)
$$

So the route becomes:

```text
factor p-1 -> test candidates with fast powers -> return the first valid g
```

## Core Invariants

## 1. Prime-Mod Cyclic-Group Invariant

For prime `p`, the nonzero residues modulo `p` form a cyclic multiplicative group of size `p - 1`.

That is why primitive roots exist here at all, and why "generator of the group" is the right mental model.

## 2. Distinct-Prime-Divisor Test Invariant

Let:

$$
\phi = p - 1
$$

and let `q` range over the distinct prime divisors of `\phi`.

Then a candidate `g` is primitive iff:

$$
g^{\phi/q} \not\equiv 1 \pmod p
$$

for all such `q`.

This is the entire reusable contest test.

## 3. Deterministic-Smallest-Generator Invariant

Contest judges usually accept any primitive root, but this repo's exact route scans candidates in increasing order.

That gives a deterministic answer and keeps smoke tests stable.

## 4. Practical Boundary Invariant

This lane is only correct as an *algorithmic fit* when the factorization of `p - 1` is already cheap enough for the intended constraints, or when a stronger factorization helper has already been supplied.

The generator test itself is light.
The real cost can be:

```text
factor p-1 well enough to know its distinct prime divisors
```

## Exact First Route In This Repo

The repo's first exact route is intentionally narrow:

- one prime modulus `p`
- one primitive root modulo `p`
- one starter that assumes factoring `p - 1` by trial division is still acceptable

The starter exposes:

- `pow_mod(a, e, mod)`
- `distinct_prime_divisors_trial(n)`
- `primitive_root_prime(p)`

This exact starter is **not** a promise of:

- composite-mod primitive-root existence testing
- discrete-root solving
- 64-bit factorization at verifier scale

That broader factorization layer may appear in individual flagship solutions, but it is not the starter contract.

## Variant Chooser

### Use Primitive Root When

- the modulus is prime
- you need one generator of the nonzero residues
- a later reduction wants to linearize multiplicative structure into exponents

### Reopen BSGS / Discrete Log Instead When

- the unknown is the exponent in:

$$
a^x \equiv b \pmod m
$$

- square-root meet-in-the-middle storage is the real issue

### Reopen Modular Square Root Instead When

- the exact task is:

$$
x^2 \equiv a \pmod p
$$

- Tonelli-Shanks is the direct route

### Push This Lane Later When

- the modulus is not prime
- the real bottleneck is factorization of `p - 1`, not generator testing; reopen [Pollard-Rho](../pollard-rho/README.md)
- the task has already crossed into full discrete-root solving

## Practice Archetypes

The most common contest shapes are:

- direct verifier-style primitive-root output under a prime modulus
- a preprocessing step before general `k`-th root solving modulo `p`
- one math task that wants to rewrite residues as exponents of one generator

The strongest smell is:

```text
I need one base g so every nonzero residue mod p becomes g^t.
```

## References And Repo Anchors

Research sweep refreshed on `2026-04-25`.

Reference:

- [cp-algorithms: Primitive Root](https://cp-algorithms.com/algebra/primitive-root.html)
- [OI Wiki: Primitive Root](https://en.oi-wiki.org/math/primitive-root/)

Practice / verifier:

- [Library Checker: Primitive Root](https://judge.yosupo.jp/problem/primitive_root)

Repo anchors:

- practice ladder: [Primitive Root ladder](../../../practice/ladders/math/primitive-root/README.md)
- practice note: [Primitive Root](../../../practice/ladders/math/primitive-root/primitiveroot.md)
- starter template: [primitive-root-prime.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/primitive-root-prime.cpp)
- notebook refresher: [Primitive Root hot sheet](../../../notebook/primitive-root-hot-sheet.md)

## Related Topics

- [Modular Arithmetic](../modular-arithmetic/README.md)
- [BSGS / Discrete Log](../bsgs-discrete-log/README.md)
- [Modular Square Root / Discrete Root](../modular-square-root-discrete-root/README.md)
- [Pollard-Rho](../pollard-rho/README.md)
- [Number Theory Basics](../number-theory-basics/README.md)
