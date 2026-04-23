# Binary Search

Binary search is not just “find a value in a sorted array.” In contests, the deeper pattern is maintaining a monotone predicate and shrinking the answer interval without losing the true answer.

## Prerequisites

- [Reasoning And Implementation Discipline](../../reasoning/README.md)
- [Sorting](../sorting/README.md)

## When To Suspect It

- the answer lies in an ordered numeric range
- the statement asks for the minimum or maximum feasible value
- a predicate changes only once from false to true
- `O(n)` checking is easy but brute-forcing all answers is too slow

## Core Idea

Use binary search only after you define:

1. the search space
2. a monotone predicate
3. a clean boundary convention

The standard invariant is:

```text
l is a known bad state
r is a known good state
The answer stays in the interval (l, r]
```

## Theory / Proof Sketch

At each step:

- pick `mid`
- test whether `mid` is good
- keep the half that still contains the answer

The invariant guarantees correctness; the shrinking interval guarantees termination.

## Complexity And Tradeoffs

- one check costs `T`
- binary search costs `O(T log range)`

Tradeoffs:

- if the data is already sorted, `lower_bound` or `upper_bound` may be simpler
- answer-search is only valid if the predicate is monotone

## Canonical C++ Pattern

Templates in this repo:

- [binary-search-first-true.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/binary-search-first-true.cpp)
- [binary-search-last-false.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/binary-search-last-false.cpp)

Useful checklist:

- does `mid` round the way I want?
- do I update `l` and `r` without getting stuck?
- did I choose inclusive or half-open bounds on purpose?

## Worked Examples

Example 1: first position `>= x`

- use `lower_bound`
- or write the first-true form yourself

Example 2: minimum time to finish `k` tasks

- predicate: “can finish at least `k` tasks within time `t`”
- the predicate is monotone in `t`

Example 3: longest feasible answer

- flip the viewpoint and search for the last false or last true state carefully

## Common Mistakes

- no monotone predicate
- inconsistent boundary meaning
- integer overflow in `mid`
- stopping with `while (l <= r)` but not knowing what the final answer means

## Practice Ladder

- [Binary search ladder](../../../../practice/ladders/foundations/binary-search/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Binary Search](https://cp-algorithms.com/num_methods/binary_search.html)
- Practice: [USACO Guide - Binary Search](https://usaco.guide/silver/binary-search)
- Practice: [CSES Problem Set](https://cses.fi/problemset/)

## Related Topics

- [Sorting](../sorting/README.md)
- [Prefix Sums](../prefix-sums/README.md)
- [Shortest Paths](../../../graphs/shortest-paths/README.md)
