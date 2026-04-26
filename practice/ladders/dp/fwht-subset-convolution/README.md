# FWHT / XOR Convolution / Subset Convolution Ladder

This lane is for when [SOS DP](../../../../topics/dp/sos-dp/README.md) already feels natural and the next step is to combine two full mask functions instead of sweeping one array.

It stays intentionally narrow:

- exact starter = xor convolution via `FWHT`
- flagship rep = one official verifier where the whole task is exactly that
- subset convolution stays as the stretch sibling after the first route is trusted

## Who This Is For

Use this lane if:

- [Bitmask DP](../../../../topics/dp/bitmask-dp/README.md) already feels ordinary
- [SOS DP](../../../../topics/dp/sos-dp/README.md) no longer feels magical
- you can already think of a mask array as a function on the full boolean cube

## Warm-Up

- say why `xor convolution` is not `subset zeta`
- say why `xor convolution` is not additive-index `FFT / NTT`
- recognize when the array size `2^bits` is the real contract, not just an implementation detail

Warm-up compare points:

- [SOS DP](../../../../topics/dp/sos-dp/README.md)
- [FFT / NTT](../../../../topics/math/fft-ntt/README.md)

## Core

- Walsh-Hadamard xor butterfly
- inverse normalization by `inv(2^bits)`
- exact flagship rep: [Bitwise XOR Convolution](bitwisexorconvolution.md)

Target skill:

- see one full-cube xor-pair-combine problem and jump straight to `FWHT`

## Stretch

- subset convolution by popcount layers plus zeta / inverse-zeta
- official stretch verifier: [Library Checker - Subset Convolution](https://judge.yosupo.jp/problem/subset_convolution)

Target skill:

- know why subset convolution still belongs to this family while requiring a stronger layered route than the xor starter

## Retrieval Layer

- exact quick sheet -> [FWHT / XOR Convolution / Subset Convolution hot sheet](../../../../notebook/fwht-subset-convolution-hot-sheet.md)
- exact starter -> [fwht-xor-convolution.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/fwht-xor-convolution.cpp)
- parent chooser -> [DP cheatsheet](../../../../notebook/dp-cheatsheet.md)
- compare point -> [SOS DP](../../../../topics/dp/sos-dp/README.md)

## External Practice

- [Library Checker - Bitwise XOR Convolution](https://judge.yosupo.jp/problem/bitwise_xor_convolution)
- [Library Checker - Subset Convolution](https://judge.yosupo.jp/problem/subset_convolution)

## Tutorial Link

- [FWHT / XOR Convolution / Subset Convolution](../../../../topics/dp/fwht-subset-convolution/README.md)
