# GCD / LCM

This page is the bridge between:

- the divisibility toolkit from [Number Theory Basics](../number-theory-basics/README.md)
- and the richer congruence / modular-system world in
  [Chinese Remainder / Linear Congruences](../chinese-remainder/README.md)

The point is not that `gcd` and `lcm` formulas exist.

The point is learning to treat gcd/lcm problems as:

- prime-exponent bookkeeping
- fold / all-except-one aggregation
- and, when witnesses are required, Bézout-style linear combination structure

## At A Glance

- **Use when:** the statement is about common divisors, least common multiples, coprimality, gcd feasibility, or repeated gcd/lcm operations across many values
- **Core worldview:** gcd and lcm are per-prime exponent operators, not just arithmetic formulas
- **Main tools:** Euclid, safe `lcm`, prefix/suffix gcd, prime-exponent reasoning, extended gcd when witness integers matter
- **Typical complexity:** `O(log n)` for one gcd, `O(n log A)` for folds over many values, plus factorization cost when the prime view must become explicit
- **Main trap:** memorizing `gcd * lcm = a * b` but not noticing when the real argument is per-prime, or when overflow and non-coprime structure matter

Strong contest signals:

- maximize or constrain gcd over many values
- build or test one number with a target gcd/lcm relation
- remove one element and recompute a gcd
- ask for integers `x, y` with `ax + by = g`

Strong anti-cues:

- the statement is really about modular inverses, not gcd itself
- the modulus system needs consistency across several congruences -> move to
  [Chinese Remainder / Linear Congruences](../chinese-remainder/README.md)
- the hard part is factorizing large 64-bit values, not reasoning with gcd/lcm

## Prerequisites

- [Number Theory Basics](../number-theory-basics/README.md)
- [Modular Arithmetic](../modular-arithmetic/README.md)

Helpful neighboring topics:

- [Chinese Remainder / Linear Congruences](../chinese-remainder/README.md)
- [Pollard-Rho](../pollard-rho/README.md)

## Problem Model And Notation

For positive integers:

$$
\gcd(a, b)
$$

is the largest common divisor, and

$$
\mathrm{lcm}(a, b)
$$

is the smallest common multiple.

If

$$
a = \prod p^{\alpha_p},
\qquad
b = \prod p^{\beta_p},
$$

then:

$$
\gcd(a, b) = \prod p^{\min(\alpha_p, \beta_p)},
\qquad
\mathrm{lcm}(a, b) = \prod p^{\max(\alpha_p, \beta_p)}.
$$

That exponent view is the real coordinate system for this page.

## From Brute Force To The Right Idea

### Brute Force: Treat GCD And LCM As Black-Box Functions

At first, people solve gcd/lcm problems by:

- calling `gcd` mechanically
- applying one formula
- hoping the structure is enough

That works for warm-ups, but not when the problem asks:

- what happens if one element is removed?
- can a construction exist?
- which prime exponents survive repeated gcd/lcm operations?

### The First Shift: GCD And LCM Are Per-Prime Operators

The deep reason many gcd/lcm tasks are easy is:

- every prime can be reasoned about independently

So the real question becomes:

- which exponent on each prime is forced, allowed, minimized, or maximized?

### The Second Shift: Aggregation Patterns Matter

Many standard tasks are not about one pair.

They are about:

- gcd over all values
- gcd over all but one value
- lcm under overflow-safe order
- gcd/lcm constraints on a whole array

That is why prefix/suffix gcd and fold reasoning show up so often.

### The Third Shift: Witness Problems Need Extended GCD

If the statement asks for integers satisfying:

$$
ax + by = g,
$$

then the topic is no longer only "compute a gcd value."

It becomes:

- use extended Euclid to recover one Bézout witness

That is the clean bridge from plain gcd values into modular inverses and
congruence solving.

## Core Invariants And Why They Work

### 1. Euclid Preserves The Common-Divisor Set

The identity

$$
\gcd(a, b) = \gcd(b, a \bmod b)
$$

works because `a = qb + r` implies:

- every common divisor of `a` and `b` also divides `r`
- every common divisor of `b` and `r` also divides `a`

So the common-divisor set is unchanged.

### 2. Safe LCM Must Divide First

The contest-safe formula is:

$$
\mathrm{lcm}(a, b) = \frac{a}{\gcd(a, b)} \cdot b.
$$

Divide before multiplying.

Otherwise a correct mathematical idea becomes a wrong machine-level answer.

### 3. Prefix / Suffix GCD Reuses Associativity

Because gcd is associative:

$$
\gcd(a, \gcd(b, c)) = \gcd(\gcd(a, b), c),
$$

you can precompute:

- prefix gcds
- suffix gcds

and combine them to answer "all except one" style questions in linear total
time.

### 4. Extended GCD Produces One Bézout Witness

If

$$
g = \gcd(a, b),
$$

then there exist integers `x, y` such that:

$$
ax + by = g.
$$

That is the structural gateway to:

- modular inverse when `g = 1`
- linear congruence solving
- CRT merges with consistency checks

## Variant Chooser

### Stay In Number Theory Basics When

- the task is still about factoring, divisor counting, or sieve preprocessing more than gcd/lcm structure itself

### Stay On This GCD / LCM Page When

- the main work is Euclid, prime-exponent reasoning, safe lcm, or gcd aggregation over many values

### Move To Modular Arithmetic When

- Bézout is only a stepping stone to inverses, modular equations, or power laws

### Move To Chinese Remainder When

- several congruences must be merged
- gcd consistency between moduli becomes the actual obstacle

## Repo Anchors And Compare Points

- [GCD / LCM ladder](../../../practice/ladders/math/gcd-lcm/README.md)
- [Euclid Problem](../../../practice/ladders/math/gcd-lcm/euclidproblem.md)
- [Common Divisors](../../../practice/ladders/math/gcd-lcm/commondivisors.md)
- [GCD on Blackboard](../../../practice/ladders/math/gcd-lcm/gcdonblackboard.md)
- [CRYPTKEY](../../../practice/ladders/math/gcd-lcm/cryptkey.md)
- [General Chinese Remainder](../../../practice/ladders/math/chinese-remainder/generalchineseremainder.md)

## Sources

- Reference: [CP-Algorithms - Euclidean algorithm](https://cp-algorithms.com/algebra/euclid-algorithm.html)
- Reference: [Competitive Programmer's Handbook](https://www.cses.fi/book/book.pdf)
- Practice: [CSES Problem Set](https://cses.fi/problemset/)
