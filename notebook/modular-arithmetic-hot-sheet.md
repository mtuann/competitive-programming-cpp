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
- recover one square root modulo one prime -> reopen [Modular Square Root hot sheet](modular-square-root-hot-sheet.md) before copying inverse code blindly
- find one generator modulo one prime once `p-1` factorization is already under control -> reopen [Primitive Root hot sheet](primitive-root-hot-sheet.md)
- solve one whole linear system modulo one prime -> reopen [Gaussian Elimination hot sheet](gaussian-elimination-hot-sheet.md) before copying inverse code blindly
- recover the exponent from `a^x ≡ b (mod m)` -> reopen [Discrete Log hot sheet](discrete-log-hot-sheet.md) before copying any helper blindly
- invert one truncated formal power series under `998244353` -> reopen [Polynomial / FPS hot sheet](polynomial-fps-hot-sheet.md) after the NTT layer is already trusted
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
- treating quadratic-residue extraction like a plain inverse / power helper problem

## Exact Starters In This Repo

- prime-mod `powmod` and inverse -> [`modular-arithmetic.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/modular-arithmetic.cpp)
- many `nCk mod prime` queries -> [`factorial-binomial-mod.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/factorial-binomial-mod.cpp)
- composite-mod inverse via Bezout coefficient plus normalization, or plain Diophantine solving -> [`extended-gcd-diophantine.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/extended-gcd-diophantine.cpp)
- anchor notes -> [Exponentiation](../practice/ladders/math/modular-arithmetic/exponentiation.md), [Exponentiation II](../practice/ladders/math/modular-arithmetic/exponentiation2.md), [Euclid Problem](../practice/ladders/math/gcd-lcm/euclidproblem.md)

## Reopen Paths

- proofs, inverse existence, and exponent reduction boundaries -> [Modular Arithmetic](../topics/math/modular-arithmetic/README.md)
- neighboring integer tools -> [Number theory cheatsheet](number-theory-cheatsheet.md)
- root extraction under one prime -> [Modular Square Root hot sheet](modular-square-root-hot-sheet.md)
- generator finding under one prime -> [Primitive Root hot sheet](primitive-root-hot-sheet.md)
- FPS algebra after trusted NTT -> [Polynomial / FPS hot sheet](polynomial-fps-hot-sheet.md)
- factorization / gcd / sieve base layer -> [Number Theory Basics](../topics/math/number-theory-basics/README.md)
