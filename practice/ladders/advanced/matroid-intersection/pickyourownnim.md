# Pick Your Own Nim

- Title: `Pick Your Own Nim`
- Judge / source: `Codeforces Gym`
- Original URL: [https://codeforces.com/gym/102156/problem/D](https://codeforces.com/gym/102156/problem/D)
- Secondary topics: `Linear matroid`, `Partition matroid`, `XOR basis`
- Difficulty: `very-hard`
- Subtype: `Linear matroid + partition matroid via exchange-graph augmentation`
- Status: `solved`
- Solution file: [pickyourownnim.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/matroid-intersection/pickyourownnim.cpp)

## Why Practice This

This is the cleanest in-repo anchor for `Matroid Intersection` because the statement naturally becomes:

- one item from each box
- while preserving one linear-independence constraint together with Alice's fixed picks

That is exactly:

- one **partition matroid**
- intersected with one **linear matroid**

Trying to think about this as plain matching or plain xor basis leaves out half of the model.

## Recognition Cue

Reach for matroid intersection when:

- you must choose exactly one object from each group
- and the whole chosen family must stay independent in another sense

The strongest smell in this task is:

```text
one from each box, but every nonempty subset of all chosen heaps must have nonzero xor
```

## Problem-Specific Transformation

Alice's already chosen heaps are fixed.

Bob must choose one heap from each of his `m` boxes so that **for every nonempty subset** of all selected heaps, the xor is nonzero.

For Nim, a position is losing exactly when the xor is zero. So Bob wants to ensure that no nonempty subset of the chosen heaps has xor zero.

That is equivalent to:

- all chosen heap values are linearly independent over `GF(2)`

So the two matroids are:

### 1. Partition Matroid

Ground-set elements are Bob's candidate heaps.

Independent sets are those containing:

- at most one heap from each box

### 2. Linear Matroid

Independent sets are those Bob heaps that stay linearly independent **together with Alice's fixed heaps**.

If Alice's own heaps are already dependent, the answer is immediately impossible.

## Core Idea

Maintain one common independent set `I` of Bob heaps.

### 1. Partition Side Is Sparse

For one outside heap `z`:

- if its box is unused, then `z` is directly addable in the partition matroid
- if its box already has one chosen heap `y`, then the only partition-side exchange is `z -> y`

That means the `M2` side of the exchange graph is extremely cheap.

### 2. Linear Side Comes From One Basis

Build one xor basis of:

- Alice's fixed heaps
- Bob's currently chosen heaps

For an outside heap `z`:

- if `z` is outside the span, then `z` is directly addable in the linear matroid
- otherwise the reduction tells you the **fundamental circuit**

Any currently chosen Bob heap appearing in that circuit can be exchanged out for `z`.

So one linear-basis reduction gives exactly the `M1` exchange edges.

### 3. Augment In The Exchange Graph

Run BFS from:

- `Z1`: heaps directly addable on the linear side

and try to reach:

- `Z2`: heaps directly addable on the partition side

If such a path exists, toggle the path and increase the size of the current common independent set by one.

If no path exists, the current set is maximum.

Bob succeeds iff the maximum size reaches `m`.

## Implementation Plan

1. check that Alice's fixed heaps are linearly independent
2. flatten Bob's heaps into one explicit ground set with `(box_id, value)`
3. maintain the current chosen Bob set
4. for each augmentation:
   - build one xor basis of `Alice + current`
   - classify every outside element as:
     - directly addable in the linear matroid
     - or dependent with one fundamental circuit
   - use box occupancy to build the partition-side transitions
   - BFS for one shortest `Z1 -> Z2` augmenting path
5. if the final size is `m`, print the chosen heap from each box; otherwise print `-1`

## Complexity

Let `E` be the total number of Bob heaps. Here `E <= 5000` and the relevant rank is at most `60`.

The specialized route is roughly:

- at most `m <= 60` augmentations
- one `O(E * 60)` scan of linear reductions per augmentation
- plus exchange-graph BFS over the sparse partition side and the circuit-derived linear side

That is exactly why this structured route is contest-usable while a fully naive oracle implementation would be much less comfortable.

## Main Traps

- forgetting to reject the case where Alice's own heaps are already xor-dependent
- thinking Bob only needs the total xor to be nonzero, instead of **every nonempty subset**
- missing the fact that linear dependence is over `GF(2)`, not over integers
- rebuilding a full generic oracle graph when the partition side is already almost free

## Reopen Path

- Topic page: [Matroid Intersection](../../../../topics/advanced/matroid-intersection/README.md)
- Practice ladder: [Matroid Intersection ladder](README.md)
- Starter template: [matroid-intersection-oracle.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/advanced/matroid-intersection-oracle.cpp)
- Notebook refresher: [Matroid Intersection hot sheet](../../../../notebook/matroid-intersection-hot-sheet.md)
- Compare points:
  - [Optimization And Duality](../../../../topics/advanced/optimization-and-duality/README.md)
  - [Matching](../../../../topics/graphs/matching/README.md)
  - [XOR Basis / Linear Basis](../../../../topics/math/xor-basis/README.md)

## Solutions

- Code: [pickyourownnim.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/matroid-intersection/pickyourownnim.cpp)
