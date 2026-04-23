# Number Theory Basics

This page is the entry point for divisibility, gcd/lcm, prime factors, and sieve-style preprocessing.

## Prerequisites

- [Modular Arithmetic](../modular-arithmetic/README.md)

## When To Suspect It

- gcd or lcm appears directly
- divisibility or prime exponents matter
- the clean solution factors numbers or precomputes primes

## Core Idea

The first tools to know are:

- `gcd`
- `lcm`
- prime factorization
- sieve / SPF preprocessing

A lot of harder problems reduce to tracking the exponent of each prime separately.

## Theory / Proof Sketch

Prime factorization turns multiplication structure into per-prime bookkeeping.

For example:

```text
gcd(a, b): take the smaller exponent of each prime
lcm(a, b): take the larger exponent of each prime
```

This is the right mental model for many gcd/lcm construction problems.

## Complexity And Tradeoffs

- Euclid gcd: very fast, effectively `O(log n)`
- trial division: good for one number of moderate size
- SPF sieve: good when factoring many numbers up front

## Canonical Pattern

Template in this repo:

- [number-theory-basics.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/number-theory-basics.cpp)

Notebook:

- [Number theory cheatsheet](../../../notebook/number-theory-cheatsheet.md)

## Worked Examples

Example 1: gcd / lcm queries

Example 2: prime factorization of many numbers with SPF

Example 3: [CRYPTKEY](../../../practice/ladders/math/gcd-lcm/cryptkey.md)

## Common Mistakes

- factoring from scratch in every query
- overflowing when computing lcm naively
- forgetting that prime-exponent reasoning is often simpler than direct simulation

## Practice Ladder

- [Number theory basics ladder](../../../practice/ladders/math/number-theory-basics/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Sieve of Eratosthenes](https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html)
- Reference: [CP-Algorithms - Linear Sieve](https://cp-algorithms.com/algebra/prime-sieve-linear.html)
- Practice: [CRYPTKEY note](../../../practice/ladders/math/gcd-lcm/cryptkey.md)

## Related Topics

- [Modular Arithmetic](../modular-arithmetic/README.md)
- [FFT / NTT](../fft-ntt/README.md)
