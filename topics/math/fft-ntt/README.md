# FFT And NTT

FFT and NTT are convolution tools. Use them when the real problem is "combine two frequency distributions" rather than "loop over all pairs."

## Prerequisites

- [Modular Arithmetic](../modular-arithmetic/README.md)
- [Number Theory Basics](../number-theory-basics/README.md)

## When To Suspect It

- you need all pair sums, differences, or matches between two sets
- a naive double loop is too slow
- the problem can be rewritten as polynomial multiplication or convolution
- the objects can be bucketed by value into frequencies

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

The important modeling step is usually the hard part:

- values become indices
- frequencies become coefficients
- pair combinations become convolution

## Theory / Proof Sketch

Polynomial multiplication and convolution are the same operation under different notation.

FFT evaluates the polynomials at many points, multiplies pointwise, then interpolates.

That converts one hard `O(n^2)` combinational loop into:

```text
transform -> pointwise multiply -> inverse transform
```

NTT does the same thing in a finite field, which removes floating-point precision issues when the modulus is compatible.

## Complexity And Tradeoffs

- naive convolution: `O(n^2)`
- FFT / NTT: `O(n log n)`

Tradeoffs:

- FFT is more flexible but needs care with floating-point rounding
- NTT is exact but only works with suitable moduli
- convolution only helps if the problem truly can be rewritten as coefficient multiplication

## Canonical Pattern

Template in this repo:

- [fft.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/fft.cpp)

Standard workflow:

1. choose a frequency representation
2. shift indices if negative values are possible
3. size arrays large enough for the resulting degree
4. convolve
5. interpret coefficients back in problem language

## Worked Examples

Example 1: count pair sums

If `A[x]` and `B[y]` are frequencies, then after convolution `C[s]` gives the number of ways to make sum `s`.

Example 2: frequency convolution after coordinate shifting

If values can be negative, add a fixed offset before storing them as indices.

Example 3: [POST2](../../../practice/ladders/math/fft/post2.md)

`POST2` is a good reminder that the real skill is spotting convolution structure in a counting problem.

## Recognition Cues

- "count all pairs/triples with sum/difference/property"
- the naive solution is "for every x, for every y"
- the objects can be bucketed by value into frequencies
- the answer needs all sums at once, not one query value
- you are multiplying generating functions in disguise

## Common Mistakes

- forgetting to shift negative values
- rounding FFT results carelessly
- using FFT when a smaller direct solution is already fast enough
- choosing array bounds too small for the resulting polynomial degree
- forgetting that self-pairs or unordered pairs may need post-processing
- applying convolution to a problem whose constraint is not actually additive

## Standard Variants

- ordinary pair-sum convolution
- reversed-array convolution for difference counting
- repeated squaring or multiple convolutions
- FFT with doubles
- NTT with exact modular arithmetic

## Practice Ladder

- [FFT ladder](../../../practice/ladders/math/fft/README.md)

## Go Deeper

- Course notes: [Stanford CS168 notes on FFT](https://web.stanford.edu/class/archive/cs/cs168/cs168.1252/)
- Reference: [CP-Algorithms - FFT](https://cp-algorithms.com/algebra/fft.html)
- Reference: [CP-Algorithms - NTT](https://cp-algorithms.com/algebra/fft.html#number-theoretic-transform)
- Blog/reference: [KACTL FFT notes](https://github.com/kth-competitive-programming/kactl)
- Practice: [POST2 note](../../../practice/ladders/math/fft/post2.md)

## Related Topics

- [Modular Arithmetic](../modular-arithmetic/README.md)
- [Combinatorics](../../combinatorics/README.md)
