# Discrete Logarithm Mod

- Title: `Discrete Logarithm Mod`
- Judge / source: `Library Checker`
- Original URL: [https://judge.yosupo.jp/problem/discrete_logarithm_mod](https://judge.yosupo.jp/problem/discrete_logarithm_mod)
- Secondary topics: `Baby-step giant-step`, `Meet-in-the-middle`, `gcd reduction`
- Difficulty: `hard`
- Subtype: `General discrete log with gcd reduction`
- Status: `solved`
- Solution file: [discretelogarithmmod.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/bsgs-discrete-log/discretelogarithmmod.cpp)

## Why Practice This

This is the cleanest verifier-style anchor for the repo's first exact `BSGS / Discrete Log` lane.

The problem is exactly:

$$
a^x \equiv b \pmod m
$$

with many test cases, and the key contest lesson is:

- modular exponentiation alone is not enough
- brute force over `x` is too slow
- the practical route is `gcd` reduction plus BSGS

## Recognition Cue

Reach for this lane when:

- the unknown is the exponent
- the statement wants one minimum nonnegative `x`
- the modulus is not guaranteed prime
- `O(sqrt(m))` memory is still plausible for the input size

The strongest smell is:

```text
I know how to compute a^x mod m quickly.
Now I need to recover x.
```

## Problem-Specific Transformation

If:

$$
\gcd(a, m) = 1
$$

then BSGS is the clean meet-in-the-middle route:

- write `x = pn + q`
- store baby steps
- scan giant steps
- match the residues

But the general judge version is slightly wider:

- `a` and `m` may share factors

So the first stage is a reduction loop:

- if the current gcd does not divide `b`, there is no solution
- otherwise peel one factor off and record that one exponent step is now forced

Only after that reduced system becomes coprime do you run ordinary BSGS.

## Core Idea

The implementation separates the lane into two exact layers.

### 1. General Reduction Layer

Maintain:

- `add`: how many exponent steps have already been forced
- `k`: the multiplicative prefix already accumulated on the left side

At each gcd reduction:

- if `b == k`, the current `add` is already the minimum answer
- if `b % g != 0`, reject
- otherwise divide out the common factor and continue

### 2. Coprime BSGS Layer

Once:

$$
\gcd(a, m) = 1
$$

you can invert `a`, set:

$$
x = pn + q,
$$

and match:

$$
a^q \equiv b \cdot a^{-pn} \pmod m
$$

with one hash table.

That makes the runtime and memory both `O(sqrt(m))`.

## Implementation Plan

1. normalize `a` and `b` modulo `m`
2. handle tiny edge cases like `m = 1`, `b = 1`, and `a = 0`
3. run the gcd-reduction loop
4. solve the remaining coprime instance with BSGS
5. add the forced prefix length back to the coprime answer

## Complexity

- per test case: `O(sqrt(m))` time and memory in the contest-sized regime

The reduction loop is cheap compared with the square-root table.

## Main Traps

- forgetting the early `b == k` success case during gcd reduction
- trying to run inverse-based BSGS before the modulus becomes coprime with the base
- returning one valid collision without preserving the minimum-answer contract
- using this route when `sqrt(m)` storage is already too large for the judge

## Reopen Path

- Topic page: [BSGS / Discrete Log](../../../../topics/math/bsgs-discrete-log/README.md)
- Practice ladder: [BSGS / Discrete Log ladder](README.md)
- Starter template: [discrete-log-bsgs.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/discrete-log-bsgs.cpp)
- Notebook refresher: [Discrete Log hot sheet](../../../../notebook/discrete-log-hot-sheet.md)
- Compare points:
  - [Chinese Remainder / Linear Congruences](../../../../topics/math/chinese-remainder/README.md)
  - [Modular Arithmetic hot sheet](../../../../notebook/modular-arithmetic-hot-sheet.md)

## Solutions

- Code: [discretelogarithmmod.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/bsgs-discrete-log/discretelogarithmmod.cpp)
