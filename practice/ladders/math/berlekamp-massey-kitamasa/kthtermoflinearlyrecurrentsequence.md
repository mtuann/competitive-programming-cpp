# K-th Term of Linearly Recurrent Sequence

- Title: `K-th Term of Linearly Recurrent Sequence`
- Judge / source: `Library Checker`
- Original URL: [https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence](https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence)
- Secondary topics: `Kitamasa`, `Characteristic polynomial reduction`, `Modular arithmetic`
- Difficulty: `hard`
- Subtype: `Given recurrence and initial terms, compute a_k`
- Status: `solved`
- Solution file: [kthtermoflinearlyrecurrentsequence.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/berlekamp-massey-kitamasa/kthtermoflinearlyrecurrentsequence.cpp)

## Why Practice This

This is the cleanest verifier-style first anchor for the repo's `Berlekamp-Massey / Kitamasa` lane.

The mathematical route is narrow:

- one recurrence is already given
- one modulus is already fixed
- the whole task is to jump to the `k`-th term

So the lesson is not recurrence discovery first and not full generating-function algebra.

It is:

- trust the recurrence convention
- reduce powers modulo the characteristic relation
- recover `a_k` in `O(d^2 log k)` instead of building a `d x d` matrix

## Recognition Cue

Reach for Kitamasa when:

- the recurrence is already given explicitly
- the order `d` is moderate
- `k` is huge
- the matrix route is conceptually fine but cubic work in `d` feels wasteful

The strongest smell is:

```text
You are given a_0..a_{d-1}, c_0..c_{d-1}, and one huge k.
```

## Problem-Specific Transformation

Given:

$$
a_n = c_0 a_{n-1} + c_1 a_{n-2} + \dots + c_{d-1} a_{n-d},
$$

interpret the recurrence as the characteristic reduction:

$$
x^d \equiv c_0 x^{d-1} + c_1 x^{d-2} + \dots + c_{d-1}.
$$

Then compute `x^k` modulo that relation.

The reduced polynomial:

$$
x^k \equiv p_0 + p_1 x + \dots + p_{d-1} x^{d-1}
$$

immediately yields:

$$
a_k = p_0 a_0 + p_1 a_1 + \dots + p_{d-1} a_{d-1}.
$$

## Core Idea

Binary exponentiation still survives here, but not on matrices.

Instead:

- multiply two coefficient polynomials
- reduce every term of degree `>= d` with the recurrence
- keep only degree `< d`

That `combine()` step is the whole Kitamasa engine.

So the loop is:

1. start from the polynomial for `x^0`
2. repeatedly square the polynomial for `x`
3. multiply into the answer on set bits of `k`
4. reduce after every product

## Complexity

- `O(d^2 log k)`

This is the exact reason to prefer this lane over dense matrix exponentiation once `d` grows.

## Pitfalls / Judge Notes

- The coefficient order matters. The repo convention is:
  - `rec[0]` multiplies `a_{n-1}`
  - `rec[d-1]` multiplies `a_{n-d}`
- `a_0..a_{d-1}` are the base values, not `a_1..a_d`
- Reducing product terms with the recurrence in the wrong order produces answers that look plausible and are still wrong
- Berlekamp-Massey is part of the lane, but this exact problem does not need it because the recurrence is already given

## Reusable Pattern

- Topic page: [Berlekamp-Massey / Kitamasa](../../../../topics/math/berlekamp-massey-kitamasa/README.md)
- Practice ladder: [Berlekamp-Massey / Kitamasa ladder](README.md)
- Starter template: [berlekamp-massey-kitamasa.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/berlekamp-massey-kitamasa.cpp)
- Notebook refresher: [Berlekamp-Massey / Kitamasa hot sheet](../../../../notebook/berlekamp-massey-kitamasa-hot-sheet.md)
- Compare point: [Linear Recurrence hot sheet](../../../../notebook/linear-recurrence-hot-sheet.md)
- Carry forward: once the recurrence is known, jump on the characteristic polynomial instead of lifting into a dense matrix

## Solution

- Code: [kthtermoflinearlyrecurrentsequence.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/berlekamp-massey-kitamasa/kthtermoflinearlyrecurrentsequence.cpp)
