# Interval Trees

This lane is for the moment interval work stops being about:

- one offline sort
- one greedy schedule over already-known intervals
- or one static range structure over a compressed coordinate line

and becomes about:

- one **live set of intervals**
- online insert / erase
- and repeated **any-overlap** queries against a new interval

The repo's exact first route for this family is:

- starter -> [interval-tree-overlap-treap.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/interval-tree-overlap-treap.cpp)
- flagship note -> [Reservation System](../../../practice/ladders/data-structures/interval-trees/reservationsystem.md)
- compare point -> [Balanced BSTs For Contests](../balanced-bsts/README.md)
- compare point -> [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md)
- compare point -> [ODT / Chtholly](../odt-chtholly/README.md)

This lane intentionally teaches the **half-open interval, any-overlap, augmented-BST route first**.
It does not start from interval stabbing counts, segment coverage aggregates,
weighted interval scheduling, or piecewise-constant range assignment.

## At A Glance

- **Use when:** one dynamic interval set must answer "does anything overlap `[l, r)`?" online
- **Core worldview:** keep intervals ordered by left endpoint and augment every subtree with the maximum right endpoint inside it
- **Main tools:** lexicographic BST order on `(l, r)`, subtree `max_r`, and overlap checks on half-open intervals
- **Typical complexity:** expected `O(log n)` per insert / erase / overlap query in the repo's treap-balanced starter
- **Main trap:** reaching for this when predecessor/successor on already-disjoint intervals or one offline sweep already closes the whole problem

Strong contest signals:

- "book this interval if it does not overlap anything already booked"
- "intervals are inserted and erased online"
- "find any conflicting interval"
- "the data is a set of intervals, not one array over a fixed coordinate universe"

Strong anti-cues:

- intervals are already disjoint and you only need predecessor/successor checks -> [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md)
- all queries are offline -> [Offline Tricks](../offline-tricks/README.md)
- the real state is one piecewise-constant partition under range assign -> [ODT / Chtholly](../odt-chtholly/README.md)
- the real query is aggregate coverage / count / maximum on a fixed coordinate line -> [Segment Tree](../segment-tree/README.md) or [Lazy Segment Tree](../lazy-segment-tree/README.md)

## Prerequisites

- [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md), because predecessor/successor reasoning over one ordered set should already feel natural
- [Balanced BSTs For Contests](../balanced-bsts/README.md), at least at the level of being comfortable with BST augmentation as a design move
- [Treap / Implicit Treap](../treap-implicit/README.md) helps, because the repo starter balances the interval tree with treap priorities instead of hand-coding AVL / Red-Black rotations

Helpful compare points:

- [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md): use this first when the live intervals are guaranteed disjoint and one predecessor/successor neighbor check is enough
- [ODT / Chtholly](../odt-chtholly/README.md): use this when the true state is one interval partition of values, not one arbitrary set of geometric intervals
- [Segment Tree](../segment-tree/README.md): use this when the line is fixed and you need range aggregates rather than one explicit interval-set witness

## Problem Model And Notation

We store one set of half-open intervals:

$$
[l, r) \quad \text{with } l < r
$$

Two intervals overlap iff:

$$
\max(l_1, l_2) < \min(r_1, r_2).
$$

The canonical task in this lane is:

- insert interval `[l, r)`
- erase exact interval `[l, r)`
- answer whether any stored interval overlaps a query interval `[ql, qr)`

The repo starter keeps intervals ordered by `(l, r)` inside a BST-like structure.

## From Brute Force To The Right Augmentation

### Brute Force

Store all intervals in one vector and scan every interval on every query.

That gives:

$$
O(n)
$$

per overlap query, which is too slow once updates and queries both scale.

### Why Plain BST Order Is Not Enough

If intervals are arbitrary, ordering only by left endpoint does **not** let you
skip whole subtrees safely.

You need one extra summary:

- for every subtree, the maximum right endpoint among all intervals inside it

Call that summary `max_r`.

### The Interval-Tree Insight

Suppose you are checking overlap with query `[ql, qr)`.

- if the left subtree has `max_r <= ql`, then **nothing** in that left subtree can overlap the query
- if the current node starts at `l >= qr`, then neither the current node nor anything in the right subtree can overlap the query

That is the whole pruning engine.

So the useful state is:

- BST order by `(l, r)`
- subtree `max_r`

and not a richer segment algebra.

## Core Invariants And Why They Matter

The repo starter keeps four contest-facing invariants.

### 1. BST Order On `(l, r)`

Intervals are ordered lexicographically:

- smaller `l` first
- break ties by `r`

That makes exact insert / erase well defined for one interval set.

### 2. Every Node Stores `max_r`

For one node `v`:

$$
v.max\_r = \max(v.r,\; v.left.max\_r,\; v.right.max\_r).
$$

This is the augmentation that turns the tree into an interval tree.

### 3. `left.max_r <= ql` Kills The Whole Left Subtree

If every interval in the left subtree ends at or before `ql`, then none of them
can overlap `[ql, qr)`.

So the search can skip that whole branch.

### 4. `current.l >= qr` Kills The Whole Right Side

Because the tree is ordered by left endpoint:

- every interval in the right subtree starts at least at `current.l`

So if `current.l >= qr`, neither the current node nor the right subtree can
overlap the query.

That is why the search remains logarithmic in the balanced setting.

## Complexity And Tradeoffs

With the repo's treap-balanced starter:

- insert: expected `O(log n)`
- erase exact interval: expected `O(log n)`
- any-overlap query: expected `O(log n)`

Rule of thumb:

- live interval set + any-overlap predicate -> this lane
- live intervals stay pairwise disjoint and you only need the neighbor around one start time -> [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md)
- interval endpoints are all known first -> [Offline Tricks](../offline-tricks/README.md)
- fixed coordinate universe with aggregate coverage queries -> [Segment Tree](../segment-tree/README.md) or [Lazy Segment Tree](../lazy-segment-tree/README.md)

## Worked Examples

### Example 1: Repo Canonical Benchmark

This repo's flagship note:

- [Reservation System](../../../practice/ladders/data-structures/interval-trees/reservationsystem.md)

The benchmark is intentionally gentle:

- one new reservation `[a, b)`
- one current set of existing reservations
- output whether any overlap exists

This benchmark can also be solved by a lighter ordered-set neighbor check,
which is exactly why the note is useful:

- it drills the **overlap predicate and augmentation**
- while also teaching when interval trees are slightly overkill

### Example 2: Why This Is Not ODT

If the problem is really:

- an array of values
- range assign / recolor / overwrite
- and later walks or statistics over the current runs

then the structure is not "one arbitrary interval set".

That is:

- [ODT / Chtholly](../odt-chtholly/README.md)

### Example 3: Why This Is Not Segment Tree First

If the query is:

- how many points are covered
- or what is the maximum cover count
- or one range sum / max / minimum over a fixed coordinate line

then the true invariant is aggregate line information, not one stored interval
set with overlap witnesses.

That points to:

- [Segment Tree](../segment-tree/README.md)
- [Lazy Segment Tree](../lazy-segment-tree/README.md)

## Repo Starter Contract

The starter:

- uses half-open intervals `[l, r)`
- assumes `l < r`
- stores one set of **unique exact interval pairs** `(l, r)`
- exposes:
  - `insert_interval(l, r)`
  - `erase_interval(l, r)`
  - `any_overlap(ql, qr)`
  - `find_any_overlap(ql, qr, out)`

If exact duplicates matter in your problem, the simplest extension is:

- attach one unique id to each inserted interval
- and order by `(l, r, id)` instead of only `(l, r)`

That extension is intentionally left outside the first route.

## Main Traps

- mixing closed-interval and half-open-interval overlap semantics
- forgetting to recompute `max_r` after rotations / merges
- thinking interval trees are automatically the best answer whenever the word "interval" appears
- using this for static offline scheduling where sorting already wins
- using this for range aggregates where segment trees are the real tool

## Reopen Paths

- quick recall -> [Interval Tree hot sheet](../../../notebook/interval-tree-hot-sheet.md)
- BST-family compare note -> [Balanced BSTs For Contests](../balanced-bsts/README.md)
- lighter ordered-set route -> [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md)
- split/merge-first BST family -> [Treap / Implicit Treap](../treap-implicit/README.md)
- interval-partition sibling -> [ODT / Chtholly](../odt-chtholly/README.md)
- offline neighbor / sweep alternatives -> [Offline Tricks](../offline-tricks/README.md)

## References And Repo Anchors

Reference / practice:

- [Introduction to Algorithms, 4th ed. TOC PDF](https://mitp-content-server.mit.edu/books/content/sectbyfn/books_pres_0/11599/4e_toc.pdf)
- [AOJ 0360 - Reservation System](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0360)

Repo anchors:

- [Interval Tree hot sheet](../../../notebook/interval-tree-hot-sheet.md)
- [Reservation System](../../../practice/ladders/data-structures/interval-trees/reservationsystem.md)
- [Balanced BSTs For Contests](../balanced-bsts/README.md)
- [Treap / Implicit Treap](../treap-implicit/README.md)
