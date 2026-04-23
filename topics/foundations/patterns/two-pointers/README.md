# Two Pointers And Sliding Window

Two pointers turn a nested scan into a linear scan when the valid window changes monotonically.

## Prerequisites

- [Reasoning And Implementation Discipline](../../reasoning/README.md)
- [Sorting](../sorting/README.md)

## When To Suspect It

- you are scanning intervals of an array or string
- left and right boundaries only move forward
- once a window becomes invalid, moving the left pointer can restore validity
- the condition is monotone as the window grows or shrinks

## Core Idea

Maintain a window `[l, r]` together with a summary of that window:

- sum
- frequency table
- distinct count
- maximum/minimum under a monotone condition

The whole method depends on one clean rule:

- every pointer move must preserve a meaningful invariant

## Theory / Proof Sketch

The two-pointer pattern is linear when each pointer moves at most `n` times.

That works when:

- `r` only increases
- `l` only increases
- restoring validity never requires moving a pointer backward

## Complexity And Tradeoffs

- linear scans are typically `O(n)`
- extra memory depends on the maintained summary

Tradeoffs:

- great for monotone window conditions
- not enough for arbitrary subarray conditions that require backtracking

## Canonical C++ Pattern

Template in this repo:

- [two-pointers-variable-window.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/two-pointers-variable-window.cpp)

Typical checklist:

- what does the current window mean?
- when do I expand?
- when do I shrink?
- what answer do I update on each step?

## Worked Examples

Example 1: longest subarray with sum at most `k`

- works directly when all numbers are nonnegative

Example 2: count pairs in a sorted array

- sort first
- move the two ends based on comparison with the target

Example 3: smallest valid window

- expand until valid
- shrink while still valid

## Common Mistakes

- using the pattern on non-monotone conditions
- forgetting the assumptions on the values
- updating the answer at the wrong moment
- letting `l` or `r` move backward

## Practice Ladder

- [Two pointers ladder](../../../../practice/ladders/foundations/two-pointers/README.md)

## Go Deeper

- Reference: [USACO Guide](https://usaco.guide/)
- Practice: [CSES Problem Set](https://cses.fi/problemset/)

## Related Topics

- [Sorting](../sorting/README.md)
- [Prefix Sums](../prefix-sums/README.md)
