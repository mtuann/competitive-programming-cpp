# Distributing Apples

- Title: `Distributing Apples`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1716](https://cses.fi/problemset/task/1716)
- Secondary topics: `Stars and bars`, `Binomial coefficients`, `Modular arithmetic`
- Difficulty: `medium`
- Subtype: `Count nonnegative solutions to x1 + x2 + ... + xn = m modulo 1e9+7`
- Status: `solved`
- Solution file: [distributingapples.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/combinatorics/counting-basics/distributingapples.cpp)

## Why Practice This

This is the canonical first stars-and-bars problem in contest form:

- the combinatorial model is clean
- the final formula is short
- the implementation still teaches one useful contest habit: compute one binomial coefficient modulo a prime efficiently

It is a strong first anchor for counting basics because the whole solution depends on describing the counted object correctly.

## Key Idea

We want the number of nonnegative integer solutions to:

```text
x1 + x2 + ... + xn = m
```

where `xi` is the number of apples given to child `i`.

By stars and bars:

- use `m` stars for apples
- use `n - 1` bars to separate the stars into `n` groups

So we place `n - 1` bars among `m + n - 1` total positions, which gives:

```text
C(m + n - 1, n - 1)
```

Since the answer is modulo `1e9+7`, we precompute factorials and inverse factorials up to `m + n - 1`.

## Complexity

- factorial precomputation: `O(n + m)`
- one binomial query: `O(1)`
- total: `O(n + m)`

## Pitfalls / Judge Notes

- This is **nonnegative** distribution, so plain stars and bars applies directly. If each child needed at least one apple, the formula would shift first.
- The modulus is prime, so Fermat inversion is valid.
- Precompute up to `m + n - 1`, not just `max(n, m)`.
- This is a counting-model problem first and a modular-arithmetic problem second. If the formula is wrong, perfect code still loses.

## Reusable Pattern

- Topic page: [Counting Basics](../../../../topics/combinatorics/counting-basics/README.md)
- Practice ladder: [Counting Basics ladder](README.md)
- Starter template: [factorial-binomial-mod.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/factorial-binomial-mod.cpp)
- Notebook refresher: [Number theory cheatsheet](../../../../notebook/number-theory-cheatsheet.md)
- Carry forward: when you count nonnegative distributions into ordered bins, think “stars and bars” before trying DP.
- This note adds: the exact shift and precompute range for one contest-style modular answer.

## Solutions

- Code: [distributingapples.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/combinatorics/counting-basics/distributingapples.cpp)
