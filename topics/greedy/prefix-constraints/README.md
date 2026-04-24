# Prefix Constraints

Prefix-constraint greedy problems are about making choices while every partial answer must stay feasible.

The central habit is not "pick the biggest" or "pick the smallest." It is:

- define what a feasible prefix means
- sort or reveal items in an order that makes that condition monotone
- repair the chosen set only when feasibility breaks

## Summary

Suspect this topic when:

- a chosen subset or ordering must satisfy a condition for every prefix
- the problem talks about "at most this many before me", "last known prefixes", or a running quota
- the clean solution looks like sorting plus one invariant, not full DP

What success looks like:

- you can say what the active prefix means
- you know which quantity must stay monotone
- you can explain why dropping one bad choice is enough to restore feasibility

## Prerequisites

- [Sorting](../../foundations/patterns/sorting/README.md)
- [Reasoning And Implementation Discipline](../../foundations/reasoning/README.md)
- [Prefix Sums](../../foundations/patterns/prefix-sums/README.md) for difference-based feasibility checks

## Core Idea

Two common shapes show up here.

### 1. Order first, then count feasibility

You sort items by the quantity that makes the prefix rule easiest to test, then scan once.

Example:

- in [Lemonade Line](../../../practice/ladders/greedy/prefix-constraints/lemonadeline.md), sorting larger tolerances first makes the current line length the only state that matters

### 2. Infer hidden elements from prefix differences

You are not directly picking objects, but the unknown sequence must be compatible with a monotone prefix structure.

Example:

- in [Prefix Sum Addicts](../../../practice/ladders/greedy/prefix-constraints/prefixsumaddicts.md), the known suffix of prefix sums determines the tail differences, and those differences must already be nondecreasing

The heavier variant is:

- keep a currently chosen feasible set
- when a new item arrives, temporarily include it
- if the prefix rule breaks, remove the most expensive or most damaging chosen item

That is the pattern behind [VODIVIDE](../../../practice/ladders/greedy/prefix-constraints/vodivide.md).

## Theory / Proof Sketch

The proof style is usually one of these:

### Exchange argument

Show that if an optimal solution made a different local choice, you can swap its worse item for your chosen one and stay feasible.

### Prefix domination

Show that your current chosen structure is never worse than any other feasible structure after the same number of processed items.

### First violation repair

Show that once feasibility breaks, removing one specific "worst" chosen item restores the invariant, and any better repair would only make future prefixes harder.

## Complexity And Tradeoffs

Typical costs:

- sorting plus one scan: `O(n log n)`
- sorting plus heap repair: `O(n log n)`
- suffix-difference validation: `O(k)`

Tradeoffs:

- often much simpler than DP
- proof burden is higher than the code length suggests
- one wrong sorting order or one wrong inequality usually destroys the whole argument

## Standard Patterns

### 1. Tolerance / capacity prefixes

Each item accepts the current prefix only if the prefix size is small enough.

### 2. Greedy with repair

Use a heap to keep the current chosen set and delete the worst chosen item when a quota is exceeded.

### 3. Hidden monotone sequence feasibility

The answer is not a constructed set but a `YES/NO` check that some sorted sequence can exist behind partial prefix information.

## Worked Examples

### Example 1: Lemonade Line

Sort tolerances descending. If the next cow tolerates at least the current line size, she can be placed now without increasing the minimum possible final line beyond what is necessary.

### Example 2: Prefix Sum Addicts

Take consecutive differences of the known suffix of prefix sums. Those differences are forced tail values of the sorted array, so they must be nondecreasing.

### Example 3: VODIVIDE

Among the items currently allowed by the prefix quota, keep the cheapest feasible chosen set and throw away the most expensive chosen item whenever the quota is exceeded.

## Recognition Cues

- "behind at most `w_i` cows"
- "given the last `k` prefix sums"
- "every prefix must satisfy..."
- "when infeasible, remove one chosen item and continue"

## Common Mistakes

- sorting in the visually natural order instead of the proof-friendly one
- checking only the final state instead of every prefix
- forgetting that prefix-sum differences become actual array values in sorted-sequence feasibility problems
- using a heap without proving why the removed item is the correct one

## Practice Ladder

- [Prefix Constraints ladder](../../../practice/ladders/greedy/prefix-constraints/README.md)

Suggested order:

1. [Lemonade Line](../../../practice/ladders/greedy/prefix-constraints/lemonadeline.md)
2. [Prefix Sum Addicts](../../../practice/ladders/greedy/prefix-constraints/prefixsumaddicts.md)
3. [VODIVIDE](../../../practice/ladders/greedy/prefix-constraints/vodivide.md)

## Go Deeper

- Reference: [OI Wiki - Greedy](https://en.oi-wiki.org/basic/greedy/)
- Practice: [USACO Guide](https://usaco.guide/)
- Practice: [Codeforces problemset](https://codeforces.com/problemset)

## Related Topics

- [Sorting](../../foundations/patterns/sorting/README.md)
- [Prefix Sums](../../foundations/patterns/prefix-sums/README.md)
- [Algorithm Engineering](../../advanced/algorithm-engineering/README.md)
