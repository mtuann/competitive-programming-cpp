# Parallel Prefix Sum Benchmark

- Title: `Parallel Prefix Sum Benchmark`
- Judge / source: `Canonical parallel scan benchmark`
- Original URL: [https://www.cs.cmu.edu/afs/cs/academic/class/15451-s14/www/LectureNotes/PrefixSumBlelloch.pdf](https://www.cs.cmu.edu/afs/cs/academic/class/15451-s14/www/LectureNotes/PrefixSumBlelloch.pdf)
- Secondary topics: `Blelloch scan`, `Work / span`, `PRAM`
- Difficulty: `medium`
- Subtype: `Simulator-first exclusive prefix-sum benchmark through a work-efficient parallel scan tree`
- Status: `solved`
- Solution file: [parallelprefixsum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/parallel-algorithms/parallelprefixsum.cpp)

## Why Practice This

This is the cleanest first in-repo anchor for `Parallel Algorithms`.

The benchmark is intentionally narrow:

- one array
- one associative operator
- one exclusive scan
- one work-efficient tree pattern
- one sequential simulator for a parallel structure

So the whole lesson is exactly the lane itself:

- what `work` and `span` mean
- why scan is a canonical parallel primitive
- how the up-sweep / down-sweep route works

## Recognition Cue

Reach for this route when:

- the benchmark explicitly mentions `parallel prefix sum` or `scan`
- the teaching goal is `work O(n), span O(log n)`
- the route wants a simulator-preserving tree structure rather than a left-to-right cumulative loop

The strongest smell is:

```text
I want one honest parallel-algorithms breadth benchmark, not a full threading stack.
```

That is exactly this note.

## Problem-Specific Route

This repo's benchmark uses:

- one integer `n`
- one array `a[0..n-1]`
- one additive monoid with identity `0`

The route is:

1. pad the array to the next power of two
2. run the up-sweep to compute subtree sums
3. replace the root value with `0`
4. run the down-sweep to distribute prefixes
5. output the first `n` leaves as the **exclusive** scan

This is exactly the Blelloch work-efficient scan route in simulator form.

## Core Idea

The first route is not about "prefix sums are cumulative."

It is about:

- restructuring the sum as a tree
- keeping total work linear
- keeping the longest dependency chain logarithmic

### 1. Up-Sweep

Build partial sums bottom-up.

After this phase, the root stores the sum of the whole padded array.

### 2. Root Reset

Replace the root with the identity element `0`.

This is what turns the route into an **exclusive** scan.

### 3. Down-Sweep

Push prefix information back down:

- left child inherits the parent's prefix
- right child inherits `parent_prefix + left_subtree_sum`

The leaves then hold the exclusive scan values.

## Worked Example

For:

```text
3 1 7 0 4 1 6 3
```

the benchmark prints:

```text
0 3 4 11 11 15 16 22
```

That is:

- before `3` -> `0`
- before `1` -> `3`
- before `7` -> `4`
- and so on

## Complexity

For input length `n` and padded size `m`:

- intended parallel work = `O(m)`
- intended parallel span = `O(log m)`
- sequential simulator runtime = `O(m)`

The benchmark is breadth-first, not wall-clock-performance-first.

## Input / Output Contract For This Repo

This repo's benchmark uses:

- one integer `n`
- one line with `n` integers

The solution prints one line with the **exclusive** scan array.

This is a repo-native benchmark, not one standard online judge task.

## Pitfalls / Judge Notes

- The route is about **exclusive** scan, not inclusive scan.
- The operator is fixed to addition on this exact starter route.
- The benchmark is simulator-first and does not claim practical multicore speedup.
- Padding with identities is part of the clean tree model.
- This note does not stand in for GPU programming, OpenMP, or general concurrent algorithms.

## Reusable Pattern

- Topic page: [Parallel Algorithms](../../../../topics/advanced/parallel-algorithms/README.md)
- Practice ladder: [Parallel Algorithms ladder](README.md)
- Starter template: [blelloch-exclusive-scan.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/advanced/blelloch-exclusive-scan.cpp)
- Notebook refresher: [Parallel Algorithms hot sheet](../../../../notebook/parallel-algorithms-hot-sheet.md)
- Compare points:
  - [Prefix Sums](../../../../topics/foundations/patterns/prefix-sums/README.md)
  - [Bit-Parallelism / Bitset Optimization](../../../../topics/dp/bit-parallelism/README.md)

## Solutions

- Code: [parallelprefixsum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/parallel-algorithms/parallelprefixsum.cpp)
