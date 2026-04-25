# Modular Arithmetic Hot Sheet

Use this page when one fixed modulus is in play and you need the fastest route back to safe `powmod`, inverse, or `nCk mod prime` helpers.

## Do Not Use When

- the real task is factorization, divisors, or gcd structure rather than residues
- the modulus is composite or changes per query and you have not separated those cases
- the problem needs a slower proof page more than a retrieval sheet

## Choose By Signal

- repeated powers or one-off inverses under one fixed prime modulus -> [`modular-arithmetic.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/modular-arithmetic.cpp)
- many `nCk mod prime` queries after one precompute -> [`factorial-binomial-mod.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/factorial-binomial-mod.cpp)
- inverse under composite modulus with `gcd(a, mod) = 1`, or solve `ax + by = c` -> [`extended-gcd-diophantine.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/extended-gcd-diophantine.cpp)
- exponent towers / exponent reduction questions -> reopen [Exponentiation II](../practice/ladders/math/modular-arithmetic/exponentiation2.md) or the topic page before copying helpers blindly

## Core Invariants

- modular division is legal only when the inverse exists
- the repo `mod_inv` helper uses Fermat, so its contract is “fixed prime modulus”
- factorial / inverse-factorial tables are only the clean route when `max_n < MOD` and many queries justify the precompute

## Main Traps

- using Fermat under a composite modulus
- forgetting to normalize after subtraction
- assuming `n!` is invertible when `n >= MOD`
- multiplying large values before `% MOD` without thinking about overflow

## Exact Starters In This Repo

- prime-mod `powmod` and inverse -> [`modular-arithmetic.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/modular-arithmetic.cpp)
- many `nCk mod prime` queries -> [`factorial-binomial-mod.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/factorial-binomial-mod.cpp)
- composite-mod inverse via Bezout coefficient plus normalization, or plain Diophantine solving -> [`extended-gcd-diophantine.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/extended-gcd-diophantine.cpp)
- anchor notes -> [Exponentiation](../practice/ladders/math/modular-arithmetic/exponentiation.md), [Exponentiation II](../practice/ladders/math/modular-arithmetic/exponentiation2.md)

## Reopen Paths

- proofs, inverse existence, and exponent reduction boundaries -> [Modular Arithmetic](../topics/math/modular-arithmetic/README.md)
- neighboring integer tools -> [Number theory cheatsheet](number-theory-cheatsheet.md)
- factorization / gcd / sieve base layer -> [Number Theory Basics](../topics/math/number-theory-basics/README.md)
