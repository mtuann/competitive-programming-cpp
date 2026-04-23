# Modular Arithmetic

Modular arithmetic is the standard way to keep huge counts manageable and to use algebraic identities safely under a modulus.

## Prerequisites

- [C++ Language For Contests](../../foundations/cpp-language/README.md)

## When To Suspect It

- the statement asks for the answer modulo some number
- counts, powers, or transitions grow too large to store exactly
- you need inverses, factorial tables, or repeated multiplication
- a DP counts ways and the exact number does not matter

## Core Idea

Work with residues instead of raw integers, and keep every step inside the range `0..MOD-1`.

Core identities:

```text
add(a, b) = (a + b) mod MOD
sub(a, b) = (a - b) mod MOD
mul(a, b) = (a * b) mod MOD
```

Fast exponentiation is the first essential tool. After that come inverses, factorial tables, and binomial coefficients.

## Theory / Proof Sketch

Modular arithmetic preserves addition and multiplication:

```text
(a + b) mod MOD = ((a mod MOD) + (b mod MOD)) mod MOD
(a * b) mod MOD = ((a mod MOD) * (b mod MOD)) mod MOD
```

This is why we can reduce aggressively during a DP, combinatorics count, or matrix transition without changing the final answer modulo `MOD`.

For prime `MOD`, modular inverse of `a != 0` can be computed with Fermat's little theorem:

```text
inverse(a) = a^(MOD - 2) mod MOD
```

For general modulus, an inverse exists only when:

```text
gcd(a, MOD) = 1
```

and then extended Euclid is the safer tool.

## Complexity And Tradeoffs

- fast power: `O(log exp)`
- factorial precompute: `O(n)`
- one inverse with extended Euclid: `O(log MOD)`

Tradeoffs:

- prime modulus is much easier than composite modulus
- subtraction needs normalization to avoid negative residues
- division is not a primitive operation; it only works when an inverse exists

## Canonical Pattern

Template in this repo:

- [modular-arithmetic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/modular-arithmetic.cpp)

Notebook:

- [Number theory cheatsheet](../../../notebook/number-theory-cheatsheet.md)

Typical helpers:

```text
normalize(x):
  x %= MOD
  if x < 0: x += MOD
  return x

powmod(a, e):
  result = 1
  while e > 0:
    if e is odd: result = result * a mod MOD
    a = a * a mod MOD
    e >>= 1
```

## Worked Examples

Example 1: count paths modulo `MOD`

If a graph DP asks for "number of paths modulo `1e9+7`", then every transition can reduce immediately:

```text
dp[v] = (dp[v] + dp[u]) mod MOD
```

You do not need the exact count first.

Example 2: binomial coefficients with factorial tables

For many queries of `nCr mod MOD` under a prime modulus:

```text
fact[i] = i! mod MOD
inv_fact[i] = (fact[i])^(MOD - 2) mod MOD
nCr = fact[n] * inv_fact[r] * inv_fact[n-r] mod MOD
```

Example 3: modular inverse under a prime modulus

To divide by `a`, replace division with multiplication by `inverse(a)`.

```text
b / a mod MOD  ->  b * inverse(a) mod MOD
```

Only do this when the inverse is valid.

## Recognition Cues

- the statement literally says "print the answer modulo `MOD`"
- combinatorics counts explode quickly
- matrix exponentiation or linear recurrences appear
- DP states count ways, not best values
- polynomial or convolution code needs exact modular coefficients

## Common Mistakes

- mixing ordinary division with modular arithmetic
- forgetting to normalize after subtraction
- applying Fermat inverse when the modulus is not prime
- multiplying two `int` values before casting to `long long`
- assuming `%` in C++ always returns a nonnegative residue
- precomputing factorials without checking the needed range first

## Standard Variants

- prime modulus with fast inverse
- composite modulus where inverse may not exist
- precomputed factorial / inverse-factorial tables
- prefix products and modular division by removing one factor
- CRT-style problems where several moduli must be combined later

## Practice Ladder

- [Math ladder overview](../../../practice/ladders/math/README.md)
- [Modular arithmetic ladder](../../../practice/ladders/math/modular-arithmetic/README.md)

## Go Deeper

- Course notes: [MIT Mathematics for Computer Science](https://courses.csail.mit.edu/6.042/spring18/mcs.pdf)
- Reference: [CP-Algorithms - Modular Inverse](https://cp-algorithms.com/algebra/module-inverse.html)
- Reference: [CP-Algorithms - Binary Exponentiation](https://cp-algorithms.com/algebra/binary-exp.html)
- Reference: [CP-Algorithms - Binomial Coefficients](https://cp-algorithms.com/combinatorics/binomial-coefficients.html)
- Blog/reference: [USACO Guide - Modular Arithmetic](https://usaco.guide/gold/modular?lang=cpp)
- Practice: [CSES Problem Set](https://cses.fi/problemset/)

## Related Topics

- [Number Theory Basics](../number-theory-basics/README.md)
- [Combinatorics](../../combinatorics/README.md)
