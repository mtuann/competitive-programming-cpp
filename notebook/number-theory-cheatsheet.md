# Number Theory Cheatsheet

Use this page when divisibility, residues, or algebraic constraints appear and you want the smallest reliable helper.

## Do Not Use When

- the core task is counting structure rather than arithmetic structure
- the problem is really implementation-heavy modular DP rather than number theory
- you have not yet separated “integer fact” from “mod prime computation”

## Core Tools

- `gcd(a, b)`
- `lcm(a, b) = a / gcd(a, b) * b`
- prime factorization
- SPF sieve
- fast power
- modular inverse
- Bezout / extended Euclid

## Choose By Signal

- repeated powers modulo `MOD` -> [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md)
- many `nCk mod prime` queries -> [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md)
- `ax + by = c` or inverse under composite modulus -> [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md)
- plain divisibility / factors / totients -> [number-theory-basics.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/number-theory-basics.cpp)

## Prime-Exponent View

```text
gcd: take the smaller exponent
lcm: take the larger exponent
```

## Core Invariants

- modular division is only legal when an inverse exists
- prime-factor views turn gcd and lcm into exponentwise min/max
- repeated-power problems usually reduce to fast exponentiation before anything fancier

## Typical Signals

- divisibility
- repeated factorizations
- counting modulo a prime
- legal or illegal modular division
- combinatorics under one fixed prime modulus

## Quick Anchors In This Repo

- modular power / tower reasoning -> [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md) + [Exponentiation II](../practice/ladders/math/modular-arithmetic/exponentiation2.md)
- gcd / divisibility -> [CRYPTKEY](../practice/ladders/math/gcd-lcm/cryptkey.md)
- broader workflow -> [Modular Arithmetic topic](../topics/math/modular-arithmetic/README.md)

## Main Trap

The most common wrong turn is treating “mod arithmetic” as if every denominator were invertible, or treating `lcm(a, b)` as safe without thinking about overflow in `a / gcd(a, b) * b`.

## Reopen Paths

- topic pages -> [Modular Arithmetic](../topics/math/modular-arithmetic/README.md), [Number Theory Basics](../topics/math/number-theory-basics/README.md)
- exact quick sheet -> [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md)
- template layer -> [Template library](../template-library.md)
