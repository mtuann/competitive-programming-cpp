# Mo's Algorithm

Mo's algorithm is the right answer when:

- every query is over one static array
- all queries are known before answering starts
- maintaining the answer for the **current active range** is easy
- but there is no clean one-directional sweep invariant

It is best learned as a **separate lane** from [Offline Tricks](../offline-tricks/README.md), not as a tiny footnote under offline processing.

The repo's exact first route for this lane is:

- starter -> [mos-algorithm.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/mos-algorithm.cpp)
- flagship note -> [Powerful Array](../../../practice/ladders/data-structures/mos-algorithm/powerfularray.md)
- compare point -> [Distinct Values Queries](../../../practice/ladders/data-structures/offline-tricks/distinctvaluesqueries.md)

## At A Glance

- **Use when:** static range queries can be maintained by adding or removing one endpoint in `O(1)` or `O(log n)`
- **Core worldview:** reorder queries so the active interval changes gradually; keep one mutable data structure for exactly the current range
- **Main tools:** block sort by left endpoint, alternating right-end order, symmetric `add(pos)` / `remove(pos)` updates
- **Typical complexity:** `O((n + q) * sqrt(n) * cost_of_update)`
- **Main trap:** choosing Mo when a simpler monotone sweep or tree structure already removes the hard part

Strong contest signals:

- "many static range queries over one array"
- "online segment tree feels too heavy, but moving `L` or `R` by one is easy"
- "the statistic depends on frequencies inside the current range"
- "all answers can be postponed to the end"

Strong anti-cues:

- one monotone key sweep already works -> [Offline Tricks](../offline-tricks/README.md)
- updates happen between queries -> ordinary Mo starter is not enough
- the problem is subtree/path on a tree and you have not flattened or reduced it yet
- add/remove of one element is still expensive or non-local

## Prerequisites

- [Offline Tricks](../offline-tricks/README.md)
- [Sorting](../../foundations/patterns/sorting/README.md)
- [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md) only as a contrast for why online maintenance may be heavier than offline reordering

Helpful compare points:

- [Distinct Values Queries](../../../practice/ladders/data-structures/offline-tricks/distinctvaluesqueries.md): offline right-endpoint sweep wins because the invariant is monotone
- [DSU Rollback / Offline Dynamic Connectivity](../dsu-rollback/README.md): another offline lane where the hard part is not locality but time-interval rollback

## Problem Model And Notation

Assume one static array:

$$
a_0, a_1, \dots, a_{n-1}
$$

and many queries:

$$
[l_i, r_i]
$$

where the answer depends only on the contents of that subarray.

Mo's algorithm does **not** build one precomputed structure per block.
Instead it maintains one current active range:

$$
[L, R]
$$

and one mutable state that is always the exact answer data for that range.

The only supported moves are:

- extend left by one
- extend right by one
- shrink left by one
- shrink right by one

So the hidden contract is:

```text
if I already know the answer-state for [L, R],
I can update it cheaply when one boundary moves by exactly one step
```

## From Brute Force To The Right Idea

### Brute Force

For each query `[l, r]`, scan the whole interval and rebuild the statistic from scratch.

That costs:

$$
O\left(\sum (r_i - l_i + 1)\right)
$$

which becomes too slow once both `n` and `q` are large.

### Why A One-Key Sweep Sometimes Fails

In [Distinct Values Queries](../../../practice/ladders/data-structures/offline-tricks/distinctvaluesqueries.md), sorting by right endpoint works because the maintained state has a monotone meaning:

```text
all positions up to r have already been seen
```

But many range-query statistics do **not** admit such a monotone frontier.

For example:

- frequency-based scores
- mode-like statistics
- values that depend on both ends in a genuinely local way

Then there is no natural "all events up to key `K` are active" interpretation.

### The Locality Pivot

Instead of forcing a monotone sweep, Mo says:

1. keep one exact answer-state for the current range
2. reorder the queries so consecutive ranges are close
3. pay only for the total movement of the two boundaries

So the hard question becomes:

```text
can I write add(pos) and remove(pos) correctly?
```

If yes, query ordering becomes the outer optimization layer.

## Core Invariant And Why It Works

For the current window `[L, R]`, the maintained data structure must satisfy:

```text
it represents exactly the statistic of a[L..R]
```

Nothing weaker is enough.

When transitioning from one query to the next, we repeatedly move one endpoint:

```text
while L > q.l: add(--L)
while R < q.r: add(++R)
while L < q.l: remove(L++)
while R > q.r: remove(R--)
```

After those loops finish, the active range is exactly the target query range, so the current state is the answer-state for that query.

That is the whole correctness argument.

The special ordering matters only because it keeps the total number of moves manageable.

## Why The Query Order Works

Split indices into blocks of size about:

$$
\lfloor \sqrt{n} \rfloor
$$

Sort queries by:

1. block of `l`
2. then by `r` inside that block

The common implementation improvement is the "snake" order:

- even left-blocks sort by increasing `r`
- odd left-blocks sort by decreasing `r`

This reduces unnecessary right-end resets between neighboring blocks.

The mental model is:

- inside one left block, `L` changes only a bounded amount
- `R` moves mostly forward/backward locally instead of jumping wildly

So the total movement becomes roughly:

$$
O((n + q)\sqrt{n})
$$

times the cost of one `add/remove`.

## Worked Examples

### Example 1: Distinct Count With Frequency Table

Suppose the answer is:

- number of distinct values inside `[L, R]`

Maintain:

- `freq[x]`
- `distinct`

Then:

- `add(pos)`: if `freq[a[pos]]` goes `0 -> 1`, increment `distinct`
- `remove(pos)`: if `freq[a[pos]]` goes `1 -> 0`, decrement `distinct`

This is the easiest Mo statistic to learn.

### Example 2: Powerful Array

This repo's flagship note:

- [Powerful Array](../../../practice/ladders/data-structures/mos-algorithm/powerfularray.md)

The score is:

$$
\sum_x \text{freq}[x]^2 \cdot x
$$

The key update is local:

If one value `x` currently has frequency `f`, then after adding one more `x`:

$$
f^2 x \rightarrow (f+1)^2 x
$$

So we can update the answer by removing the old contribution and adding the new one.

This is exactly the kind of statistic Mo wants:

- no clean monotone sweep
- but add/remove are easy

### Example 3: When Mo Loses To A Sweep

Suppose the task is:

- number of distinct values in `[l, r]`

Mo can solve it.

But the offline right-endpoint sweep in:

- [Distinct Values Queries](../../../practice/ladders/data-structures/offline-tricks/distinctvaluesqueries.md)

is cleaner and asymptotically better for that exact structure.

This is an important lesson:

```text
Mo is not "the offline range-query default."
It is the fallback when monotone sweeps do not exist or do not fit the maintained statistic.
```

## Variant Chooser

### Use Ordinary Mo When

- the array is static
- each query is one range `[l, r]`
- add/remove on one endpoint are cheap
- answer order can be restored offline

Canonical examples:

- distinct counts
- frequency-weighted scores
- mode-adjacent or contribution-by-frequency statistics

### Reopen Offline Tricks Instead When

- one monotone dimension orders all events cleanly
- "all information up to current right endpoint / threshold / time" is the real invariant

Canonical examples:

- right-endpoint sweeps
- threshold sweeps
- parallel binary search

### Treat "Mo With Updates" As A Different Lane

If point modifications occur between queries, the ordinary starter here is no longer enough.

That becomes:

- a time-aware Mo variant
- or a different offline structure entirely

For this repo, that should be treated as a later follow-up, not part of the first learning lane.

### Treat Tree Mo As A Different Reduction

Path/subtree versions need:

- Euler-tour reduction
- often LCA handling
- toggle semantics that differ from plain array Mo

So first trust ordinary array Mo.

## Algorithm And Pseudocode

Repo starter:

- [mos-algorithm.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/mos-algorithm.cpp)

```text
choose block size ≈ sqrt(n)
sort queries by (block(l), snake-ordered r)

L = 0
R = -1

for q in sorted order:
    while L > q.l: add(--L)
    while R < q.r: add(++R)
    while L < q.l: remove(L++)
    while R > q.r: remove(R--)
    ans[q.idx] = extract current answer
```

The starter deliberately assumes:

- ordinary array queries
- no modifications
- one active window

It does **not** try to be a universal offline-query engine.

## Implementation Notes

### 1. Define Query Boundaries Once

Pick one convention:

- either inclusive `[l, r]`
- or half-open `[l, r)`

Then make `add/remove` loops match it exactly.

This repo's starter uses inclusive `l, r`.

### 2. Symmetry Of Add / Remove Matters More Than The Sort

Most wrong answers come from:

- forgetting to undo the old contribution before changing frequency
- using one update rule that is not the exact inverse of the other

The ordering is rarely the real bug.

### 3. Coordinate Compression Is Often The Hidden First Step

If values are large but only equality/frequency matters, compress them before building `freq`.

That keeps:

- memory small
- updates fast
- implementation sane

### 4. Use `long long` Aggressively

Frequency-weighted scores like `freq[x]^2 * x` overflow `int` easily.

### 5. Ordinary Mo Is Static

Do not silently stretch this starter to:

- updates between queries
- tree paths
- 2D points

Those need extra modeling layers.

## Practice Archetypes

### First Rep In This Repo

- [Powerful Array](../../../practice/ladders/data-structures/mos-algorithm/powerfularray.md)

### Best Compare Point In This Repo

- [Distinct Values Queries](../../../practice/ladders/data-structures/offline-tricks/distinctvaluesqueries.md)

### Good External Follow-Ups

- [Static Range Count Distinct](https://judge.yosupo.jp/problem/static_range_count_distinct)
- [D-query](https://www.spoj.com/problems/DQUERY/)
- [Powerful Array](https://codeforces.com/problemset/problem/86/D)

## References

- [cp-algorithms: Sqrt Decomposition / Mo's algorithm](https://cp-algorithms.com/data_structures/sqrt_decomposition.html)
- [OI Wiki: Mo's algorithm intro](https://en.oi-wiki.org/misc/mo-algo-intro/)
- [USACO Guide: Square Root Decomposition](https://usaco.guide/plat/sqrt)
- [Library Checker: Static Range Count Distinct](https://judge.yosupo.jp/problem/static_range_count_distinct)

## Repo Anchors

- [Mo's Algorithm ladder](../../../practice/ladders/data-structures/mos-algorithm/README.md)
- [Powerful Array](../../../practice/ladders/data-structures/mos-algorithm/powerfularray.md)
- [Mo's hot sheet](../../../notebook/mos-hot-sheet.md)
- [Offline Tricks](../offline-tricks/README.md)
