# Modular Square Root / Discrete Root

This lane starts when modular arithmetic stops being:

```text
compute powers, inverses, or one residue merge
```

and becomes:

```text
recover one root inside the multiplicative structure itself
```

The repo keeps the first exact route deliberately narrow.

It starts with:

- one odd prime modulus `p`
- one query of the form:

$$
x^2 \equiv a \pmod p
$$

- one contest-clean algorithm:
  - **Tonelli-Shanks**

This page does **not** start with:

- general prime-power lifting
- composite-mod square roots
- full primitive-root theory as the first lesson
- general `k`-th roots as the starter implementation

The first reusable move is:

```text
test whether a is a quadratic residue mod p,
then recover one square root with Tonelli-Shanks
```

The same family eventually grows into:

- [primitive roots](../primitive-root/README.md)
- discrete roots of the form `x^k ≡ a (mod p)`
- reductions to [BSGS / Discrete Log](../bsgs-discrete-log/README.md)

but those are the **follow-up boundary**, not the first snippet to memorize.

## At A Glance

- **Use when:** the statement literally asks for `x^2 ≡ a (mod p)` under one prime modulus, or a larger task reduces to quadratic-residue extraction
- **Core worldview:** decide whether `a` is a quadratic residue first, then recover one root through repeated squaring structure rather than brute force
- **Main tools:** fast power, Legendre symbol, Tonelli-Shanks, normalization modulo `p`
- **Typical complexity:** `O(log^2 p)`-style arithmetic for one odd prime query
- **Main trap:** overextending a prime-mod square-root snippet to composite moduli, prime powers, or general `k`-th roots without checking the group structure

Strong contest signals:

- the modulus is prime or explicitly guaranteed to be one prime per query
- the unknown appears as:

$$
x^2 \equiv a \pmod p
$$

- the task wants one valid root or `-1`
- direct brute force over `x = 0 .. p-1` is impossible
- a larger number-theory task needs square-root extraction as one subroutine

Strong anti-cues:

- the unknown is in the exponent -> [BSGS / Discrete Log](../bsgs-discrete-log/README.md)
- several residue conditions must all hold simultaneously -> [Chinese Remainder / Linear Congruences](../chinese-remainder/README.md)
- the modulus is composite and you were about to apply the Legendre-symbol test anyway
- the real target is `x^k ≡ a (mod p)` for general `k`; that is the discrete-root follow-up after primitive-root and discrete-log machinery is ready

## Prerequisites

- [Modular Arithmetic](../modular-arithmetic/README.md)
- [Number Theory Basics](../number-theory-basics/README.md)

Helpful nearby anchors:

- [BSGS / Discrete Log](../bsgs-discrete-log/README.md)
- [Primitive Root](../primitive-root/README.md)
- [Chinese Remainder / Linear Congruences](../chinese-remainder/README.md)
- [Modular Arithmetic hot sheet](../../../notebook/modular-arithmetic-hot-sheet.md)
- [Number Theory cheatsheet](../../../notebook/number-theory-cheatsheet.md)

## Problem Model And Notation

The first exact task is:

$$
x^2 \equiv a \pmod p
$$

where `p` is prime.

If a solution exists, there are usually two roots:

$$
x \quad \text{and} \quad p-x
$$

except in degenerate cases like `a = 0` or `p = 2`.

The first question is not "how do I search for x?"

It is:

```text
is a even a quadratic residue modulo p?
```

For odd prime `p`, Euler's criterion says:

$$
a^{(p-1)/2} \equiv
\begin{cases}
1 \pmod p & \text{if } a \text{ is a nonzero quadratic residue} \\
-1 \pmod p & \text{if } a \text{ is a non-residue}
\end{cases}
$$

That residue test is the gate before Tonelli-Shanks is even allowed to continue.

## From Brute Force To The Right Idea

### Brute Force: Try Every x

The direct approach is:

- test `x = 0 .. p-1`
- check whether `x^2 mod p == a`

That is `O(p log p)` or worse and immediately dies for contest-sized primes.

### The First Shift: Think In The Multiplicative Group

For odd prime `p`, the nonzero residues form a cyclic multiplicative group of size:

$$
p-1
$$

Square-root extraction is now a group-structure question, not a value search.

The first two moves are:

1. determine whether the target is even reachable as a square
2. if it is reachable, recover one root by exploiting the factorization:

$$
p - 1 = q \cdot 2^s
$$

with `q` odd

That is the Tonelli-Shanks worldview.

## Core Technique

For odd prime `p`:

1. normalize `a mod p`
2. handle trivial cases:
   - `a = 0`
   - `p = 2`
3. compute the Legendre test:

$$
a^{(p-1)/2} \pmod p
$$

4. if the answer is `-1 mod p`, there is no root
5. otherwise split:

$$
p - 1 = q \cdot 2^s
$$

with `q` odd

6. find one quadratic non-residue `z`
7. run Tonelli-Shanks to maintain:
   - one current candidate root
   - one current correction factor
   - one shrinking power-of-two order

The invariant is:

```text
the remaining mismatch lives inside a subgroup of 2-power order,
and each round shrinks that order
```

## Exact Starter Route In This Repo

- Topic: this page
- Hot sheet: [Modular Square Root hot sheet](../../../notebook/modular-square-root-hot-sheet.md)
- Starter: [`mod-sqrt-tonelli-shanks.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/mod-sqrt-tonelli-shanks.cpp)
- Flagship note: [Sqrt Mod](../../../practice/ladders/math/modular-square-root-discrete-root/sqrtmod.md)

That starter intentionally assumes:

- one prime modulus per query
- Tonelli-Shanks is the exact route
- we want **one** root or `-1`

It does **not** pretend to solve:

- composite-mod square roots
- Hensel lifting
- all roots for arbitrary prime powers
- general discrete roots

## Follow-Up Boundary: Discrete Root

The same family later asks for:

$$
x^k \equiv a \pmod p
$$

That is the **discrete-root** lane.

The reusable contest route there is usually:

1. find a primitive root modulo `p`
2. rewrite every nonzero residue as a power of that primitive root
3. reduce the root problem to:
   - one linear congruence over exponents, or
   - one [BSGS / Discrete Log](../bsgs-discrete-log/README.md) instance

So the conceptual progression is:

```text
modular arithmetic
-> modular square root
-> primitive root + discrete log
-> general discrete root
```

Do not jump straight to this second step if square-root extraction itself still feels shaky.

## Worked Micro-Example

Solve:

$$
x^2 \equiv 10 \pmod{13}
$$

Check the squares mod `13`:

- `6^2 = 36 ≡ 10`
- `7^2 = 49 ≡ 10`

So the valid roots are `6` and `7`.

The repo starter returns one deterministic representative, typically the smaller root.

## Main Failure Modes

- using Euler's criterion under a composite modulus
- forgetting the `a = 0` and `p = 2` edge cases
- assuming Tonelli-Shanks gives all roots when the task only needs one
- treating discrete roots `x^k ≡ a (mod p)` as "just run Tonelli-Shanks with k instead of 2"
- forgetting that primitive-root / BSGS machinery is the doorway for the follow-up lane, not the starter lane

## Retrieval Links

- [Template Library](../../../template-library.md)
- [Build Kit](../../../docs/build-kit.md)
- [Number Theory cheatsheet](../../../notebook/number-theory-cheatsheet.md)

## Practice

- [Sqrt Mod](../../../practice/ladders/math/modular-square-root-discrete-root/sqrtmod.md)

## External Reading

- [CP-Algorithms: Discrete Root](https://cp-algorithms.com/algebra/discrete-root.html)
- [OI Wiki: Primitive Root](https://en.oi-wiki.org/math/primitive-root/)
- [Library Checker: Sqrt Mod](https://judge.yosupo.jp/problem/sqrt_mod)
