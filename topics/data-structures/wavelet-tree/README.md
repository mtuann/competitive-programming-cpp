# Wavelet Tree

Wavelet Tree is the static range-query lane for questions like:

- k-th smallest in `a[l:r)`
- how many values in `a[l:r)` are `<= x`
- how many values in `a[l:r)` are exactly `x`

The key promise is:

```text
the array never changes
but the query depends on both
- position interval [l, r)
- value order inside that interval
```

That is where prefix sums, sparse table, and ordinary segment tree summaries start feeling awkward.

A Wavelet Tree answers these value-sensitive range queries by storing, at each value-partition node, a prefix map that tells us how the current subsequence splits into the left and right children.

## At A Glance

- **Use when:** one static array gets many subarray order-statistics or value-count queries
- **Core worldview:** every node represents one value interval and one subsequence of the array, preserving original order inside that subsequence
- **Main tools:** coordinate compression, value-range recursion, `pref[i] = how many of the first i elements go left`
- **Typical complexity:** `O(n log sigma)` build, `O(log sigma)` query
- **Main trap:** forgetting that as you descend, `l` and `r` stop meaning positions in the original array and become positions inside the current node subsequence

Strong contest signals:

- "k-th smallest in subarray"
- "count numbers `<= x` in subarray"
- static array, many queries, no updates
- persistent segment tree would work too, but the statement does not need versioning

Strong anti-cues:

- updates happen between queries -> reopen [Persistent Data Structures](../persistent-data-structures/README.md), [Mo's Algorithm](../mos-algorithm/README.md), or a segment-tree lane instead
- the query is only static RMQ / min / gcd -> [Sparse Table](../sparse-table/README.md)
- one monotone sweep or right-endpoint offline pass already solves it -> [Offline Tricks](../offline-tricks/README.md)
- the answer is not value-sensitive at all, only aggregate-sensitive

## Prerequisites

- [Coordinate Compression](../../foundations/patterns/sorting/README.md)
- [Segment Tree](../segment-tree/README.md) for the "recursive value partition" mental model
- [Persistent Data Structures](../persistent-data-structures/README.md) as the best compare point for static range order statistics

Helpful neighbors:

- [Mo's Algorithm](../mos-algorithm/README.md) when the real invariant is "one current active interval" rather than value splitting
- [Offline Tricks](../offline-tricks/README.md) when queries are reorderable enough that a lighter sweep wins

## Problem Model And Notation

Let:

$$
a_0, a_1, \dots, a_{n-1}
$$

be a **static** array.

We will use zero-based half-open interval notation:

$$
[l, r)
$$

for the queried subarray.

The starter in this repo supports:

- `kth_smallest(l, r, k)` with `k` zero-based
- `count_leq(l, r, x)`
- `count_equal(l, r, x)`

Internally:

1. coordinate-compress the values
2. build a binary recursion over the compressed value range
3. at each node, store a prefix-count vector:

```text
pref[i] = among the first i elements of this node's subsequence,
          how many map to the left child
```

That one vector is the whole translation mechanism.

## From Brute Force To The Right Idea

### Brute Force

For one query `k-th smallest on a[l:r)`, the obvious route is:

1. copy the subarray
2. sort it
3. read the answer

That costs:

$$
O((r-l)\log(r-l))
$$

per query, which is too slow for heavy query sets.

### A Compare Point: Persistent Segment Tree

A persistent segment tree can answer the same order-statistics family by comparing two version roots:

- prefix root up to `r`
- prefix root up to `l`

That route is excellent when the teaching goal is:

- versions
- path copying
- prefix-root subtraction

But if the array is just static and the job is only "query by position interval and value rank", the persistent route is not the lightest mental model.

### The Structural Observation

Suppose we split the compressed value domain into:

$$
[lo, mid] \quad \text{and} \quad [mid+1, hi]
$$

At one node, consider the subsequence of array elements whose values belong to `[lo, hi]`.

For a range query `[l, r)` on that subsequence, the next question is:

```text
how many of those queried elements belong to the left child?
```

If we know that count quickly, then:

- `k-th smallest` knows whether to go left or right
- `count <= x` knows whether to prune or recurse
- `count == x` knows which unique value branch to follow

So the only real problem is:

```text
fast translation of one current [l, r)
into child-local intervals
```

### The Wavelet Tree Trick

Store, at every node:

```text
pref[i] = count of left-child elements among the first i elements
```

Then:

- left child interval becomes:

$$
[pref[l], pref[r))
$$

- right child interval becomes:

$$
[l - pref[l],\ r - pref[r))
$$

That is why queries drop to `O(log sigma)`: each level uses one `O(1)` translation.

## Core Invariant And Why It Works

## 1. Node Meaning

Each node represents:

- one compressed value interval `[lo, hi]`
- one subsequence containing exactly the array elements whose values lie in that interval
- original order preserved inside that subsequence

Preserving order is essential, because range queries are position-based.

## 2. Prefix-Left Meaning

At one node:

```text
pref[i] = number of first i subsequence elements that go to the left child
```

So for any queried node-local interval `[l, r)`:

- `pref[r] - pref[l]` = how many queried elements continue into the left child
- the rest continue into the right child

## 3. Why Range Translation Is Correct

The left child subsequence is exactly the stable filter:

```text
keep only elements whose compressed value is in the left value interval
```

So among the first `l` elements of the current subsequence, exactly `pref[l]` survive into the left child.

That makes the left child range:

$$
[pref[l], pref[r))
$$

The right child range is what remains after removing those left-going elements.

## 4. Why `k-th smallest` Works

At a node, let:

$$
cnt_L = pref[r] - pref[l]
$$

If `k < cnt_L`, then the answer lies in the left child.

Otherwise, the answer lies in the right child, and inside that child it becomes:

$$
k - cnt_L
$$

So every level peels off exactly the left-side rank mass and continues.

## 5. Why `count_leq` Works

If the node value interval is fully above `x`, contribute `0`.

If the node value interval is fully below or equal to `x`, contribute the whole range length:

$$
r - l
$$

Otherwise recurse, using the same translated child ranges.

That is the same invariant as segment-tree pruning, except the dimension is:

- value interval

while the query range remains:

- position interval within the current subsequence

## Worked Example

Take:

$$
a = [1, 5, 2, 6, 3, 7, 4]
$$

and query:

```text
Q(2, 5, 3)
```

meaning:

- one-based inclusive interval `[2, 5]`
- third smallest element

Convert to the starter convention:

- interval `[1, 5)`
- `k = 2` zero-based

The queried subarray is:

$$
[5, 2, 6, 3]
$$

whose sorted order is:

$$
[2, 3, 5, 6]
$$

so the answer should be `5`.

At the root, split the value ranks into:

- left half = smaller values
- right half = larger values

Inside `[5, 2, 6, 3]`, exactly two values go left:

$$
[2, 3]
$$

So:

- `cnt_L = 2`
- `k = 2`

Since `k` is **not** `< 2`, the answer is in the right child, and the new rank is:

$$
2 - 2 = 0
$$

The right-child subsequence for this query is:

$$
[5, 6]
$$

At the next split, only `5` goes left, so:

- left count = `1`
- `k = 0`

Now `k < 1`, so descend left and reach the leaf for value `5`.

That is the whole algorithm:

- count how many queried elements go left
- rewrite the interval
- keep the correct child-local rank

## Algorithm And Pseudocode

### Build

```text
build(node, values_in_this_subsequence, lo, hi):
    store node value interval [lo, hi]
    pref[0] = 0

    if lo == hi:
        fill pref as 0, 1, 2, ..., len
        return

    mid = (lo + hi) / 2
    left_values = []
    right_values = []

    for value in values_in_this_subsequence:
        if value <= mid:
            left_values.push(value)
            pref.push_back(pref.back() + 1)
        else:
            right_values.push(value)
            pref.push_back(pref.back())

    build(left child, left_values, lo, mid)
    build(right child, right_values, mid + 1, hi)
```

### K-th Smallest

```text
kth(node, l, r, k):
    if node is a leaf:
        return node value

    left_l = pref[l]
    left_r = pref[r]
    left_count = left_r - left_l

    if k < left_count:
        return kth(left child, left_l, left_r, k)

    right_l = l - left_l
    right_r = r - left_r
    return kth(right child, right_l, right_r, k - left_count)
```

### Count `<= x`

```text
count_leq(node, l, r, x_rank):
    if [node.lo, node.hi] is fully above x_rank:
        return 0
    if [node.lo, node.hi] is fully inside <= x_rank:
        return r - l

    translate [l, r) into children using pref
    recurse only where needed
```

## Variant Chooser

### Use The Repo Starter Exactly When

- the array is static
- queries are online or arbitrary-order, but updates never happen
- you need order statistics or value-count queries on subarrays
- coordinate compression is acceptable

This is the exact lane for:

- [MKTHNUM - K-th Number](../../../practice/ladders/data-structures/wavelet-tree/mkthnum.md)

### Prefer Persistent Segment Tree When

- the teaching goal is really prefix-root subtraction
- you need the stronger compare point for versioned structures
- the problem family naturally talks about snapshots or version roots

Persistent segment tree and wavelet tree often solve similar static order-statistics tasks. The question is:

- do you want **value partition with prefix-left maps**
- or **version roots with path copying**

### Prefer Mo / Offline Tricks When

- the answer is maintained by local `add/remove` of one active window
- or one monotone sweep already kills the problem

Those lanes are about:

- reordering queries

Wavelet tree is about:

- prebuilding a value-sensitive query structure

### Reopen The Topic Before Reusing The Starter When

- updates appear
- the task wants a wavelet **matrix** or compressed bitvector engineering for tighter memory/constants
- the task becomes 2D or geometric
- you need richer queries than the starter advertises

## Implementation Notes

### 1. Compress Values First

The starter compresses values automatically.

That keeps the recursion depth tied to:

- number of distinct values

rather than raw magnitude like `10^9`.

### 2. Internal `[l, r)` Is Node-Local

This is the main source of bugs.

After one descent, `[l, r)` no longer indexes the original array. It indexes:

- the subsequence stored at the current node

### 3. Decide `k` Convention Once

The starter uses:

- zero-based `k`

Many judge statements use:

- one-based `k`

Convert exactly once at the call site.

### 4. Static Means Static

This starter does **not** support:

- point updates
- swaps
- dynamic insert / erase

If updates appear, reopen the lane choice.

### 5. Wavelet Tree vs Wavelet Matrix

This repo ships the classical recursive wavelet-tree starter because it is the cleanest first learning route.

If later you need:

- better constants
- packed bitvector engineering
- stronger low-memory static queries

the next compare point is:

- wavelet matrix

not "stretch this starter until it hurts."

## Practice Archetypes

### First Rep In This Repo

- [MKTHNUM - K-th Number](../../../practice/ladders/data-structures/wavelet-tree/mkthnum.md)

### Best Compare Point In This Repo

- [Persistent Data Structures](../persistent-data-structures/README.md)

### Good External Follow-Ups

- [SPOJ - KQUERY](https://www.spoj.com/problems/KQUERY/)
- [Library Checker - Range K-th Smallest](https://judge.yosupo.jp/problem/range_kth_smallest)
- [Library Checker - Static Range Frequency](https://judge.yosupo.jp/problem/static_range_frequency)

## References

- [USACO Guide: Wavelet Tree](https://usaco.guide/adv/wavelet?lang=java)
- [IOI Journal: Wavelet Trees for Competitive Programming](https://ioinformatics.org/files/volume10.pdf)
- [SPOJ - MKTHNUM](https://www.spoj.com/problems/MKTHNUM/)

## Repo Anchors

- [Wavelet Tree ladder](../../../practice/ladders/data-structures/wavelet-tree/README.md)
- [Wavelet Tree hot sheet](../../../notebook/wavelet-tree-hot-sheet.md)
- [Exact starter template](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/wavelet-tree.cpp)
- [MKTHNUM - K-th Number](../../../practice/ladders/data-structures/wavelet-tree/mkthnum.md)
- Compare points:
  - [Persistent Data Structures](../persistent-data-structures/README.md)
  - [Mo's Algorithm](../mos-algorithm/README.md)
  - [Sparse Table](../sparse-table/README.md)
