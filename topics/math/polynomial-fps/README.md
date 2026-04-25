# Polynomial / Formal Power Series

This lane is about one narrow contest route:

- coefficients live under one NTT-friendly prime modulus
- only the first `n` coefficients matter
- and you need algebra on truncated series, not just one plain convolution

The exact first route in this repo is:

- invert one formal power series `A(x)` modulo `x^n`
- under `998244353`
- with Newton doubling and NTT-backed multiplication

This page is not trying to teach all symbolic polynomial algebra at once.

It is teaching the first reusable FPS doorway that later supports:

- `log`
- `exp`
- `pow`
- `sqrt`

## At A Glance

- **Use when:** the statement literally asks for inverse / log / exp / pow / sqrt of a truncated formal power series, or the intended solution clearly becomes FPS algebra after one convolution layer
- **Core worldview:** work modulo `x^n`, so only the first `n` coefficients matter; upgrade one correct prefix of the answer to a longer correct prefix by Newton iteration
- **Main tools:** NTT convolution, truncation modulo `x^n`, nonzero constant term, Newton doubling
- **Typical complexity:** `O(n log^2 n)` for the inverse route with repeated NTT products
- **Main trap:** treating FPS algebra like ordinary full polynomials and forgetting truncation after every doubling step

Strong contest signals:

- the statement is literally `Inv / Log / Exp / Pow / Sqrt of Formal Power Series`
- coefficients are modulo `998244353` or another NTT-friendly prime
- one direct coefficient-by-coefficient DP feels too slow, but convolution-backed Newton steps fit

Strong anti-cues:

- you only need one convolution -> [FFT And NTT](../fft-ntt/README.md)
- the modulus is not friendly for your NTT route
- the task is really recurrence or combinatorics, not FPS algebra

## Prerequisites

- [Modular Arithmetic](../modular-arithmetic/README.md)
- [FFT And NTT](../fft-ntt/README.md)

Helpful neighboring topics:

- [Linear Recurrence / Matrix Exponentiation](../linear-recurrence/README.md) for "coefficient objects under one modulus" instinct
- [FFT And NTT](../fft-ntt/README.md) when the convolution layer itself still feels less trustworthy than the Newton-doubling wrapper built on top of it

## Problem Model And Notation

Write

$$
A(x) = a_0 + a_1 x + a_2 x^2 + \cdots
$$

and suppose we only care modulo `x^n`.

That means:

- coefficients of degree `>= n` are irrelevant
- every product is truncated to the first `n` terms

So when we say

$$
B(x) = A(x)^{-1} \pmod{x^n},
$$

we mean:

$$
A(x)B(x) \equiv 1 \pmod{x^n}.
$$

The inverse exists exactly when:

$$
a_0 \ne 0.
$$

That one condition is the entry ticket for the whole first route.

## Why Newton Doubling Works

Suppose `B(x)` is already correct modulo `x^m`:

$$
A(x)B(x) \equiv 1 \pmod{x^m}.
$$

Then define:

$$
B'(x) = B(x)\left(2 - A(x)B(x)\right).
$$

This is the Newton step for multiplicative inverse, and it doubles the number of correct coefficients:

$$
A(x)B'(x) \equiv 1 \pmod{x^{2m}}.
$$

So the contest loop is:

1. start with the degree-1 inverse `b_0 = a_0^{-1}`
2. repeatedly double the trusted prefix length
3. truncate every intermediate product to the new target length

That is the whole starter route.

## Worked Example: Inv Of Formal Power Series

In [Inv of Formal Power Series](../../../practice/ladders/math/polynomial-fps/invofformalpowerseries.md), the statement gives:

- `n`
- coefficients `a_0, ..., a_{n-1}`

and asks for:

$$
B(x) = A(x)^{-1} \pmod{x^n}.
$$

This is the cleanest official first rep because:

- the series inverse is the whole task
- the modulus is already the standard NTT prime
- there is no extra modeling noise hiding the FPS layer

## Variant Chooser

### Use Plain FFT / NTT When

- the task is only one convolution or polynomial product
- no inverse / log / exp / sqrt / power is required

### Use FPS Inverse When

- you need `A(x)^{-1} mod x^n`
- `a_0 != 0`
- and repeated truncated products are affordable

### Use Wider FPS Algebra Later When

- the inverse route already feels natural
- and the task wants:
  - `log F = integral(F' / F)`
  - `exp F`
  - `pow F`
  - `sqrt F`

This repo's first starter intentionally stops before those larger routes.

## Implementation Notes

- keep one NTT-backed convolution helper trusted first
- represent the answer prefix as a vector of length `m`
- on each doubling step, truncate to `min(2m, n)`
- never forget that all equalities are modulo `x^k`, not as full infinite series

The exact in-repo starter keeps the route narrow:

- `998244353`
- one FPS inverse
- one Newton doubling loop

## Complexity

If convolution is `O(t log t)`, then Newton doubling gives:

$$
O(n \log^2 n)
$$

for the inverse route in contest-ready form.

That is the right mental model for the first lane.

## Main Traps

- trying FPS before ordinary convolution is trustworthy
- forgetting the condition `a_0 != 0`
- forgetting truncation after each doubling step
- assuming the same starter works unchanged for an arbitrary modulus
- overgeneralizing from inverse to `log/exp/pow` without new contracts

## Recommended Practice Flow

1. reopen [FFT And NTT](../fft-ntt/README.md) if convolution trust is still low
2. learn the inverse contract on this page
3. implement or reuse the starter
4. verify it on [Inv of Formal Power Series](../../../practice/ladders/math/polynomial-fps/invofformalpowerseries.md)
5. only then reach for `log/exp/pow/sqrt`

## Reopen Paths

- Quick refresher -> [Polynomial / FPS hot sheet](../../../notebook/polynomial-fps-hot-sheet.md)
- Exact starter -> [`fps-inv-newton.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/fps-inv-newton.cpp)
- Practice ladder -> [Polynomial / Formal Power Series ladder](../../../practice/ladders/math/polynomial-fps/README.md)
- Compare point -> [FFT And NTT](../fft-ntt/README.md)

## Sources

- Official docs: [AtCoder Library Convolution](https://atcoder.github.io/ac-library/production/document_en/convolution.html)
- Official benchmark: [Library Checker - Inv of Formal Power Series](https://judge.yosupo.jp/problem/inv_of_formal_power_series)
- Official follow-ups: [Library Checker - Log of Formal Power Series](https://judge.yosupo.jp/problem/log_of_formal_power_series), [Library Checker - Exp of Formal Power Series](https://judge.yosupo.jp/problem/exp_of_formal_power_series)
