# Pairing Heap / Leftist Heap

This lane starts when an ordinary heap is almost enough, but the statement keeps asking for one extra operation:

```text
meld these two heaps
```

The repo keeps the first exact route deliberately narrow:

- one **meldable min-heap**
- every item starts as one singleton heap
- operations are `meld`, `top`, and `delete-min`
- equal keys are tie-broken by item id so owner-tracking stays deterministic

This page is about the contest family:

- **leftist heap** as the first exact starter route
- **pairing heap** as the sibling route you should recognize once the meldable-PQ model is already trusted

It is **not** about:

- ordinary binary heaps in arrays
- predecessor / successor queries
- rank / `k`-th queries
- split / merge ordered sets by key

If the true problem only needs:

- current min / max without meld -> [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md)
- predecessor / successor -> [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md)
- rank or `k`-th -> [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md)

then this lane is heavier than necessary.

## At A Glance

- **Use when:** heaps must support online meld, not just `push / pop / top`
- **Core worldview:** every heap is one tree root, and `merge(a, b)` is the primitive operation everything else reduces to
- **Main tools:** leftist-heap null-path-length invariant, root tie-break by `(key, id)`, DSU-style owner tracking for many singleton heaps
- **Typical complexity:** `O(log n)` meld / delete-min for the leftist exact route
- **Main trap:** forgetting that the hard part is often not `merge` itself, but keeping track of which item currently belongs to which live heap after pops and melds

Strong contest signals:

- "merge the heaps containing `x` and `y`"
- "every node starts as its own priority queue"
- "pop the minimum from the component / clan / army containing `x`"
- "ordinary `priority_queue` logic is right except heaps must also union fast"

Strong anti-cues:

- only one global heap exists
- you need predecessor / floor queries, not meld
- the set is ordered by key and needs rank or `k`-th
- sequence surgery by position is the real invariant -> [Treap / Implicit Treap](../treap-implicit/README.md)

## Prerequisites

- [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md)
- [DSU](../dsu/README.md) just enough to trust owner / representative tracking

Helpful compare points:

- [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md): use this first when meld is not required
- [Treap / Implicit Treap](../treap-implicit/README.md): use this when split/merge happens on ordered sets or sequences rather than heaps
- [Persistent Treap](../persistent-treap/README.md): use this when old versions must survive, not just current meldable heaps

## Problem Model And Notation

Think of the state as a family of heaps:

$$
H_1, H_2, \dots, H_k
$$

with operations like:

- `meld(H_a, H_b)`
- `top(H_a)`
- `pop(H_a)`

In many contest tasks the input is phrased through item ids:

- every item `i` starts in its own heap
- a query names one item `x`
- you must first recover the current heap containing `x`

That is why the first exact route in this repo uses:

- one meldable heap structure
- plus one lightweight owner-tracking layer

## From Brute Force To The Right Idea

### Brute Force

Keep every heap as a `vector` or `multiset`, and when two heaps merge:

- move every element from the smaller structure into the larger

This can pass tiny constraints, but once meld happens many times, repeated full movement becomes too expensive.

### The First Shift

The statement is not asking for:

```text
maintain one priority queue
```

It is asking for:

```text
maintain many priority queues that keep combining
```

So the primitive operation is no longer `push`.
It is:

```text
merge(root_a, root_b)
```

### The Second Shift

Once `merge` is primitive, insert and delete-min are just small wrappers:

- insert = merge the old heap with one singleton node
- delete-min = remove the root, then merge its remaining children

That is the whole meldable-heap mental model.

## Core Technique

The first exact starter route in this repo is a **leftist heap**:

- min-heap ordered by `(key, id)`
- binary-tree shape
- every node stores its `null-path-length` / rank
- after merge, the right spine stays short because the smaller-rank child is forced to the right

The invariant is:

```text
rank(left) >= rank(right)
```

which implies:

- the right spine has logarithmic length
- merge only walks one short path

So the core primitive:

```text
merge(a, b)
```

becomes logarithmic, and everything else follows.

## Pairing Heap As The Sibling Route

The same contest signals also point to **pairing heaps**:

- meld stays extremely short
- delete-min uses the classic two-pass sibling pairing
- the code is often shorter in practice

This repo still starts with **leftist heap** because:

- the exact invariant is easier to reason about under pressure
- worst-case-style contest intuition is cleaner
- the owner-tracking flagship route is easier to teach honestly on top of leftist merge

So the family boundary is:

- **leftist heap** = first exact route here
- **pairing heap** = sibling you should recognize as valid once meldable-PQ modeling is comfortable

## Exact Starter Route In This Repo

- Topic: this page
- Hot sheet: [Pairing / Leftist Heap hot sheet](../../../notebook/pairing-leftist-heap-hot-sheet.md)
- Starter template: [`leftist-heap-meldable-pq.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/leftist-heap-meldable-pq.cpp)
- Flagship anchor: [Mergeable Heap 1](../../../practice/ladders/data-structures/pairing-leftist-heap/mergeableheap1.md)

The starter is intentionally honest:

- it is a **leftist heap** route, not a generic abstract heap library
- it assumes every item is pre-created and identified by id
- it exposes `meld`, `top`, and `delete-min from the heap containing x`
- it does **not** promise persistence, decrease-key, or arbitrary erase

## Flagship Modeling: Mergeable Heap 1

The cleanest first rep in this repo is:

- [Mergeable Heap 1](../../../practice/ladders/data-structures/pairing-leftist-heap/mergeableheap1.md)

Why it fits:

- every item starts as a singleton heap
- one operation melds the heaps containing `x` and `y`
- the other operation deletes the current minimum from the heap containing `x`
- deleted items must be rejected later

That is exactly the first route:

- meldable min-heap
- DSU-style owner lookup
- deterministic root tie-break under equal keys

## Complexity And Tradeoffs

For the exact leftist route:

- `merge`: `O(log n)`
- `delete-min`: `O(log n)`
- `top`: `O(1)` after owner lookup
- owner lookup: inverse-Ackermann path compression overhead

Practical tradeoffs:

| Route | Best when | Main tradeoff |
| --- | --- | --- |
| leftist heap | you want a crisp structural invariant and a deterministic exact route | slightly more code than a pairing heap |
| pairing heap | meldable PQ is right and you want the shortest practical code | delete-min is usually taught amortized and is less "first-proof" friendly |
| `priority_queue` + no meld | there is only one heap or meld never happens | impossible to union heaps cleanly |
| multiset / ordered set | you need sorted-neighbor logic, predecessor, or erase-one by value | does not model heap meld as the primitive |

## Main Pitfalls

- forgetting to ignore operations on deleted items
- not tie-breaking equal keys by id, so future owner behavior becomes unstable
- merging heaps by moving all elements instead of merging roots
- confusing DSU representative tracking with heap parent pointers
- trying to stretch this route into arbitrary erase or decrease-key without redesigning the structure

## Practice

### First In Repo

- [Mergeable Heap 1](../../../practice/ladders/data-structures/pairing-leftist-heap/mergeableheap1.md)

### Strong Follow-Ups

- [P1456 - Monkey King](https://www.luogu.com.cn/problem/P1456)
- [P2713 - Roman Game](https://www.luogu.com.cn/problem/P2713)

## Retrieval Map

- quick recall -> [Pairing / Leftist Heap hot sheet](../../../notebook/pairing-leftist-heap-hot-sheet.md)
- reusable route -> [`leftist-heap-meldable-pq.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/leftist-heap-meldable-pq.cpp)
- broader chooser -> [Data structures cheatsheet](../../../notebook/data-structures-cheatsheet.md)
- routing layer -> [Template Library](../../../template-library.md), [Build Kit](../../../docs/build-kit.md)

## References And Repo Anchors

Reference / practice:

- [OI Wiki - Leftist Tree](https://en.oi-wiki.org/ds/leftist-tree/)
- [OI Wiki - Pairing Heap](https://en.oi-wiki.org/ds/pairing-heap/)
- [Luogu P3377 - Mergeable Heap 1](https://www.luogu.com.cn/problem/P3377)

Repo anchors:

- starter template: [`leftist-heap-meldable-pq.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/leftist-heap-meldable-pq.cpp)
- ladder: [Pairing Heap / Leftist Heap ladder](../../../practice/ladders/data-structures/pairing-leftist-heap/README.md)
- notebook refresher: [Pairing / Leftist Heap hot sheet](../../../notebook/pairing-leftist-heap-hot-sheet.md)

## Related Topics

- [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md)
- [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md)
- [Treap / Implicit Treap](../treap-implicit/README.md)
