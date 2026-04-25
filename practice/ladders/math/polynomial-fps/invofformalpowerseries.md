# Inv of Formal Power Series

- Title: `Inv of Formal Power Series`
- Judge / source: `Library Checker`
- Original URL: [https://judge.yosupo.jp/problem/inv_of_formal_power_series](https://judge.yosupo.jp/problem/inv_of_formal_power_series)
- Secondary topics: `Formal power series`, `NTT`, `Newton iteration`
- Difficulty: `hard`
- Subtype: `Truncated FPS inverse modulo x^n`
- Status: `solved`
- Solution file: [invofformalpowerseries.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/polynomial-fps/invofformalpowerseries.cpp)

## Why Practice This

This is the cleanest official flagship for the repo's first formal-power-series lane.

There is no extra modeling noise:

- you are given one series `A(x)`
- you need `A(x)^{-1} mod x^n`

So the whole point is to trust the exact FPS inverse contract.

## Recognition Cue

Reach for this route when:

- the statement literally asks for inverse of a truncated series
- coefficients are already modulo an NTT-friendly prime
- one convolution helper is known-good

The strongest smell here is:

- plain polynomial multiplication is not enough anymore, but it is still the inner engine

## Problem-Specific Transformation

We want:

$$
A(x)B(x) \equiv 1 \pmod{x^n}.
$$

Only the first `n` coefficients matter.

So every time we multiply two intermediate polynomials, we only care about the prefix up to degree `n-1`.

## Newton Doubling Route

Let `B` already satisfy:

$$
A(x)B(x) \equiv 1 \pmod{x^m}.
$$

Then upgrade it by:

$$
B'(x) = B(x)\left(2 - A(x)B(x)\right) \pmod{x^{2m}}.
$$

This doubles the number of correct coefficients.

The contest loop is:

1. start from `b_0 = a_0^{-1}`
2. double the trusted prefix length
3. use NTT for the products
4. truncate every step to the new target length

## Why The Optimization Fits

This is the first FPS route because:

- inverse exists iff `a_0 != 0`
- the Newton step is compact and reusable
- later FPS operations often reduce back to this same backbone

So this note is not just one judge problem.

It is the gateway to:

- `log`
- `exp`
- `pow`
- `sqrt`

## Complexity

With NTT-backed multiplication and doubling lengths, the standard contest implementation runs in:

$$
O(n \log^2 n)
$$

which is enough for this verifier-style task.

## Main Traps

- forgetting that the inverse does not exist when `a_0 = 0`
- treating intermediate products as full polynomials instead of truncating
- debugging the Newton step before debugging convolution

## Reopen Path

- Topic page: [Polynomial / Formal Power Series](../../../../topics/math/polynomial-fps/README.md)
- Practice ladder: [Polynomial / Formal Power Series ladder](README.md)
- Starter template: [`fps-inv-newton.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/fps-inv-newton.cpp)
- Notebook refresher: [Polynomial / FPS hot sheet](../../../../notebook/polynomial-fps-hot-sheet.md)
- Compare point: [FFT And NTT](../../../../topics/math/fft-ntt/README.md)

## Solution

- Code: [invofformalpowerseries.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/polynomial-fps/invofformalpowerseries.cpp)
