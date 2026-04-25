# Discrete Log Hot Sheet

Use this page when the unknown is in the exponent and the contest-sized route is:

$$
a^x \equiv b \pmod m
$$

with `O(sqrt(m))` time and memory still acceptable.

## Do Not Use When

- you only need `powmod` or one modular inverse
- the real task is congruence merging, not exponent recovery
- `sqrt(m)` memory is already too large for the intended constraints
- the intended lane is [Modular Square Root / Discrete Root](../topics/math/modular-square-root-discrete-root/README.md) rather than plain discrete log

## Choose By Signal

- recover `x` from `a^x ≡ b (mod m)` -> [`discrete-log-bsgs.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/discrete-log-bsgs.cpp)
- recover one square root from `x^2 ≡ a (mod p)` -> [Modular Square Root hot sheet](modular-square-root-hot-sheet.md)
- solve `a x ≡ b (mod m)` or merge residue classes -> [Chinese Remainder / Linear Congruences](../topics/math/chinese-remainder/README.md)
- only compute powers / inverses under one modulus -> [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md)

## Core Invariants

- in the coprime stage, rewrite `x = pn + q` with `n ≈ sqrt(m)`
- store baby steps and scan giant steps until one residue collision appears
- keep the minimum `pn + q`, not just any valid answer
- when `gcd(a, m) > 1`, reduce first; BSGS is the second stage, not the whole story
- this route only makes sense when the square-root table is still contest-safe

## Main Traps

- forgetting the `gcd`-reduction stage for composite-mod instances
- returning one collision without checking whether it is the minimum valid exponent
- treating this as a cheap lane when `m` is too large for `O(sqrt(m))` memory
- mixing up discrete log with linear congruence solving

## Exact Starters In This Repo

- exact starter -> [`discrete-log-bsgs.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/discrete-log-bsgs.cpp)
- flagship in-lane rep -> [Discrete Logarithm Mod](../practice/ladders/math/bsgs-discrete-log/discretelogarithmmod.md)
- nearby compare points -> [Chinese Remainder / Linear Congruences](../topics/math/chinese-remainder/README.md), [Modular Square Root / Discrete Root](../topics/math/modular-square-root-discrete-root/README.md)
- nearby foundation -> [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md)

## Reopen Paths

- full lesson -> [BSGS / Discrete Log](../topics/math/bsgs-discrete-log/README.md)
- broader chooser -> [Number Theory cheatsheet](number-theory-cheatsheet.md)
- template chooser -> [Template Library](../template-library.md)
