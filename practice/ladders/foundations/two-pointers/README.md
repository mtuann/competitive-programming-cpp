# Two Pointers Ladder

Two-pointers practice should teach you to recognize monotone windows and sorted scans, and just as importantly, to reject the pattern when the condition is not monotone enough.

## Who This Is For

Use this ladder if:

- you can copy a sliding-window loop, but not justify it
- you are unsure when negative values break the approach
- you want better instinct for window invariants

## Warm-Up

- fixed-size windows
- count pairs in a sorted array
- longest subarray under a monotone constraint

Target skill:

- understand what the current window represents

## Core

- variable-size windows with counts or sums
- distinct-element windows
- shortest valid window
- sorted two-end scans

Target skill:

- know exactly when to expand, shrink, and update the answer

## Stretch

- decide whether the condition is monotone enough for two pointers
- compare two pointers against prefix sums plus binary search
- explain why each pointer moves at most `n` times

Target skill:

- prove linearity and detect invalid uses of the pattern

## Exit Criteria

You are ready to move on when:

- you can state the maintained invariant before coding
- you know whether the method depends on nonnegative values or sorted order
- you can explain why no pointer ever needs to move backward

## External Practice

- [USACO Guide](https://usaco.guide/)
- [CSES Problem Set](https://cses.fi/problemset/)
- [CP-Algorithms](https://cp-algorithms.com/)

## Tutorial Link

- [Two Pointers And Sliding Window](../../../../topics/foundations/patterns/two-pointers/README.md)
