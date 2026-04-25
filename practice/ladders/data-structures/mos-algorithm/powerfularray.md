# Powerful Array

- Title: `Powerful Array`
- Judge / source: `Codeforces`
- Original URL: [https://codeforces.com/problemset/problem/86/D](https://codeforces.com/problemset/problem/86/D)
- Secondary topics: `Mo's Algorithm`, `Frequency maintenance`, `Offline range queries`
- Difficulty: `hard`
- Subtype: `Maintain a frequency-weighted score over many static subarrays`
- Status: `solved`
- Solution file: [powerfularray.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/mos-algorithm/powerfularray.cpp)

## Why Practice This

This is one of the best first "real" Mo problems because the maintained statistic is unmistakably local:

$$
\sum_x \text{freq}[x]^2 \cdot x
$$

There is no clean monotone sweep interpretation, but adding or removing one endpoint is easy.

That makes it the right flagship contrast to:

- [Distinct Values Queries](../offline-tricks/distinctvaluesqueries.md)

where an ordinary offline sweep is cleaner.

## Recognition Cue

Reach for ordinary Mo when:

- the array is static
- all queries are known first
- the answer for one range can be updated cheaply after moving one endpoint by one
- trying to force a one-key sweep feels unnatural

For this problem, the key smell is:

- "one current range, one frequency table, one score updated by local contribution changes"

That is classic Mo territory.

## Problem-Specific Transformation

The statement asks for:

$$
f([l, r]) = \sum_x \text{freq}_{[l,r]}(x)^2 \cdot x
$$

The reusable rewrite is:

- maintain the exact current active range `[L, R]`
- keep `cnt[x] =` frequency of value `x` in that active range
- keep one current score `cur`

Then a query answer is available immediately once the active range matches `[l, r]`.

So the original problem becomes:

- reorder queries offline
- move `L` and `R` gradually
- update one frequency-weighted score locally

## Core Idea

If one value `x` currently has frequency `f`, its contribution is:

$$
f^2 \cdot x
$$

If we add one more `x`, the contribution becomes:

$$
(f+1)^2 \cdot x
$$

So `add(pos)` can do:

1. subtract old contribution `f^2 * x`
2. increment `f`
3. add new contribution `(f+1)^2 * x`

Similarly, `remove(pos)` does the exact inverse:

1. subtract `f^2 * x`
2. decrement `f`
3. add `(f-1)^2 * x`

This is why Mo works so well here:

- the answer-state is expensive to rebuild from scratch
- but each one-step boundary move is cheap

Sort queries in Mo order, maintain the active range, and write answers back by original query index.

## Complexity

- sorting queries: `O(q log q)`
- total boundary movement under ordinary Mo order: about `O((n + q) sqrt(n))`
- each move is `O(1)`
- total: `O((n + q) sqrt(n))`

## Pitfalls / Judge Notes

- Use `long long` for the score.
- The values can be large enough that `freq^2 * value` overflows `int`.
- `add` and `remove` must be exact inverses; if one update rule is off by one, answers drift silently.
- Use one stable query index because processing order is not input order.
- This is the right lane for `Mo`; unlike [Distinct Values Queries](../offline-tricks/distinctvaluesqueries.md), there is no nicer monotone sweep here.

## Reusable Pattern

- Topic page: [Mo's Algorithm](../../../../topics/data-structures/mos-algorithm/README.md)
- Practice ladder: [Mo's Algorithm ladder](README.md)
- Starter template: [mos-algorithm.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/mos-algorithm.cpp)
- Notebook refresher: [Mo's hot sheet](../../../../notebook/mos-hot-sheet.md)
- Carry forward: if the answer-state for one active range can be updated through symmetric endpoint moves, reorder the queries instead of rebuilding every range from scratch.
- This note adds: the exact contribution update for one frequency-weighted score.

## Solutions

- Code: [powerfularray.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/mos-algorithm/powerfularray.cpp)
