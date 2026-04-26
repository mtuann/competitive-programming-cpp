# Counting Necklaces

- Title: `Counting Necklaces`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/2209](https://cses.fi/problemset/task/2209)
- Secondary topics: `Burnside lemma`, `Rotation symmetry`, `Modular arithmetic`
- Difficulty: `hard`
- Subtype: `Count k-colorings of an n-cycle up to cyclic rotation`
- Status: `solved`
- Solution file: [countingnecklaces.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/combinatorics/burnside-polya/countingnecklaces.cpp)

## Why Practice This

This is the cleanest first Burnside problem in the repo:

- the group is explicit and small enough to describe completely
- the fixed-coloring count under one rotation is simple
- modular arithmetic is present, but the real step up is symmetry counting

It is the right first anchor because the orbit-counting idea is fully visible and not hidden inside a heavier cycle-index formula.

## Recognition Cue

Reach for Burnside when:

- the statement says two colorings are the same after a rotation
- direct counting of raw strings is easy, but deduplicating by symmetry is not
- the symmetry group is explicit enough that you can count fixed assignments for each element

The strongest smell here is:

- "count colorings on a cycle, where cyclic shifts do not create new objects"

## Problem-Specific Transformation

Raw objects:

- strings of length `n` over `m` colors

Real objects:

- equivalence classes of those strings under cyclic rotation

So the task is not to count strings directly. It is to count orbits of the `C_n` action on those strings.

That is exactly Burnside's lemma territory.

## Core Idea

For each rotation `r` from `0` to `n-1`:

- applying the rotation partitions positions into cycles
- the number of cycles is `gcd(n, r)`
- a coloring fixed by that rotation must be constant on each cycle
- so the number of fixed colorings is `m^{gcd(n, r)}`

Burnside gives:

```text
answer = (1 / n) * sum_{r = 0}^{n - 1} m^{gcd(n, r)}
```

Because the modulus is `1e9+7` and `n <= 1e6`, division by `n` is implemented as multiplication by `n^{-1} mod MOD`.

## Complexity

- `O(n log MOD)` using one `powmod` per rotation

This is fast enough for the official constraints `n, m <= 10^6`.

## Pitfalls / Judge Notes

- The symmetry is **rotation only**. Do not add reflections.
- The answer is not `m^n / n`; different rotations fix different numbers of colorings.
- The implementation relies on modular inverse of `n`, which is legal here because `MOD` is prime and `n < MOD`.
- If you already know the grouped divisor form, it is equivalent, but the direct Burnside loop keeps the route easier to trust.

## Reusable Pattern

- Topic page: [Burnside / Pólya / Group Actions](../../../../topics/combinatorics/burnside-polya/README.md)
- Practice ladder: [Burnside / Pólya ladder](README.md)
- Starter template: [burnside-cyclic-necklaces.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/combinatorics/burnside-cyclic-necklaces.cpp)
- Notebook refresher: [Burnside / Pólya hot sheet](../../../../notebook/burnside-polya-hot-sheet.md)
- Carry forward: when the group is small and explicit, count fixed representations per group element and average
- This note adds: the exact `gcd(n, r)` cycle-count identity for cyclic rotations

## Solutions

- Code: [countingnecklaces.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/combinatorics/burnside-polya/countingnecklaces.cpp)
