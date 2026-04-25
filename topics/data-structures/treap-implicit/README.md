# Treap / Implicit Treap

Treap is the randomized split/merge family for two different but related jobs:

- **key-based treap**: ordered-set operations where explicit key order still matters
- **implicit treap**: sequence operations where the "key" is the element position and should not be stored explicitly

The repo now has two exact starter routes inside the same family:

- key-based route -> [treap-key-ordered-set.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/treap-key-ordered-set.cpp) -> [Salary Queries](../../../practice/ladders/data-structures/treap-implicit/salaryqueries.md)
- implicit route -> [implicit-treap-sequence.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/implicit-treap-sequence.cpp) -> [Cut and Paste](../../../practice/ladders/data-structures/treap-implicit/cutandpaste.md)
- compare points -> [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md), [Persistent Treap](../persistent-treap/README.md), [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md), [Lazy Segment Tree](../lazy-segment-tree/README.md)

This lane matters when arrays are too rigid and ordered sets are too weak:

- arrays make insert / erase / cut / paste by position cost `O(n)`
- ordinary ordered sets do not naturally model "the 37th element of the current sequence"

Treap fixes that by combining:

- BST order
- heap order on random priorities

and then reusing one pair of core operations:

- `split`
- `merge`

## At A Glance

- **Use when:** one mutable sequence needs insert / erase / cut / paste / split / merge by position, or an ordered set needs split/merge by key
- **Core worldview:** priorities choose the shape, while BST order or implicit position determines the in-order sequence
- **Main tools:** randomized priorities, subtree sizes, split, merge, and optional lazy tags later
- **Typical complexity:** expected `O(log n)` per split/merge/insert/erase
- **Main trap:** mixing up key-based split conventions and implicit split conventions as if they were the same API

Strong contest signals:

- "cut a substring and paste it somewhere else"
- "ordered set is right, but I want a self-hosted split/merge tree instead of PBDS"
- "insert / erase at position `i`"
- "split one sequence into two, then merge back in a different order"
- "a balanced BST with split/merge would be cleaner than fighting `std::set`"

Strong anti-cues:

- the structure is fixed-length and only needs range aggregates -> [Segment Tree](../segment-tree/README.md) or [Lazy Segment Tree](../lazy-segment-tree/README.md)
- you only need predecessor / successor / erase-one in value order -> [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md)
- the array is static -> [Wavelet Tree](../wavelet-tree/README.md), [Sparse Table](../sparse-table/README.md), or offline lanes
- the task never splits or merges a sequence, only scans or updates fixed indices

## Prerequisites

- [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md)
- [Segment Tree](../segment-tree/README.md)
- [Randomized Algorithms](../../advanced/randomized-algorithms/README.md) as the best conceptual neighbor for why random priorities keep the height small in expectation

Helpful compare points:

- [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md): use this first when plain `set / multiset / priority_queue` already solves the problem
- [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md): use this first when GNU PBDS already gives a simpler exact route for rank / `k`-th
- [Persistent Treap](../persistent-treap/README.md): use this when old sequence versions stay alive and split/merge itself must be non-destructive
- [Lazy Segment Tree](../lazy-segment-tree/README.md): use this when indices are fixed and only interval aggregates/updates matter
- [Lexicographic Enumeration](../../combinatorics/lexicographic-enumeration/README.md): sequence order reasoning sometimes appears, but the data-structure need is different
- [Balanced BSTs For Contests](../balanced-bsts/README.md): use this if you want the AVL / Red-Black / Scapegoat / SBT compare note and the broader map of textbook balanced-BST variants

## Problem Model And Notation

There are two variants to keep separate.

### 1. Key-Based Treap

Each node stores:

- one explicit key `key`
- one random priority `prior`

The in-order traversal is the sorted order by `key`.

This fits:

- ordered-set split by key
- merge of two disjoint key ranges

### 2. Implicit Treap

Each node stores:

- payload value
- random priority
- subtree size

But **not** the position key itself.

Instead, a node's implicit position is:

```text
all nodes in its left subtree
+ all nodes in left subtrees of ancestors where this node sits in the right branch
+ those ancestors themselves
```

That means position can be recovered while descending, so insert/erase by position stays logarithmic.

The implicit starter in this repo uses zero-based half-open sequence ranges `[l, r)`.

It supports:

- `insert(pos, c)`
- `erase(pos)`
- `cut_paste_to_end(l, r)`
- `to_string()`

That is the exact route for [Cut and Paste](../../../practice/ladders/data-structures/treap-implicit/cutandpaste.md).

## From Brute Force To The Right Idea

### Brute Force On Arrays

Suppose a sequence must support:

- cut substring `[l, r)`
- paste it elsewhere

With a plain array or string, one operation can shift:

$$
O(n)
$$

elements.

That is too slow once both:

- `n`
- number of operations

reach `2 * 10^5`.

### Why Ordered Sets Alone Do Not Fix It

An ordered set is good when the identity of an element is:

- its value key

But in sequence tasks, the identity is often:

- current position in the sequence

If one insertion near the front shifts all later positions, storing explicit indices becomes awkward.

### The Structural Observation

If a structure can answer:

- first `k` elements
- remaining elements

as a split, then cut/paste becomes simple:

1. split before `l`
2. split before `r`
3. rearrange the three pieces with merges

So the whole lane reduces to:

```text
make split and merge cheap while keeping the tree balanced
```

### The Treap Trick

Treap stores:

- BST/sequence order invariant
- heap invariant on random priorities

The priority decides shape probabilistically, which keeps expected height near logarithmic.

Then:

- `split` peels one tree into two
- `merge` glues two valid trees into one

Everything else is built from those two primitives.

## Core Invariant And Why It Works

## 1. Two Invariants For Ordinary Treap

For key-based treap:

- BST property on explicit keys
- heap property on priorities

That means:

- in-order traversal is sorted by key
- the highest-priority node in a subtree becomes its root

## 2. Why Split Works

For key-based treap:

```text
split(root, x)
```

returns:

- left tree = keys `< x`
- right tree = keys `>= x`

Only one root-to-leaf path is rewired, so the operation stays logarithmic in expected height.

For implicit treap:

```text
split(root, k)
```

returns:

- left tree = first `k` sequence elements
- right tree = the rest

The only difference is the routing test:

- use subtree sizes instead of explicit keys

## 3. Why Merge Works

If every key in `A` belongs before every key in `B`, then:

```text
merge(A, B)
```

chooses the root with larger priority and recursively merges the remaining child.

Because both inputs already satisfy the treap invariants, the result does too.

For implicit treap, the same merge works because sequence order is:

- all of left sequence
- then all of right sequence

No explicit key comparison is needed.

## 4. Why Subtree Size Is Mandatory For Implicit Treap

Implicit key is not stored.

So at any node, the count:

$$
size(left)
$$

tells us how many sequence elements come before the current node inside this subtree.

That is exactly the information split-by-position needs.

The invariant is:

```text
size[v] = true number of live nodes in subtree v
```

Every merge and split must repair this with one `pull`.

## 5. Why Expected Height Stays Small

Random priorities make the treap behave like a randomized BST / heap merge structure.

The shape is not chosen by the adversarial insertion order alone, so expected height is logarithmic.

This is the family reason treap works at all.

## Worked Examples

### Example 1: Key-Based Split By Value

Suppose the treap stores keys:

$$
\{2, 5, 8, 11, 14\}
$$

Calling:

```text
split(root, 9)
```

should produce:

- left = `{2, 5, 8}`
- right = `{11, 14}`

This is the right treap flavor when:

- explicit key order is the point
- split/merge by key is cleaner than fighting `std::set`

This repo's exact first key-based anchor is:

- [Salary Queries](../../../practice/ladders/data-structures/treap-implicit/salaryqueries.md)

### Example 2: Implicit Cut And Paste

Take the sequence:

```text
AYBABTU
```

and cut positions `[2, 5)` zero-based:

```text
YBA
```

Split into:

- left = `A`
- mid = `YBA`
- right = `BTU`

Then merge:

```text
left + right + mid
```

to get:

```text
ABTUYBA
```

The sequence changed, but no element stored an explicit mutable index.

That is exactly why implicit treap exists.

## Algorithm And Pseudocode

### Key-Based Split / Merge

```text
split_by_key(t, x):
    if t is null:
        return (null, null)
    if t.key < x:
        (a, b) = split_by_key(t.right, x)
        t.right = a
        pull(t)
        return (t, b)
    else:
        (a, b) = split_by_key(t.left, x)
        t.left = b
        pull(t)
        return (a, t)

merge(a, b):
    if a is null: return b
    if b is null: return a
    if a.prior > b.prior:
        a.right = merge(a.right, b)
        pull(a)
        return a
    else:
        b.left = merge(a, b.left)
        pull(b)
        return b
```

### Implicit Split By Position

```text
split_by_pos(t, k):
    if t is null:
        return (null, null)

    left_size = size(t.left)
    if k <= left_size:
        (a, b) = split_by_pos(t.left, k)
        t.left = b
        pull(t)
        return (a, t)
    else:
        (a, b) = split_by_pos(t.right, k - left_size - 1)
        t.right = a
        pull(t)
        return (t, b)
```

### Cut And Paste To End

For zero-based half-open `[l, r)`:

```text
(a, bc) = split(root, l)
(b, c) = split(bc, r - l)
root = merge(merge(a, c), b)
```

That one identity is the first exact pattern worth memorizing in this lane.

## Variant Chooser

### Use Key-Based Treap When

- explicit value order is still the intended order
- you need split / merge by key
- `std::set` gives predecessor/successor, but not the structural operations cleanly enough

### Use Implicit Treap When

- the real key is current sequence position
- sequence edits shift later positions
- cut / paste / insert / erase by position are central

This is the exact first implicit route in this repo.

### Prefer PBDS When

- the task is fundamentally online rank / `k`-th on one ordered set
- GNU PBDS is allowed
- you do not need a self-hosted split/merge structure

The clean compare point is:

- [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md)

### Prefer Ordered Sets When

- you only need predecessor / successor / erase-one / top-k style set behavior
- no sequence surgery or split/merge by structure is required

In C++, plain ordered sets are usually the lighter first choice.

### Prefer Segment Tree / Lazy Segment Tree When

- the sequence length is fixed
- positions are stable
- interval aggregate/update is the real job

Treap shines when:

- sequence structure itself changes

not just values on a fixed index line.

### Reopen The Topic Before Reusing The Starter When

- you need range sums, min/max, reverse tags, or affine lazy tags
- the problem is really a stronger implicit-treap-with-lazy lane
- you need the key-based starter, not the sequence starter

The two starters here are intentionally narrow:

- [treap-key-ordered-set.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/treap-key-ordered-set.cpp):
  ordered-set-by-key, expected `O(log n)` insert / erase / rank / `k`-th
- [implicit-treap-sequence.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/implicit-treap-sequence.cpp):
  sequence surgery by position

Neither starter pretends to cover the whole family.

## Implementation Notes

### 1. Use One `pull` Discipline

Every place that rewires children must repair:

- subtree size

If you later add aggregates, `pull` is where they belong too.

### 2. Keep Position Convention Explicit

The starter uses:

- zero-based positions
- half-open `[l, r)`

Contest statements often use:

- one-based inclusive intervals

Convert at the call site.

### 3. Do Not Store Explicit Indices In Implicit Treap

That defeats the whole purpose.

The position is recovered from subtree sizes while descending.

### 4. Random Priorities Must Be Stable Enough

Use one RNG and assign one priority per node at creation time.

Do not recompute priorities later.

### 5. The First Starter Is Sequence-Surgery-First

The repo starter intentionally covers:

- build from one initial string
- insert one character at position
- erase one position
- move one substring to the end

That keeps the first route honest and easy to trust.

## Practice Archetypes

### First Rep In This Repo

- [Salary Queries](../../../practice/ladders/data-structures/treap-implicit/salaryqueries.md)
- [Cut and Paste](../../../practice/ladders/data-structures/treap-implicit/cutandpaste.md)

### Best Compare Points In This Repo

- [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md)
- [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md)
- [Lazy Segment Tree](../lazy-segment-tree/README.md)

### Good External Follow-Ups

- [CSES - Substring Reversals](https://cses.fi/problemset/task/2073)
- [CSES - Reversals and Sums](https://cses.fi/problemset/task/2074)
- [Library Checker - Dynamic Sequence Range Affine Range Sum](https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum)

## References

- [USACO Guide: Treaps](https://usaco.guide/adv/treaps)
- [CP-Algorithms: Treap](https://cp-algorithms.com/data_structures/treap.html)
- [CSES - Cut and Paste](https://cses.fi/problemset/task/2072)

## Repo Anchors

- [Treap / Implicit Treap ladder](../../../practice/ladders/data-structures/treap-implicit/README.md)
- [Treap / Implicit Treap hot sheet](../../../notebook/treap-hot-sheet.md)
- [Exact key-based starter](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/treap-key-ordered-set.cpp)
- [Exact implicit starter](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/implicit-treap-sequence.cpp)
- [Salary Queries note](../../../practice/ladders/data-structures/treap-implicit/salaryqueries.md)
- [Cut and Paste note](../../../practice/ladders/data-structures/treap-implicit/cutandpaste.md)
- Compare points:
  - [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md)
  - [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md)
  - [Lazy Segment Tree](../lazy-segment-tree/README.md)
  - [Randomized Algorithms](../../advanced/randomized-algorithms/README.md)
