# Exponentiation II

- Title: `Exponentiation II`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1712](https://cses.fi/problemset/task/1712)
- Secondary topics: `Binary exponentiation`, `Fermat reduction`, `Zero-exponent edge case`
- Difficulty: `medium`
- Subtype: `Compute a^(b^c) modulo a prime efficiently`
- Status: `solved`
- Solution file: [exponentiation2.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/modular-arithmetic/exponentiation2.cpp)

## Why Practice This

This is one of the best small problems for turning modular arithmetic from “just use `% MOD` everywhere” into real algebraic reasoning.

The key question is not how to compute `a^x mod MOD` once. We already know binary exponentiation.

The real question is:

```text
how do we shrink the exponent x = b^c first?
```

## Recognition Cue

This is a modular-arithmetic alarm bell:

- the exponent itself is another huge exponent
- direct evaluation of `b^c` is impossible
- the modulus is prime
- the real task is to reduce the exponent before the outer power

Whenever the exponent is too large to materialize, stop and ask what cycle length the exponent lives in.

## Problem-Specific Transformation

The raw expression is:

```text
a^(b^c) mod MOD
```

The reusable rewrite is:

1. treat the outer exponent as a separate quantity `e`
2. reduce `e` modulo `MOD - 1` using Fermat's little theorem
3. compute `a^e mod MOD` with binary exponentiation

The only extra branch is the zero-base / zero-exponent edge case, because exponent reduction alone does not explain what to do when `a % MOD == 0`.

## Core Idea

Let:

```text
MOD = 1_000_000_007
```

which is prime.

If `a` is not divisible by `MOD`, Fermat's little theorem gives:

```text
a^(MOD - 1) ≡ 1 (mod MOD)
```

So exponents can be reduced modulo `MOD - 1`:

```text
a^(b^c) mod MOD = a^( (b^c mod (MOD-1)) ) mod MOD
```

That means the algorithm is:

1. compute `e = b^c mod (MOD - 1)` with binary exponentiation
2. compute `a^e mod MOD` with binary exponentiation again

There is one important edge case:

- if `a % MOD == 0`, then positive exponents give answer `0`
- but exponent `0` gives answer `1`

So we explicitly detect whether `b^c == 0` before applying the reduction shortcut to a zero base.

## Complexity

Each query performs two fast exponentiations:

- `O(log c)` for `b^c mod (MOD - 1)`
- `O(log MOD)` for `a^e mod MOD`

So each test case is effectively `O(log MOD)`.

## Pitfalls / Judge Notes

- Reduce the exponent modulo `MOD - 1`, not modulo `MOD`.
- Modular division is irrelevant here; this is pure exponent reduction plus binary exponentiation.
- The zero-base / zero-exponent edge case is easy to miss if you apply Fermat reduction blindly.
- Keep multiplication in `long long` before taking `% MOD`.

## Reusable Pattern

- Topic page: [Modular Arithmetic](../../../../topics/math/modular-arithmetic/README.md)
- Practice ladder: [Modular Arithmetic ladder](README.md)
- Starter template: [modular-arithmetic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/modular-arithmetic.cpp)
- Notebook refresher: [Number theory cheatsheet](../../../../notebook/number-theory-cheatsheet.md)
- Carry forward: decide which operations are happening mod `M` and which are happening on exponents first.
- This note adds: the exponent reduction or edge-case logic needed by this modular task.

## Solutions

- Code: [exponentiation2.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/modular-arithmetic/exponentiation2.cpp)
