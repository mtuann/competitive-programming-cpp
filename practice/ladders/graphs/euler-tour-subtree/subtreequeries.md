# SUBTREEQUERIES - Subtree Queries

- Title: `Subtree Queries`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1137](https://cses.fi/problemset/task/1137)
- Secondary topics: `Euler tour flattening`, `Subtree interval`, `Fenwick tree`
- Difficulty: `medium`
- Subtype: `Point assignment updates and subtree-sum queries on a rooted tree`
- Status: `solved`
- Solution file: [subtreequeries.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/euler-tour-subtree/subtreequeries.cpp)

## Why Practice This

This is the cleanest in-repo anchor for the subtree-flattening lane.

The tree is static, the root is fixed, and the two operations are exactly the ones that make the reduction feel natural:

- change the value of one node
- ask the sum of one subtree

So the real lesson is not a new range data structure.

It is:

- how to flatten a subtree into one interval
- how to store each node at exactly one entry time
- how point assignment becomes a point delta update after flattening

## Recognition Cue

Reach for subtree flattening when:

- the statement asks about the descendants of one node again and again
- subtree queries are many, but the tree edges never change
- the query target is one rooted subtree, not an arbitrary path
- once flattened, the remaining array problem is only point update + range sum

The strong smell here is:

- "change one node value, then ask the sum of node `s` and all its descendants"

That is the textbook `Euler flattening + Fenwick` route.

## Problem-Specific Transformation

Root the tree at node `1`.

Run one DFS and record:

- `tin[u]`: first-entry time of node `u`
- `tout[u]`: timer after finishing the subtree of `u`

Then keep:

$$
flat[tin[u]] = value[u]
$$

Now the subtree of `u` is exactly:

$$
[tin[u], tout[u])
$$

So the statement becomes:

- type `1 s x`: set one array position `tin[s]` to `x`
- type `2 s`: sum one interval `[tin[s], tout[s])`

That is just a range-query problem on a flattened array.

## Core Idea

In single-entry DFS order, every node in the subtree of `u` is visited before DFS can return to the parent of `u`.

So all descendants of `u` occupy one contiguous interval in the entry-order array.

That means:

- subtree query -> one range query
- point update on node `u` -> one point update at `tin[u]`

The reusable data structure is then simple:

- use a Fenwick tree over the flattened array
- store the current value of each node
- convert assignment `value[u] = x` into delta:

$$
\Delta = x - value[u]
$$

and add `Δ` at `tin[u]`

The important invariant is:

```text
the tree reasoning ends at the flattening step;
after that, the only live query primitive is interval sum on [tin[u], tout[u])
```

## Complexity

- flattening DFS: `O(n)`
- Fenwick build: `O(n log n)` in the straightforward version
- each point assignment update: `O(log n)`
- each subtree sum query: `O(log n)`
- memory: `O(n)`

This is comfortably fast for the CSES limits.

## Pitfalls / Judge Notes

- The tree is rooted at `1`; subtree language depends on that fixed root.
- Use a **single-entry** DFS order for subtree intervals.
- Keep subtree ranges half-open: `[tin[u], tout[u])`.
- For assignment updates, remember to store current values so you can compute the Fenwick delta.
- Iterative DFS is a safe choice here because `n` can reach `2 * 10^5`.

## Reusable Pattern

- Topic page: [Euler Tour / Subtree Queries](../../../../topics/graphs/euler-tour-subtree/README.md)
- Practice ladder: [Euler Tour / Subtree Queries ladder](README.md)
- Starter template: [euler-tour-subtree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/euler-tour-subtree.cpp)
- Notebook refresher: [Subtree Queries hot sheet](../../../../notebook/subtree-queries-hot-sheet.md)
- Compare points: [Trees](../../../../topics/graphs/trees/README.md), [Fenwick Tree](../../../../topics/data-structures/fenwick-tree/README.md), [Path Queries II](../hld/pathqueries2.md)
- This note adds: the cleanest route where rooted subtree structure is reduced to one Fenwick-backed range query.

## Solutions

- Code: [subtreequeries.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/euler-tour-subtree/subtreequeries.cpp)
