# Pollard-Rho Ladder

## Who This Is For

Use this lane when basic number theory feels fine, but 64-bit factorization still feels like a black box and trial division is no longer viable.

## Warm-Up

- trial division and SPF sieve
- fast modular multiplication / exponentiation
- why primality testing must come before recursive splitting

## Core

- deterministic Miller-Rabin for 64-bit primality
- Pollard-Rho to split one composite into two smaller factors
- recurse until all leaves are prime
- flagship verifier-style rep: [Factorize](factorize.md)

## Stretch

- explain why this lane is "split then recurse", not "search divisors directly"
- compare 64-bit factorization with [Primitive Root](../../../../topics/math/primitive-root/README.md) as a consumer of the factorization layer
- say when ordinary trial division is still the better route

## Retrieval Layer

- exact starter -> [pollard-rho-factorize.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/pollard-rho-factorize.cpp)
- quick reminder sheet -> [Pollard-Rho hot sheet](../../../../notebook/pollard-rho-hot-sheet.md)
- compare point -> [Primitive Root](../../../../topics/math/primitive-root/README.md)

## Repo Anchors

- [Factorize](factorize.md)

## Exit Criteria

You are ready to move on when you can:

- explain why Miller-Rabin is the gate before Pollard-Rho
- say what counts as a successful Pollard-Rho split
- recurse to a sorted prime multiset without losing multiplicities
- tell when trial division is still simpler and more appropriate

## External Practice

- [Library Checker - Factorize](https://judge.yosupo.jp/problem/factorize)
- [cp-algorithms - Integer factorization](https://cp-algorithms.com/algebra/factorization.html)

## Tutorial Link

- [Pollard-Rho](../../../../topics/math/pollard-rho/README.md)
