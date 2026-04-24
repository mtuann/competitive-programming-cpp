# Offline Tricks

Offline techniques are the modeling move where you stop asking:

- "how do I maintain this online after every query?"

and start asking:

- "if all queries are known first, can I reorder the work so the state only moves in one easy direction?"

That shift is often enough to turn a problem that looks like:

- dynamic range queries
- dynamic connectivity
- repeated threshold decisions

into one of:

- a sorted sweep
- a Fenwick pass
- a DSU sweep by threshold
- a batched decision framework such as parallel binary search
- or a local add/remove order such as Mo's algorithm

This topic is not one algorithm. It is a family of reductions whose common benefit is:

- replace hard online maintenance with easier batched structure changes

## At A Glance

- **Use when:** all queries are known before any answer must be produced, and reordering them makes the maintained state simpler
- **Core worldview:** reorder the work, not the output; the answers still go back to original query order
- **Main tools:** sorting by endpoint or threshold, event sweeps, DSU, Fenwick tree, add/remove range maintenance, batched monotone decisions
- **Typical payoff:** simpler invariants and lighter data structures than the fully online version
- **Main trap:** reordering queries whose answers depend on previous answers, or getting equal-key event ordering wrong

## Problem Model And Notation

Think of the input as containing:

- a set of **events** that make information available
- a set of **queries** that ask for the answer after some subset of those events should have taken effect

Each query has:

- a **key** that determines when it becomes answerable in the reordered pass
- an **original index** so the final output can be restored

For a right-endpoint sweep, the key is often:

$$
r.
$$

For a threshold sweep, the key is often:

$$
x.
$$

The whole offline idea is to build a pass where:

- the maintained state changes monotonically with the key
- each query is answered exactly when the sweep has incorporated everything that should affect it

## From Brute Force To The Right Idea

### Brute Force: Answer In Input Order

The most literal reading of many query problems is:

- read one query
- update the data structure
- answer immediately
- move to the next query

That forces you to solve the fully online version of the problem.

Sometimes that is necessary.

But if:

- all queries are known in advance
- answers do not affect future queries
- only the final output order matters

then insisting on input order is usually self-inflicted difficulty.

### The First Shift: Reordering Is Part Of The Algorithm

Offline problems are not "almost online."

They are problems where the legal algorithm is allowed to:

- sort queries
- batch them
- interleave them with events in a better order

and only later restore the original order of answers.

This is not bookkeeping around the algorithm. It is the algorithm.

### The Second Shift: Look For A Monotone Sweep Key

Most successful offline reductions come from identifying one key that only moves forward:

- right endpoint
- left endpoint
- threshold value
- time segment in divide-and-conquer over queries

Once the key is monotone, the maintained state often becomes simple:

- a Fenwick tree of currently active contributions
- a DSU containing all edges with weight at most the current threshold
- a current range `[L, R]` that only moves locally between neighboring queries

### The Third Shift: One Family, Several Shapes

There are several common offline shapes:

- **sorted sweep:** sort queries by a key and process events once
- **endpoint sweep:** answer range queries when the sweep reaches `r`
- **threshold sweep:** activate edges/items as a threshold grows
- **local reordering:** Mo's algorithm minimizes total pointer movement between range queries
- **batched monotone decisions:** parallel binary search asks many "first time true" questions together
- **time segmentation:** offline deletion / rollback DSU turns add-delete-query timelines into interval assignments

The unifying skill is recognizing that the online order is not sacred.

## Core Invariants And Why They Work

### 1. Reordering Is Legal Only If Query Semantics Are Order-Independent

You may reorder computation only when each answer depends on:

- the underlying input
- and the query itself

not on previously printed answers or interactive feedback.

If the statement is interactive, adaptive, or explicitly depends on earlier outputs, offline processing is not legal.

### 2. Sorted Sweep Invariant

The basic offline invariant has this shape:

```text
After processing all events with key <= K,
the data structure represents exactly the contribution of those events.
```

Then any query whose answer depends exactly on events with key at most `K` can be answered immediately.

This is why endpoint sweeps and threshold sweeps work.

### 3. Original Order Restoration Is Part Of Correctness

Suppose query `q_i` is processed third after sorting, but appears seventeenth in the statement.

The correct algorithm does not print the third processed answer in third position. It stores:

$$
\text{ans}[i].
$$

So every offline query needs one stable identifier:

- original query id

Without that, the algorithm is not merely inconvenient. It is wrong.

### 4. Equal-Key Policy Matters

When events and queries share the same key, the processing order at ties is often part of the invariant.

Typical examples:

- for threshold `<= x`, activate all events with key `<= x` before answering queries at `x`
- for a strict `< x` condition, answer first, then activate key `x`

Many offline bugs are not complexity mistakes. They are tie-policy mistakes.

### 5. Mo's Algorithm Uses Locality Instead Of Monotone Activation

Mo's algorithm is still offline, but the invariant is different.

You do not maintain "all events up to key `K`."

Instead you maintain:

- the exact current answer for one active range `[L, R]`

and reorder queries so the total movement of `L` and `R` is small.

It belongs to the same family because:

- all queries are known first
- reordering them simplifies maintenance cost

### 6. Parallel Binary Search Uses Batched Monotone Decisions

Suppose each query asks:

- what is the first step / threshold / time where a monotone predicate becomes true?

Then instead of binary-searching each query independently, you can:

- group many queries by current midpoint
- process one batch pass
- split queries left or right together

The same offline principle appears again:

- spend one structured pass on many queries at once

## Variant Chooser

### Use Right-Endpoint Sweep When

- each query is about a static subarray `[l, r]`
- the information needed for a query is complete once the sweep reaches `r`
- updates can be expressed as point/range changes caused by seeing `a[r]`

Canonical examples:

- distinct values in subarrays
- offline frequency/count questions with a "latest active occurrence" invariant

This is the cleanest first offline pattern to learn.

### Use Threshold Sweep With DSU Or BIT When

- items become active when some threshold is reached
- queries ask about the world under one threshold `x`
- activation is monotone in sorted order

Canonical examples:

- connectivity using edges with weight `<= x`
- counting values `<= x`
- processing events by compressed coordinate

The state usually becomes:

- DSU for connectivity
- Fenwick / segment tree for additive counts

### Use Mo's Algorithm When

- the online range structure is hard
- but adding or removing one endpoint is cheap
- and queries are all static over the same array

Canonical smells:

- the answer for `[L, R]` can be updated in `O(1)` or `O(log n)` after moving one boundary by one step
- there is no monotone sweep that makes all updates one-directional

Mo's algorithm is often the right fallback when:

- endpoint sorting alone is not enough
- but full dynamic maintenance is still too heavy

### Use Parallel Binary Search When

- each query asks for the smallest value where a monotone predicate becomes true
- checking one midpoint for many queries can be batched efficiently

Canonical smells:

- "first time", "minimum answer", "smallest threshold"
- decision version is easy
- optimization version repeated per query would be too expensive

### Use Offline Deletion / Rollback Structures When

- updates and deletions both exist
- but the whole timeline is known in advance
- each update is active on an interval of time

Then the right model is often:

- assign each active interval to nodes of a segment tree over time
- traverse the tree with rollback DSU or another rollback-friendly structure

This is the "next layer" after the simpler sorted sweeps.

## Worked Examples

### Example 1: Distinct Values Queries

This is the canonical right-endpoint sweep in the repo:

- [Distinct Values Queries](../../../practice/ladders/data-structures/offline-tricks/distinctvaluesqueries.md)

Take an array `a[1..n]`. For each value, keep only its **latest active occurrence** marked as `1`; older occurrences are marked as `0`.

When the sweep reaches position `r`:

- every value contributes exactly one active mark at its last occurrence in `[1, r]`

So for a query `[l, r]`, the number of distinct values is exactly:

$$
\sum_{i=l}^{r} \text{active}[i].
$$

The invariant is:

```text
After processing position r,
Fenwick stores one active 1 at the latest occurrence of each value seen so far.
```

That is why answering a query at its right endpoint is correct.

### Example 2: Threshold Connectivity

Suppose each query asks:

- are `u` and `v` connected using only edges with weight `<= x`?

Sort:

- edges by weight
- queries by threshold `x`

Sweep thresholds upward. Before answering a query at `x`, unite every edge whose weight is at most `x`.

Invariant:

```text
DSU contains exactly the edges with weight <= current threshold.
```

Then the query answer is just:

- `find(u) == find(v)`

This is far simpler than maintaining general dynamic connectivity online.

### Example 3: Why Equal-Key Policy Matters

Suppose the question is:

- count elements with value `<= x`

If an event has key exactly `x`, then it must be activated **before** answering the query.

If the question were instead:

- count elements with value `< x`

then equal-key events must be excluded.

So the correct event/query order at tied keys depends on the exact inequality in the statement.

### Example 4: When Mo's Algorithm Beats A Sweep

Suppose the answer on `[L, R]` depends on:

- counts of frequencies inside the current range
- and changing the range by one endpoint is cheap

But there is no good monotone notion of "all information up to key `K`."

Then a one-directional sweep may not exist.

Mo's algorithm solves this by reordering queries so the active range changes gradually:

- add one element
- remove one element
- keep the current answer updated

The invariant is not threshold-based. It is range-based.

### Example 5: Parallel Binary Search

Suppose many queries ask for the first answer `ans_i` such that a monotone property becomes true.

Instead of doing:

- one binary search per query

do this:

- group all queries whose current midpoint is `mid`
- run one batch check for `mid`
- split queries into left/right buckets

The key idea is still offline:

- many queries share the same expensive state-building pass

## Algorithm And Pseudocode

Repo starter template:

- [offline-query-skeleton.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/offline-query-skeleton.cpp)

### Generic Sorted Sweep

```text
attach original id to every query
sort events by key
sort queries by key

ptr = 0
for q in sorted queries:
    while ptr < events.size and event[ptr] should be active for q:
        apply event[ptr] to the data structure
        ptr++
    ans[q.id] = answer current query from the data structure
```

The whole problem is hidden in two design choices:

- what the key is
- what invariant the data structure should represent at each key

### Parallel Binary Search Skeleton

```text
while some queries still have lo < hi:
    bucket queries by mid = (lo + hi) / 2
    rebuild one batched structure pass
    for mids in increasing order:
        apply enough events to reach this mid
        test all queries in this bucket
        send each query left or right
```

This is conceptually different from a sorted sweep, but the same batching mindset appears again.

### Mo's Algorithm Skeleton

```text
sort queries by (block_of_L, then R with the chosen block order)
current range = empty
current answer = answer on empty range

for q in sorted queries:
    while current L > q.L: add(--L)
    while current R < q.R: add(++R)
    while current L < q.L: remove(L++)
    while current R > q.R: remove(R--)
    ans[q.id] = current answer
```

The hidden contract is:

- `add(pos)` and `remove(pos)` must update the same maintained statistic consistently
- the active range after the loop really is exactly `[q.L, q.R]`

### Offline Deletion / Rollback DSU Sketch

```text
for each update:
    determine the time interval where it is active
    add that update to all segment-tree-over-time nodes covering the interval

dfs(node):
    apply this node's updates to the rollback-friendly structure
    if node is a leaf:
        answer all queries at this time
    else:
        dfs(left child)
        dfs(right child)
    rollback all updates added at this node
```

This is the cleanest mental model for:

- add / delete / query timelines
- dynamic connectivity asked offline
- any structure that can undo changes exactly

## Implementation Notes

### 1. Original Index Is Mandatory

Every offline query structure should store:

- the key used for processing
- the original query index

Do not leave that to the very end as an afterthought.

### 2. Tie Policy Must Match The Inequality In The Statement

Always ask:

- should key `x` events be included in a query at `x`?

That determines whether equal-key events go:

- before the query
- or after it

### 3. Coordinate Compression Often Belongs Naturally Here

Offline passes frequently sort:

- values
- endpoints
- thresholds

So coordinate compression is often almost free and helps:

- Fenwick indexing
- event bucketing
- value-based sweeps

### 4. Choose Offline Only If The State Truly Simplifies

Not every problem with all queries known in advance should be solved offline.

Go offline when reordering buys one of:

- monotone activation
- cheap add/remove updates
- batched midpoint testing
- rollback over time intervals

If the reordered state is still complicated, the offline move may not be the right abstraction.

### 5. Mo's Algorithm Needs Symmetric Add / Remove Logic

Before choosing Mo, verify that you can support both:

- add one element to the current range
- remove one element from the current range

cleanly and cheaply.

If `add` is easy but `remove` is painful, a different offline strategy may be better.

### 6. Rollback-Friendly Structures Must Avoid Irreversible Compression

For rollback DSU and similar patterns, path compression is usually avoided or used carefully because rollback must undo state exactly.

This is a common place where "the normal online optimization" stops being compatible with the offline time-segmentation framework.

## Practice Archetypes

The most common offline-tricks-shaped tasks are:

- **static range queries answered by endpoint sweep**
- **threshold activation queries**
- **range queries with cheap add/remove updates**
- **first true answer per query via batched binary search**
- **dynamic add/delete/query timelines handled offline**

Strong contest smells include:

- "all queries are given first"
- "the online version feels harder than the intended difficulty"
- sorting by one coordinate seems to make updates one-directional
- decision checks are easy, but independent searches would repeat too much work

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Research:

- [David Eppstein: Persistence, Offline Algorithms, and Space Compaction](https://ics.uci.edu/~eppstein/pubs/Epp-TR-91-54.pdf)

Reference:

- [CP-Algorithms: Deleting from a data structure in $O(T(n)\log n)$](https://cp-algorithms.com/data_structures/deleting_in_log_n.html)
- [USACO Guide: Offline Deletion](https://usaco.guide/adv/offline-del)
- [OI Wiki: Mo's Algorithm](https://en.oi-wiki.org/misc/mo-algo-intro/)
- [AlgoWiki: Parallel Binary Search](https://wiki.algo.is/Parallel%20binary%20search/)

Practice:

- [CSES Range Queries](https://cses.fi/problemset/list/)
- [Library Checker: Static Range Count Distinct](https://judge.yosupo.jp/problem/static_range_count_distinct)
- [Codeforces 86D: Powerful Array](https://codeforces.com/problemset/problem/86/D)

Repo anchors:

- practice ladder: [Offline Tricks ladder](../../../practice/ladders/data-structures/offline-tricks/README.md)
- practice note: [Distinct Values Queries](../../../practice/ladders/data-structures/offline-tricks/distinctvaluesqueries.md)
- starter template: [offline-query-skeleton.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/offline-query-skeleton.cpp)
- notebook refresher: [Data Structures cheatsheet](../../../notebook/data-structures-cheatsheet.md)
- adjacent topic: [Fenwick Tree](../fenwick-tree/README.md)
- adjacent topic: [DSU](../dsu/README.md)

## Related Topics

- [Fenwick Tree](../fenwick-tree/README.md)
- [DSU](../dsu/README.md)
- [Sorting](../../foundations/patterns/sorting/README.md)
- [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md)
- [Graph Modeling](../../graphs/graph-modeling/README.md)
