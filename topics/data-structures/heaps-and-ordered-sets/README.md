# Heaps And Ordered Sets

These are the lightweight dynamic structures you should reach for before segment trees: `priority_queue`, `set`, `multiset`, and occasionally policy-based ordered sets. They solve many “active set” problems with far less code than a heavy structure.

## Summary

Suspect heaps or ordered sets when:

- you only need the current minimum or maximum
- you need insert / erase over a changing active set
- predecessor / successor or sorted active order matters
- duplicates may or may not matter, and that choice affects the structure

What success looks like:

- you choose the structure from operations, not habit
- you know when lazy deletion is simpler than true heap deletion
- you can explain why `set`, `multiset`, and `priority_queue` differ in power

## Prerequisites

- [C++ Language For Contests](../../foundations/cpp-language/README.md)
- [Sorting](../../foundations/patterns/sorting/README.md)

## Core Idea

Think in terms of operations first:

- do I only need the best current candidate?
- do I need predecessor / successor?
- do duplicates matter?
- do stale values appear naturally?

Structure choices:

- `priority_queue`: best when only the current extremum matters
- `set`: ordered distinct active values
- `multiset`: ordered active values with duplicates
- PBDS / order-statistics tree: when you need rank or k-th order queries online

## Theory / Proof Sketch

There is no single deep theorem here. The key invariant is representation-based:

- the heap top is always the best remaining candidate under the chosen order
- the ordered set always contains the active values in sorted order

If your active set invariant is right, the operations become direct consequences of the container.

## Complexity And Tradeoffs

- heap push / pop: `O(log n)`
- `set` / `multiset` insert / erase / find: `O(log n)`
- predecessor / successor via iterators: `O(log n)` to locate

Tradeoffs:

- heaps are simpler and smaller
- sets are richer
- `multiset` is necessary when duplicates matter
- lazy deletion often beats trying to force arbitrary erase behavior into a heap

## Canonical C++ Pattern

Template in this repo:

- [heap-lazy-delete.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/heap-lazy-delete.cpp)

Practical rules:

- use `priority_queue` for repeated “take best next”
- use `set` / `multiset` for active intervals or dynamic ordered values
- if heap values become stale, mark-and-skip is often easier than removing them immediately

## Standard Patterns

### 1. Always Take The Best Current Item

Examples:

- scheduling
- greedy resource allocation
- repeatedly process smallest / largest available event

### 2. Active Ordered Set

Examples:

- sweep-line active intervals
- maintain the current window values in sorted order
- predecessor / successor lookups

### 3. Sliding Median / Two-Structure Maintenance

Often solved with:

- two heaps
- or two multisets

The point is to keep one part for the smaller half and one for the larger half.

## Worked Examples

### Example 1: task scheduling with a heap

At each step:

- push newly available tasks
- pop the current best one

This works because only the best active candidate matters.

### Example 2: active interval set

During a sweep:

- add interval when it starts
- remove it when it ends
- query predecessor / successor or min / max among current intervals

This is set territory, not heap territory.

### Example 3: sliding median

You need:

- insert
- erase
- access to the “middle”

That usually pushes you toward two multisets or a more specialized ordered-statistics structure.

## Recognition Cues

Strong clues:

- “current smallest / largest”
- active values change over time
- predecessor, successor, or closest active value
- duplicates affect correctness

These tools are often confused with:

- [Sorting](../../foundations/patterns/sorting/README.md), which is static
- [Offline Tricks](../offline-tricks/README.md), because offline sorting can sometimes replace a dynamic active structure

## Common Mistakes

- using a set when only heap top is needed
- forgetting that `priority_queue` cannot remove arbitrary stale values cleanly without bookkeeping
- using `set` instead of `multiset` when duplicates matter
- overengineering with PBDS when heap or multiset is enough

## Practice Ladder

- [Heaps and ordered sets ladder](../../../practice/ladders/data-structures/heaps-and-ordered-sets/README.md)

Suggested order:

1. heap-based scheduling
2. min/max active values
3. ordered set predecessor / successor
4. sliding median or similar dual-structure maintenance

## Go Deeper

- Reference: [CPPReference](https://en.cppreference.com/w/)
- Practice: [CSES Sorting and Searching](https://cses.fi/problemset/)
- Practice: [USACO Guide](https://usaco.guide/)

## Related Topics

- [Sorting](../../foundations/patterns/sorting/README.md)
- [Offline Tricks](../offline-tricks/README.md)
- [Sweep Line](../../geometry/sweep-line/README.md)
