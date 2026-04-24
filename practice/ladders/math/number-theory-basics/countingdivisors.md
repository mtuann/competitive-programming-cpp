# Counting Divisors

- Title: `Counting Divisors`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1713](https://cses.fi/problemset/task/1713)
- Secondary topics: `Divisor counting`, `Sieve preprocessing`, `Prime exponents`
- Difficulty: `easy`
- Subtype: `Report the number of divisors for many integers up to 1e6`
- Status: `solved`
- Solution file: [countingdivisors.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/number-theory-basics/countingdivisors.cpp)

## Why Practice This

This is a very good first number-theory implementation problem because it teaches a reusable sieve mindset without requiring deep theory.

You only need one fact:

```text
if x = p1^e1 * p2^e2 * ... * pk^ek
then d(x) = (e1 + 1)(e2 + 1)...(ek + 1)
```

The rest is deciding how to answer many queries efficiently.

## Recognition Cue

Reach for a divisor sieve when:

- many independent queries ask about one arithmetic function on bounded values
- the function can be described by "every divisor contributes to its multiples"
- per-query factorization would repeat the same work too often

The strongest smell is:

- "up to `10^5` queries, each value up to `10^6`"

That usually means one precompute pass is cheaper than repeated number-theory work.

## Problem-Specific Transformation

The statement is about the divisor count of one queried number at a time. The reusable rewrite is:

- precompute divisor counts for every value up to the maximum

Then the problem is no longer many small number-theory tasks. It becomes:

- one sieve-like pass over divisors
- then pure table lookup

## Core Idea

Because every query value satisfies `x <= 10^6`, precompute the divisor count for every value once.

The sieve view is:

- every integer `d` contributes `1` to all multiples of `d`

So:

1. Create an array `divisor_count`.
2. For every `d` from `1` to `MAX_X`, add `1` to `divisor_count[multiple]` for each multiple of `d`.
3. Answer each query in `O(1)` by printing the precomputed value.

This is simpler than factoring each query separately, and the total work is only:

```text
MAX_X/1 + MAX_X/2 + ... + MAX_X/MAX_X
```

which is fast enough for `MAX_X = 10^6`.

## Complexity

- preprocessing: `O(MAX_X log MAX_X)`
- each query: `O(1)`
- total: `O(MAX_X log MAX_X + n)`

## Pitfalls / Judge Notes

- This task is about many queries, so a one-number trial division loop repeated `10^5` times is not the nicest fit here.
- `1` has exactly one divisor.
- The divisor-count sieve is often easier to trust than writing repeated prime-factorization code under time pressure.

## Reusable Pattern

- Topic page: [Number Theory Basics](../../../../topics/math/number-theory-basics/README.md)
- Practice ladder: [Number Theory Basics ladder](README.md)
- Starter template: [number-theory-basics.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/number-theory-basics.cpp)
- Notebook refresher: [Number theory cheatsheet](../../../../notebook/number-theory-cheatsheet.md)
- Carry forward: when values are bounded and queries are many, a small divisor sieve is often cleaner than per-query factorization.
- This note adds: the exact divisor-count precompute shape for `x <= 10^6`.

## Solutions

- Code: [countingdivisors.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/number-theory-basics/countingdivisors.cpp)
