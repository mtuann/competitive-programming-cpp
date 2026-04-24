# FFT Ladder

## Who This Is For

Use this ladder when you already know arrays and counting, and you want to learn when a scary pair-counting problem is secretly just convolution.

## Warm-Up

- understand convolution as pair counting
- frequency arrays with coordinate shifting

## Core

- implement iterative FFT
- convert pair-sum or pair-difference counting into convolution

## Stretch

- precision pitfalls
- [POST2](post2.md)

## Build Path

- floating FFT starter -> [fft.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/fft.cpp)
- exact modular convolution -> [ntt.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/ntt.cpp)

## Reopen Theory Pages

- quick theory refresher -> [FFT / NTT](../../../../topics/math/fft-ntt/README.md)
- counting precheck -> [Counting Basics](../../../../topics/combinatorics/counting-basics/README.md)

## Repo Anchors And Compare Points

- direct repo note -> [POST2](post2.md)
- compare floating vs exact viewpoints -> [FFT / NTT](../../../../topics/math/fft-ntt/README.md)
- reopen the counting lens before the transform lens -> [Counting Basics](../../../../topics/combinatorics/counting-basics/README.md)
- if coefficient shifts or mod arithmetic are the real bottleneck -> [Modular Arithmetic ladder](../modular-arithmetic/README.md)

This ladder is still thin on direct internal notes. In the current repo, the floating-FFT branch is note-backed through [POST2](post2.md), while the exact NTT branch is still mainly topic/template-backed.

The intended loop is:

1. first reduce the statement to a clean convolution story
2. compare that reduction against [POST2](post2.md)
3. only then decide whether [fft.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/fft.cpp) or [ntt.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/ntt.cpp) is the better build path

## Exit Criteria

You are ready to move on when you can:

- rewrite a pair problem as coefficient multiplication
- choose sensible array bounds and shifts
- explain why FFT changes `O(n^2)` pair work into `O(n log n)`
- tell when FFT is unnecessary because the direct solution is already small enough

## External Practice

- [CP-Algorithms - FFT](https://cp-algorithms.com/algebra/fft.html)
- [KACTL](https://github.com/kth-competitive-programming/kactl)

## Tutorial Link

- [FFT And NTT](../../../../topics/math/fft-ntt/README.md)
