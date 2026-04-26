# Bit-Parallelism / Bitset Optimization

This family begins when a DP or reachability problem still has the right high-level model,

```text
boolean states on one large axis
```

but the ordinary implementation

```text
for every item:
    for every state:
```

is too slow by a large constant or by a whole factor of machine word width.

In this repo, the first exact route is intentionally narrow:

- one boolean reachability DP
- one packed bitset state
- one update of the form:

$$
reachable \mathrel{|}= reachable \ll w
$$

That is the first contest-ready doorway into bit-parallelism here.

This page does **not** try to teach every use of bitsets in algorithms.

It starts with the most reusable practical route:

- word-packed subset-sum / feasibility DP on one sum axis

and only then points toward:

- string bitset speedups
- packed transitive-closure style DP
- broader word-parallel boolean-state tricks

## At A Glance

- **Use when:** the state is boolean or near-boolean, one axis is large, and the update can be phrased as word shifts / ORs instead of scalar transitions
- **Core worldview:** pack many boolean DP states into machine words and update many states at once
- **Main tools:** dynamic bitset, shift-OR reachability, word trimming, component-size compression
- **Typical complexity:** about `O(n * max_sum / word_bits)` instead of `O(n * max_sum)`
- **Main trap:** using bitset packing for problems that really need max-value or counting DP, not pure feasibility / reachability

Strong contest signals:

- the DP state is boolean: reachable or not
- the transition is:
  - "add one weight"
  - "shift all currently reachable sums by `w`"
  - "OR the result back"
- `max_sum` is too large for a comfortable scalar `O(nW)` implementation, but still small enough to store one packed bitset
- the bottleneck is plain state updates, not modeling

Strong anti-cues:

- the DP stores best value, min cost, or number of ways instead of a boolean state
- `W` is already tiny enough that ordinary `O(nW)` is simpler
- the state space is the full boolean cube and the real need is a transform family -> [FWHT / XOR Convolution / Subset Convolution](../fwht-subset-convolution/README.md)
- the state is a subset mask of items, not a sum axis or packed boolean frontier -> [Bitmask DP](../bitmask-dp/README.md)

## Prerequisites

- [Knapsack Family](../knapsack-family/README.md)
- [DP Foundations](../foundations/README.md)

Helpful nearby anchors:

- [DP cheatsheet](../../../notebook/dp-cheatsheet.md)
- [FWHT / XOR Convolution / Subset Convolution](../fwht-subset-convolution/README.md), when the packed bitset idea is not enough and the real lane is transform algebra

## Problem Model And Notation

Assume we want the set of reachable sums:

$$
S \subseteq [0, W]
$$

after processing some multiset of nonnegative weights.

The ordinary boolean DP is:

$$
dp[x] = 1 \iff \text{sum } x \text{ is reachable.}
$$

For one `0/1` weight `w`, the scalar update is:

$$
dp'[x] = dp[x] \lor dp[x - w].
$$

The packed view stores the whole boolean row as one bitset:

$$
reachable
$$

where bit `x` is set exactly when sum `x` is reachable.

Then the same update becomes:

$$
reachable \mathrel{|}= reachable \ll w.
$$

That is the central invariant of the first route.

## From Brute Force To The Right Idea

### Scalar Boolean DP

For classic subset-sum reachability, the direct transition is:

```text
for each weight w:
    for sum from W down to w:
        reachable[sum] |= reachable[sum - w]
```

This is already correct and often good enough.

But when:

- `W` is large
- the state is only boolean
- and the transition is just one shift plus OR

then scalar updates are wasting machine-word parallelism.

### The Packing Observation

Instead of storing:

```text
reachable[0], reachable[1], ..., reachable[W]
```

as separate bytes or integers, pack them into 64-bit words.

Then one shifted OR updates roughly 64 states at once.

So the question changes from:

```text
what is the recurrence?
```

to:

```text
can the same recurrence be executed wordwise?
```

For boolean subset sum, the answer is yes.

## Core Invariant And Why It Works

Let bit `x` of `reachable` mean:

$$
x \in S.
$$

Then shifting left by `w` produces a new bitset whose set bits are exactly:

$$
\{x + w \mid x \in S\}.
$$

So after:

$$
reachable \mathrel{|}= reachable \ll w,
$$

bit `y` is set iff:

- `y` was already reachable, or
- `y - w` was reachable before this item

which is exactly the `0/1` subset-sum transition.

The implementation detail is that a dynamic bitset shift must:

- move whole machine words
- then move the remaining bit offset
- and trim away bits beyond the allowed maximum index

That is the first exact route taught by:

- [bitset-reachability-shift.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/bitset-reachability-shift.cpp)

## Why The Flagship Problem Fits

The flagship rep in this repo is:

- [School Excursion](../../../practice/ladders/dp/bit-parallelism/schoolexcursion.md)

That problem is not just raw subset sum.

It first compresses the graph into connected-component sizes, then asks which group sizes are reachable.

So it is a perfect first practical route for the family:

1. do one light modeling step
2. reduce to boolean subset-sum reachability
3. solve by packed shift-OR DP

## Common Traps

### 1. Using This For Max-Value DP

Bitset packing is ideal when the state is boolean.

If the DP stores:

- maximum value
- minimum cost
- number of ways

then this starter is the wrong tool.

### 2. Reusing One Item More Than Once By Mistake

The route here is for `0/1`-style reachability.

The packed shift:

$$
reachable \mathrel{|}= reachable \ll w
$$

is correct because the whole right-hand side conceptually uses the pre-update row.

If you change the model, re-check that contract carefully.

### 3. Forgetting To Trim High Bits

If the maximum useful sum is `W`, bits above `W` are garbage.

Dynamic bitset implementations must zero those tail bits after updates or before extraction.

### 4. Overclaiming The Family

This lane is broader than one subset-sum trick, but the first route is still narrow.

Do not jump straight from this starter to:

- weighted maximization DP
- full boolean-cube transforms
- every string bitset trick

without checking whether the state contract is still the same.

## Use This Lane When

- reachability or feasibility is the real output
- one axis is large enough that word packing matters
- the update is mostly shifts, ORs, ANDs, or bitwise filters

## Do Not Use This Lane When

- the value stored per state is not boolean
- the intended route is still ordinary knapsack and constants are irrelevant
- the task is really a transform problem on the full mask cube

## References And Repo Anchors

Research sweep refreshed on `2026-04-25`.

Books:

- [Competitive Programmer's Handbook](https://www.cses.fi/book/book.pdf)
- [Guide to Competitive Programming](https://link.springer.com/book/10.1007/978-3-031-61794-2)

Official benchmarks:

- [CSES - School Excursion](https://cses.fi/problemset/task/1706/)
- [CSES - Money Sums](https://cses.fi/problemset/task/1745/)

Repo anchors:

- practice ladder: [Bit-Parallelism / Bitset Optimization ladder](../../../practice/ladders/dp/bit-parallelism/README.md)
- flagship note: [School Excursion](../../../practice/ladders/dp/bit-parallelism/schoolexcursion.md)
- starter template: [bitset-reachability-shift.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/bitset-reachability-shift.cpp)
- notebook refresher: [Bit-Parallelism / Bitset Optimization hot sheet](../../../notebook/bit-parallelism-hot-sheet.md)

## Related Topics

- [Knapsack Family](../knapsack-family/README.md)
- [Bitmask DP](../bitmask-dp/README.md)
- [FWHT / XOR Convolution / Subset Convolution](../fwht-subset-convolution/README.md)
