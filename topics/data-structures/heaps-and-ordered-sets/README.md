# Heaps And Ordered Sets

These are the “lightweight dynamic structure” tools you reach for before segment trees: `priority_queue`, `set`, `multiset`, and sometimes PBDS.

## Prerequisites

- [C++ Language For Contests](../../foundations/cpp-language/README.md)
- [Sorting](../../foundations/patterns/sorting/README.md)

## When To Suspect It

- you only need the current minimum or maximum
- you need to maintain an active ordered set of values or intervals
- you need insert / erase / predecessor / successor

## Core Idea

- `priority_queue`: best when you only care about one extremum
- `set` / `multiset`: best when order inside the active set matters

Think in terms of operations first:

- top only?
- insert / erase?
- predecessor / successor?
- duplicates?

## Theory / Proof Sketch

There is no deep correctness theorem here beyond choosing the right invariant:

- the heap top is always the best remaining candidate
- the ordered set always contains the active values in sorted order

## Complexity And Tradeoffs

- heap push / pop: `O(log n)`
- `set` insert / erase / find: `O(log n)`

Tradeoffs:

- heap is smaller and simpler
- set gives richer ordered queries
- lazy deletion is often simpler than deleting from a heap directly

## Canonical Pattern

Template in this repo:

- [heap-lazy-delete.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/heap-lazy-delete.cpp)

## Worked Examples

Example 1: always take the next best task

Example 2: maintain active intervals in sweep line

Example 3: sliding median with two multisets or heaps

## Common Mistakes

- using a set when only heap top is needed
- forgetting that `priority_queue` cannot remove arbitrary stale values cleanly without extra bookkeeping
- using `set` instead of `multiset` when duplicates matter

## Practice Ladder

- [Heaps and ordered sets ladder](../../../practice/ladders/data-structures/heaps-and-ordered-sets/README.md)

## Go Deeper

- Reference: [CPPReference](https://en.cppreference.com/w/)
- Practice: [CSES Sorting and Searching](https://cses.fi/problemset/)

## Related Topics

- [Sorting](../../foundations/patterns/sorting/README.md)
- [Offline Tricks](../offline-tricks/README.md)
