# Skip Lists

This lane is for the moment ordered-dictionary work stops being about:

- deterministic binary balancing
- or one library-backed contest ordered set

and becomes about:

- **probabilistic balancing**
- towers of forward pointers
- and expected-time search / insert / erase without tree rotations

The repo's exact first route for this family is:

- starter -> [skiplist-ordered-set.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/skiplist-ordered-set.cpp)
- flagship note -> [Skiplist Dictionary](../../../practice/ladders/data-structures/skip-lists/skiplistdictionary.md)
- compare point -> [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md)
- compare point -> [Treap / Implicit Treap](../treap-implicit/README.md)
- compare point -> [B-Trees](../b-trees/README.md)

This lane intentionally teaches the **search + insert + erase-one ordered-set route first**.
It does not start from indexable skiplists, skiplist lists, concurrency, or
lock-free engineering details.

## At A Glance

- **Use when:** you explicitly want skiplist mechanics, or one textbook breadth lane for probabilistic ordered dictionaries
- **Core worldview:** each element gets a random height, higher levels sparsify the search path, and updates splice one tower into multiple forward lists
- **Main tools:** sentinel head, random level generation, one `update[]` path, and expected `O(log n)` search / insert / erase
- **Typical complexity:** expected `O(log n)` per operation with `O(n)` space
- **Main trap:** reaching for skiplists in ordinary CP ordered-set tasks where PBDS, treap, or plain `set` is shorter and more standard

Strong study signals:

- "I want the classical skiplist story from ODS / Pugh"
- "probabilistic balancing is the lesson, not tree rotations"
- "I want one ordered dictionary breadth lane outside BSTs"

Strong anti-cues:

- online rank / `k`-th is the real invariant -> [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md)
- split / merge is the real primitive -> [Treap / Implicit Treap](../treap-implicit/README.md)
- high-fanout pages and split-full-child are the real lesson -> [B-Trees](../b-trees/README.md)
- ordinary ordered-set work under contest pressure is the actual need -> [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md)

## Prerequisites

- [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md), because the baseline ordered-set interface should already feel natural
- [Balanced BSTs For Contests](../balanced-bsts/README.md) helps as a compare note, because skip lists occupy a similar "breadth ordered dictionary" slot without being tree-based

Helpful compare points:

- [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md): use this when contest code wants rank / `k`-th right now
- [Treap / Implicit Treap](../treap-implicit/README.md): use this when self-hosted split/merge is the real abstraction
- [B-Trees](../b-trees/README.md): use this when high fanout and node splitting are the real breadth lesson

## Problem Model And Notation

The canonical task in this lane is one ordered set with:

- `insert(x)`
- `erase_one(x)`
- `contains(x)`

The repo starter uses set semantics:

- duplicate inserts are ignored
- erase on a missing key is a no-op that returns `false`

The skiplist keeps:

- one sentinel head node
- forward pointers on levels `0 .. h`
- one random height for each inserted node

## From Sorted Linked List To Skiplist

### Plain Sorted Linked List

If keys are kept in one sorted linked list:

- search is `O(n)`
- insert is `O(n)`
- erase is `O(n)`

because locating the position dominates.

### The Skiplist Insight

Add extra forward pointers so some nodes appear on higher levels.

Then a search path can:

- move right while the next key is still too small
- drop one level when it would overshoot

The structure becomes a probabilistically balanced tower system.

### Why Updates Stay Simple

During search, store the last node visited on each level in `update[level]`.

Then:

- insertion splices the new node after those predecessors on every owned level
- deletion bypasses the node from those same predecessors

That is the whole implementation payoff compared with many tree-based routes.

## Core Invariants And Why They Matter

The repo starter keeps four contest-facing invariants.

### 1. Every Level Is Sorted

Each forward list is sorted by key.

That is what makes rightward motion safe.

### 2. Higher Levels Are Subsequences Of Lower Levels

If a node appears on level `r`, it also appears on all levels below `r`.

That is what makes "move right, then drop down" preserve correctness.

### 3. Random Heights Create Sparse Upper Levels

Each node height is chosen by repeated coin-flip style logic.

That gives:

- many level-0 nodes
- fewer level-1 nodes
- fewer level-2 nodes

and so on, which is where expected logarithmic search comes from.

### 4. `update[]` Must Match The Search Path

Before an insert or erase:

- `update[r]` stores the rightmost node before the target position on level `r`

This is the one local state that makes splicing correct across all levels.

## Complexity And Tradeoffs

With the repo starter:

- search: expected `O(log n)`
- insert: expected `O(log n)`
- erase-one: expected `O(log n)`
- space: expected `O(n)`

Rule of thumb:

- explicit probabilistic ordered-dictionary breadth -> this lane
- ordinary contest ordered-set work -> [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md) or `set`
- self-hosted split/merge route -> [Treap / Implicit Treap](../treap-implicit/README.md)

## Worked Examples

### Example 1: Repo Canonical Benchmark

This repo's flagship note:

- [Skiplist Dictionary](../../../practice/ladders/data-structures/skip-lists/skiplistdictionary.md)

The benchmark is intentionally canonical:

- `+ x`
- `- x`
- `? x`

So the whole focus is:

- search path
- `update[]`
- random height

### Example 2: Why This Is Not PBDS First

If the real task is:

- `order_of_key`
- `find_by_order`
- rank or `k`-th

then the repo would not teach skiplist first.

That is:

- [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md)

### Example 3: Why This Is Not Treap First

If the real task is:

- split by key
- merge
- persistence
- or sequence surgery

then probabilistic forward towers are not the right abstraction.

That is:

- [Treap / Implicit Treap](../treap-implicit/README.md)

## Repo Starter Contract

The starter:

- stores one ordered set of unique keys
- supports:
  - `contains(x)`
  - `insert(x)`
  - `erase_one(x)`
- uses probabilistic heights with one fixed maximum level

That contract is enough for:

- textbook skiplist ordered-set search
- straightforward insert / erase splicing
- one canonical breadth benchmark

## Main Traps

- forgetting that expected-time analysis depends on random heights, not worst-case deterministic balancing
- corrupting `update[]` and then splicing on the wrong predecessors
- using skip lists because they sound advanced when PBDS or treap is the cleaner CP route
- treating this as a first-line contest lane instead of breadth coverage

## Reopen Paths

- quick recall -> [Skiplist hot sheet](../../../notebook/skiplist-hot-sheet.md)
- contest-first ordered-set route -> [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md)
- self-hosted split/merge route -> [Treap / Implicit Treap](../treap-implicit/README.md)
- high-fanout breadth sibling -> [B-Trees](../b-trees/README.md)

## References And Repo Anchors

Reference / practice:

- [Open Data Structures - 4. Skiplists](https://opendatastructures.org/ods-cpp/4_Skiplists.html)
- [Skip Lists: A Probabilistic Alternative to Balanced Trees](https://epaperpress.com/sortsearch/download/skiplist.pdf)

Repo anchors:

- [Skiplist hot sheet](../../../notebook/skiplist-hot-sheet.md)
- [Skiplist Dictionary](../../../practice/ladders/data-structures/skip-lists/skiplistdictionary.md)
- [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md)
- [Treap / Implicit Treap](../treap-implicit/README.md)
