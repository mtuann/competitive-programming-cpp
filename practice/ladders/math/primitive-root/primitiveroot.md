# Primitive Root

- Title: `Primitive Root`
- Judge / source: `Library Checker`
- Original URL: [https://judge.yosupo.jp/problem/primitive_root](https://judge.yosupo.jp/problem/primitive_root)
- Secondary topics: `Generator test`, `Factorization of p-1`, `Fast power`
- Difficulty: `hard`
- Subtype: `Find one primitive root modulo one prime`
- Status: `solved`
- Solution file: [primitiveroot.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/primitive-root/primitiveroot.cpp)

## Why Practice This

This is the cleanest verifier-style anchor for the repo's first exact `Primitive Root` lane.

The mathematical route is narrow:

- one prime modulus `p`
- one target: output **any** primitive root modulo `p`
- one reusable test: factor `p - 1`, then reject candidates whose reduced-order powers collapse to `1`

So the lesson is not full composite-mod primitive-root theory and not general discrete-root solving.

It is:

- understand why a primitive root is an element of order `p - 1`
- factor the group size `p - 1`
- test candidates against the distinct prime divisors of `p - 1`

The judge is a little wider operationally than the starter contract because `p` can be a large 64-bit prime. That means the verifier solution upgrades the **factorization layer**, but the generator test itself stays exactly the same.

## Recognition Cue

Reach for this lane when:

- the modulus is prime
- the statement wants one generator of the nonzero residues
- later algebra wants to rewrite every nonzero residue as a power of one base
- the judge accepts any valid primitive root

The strongest smell is:

```text
I need one g so every nonzero residue modulo p becomes g^t.
```

## Problem-Specific Transformation

For prime `p`, let:

$$
\phi = p - 1
$$

and factor `\phi` into its distinct prime divisors:

$$
\phi = \prod q_i^{e_i}
$$

A candidate `g` is a primitive root modulo `p` iff:

$$
g^{\phi/q_i} \not\equiv 1 \pmod p
$$

for every distinct prime divisor `q_i`.

So the problem reduces to:

1. handle `p = 2`
2. factor `p - 1`
3. scan `g = 2, 3, 4, ...`
4. print the first candidate that survives all the order tests

## Core Idea

The implementation separates the lane into two exact layers.

### 1. Factorization Layer

You need the **distinct prime divisors** of `p - 1`.

The repo starter uses the narrowest route:

- ordinary trial division

The verifier-style solution widens only this part:

- deterministic 64-bit primality testing
- Pollard-Rho factorization

### 2. Generator-Test Layer

Once the distinct prime divisors of `p - 1` are known, the reusable contest test is tiny:

- for each candidate `g`
- check all:

$$
g^{(p-1)/q}
$$

- if none equals `1`, `g` is primitive

That is the real lesson of the lane.

## Complexity

After factorization of `p - 1` is available:

- each candidate test costs `O(k log p)` where `k` is the number of distinct prime divisors

So the main runtime question is usually:

```text
how expensive is it to factor p-1 under this judge's constraints?
```

The starter keeps that narrow.
The verifier solution upgrades it because this judge needs 64-bit factorization support.

## Solution Sketch

1. Read prime `p`.
2. If `p = 2`, output `1`.
3. Factor `p - 1` and keep only distinct prime divisors.
4. For `g = 2, 3, 4, ...`:
   - set `ok = true`
   - for every distinct prime divisor `q` of `p - 1`, check:

$$
g^{(p-1)/q} \pmod p
$$

   - if any result is `1`, reject `g`
   - otherwise print `g`

## Common Pitfalls

- forgetting to deduplicate prime divisors of `p - 1`
- using the prime-mod generator test unchanged for composite moduli
- forgetting the `p = 2` edge case
- copying the repo starter to this verifier without upgrading the factorization layer; that upgrade path is [Pollard-Rho](../../../../topics/math/pollard-rho/README.md)

## Related Paths

- Bigger theory step: [Primitive Root](../../../../topics/math/primitive-root/README.md)
- Factorization doorway: [Pollard-Rho](../../../../topics/math/pollard-rho/README.md)
- Compare point: [BSGS / Discrete Log](../../../../topics/math/bsgs-discrete-log/README.md)
- Follow-up doorway: [Modular Square Root / Discrete Root](../../../../topics/math/modular-square-root-discrete-root/README.md)
- Retrieval page: [Primitive Root hot sheet](../../../../notebook/primitive-root-hot-sheet.md)
