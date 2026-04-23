# Modular Arithmetic

Modular arithmetic is the standard way to keep huge counts manageable and to use algebraic identities safely under a modulus.

## Prerequisites

- [C++ Language For Contests](../../foundations/cpp-language/README.md)

## When To Suspect It

- the statement asks for the answer modulo some number
- counts or powers grow too large
- you need inverses, factorial tables, or repeated multiplication

## Core Idea

Work with values modulo `MOD` and normalize after each arithmetic step.

Core identities:

```text
(a + b) mod MOD
(a - b) mod MOD
(a * b) mod MOD
```

Fast power is the base tool for repeated exponentiation.

## Theory / Proof Sketch

Modular arithmetic preserves addition and multiplication:

```text
(a + b) mod MOD = ((a mod MOD) + (b mod MOD)) mod MOD
(a * b) mod MOD = ((a mod MOD) * (b mod MOD)) mod MOD
```

For prime `MOD`, modular inverse of `a != 0` can be computed with:

```text
a^(MOD - 2) mod MOD
```

## Complexity And Tradeoffs

- fast power: `O(log exp)`
- factorial precompute: `O(n)`

Tradeoffs:

- prime modulus is much easier than composite modulus
- subtraction needs normalization to avoid negative residues

## Canonical Pattern

Template in this repo:

- [modular-arithmetic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/modular-arithmetic.cpp)

Notebook:

- [Number theory cheatsheet](../../../notebook/number-theory-cheatsheet.md)

## Worked Examples

Example 1: count paths modulo `MOD`

Example 2: binomial coefficients with factorial tables

Example 3: modular inverse under a prime modulus

## Common Mistakes

- mixing ordinary division with modular arithmetic
- forgetting to normalize after subtraction
- applying Fermat inverse when the modulus is not prime

## Practice Ladder

- [Math ladder overview](../../../practice/ladders/math/README.md)
- [Modular arithmetic ladder](../../../practice/ladders/math/modular-arithmetic/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Modular Inverse](https://cp-algorithms.com/algebra/module-inverse.html)
- Reference: [CP-Algorithms - Binary Exponentiation](https://cp-algorithms.com/algebra/binary-exp.html)
- Practice: [CSES Problem Set](https://cses.fi/problemset/)

## Related Topics

- [Number Theory Basics](../number-theory-basics/README.md)
- [Combinatorics](../../combinatorics/README.md)
