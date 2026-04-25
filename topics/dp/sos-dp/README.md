# SOS DP

This lane begins when a mask problem stops being:

```text
add one bit, remove one bit, or iterate one explicit submask transition
```

and becomes:

```text
for every mask, aggregate information over all of its submasks or all of its supersets
```

That is the exact contest meaning of `SOS DP` in this repo:

- treat the full bitmask cube `0 .. (1 << bits) - 1` as the state space
- sweep one bit at a time
- reuse the same recurrence shape for sums, counts, booleans, or one witness value

This page is intentionally narrow.

It does **not** try to teach:

- xor convolution / Walsh-Hadamard transform
- subset convolution
- every fast transform on the boolean cube

It teaches the first exact route that still appears often in contest problems:

```text
subset/superset zeta sweeps on the full mask cube
```

## At A Glance

- **Use when:** every mask needs an aggregate over all of its submasks or all of its supersets
- **Core worldview:** SOS DP is an `n`-dimensional prefix-sum sweep over the boolean cube
- **Main tools:** subset zeta transform, superset zeta transform, complement masks, witness propagation
- **Typical complexity:** `O(bits * 2^bits)`
- **Main trap:** mixing subset direction and superset direction, then querying the wrong transformed array

Strong contest signals:

- values already live on the full mask space or can be bucketed into it
- the task asks for:
  - sum/count over all `submask ⊆ mask`
  - sum/count over all `supermask ⊇ mask`
  - or "any witness" among those masks
- the bit width is moderate, often around `20` to `24`
- brute force over all mask pairs would be `O(4^bits)` or `O(3^bits)`

Strong anti-cues:

- the DP state evolves by adding one chosen item -> [Bitmask DP](../bitmask-dp/README.md)
- the mask is a frontier on a grid, not the whole subset cube -> [Broken Profile / Plug DP](../broken-profile/README.md)
- the intended operation is xor convolution or another transform this lane does not advertise
- the universe is too large to allocate arrays of length `1 << bits`

## Prerequisites

- [DP Foundations](../foundations/README.md)
- [Bitmask DP](../bitmask-dp/README.md)

Helpful nearby anchors:

- [Broken Profile / Plug DP](../broken-profile/README.md)
- [DP cheatsheet](../../../notebook/dp-cheatsheet.md)
- [XOR Basis / Linear Basis](../../math/xor-basis/README.md), when bitwise wording hides a linear-algebra task instead of a mask-cube aggregate

## Problem Model And Notation

Assume the universe has `bits` binary coordinates.

Then every mask satisfies:

$$
mask \in [0, 2^{bits})
$$

and the full cube is:

$$
full = (1 \ll bits) - 1.
$$

We start from one base array:

$$
base[mask]
$$

and want one transformed array where each entry aggregates over:

### All Submasks

$$
sub[mask] = \sum_{submask \subseteq mask} base[submask]
$$

### Or All Supermasks

$$
super[mask] = \sum_{supermask \supseteq mask} base[supermask]
$$

The same bit-by-bit sweep also works when the combine operation is not addition.

For example:

- store whether any exact mask is present
- carry one witness value
- propagate one best / first valid representative

That is why the flagship note in this repo is not "sum values on subsets."

It is a witness-propagation problem:

- [Compatible Numbers](../../../practice/ladders/dp/sos-dp/compatiblenumbers.md)

## From Brute Force To The Right Idea

### Brute Force

The naive idea is:

- for every `mask`
- iterate over every other mask
- test subset / superset relation
- update the answer if the relation matches

That is:

$$
O(4^{bits})
$$

for all masks together, which is dead once `bits` is around `22`.

Even enumerating all submasks separately for every mask costs:

$$
O(3^{bits})
$$

which is sometimes too large as well.

### The Cube-Sweep Observation

Think of each mask as one point in an `n`-dimensional grid where every coordinate is `0` or `1`.

Then "sum over all submasks" is exactly:

- an `n`-dimensional prefix sum
- where each dimension has only two states

So instead of re-enumerating all compatible masks for every query mask, we:

1. copy the base array
2. sweep one bit at a time
3. fold information across that bit boundary

That turns repeated subset/superset aggregation into:

$$
O(bits \cdot 2^{bits})
$$

## Core Invariants And Why They Work

## 1. Subset-Zeta Invariant

Suppose we want:

$$
sub[mask] = \sum_{submask \subseteq mask} base[submask]
$$

Initialize:

$$
sub = base
$$

Then for each bit `b`:

- if `mask` has bit `b` set
- fold from `mask ^ (1 << b)` into `mask`

After processing the first `t` bits:

- `sub[mask]` already contains contributions from all masks that only differ from `mask` inside those processed dimensions by turning some `1`s into `0`s

After all bits are processed, that means:

- all submasks have been included

## 2. Superset-Zeta Invariant

If instead we want:

$$
super[mask] = \sum_{supermask \supseteq mask} base[supermask]
$$

then the sweep goes the other way.

For each bit `b`:

- if `mask` does **not** contain bit `b`
- fold from `mask | (1 << b)` into `mask`

So the whole lane is really one idea with two directions:

- subset aggregation
- superset aggregation

## 3. Witness Propagation Uses The Same Skeleton

The combine step does not need to be `+`.

If:

- `witness[mask] = mask` when that exact mask is present
- `witness[mask] = -1` otherwise

then the subset sweep:

- "if current witness is missing, copy from the smaller submask"

fills every `mask` with **one present submask witness** when such a witness exists.

That is the exact first route used by [Compatible Numbers](../../../practice/ladders/dp/sos-dp/compatiblenumbers.md).

## 4. Complement Queries Are Often The Modeling Step

Many SOS problems are not stated as:

```text
aggregate over all submasks
```

They are stated in bitwise language like:

```text
x & y == 0
```

The modeling bridge is usually:

- if `x & y == 0`, then `y` must be a submask of `full ^ x`

So the contest skill is not only the sweep itself.

It is also:

- convert the original predicate into one subset/superset query on a transformed array

## Exact First Route In This Repo

The repo's first exact route is intentionally narrow:

- full mask cube
- subset zeta transform
- superset zeta transform
- one witness-propagation helper using the same subset sweep

The starter exposes:

- `subset_zeta_transform(f, bits)`
- `superset_zeta_transform(f, bits)`
- `propagate_any_subset(witness, bits)`

where:

- `f.size() == 1 << bits`
- `witness[mask]` uses `-1` as "no representative yet"

This is enough for:

- counts
- sums
- any-present checks
- one compatible representative under complement modeling

## Variant Chooser

### Use Plain Bitmask DP When

- the state is a subset, but transitions add or remove one chosen bit
- you are storing best cost / count per state
- the problem is about path/order/coverage evolution

That route belongs to [Bitmask DP](../bitmask-dp/README.md).

### Use SOS DP When

- every mask needs data from **all** of its submasks or supersets
- you want one global cube sweep before answering many mask queries
- the recurrence is over the whole boolean cube, not one search tree of chosen states

### Use Broken Profile When

- the mask is a moving grid frontier
- the dimensions of the DP state are "row within a column sweep," not the full subset cube

That route belongs to [Broken Profile / Plug DP](../broken-profile/README.md).

## Complexity And Feasibility

If `bits = B`, then:

- state count is `2^B`
- one full SOS sweep is `O(B 2^B)`

Rough contest numbers:

- `2^20 ≈ 10^6`
- `22 * 2^22 ≈ 9.2 * 10^7`
- `24 * 2^24 ≈ 4.0 * 10^8`

So this lane is realistic only while:

- the bit width stays moderate
- and the judge/memory model supports dense arrays on the whole cube

## Main Traps

- mixing subset direction and superset direction
- forgetting to transform the predicate with a complement mask first
- treating this as plain `dp[mask]` evolution rather than one cube sweep
- reaching for SOS when explicit submask enumeration is already cheap enough
- overclaiming the starter as a general boolean-cube transform library

## Retrieval Layer

- exact quick sheet -> [SOS DP hot sheet](../../../notebook/sos-dp-hot-sheet.md)
- exact starter -> [sos-dp-zeta.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/sos-dp-zeta.cpp)
- flagship note -> [Compatible Numbers](../../../practice/ladders/dp/sos-dp/compatiblenumbers.md)
- parent chooser -> [DP cheatsheet](../../../notebook/dp-cheatsheet.md)

Compare points:

- [Bitmask DP](../bitmask-dp/README.md)
- [Broken Profile / Plug DP](../broken-profile/README.md)

## References And Repo Anchors

Research sweep refreshed on `2026-04-25`.

Reference:

- [USACO Guide: Sum over Subsets DP](https://usaco.guide/plat/dp-sos?lang=py)
- [OI Wiki: Prefix Sum and SOS subsection](https://oi-wiki.org/basic/prefix-sum/)

Practice:

- [Codeforces 165E - Compatible Numbers](https://codeforces.com/problemset/problem/165/E)
- [CSES - SOS Bit Problem](https://cses.fi/problemset/task/1654/)

Repo anchors:

- practice ladder: [SOS DP ladder](../../../practice/ladders/dp/sos-dp/README.md)
- practice note: [Compatible Numbers](../../../practice/ladders/dp/sos-dp/compatiblenumbers.md)
- starter template: [sos-dp-zeta.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/sos-dp-zeta.cpp)
- notebook refresher: [SOS DP hot sheet](../../../notebook/sos-dp-hot-sheet.md)

## Related Topics

- [Bitmask DP](../bitmask-dp/README.md)
- [Broken Profile / Plug DP](../broken-profile/README.md)
- [XOR Basis / Linear Basis](../../math/xor-basis/README.md)
