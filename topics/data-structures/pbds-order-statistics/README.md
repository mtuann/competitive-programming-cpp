# PBDS / Order Statistics Tree

This lane is for the moment when an ordinary ordered set is almost enough, but the statement keeps asking for:

- the `k`-th smallest alive element
- the number of alive elements `< x`
- rank queries after updates
- one dynamic ordered set where brute-force indexing is too slow

The repo's exact first route for this family is:

- starter -> [pbds-ordered-set.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/pbds-ordered-set.cpp)
- flagship note -> [ORDERSET - Order Statistic Set](../../../practice/ladders/data-structures/pbds-order-statistics/orderset.md)
- compare point -> [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md)
- compare point -> [Fenwick Tree](../fenwick-tree/README.md)

This lane is intentionally about the **contest-useful GNU PBDS route**, not about re-teaching red-black trees from scratch.

## At A Glance

- **Use when:** one dynamic ordered set needs online rank or `k`-th queries
- **Core worldview:** keep the set sorted and maintain subtree sizes so rank and `k`-th become logarithmic tree descents
- **Main tools:** `order_of_key`, `find_by_order`, and a pair-key wrapper when duplicates matter
- **Typical complexity:** `O(log n)` per insert / erase / rank / `k`-th operation
- **Main trap:** forgetting that raw `tree<T, ...>` is a set, so duplicates need a wrapper such as `(value, unique_id)`

Strong contest signals:

- "print the `k`-th remaining element"
- "how many active values are strictly smaller than `x`?"
- "maintain salaries / ratings / scores under updates and answer rank-count queries"
- "ordered set is right, but predecessor alone is not enough"

Strong anti-cues:

- you only need predecessor / successor / erase-one -> plain [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md)
- the value universe is compressible and only prefix counts matter -> [Fenwick Tree](../fenwick-tree/README.md)
- the real task is static subarray order statistics -> [Wavelet Tree](../wavelet-tree/README.md)
- the structure is really a mutable sequence by position rather than a value-ordered set -> [Treap / Implicit Treap](../treap-implicit/README.md)

## Prerequisites

- [C++ Language For Contests](../../foundations/cpp-language/README.md) at the level of reading one GNU-only extension without fear
- [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md) because you should already know when ordinary `set` / `multiset` is enough
- [Fenwick Tree](../fenwick-tree/README.md) as the best compare route when compression turns the same rank-count story into prefix sums

Helpful compare points:

- [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md): use this first when neighbor queries are enough
- [Fenwick Tree](../fenwick-tree/README.md): use this when counts live on one compressed coordinate axis and prefix sums already solve the query
- [Treap / Implicit Treap](../treap-implicit/README.md): use this when split/merge or sequence surgery is the real need, not just order statistics
- [Wavelet Tree](../wavelet-tree/README.md): use this when the array is static and the query is inside one subarray, not one evolving ordered set
- [Balanced BSTs For Contests](../balanced-bsts/README.md): use this if you deliberately want the AVL / Red-Black / Scapegoat / SBT compare note and the broader textbook balancing map

## Problem Model And Notation

Let `S` be one dynamic ordered set or multiset.

The two canonical order-statistics queries are:

$$
\operatorname{rank}(x) = |\{y \in S : y < x\}|
$$

and

$$
\operatorname{kth}(k)
$$

for the element with zero-based order `k` in sorted order.

The ordinary online operations are:

- `insert(x)`
- `erase(x)` or `erase_one(x)`
- `count_less(x)`
- `count_leq(x)`
- `kth(k)`

The exact PBDS primitive names are:

- `order_of_key(x)` -> number of keys strictly smaller than `x`
- `find_by_order(k)` -> iterator to the zero-based `k`-th key

That is the whole contest contract.

## From Brute Force To The Right Idea

### Brute Force

Keep all active values in a `vector` and:

- insert / erase in `O(n)`
- sort when needed
- answer `k`-th or rank queries by indexing after re-sort

This fails as soon as updates and queries interleave many times.

### The First Shift

The statement is not about one array. It is about **one changing sorted set**.

If the real questions are:

- how many active values are `< x`?
- what is the `k`-th active value right now?

then the sorted order itself is the state that matters.

### The Second Shift

An ordinary `set` already keeps sorted order, but it does not expose rank or `k`-th directly.

PBDS adds exactly that extra layer by attaching an order-statistics policy to the tree.

So the contest pivot is:

```text
ordered set + subtree-size aware rank queries
```

not:

```text
invent a new balanced BST from scratch
```

## Core Invariant And Why It Works

The structural invariant is:

```text
the tree stores all live keys in sorted order
```

The order-statistics invariant is:

```text
every node knows the size of its subtree
```

That is enough for both core queries.

### 1. Why `order_of_key(x)` Works

To count how many keys are `< x`, the tree descends by comparisons:

- if the current key is `< x`, then its whole left subtree also counts
- otherwise only the left branch can still contribute

Subtree sizes make those whole-branch contributions `O(1)` at each step.

### 2. Why `find_by_order(k)` Works

If the left subtree has size `L`:

- `k < L` -> go left
- `k = L` -> current node is the answer
- `k > L` -> go right with `k -= L + 1`

Again, the only extra ingredient is subtree size.

### 3. Why Duplicates Need A Wrapper

Raw PBDS ordered trees are **sets**, not multisets.

So if duplicates matter, the correct contest trick is:

$$
(value, unique\_id)
$$

ordered lexicographically.

That turns equal values into distinct keys while preserving value order.

Then:

- `count_less(x)` becomes `order_of_key((x, -INF))`
- `count_leq(x)` becomes `order_of_key((x, +INF))`
- `erase_one(x)` means erase the first pair whose first component is `x`

That is the exact bridge from pure set semantics to duplicate-safe multiset semantics.

## Worked Examples

### Example 1: ORDERSET

This repo's flagship note:

- [ORDERSET - Order Statistic Set](../../../practice/ladders/data-structures/pbds-order-statistics/orderset.md)

The whole problem is exactly the family:

- insert if absent
- delete if present
- print the `k`-th smallest
- count how many values are `< x`

That is the cleanest first benchmark because no extra modeling hides the PBDS lane.

### Example 2: Salary Queries

Suppose salaries update online and each query asks:

$$
\#\{salary \in [a, b]\}
$$

This is still one order-statistics problem.

With the duplicate-safe pair wrapper:

- erase the old salary of employee `i`
- insert the new salary
- answer with:

$$
\operatorname{count\_leq}(b) - \operatorname{count\_less}(a)
$$

This is the exact bridge from unique ordered sets to duplicate-safe ordered multisets.

### Example 3: Josephus Problem II

Maintain the alive positions:

$$
\{1, 2, \dots, n\}
$$

At each step:

- compute the next removal index modulo current size
- remove `*find_by_order(idx)`

This is the cleanest first `find_by_order`-heavy benchmark.

So the same family supports:

- rank by value
- `k`-th by sorted order
- cyclic elimination on alive indices

## Complexity And Tradeoffs

For the first-order PBDS lane:

- insert: `O(log n)`
- erase: `O(log n)`
- `order_of_key`: `O(log n)`
- `find_by_order`: `O(log n)`
- memory: `O(n)`

Tradeoffs:

- very clean for contest problems that truly want rank or `k`-th online
- GNU-specific, so it is not portable ISO C++
- not the best first choice when a compressed Fenwick tree already gives simpler prefix-count logic
- not a replacement for split/merge BST families such as treap

## Starter Fit

The starter in this repo is intentionally practical rather than maximal.

It exposes:

- `ordered_set<T>` for the raw unique-key PBDS route
- `OrderedMultiset<T>` for duplicate-safe contest use

The duplicate-safe wrapper gives:

- `insert(x)`
- `erase_one(x)`
- `count_less(x)`
- `count_leq(x)`
- `count_in_range(l, r)`
- `kth_value(k, out)`

It does **not** try to teach:

- custom node updates
- portable self-balanced BST implementations
- split/merge BST design

If you need those, leave this lane and reopen:

- [Treap / Implicit Treap](../treap-implicit/README.md)
- [Link-Cut Tree](../../graphs/link-cut-tree/README.md) if the ordered set is only preparatory machinery and the real problem has already become dynamic-tree path logic

## Retrieval Layer

- quick sheet -> [Order Statistics Tree hot sheet](../../../notebook/order-statistics-tree-hot-sheet.md)
- exact starter -> [pbds-ordered-set.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/pbds-ordered-set.cpp)
- flagship note -> [ORDERSET - Order Statistic Set](../../../practice/ladders/data-structures/pbds-order-statistics/orderset.md)
- compare route -> [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md)
- compare route -> [Fenwick Tree](../fenwick-tree/README.md)
- broader chooser -> [Data structures cheatsheet](../../../notebook/data-structures-cheatsheet.md)

## Exit Criteria

You are ready to move on when:

- you can explain the difference between predecessor queries and order-statistics queries
- you know when `order_of_key` beats `lower_bound`-style reasoning
- you remember that duplicates need the pair-key wrapper
- you can recognize when compressed prefix counts are simpler than PBDS

## References And Repo Anchors

Research sweep refreshed on `2026-04-25`.

Primary / reference:

- [GCC libstdc++: `tree_order_statistics_node_update`](https://gcc.gnu.org/onlinedocs/libstdc%2B%2B/ext/pb_ds/tree_order_statistics_node_update.html)
- [GCC libstdc++ PBDS manual](https://gcc.gnu.org/onlinedocs/gcc-9.3.0/libstdc%2B%2B/manual/manual/policy_data_structures.html)
- [Competitive Programmer's Handbook](https://cses.fi/book/book.pdf)

Practice:

- [ORDERSET - Order Statistic Set](https://www.spoj.com/problems/ORDERSET/)
- [CSES - Josephus Problem II](https://cses.fi/problemset/task/2163)
- [CSES - Salary Queries](https://cses.fi/problemset/task/1144)

Repo anchors:

- starter template: [pbds-ordered-set.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/pbds-ordered-set.cpp)
- ladder: [PBDS / Order Statistics Tree ladder](../../../practice/ladders/data-structures/pbds-order-statistics/README.md)
- notebook refresher: [Order Statistics Tree hot sheet](../../../notebook/order-statistics-tree-hot-sheet.md)
- flagship note: [ORDERSET - Order Statistic Set](../../../practice/ladders/data-structures/pbds-order-statistics/orderset.md)

## Related Topics

- [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md)
- [Fenwick Tree](../fenwick-tree/README.md)
- [Treap / Implicit Treap](../treap-implicit/README.md)
- [Wavelet Tree](../wavelet-tree/README.md)
