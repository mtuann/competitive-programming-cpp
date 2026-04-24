# Sparse Table

Sparse table is the cleanest static-range-query structure for idempotent operations such as `min`, `max`, and `gcd`. It is the data structure you reach for when:

- the array never changes
- the query operation is associative and idempotent
- you want simpler `O(1)` queries than a segment tree can give

The whole trick is to precompute answers on intervals of length `2^k`, then answer any query using two overlapping blocks of equal length. That overlap is not a hack. It is exactly where idempotence enters.

## At A Glance

- **Use when:** immutable array, many range queries, idempotent merge (`min`, `max`, `gcd`, bitwise `and/or`)
- **Core invariant:** `st[k][i]` stores the answer on `[i, i + 2^k - 1]`
- **Build cost:** `O(n log n)`
- **Query cost:** `O(1)` for the standard overlapping-two-block form
- **Memory:** `O(n log n)`
- **Do not use when:** point/range updates exist, or the merge is non-idempotent and you only know the standard sparse-table trick

## Problem Model And Notation

We are given a static array

$$
A[0], A[1], \dots, A[n-1].
$$

Each query asks for the aggregate on a range

$$
[l, r] \quad \text{with } 0 \le l \le r < n.
$$

Let the merge operation be written as $x \otimes y$.

For the classic sparse-table query trick, we need:

- **associativity**, so ranges can be split and merged in any parenthesization
- **idempotence**, so overlapping coverage does not change the answer:

$$
x \otimes x = x.
$$

Typical valid operations:

- `min`
- `max`
- `gcd`
- bitwise `and`
- bitwise `or`

Typical invalid operations for the standard query trick:

- `sum`
- `xor`
- product

The table is:

$$
st[k][i] = A[i] \otimes A[i+1] \otimes \cdots \otimes A[i + 2^k - 1].
$$

So row `k` stores answers on all power-of-two intervals of length $2^k$.

## From Brute Force To The Right Idea

### Brute Force Per Query

The most direct approach is:

- iterate from `l` to `r`
- merge everything

That costs `O(r - l + 1)` per query. This is fine for a few queries, but terrible when:

- `n` is large
- `q` is large
- the array is static, so repeated work feels wasteful

### Precompute Every Interval

At the other extreme, you could precompute the answer for every interval `[l, r]`.

That gives:

- `O(1)` query
- but `O(n^2)` space and preprocessing

This is conceptually useful because it tells us the real goal:

- keep the "answer by lookup" flavor
- without storing all `n^2` intervals

### Power-Of-Two Blocks Are The Right Basis

The standard observation is:

- every query length contains a largest power of two
- a power-of-two interval can be built from two adjacent half-size intervals

So instead of storing all intervals, store only intervals of lengths

$$
1, 2, 4, 8, \dots
$$

That reduces the total amount of precomputed information from quadratic down to `O(n log n)`.

### Why Two Blocks Are Enough

For any query length

$$
\ell = r - l + 1,
$$

let

$$
k = \lfloor \log_2 \ell \rfloor.
$$

Then the two length-$2^k$ blocks

$$
[l, l + 2^k - 1]
\quad\text{and}\quad
[r - 2^k + 1, r]
$$

both lie inside `[l, r]`, and together they cover the whole query range.

They may overlap. That overlap is exactly why idempotence matters.

## Core Invariant And Why It Works

### The Invariant

For every valid pair `(k, i)`,

$$
st[k][i]
$$

stores the aggregate over the interval

$$
[i, i + 2^k - 1].
$$

That is the only invariant you must protect. Everything else follows from it.

### Why The Build Recurrence Is Correct

A length-$2^k$ interval splits into two adjacent length-$2^{k-1}$ halves:

$$
[i, i + 2^k - 1]
=
[i, i + 2^{k-1} - 1]
\cup
[i + 2^{k-1}, i + 2^k - 1].
$$

So by associativity,

$$
st[k][i]
=
st[k-1][i] \otimes st[k-1][i + 2^{k-1}].
$$

This is why sparse table is so easy to build: each row is just the previous row doubled.

### Why The Query Formula Is Correct

Take

$$
k = \lfloor \log_2(r-l+1) \rfloor.
$$

Then each of these intervals has length $2^k$:

$$
L = [l, l + 2^k - 1], \qquad
R = [r - 2^k + 1, r].
$$

Because $2^k \le r-l+1 < 2^{k+1}$, those two blocks cover `[l, r]`.

So the candidate answer is

$$
st[k][l] \otimes st[k][r - 2^k + 1].
$$

If `L` and `R` overlap, then some middle elements are counted twice. For idempotent operations that does not matter:

$$
x \otimes x = x.
$$

So duplicated middle coverage leaves the answer unchanged.

### Why This Fails For Sum

Suppose the array is:

$$
[5, 2, 7, 1, 3]
$$

and the query is `[1, 4]`, whose length is `4`. That one is fine: the blocks do not overlap.

But for query `[0, 4]`, the length is `5`, so `k = 2` and the two length-`4` blocks are:

$$
[0, 3] \quad \text{and} \quad [1, 4].
$$

The middle region `[1, 3]` is covered twice.

For `min`, this is harmless.

For `sum`, this would compute

$$
(A[0] + A[1] + A[2] + A[3]) + (A[1] + A[2] + A[3] + A[4]),
$$

which double-counts the overlap and is therefore wrong.

So the standard sparse-table `O(1)` query formula is not "for static ranges" in general. It is specifically for **static idempotent range queries**.

## Variant Chooser

Use this page to choose quickly:

### Choose Sparse Table When

- the array is immutable
- the operation is idempotent
- queries are numerous
- you want the simplest `O(1)` static query structure

Canonical examples:

- range minimum
- range maximum
- range gcd
- RMQ layer inside Euler-tour LCA

### Choose Prefix Sums Instead When

- the operation is additive
- queries are just sums or counts
- you do not need `min/max/gcd` style structure

Prefix sums are cheaper:

- `O(n)` preprocess
- `O(1)` query
- `O(n)` memory

So if the task is only about sums, sparse table is overkill.

### Choose Segment Tree Instead When

- updates exist
- or the operation is not idempotent and you still need flexible range queries

Segment tree gives:

- `O(log n)` query
- `O(log n)` updates
- more generality

Sparse table wins on immutable data when query speed and simplicity matter more than update support.

### Choose LCA-By-RMQ View When

- you already have an Euler tour
- the LCA problem has been reduced to "minimum depth on a static interval"

Then sparse table is one clean RMQ backend.

### Think About More Advanced RMQ Structures Only After Sparse Table

There are stronger RMQ constructions with:

- `O(n)` preprocessing
- `O(1)` queries

But for contest practice, sparse table is usually the first correct answer you should be able to deploy from memory.

## Worked Examples

### Example 1: Build A Small RMQ Table By Hand

Take:

$$
A = [5, 2, 7, 1, 3, 6].
$$

#### Row `k = 0`

Length `1` intervals:

```text
st[0] = [5, 2, 7, 1, 3, 6]
```

#### Row `k = 1`

Length `2` intervals:

```text
st[1][0] = min(5, 2) = 2
st[1][1] = min(2, 7) = 2
st[1][2] = min(7, 1) = 1
st[1][3] = min(1, 3) = 1
st[1][4] = min(3, 6) = 3
```

So:

```text
st[1] = [2, 2, 1, 1, 3]
```

#### Row `k = 2`

Length `4` intervals:

```text
st[2][0] = min(st[1][0], st[1][2]) = min(2, 1) = 1
st[2][1] = min(st[1][1], st[1][3]) = min(2, 1) = 1
st[2][2] = min(st[1][2], st[1][4]) = min(1, 3) = 1
```

So:

```text
st[2] = [1, 1, 1]
```

Now query `[1, 5]`:

- length is `5`
- `k = floor(log2 5) = 2`
- take two length-`4` blocks:
  - `[1, 4]`
  - `[2, 5]`

Therefore:

$$
\text{RMQ}(1, 5) = \min(st[2][1], st[2][2]) = \min(1, 1) = 1.
$$

The overlap is `[2, 4]`, and that overlap is harmless because we are taking a minimum.

### Example 2: Static Range GCD

Let:

$$
A = [12, 18, 24, 30].
$$

Query `[1, 3]` asks for:

$$
\gcd(18, 24, 30).
$$

Length is `3`, so `k = 1`. Use the two length-`2` blocks:

- `[1, 2]`
- `[2, 3]`

Then:

$$
\gcd(\gcd(18,24), \gcd(24,30))
=
\gcd(6,6)
= 6.
$$

Again, the middle element `24` appears twice, and that is harmless because:

$$
\gcd(x, x) = x.
$$

### Example 3: Euler Tour + RMQ For LCA

Suppose the Euler tour of a rooted tree is:

```text
E = [0, 1, 3, 1, 4, 1, 0, 2, 5, 2, 0]
```

and the matching depth array is:

```text
D = [0, 1, 2, 1, 2, 1, 0, 1, 2, 1, 0]
```

If the first occurrences are:

- `first[3] = 2`
- `first[4] = 4`

then the LCA of nodes `3` and `4` is the node whose depth is minimum on `D[2..4]`.

That range is:

```text
[2, 1, 2]
```

whose minimum occurs at the middle position, corresponding to node `1`.

So:

$$
\mathrm{LCA}(3, 4) = 1.
$$

This is the cleanest reason sparse table shows up in LCA discussions at all: after Euler tour, the tree part is gone and the remaining task is a static RMQ.

## Algorithm And Pseudocode

Repo starter template:

- [sparse-table-rmq.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/sparse-table-rmq.cpp)

### Build

```text
lg[1] = 0
for len from 2 to n:
    lg[len] = lg[len / 2] + 1

st[0][i] = A[i]

for k from 1 while 2^k <= n:
    for i from 0 while i + 2^k <= n:
        st[k][i] = merge(st[k-1][i], st[k-1][i + 2^(k-1)])
```

### Query

```text
query(l, r):
    k = lg[r - l + 1]
    return merge(st[k][l], st[k][r - 2^k + 1])
```

### Index-Of-Min Variant

For RMQ on values, it is often enough to store the minimum value directly.

For LCA-via-RMQ or any problem where you need the **position** of the winner, store indices instead:

```text
st[k][i] = index of minimum on [i, i + 2^k - 1]
```

and compare by `A[index]`.

## Implementation Notes

### 1. Decide Early: Store Values Or Store Indices

For plain static RMQ, storing values is simplest.

For these tasks, store indices instead:

- Euler-tour LCA
- "return the position of the minimum"
- tie-breaking by smallest index

The invariant stays the same; only the payload changes.

### 2. `lg[len]` Table Versus `__lg`

Both are standard contest choices.

Use a precomputed `lg` table when:

- you want portability and clarity
- you do not want to think about builtin behavior

Use `__lg` when:

- you are already comfortable with GNU-style builtins
- and your codebase is already relying on them

The repo starter template uses the explicit `lg` table, which is the friendlier teaching version.

### 3. Inclusive Ranges Need Discipline

The standard sparse-table formula is usually written for inclusive ranges `[l, r]`.

If you internally prefer half-open ranges `[l, r)`, convert once and keep it consistent.

Most sparse-table bugs are not algorithmic. They are indexing bugs.

### 4. `n` Does Not Need To Be A Power Of Two

You only build entries where the interval fits:

$$
i + 2^k \le n.
$$

That is all.

No padding is required for the standard contest implementation.

### 5. The Table Is Heavy But Predictable

Memory is:

$$
O(n \log n).
$$

That is usually fine for one static array, but it is meaningfully heavier than:

- prefix sums
- Fenwick
- segment tree

So use sparse table because the problem shape fits, not because `O(1)` query sounds nice in isolation.

### 6. Standard Sparse Table Is About Idempotence

This is the conceptual trap that matters most:

- associativity is enough for the build
- idempotence is what makes the overlapping two-block query correct

If the merge is not idempotent, this page's standard query formula is not valid.

### 7. Sparse Table Versus Segment Tree

This is the practical contest comparison:

- sparse table: static only, `O(1)` queries, more preprocessing, more memory
- segment tree: updates allowed, `O(log n)` queries, less memory than `O(n log n)` tables

If the data is immutable and the operation is idempotent, sparse table is often the cleaner choice.

### 8. Sparse Table Versus Fenwick Tree

Fenwick tree is not a competitor for RMQ in the same sense.

Fenwick is best when:

- updates exist
- the operation has a prefix-friendly structure

Sparse table is for a very different shape:

- static
- range query
- idempotent merge

### 9. LCA Backend Choice

For LCA, sparse table is one beautiful backend after Euler tour, but not always the default best contest choice.

Binary lifting may still be preferable when:

- you also need `k`-th ancestor
- memory needs to stay smaller
- you want one tree-native structure instead of an Euler-tour reduction

## Beyond Basic Sparse Table

The core contest layer is:

- static RMQ / range max / range gcd
- Euler-tour LCA backend

Important next-layer directions include:

- **disjoint sparse table**, which supports `O(1)` static queries for any associative operation, not just idempotent ones
- **optimal RMQ structures** with `O(n)` preprocessing and `O(1)` queries

Those are valuable, but the right study order is:

1. internalize the standard sparse-table invariant
2. understand exactly why idempotence is required
3. only then move to disjoint sparse table or optimal RMQ

## Practice Archetypes

The most common sparse-table-shaped tasks are:

- **static range minimum**
- **static range maximum**
- **static range gcd**
- **Euler-tour RMQ for LCA**
- **static query backend inside another immutable preprocessing pipeline**

The strongest contest smell is:

- no updates
- many queries
- and the operation is something like `min`, `max`, or `gcd`

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Course:

- [Stanford CS166: Range Minimum Queries, Part I](https://web.stanford.edu/class/archive/cs/cs166/cs166.1256/lectures/00/)
- [Jeff Erickson, Data Structures Lecture 9: Range-Minimum Queries](https://jeffe.cs.illinois.edu/teaching/225H/notes/RMQ-LCA.pdf)
- [CMU 15-451/651: LCA and RMQ Notes](https://www.cs.cmu.edu/~15451-s15/LectureNotes/lecture26/LCA-RMQ.pdf)

Reference:

- [CP-Algorithms: Sparse Table](https://cp-algorithms.com/data_structures/sparse-table.html)

Practice:

- [CSES Range Queries](https://cses.fi/problemset/list/)

Repo anchors:

- practice ladder: [Sparse Table ladder](../../../practice/ladders/data-structures/sparse-table/README.md)
- practice note: [Static Range Minimum Queries](../../../practice/ladders/data-structures/sparse-table/staticrangeminimumqueries.md)
- starter template: [sparse-table-rmq.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/sparse-table-rmq.cpp)
- related practice note: [Company Queries II](../../../practice/ladders/graphs/lca/companyqueries2.md)
- notebook refresher: [Data Structures cheatsheet](../../../notebook/data-structures-cheatsheet.md)

## Related Topics

- [Segment Tree](../segment-tree/README.md)
- [Fenwick Tree](../fenwick-tree/README.md)
- [Prefix Sums](../../foundations/patterns/prefix-sums/README.md)
- [LCA](../../graphs/lca/README.md)
