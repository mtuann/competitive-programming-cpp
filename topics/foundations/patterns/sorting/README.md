# Sorting

Sorting is one of the most common hidden preprocess moves in competitive programming. Many greedy, sweep-line, binary-search, and counting solutions only become visible after the data is ordered.

## Summary

Suspect sorting when:

- only relative order matters
- the proof sounds like “take the earliest”, “take the smallest”, or “after sorting by x”
- nearby or consecutive elements become meaningful after ordering
- you want to turn a hard search into a monotone scan

What success looks like:

- you recognize when sorting is the main trick and when it is just support
- you can write safe custom comparators quickly
- you know the common proof patterns that justify greedy-after-sorting solutions

## Prerequisites

- [C++ Language For Contests](../../cpp-language/README.md)
- [Reasoning And Implementation Discipline](../../reasoning/README.md)

## Core Idea

Sorting creates structure.

After sorting, you often gain one or more of:

- monotonicity
- adjacency information
- a canonical order for greedy choices
- grouped duplicates
- a clean event order for sweeping

That is why many problems really become:

1. sort the records
2. scan once or twice
3. maintain a small invariant

## Theory / Proof Sketch

The most common proof tool after sorting is the exchange argument.

Typical pattern:

```text
Take any optimal solution.
Show that swapping one “out of order” choice with the sorted-order choice never hurts.
Repeat until the solution matches the desired order.
```

Two other common uses:

### Adjacency Reduction

After sorting numbers on a line, the best candidate is often adjacent.

Example:

- minimum difference pair
- grouping equal or near-equal values

### Ordered Event Processing

After sorting events by coordinate or time, you can process them in one pass while maintaining a small active state.

This is the foundation of many sweep-line solutions.

## Complexity And Tradeoffs

Standard comparison sort costs:

```text
O(n log n)
```

Useful tradeoffs:

- `sort` is the default
- `stable_sort` is only needed when the order among equal keys must be preserved
- `nth_element` is useful when you need a median or k-th element, not full order
- sorting once can be much cheaper than repeatedly searching unsorted data

The real decision is often:

- is sorting the main idea?
- or is it only a preprocessing step for another technique?

## Canonical C++ Pattern

Template in this repo:

- [sort-and-comparator.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/sort-and-comparator.cpp)

Useful habits:

- store records as `pair` or `struct`
- sort by the main key
- break ties explicitly when the proof or judge behavior depends on it
- ensure the comparator defines a strict weak ordering

Small example:

```cpp
struct Interval {
    int l, r;
};

bool by_end(const Interval &a, const Interval &b) {
    if (a.r != b.r) return a.r < b.r;
    return a.l < b.l;
}
```

This is safer than relying on an incomplete comparator.

## Comparator Sanity Check

Before trusting a custom comparator, ask:

- what is the primary key?
- what happens on ties?
- is the comparison still consistent if I swap the arguments?

If the proof depends on a tie rule, make that rule explicit in code instead of leaving equal keys unspecified.

## Newbie Retrieval Layer

If you feel "I can sort, but I still do not see why sorting solves the problem", use this path:

- [Sorting ladder](../../../../practice/ladders/foundations/sorting/README.md)
- [Movie Festival](../../../../practice/ladders/foundations/sorting/moviefestival.md)
- [Ferris Wheel](../../../../practice/ladders/foundations/sorting/ferriswheel.md)

That trio covers the two most common beginner wins:

- sorting to justify a greedy choice
- sorting to unlock a clean two-pointer scan

## Standard Patterns

### 1. Greedy After Sorting

Examples:

- interval scheduling by finishing time
- choose cheapest or earliest feasible item first
- maintain current best while scanning in sorted order

### 2. Adjacent-Pair Reasoning

Examples:

- minimum absolute difference
- detect duplicates quickly
- merge or compress equal values

### 3. Sorting Events

Examples:

- line sweep
- offline query processing
- coordinate compression preparation

### 4. Sorting For Binary Search

Examples:

- lower bound / upper bound on values
- search among sorted candidate answers
- sort once, answer many membership or predecessor queries

## Worked Examples

### Example 1: interval scheduling

Sort by ending time and greedily take the first compatible interval.

Why it works:

- an earlier finishing interval leaves at least as much room for the future as any later finishing compatible interval

### Example 2: minimum adjacent difference

Sort the numbers. Then the minimum absolute difference must appear between adjacent elements in sorted order.

Why:

- if two elements are not adjacent, some element lies between them and gives a no-worse difference to one side

### Example 3: event sweep

Sort events by position, then process them in order.

What sorting gives you:

- a single forward timeline
- a small active state instead of all-pairs comparisons

## Recognition Cues

Strong clues:

- the statement only cares about rank, order, earliest, latest, smallest, largest, or nearest
- a greedy step becomes obvious only after records are ordered
- the solution needs duplicates grouped or boundaries found quickly

Sorting is often confused with:

- [Binary Search](../binary-search/README.md), because both like ordered data
- [Two Pointers](../two-pointers/README.md), because sorted scans often use both
- [Sweep Line](../../../geometry/sweep-line/README.md), because event order usually starts with sorting

## Common Mistakes

- forgetting to define tie behavior
- writing a comparator that is inconsistent
- using `stable_sort` when normal `sort` is enough
- sorting too late, after already building the wrong model
- assuming sorting alone proves the greedy choice without an exchange argument

## Practice Ladder

- [Sorting ladder](../../../../practice/ladders/foundations/sorting/README.md)

Suggested order:

1. basic value sorting
2. pair and struct comparators
3. greedy after sorting
4. event ordering and sweep-style problems

## Go Deeper

- Course: [Princeton COS 226](https://www.cs.princeton.edu/~cos226)
- Reference: [CPPReference - sort](https://en.cppreference.com/w/cpp/algorithm/sort)
- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Practice: [CSES Sorting and Searching](https://cses.fi/problemset/)
- Notes: [Template Library](https://github.com/mtuann/competitive-programming-cpp/blob/main/template-library.md)

## Related Topics

- [Binary Search](../binary-search/README.md)
- [Two Pointers](../two-pointers/README.md)
- [Graph Modeling](../../../graphs/graph-modeling/README.md)
- [Sweep Line](../../../geometry/sweep-line/README.md)
