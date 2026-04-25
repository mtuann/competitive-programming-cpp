# POST2

- Title: `A cộng B version 2`
- Judge / source: `VN SPOJ / VNOI`
- Original URL: [https://vn.spoj.com/problems/POST2/](https://vn.spoj.com/problems/POST2/)
- Mirror URL: [https://oj.vnoi.info/problem/post2](https://oj.vnoi.info/problem/post2)
- Secondary topics: `Polynomial convolution`, `Frequency counting`
- Difficulty: `medium`
- Subtype: `Count triples with A_i + B_j = C_k`
- Status: `solved`
- Solution file: [post2.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/fft/post2.cpp)

## Why Practice This

This is a classic frequency-convolution problem: the combinatorics is simple, but the direct `O(N^2)` pair counting is impossible for `N = 10^5`.

## Recognition Cue

Reach for convolution when:

- two arrays contribute one term each to a sum or difference condition
- you need counts for all possible sums at once
- the value range is moderate even if the index range is huge

The strongest smell is:

- "count pairs `(a, b)` such that `a + b = c` for many possible `c`"

That usually means frequency arrays plus polynomial convolution.

## Problem-Specific Transformation

The triple-counting statement is rewritten as:

- frequency array for `A`
- frequency array for `B`
- convolution = number of ordered pairs achieving each sum

Then `C` is no longer part of the convolution itself. It is just one final weighting layer:

- sum `pairs[c] * cntC[c]`

So the global triple count becomes:

- one convolution
- one final frequency lookup sweep

## Core Idea

Let:

- `cntA[x]` = how many times value `x` appears in `A`
- `cntB[x]` = how many times value `x` appears in `B`

Then the number of ordered pairs `(A_i, B_j)` with sum `s` is:

`pairs[s] = sum cntA[x] * cntB[s - x]`

That is exactly the convolution of the two frequency arrays.

Because values are in `[-50000, 50000]`, we shift them by `50000`, run FFT once, and obtain every possible sum count in one shot.

Finally:

`answer = sum pairs[c] * cntC[c]`

for all values `c`.

## Complexity

- frequency building: `O(N)`
- FFT convolution: `O(M log M)` with `M ≈ 2^18`

This easily fits the limits.

## Pitfalls / Judge Notes

- The answer can be as large as `N^3`, so use `long long`.
- Duplicates matter: if `C` contains the same value many times, multiply by its frequency.
- Values are negative, so shift them before indexing.
- The problem counts ordered index triples `(i, j, k)`, not distinct values.

## Reusable Pattern

- Topic page: [FFT And NTT](../../../../topics/math/fft-ntt/README.md)
- Practice ladder: [FFT And NTT ladder](README.md)
- Starter template: [fft.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/fft.cpp)
- Topic refresher: [FFT And NTT](../../../../topics/math/fft-ntt/README.md)
- Carry forward: separate the algebraic transform from the problem-specific coefficient interpretation.
- This note adds: the frequency-array encoding and final weighted accumulation layered on top of convolution.

## Solutions

- Code: [post2.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/fft/post2.cpp)
