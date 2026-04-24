# Prefix Sums

Prefix sums are the first major “precompute once, answer many times” tool in competitive programming. They turn repeated range aggregation into constant-time queries after linear preprocessing.

## Summary

Suspect prefix sums when:

- you have many static range-sum or range-count queries
- the desired quantity can be written as “everything up to `r` minus everything before `l`”
- the array does not change between queries

What success looks like:

- you define the prefix meaning clearly
- you pick one indexing convention and keep it
- you can extend the idea from sums to counts, frequencies, and 2D rectangles

## Prerequisites

- [Reasoning And Implementation Discipline](../../reasoning/README.md)

## Core Idea

Define a prefix array whose meaning is simple and stable.

Most common form:

```text
pref[i] = sum of the first i values
pref[0] = 0
sum(l..r) = pref[r] - pref[l - 1]
```

The real technique is not the formula itself. It is choosing a prefix definition that makes your target query a subtraction of two prefixes.

## Theory / Proof Sketch

Invariant:

```text
pref[i] stores the aggregate value on the prefix ending at i
```

Then:

```text
aggregate(1..r) - aggregate(1..l-1) = aggregate(l..r)
```

This works for any additive quantity:

- sums
- counts
- frequency totals
- weighted sums

The same idea also extends to 2D using inclusion-exclusion.

## Complexity And Tradeoffs

Standard 1D prefix sums:

- preprocessing: `O(n)`
- one range query: `O(1)`
- memory: `O(n)`

Tradeoffs:

- excellent for static data
- poor for many updates
- once updates matter, [Fenwick Tree](../../../data-structures/fenwick-tree/README.md) or [Segment Tree](../../../data-structures/segment-tree/README.md) may be a better fit

## Canonical C++ Pattern

Template in this repo:

- [prefix-sum-1d.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/prefix-sum-1d.cpp)

Notebook:

- [Foundations cheatsheet](../../../../notebook/foundations-cheatsheet.md)

Safe habit:

- use a one-based prefix array and set `pref[0] = 0`

Example:

```cpp
vector<long long> pref(n + 1, 0);
for (int i = 1; i <= n; ++i) {
    pref[i] = pref[i - 1] + a[i];
}
```

Then every range formula is uniform.

## Indexing Discipline

The safest beginner habit is:

- store the original array however you like
- build prefix sums as `pref[0..n]`
- let `pref[i]` mean “aggregate of the first `i` elements”

Then:

```text
sum on [l, r) = pref[r] - pref[l]
```

or, if you prefer one-based problem statements, convert once and keep the formula uniform. Most prefix-sum bugs are really indexing-discipline bugs.

## Newbie Retrieval Layer

When you feel "I know the idea but I still keep getting the formula wrong", use:

- [Static Range Sum Queries note](../../../../practice/ladders/foundations/prefix-sums/staticrangesumqueries.md)
- [Prefix sums ladder](../../../../practice/ladders/foundations/prefix-sums/README.md)
- [Foundations cheatsheet](../../../../notebook/foundations-cheatsheet.md)

## Standard Patterns

### 1. Range Sums

The classic use:

```text
sum(l..r) = pref[r] - pref[l - 1]
```

### 2. Range Counts

Instead of storing value sums, store counts of some event:

```text
pref_bad[i] = number of bad positions in the first i elements
```

Then count bad positions in any interval with one subtraction.

### 3. Prefix Frequencies

Useful when values are small or compressed:

```text
freq[x][i] = number of times value x appears in the first i positions
```

### 4. 2D Prefix Sums

For a grid:

```text
pref[x][y] = sum on rectangle (1,1) to (x,y)
```

Rectangle queries use inclusion-exclusion.

## Worked Examples

### Example 1: range sums

Definition:

```text
pref[i] = a[1] + a[2] + ... + a[i]
```

Then:

```text
sum(l..r) = pref[r] - pref[l - 1]
```

The main bug risk is indexing, not the math.

### Example 2: count zeros in a range

Let:

```text
pref_zero[i] = number of zeros in positions 1..i
```

Then:

```text
zeros(l..r) = pref_zero[r] - pref_zero[l - 1]
```

Same pattern, different aggregate.

### Example 3: 2D prefix sums

For a matrix:

```text
rect(x1..x2, y1..y2)
= pref[x2][y2]
 - pref[x1 - 1][y2]
 - pref[x2][y1 - 1]
 + pref[x1 - 1][y1 - 1]
```

This is just 2D inclusion-exclusion on prefixes.

## Recognition Cues

Strong clues:

- many queries, no updates
- “how many in this interval?”
- “sum on rectangle” or “sum on subarray”
- the query naturally decomposes into prefix pieces

Prefix sums are often confused with:

- [Difference Arrays](../difference-arrays/README.md), which are update-friendly
- [Fenwick Tree](../../../data-structures/fenwick-tree/README.md), which handles updates
- [Two Pointers](../two-pointers/README.md), which also work on intervals but in a dynamic scan

## Common Mistakes

- mixing zero-based and one-based formulas
- forgetting `pref[0] = 0`
- using `int` for large sums
- forcing a segment tree when the data is actually static
- writing one special-case formula for every query instead of choosing a cleaner prefix definition

## Practice Ladder

- [Prefix sums ladder](../../../../practice/ladders/foundations/prefix-sums/README.md)

Suggested order:

1. 1D range sums
2. range counts
3. 2D prefix sums
4. combine prefix sums with binary search or offline counting

## Go Deeper

- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Practice: [CSES Problem Set](https://cses.fi/problemset/)
- Next step: [Difference Arrays](../difference-arrays/README.md)
- Next step: [Fenwick Tree](../../../data-structures/fenwick-tree/README.md)

## Related Topics

- [Difference Arrays](../difference-arrays/README.md)
- [Fenwick Tree](../../../data-structures/fenwick-tree/README.md)
- [Two Pointers](../two-pointers/README.md)
- [Binary Search](../binary-search/README.md)
