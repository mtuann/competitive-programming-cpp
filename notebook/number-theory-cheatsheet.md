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
- recover one square root from `x^2 ≡ a (mod p)` under one prime modulus -> [Modular Square Root hot sheet](modular-square-root-hot-sheet.md)
- find one generator of the nonzero residues modulo prime `p` -> [Primitive Root hot sheet](primitive-root-hot-sheet.md)
- factor one 64-bit integer into sorted prime factors -> [Pollard-Rho hot sheet](pollard-rho-hot-sheet.md)
- recover `x` from `a^x ≡ b (mod m)` with square-root meet-in-the-middle -> [Discrete Log hot sheet](discrete-log-hot-sheet.md)
- gcd/divisor counting over all multiples -> [Mobius hot sheet](mobius-hot-sheet.md)
- summatory arithmetic functions opened through one divisor-side floor-sum -> [Dirichlet prefix sums hot sheet](dirichlet-prefix-sums-hot-sheet.md)
- implicit prefix sums of `phi` / `mu` on the quotient set `Q_n` -> [Min_25 / Du Jiao hot sheet](min25-du-jiao-hot-sheet.md)
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
- gcd / divisibility -> [GCD / LCM](../topics/math/gcd-lcm/README.md) + [CRYPTKEY](../practice/ladders/math/gcd-lcm/cryptkey.md)
- exponent recovery modulo one contest-sized modulus -> [Discrete Log hot sheet](discrete-log-hot-sheet.md) + [Discrete Logarithm Mod](../practice/ladders/math/bsgs-discrete-log/discretelogarithmmod.md)
- modular square-root extraction modulo one prime -> [Modular Square Root hot sheet](modular-square-root-hot-sheet.md) + [Sqrt Mod](../practice/ladders/math/modular-square-root-discrete-root/sqrtmod.md)
- primitive-root finding modulo one prime -> [Primitive Root hot sheet](primitive-root-hot-sheet.md) + [Primitive Root](../practice/ladders/math/primitive-root/primitiveroot.md)
- 64-bit integer factorization -> [Pollard-Rho hot sheet](pollard-rho-hot-sheet.md) + [Factorize](../practice/ladders/math/pollard-rho/factorize.md)
- divisor-side inclusion-exclusion -> [Counting Coprime Pairs](../practice/ladders/math/mobius-multiplicative/countingcoprimepairs.md)
- quotient-grouped summatory sigma -> [Sum of Divisors](../practice/ladders/math/dirichlet-prefix-sums/sumofdivisors.md)
- quotient-set prefix phi -> [Sum of Totient Function](../practice/ladders/math/min25-du-jiao/sumoftotientfunction.md)
- broader workflow -> [Modular Arithmetic topic](../topics/math/modular-arithmetic/README.md)

## Main Trap

The most common wrong turn is treating “mod arithmetic” as if every denominator were invertible, or treating `lcm(a, b)` as safe without thinking about overflow in `a / gcd(a, b) * b`.

## Reopen Paths

- topic pages -> [Modular Arithmetic](../topics/math/modular-arithmetic/README.md), [Number Theory Basics](../topics/math/number-theory-basics/README.md), [GCD / LCM](../topics/math/gcd-lcm/README.md), [BSGS / Discrete Log](../topics/math/bsgs-discrete-log/README.md), [Modular Square Root / Discrete Root](../topics/math/modular-square-root-discrete-root/README.md), [Primitive Root](../topics/math/primitive-root/README.md), [Pollard-Rho](../topics/math/pollard-rho/README.md), [Mobius And Multiplicative Counting](../topics/math/mobius-multiplicative/README.md), [Dirichlet Convolution / Prefix Sums Of Number-Theoretic Functions](../topics/math/dirichlet-prefix-sums/README.md), [Min_25 / Du Jiao](../topics/math/min25-du-jiao/README.md)
- exact quick sheet -> [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md)
- exact exponent-recovery sheet -> [Discrete Log hot sheet](discrete-log-hot-sheet.md)
- exact root-extraction sheet -> [Modular Square Root hot sheet](modular-square-root-hot-sheet.md)
- exact generator-finding sheet -> [Primitive Root hot sheet](primitive-root-hot-sheet.md)
- exact 64-bit factorization sheet -> [Pollard-Rho hot sheet](pollard-rho-hot-sheet.md)
- exact gcd/divisor quick sheet -> [Mobius hot sheet](mobius-hot-sheet.md)
- exact prefix-sum quick sheet -> [Dirichlet prefix sums hot sheet](dirichlet-prefix-sums-hot-sheet.md)
- exact implicit prefix-sum quick sheet -> [Min_25 / Du Jiao hot sheet](min25-du-jiao-hot-sheet.md)
- template layer -> [Template library](../template-library.md)
