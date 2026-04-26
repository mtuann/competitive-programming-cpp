# X-Fast / Y-Fast Tries

This lane is for the moment integer ordered-set work stops being about:

- one ordinary `O(log n)` tree
- or one xor-greedy bit trie

and becomes about:

- **bounded integer universe**
- prefix hashing by bit length
- and predecessor / successor in doubly-logarithmic time in the bit width

The repo's exact first route for this family is:

- starter -> [x-fast-trie.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/x-fast-trie.cpp)
- flagship note -> [X-Fast Dictionary](../../../practice/ladders/data-structures/x-fast-y-fast-tries/xfastdictionary.md)
- compare point -> [Binary Trie / XOR Queries](../binary-trie-xor/README.md)
- compare point -> [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md)
- compare point -> [Skip Lists](../skip-lists/README.md)

This lane intentionally teaches the **x-fast trie predecessor / successor route first**.
It does not start from y-fast bucket sampling, van Emde Boas trees, or cache-conscious implementation details.

## At A Glance

- **Use when:** the keys are non-negative integers from one fixed-width universe and predecessor / successor is the real lesson
- **Core worldview:** store all existing prefixes in hash tables by depth, binary-search the deepest existing prefix, and use a linked leaf order to finish predecessor / successor
- **Main tools:** fixed bit width, per-level prefix hash tables, leaf linked list, and one jump pointer per internal node
- **Typical complexity:** x-fast gives `O(log w)` search / predecessor / successor with `O(w)` insert / erase and `O(nw)` space; y-fast improves this to expected `O(log w)` updates with `O(n)` space
- **Main trap:** using this family when the actual need is just one ordinary ordered set or one xor-max bit trie

Strong study signals:

- "the keys come from `[0, U)` and `U` is the real parameter"
- "predecessor / successor is the point, not rank / `k`-th"
- "I want the classical ODS x-fast / y-fast story"

Strong anti-cues:

- the task is `max xor` against one stored value -> [Binary Trie / XOR Queries](../binary-trie-xor/README.md)
- the task wants online rank / `k`-th -> [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md)
- the task only needs one contest ordered set and the universe bound is irrelevant -> [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md)
- the keys are not bounded integers in the first place

## Prerequisites

- [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md), because the baseline ordered-set interface should already be familiar
- [Binary Trie / XOR Queries](../binary-trie-xor/README.md), because x-fast still starts from a bit-prefix tree worldview
- [Skip Lists](../skip-lists/README.md) helps as a compare note, because both families are textbook breadth routes that are usually not first-line contest retrieval

Helpful compare points:

- [Binary Trie / XOR Queries](../binary-trie-xor/README.md): same fixed-width bit view, but the query objective is xor-greedy rather than predecessor / successor
- [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md): use this when dynamic order statistics matter more than bounded-universe asymptotics
- [Skip Lists](../skip-lists/README.md): use this when the lesson is probabilistic ordered dictionaries rather than bounded-universe prefix hashing
- [B-Trees](../b-trees/README.md): use this when high fanout and multiway search are the real breadth lesson

## Problem Model And Notation

Assume one set `S` of non-negative integers from:

$$
[0, 2^w)
$$

with one fixed bit width `w`.

The canonical task in this lane is:

- `contains(x)`
- `insert(x)`
- `erase_one(x)`
- `predecessor(x)`
- `successor(x)`

The repo starter uses set semantics:

- duplicate inserts are ignored
- erase on a missing key is a no-op that returns `false`
- predecessor / successor are strict and may not exist

## From Binary Trie To X-Fast Trie

### Plain Binary Trie

A plain binary trie over width `w` already gives:

- membership by descending `w` bits
- predecessor / successor in `O(w)` if the navigation support is implemented carefully

That is good enough when:

- `w` is tiny
- or xor objectives dominate

but it does not yet exploit the fact that whole prefixes can be indexed directly.

### The X-Fast Insight

Store every existing prefix of every stored key in one hash table per depth.

Then, for a query `x`:

1. binary-search the deepest prefix of `x` that exists
2. stop at the highest node where the next branch is missing
3. finish predecessor / successor from a linked leaf order

So the structure is no longer:

- just one trie walk of length `w`

It becomes:

- one binary search over levels
- plus one local leaf-order repair step

That is where the `O(log w)` search bound comes from.

### Why The Leaf List Matters

If the search stops at a node whose next desired child is missing, we need the nearest stored keys around that gap.

That is why x-fast keeps:

- all leaves linked in sorted order
- one jump pointer at internal nodes that have exactly one child

The leaf order is what turns "deepest existing prefix" into one actual predecessor or successor key.

## Why Y-Fast Exists

The cost of x-fast is:

- `O(nw)` space
- and `O(w)` update work because a whole root-to-leaf prefix chain is explicit

Y-fast keeps the same bounded-universe philosophy, but changes the storage plan:

- keep only sampled representatives in an x-fast trie
- keep the full keys inside small balanced buckets

So the first real y-fast lesson is:

```text
y-fast = x-fast over bucket representatives + one ordinary ordered set per bucket
```

That improves the family to:

- expected `O(log w)` search / predecessor / successor / insert / erase
- `O(n)` space

This repo still teaches x-fast first because:

- the bit-prefix and leaf-jump mechanics are the conceptual core
- y-fast makes more sense only after that core is already stable

## Core Invariants And Why They Matter

The repo starter keeps four contest-facing invariants.

### 1. Prefix Tables Are Exact

For every depth `d`, the hash table for level `d` stores exactly the trie nodes whose first `d` bits exist among current keys.

That is what makes binary search on depth valid.

### 2. Leaves Stay Linked In Sorted Order

All present keys appear as leaf nodes in one doubly-linked sorted list.

That is what makes predecessor / successor extraction local once the missing branch is identified.

### 3. A One-Child Internal Node Stores A Jump

If an internal node has only:

- a left child, its jump points to the largest leaf in that subtree
- a right child, its jump points to the smallest leaf in that subtree

That is the bridge from "missing next branch" to the nearest stored key on the surviving side.

### 4. Universe Width Is Fixed

Every key is interpreted with the same bit width.

Without that, prefixes at equal depths no longer mean the same thing, so the whole hash-by-depth model breaks.

## Complexity And Tradeoffs

For one fixed width `w`:

- x-fast membership / predecessor / successor: `O(log w)`
- x-fast insert / erase: `O(w)`
- x-fast space: `O(nw)`

Y-fast improves the family to:

- expected `O(log w)` for all main ordered-set operations
- `O(n)` space

Rule of thumb:

- explicit bounded-universe predecessor / successor breadth -> this lane
- ordinary contest ordered set -> [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md) or `set`
- bitwise xor optimization -> [Binary Trie / XOR Queries](../binary-trie-xor/README.md)

## Worked Examples

### Example 1: Repo Canonical Benchmark

This repo's flagship note:

- [X-Fast Dictionary](../../../practice/ladders/data-structures/x-fast-y-fast-tries/xfastdictionary.md)

The benchmark is intentionally canonical:

- `+ x`
- `- x`
- `? x`
- `< x`
- `> x`

So the whole focus is:

- prefix tables
- leaf links
- predecessor / successor under one fixed-width universe

### Example 2: Why This Is Not Binary Trie First

If the real task is:

- "maximize `x xor y`"
- or "best xor partner among stored values"

then the route is not x-fast.

That is:

- [Binary Trie / XOR Queries](../binary-trie-xor/README.md)

### Example 3: Why This Is Not PBDS First

If the real task is:

- online rank
- `k`-th
- count smaller

then the bounded-universe prefix tables are not the cleanest abstraction.

That is:

- [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md)

## Repo Starter Contract

The starter:

- stores one set of unique non-negative integers
- assumes keys are in `[0, 2^31)`
- supports:
  - `contains(x)`
  - `insert(x)`
  - `erase_one(x)`
  - strict predecessor
  - strict successor
- advertises the x-fast route honestly

What it does **not** advertise:

- y-fast bucket maintenance
- rank / `k`-th
- xor-max queries

## Main Traps

- forgetting that this family only makes sense over one bounded integer universe
- mixing x-fast predecessor / successor with xor-trie thinking
- overclaiming y-fast support when the starter only implements x-fast
- using this under contest pressure when PBDS or `set` is shorter and safer

## Reopen Paths

- quick recall -> [X-Fast / Y-Fast hot sheet](../../../notebook/x-fast-y-fast-hot-sheet.md)
- xor-bit route -> [Binary Trie / XOR Queries](../binary-trie-xor/README.md)
- contest-first ordered set -> [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md)
- probabilistic breadth sibling -> [Skip Lists](../skip-lists/README.md)
