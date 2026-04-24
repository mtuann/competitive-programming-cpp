# Common Divisors

- Title: `Common Divisors`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1081](https://cses.fi/problemset/task/1081)
- Secondary topics: `Frequency over divisors`, `Divisibility counting`, `Greatest common divisor`
- Difficulty: `medium`
- Subtype: `Find the largest gcd achievable by some pair of array elements`
- Status: `solved`
- Solution file: [commondivisors.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/gcd-lcm/commondivisors.cpp)

## Why Practice This

This is a strong bridge problem for the `gcd/lcm` lane because it is not solved by calling `gcd` on every pair.

The useful shift is:

- stop asking which pair has the best gcd
- start asking which divisor appears in at least two numbers

That turns a pair problem into a divisor-frequency problem.

## Key Idea

Suppose some answer value is `d`.

Then there must exist at least two numbers in the array that are both divisible by `d`.

So instead of checking pairs, iterate possible gcd values from large to small and count how many array elements are multiples of each `d`.

If for some `d`:

```text
count of multiples of d >= 2
```

then there exists a pair whose gcd is at least `d`.

Because we scan downward, the first such `d` is the maximum possible answer.

Implementation shape:

1. Build a frequency array for the input values.
2. For each candidate `d` from `MAX_X` down to `1`, sum `freq[d] + freq[2d] + freq[3d] + ...`.
3. Print the first `d` whose multiple count reaches at least `2`.

## Complexity

- frequency build: `O(n)`
- divisor-multiple scan: `O(MAX_X log MAX_X)` in harmonic-sum form

This is fast enough for `MAX_X <= 10^6`.

## Pitfalls / Judge Notes

- The answer is about **some pair**, not all numbers.
- A candidate divisor only needs to divide two values, not appear as a value itself.
- Scanning from high to low lets you stop early on the first valid divisor.
- This is a gcd problem, but the clean implementation works over multiples rather than explicit gcd calls.

## Reusable Pattern

- Topic page: [GCD And LCM](../../../../topics/math/number-theory-basics/README.md)
- Practice ladder: [GCD And LCM ladder](README.md)
- Starter template: [number-theory-basics.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/number-theory-basics.cpp)
- Notebook refresher: [Number theory cheatsheet](../../../../notebook/number-theory-cheatsheet.md)
- Carry forward: when a gcd value is the target, try counting how many numbers are divisible by each candidate.
- This note adds: the downward divisor-frequency scan that replaces pairwise gcd enumeration.

## Solutions

- Code: [commondivisors.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/gcd-lcm/commondivisors.cpp)
