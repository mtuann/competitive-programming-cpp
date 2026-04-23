# FFT And NTT

FFT and NTT are convolution tools. Use them when the real problem is “combine two frequency distributions” rather than “loop over all pairs.”

## Prerequisites

- [Modular Arithmetic](../modular-arithmetic/README.md)
- [Number Theory Basics](../number-theory-basics/README.md)

## When To Suspect It

- you need all pair sums, differences, or matches between two sets
- a naive double loop is too slow
- the problem can be rewritten as polynomial multiplication or convolution

## Core Idea

If:

```text
A[x] = how many times value x appears
B[y] = how many times value y appears
```

then the convolution:

```text
C[s] = sum over all x of A[x] * B[s - x]
```

counts how many ordered pairs produce sum `s`.

FFT computes this quickly with complex numbers.
NTT does the same in modular arithmetic with a suitable prime modulus.

## Theory / Proof Sketch

Polynomial multiplication and convolution are the same operation under different notation.

FFT evaluates the polynomials at many points, multiplies pointwise, then interpolates.

## Complexity And Tradeoffs

- naive convolution: `O(n^2)`
- FFT / NTT: `O(n log n)`

Tradeoffs:

- FFT is more flexible but needs care with floating-point rounding
- NTT is exact but only works with suitable moduli

## Canonical Pattern

Template in this repo:

- [fft.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/fft.cpp)

## Worked Examples

Example 1: count pair sums

Example 2: frequency convolution after coordinate shifting

Example 3: [POST2](../../../practice/ladders/math/fft/post2.md)

## Common Mistakes

- forgetting to shift negative values
- rounding FFT results carelessly
- using FFT when a smaller direct solution is already fast enough

## Practice Ladder

- [FFT ladder](../../../practice/ladders/math/fft/README.md)

## Go Deeper

- Reference: [CP-Algorithms - FFT](https://cp-algorithms.com/algebra/fft.html)
- Practice: [POST2 note](../../../practice/ladders/math/fft/post2.md)

## Related Topics

- [Modular Arithmetic](../modular-arithmetic/README.md)
- [Combinatorics](../../combinatorics/README.md)
