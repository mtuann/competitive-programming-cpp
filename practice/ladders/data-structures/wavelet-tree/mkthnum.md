# MKTHNUM - K-th Number

- Title: `MKTHNUM - K-th Number`
- Judge / source: `SPOJ`
- Original URL: [https://www.spoj.com/problems/MKTHNUM/](https://www.spoj.com/problems/MKTHNUM/)
- Secondary topics: `Wavelet tree`, `Static order statistics`, `Coordinate compression`
- Difficulty: `hard`
- Subtype: `Static subarray k-th smallest queries`
- Status: `solved`
- Solution file: [mkthnum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/wavelet-tree/mkthnum.cpp)

## Why Practice This

This is the cleanest first anchor for the Wavelet Tree lane.

The statement gives exactly the right signal:

- the array is static
- each query asks for the k-th smallest value in one subarray
- values can be large, but only relative order matters

So the real lesson is:

- compress values
- build one value-partition tree
- use prefix-left counts to translate the queried interval down that tree

## Recognition Cue

Reach for a wavelet tree when:

- the array never changes after input
- queries ask about value order inside one position interval
- the answer is something like `k-th`, `<= x`, or exact frequency by value
- persistent segment tree feels plausible, but version roots are not the story the statement is telling

The strongest smell here is:

- "What is the k-th number in `a[i..j]` if this segment were sorted?"

## Problem-Specific Transformation

Compress the array values into ranks:

```text
0 .. sigma - 1
```

Build one wavelet tree over the whole static array.

Then each query:

```text
Q(i, j, k)
```

becomes:

```text
kth_smallest(i - 1, j, k - 1)
```

because:

- the statement is one-based inclusive
- the starter is zero-based half-open
- the starter uses zero-based `k`

So the problem is no longer:

- sort each subarray

It becomes:

- descend the same static value-partition tree and keep rewriting the node-local range

## Core Idea

Each wavelet-tree node stores:

- one compressed value interval `[lo, hi]`
- a prefix vector `pref`

where:

```text
pref[t] = among the first t elements of this node's subsequence,
          how many go to the left child
```

For a queried node-local interval `[l, r)`:

- left child interval = `[pref[l], pref[r))`
- right child interval = `[l - pref[l], r - pref[r))`

If `left_count = pref[r] - pref[l]`, then:

- go left when `k < left_count`
- otherwise go right with `k -= left_count`

At a leaf, the compressed rank maps back to the original array value.

The important invariant is:

```text
at every level, [l, r) means the queried slice inside the current node subsequence,
not inside the original array
```

## Complexity

For `n` values, `m` queries, and `sigma` distinct values:

- build: `O(n log sigma)`
- each query: `O(log sigma)`
- memory: `O(n log sigma)`

This is easily fast enough for `MKTHNUM`.

## Pitfalls / Judge Notes

- The statement uses one-based inclusive intervals.
- `k` in the statement is one-based; convert it once.
- Do not mix original positions with node-local positions after one descent.
- Coordinate compression is mandatory in practice because raw values can be as large as `10^9`.
- `MKTHNUM` says all numbers are distinct, but the starter itself also supports duplicates.

## Reusable Pattern

- Topic page: [Wavelet Tree](../../../../topics/data-structures/wavelet-tree/README.md)
- Practice ladder: [Wavelet Tree ladder](README.md)
- Starter template: [wavelet-tree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/wavelet-tree.cpp)
- Notebook refresher: [Wavelet Tree hot sheet](../../../../notebook/wavelet-tree-hot-sheet.md)
- Compare points:
  - [Persistent Data Structures](../../../../topics/data-structures/persistent-data-structures/README.md)
  - [Mo's Algorithm](../../../../topics/data-structures/mos-algorithm/README.md)
- This note adds: the first exact static subarray order-statistics route where position intervals are translated through value splits rather than through version roots.

## Solutions

- Code: [mkthnum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/wavelet-tree/mkthnum.cpp)
