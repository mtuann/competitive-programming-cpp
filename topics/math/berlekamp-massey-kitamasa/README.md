# Berlekamp-Massey / Kitamasa

This lane starts when ordinary [Linear Recurrence / Matrix Exponentiation](../linear-recurrence/README.md) is conceptually right, but the matrix route is no longer the cleanest tool.

The two main triggers are:

- the recurrence order `d` is large enough that dense `O(d^3 log k)` matrix powers feel wasteful
- the recurrence itself is not given directly, but a long enough prefix of terms is

The exact combined route in this repo is:

- work over one fixed prime field
- use **Kitamasa** to jump to the `k`-th term in `O(d^2 log k)` once the recurrence is known
- use **Berlekamp-Massey** to recover the shortest linear recurrence from a prefix when the coefficients are not given

This is the natural follow-up after the matrix-exponentiation lane, not a replacement for it.

## At A Glance

- **Use when:** one sequence satisfies a fixed linear recurrence under one modulus, and you need either the `k`-th term fast or the recurrence itself from a prefix
- **Core worldview:** reduce powers of `x` modulo the characteristic recurrence, so "advance the sequence by `k` steps" becomes polynomial reduction instead of matrix powering
- **Main tools:** characteristic polynomial, Kitamasa doubling/combine, Berlekamp-Massey discrepancy updates
- **Typical complexity:** `O(d^2 log k)` for `k`-th term with known recurrence, plus `O(n^2)` to recover a length-`d` recurrence from `n` prefix terms by Berlekamp-Massey
- **Main trap:** mixing the coefficient order of the recurrence with the coefficient order of the reduction polynomial

Strong contest signals:

- the statement literally gives the first `d` terms and recurrence coefficients, then asks for the `k`-th term
- the judge wants "find the shortest recurrence" from a prefix
- the recurrence order is too large for a comfortable dense matrix route
- the whole problem is one linear recurrence over a fixed prime modulus

Strong anti-cues:

- the recurrence width is tiny and the matrix route is already simple and trusted
- the transition is not linear
- the modulus is not a field you trust for Berlekamp-Massey arithmetic
- you only need a small number of next terms, not one giant jump

## Prerequisites

- [Linear Recurrence / Matrix Exponentiation](../linear-recurrence/README.md)
- [Modular Arithmetic](../modular-arithmetic/README.md)

Helpful neighboring topics:

- [Polynomial / Formal Power Series](../polynomial-fps/README.md) as a later algebraic compare point
- [FFT / NTT](../fft-ntt/README.md) only later, if you ever want faster polynomial products than the starter's quadratic combine

## Problem Model And Notation

Suppose the sequence satisfies:

$$
a_n = c_0 a_{n-1} + c_1 a_{n-2} + \dots + c_{d-1} a_{n-d}
$$

for all `n >= d`.

Define the characteristic reduction:

$$
x^d \equiv c_0 x^{d-1} + c_1 x^{d-2} + \dots + c_{d-1}
$$

modulo the recurrence relation.

This means any power `x^k` can be reduced to a polynomial of degree `< d`.

If:

$$
x^k \equiv p_0 + p_1 x + \dots + p_{d-1} x^{d-1},
$$

then:

$$
a_k = p_0 a_0 + p_1 a_1 + \dots + p_{d-1} a_{d-1}.
$$

That is the whole Kitamasa worldview.

Berlekamp-Massey solves the inverse problem:

- given enough prefix terms
- recover the shortest recurrence that explains them

## First Exact Route In This Repo

The repo starter exposes both halves because the family is naturally two-step:

- `berlekamp_massey(sequence)` -> recover the shortest recurrence over `998244353`
- `linear_recurrence_kth(initial, recurrence, k)` -> jump to term `k`

But the flagship solved note keeps the first contest contract narrow:

- recurrence coefficients are already given
- initial values are already given
- answer the `k`-th term

That first rep is:

- [K-th Term of Linearly Recurrent Sequence](../../../practice/ladders/math/berlekamp-massey-kitamasa/kthtermoflinearlyrecurrentsequence.md)

## From Matrix Powers To Characteristic Reduction

### The Matrix Route

The previous lane packages one step into:

$$
S(n+1) = T S(n)
$$

and computes:

$$
S(k) = T^k S(0).
$$

That is perfect when the recurrence width is small.

### Why Another Route Exists

If the sequence is one scalar recurrence of order `d`, then the matrix is just one encoding of the same algebra.

The other encoding is:

- keep only the coefficients needed to express `x^k` modulo the recurrence
- multiply and reduce those coefficient polynomials directly

This avoids dense matrix multiplication and gives:

$$
O(d^2 \log k)
$$

instead of:

$$
O(d^3 \log k).
$$

### Why Berlekamp-Massey Fits Naturally

Once the sequence is understood through a recurrence relation instead of a matrix, the next obvious question is:

- what if the recurrence is not given?

Berlekamp-Massey answers exactly that.

It scans the prefix, tracks the current best recurrence, and updates it whenever a new term creates a nonzero discrepancy.

So the combined lane is:

1. recover recurrence if needed
2. jump to a huge index using that recurrence

## Core Invariants And Why It Works

### 1. Kitamasa Works In The Quotient Ring

You are no longer multiplying matrices.

You are multiplying polynomials modulo the characteristic relation.

The invariant is:

- every polynomial is reduced to degree `< d`
- its coefficients mean "how to combine `a_0..a_{d-1}`"

### 2. Coefficient Order Matters

For the recurrence

$$
a_n = c_0 a_{n-1} + \dots + c_{d-1} a_{n-d},
$$

the reduction of `x^d` is:

$$
x^d \equiv c_0 x^{d-1} + \dots + c_{d-1}.
$$

This reversal of exponent positions is the exact place many implementations drift.

### 3. Berlekamp-Massey Tracks Discrepancy

At each new term, evaluate the current recurrence.

- if the discrepancy is `0`, the current recurrence still explains the prefix
- otherwise, patch it using the last best recurrence that had smaller length

That one discrepancy invariant is the heart of the algorithm.

### 4. The Repo Starter Is A Fixed-Prime Field Route

The starter uses `998244353`.

That means:

- division is field inversion
- Berlekamp-Massey arithmetic is straightforward
- the flagship Library Checker tasks fit the contract directly

## Recognition Cues

Reach for this lane when:

- one huge `k` asks for the `k`-th term of a linear recurrence
- the recurrence order is moderate, but not tiny enough to love dense matrices
- the judge gives many initial terms and hints that you should infer the shortest recurrence
- you see "linearly recurrent sequence" explicitly in the statement

## Common Pitfalls

- using matrix exponentiation when the order is large enough that cubic work is the real bottleneck
- mixing zero-indexed initial terms with one-indexed paper notation
- reducing polynomial products with the recurrence coefficients in the wrong order
- calling Berlekamp-Massey on data that does not live in a field you handle correctly

## Stretch Routes After The First Lane

After the first flagship rep, the natural next openings are:

- **Find Linear Recurrence**
  - same field, same Berlekamp-Massey route, but recurrence recovery is the whole task
- **faster polynomial reduction**
  - only if one day the repo wants subquadratic recurrence jumping
- **deeper algebraic bridges**
  - relation to generating functions and polynomial/FPS viewpoints

## Solved Example In This Repo

- [K-th Term of Linearly Recurrent Sequence](../../../practice/ladders/math/berlekamp-massey-kitamasa/kthtermoflinearlyrecurrentsequence.md): known recurrence + Kitamasa jump, with Berlekamp-Massey exposed in the starter as the natural sibling helper

## Related Topics

- [Linear Recurrence / Matrix Exponentiation](../linear-recurrence/README.md)
- [Polynomial / Formal Power Series](../polynomial-fps/README.md)
- [Modular Arithmetic](../modular-arithmetic/README.md)

## Go Deeper

- Reference: [Competitive Programmer's Handbook](https://www.cses.fi/book/book.pdf)
- Reference: [Guide to Competitive Programming](https://link.springer.com/book/10.1007/978-3-031-61794-2)
- Practice: [Library Checker - K-th Term of Linearly Recurrent Sequence](https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence)
- Practice: [Library Checker - Find Linear Recurrence](https://judge.yosupo.jp/problem/find_linear_recurrence)
