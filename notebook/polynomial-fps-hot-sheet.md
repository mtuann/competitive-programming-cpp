# Polynomial / FPS Hot Sheet

Use this page when the statement wants truncated formal power series algebra under one NTT-friendly prime, not just one plain convolution.

## Do Not Use When

- you only need one convolution -> reopen [FFT And NTT](../topics/math/fft-ntt/README.md)
- the modulus is not friendly for your NTT route
- the task is really recurrence / combinatorics modeling, not FPS algebra

## Exact First Route In This Repo

Invert one series:

$$
A(x)^{-1} \pmod{x^n}
$$

under `998244353`, with the contract:

- `a_0 != 0`
- every product is truncated modulo `x^n`
- multiplication is delegated to trusted NTT convolution

## Core Identity

If `B` is correct modulo `x^m`, improve it by:

```text
B <- B * (2 - A * B) mod x^(2m)
```

That is the Newton-doubling step for FPS inverse.

## Recognition Cues

- `Inv / Log / Exp / Pow / Sqrt of Formal Power Series`
- coefficients are modulo `998244353`
- one convolution helper is already trusted, but coefficient-by-coefficient algebra would be too slow

## Core Invariants

- inverse exists iff `a_0 != 0`
- all equalities are modulo `x^k`, not as full polynomials
- truncate after every doubling step
- the first reusable gateway is inverse; `log/exp/pow/sqrt` come later

## Main Traps

- forgetting truncation
- forgetting the `a_0 != 0` condition
- trying FPS before the underlying NTT is trustworthy
- overpromising from inverse to the whole FPS family without new contracts

## Exact Starter In This Repo

- starter -> [`fps-inv-newton.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/fps-inv-newton.cpp)
- flagship rep -> [Inv of Formal Power Series](../practice/ladders/math/polynomial-fps/invofformalpowerseries.md)
- compare point -> [FFT And NTT](../topics/math/fft-ntt/README.md)

## Reopen Paths

- full tutorial -> [Polynomial / Formal Power Series](../topics/math/polynomial-fps/README.md)
- parent router -> [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md)
- broader transform family -> [FFT And NTT](../topics/math/fft-ntt/README.md)
