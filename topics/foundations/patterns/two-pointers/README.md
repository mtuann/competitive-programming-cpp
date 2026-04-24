# Two Pointers And Sliding Window

Two pointers turn a nested scan into a linear scan when the valid region changes monotonically. This is one of the most useful “looks simple, saves huge time” patterns in beginner and intermediate contest problems.

## Summary

Suspect two pointers when:

- you are scanning intervals of an array or string
- left and right boundaries mostly move forward
- once a window becomes invalid, moving the left pointer can restore validity
- the condition behaves monotonically as the window grows or shrinks

What success looks like:

- you can state what the current window means
- you know exactly when to expand and when to shrink
- you can tell when two pointers is invalid because the condition is not monotone

## Prerequisites

- [Reasoning And Implementation Discipline](../../reasoning/README.md)
- [Sorting](../sorting/README.md)

## Core Idea

Maintain a window and a summary of that window.

Typical summary:

- current sum
- frequency table
- number of distinct values
- current count of violations

The main rule is:

```text
every pointer move must preserve a meaningful invariant
```

This is why two pointers is more about reasoning than syntax.

## Theory / Proof Sketch

The standard linear-time proof is:

- `r` only moves forward
- `l` only moves forward
- each pointer moves at most `n` times

So the total work is `O(n)` plus the cost of maintaining the window summary.

This only works when the window condition is monotone enough:

- expanding can only make one direction of change
- shrinking can restore validity without needing backward moves

If the condition needs backtracking, the pattern may not apply.

## Complexity And Tradeoffs

Typical cost:

- `O(n)` pointer movement
- extra work depends on what the window maintains

Tradeoffs:

- excellent for monotone interval conditions
- not suitable for arbitrary subarray optimization
- sometimes sorting first turns a hard problem into a two-pointer problem

## Canonical C++ Pattern

Template in this repo:

- [two-pointers-variable-window.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/two-pointers-variable-window.cpp)

Useful checklist:

- what is the exact meaning of `[l, r]` or `[l, r)`?
- what summary is maintained?
- when is the window valid?
- at which moment is the answer updated?

Common structure:

```text
for each r:
    add a[r]
    while window is invalid:
        remove a[l]
        l++
    update answer
```

## Monotonicity Test

Before using two pointers, check whether one-direction pointer movement is believable.

Good signs:

- all numbers are nonnegative for sum-based windows
- shrinking the window can only improve validity
- sorting makes the pair condition move predictably

Bad signs:

- negative values destroy the simple sum monotonicity
- validity depends on a future choice that may require moving backward
- you cannot explain why each pointer moves at most `n` times

## Standard Patterns

### 1. Variable-Size Sliding Window

Examples:

- longest subarray with sum at most `k`
- shortest subarray satisfying a requirement
- longest substring with at most `k` distinct characters

### 2. Two Ends On A Sorted Array

Examples:

- pair sum
- closest pair under a target
- count compatible pairs

Here the two pointers are not a window but two moving positions in sorted order.

### 3. Merge-Style Scan

Examples:

- intersect two sorted lists
- compare two event streams
- advance the pointer with the smaller current value

## Worked Examples

### Example 1: longest subarray with sum at most `k`

This works directly when all values are nonnegative.

Why:

- expanding increases or preserves the sum
- shrinking decreases or preserves the sum

That monotonicity makes the window manageable.

### Example 2: count pairs in a sorted array

Sort first, then keep one pointer at each end.

If the sum is too small, move the left pointer.

If the sum is too large, move the right pointer.

This works because sorting creates monotonicity.

### Example 3: shortest valid window

Expand until the window becomes valid, then shrink while validity is preserved.

The answer must be updated during the shrinking phase, not only after expansion.

## Recognition Cues

Strong clues:

- windows, intervals, substrings, or subarrays
- both boundaries move only forward
- “at most”, “at least”, or “no more than k distinct”
- sorted pair problems where moving one endpoint changes the condition predictably

Two pointers is often confused with:

- [Prefix Sums](../prefix-sums/README.md), because both work on ranges
- [Binary Search](../binary-search/README.md), because both exploit monotonicity
- [Sorting](../sorting/README.md), because sorted order often makes two pointers possible

## Common Mistakes

- using the pattern on non-monotone conditions
- forgetting that negative values can break a sum-based sliding window
- updating the answer at the wrong moment
- mixing `[l, r]` and `[l, r)` conventions
- letting a pointer move backward

## Practice Ladder

- [Two pointers ladder](../../../../practice/ladders/foundations/two-pointers/README.md)

Suggested order:

1. fixed-size windows
2. variable windows with nonnegative sums
3. distinct-element windows
4. sorted two-end pointer problems

## Go Deeper

- Reference: [USACO Guide](https://usaco.guide/)
- Practice: [CSES Problem Set](https://cses.fi/problemset/)
- Notes: [Reasoning And Implementation Discipline](../../reasoning/README.md)

## Related Topics

- [Sorting](../sorting/README.md)
- [Prefix Sums](../prefix-sums/README.md)
- [Binary Search](../binary-search/README.md)
- [Difference Arrays](../difference-arrays/README.md)
