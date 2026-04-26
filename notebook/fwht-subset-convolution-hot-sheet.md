# FWHT / XOR Convolution / Subset Convolution Hot Sheet

Use this page when the data already lives on the full boolean cube and the bottleneck is combining **two** mask functions, not sweeping one array over all submasks.

## Do Not Use When

- one array only needs all-submask or all-superset aggregates -> [SOS DP](sos-dp-hot-sheet.md)
- the combine rule is additive `i + j = k` -> [FFT / NTT](../topics/math/fft-ntt/README.md)
- the mask is just one evolving DP state -> [DP cheatsheet](dp-cheatsheet.md)

## Choose By Signal

- `h[k] = sum_i f[i] g[i xor k]` over the full cube -> this lane, first route is `FWHT`
- `h[S] = sum_{T subseteq S} f[T] g[S \\ T]` with exact subset splits -> same family, stretch route is `subset convolution`
- every mask just wants one aggregate over all submasks / supersets -> [SOS DP hot sheet](sos-dp-hot-sheet.md)

## Core Invariants

- xor convolution diagonalizes under the Walsh-Hadamard basis
- the xor butterfly is always `(x, y) -> (x + y, x - y)`
- inverse xor FWHT is the same butterfly plus multiply by `inv(2^bits)`
- subset convolution is **not** plain zeta-product; it needs popcount layers before zeta / inverse-zeta

## Main Traps

- forgetting the final `inv(n)` normalization after inverse xor FWHT
- using this lane for subset/superset sweeps that are really just SOS DP
- using FFT/NTT because the word `convolution` appears, even though the indexing law is xor or exact subset split
- forgetting the array length must already be exactly one full power-of-two cube

## Reopen Paths

- full lesson -> [FWHT / XOR Convolution / Subset Convolution](../topics/dp/fwht-subset-convolution/README.md)
- parent compare -> [SOS DP](../topics/dp/sos-dp/README.md)
- additive-index compare -> [FFT / NTT](../topics/math/fft-ntt/README.md)
- exact starter -> [fwht-xor-convolution.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/fwht-xor-convolution.cpp)
- flagship rep -> [Bitwise XOR Convolution](../practice/ladders/dp/fwht-subset-convolution/bitwisexorconvolution.md)
