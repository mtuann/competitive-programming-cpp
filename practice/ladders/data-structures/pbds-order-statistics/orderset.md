# ORDERSET - Order Statistic Set

- Title: `ORDERSET - Order Statistic Set`
- Judge / source: `SPOJ`
- Original URL: [https://www.spoj.com/problems/ORDERSET/](https://www.spoj.com/problems/ORDERSET/)
- Secondary topics: `PBDS`, `Ordered set`, `k-th smallest`, `count smaller`
- Difficulty: `medium`
- Subtype: `Dynamic ordered set with insert / delete / k-th / rank queries`
- Status: `solved`
- Solution file: [orderset.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/pbds-order-statistics/orderset.cpp)

## Why Practice This

This is the cleanest first exact benchmark for the PBDS lane.

The statement is almost the family definition:

- insert if absent
- delete if present
- print the `k`-th smallest
- count how many values are `< x`

So the real lesson is not hidden in extra modeling.

It is:

- one dynamic ordered set is the whole state
- `order_of_key` directly answers the rank side
- `find_by_order` directly answers the `k`-th side

## Recognition Cue

Reach for PBDS / order-statistics trees when:

- the set changes online
- plain predecessor or successor is not enough
- the query asks for rank or `k`-th under the current active values
- sorting from scratch after each update is too slow

The strongest smell here is:

- "dynamic set + `k`-th smallest + count smaller than `x`"

That is the canonical first order-statistics-tree problem.

## Problem-Specific Transformation

Maintain one ordered set `S` of the currently alive values.

The statement gives four operations:

- `I x` -> `insert x` if absent
- `D x` -> erase `x` if present
- `K k` -> if `k > |S|`, print `invalid`; otherwise print the one-based `k`-th smallest
- `C x` -> print the number of values `< x`

Under PBDS, that becomes:

- `S.insert(x)`
- `S.erase(x)`
- `*S.find_by_order(k - 1)`
- `S.order_of_key(x)`

Now the original problem is no longer "simulate a sorted container somehow."

It becomes:

- maintain one live sorted tree
- use subtree-size-aware order statistics for rank and `k`-th queries

## Core Idea

Two PBDS primitives solve the whole task.

### `order_of_key(x)`

Returns:

$$
|\{y \in S : y < x\}|
$$

So this is exactly the `C x` query.

### `find_by_order(k)`

Returns an iterator to the zero-based `k`-th smallest element.

So the `K k` query becomes:

- check `k - 1 < S.size()`
- print `*find_by_order(k - 1)`

The only subtlety is indexing:

- statement uses one-based `k`
- PBDS uses zero-based order

## Complexity

- insert: `O(log n)`
- delete: `O(log n)`
- `order_of_key`: `O(log n)`
- `find_by_order`: `O(log n)`
- memory: `O(n)`

## Pitfalls / Judge Notes

- This problem is a **set**, not a multiset, so duplicate inserts should do nothing.
- `find_by_order` is zero-based; the statement's `K k` is one-based.
- Print `invalid` if `k` exceeds the current size.
- `C x` is strictly smaller than `x`, not `<= x`.
- PBDS is a GNU extension, so this exact route assumes the contest toolchain allows it.

## Reusable Pattern

- Topic page: [PBDS / Order Statistics Tree](../../../../topics/data-structures/pbds-order-statistics/README.md)
- Practice ladder: [PBDS / Order Statistics Tree ladder](README.md)
- Starter template: [pbds-ordered-set.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/pbds-ordered-set.cpp)
- Notebook refresher: [Order Statistics Tree hot sheet](../../../../notebook/order-statistics-tree-hot-sheet.md)
- Compare points:
  - [Heaps And Ordered Sets](../../../../topics/data-structures/heaps-and-ordered-sets/README.md)
  - [Fenwick Tree](../../../../topics/data-structures/fenwick-tree/README.md)
- Carry forward: when one live ordered set needs online rank or `k`-th, use order statistics instead of rebuilding sorted order manually.
- This note adds: the exact one-based vs zero-based conversion for `k`-th queries under raw set semantics.

## Solutions

- Code: [orderset.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/pbds-order-statistics/orderset.cpp)
