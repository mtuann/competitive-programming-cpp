# Convolution

- Title: `Convolution`
- Judge / source: `AtCoder Library Practice Contest`
- Original URL: [https://atcoder.jp/contests/practice2/tasks/practice2_f](https://atcoder.jp/contests/practice2/tasks/practice2_f)
- Secondary topics: `NTT`, `Exact modular convolution`, `998244353`
- Difficulty: `medium`
- Subtype: `Multiply two coefficient arrays modulo 998244353`
- Status: `solved`
- Solution file: [convolution.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/fft/convolution.cpp)

## Why Practice This

This is the cleanest exact anchor for the repo's `ntt.cpp`.

There is no modeling layer to hide the transform:

- the input is already two coefficient arrays
- the output is already the convolution
- the modulus is exactly the friendly `998244353`

So this is the direct “can you deploy exact NTT cleanly?” note.

## Recognition Cue

Reach for NTT when:

- the statement already asks for polynomial convolution
- the modulus is NTT-friendly, especially `998244353`
- floating-point FFT would add unnecessary precision risk

The strongest smell is:

- "compute c_i = sum a_j b_{i-j} mod 998244353"

That is not just convolution-like. It is exactly the transform target.

## Problem-Specific Transformation

There is essentially no transformation here:

- read `a`
- read `b`
- return `convolution(a, b)` modulo `998244353`

That makes the problem ideal as a starter anchor for exact modular convolution.

## Core Idea

NTT is the modular analogue of FFT.

Instead of evaluating the polynomials at complex roots of unity, we evaluate them at powers of a primitive root inside the finite field modulo `998244353`.

The usual radix-2 pipeline is:

1. resize both arrays to one power-of-two length
2. apply forward NTT to both arrays
3. multiply pointwise
4. apply inverse NTT
5. truncate back to length `n + m - 1`

Because the modulus and primitive root are chosen to support these transform lengths, the result is exact.

## Complexity

- `O((n + m) log(n + m))`

## Pitfalls / Judge Notes

- The modulus is fixed at `998244353`; this is exactly why the repo starter fits cleanly.
- The transform length must be a power of two at least `n + m - 1`.
- Do not reuse this starter blindly under a different modulus unless the primitive-root constraints still hold.
- The output length is exactly `n + m - 1`.

## Reusable Pattern

- Topic page: [FFT And NTT](../../../../topics/math/fft-ntt/README.md)
- Practice ladder: [FFT And NTT ladder](README.md)
- Starter template: [ntt.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/ntt.cpp)
- Topic refresher: [FFT And NTT](../../../../topics/math/fft-ntt/README.md)
- Carry forward: separate “exact modular convolution” from “floating FFT with rounding”.
- This note adds: the fully direct starter deployment for the friendly modulus case.

## Solutions

- Code: [convolution.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/fft/convolution.cpp)
