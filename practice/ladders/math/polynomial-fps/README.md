# Polynomial / Formal Power Series Ladder

This ladder is for the narrow contest route where:

- coefficients live modulo one NTT-friendly prime
- the statement wants truncated FPS algebra
- and plain convolution is only the starting layer

## Who This Is For

Use this lane if:

- [FFT And NTT](../../../../topics/math/fft-ntt/README.md) already feels stable
- you can trust one exact NTT convolution
- you now need inverse / log / exp / pow style series operations

## Warm-Up

- plain exact convolution -> [Convolution](../fft/convolution.md)

Target skill:

- trust the multiplication layer before trying Newton-style FPS algebra

## Core

- exact starter -> [`fps-inv-newton.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/fps-inv-newton.cpp)
- exact flagship -> [Inv of Formal Power Series](invofformalpowerseries.md)

Target skill:

- work modulo `x^n`
- spot the condition `a_0 != 0`
- use Newton doubling with NTT-backed multiplication

## Stretch

- logarithm follow-up -> [Library Checker - Log of Formal Power Series](https://judge.yosupo.jp/problem/log_of_formal_power_series)
- exponential follow-up -> [Library Checker - Exp of Formal Power Series](https://judge.yosupo.jp/problem/exp_of_formal_power_series)
- power follow-up -> [Library Checker - Pow of Formal Power Series](https://judge.yosupo.jp/problem/pow_of_formal_power_series)
- square-root follow-up -> [Library Checker - Sqrt of Formal Power Series](https://judge.yosupo.jp/problem/sqrt_of_formal_power_series)

Target skill:

- distinguish "same FPS family" from "same exact starter contract"

## Retrieval Layer

- quick sheet -> [Polynomial / FPS hot sheet](../../../../notebook/polynomial-fps-hot-sheet.md)
- exact starter -> [`fps-inv-newton.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/fps-inv-newton.cpp)
- parent routers -> [Modular Arithmetic hot sheet](../../../../notebook/modular-arithmetic-hot-sheet.md), [Math ladders](../README.md)

## Repo Anchors And Compare Points

- topic page -> [Polynomial / Formal Power Series](../../../../topics/math/polynomial-fps/README.md)
- compare point -> [FFT And NTT](../../../../topics/math/fft-ntt/README.md)
- flagship rep -> [Inv of Formal Power Series](invofformalpowerseries.md)

The cleanest in-repo loop here is:

1. trust the convolution layer in [FFT And NTT](../../../../topics/math/fft-ntt/README.md)
2. learn the inverse contract from [Polynomial / Formal Power Series](../../../../topics/math/polynomial-fps/README.md)
3. verify the route on [Inv of Formal Power Series](invofformalpowerseries.md)

## Exit Criteria

You are ready to move on when:

- you can say why `a_0 != 0` is necessary
- you know the Newton step `B <- B(2 - AB)`
- you remember to truncate every intermediate product
- you can explain why this lane is more than one plain convolution

## External Practice

- [Library Checker - Inv of Formal Power Series](https://judge.yosupo.jp/problem/inv_of_formal_power_series)
- [Library Checker - Log of Formal Power Series](https://judge.yosupo.jp/problem/log_of_formal_power_series)
- [Library Checker - Exp of Formal Power Series](https://judge.yosupo.jp/problem/exp_of_formal_power_series)
- [Library Checker - Pow of Formal Power Series](https://judge.yosupo.jp/problem/pow_of_formal_power_series)

## Tutorial Link

- [Polynomial / Formal Power Series](../../../../topics/math/polynomial-fps/README.md)
