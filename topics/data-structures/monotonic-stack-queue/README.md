# Monotonic Stack / Queue

Monotonic stacks and queues are the bridge between raw linear scans and the
moment you realize every element only needs to survive until a stronger witness
kills it.

This family is about one recurring idea:

- maintain a deque or stack whose order is chosen to preserve exactly the
  candidates that can still matter later

## At A Glance

- **Use when:** the problem asks for next greater/smaller, previous greater/smaller, span lengths, histogram ranges, or sliding-window min/max
- **Core worldview:** every element is pushed once and popped once because domination is permanent
- **Main tools:** decreasing stack, increasing stack, deque for fixed-width windows
- **Typical complexity:** `O(n)` because each element enters and leaves the structure at most once
- **Main trap:** reaching for segment tree or multiset before checking whether domination is monotone and one linear pass is enough

Strong contest signals:

- nearest greater / smaller element
- "for each index, find the first index to the left/right with property..."
- maximum/minimum over every fixed-length window
- histogram / rectangle expansion where boundaries are set by the first smaller bar

Strong anti-cues:

- updates happen online after the scan starts
- the window is not monotone and candidates can become relevant again later
- the query family is arbitrary enough that a real range data structure is needed

## Prerequisites

- [Two Pointers](../../foundations/patterns/two-pointers/README.md)
- [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md)

Helpful neighboring topics:

- [Sliding Window ladder](../../../practice/ladders/dp/sliding-window/README.md)
- [Sparse Table](../sparse-table/README.md)
- [Segment Tree](../segment-tree/README.md)

## Problem Model And Notation

The stack/queue stores indices, not just values.

That matters because the statement usually needs:

- distance
- boundary
- width
- or a window-expiration check

The value order gives the monotonic invariant.

The indices give the geometry of the answer.

## From Brute Force To The Right Idea

### Brute Force: Re-scan Neighbors Or Recompute Window Extrema

A beginner often does:

- for every index, scan left until the answer appears
- for every window, recompute min/max from scratch

That becomes quadratic.

### The First Shift: Domination Is Permanent

Suppose you want a decreasing deque for sliding-window maximums.

If a new value `a[i]` is at least as large as the old tail `a[j]`, then `j`
can never be the maximum of any future window that also contains `i`.

So `j` may be popped permanently.

That one observation is the whole family.

### The Second Shift: Pop Rules Encode The Invariant

Monotonic structures are not magic containers.

They are ordinary stacks/deques plus one deterministic pop rule:

- while the new element dominates the tail, pop

Once the pop rule is correct, the `O(n)` bound follows naturally because each
index dies only once.

## Core Invariants And Why They Work

### 1. Value Order Is Monotone Inside The Structure

Examples:

- increasing stack for nearest smaller
- decreasing deque for window maximum

That invariant is maintained only by the pop rule.

### 2. Expired Indices Leave From The Front

For fixed-width windows, the left boundary moves monotonically.

So any index that falls out of the window can be removed from the front once and
never return.

### 3. Each Index Is Pushed Once And Popped Once

This is the amortized proof.

Even if one step pops many elements, each popped index disappears forever.

So the total number of pop operations across the whole scan is `O(n)`.

## Variant Chooser

### Use A Monotonic Stack When

- you need nearest boundary information
- indices are answered once and never reactivated

### Use A Monotonic Queue / Deque When

- the structure represents one moving window
- expired items leave from the front

### Use Ordered Sets Or Heaps Instead When

- the active set changes online in a non-monotone way
- an element may need to become relevant again later

### Use Segment Tree / Sparse Table Instead When

- the queries are arbitrary intervals, not one structured scan

## Repo Anchors And Compare Points

- [Monotonic Stack / Queue ladder](../../../practice/ladders/data-structures/monotonic-stack-queue/README.md)
- [Monotonic Stack / Queue hot sheet](../../../notebook/monotonic-stack-queue-hot-sheet.md)
- [Nearest Smaller Values](../../../practice/ladders/data-structures/monotonic-stack-queue/nearestsmallervalues.md)
- [monotonic-stack-nearest-smaller.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/monotonic-stack-nearest-smaller.cpp)
- [monotonic-deque-min.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/monotonic-deque-min.cpp)
- [Two Pointers](../../foundations/patterns/two-pointers/README.md)
- [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md)
- [Sliding Window ladder](../../../practice/ladders/dp/sliding-window/README.md)

## Sources

- Reference: [CP-Algorithms - Minimum stack / minimum queue](https://cp-algorithms.com/data_structures/stack_queue_modification.html)
- Reference: [Competitive Programmer's Handbook](https://www.cses.fi/book/book.pdf)
- Practice: [CSES Problem Set](https://cses.fi/problemset/)
