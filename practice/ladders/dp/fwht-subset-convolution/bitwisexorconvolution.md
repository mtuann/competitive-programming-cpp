# Bitwise XOR Convolution

- Title: `Bitwise XOR Convolution`
- Judge / source: `Library Checker`
- Original URL: [https://judge.yosupo.jp/problem/bitwise_xor_convolution](https://judge.yosupo.jp/problem/bitwise_xor_convolution)
- Secondary topics: `FWHT`, `Walsh-Hadamard`, `Boolean-cube transforms`
- Difficulty: `hard`
- Subtype: `Full-cube xor convolution under one prime modulus`
- Status: `solved`
- Solution file: [bitwisexorconvolution.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/fwht-subset-convolution/bitwisexorconvolution.cpp)

Track:

- [FWHT / XOR Convolution / Subset Convolution](../../../../topics/dp/fwht-subset-convolution/README.md)

Exact route:

- xor `FWHT`

This is the cleanest first verifier for the family because the whole task is exactly:

$$
h[k] = \sum_i f[i] g[i \oplus k]
$$

on one full boolean cube of size `2^N`.

## Why This Problem Fits The Lane

This is not:

- one-array subset aggregation -> [SOS DP](../../../../topics/dp/sos-dp/README.md)
- additive convolution on indices -> [FFT / NTT](../../../../topics/math/fft-ntt/README.md)

It is specifically:

- pair-combine two mask functions
- with `xor` as the index law

That is the exact first route for this lane.

## Implementation Contract

- the input arrays already have length `2^N`
- the modulus is `998244353`
- the xor transform uses the butterfly `(x + y, x - y)`
- the inverse is the same loops plus multiplying every entry by `inv(2^N)`

## Main Traps

- forgetting the final normalization after the inverse transform
- trying to reuse FFT intuition just because the word `convolution` appears
- confusing xor convolution with OR / AND transforms or subset convolution

## Repo Links

- topic page: [FWHT / XOR Convolution / Subset Convolution](../../../../topics/dp/fwht-subset-convolution/README.md)
- practice ladder: [FWHT / XOR Convolution / Subset Convolution ladder](README.md)
- starter template: [fwht-xor-convolution.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/fwht-xor-convolution.cpp)
- notebook refresher: [FWHT / XOR Convolution / Subset Convolution hot sheet](../../../../notebook/fwht-subset-convolution-hot-sheet.md)
