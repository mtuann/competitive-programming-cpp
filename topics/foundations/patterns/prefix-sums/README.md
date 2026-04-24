# Prefix Sums

Prefix sums are the first serious example of this contest pattern:

- preprocess once
- answer many static queries cheaply

The trick is not the formula itself.

The real trick is choosing a prefix definition so the target quantity becomes:

- one prefix
- or the difference of two prefixes
- or, in 2D, an inclusion-exclusion combination of four prefixes

Once you see a query as "everything up to here minus everything before there," the implementation is usually one line.

## At A Glance

- **Use when:** the data is static and the query can be written as a difference of cumulative aggregates
- **Core worldview:** range questions become easy after you store all prefixes once
- **Main tools:** 1D prefix sums, frequency/count prefixes, modulo/count prefixes, 2D prefix sums
- **Typical complexity:** `O(n)` preprocessing and `O(1)` per static 1D query
- **Main trap:** inconsistent indexing or using prefix sums in a problem that actually needs online updates

## Prerequisites

- [Reasoning](../../reasoning/README.md)

Helpful neighboring topics:

- [Difference Arrays](../difference-arrays/README.md)
- [Fenwick Tree](../../../data-structures/fenwick-tree/README.md)
- [Segment Tree](../../../data-structures/segment-tree/README.md)

## Problem Model And Notation

Let the array be:

$$
a_0, a_1, \dots, a_{n-1}.
$$

The safest contest convention is:

$$
\mathrm{pref}[i] = a_0 + a_1 + \cdots + a_{i-1},
$$

so:

- `pref` has length `n + 1`
- `pref[0] = 0`
- `pref[i]` stores the sum of the first `i` elements

Then the sum on the half-open interval `[l, r)` is:

$$
\sum_{i=l}^{r-1} a_i = \mathrm{pref}[r] - \mathrm{pref}[l].
$$

If the statement uses one-based inclusive intervals `[l, r]`, you can still use the same idea after converting indices once.

## From Brute Force To The Right Idea

### Brute Force: Recompute Every Query

Suppose queries ask:

- sum on `[l, r]`
- number of zeros on `[l, r]`
- number of values satisfying a predicate in `[l, r]`

The brute-force answer is:

- scan the interval every time

That costs:

$$
O(r-l+1)
$$

per query, which is too slow when there are many queries.

### The First Shift: Store Everything Up To Here

Instead of answering a range query directly, answer a simpler question once for every endpoint:

- what is the aggregate on the prefix ending here?

Now every future query can reuse that work.

### The Second Shift: A Range Is A Difference Of Prefixes

For sums, this is the core identity:

$$
(a_0 + \cdots + a_{r-1}) - (a_0 + \cdots + a_{l-1}) = a_l + \cdots + a_{r-1}.
$$

So the hard work is not the subtraction. The hard work is defining a prefix whose meaning is stable and easy to trust.

### The Third Shift: "Prefix Sum" Means "Any Additive Prefix Aggregate"

You are not limited to numeric sums.

The same pattern works for:

- counts
- frequencies
- weighted sums
- parity counts
- indicator arrays
- 2D rectangle sums

So the general question is:

- can I encode the thing I care about as something additive over prefixes?

If yes, prefix sums may be the right tool.

## Core Invariants And Why They Work

## 1. Stable Prefix Meaning

The most important invariant is:

```text
pref[i] has one precise meaning and never changes during the whole solution.
```

For the standard half-open convention:

```text
pref[i] = sum of a[0..i-1]
```

Once that meaning is fixed, every range formula becomes routine.

## 2. Why Range Subtraction Works

Under the half-open convention:

$$
\mathrm{pref}[r] = a_0 + a_1 + \cdots + a_{r-1},
$$

and:

$$
\mathrm{pref}[l] = a_0 + a_1 + \cdots + a_{l-1}.
$$

Subtracting cancels the common left prefix and leaves exactly:

$$
a_l + a_{l+1} + \cdots + a_{r-1}.
$$

This proof is tiny, but it matters because almost every indexing bug is a meaning bug, not an arithmetic bug.

## 3. Prefix Sums Work For Any Additive Quantity

Suppose `b[i]` is not the original array value, but an indicator:

$$
b[i] =
\begin{cases}
1, & \text{if position } i \text{ has the property} \\
0, & \text{otherwise}
\end{cases}
$$

Then:

$$
\mathrm{prefB}[r] - \mathrm{prefB}[l]
$$

counts how many positions in `[l, r)` satisfy the property.

This is why prefix sums immediately generalize from "sum" to:

- count positives
- count zeros
- count occurrences of one letter
- count how many values are at most some threshold after preprocessing

## 4. 2D Prefix Sums Are Just Inclusion-Exclusion

For a matrix, define:

$$
\mathrm{pref}[x][y]
$$

as the aggregate on the rectangle from `(1,1)` to `(x,y)`.

Then a query rectangle is:

$$
\mathrm{pref}[x_2][y_2]
- \mathrm{pref}[x_1-1][y_2]
- \mathrm{pref}[x_2][y_1-1]
+ \mathrm{pref}[x_1-1][y_1-1].
$$

This is the same prefix idea again, only now one overlap must be added back.

## 5. Why Prefix Sums Fail For Frequent Updates

If one array element changes, then all later prefixes change too.

So a single point update may force:

$$
O(n)
$$

recomputation.

That is the exact boundary where you should stop using static prefix sums and move to:

- [Difference Arrays](../difference-arrays/README.md) for offline range updates
- [Fenwick Tree](../../../data-structures/fenwick-tree/README.md) or [Segment Tree](../../../data-structures/segment-tree/README.md) for online updates

## Variant Chooser

### Use 1D Prefix Sums When

- the array is static
- many range sums or range counts must be answered
- each answer can be expressed as a difference of two cumulative values

Canonical examples:

- static range sum
- static frequency count
- number of bad positions in a segment

### Use Frequency Prefixes When

- the value domain is small or compressed
- queries ask "how many times does value `x` occur in `[l, r]`?"

Then you may store one prefix per value.

### Use Prefixes Modulo Something When

- the target is about divisibility or equal-prefix classes

Canonical smell:

- subarray sums divisible by `m`
- equal count of two symbols

Then the useful invariant is often not the raw prefix sum, but the prefix sum modulo `m` or the difference between two counters.

### Use 2D Prefix Sums When

- the data is a static grid
- rectangle sums or rectangle counts are queried

### Do Not Use Plain Prefix Sums When

- updates appear between queries
- the answer depends on a moving window with no static preprocessing
- the aggregate is not additive in a prefix-friendly way

Then you should think about:

- [Difference Arrays](../difference-arrays/README.md)
- [Two Pointers](../two-pointers/README.md)
- [Fenwick Tree](../../../data-structures/fenwick-tree/README.md)

## Worked Examples

### Example 1: Static Range Sum Queries

This is the repo's canonical first note:

- [Static Range Sum Queries](../../../../practice/ladders/foundations/prefix-sums/staticrangesumqueries.md)

Build:

$$
\mathrm{pref}[i] = \text{sum of first } i \text{ elements}.
$$

Then each sum query is:

$$
\mathrm{pref}[r] - \mathrm{pref}[l-1]
$$

under one-based inclusive indexing, or:

$$
\mathrm{pref}[r] - \mathrm{pref}[l]
$$

under zero-based half-open indexing.

The technique is identical; only the indexing convention changes.

### Example 2: Count Zeros In A Range

Define:

$$
b[i] =
\begin{cases}
1, & a[i] = 0 \\
0, & \text{otherwise}
\end{cases}
$$

Then the number of zeros in `[l, r)` is simply:

$$
\mathrm{prefB}[r] - \mathrm{prefB}[l].
$$

This is the cleanest reminder that prefix sums are not tied to actual sums of the original values.

### Example 3: 2D Rectangle Sum

Let a matrix query ask for the sum over:

$$
[x_1, x_2] \times [y_1, y_2].
$$

Use 2D prefix sums and answer with:

$$
\mathrm{pref}[x_2][y_2]
- \mathrm{pref}[x_1-1][y_2]
- \mathrm{pref}[x_2][y_1-1]
+ \mathrm{pref}[x_1-1][y_1-1].
$$

The minus-minus-plus pattern is not a trick to memorize blindly. It comes from:

- subtracting the top strip
- subtracting the left strip
- adding back the overlap that was subtracted twice

### Example 4: Prefix Sums + Another Technique

Many problems do not end at "build prefix sums."

Instead, prefix sums are the cheap helper that feeds another idea:

- interval cost for DP
- feasibility check for binary search
- rectangle area/count queries inside geometry or grids

That is why prefix sums are often a support tool rather than the whole solution.

### Example 5: Prefix Sums Modulo `m`

Suppose you want to count subarrays whose sum is divisible by `m`.

Let:

$$
\mathrm{pref}[i] = a_0 + a_1 + \cdots + a_{i-1}.
$$

Then the subarray sum on `[l, r)` is divisible by `m` exactly when:

$$
(\mathrm{pref}[r] - \mathrm{pref}[l]) \bmod m = 0,
$$

which is equivalent to:

$$
\mathrm{pref}[r] \equiv \mathrm{pref}[l] \pmod m.
$$

So the problem becomes:

- count pairs of equal prefix-sum remainders

This is the first important jump beyond direct range queries:

- you are still using prefix sums
- but the answer comes from comparing prefix **classes**, not subtracting one explicit interval query

## Algorithms And Pseudocode

### Standard 1D Build

```text
pref[0] = 0
for i from 0 to n-1:
    pref[i + 1] = pref[i] + a[i]
```

### Half-Open Query

```text
sum(l, r):
    return pref[r] - pref[l]
```

### One-Based Inclusive Query

```text
sum(l, r):
    return pref[r] - pref[l - 1]
```

### 2D Build

```text
pref[x][y] =
    grid[x][y]
    + pref[x - 1][y]
    + pref[x][y - 1]
    - pref[x - 1][y - 1]
```

## Implementation Notes

- Pick one indexing convention and keep it everywhere.
- The safest 1D contest convention is often `pref[0..n]` with half-open queries.
- Use `long long` whenever sums may exceed `int`.
- For 2D prefix sums, initialize the zero row and zero column so boundary formulas stay uniform.
- Prefix sums pair naturally with immutable arrays. If the array changes repeatedly, the technique is usually the wrong main tool.

## Practice Archetypes

You should strongly suspect prefix sums when you see:

- many static range-sum queries
- range counts over a fixed array
- rectangle sums on a fixed grid
- interval cost precomputation for DP

Repo anchors:

- [Static Range Sum Queries](../../../../practice/ladders/foundations/prefix-sums/staticrangesumqueries.md)

Starter template:

- [prefix-sum-1d.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/prefix-sum-1d.cpp)

Notebook refresher:

- [Foundations cheatsheet](../../../../notebook/foundations-cheatsheet.md)

## References And Repo Anchors

Course / tutorial style:

- [USACO Guide: Introduction to Prefix Sums](https://usaco.guide/silver/prefix-sums)
- [OI Wiki: Prefix Sum And Adjacent Difference](https://en.oi-wiki.org/basic/prefix-sum/)
- [Competitive Programmer's Handbook](https://usaco.guide/CPH.pdf)

Practice / repo anchors:

- [Prefix sums ladder](../../../../practice/ladders/foundations/prefix-sums/README.md)
- [Static Range Sum Queries](../../../../practice/ladders/foundations/prefix-sums/staticrangesumqueries.md)

## Related Topics

- [Difference Arrays](../difference-arrays/README.md)
- [Fenwick Tree](../../../data-structures/fenwick-tree/README.md)
- [Segment Tree](../../../data-structures/segment-tree/README.md)
- [Two Pointers](../two-pointers/README.md)
