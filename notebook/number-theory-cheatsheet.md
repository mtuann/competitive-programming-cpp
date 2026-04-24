# Number Theory Cheatsheet

Use this page when divisibility, residues, or algebraic constraints appear and you want the smallest reliable helper.

## Core Tools

- `gcd(a, b)`
- `lcm(a, b) = a / gcd(a, b) * b`
- prime factorization
- SPF sieve
- fast power
- modular inverse
- Bezout / extended Euclid

## Choose By Signal

- repeated powers modulo `MOD` -> [modular-arithmetic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/modular-arithmetic.cpp)
- many `nCk mod prime` queries -> [factorial-binomial-mod.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/factorial-binomial-mod.cpp)
- `ax + by = c` or inverse under composite modulus -> [extended-gcd-diophantine.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/extended-gcd-diophantine.cpp)
- plain divisibility / factors / totients -> [number-theory-basics.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/number-theory-basics.cpp)

## Prime-Exponent View

```text
gcd: take the smaller exponent
lcm: take the larger exponent
```

## Typical Signals

- divisibility
- repeated factorizations
- counting modulo a prime
- legal or illegal modular division
- combinatorics under one fixed prime modulus

## Quick Anchors In This Repo

- modular power / tower reasoning -> [Exponentiation II](../practice/ladders/math/modular-arithmetic/exponentiation2.md)
- gcd / divisibility -> [CRYPTKEY](../practice/ladders/math/gcd-lcm/cryptkey.md)
- broader workflow -> [Modular Arithmetic topic](../topics/math/modular-arithmetic/README.md)
