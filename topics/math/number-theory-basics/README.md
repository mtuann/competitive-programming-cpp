# Number Theory Basics

This page is the entry point for divisibility, gcd/lcm, prime factors, and sieve-style preprocessing.

## Prerequisites

- [Modular Arithmetic](../modular-arithmetic/README.md)

## When To Suspect It

- gcd or lcm appears directly
- divisibility or prime exponents matter
- the clean solution factors numbers or precomputes primes
- repeated arithmetic operations become easier when split by prime

## Core Idea

The first tools to know are:

- `gcd`
- `lcm`
- prime factorization
- sieve / SPF preprocessing

A lot of harder problems become much simpler once you stop thinking in decimal form and start tracking the exponent of each prime separately.

## Theory / Proof Sketch

Prime factorization turns multiplication structure into per-prime bookkeeping.

For example:

```text
gcd(a, b): take the smaller exponent of each prime
lcm(a, b): take the larger exponent of each prime
```

This is the right mental model for many gcd/lcm construction problems, divisibility arguments, and "build a target value from operations" problems.

Two especially important identities:

```text
gcd(a, b) * lcm(a, b) = a * b
lcm(a, b) = a / gcd(a, b) * b
```

The second form is the one you usually want in code to reduce overflow risk.

## Complexity And Tradeoffs

- Euclid gcd: very fast, effectively `O(log n)`
- trial division: good for one number of moderate size
- SPF sieve: good when factoring many numbers up front
- linear sieve: good when you need primes and smallest prime factors together

## Canonical Pattern

Template in this repo:

- [number-theory-basics.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/number-theory-basics.cpp)

Notebook:

- [Number theory cheatsheet](../../../notebook/number-theory-cheatsheet.md)

Standard workflow:

1. ask whether the statement is really about divisibility, not values
2. decide whether you need one factorization or many
3. choose `gcd`, trial division, SPF sieve, or linear sieve
4. reason per prime exponent when possible

## Worked Examples

Example 1: gcd / lcm queries

If a task asks for repeated `gcd` on ranges or values built online, the number-theory part is often easy and the real difficulty is the data structure.

Example 2: prime factorization of many numbers with SPF

If `spf[x]` stores the smallest prime factor of `x`, then:

```text
while x > 1:
  p = spf[x]
  count exponent of p
  divide x by p until no longer divisible
```

Example 3: [CRYPTKEY](../../../practice/ladders/math/gcd-lcm/cryptkey.md)

`CRYPTKEY` is a good example of turning a repeated gcd/lcm operation problem into per-prime exponent conditions.

## Recognition Cues

- the words `gcd`, `lcm`, `divisible`, `coprime`, `prime factor`, or `divisor`
- the clean solution seems to depend on factorization structure, not direct simulation
- operations like `gcd` / `lcm` are applied repeatedly and seem to "separate by prime"
- a sieve can replace repeated expensive work

## Common Mistakes

- factoring from scratch in every query
- overflowing when computing lcm naively
- forgetting that prime-exponent reasoning is often simpler than direct simulation
- mixing up "divides" and "is divisible by"
- assuming trial division is fine for many large inputs
- forgetting that `gcd(0, x) = x` is useful in constructions

## Standard Variants

- single-number trial division
- many-number factorization with SPF
- divisor enumeration
- mobius / phi flavored number theory
- gcd/lcm constructions and feasibility checks

## Practice Ladder

- [Number theory basics ladder](../../../practice/ladders/math/number-theory-basics/README.md)

## Repo Anchors

- [Counting Divisors](../../../practice/ladders/math/number-theory-basics/countingdivisors.md): divisor-count precomputation by a direct divisor sieve.
- [LAMP](../../../practice/ladders/math/number-theory-basics/lamp.md): a much heavier number-theory counting example once the basics feel stable.

## Go Deeper

- Course notes: [MIT Mathematics for Computer Science](https://courses.csail.mit.edu/6.042/spring18/mcs.pdf)
- Reference: [CP-Algorithms - Sieve of Eratosthenes](https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html)
- Reference: [CP-Algorithms - Linear Sieve](https://cp-algorithms.com/algebra/prime-sieve-linear.html)
- Reference: [CP-Algorithms - Euclidean Algorithm](https://cp-algorithms.com/algebra/euclid-algorithm.html)
- Blog/reference: [USACO Guide - Divisibility](https://usaco.guide/gold/divisibility?lang=cpp)
- Practice: [CRYPTKEY note](../../../practice/ladders/math/gcd-lcm/cryptkey.md)

## Related Topics

- [Modular Arithmetic](../modular-arithmetic/README.md)
- [FFT / NTT](../fft-ntt/README.md)
