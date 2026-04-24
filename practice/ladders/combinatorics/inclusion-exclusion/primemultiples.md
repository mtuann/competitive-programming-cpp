# Prime Multiples

- Title: `Prime Multiples`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/2185](https://cses.fi/problemset/task/2185)
- Secondary topics: `Subset enumeration`, `LCM reasoning`, `Overflow guards`
- Difficulty: `medium`
- Subtype: `Count integers in [1, n] divisible by at least one prime from a small set`
- Status: `solved`
- Solution file: [primemultiples.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/combinatorics/inclusion-exclusion/primemultiples.cpp)

## Why Practice This

This is the textbook inclusion-exclusion problem for contests:

- the bad/good sets are obvious
- the subset count is small enough to enumerate
- the only serious trap is computing subset products safely when `n` can reach `1e18`

It is the right first anchor for this topic because the alternating-sign logic is completely exposed.

## Recognition Cue

Reach for inclusion-exclusion when:

- the question is "divisible by at least one of these small-set properties"
- each subset intersection is easy to count
- the number of properties is small enough to enumerate subsets

The strongest smell is:

- "count integers in `[1, n]` divisible by at least one value from a small list"

That is nearly the canonical `PIE + subset lcm/product` pattern.

## Problem-Specific Transformation

The statement can be rewritten as a union of divisibility sets:

- one set per prime divisor

Then the problem becomes:

- count one subset intersection at a time
- alternate signs by subset parity

Because the inputs are distinct primes, every subset lcm is just the product, so the only real implementation detail left is overflow-safe multiplication.

## Core Idea

For each prime `a[i]`, define the set:

```text
Si = { x in [1, n] : a[i] divides x }
```

We want:

```text
|S1 union S2 union ... union Sk|
```

By inclusion-exclusion:

- add `floor(n / product)` for odd-sized subsets
- subtract it for even-sized subsets

Because the numbers are prime and distinct, the lcm of a subset is just the product of its primes.

So the algorithm is:

1. Enumerate every non-empty subset of the `k` primes.
2. Multiply the chosen primes to get the subset lcm/product.
3. If the product already exceeds `n`, that subset contributes `0`.
4. Otherwise add or subtract `n / product` depending on subset parity.

The implementation detail that matters most is overflow-safe multiplication:

```text
if product > n / next_prime, stop and mark this subset as too large
```

## Complexity

- subset enumeration: `O(k * 2^k)`
- with `k <= 20`, this is easily fast enough

## Pitfalls / Judge Notes

- The formula here counts numbers divisible by **at least one** prime, not by exactly one.
- Stop multiplying as soon as the running product would exceed `n`; otherwise 64-bit overflow can silently corrupt the count.
- Because the inputs are distinct primes, lcm simplifies to product. That simplification would not be valid for arbitrary integers.
- Be explicit about what the accumulator means so the alternating signs do not drift.

## Reusable Pattern

- Topic page: [Inclusion-Exclusion](../../../../topics/combinatorics/inclusion-exclusion/README.md)
- Practice ladder: [Inclusion-Exclusion ladder](README.md)
- Starter template: [number-theory-basics.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/number-theory-basics.cpp)
- Notebook refresher: [Number theory cheatsheet](../../../../notebook/number-theory-cheatsheet.md)
- Carry forward: when the number of bad properties is small and each intersection is easy, think subsets plus alternating signs.
- This note adds: the overflow-safe product guard needed when subset lcms live near `1e18`.

## Solutions

- Code: [primemultiples.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/combinatorics/inclusion-exclusion/primemultiples.cpp)
