# Binary Search

Binary search is not just “find a value in a sorted array.” In contests, the deeper pattern is maintaining a monotone predicate and shrinking an answer interval without ever losing the true answer.

## Summary

Suspect binary search when:

- the answer lies in an ordered range
- the statement asks for the minimum or maximum feasible value
- a predicate changes only once from false to true
- checking one candidate is easy, but scanning all candidates is too slow

What success looks like:

- you can define the search space clearly
- you can state the monotone predicate precisely
- you can write one boundary convention and keep it consistent

## Prerequisites

- [Reasoning And Implementation Discipline](../../reasoning/README.md)
- [Sorting](../sorting/README.md)

## Core Idea

Binary search needs three things:

1. a search space with order
2. a monotone predicate
3. endpoints whose meanings never change

The safest contest form is:

```text
l is a known bad state
r is a known good state
the answer remains in (l, r]
```

Each step tests `mid` and discards one half while preserving that invariant.

## Theory / Proof Sketch

Correctness has two parts:

### 1. Invariant Preservation

If `mid` is good, then the first good answer lies in `(l, mid]`, so set `r = mid`.

If `mid` is bad, then the first good answer lies in `(mid, r]`, so set `l = mid`.

### 2. Termination

The interval length shrinks every iteration. When `r = l + 1`, there is no room left for another candidate, so `r` is the first good value.

This is why binary search is less about the loop and more about choosing the right invariant.

## Complexity And Tradeoffs

If one check costs `T`, then:

```text
binary search cost = O(T log range)
```

Useful tradeoffs:

- if you are searching inside a sorted container, `lower_bound` or `upper_bound` may be simpler
- answer-search works only if the predicate is genuinely monotone
- if the domain is tiny, brute force may be clearer

## Canonical C++ Pattern

Templates in this repo:

- [binary-search-first-true.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/binary-search-first-true.cpp)
- [binary-search-last-false.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/binary-search-last-false.cpp)

Checklist:

- what exactly does `good(x)` mean?
- are `l` and `r` initialized to one bad and one good state?
- does `mid` move the loop forward?
- what does the returned endpoint mean?

For integer search, prefer:

```cpp
long long mid = l + (r - l) / 2;
```

to avoid overflow.

## Newbie Guardrail

If binary search still feels slippery, write these four lines in comments first:

```text
good(x) =
l means =
r means =
return =
```

If any line feels vague, the loop is not ready yet.

## Standard Patterns

### 1. Search In Sorted Data

Examples:

- first position `>= x`
- last position `<= x`
- membership in sorted values

In this case, STL helpers like `lower_bound` are often the cleanest choice.

### 2. Binary Search On Answer

Examples:

- minimum time to finish work
- maximum feasible distance
- smallest capacity that allows completion

This is the main contest pattern.

### 3. Continuous Or Real-Valued Search

Sometimes the answer space is real rather than integer. Then the stopping condition is based on precision, not adjacent endpoints. This is useful, but secondary to the integer version.

## Worked Examples

### Example 1: first position `>= x`

Search on indices of a sorted array.

Predicate:

```text
good(i) = a[i] >= x
```

This is exactly the “first true” pattern.

### Example 2: minimum time to finish `k` tasks

Predicate:

```text
good(t) = within time t, the machines can finish at least k tasks
```

Why it is monotone:

- if time `t` is enough, any larger time is also enough

### Example 3: longest feasible answer

Sometimes it is easier to search for the first bad value, or the last good value. The main thing is not the exact variant. It is keeping the boundary meaning consistent from start to finish.

## Recognition Cues

Strong clues:

- “minimum value such that...”
- “maximum value for which...”
- “is it possible if the answer is x?”
- check function is linear or near-linear, while the raw answer range is huge

Binary search is often confused with:

- [Sorting](../sorting/README.md), because sorted data often enables it
- [Two Pointers](../two-pointers/README.md), because both exploit monotonicity
- [Prefix Sums](../prefix-sums/README.md), because they often make the check function fast enough

## Common Mistakes

- using it without a monotone predicate
- inconsistent endpoint meaning
- integer overflow in `mid`
- returning `l` or `r` without knowing which one is the answer
- using `while (l <= r)` with ad hoc updates and then patching corner cases afterward

## Practice Ladder

- [Binary search ladder](../../../../practice/ladders/foundations/binary-search/README.md)

Suggested order:

1. array search with `lower_bound`
2. first-true / last-false integer search
3. answer-search with a greedy or prefix-sum check
4. compare binary search against a direct formula when both exist

## Go Deeper

- Reference: [CP-Algorithms - Binary Search](https://cp-algorithms.com/num_methods/binary_search.html)
- Practice: [USACO Guide - Binary Search](https://usaco.guide/silver/binary-search)
- Practice: [CSES Problem Set](https://cses.fi/problemset/)
- Notes: [Reasoning And Implementation Discipline](../../reasoning/README.md)

## Related Topics

- [Sorting](../sorting/README.md)
- [Prefix Sums](../prefix-sums/README.md)
- [Two Pointers](../two-pointers/README.md)
- [Shortest Paths](../../../graphs/shortest-paths/README.md)
