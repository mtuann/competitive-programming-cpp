# Modular Square Root Hot Sheet

Use this page when the task is:

$$
x^2 \equiv a \pmod p
$$

with one prime modulus and you want the shortest safe route back to Tonelli-Shanks.

## Do Not Use When

- the unknown is in the exponent rather than the base
- the modulus is composite or a prime power and you have not separated that case
- the real target is general `x^k ≡ a (mod p)` rather than square roots

## Choose By Signal

- recover one square root modulo one prime -> [`mod-sqrt-tonelli-shanks.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/mod-sqrt-tonelli-shanks.cpp)
- recover the exponent from `a^x ≡ b (mod m)` -> [Discrete Log hot sheet](discrete-log-hot-sheet.md)
- solve several residue conditions at once -> [Chinese Remainder / Linear Congruences](../topics/math/chinese-remainder/README.md)
- only need power / inverse / factorial helpers -> [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md)

## Core Invariants

- for odd prime `p`, test reachability first with Euler's criterion
- split:

$$
p - 1 = q \cdot 2^s
$$

with `q` odd

- Tonelli-Shanks shrinks the remaining mismatch inside a subgroup of `2`-power order
- if `r` is one root, then `p-r` is the other nonzero root

## Main Traps

- applying the Legendre test under a composite modulus
- forgetting the `a = 0` and `p = 2` edge cases
- assuming Tonelli-Shanks is the route for general `k`-th roots
- returning "no root" without normalizing `a mod p` first

## Exact Starters In This Repo

- exact starter -> [`mod-sqrt-tonelli-shanks.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/mod-sqrt-tonelli-shanks.cpp)
- flagship in-lane rep -> [Sqrt Mod](../practice/ladders/math/modular-square-root-discrete-root/sqrtmod.md)
- compare point -> [BSGS / Discrete Log](../topics/math/bsgs-discrete-log/README.md)
- nearby foundation -> [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md)

## Reopen Paths

- full lesson -> [Modular Square Root / Discrete Root](../topics/math/modular-square-root-discrete-root/README.md)
- broader chooser -> [Number Theory cheatsheet](number-theory-cheatsheet.md)
- template chooser -> [Template Library](../template-library.md)
