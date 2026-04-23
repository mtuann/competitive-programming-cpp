# DP Foundations

Dynamic programming starts when you can describe exactly what information from the past still matters. It is less about memorizing recurrences and more about designing the right state.

## Summary

Suspect DP when:

- the problem has overlapping subproblems
- greedy feels unsafe
- the answer can be built from smaller prefixes, suffixes, subsets, intervals, or subtrees

What success looks like:

- you can state what each DP entry means in one sentence
- you can count states and transitions before coding
- you know whether top-down or bottom-up is clearer for the problem

## Prerequisites

- [Reasoning And Implementation Discipline](../../foundations/reasoning/README.md)

## Core Idea

A good DP state answers three questions:

1. what has already been decided?
2. what still matters for the future?
3. what choices exist next?

Typical early forms:

- prefix DP
- last-choice DP
- counting DP
- optimization DP

The state is the real algorithm. The recurrence only comes after the state meaning is precise.

## Theory / Proof Sketch

DP is correct when:

- the state captures all relevant history
- transitions cover all legal next steps
- states do not depend on future information they do not store

The proof style is usually induction:

```text
Assume smaller states are correct.
Show the transition builds the current state correctly.
```

That is why writing the state meaning first is so important.

## Complexity And Tradeoffs

Always estimate:

```text
number of states * transitions per state
```

Also decide:

- top-down vs bottom-up
- whether reconstruction is needed
- whether memory compression is safe

Tradeoffs:

- top-down can be easier to derive
- bottom-up can be faster and easier to control
- memory compression is elegant, but only after correctness is stable

## Canonical C++ Pattern

Useful checklist:

- exact state meaning
- base case
- transition formula
- iteration order
- answer location

Notebook:

- [DP cheatsheet](../../../notebook/dp-cheatsheet.md)

Start with a plain version before optimizing.

## Standard Patterns

### 1. Prefix DP

Examples:

- process first `i` items
- `dp[i]` or `dp[i][j]`

### 2. Counting DP

Examples:

- number of ways
- modulo arithmetic often appears

### 3. Optimization DP

Examples:

- maximum score
- minimum cost

### 4. State Compression

Once the basic form works, look for:

- rolling arrays
- one-dimensional compression

But only if dependencies still remain valid.

## Worked Examples

### Example 1: maximum sum over prefixes

One-dimensional optimization DP:

```text
dp[i] = best answer on the first i items
```

### Example 2: count ways to reach sum `S`

Counting DP:

- the state counts possibilities instead of storing a best value

### Example 3: structured optimization

- [TFIELD](../../../practice/ladders/dp/sliding-window/tfield.md) is a later example where the “real” work is designing the right compressed state rather than applying a standard textbook recurrence

## Recognition Cues

Strong clues:

- many subproblems look similar
- brute force recomputes the same things
- local greedy decisions do not seem obviously safe
- state summaries seem possible

DP is often confused with:

- [Greedy](../../foundations/reasoning/README.md), when a recurrence exists but greediness does not
- graph shortest paths, when the state graph interpretation is cleaner than a table

## Common Mistakes

- state is too vague
- transition double-counts or misses cases
- iteration order breaks dependencies
- memory compression is applied before the recurrence is fully trusted
- answer location is unclear

## Practice Ladder

- [DP foundations ladder](../../../practice/ladders/dp/foundations/README.md)

Suggested order:

1. 1D prefix DP
2. counting DP
3. 2D state design
4. reconstruction and compression

## Go Deeper

- Reference: [CP-Algorithms - Intro to DP](https://cp-algorithms.com/dynamic_programming/intro-to-dp.html)
- Practice: [AtCoder Educational DP Contest](https://atcoder.jp/contests/dp)
- Practice: [USACO Guide](https://usaco.guide/)
- Notes: [DP cheatsheet](../../../notebook/dp-cheatsheet.md)

## Related Topics

- [Knapsack Family](../knapsack-family/README.md)
- [Bitmask DP](../bitmask-dp/README.md)
- [Tree DP](../tree-dp/README.md)
