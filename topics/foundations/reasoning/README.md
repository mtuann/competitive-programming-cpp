# Reasoning And Implementation Discipline

This page is the bridge between “I know the idea” and “I can explain why this implementation is correct.”

## Prerequisites

- [C++ Language For Contests](../cpp-language/README.md)

## When To Suspect This Topic

Spend time here if:

- you often get off-by-one errors
- your binary search or DP code works only on samples
- you struggle to explain what a loop variable or pointer really means

## Core Idea

Most contest bugs come from missing invariants, not from missing syntax.

The core questions are:

- what does each variable mean right now?
- what remains true after each iteration?
- why does the loop stop in the right state?

## Theory / Proof Sketch

Three proof tools matter constantly in competitive programming:

1. invariants
2. induction on processed elements or states
3. exchange arguments after sorting or greedy choices

Example invariant:

```text
Before processing a[i], pref[i - 1] is the sum of the first i - 1 values.
After processing a[i], pref[i] is the sum of the first i values.
```

Example binary-search invariant:

```text
l is always a bad state
r is always a good state
The answer stays in the half-open interval (l, r].
```

## Complexity And Tradeoffs

Always estimate before coding:

- `O(n)` is usually safe up to about `1e6`
- `O(n log n)` is usually safe up to about `2e5` or `1e6`, depending on constants
- `O(n^2)` is only safe for moderate `n`

Do not memorize limits mechanically. Estimate:

- how many operations
- how much memory
- whether recursion depth is safe

## Canonical C++ Pattern

Before or while coding, write down:

- state meaning
- loop invariant
- boundary convention
- expected complexity

A small comment or scratch checklist is often enough.

## Worked Examples

Example 1: prefix sums

```text
pref[i] = pref[i - 1] + a[i]
sum(l..r) = pref[r] - pref[l - 1]
```

The invariant is what makes the range-sum formula valid.

Example 2: sliding window with positive numbers

- `l` and `r` define the current window
- the maintained quantity is the sum of the current window
- shrinking is valid because moving `l` only decreases the sum

Example 3: binary search on answer

- define a monotone predicate first
- then maintain one bad endpoint and one good endpoint

## Common Mistakes

- writing code before naming the state clearly
- changing indexing conventions halfway through
- using binary search without a monotone predicate
- proving the algorithm informally but not proving the implementation

## Practice Ladder

- [Complexity and invariants ladder](../../../practice/ladders/foundations/complexity-and-invariants/README.md)
- [Binary search ladder](../../../practice/ladders/foundations/binary-search/README.md)
- [Prefix sums ladder](../../../practice/ladders/foundations/prefix-sums/README.md)

## Go Deeper

- Course: [Stanford CS161](https://cs161-stanford.github.io)
- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Practice: [AtCoder Educational DP Contest](https://atcoder.jp/contests/dp)
- Notes: [Markdown Math Style](../../../docs/authoring/markdown-math-style.md)

## Related Topics

- [Binary Search](../patterns/binary-search/README.md)
- [Prefix Sums](../patterns/prefix-sums/README.md)
- [Two Pointers](../patterns/two-pointers/README.md)
