# Range Chmin Chmax Add Range Sum

- Title: `Range Chmin Chmax Add Range Sum`
- Judge / source: `Library Checker`
- Original URL: [https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum](https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum)
- Secondary topics: `Segment Tree Beats`, `Range chmin`, `Range chmax`
- Difficulty: `hard`
- Subtype: `Canonical beats verifier with range chmin / chmax / add / sum`
- Status: `solved`
- Solution file: [rangechminchmaxaddrangesum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/segment-tree-beats/rangechminchmaxaddrangesum.cpp)

## Why Practice This

This is the cleanest exact verifier for the canonical Beats starter in this repo.

The operation family matches the lane exactly:

- cap a range from above
- cap a range from below
- add one delta to a range
- ask the range sum

So the real lesson is not one narrow custom pruning trick.

It is:

- why `second maximum` / `second minimum` are enough
- how Beats weakens the full-cover tag condition
- how additive lazy tags coexist with the beats summaries

## Recognition Cue

Reach for Segment Tree Beats when:

- the array is mutable and online
- the statement asks for `range chmin` or `range chmax`
- the answer still needs one aggregate like the sum
- one ordinary lazy tag cannot summarize the clamp update without knowing which values are currently maximal or minimal

The strongest smell here is:

- "clamp a whole interval from above or below, then keep querying sums"

## Problem-Specific Transformation

Store one node summary per segment:

- `sum`
- `max1`, `max2`, `maxc`
- `min1`, `min2`, `minc`
- one additive lazy tag

Then process the four query types as:

- `0 l r x` -> `range_chmin(l, r, x)`
- `1 l r x` -> `range_chmax(l, r, x)`
- `2 l r x` -> `range_add(l, r, x)`
- `3 l r` -> `range_sum(l, r)`

The reusable rewrite is:

- `range_chmin` only needs to recurse when the node is covered but `max2 >= x`
- `range_chmax` only needs to recurse when the node is covered but `min2 <= x`

That is the exact Beats worldview.

## Core Idea

For a covered segment, `range_chmin(..., x)` has three cases:

1. `max1 <= x` -> nothing changes
2. `max2 < x < max1` -> only the current maxima change
3. otherwise -> push and recurse

Case 2 is the whole reason the data structure works:

$$
\text{sum} \leftarrow \text{sum} + (x - \text{max1}) \cdot \text{maxc}
$$

without touching every leaf.

The symmetric rule holds for `range_chmax`.

`range_add` is still a normal lazy tag:

- every value in the segment shifts together
- all extrema shift together
- counts do not change

So the implementation is a hybrid:

- ordinary lazy propagation for `add`
- Beats pruning for `chmin` / `chmax`

## Complexity

- build: `O(n)`
- `range_sum`: `O(log n)`
- `range_add`: `O(log n)`
- `range_chmin` / `range_chmax`: amortized heavy near-logarithmic updates

For contest planning, treat the Beats updates as clearly heavier than plain lazy propagation.

## Pitfalls / Judge Notes

- Intervals are zero-based half-open `[l, r)`.
- `max2` and `min2` must be strict second extrema, not duplicates of the top/bottom value.
- The `O(1)` clamp update is valid only when the stronger tag condition holds.
- This exact verifier matches the canonical starter; do not switch to modulo/historic variants mid-implementation.
- Use `long long` throughout.

## Reusable Pattern

- Topic page: [Segment Tree Beats](../../../../topics/data-structures/segment-tree-beats/README.md)
- Practice ladder: [Segment Tree Beats ladder](README.md)
- Starter template: [segment-tree-beats.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/segment-tree-beats.cpp)
- Notebook refresher: [Segment Tree Beats hot sheet](../../../../notebook/segment-tree-beats-hot-sheet.md)
- Compare points:
  - [Lazy Segment Tree](../../../../topics/data-structures/lazy-segment-tree/README.md)
  - [The Child and Sequence](https://codeforces.com/problemset/problem/438/D)
- This note adds: the exact canonical verifier where the repo starter fits directly.

## Solutions

- Code: [rangechminchmaxaddrangesum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/segment-tree-beats/rangechminchmaxaddrangesum.cpp)
