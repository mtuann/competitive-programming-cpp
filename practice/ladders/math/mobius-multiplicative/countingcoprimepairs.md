# Counting Coprime Pairs

- Title: `Counting Coprime Pairs`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/2417](https://cses.fi/problemset/task/2417)
- Secondary topics: `Mobius inversion`, `Divisor-frequency counting`, `Linear sieve`
- Difficulty: `medium`
- Subtype: `Count unordered pairs with gcd = 1 in a bounded-value array`
- Status: `solved`
- Solution file: [countingcoprimepairs.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/mobius-multiplicative/countingcoprimepairs.cpp)

## Why Practice This

This is the cleanest in-repo anchor for the first exact `Mobius And Multiplicative Counting` lane.

The statement looks like a pairwise gcd problem, but the reusable lesson is:

- stop iterating over pairs
- count how many values are divisible by each `d`
- let Mobius cancellation isolate the `gcd = 1` pairs

It is the first problem in this repo where Mobius is the real unlock, not just a curiosity.

## Recognition Cue

Reach for Mobius / divisor-side inclusion-exclusion when:

- the statement asks for coprime pairs or exact gcd structure over many values
- the values are bounded tightly enough for one multiples loop over `d <= MAX`
- explicit prime-subset inclusion-exclusion would be awkward or too indirect

The strongest smell here is:

- "count unordered pairs with gcd = 1"

That is exactly the kind of event Mobius isolates cleanly.

## Problem-Specific Transformation

Let:

$$
\text{cnt}[d] = \#\{a_i : d \mid a_i\}
$$

Then:

$$
\binom{\text{cnt}[d]}{2}
$$

is the number of unordered pairs whose gcd is divisible by `d`.

Now use the identity:

$$
[ \gcd(x, y) = 1 ] = \sum_{d \mid \gcd(x, y)} \mu(d)
$$

Summing over all unordered pairs gives:

$$
\text{answer} =
\sum_{d \ge 1} \mu(d)\binom{\text{cnt}[d]}{2}
$$

So the problem becomes:

1. build `mu` up to `MAX`
2. build `cnt[d]` by iterating over multiples
3. sum the Mobius-weighted pair counts

## Core Idea

Use divisor frequencies plus Mobius cancellation.

1. Count how many times each value appears.
2. For every divisor `d`, compute how many array values are divisible by `d`.
3. Treat `C(cnt[d], 2)` as the number of unordered pairs whose gcd is divisible by `d`.
4. Multiply by `mu[d]` and sum over all `d`.

The invariant is:

```text
the partial sum over d already adds every pair with the correct inclusion-exclusion sign
according to the divisor structure of its gcd
```

That is why pairs with gcd `> 1` cancel out and only gcd-`1` pairs survive.

## Complexity

- linear sieve for `mu`: `O(MAX)`
- counting divisible values over multiples: `O(MAX log MAX)` style
- final sum: `O(MAX)`

With `MAX <= 10^6`, this is easily fast enough.

## Pitfalls / Judge Notes

- The statement wants **unordered** pairs, so use `C(cnt[d], 2)`, not `cnt[d] * cnt[d]`.
- `mu[d] = 0` means the divisor contributes nothing.
- Do not compute gcd for each pair.
- `1` naturally works with the same formula; you do not need a special-case branch.
- Use `long long` for the answer.

## Reusable Pattern

- Topic page: [Mobius And Multiplicative Counting](../../../../topics/math/mobius-multiplicative/README.md)
- Practice ladder: [Mobius And Multiplicative Counting ladder](README.md)
- Starter template: [mobius-linear-sieve.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/mobius-linear-sieve.cpp)
- Notebook refresher: [Mobius hot sheet](../../../../notebook/mobius-hot-sheet.md)
- Compare points:
  - [Common Divisors](../gcd-lcm/commondivisors.md)
  - [Prime Multiples](../../combinatorics/inclusion-exclusion/primemultiples.md)
- This note adds: the first exact in-repo route for Mobius-weighted gcd counting over an array.

## Solutions

- Code: [countingcoprimepairs.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/mobius-multiplicative/countingcoprimepairs.cpp)
