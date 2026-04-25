# Tree Distances II

- Title: `Tree Distances II`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1133](https://cses.fi/problemset/task/1133)
- Secondary topics: `Rerooting`, `Subtree sizes`, `All-roots answers`
- Difficulty: `medium`
- Subtype: `Sum of distances from every node to all other nodes`
- Status: `solved`
- Solution file: [treedistances2.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/tree-dp/treedistances2.cpp)

## Why Practice This

This is the cleanest rerooting note in the repo.

The statement asks for one answer per possible root:

- for every node `u`
- compute the sum of distances from `u` to all other nodes

That is exactly the kind of “all roots” question where subtree DP alone is not enough, but rerooting turns one rooted answer into all of them.

## Recognition Cue

Reach for rerooting when:

- you can solve the problem for one fixed root
- the final answer is needed for every node
- moving the root across one edge changes the answer in a simple local way

The strongest smell is:

- "answer for every node as the root"

That usually means:

- first compute one rooted summary
- then push parent-side contribution across edges

## Problem-Specific Transformation

The raw task looks like `n` separate BFS/DFS computations, one from each node.

The reusable rewrite is:

- root the tree once
- compute subtree sizes and the total distance sum for one root
- derive a constant-time reroot formula for one edge `u -> v`

Then all `n` answers come from:

- one downward DP pass
- one reroot pass

instead of `n` separate traversals.

## Core Idea

Let node `1` be the initial root.

First pass:

- `sub_size[u]` = size of the subtree of `u`
- `sub_dist[u]` = sum of distances from `u` to nodes inside its subtree

This gives the first full answer:

```text
ans[1] = sub_dist[1]
```

Now suppose `v` is a child of `u`.

When the root moves from `u` to `v`:

- all nodes inside `v`'s subtree become `1` step closer
- all nodes outside `v`'s subtree become `1` step farther

So:

```text
ans[v] = ans[u] - sub_size[v] + (n - sub_size[v])
```

That is the whole reroot transition.

Once the first root answer is known, a second traversal pushes this formula through every edge.

## Complexity

- build parent / order: `O(n)`
- subtree DP: `O(n)`
- reroot pass: `O(n)`
- total: `O(n)`

## Pitfalls / Judge Notes

- Use `long long`; distance sums are much larger than a single edge count.
- `sub_size[v]` must mean the child subtree size in the initial rooted tree, not a recomputed dynamic size.
- The reroot formula is directional across a parent-child edge in the fixed DFS tree.
- You do not need a generic rerooting framework here; one concrete formula is enough.

## Reusable Pattern

- Topic page: [Tree DP](../../../../topics/dp/tree-dp/README.md)
- Practice ladder: [Tree DP ladder](README.md)
- Starter template: [tree-dp-rerooting.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/tree-dp-rerooting.cpp)
- Notebook refresher: [DP cheatsheet](../../../../notebook/dp-cheatsheet.md)
- Carry forward: once one-root DP is solved, ask whether one edge reroot step can transform the answer locally.
- This note adds: the exact `ans[v] = ans[u] - sub_size[v] + (n - sub_size[v])` transition and the two-pass implementation shape.

## Solutions

- Code: [treedistances2.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/tree-dp/treedistances2.cpp)
