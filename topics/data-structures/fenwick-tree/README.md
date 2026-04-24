# Fenwick Tree

Fenwick tree, or Binary Indexed Tree (`BIT`), is the lightest standard data structure for dynamic prefix sums and dynamic frequency prefixes. It is often the first data structure that teaches a deeper lesson than "store everything explicitly": we only cache the right partial sums, and the binary structure of indices tells us exactly which ones.

If you already understand static prefix sums, Fenwick tree is the next natural step when updates become online.

## At A Glance

Fenwick tree is the right default when:

- point updates and prefix or range queries are interleaved
- the operation is additive, or can be reduced to additive counts
- you need prefix frequencies, inversion counting, or order statistics on counts
- a segment tree feels heavier than necessary

Typical contest triggers:

- "update one position, ask sum on a range"
- "count how many values `<= x` have appeared so far"
- "count inversions after coordinate compression"
- "find the k-th alive / k-th inserted / k-th one"

Strong anti-cues:

- arbitrary associative range queries like `min`, `gcd`, or custom merges with updates
- lazy propagation requirements on many interval updates with non-additive queries
- problems where the natural structure is a full segment tree, not a prefix structure

What success looks like after studying this page:

- you can explain what `bit[i]` stores without memorizing loops blindly
- you can derive both query and update loops from the same interval invariant
- you know when a single `BIT`, two `BIT`s, or a segment tree is the right tool

## Prerequisites

- [Prefix Sums](../../foundations/patterns/prefix-sums/README.md)
- [Difference Arrays](../../foundations/patterns/difference-arrays/README.md) for the range-update variants

## Problem Model And Notation

Assume a one-based array $a_1, a_2, \dots, a_n$.

Define:

- $\operatorname{lowbit}(i) = i \mathbin{\&} (-i)$
- `bit[i]`: the Fenwick node stored at index `i`

The core invariant is:

$$
\operatorname{bit}[i] = \sum_{j=i-\operatorname{lowbit}(i)+1}^{i} a_j
$$

So `bit[i]` stores the sum of the suffix block of length $\operatorname{lowbit}(i)$ ending at $i$.

For the first few indices, the stored blocks are:

| `i` | `lowbit(i)` | stored interval |
| --- | --- | --- |
| `1` | `1` | `[1, 1]` |
| `2` | `2` | `[1, 2]` |
| `3` | `1` | `[3, 3]` |
| `4` | `4` | `[1, 4]` |
| `5` | `1` | `[5, 5]` |
| `6` | `2` | `[5, 6]` |
| `7` | `1` | `[7, 7]` |
| `8` | `8` | `[1, 8]` |

This table is the whole data structure in miniature. Every loop in a Fenwick tree is just moving between these blocks.

## From Brute Force To The Right Idea

Suppose we need two online operations:

- `add(i, delta)`: add `delta` to one position
- `sum(l, r)`: query a range sum at any time

### Brute Force

- point update: `O(1)`
- range sum by scanning: `O(n)`

This is too slow when both updates and queries are frequent.

### Static Prefix Sums

Static prefix sums fix the query:

$$
\sum_{k=l}^{r} a_k = \operatorname{pref}[r] - \operatorname{pref}[l - 1]
$$

but a point update now forces every later prefix to change, so the update becomes `O(n)`.

### What We Really Need

We want a cache of partial sums that is:

- small enough that one point update touches only `O(log n)` cached values
- rich enough that one prefix query can be reconstructed from only `O(log n)` cached values

The right observation is that every prefix can be decomposed into a small number of suffix blocks.

For example, for $r = 13$:

$$
[1, 13] = [1, 8] \cup [9, 12] \cup [13, 13]
$$

and those block lengths are exactly the low bits encountered while repeatedly subtracting `lowbit`:

$$
13 \rightarrow 12 \rightarrow 8 \rightarrow 0
$$

So the algorithmic idea becomes:

1. store the sum of one canonical suffix block at each index
2. reconstruct a prefix by peeling off those blocks from right to left
3. update a point by climbing to all blocks that contain it

That gives logarithmic time in both directions.

## Core Invariant And Why It Works

### The Invariant

Fenwick tree is correct because every node `bit[i]` stores exactly one interval:

$$
I(i) = [i-\operatorname{lowbit}(i)+1, i]
$$

and all operations preserve and exploit that invariant.

### Why Prefix Queries Work

Let $r_0 = r$, and define:

$$
r_{k+1} = r_k - \operatorname{lowbit}(r_k)
$$

The query loop visits the intervals:

$$
I(r_0), I(r_1), I(r_2), \dots
$$

These intervals are:

1. pairwise disjoint, because each step removes the last stored block
2. contiguous from right to left
3. together they cover exactly `[1, r]`

More explicitly, if $I(r_k) = [r_{k+1}+1, r_k]$, then:

$$
[1, r] = [1, r_m] \cup \bigcup_{k=0}^{m-1} [r_{k+1}+1, r_k]
$$

and the process ends when $r_m = 0$. Therefore:

$$
\sum_{k=1}^{r} a_k = \sum_{\text{visited } x} \operatorname{bit}[x]
$$

That is exactly what the prefix-query loop computes.

### Why Point Updates Work

Suppose position $p$ changes by $\Delta$. We must add $\Delta$ to every Fenwick node whose interval contains $p$.

The update loop visits:

$$
p,\; p + \operatorname{lowbit}(p),\; p + \operatorname{lowbit}(p + \operatorname{lowbit}(p)), \dots
$$

Each jump moves to the next larger suffix block that still ends at or after $p$. Those are precisely the blocks whose stored interval contains $p$, so adding $\Delta$ to every visited node restores the invariant.

You can think of the query loop as "strip the lowest block" and the update loop as "add the position into every larger cached block that covers it". They are inverse views of the same block system.

## Complexity And Tradeoffs

- point update: `O(log n)`
- prefix query: `O(log n)`
- range sum: `O(log n)` via two prefix queries
- memory: `O(n)`

Practical tradeoffs:

- lighter and shorter than a segment tree
- excellent cache behavior and constant factors
- ideal when the structure is fundamentally prefix-based
- weaker than a segment tree for general range aggregates or heavy lazy propagation

Use Fenwick instead of nearby tools when:

- [Prefix Sums](../../foundations/patterns/prefix-sums/README.md) are too static
- [Difference Arrays](../../foundations/patterns/difference-arrays/README.md) are too offline
- [Segment Tree](../segment-tree/README.md) would solve the problem, but with unnecessary machinery

## Variant Chooser

| Variant | Supports | Main idea | Complexity | Best use case |
| --- | --- | --- | --- | --- |
| Standard `BIT` | point add, prefix sum, range sum | store suffix blocks of the original array | `O(log n)` per op | dynamic sums, frequencies, inversion counts |
| Difference-style `BIT` | range add, point query | store the difference array in one `BIT` | `O(log n)` per op | many interval increments, only final point values needed |
| Two-`BIT` formula | range add, range sum | combine a difference `BIT` with a weighted correction `BIT` | `O(log n)` per op | online interval adds plus online interval sums |
| Frequency `BIT` with binary lifting | add/remove counts, k-th element | treat prefix sums as cumulative frequencies | `O(log n)` per op/query | order statistics on compressed coordinates |

The two-`BIT` prefix formula is:

$$
\operatorname{pref}(x) = x \cdot \operatorname{sum}(B_1, x) - \operatorname{sum}(B_2, x)
$$

after encoding a range add through the difference array. This is powerful, but the standard one-`BIT` version should feel automatic first.

## Worked Examples

### Example 1: Tiny Trace On Dynamic Prefix Sums

Take:

$$
a = [2, 1, 3, 4, 5, 1, 2, 6]
$$

Then the Fenwick array becomes:

| `i` | stored interval | `bit[i]` |
| --- | --- | --- |
| `1` | `[1, 1]` | `2` |
| `2` | `[1, 2]` | `3` |
| `3` | `[3, 3]` | `3` |
| `4` | `[1, 4]` | `10` |
| `5` | `[5, 5]` | `5` |
| `6` | `[5, 6]` | `6` |
| `7` | `[7, 7]` | `2` |
| `8` | `[1, 8]` | `24` |

Now query the prefix sum up to `7`.

The loop visits:

| current index | interval contributed | value added |
| --- | --- | --- |
| `7` | `[7, 7]` | `2` |
| `6` | `[5, 6]` | `6` |
| `4` | `[1, 4]` | `10` |

Total:

$$
\operatorname{sum\_prefix}(7) = 2 + 6 + 10 = 18
$$

which is exactly:

$$
2 + 1 + 3 + 4 + 5 + 1 + 2 = 18
$$

Now update position `5` by `+3`.

The update loop visits:

| current index | why it changes |
| --- | --- |
| `5` | block `[5, 5]` contains position `5` |
| `6` | block `[5, 6]` contains position `5` |
| `8` | block `[1, 8]` contains position `5` |

So only three cached sums change. That is the whole point of the structure.

### Example 2: Contest-Style Recognition Through Inversion Counting

Suppose the array is:

$$
[3, 1, 2, 2]
$$

After coordinate compression, the ranks are still `[3, 1, 2, 2]`.

Scan left to right, and let the `BIT` store how many times each rank has appeared.

At each step:

- `seen`: number of processed elements
- `prefix(rank)`: how many processed elements are `<= current`
- `seen - prefix(rank)`: how many processed elements are greater than `current`

| current value | `seen` before insert | `prefix(rank)` | new inversions contributed |
| --- | --- | --- | --- |
| `3` | `0` | `0` | `0` |
| `1` | `1` | `0` | `1` |
| `2` | `2` | `1` | `1` |
| `2` | `3` | `2` | `1` |

Total inversions:

$$
0 + 1 + 1 + 1 = 3
$$

Recognition lesson:

- the statement is not "about prefix sums"
- it is "about online prefix counts after compression"
- that is exactly where Fenwick tree shines

## Algorithm And Pseudocode

For the standard point-add / prefix-sum version:

```text
Fenwick(n):
    bit[1..n] <- 0

add(i, delta):
    while i <= n:
        bit[i] <- bit[i] + delta
        i <- i + lowbit(i)

sum_prefix(i):
    answer <- 0
    while i > 0:
        answer <- answer + bit[i]
        i <- i - lowbit(i)
    return answer

sum_range(l, r):
    return sum_prefix(r) - sum_prefix(l - 1)
```

The repository template for this version is:

- [fenwick-point-prefix.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/fenwick-point-prefix.cpp)

## Implementation Notes

### Indexing Policy

Use one-based indexing inside the structure.

If the input is zero-based, convert once at the boundary and keep the internals one-based all the way through.

### Numeric Types

Use `long long` by default for sums and frequency totals. Many contest constraints overflow `int` surprisingly quickly once updates accumulate.

### Linear Build

If you already have the full array and want to build a `BIT` in `O(n)`, you can propagate each node into its parent block:

```text
for i = 1..n:
    bit[i] += a[i]
    j = i + lowbit(i)
    if j <= n:
        bit[j] += bit[i]
```

This is a useful optimization, but not the first thing to memorize.

### Order Statistics

To find the smallest index whose prefix sum is at least `k`, the stored values must behave like nonnegative frequencies. If counts can go negative, the binary-lifting trick loses its monotonicity guarantee.

### Range-Update Variants

For range add plus point query, think in terms of a difference array:

- add `delta` at `l`
- add `-delta` at `r + 1`
- query the point value as a prefix sum

For range add plus range sum, combine two `BIT`s and use the prefix formula from the variant table above.

## Common Mistakes

- mixing zero-based and one-based indexing
- forgetting that the basic `BIT` is a prefix structure first, not an arbitrary range structure
- using Fenwick for `min` / `max` just because the loops look similar
- forgetting coordinate compression when values are large but sparse
- using the k-th-order-statistic trick on negative or non-monotone cumulative data
- memorizing `idx += idx & -idx` without understanding which interval is being updated

## Practice Archetypes

### Warm-Up

- `Dynamic Range Sum Queries`:
  why it fits: direct point updates plus range sums; the cleanest "Fenwick instead of segment tree" exercise
- `List Removals`:
  why it fits: frequency `BIT` plus k-th alive element

### Core

- `INVCNT` / inversion-count tasks:
  why it fits: coordinate compression plus online prefix counts
- `Salary Queries`-style frequency tasks:
  why it fits: dynamic rank and prefix counts on compressed values

### Stretch

- [CVP00001 - Ô ăn quan](../../../practice/ladders/data-structures/fenwick-tree/cvp00001.md):
  why it fits: the statement hides circular range updates plus point resets, so the real work is transforming the simulation into Fenwick-friendly operations
- offline distinct-value or sweep problems with a `BIT`:
  why it fits: the tree becomes a light event accumulator inside a larger offline strategy

## References And Repo Anchors

- Practice ladder: [Fenwick Tree ladder](../../../practice/ladders/data-structures/fenwick-tree/README.md)
- Notebook refresher: [Data structures cheatsheet](../../../notebook/data-structures-cheatsheet.md)
- Canonical template: [fenwick-point-prefix.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/fenwick-point-prefix.cpp)
- Strong repo note: [CVP00001](../../../practice/ladders/data-structures/fenwick-tree/cvp00001.md)
- Reference: [CP-Algorithms - Fenwick Tree](https://cp-algorithms.com/data_structures/fenwick.html)
- Reference: [USACO Guide - BIT / Fenwick Tree](https://usaco.guide/gold/PURS)
- Practice source: [CSES Problem Set](https://cses.fi/problemset/)

## Related Topics

- [Prefix Sums](../../foundations/patterns/prefix-sums/README.md)
- [Difference Arrays](../../foundations/patterns/difference-arrays/README.md)
- [Segment Tree](../segment-tree/README.md)
