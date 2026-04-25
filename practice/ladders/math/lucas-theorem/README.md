# Lucas Theorem / Large Binomial Mod Prime Ladder

## Who This Is For

Use this ladder when ordinary factorial / inverse-factorial binomial code feels familiar, but you still hesitate when a query crosses `n >= p`.

## Warm-Up

- modular inverse under a prime modulus
- factorial / inverse-factorial binomial precompute
- base conversion and digit decomposition

## Core

- detect the boundary `max_n < p` versus `n >= p`
- apply Lucas theorem digit by digit
- keep one prime-mod binomial helper for the digit layer

## Stretch

- special-case parity and other tiny-prime patterns
- explain why composite moduli are outside the first Lucas lane
- compare the lightweight factorial-table route against Lucas on the same judge

## Retrieval Layer

- exact starter -> [lucas-binomial.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/lucas-binomial.cpp)
- quick reminder sheet -> [Lucas Theorem hot sheet](../../../../notebook/lucas-hot-sheet.md)
- compare point -> [factorial-binomial-mod.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/factorial-binomial-mod.cpp)

## Repo Anchors

- [Binomial Coefficient (Prime Mod)](binomialcoefficientprimemod.md)

## Exit Criteria

You are ready to move on when you can:

- tell immediately whether one factorial table is enough
- explain Lucas as a base-`p` digit product instead of a memorized formula
- stop early when one digit forces the answer to zero
- explain why composite-mod binomial problems are a different lane

## External Practice

- [Library Checker - Binomial Coefficient (Prime Mod)](https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod)
- [Kattis - Odd Binomial Coefficients](https://open.kattis.com/problems/oddbinom)

## Tutorial Link

- [Lucas Theorem / Large Binomial Mod Prime](../../../../topics/math/lucas-theorem/README.md)
