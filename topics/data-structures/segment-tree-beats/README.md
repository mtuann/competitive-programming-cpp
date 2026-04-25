# Segment Tree Beats

Segment Tree Beats is the lane for interval updates that are **too strong for ordinary lazy tags**, but still weak enough that one node can sometimes absorb the whole update after checking a richer summary.

The canonical contest version is:

- `range_chmin(l, r, x)`
- `range_chmax(l, r, x)`
- `range_add(l, r, delta)`
- `range_sum(l, r)`

This topic matters because a plain lazy segment tree wants one closed-form tag family. For `chmin` / `chmax`, that family is not small enough in general. Beats works by replacing:

```text
full cover => always tag and return
```

with:

```text
full cover + stronger node condition => tag and return
otherwise push and recurse
```

That stronger condition is the whole technique.

## At A Glance

- **Use when:** the array is online, queries ask for sums or extrema, and updates like `a[i] = min(a[i], x)` or `a[i] = max(a[i], x)` must hit whole ranges
- **Core worldview:** a node stores enough information about its largest and smallest values that some interval updates can be finished in `O(1)` at that node
- **Main tools:** `max1 / max2 / max_count`, `min1 / min2 / min_count`, range sum, and one additive lazy tag
- **Main trap:** treating Beats as "lazy propagation but fancier" without checking the stronger tag condition

Strong contest signals:

- range `chmin` or `chmax` plus range sum
- updates that only change the current maxima or minima of a segment
- the statement feels like "cap values from above / below" rather than "add one delta to all values"
- an ordinary lazy tag cannot summarize the update without knowing the segment distribution

Strong anti-cues:

- updates are only `range add` / `range assign` -> [Lazy Segment Tree](../lazy-segment-tree/README.md)
- the array is static -> [Sparse Table](../sparse-table/README.md) or offline processing
- only one special route like `range modulo + sum` is needed -> this is a beats-like pruning problem, not necessarily the full canonical lane
- the real structure is on a tree -> do Euler flattening or HLD first, then ask whether Beats still belongs

What success looks like after this page:

- you can explain why `second maximum` and `second minimum` are the key summaries
- you know the difference between a `break condition` and a `tag condition`
- you can tell when a node can absorb `chmin` / `chmax` immediately and when recursion must continue
- you know when the repo starter fits exactly and when the problem has drifted into modulo, historic, or GCD variants

## Prerequisites

- [Segment Tree](../segment-tree/README.md)
- [Lazy Segment Tree](../lazy-segment-tree/README.md)
- [Reasoning And Implementation Discipline](../../foundations/reasoning/README.md)

Helpful neighbors:

- [Offline Tricks](../offline-tricks/README.md) when the statement is secretly reorderable
- [Heavy-Light Decomposition](../../graphs/hld/README.md) if the same update/query family lives on tree paths instead of one array

## Problem Model And Notation

Assume an array:

$$
a_0, a_1, \dots, a_{n-1}
$$

The canonical Beats lane supports:

- `chmin(l, r, x)`: set each `a[i] = min(a[i], x)` on `[l, r)`
- `chmax(l, r, x)`: set each `a[i] = max(a[i], x)` on `[l, r)`
- `add(l, r, delta)`: set each `a[i] += delta` on `[l, r)`
- `sum(l, r)`: sum on `[l, r)`

For one node interval `[L, R)`, the exact summaries we care about are:

- `sum`
- `max1` = largest value in the segment
- `max2` = strict second largest value in the segment
- `maxc` = count of values equal to `max1`
- `min1` = smallest value in the segment
- `min2` = strict second smallest value in the segment
- `minc` = count of values equal to `min1`
- `add` = one pending additive lazy tag

The invariant is:

```text
the node summaries describe the true multiset of values in that segment
after all already-applied operations on this node
```

This is stronger than plain lazy segment tree, because we are not storing just one aggregate and one tag. We are storing the exact information needed to know whether only the current maxima or minima will change.

## From Lazy Propagation To Beats

### Why Ordinary Lazy Tags Fail

For `range add + range sum`, one covered node can absorb the update:

$$
\text{sum} \leftarrow \text{sum} + \delta \cdot (R-L)
$$

and one additive tag is enough for the children later.

For `range chmin(l, r, x)`, there is no similarly small tag in general.

If a segment contains:

$$
[9, 8, 2, 2]
$$

and we apply `chmin(..., 7)`, only the `9` and `8` change.  
If the segment contains:

$$
[9, 2, 2, 2]
$$

only the `9` changes.

So the update effect depends on how many elements are currently maximal and what the next-largest value is. One plain lazy tag cannot summarize that blindly.

### The Beats Idea

Instead of demanding:

```text
full cover => always stop
```

we use two tests.

For `range_chmin(..., x)` on one node:

- **break condition:** `max1 <= x`
- **tag condition:** `max2 < x < max1`

If the break condition holds, nothing changes.

If the tag condition holds, only the values equal to `max1` are affected, because everything else is already `< x`.

Then we can update the node in `O(1)`:

$$
\text{sum} \leftarrow \text{sum} + (x - \text{max1}) \cdot \text{maxc}
$$

and change the node's maximal summaries accordingly.

If neither condition holds, we must push and recurse.

The symmetric tests for `range_chmax(..., x)` are:

- **break condition:** `min1 >= x`
- **tag condition:** `min1 < x < min2`

This is why the technique is called "Beats": the full-cover shortcut becomes conditional on a stronger structural test.

## Core Invariant And Why It Works

## 1. Why `second maximum` is enough for `chmin`

Suppose a node interval is fully covered and:

$$
\text{max2} < x < \text{max1}
$$

Then:

- every value strictly below `max1` is already `< x`
- every value equal to `max1` becomes exactly `x`

So the update changes **only the current maxima**.

That means:

$$
\text{sum} \leftarrow \text{sum} + (x - \text{max1}) \cdot \text{maxc}
$$

and:

- `max1` becomes `x`
- `max2` stays the same
- `min1 / min2` may need a small repair if the old maximum was also one of the segment minima cases

No child descent is needed.

## 2. Why `second minimum` is enough for `chmax`

The symmetric story holds for:

$$
\text{min1} < x < \text{min2}
$$

Now only the current minima change, so:

$$
\text{sum} \leftarrow \text{sum} + (x - \text{min1}) \cdot \text{minc}
$$

and the minimal summaries can be repaired in `O(1)`.

## 3. Why `add` still fits as an ordinary lazy tag

Range add shifts every value in the segment by the same amount. So all stored extrema move together:

- `max1`, `max2`, `min1`, `min2` all shift by `delta`
- `sum` shifts by `delta * len`
- `maxc` and `minc` stay the same

So `add` is the one part of the starter that is still ordinary lazy propagation.

## 4. Pushdown Rule

When recursion must continue, the parent pushes:

1. pending additive tag
2. any tighter upper cap implied by the parent maximum
3. any tighter lower cap implied by the parent minimum

The useful mental model is:

```text
children may be too optimistic about their own max/min values;
the parent summaries tell us the legal ceiling/floor they must respect
```

## 5. Pull Rule

After child recursion, recompute:

- sum
- top two maxima and count of the top maximum
- bottom two minima and count of the bottom minimum

This is an ordinary merge step, just with a richer node state.

## Complexity And Amortization Intuition

Practical contest planning:

- build: `O(n)`
- `range_sum`: `O(log n)`
- `range_add`: `O(log n)`
- `range_chmin` / `range_chmax`: amortized near-logarithmic, but with heavier constants than ordinary lazy propagation

For the repo starter, a safe mental model is:

- queries are logarithmic
- Beats updates are amortized and noticeably heavier than lazy-segtree updates
- treat them as `log^2`-ish planning cost unless the exact proof matters

Why amortization is still good:

- each time a covered node fails the tag condition, recursion only continues because the segment still has too much variation
- successful Beats updates strictly reduce some top or bottom extreme gap
- the same value cannot keep being "the unique troublesome maximum/minimum" too many times without the node summaries changing materially

You do **not** need the full formal proof to use the structure safely in contests. You do need to respect the boundary between:

- canonical Beats operations
- more exotic extensions like modulo, historic info, or GCD tracking

## Variant Chooser

| Situation | Preferred route |
| --- | --- |
| point updates + range aggregates | [Segment Tree](../segment-tree/README.md) |
| range add / assign with one closed-form tag family | [Lazy Segment Tree](../lazy-segment-tree/README.md) |
| range `chmin` / `chmax` / `add` + range sum | Segment Tree Beats |
| one special pruning family like `range modulo + sum` | beats-like custom tree; compare against this topic, but do not assume the starter fits |
| tree paths or subtrees | flatten / decompose first, then ask whether lazy or beats is the right second layer |

## Worked Example

Start with:

$$
[5, 1, 7, 3]
$$

Apply:

1. `chmin(0, 4, 4)`  
   result:

$$
[4, 1, 4, 3]
$$

Only the old maxima `7` changed.

2. `add(1, 3, 2)`  
   result:

$$
[4, 3, 6, 3]
$$

3. `chmax(0, 2, 5)`  
   result:

$$
[5, 5, 6, 3]
$$

Now:

$$
\text{sum}(0, 4) = 19,\quad \text{sum}(1, 3) = 11
$$

This exact trace is what the repo starter demo prints.

## Implementation Notes

- Use half-open intervals `[l, r)` internally.
- Keep `max2 = -INF` and `min2 = +INF` on a leaf.
- `range_chmin` should stop early if `max1 <= x`.
- `range_chmax` should stop early if `min1 >= x`.
- Do not call the `O(1)` node update unless the strict second-extremum condition holds.
- The repo starter is for:
  - `range chmin`
  - `range chmax`
  - `range add`
  - `range sum`
- It does **not** advertise:
  - range modulo
  - historic maxima/minima/sums
  - GCD-enhanced beats
  - tree-path beats

## Pitfalls

- forgetting that `max2` and `min2` are **strict** second extrema
- confusing "parent summary says child must be capped" with ordinary lazy tags
- overclaiming complexity as if this were the same simplicity level as range-add lazy propagation
- using this structure when one simpler route already fits
- mixing min-lane and max-lane repairs when a node collapses to one single value

## Reopen Paths

- simpler online range updates -> [Lazy Segment Tree](../lazy-segment-tree/README.md)
- ordinary point-update range queries -> [Segment Tree](../segment-tree/README.md)
- compact retrieval page -> [Segment Tree Beats hot sheet](../../../notebook/segment-tree-beats-hot-sheet.md)
- exact starter route -> [Template Library](../../../template-library.md)
- flagship verifier note -> [Range Chmin Chmax Add Range Sum](../../../practice/ladders/data-structures/segment-tree-beats/rangechminchmaxaddrangesum.md)

## References

- [A simple introduction to Segment Tree Beats](https://codeforces.com/blog/entry/57319)
- [Library Checker: Range Chmin Chmax Add Range Sum](https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum)
- [Segment Tree Beats ACL-based reference](https://hitonanode.github.io/cplib-cpp/segmenttree/acl_beats.hpp.html)
