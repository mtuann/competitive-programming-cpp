# Centroid Decomposition

Centroid decomposition is the first tree technique that says:

```text
stop treating the whole tree as one object;
split it around one balanced pivot,
solve the contribution that passes through that pivot,
then recurse on the remaining components.
```

It also sits naturally next to [Trees](../trees/README.md), [Euler Tour / Subtree Queries](../euler-tour-subtree/README.md), and [Heavy-Light Decomposition](../hld/README.md):

- subtree flattening handles one rooted subtree
- HLD handles online path aggregates
- centroid decomposition handles many tree-path problems whose clean split is “through one pivot or not”

It is also the standard route for many “nearest marked node”, “count paths with property `P`”, and “label nodes by balanced recursive layers” problems on a **static** tree.

## At A Glance

- **Use when:** the tree is static and the clean divide-and-conquer split is “paths through one balanced center” versus “paths entirely inside one child component”
- **Core worldview:** repeatedly remove one centroid so every remaining component has size at most half
- **Main tools:** subtree sizes, centroid finding, centroid tree, per-node centroid ancestors, per-centroid aggregates
- **Typical complexity:** build `O(n log n)`; many standard updates/queries become `O(log n)` or `O(log^2 n)`
- **Main trap:** reaching for centroid decomposition when the real problem is only subtree flattening, path range queries, or ordinary tree DP

Strong contest signals:

- “find the nearest special/painted node on a static tree under many updates”
- “count or optimize paths with a condition on length / xor / weight”
- “recursively label or partition the tree by balanced centers”
- “each node only needs to interact with `O(log n)` structural ancestors after preprocessing”

Strong anti-cues:

- subtree-only query -> [Euler Tour / Subtree Queries](../euler-tour-subtree/README.md)
- online path max/sum/min with segment-tree-style aggregation -> [Heavy-Light Decomposition](../hld/README.md)
- one fixed rooted DP where child states merge once -> [Tree DP](../../dp/tree-dp/README.md)
- the tree changes online by link/cut -> this page is too static
- you only need one centroid, not the whole decomposition -> stay in [Trees](../trees/README.md)

## Prerequisites

- [Trees](../trees/README.md)

Helpful neighboring topics:

- [Euler Tour / Subtree Queries](../euler-tour-subtree/README.md) for one lighter tree-reduction neighbor
- [Heavy-Light Decomposition](../hld/README.md) for the main “path queries, but different family” compare point
- [Tree DP](../../dp/tree-dp/README.md)
- [Offline Tricks](../../data-structures/offline-tricks/README.md)
- [Algorithm Engineering](../../advanced/algorithm-engineering/README.md) once constants and memory layout start to matter

## Problem Model And Notation

Let `T` be a tree with `n` nodes.

A **centroid** of a component `C` is a node `c` such that, after removing `c`, every remaining component has size at most:

$$
\left\lfloor \frac{|C|}{2} \right\rfloor.
$$

Centroid decomposition recursively does:

1. find a centroid `c` of the current component
2. make `c` one node in the **centroid tree**
3. remove `c`
4. recurse on every remaining component

We will use:

- `sub[u]`: subtree size inside the current rooted component walk
- `cd_parent[u]`: parent of `u` in the centroid tree
- `cd_depth[u]`: depth of `u` in the centroid tree
- `anc[u]`: centroid ancestors of original node `u`
- `dist[u][k]`: distance from `u` to its `k`-th centroid ancestor

The decomposition is over a **static** tree. The centroid tree is an auxiliary structure, not the original tree.

## From Brute Force To The Right Idea

### Brute Force

Many centroid problems sound like this:

- update one marked node, then query the closest marked node to `u`
- count all paths whose length equals `k`
- assign balanced recursive labels to the whole tree

The naive instinct is often:

- rerun BFS / DFS from each query node
- enumerate too many path pairs
- or root the tree in one way and hope ordinary subtree logic is enough

That usually fails because the hard object is not one subtree.

It is the set of **all simple paths** in the current component.

### The First Right Question

For a component `C`, ask:

```text
can I solve the contribution of all paths that pass through one chosen node,
then recurse on paths that do not?
```

If yes, we want that chosen node to keep the recursion balanced.

That is exactly what the centroid gives.

### Why Balance Matters

If every recursive split could leave a component of size `n - 1`, the decomposition would be useless.

But with a centroid, every child component has size at most half.

So one node belongs to only:

$$
O(\log n)
$$

recursive components.

That is the structural reason centroid decomposition works.

## Core Invariants And Why They Work

## 1. Every Tree Component Has A Centroid

This is the same fact behind [Finding a Centroid](https://cses.fi/problemset/task/2079).

One practical proof idea is the “walk into the too-large side” rule:

- root the component anywhere
- if some adjacent side has size `> total / 2`, move there
- this walk cannot continue forever
- when it stops, the current node is a centroid

So the decomposition always has a valid next pivot.

## 2. Every Recursive Piece Shrinks By At Least Half

If `c` is a centroid of a component of size `m`, then after removing `c`, each remaining piece has size at most `m / 2`.

That implies:

- centroid-tree depth is `O(log n)`
- each original node has `O(log n)` centroid ancestors

This is the main complexity invariant.

## 3. The Centroid Tree Is A Structural Index, Not The Original Tree

Each original node appears exactly once as a centroid node in the decomposition tree.

But the parent-child relation in that centroid tree means:

```text
which component was recursively split from which larger component
```

It does **not** mean:

- original-tree parent
- subtree relation in one rooted tree
- shortest-path parent

Confusing these two trees is one of the biggest beginner bugs.

## 4. Every Node Has Only O(log n) Relevant Centroid Ancestors

If we store, for each original node `u`, all centroid ancestors on the path:

```text
u -> cd_parent[u] -> cd_parent[cd_parent[u]] -> ...
```

then any update or query that only needs one contribution per centroid ancestor becomes logarithmic.

This is the standard pattern in problems like `Xenia and Tree`:

- update one node -> walk up its centroid ancestors
- query one node -> walk up its centroid ancestors

## 5. Every Simple Path Is Captured At One Decomposition Level

Consider two nodes `a` and `b`.

During decomposition, there is a first centroid `c` whose recursive component still contains both `a` and `b`, but after removing `c`, they fall into different child components or one endpoint is exactly `c`.

Then the path `a -> b` passes through `c`.

So path problems can often be organized as:

- count / optimize all paths through current centroid `c`
- recurse on each child component for paths that avoid `c`

This is the real divide-and-conquer invariant.

## Variant Chooser

### Use “Find One Centroid” When

- the statement only asks for one centroid node
- no recursive centroid tree is needed

Warm-up anchor:

- [Finding a Centroid](https://cses.fi/problemset/task/2079)

### Use Full Centroid Decomposition When

- the tree is static
- each node/query can be answered by combining `O(log n)` centroid-ancestor contributions
- or the global path family can be split into “through this centroid” versus “fully inside one child component”

### Use HLD Instead When

- queries are path aggregates with online updates
- the real primitive is segment-tree-on-paths, not balanced recursive splitting

### Use Euler Flattening Instead When

- every query is one whole rooted subtree
- no arbitrary-path reasoning is needed

### Use Tree DP / Rerooting Instead When

- every answer is built from child states once
- the problem is not naturally “through a pivot or not”

### Use Small-To-Large / DSU-On-Tree Instead When

- the key object is one multiset of colors/frequencies in subtrees
- not a path family over the whole component

## Worked Examples

### Example 1: Finding One Centroid By Walking

Suppose the current component has `9` nodes.

Start at any node `u`.

If one adjacent side has more than `4` nodes, move into that side.

Why is this safe?

Because the side you leave behind is now strictly smaller than half, so no centroid can be there anymore.

When no adjacent side is larger than half, you are at a centroid.

This turns centroid finding into a reusable structural primitive instead of magic.

### Example 2: Ciel The Commander

In [Ciel the Commander](https://codeforces.com/problemset/problem/321/C), assign ranks so that any two equal-rank nodes have a higher-rank node on their path.

Centroid decomposition solves it directly:

- current centroid gets rank `A`
- recurse on child components and give them rank `B`
- recurse again and give those `C`, and so on

Why is this valid?

Because if two nodes get the same rank, they were separated earlier by a higher-rank centroid on the recursion path.

This is the cleanest “build the centroid tree itself” anchor problem.

### Example 3: Nearest Red Node

Suppose each node can become red, and we need:

```text
query(u) = distance from u to the nearest red node
```

For each centroid `c`, keep:

$$
best[c] = \min \text{ distance}(c, red)
$$

over all red nodes seen so far.

Then:

$$
query(u) = \min_{c \in anc[u]} \left(best[c] + dist(u, c)\right)
$$

and an update of node `u` only touches its centroid ancestors.

That is the standard `O(log n)` ancestor-walk pattern.

### Example 4: Counting Paths Through One Centroid

Suppose we want to count paths with exact length `k`.

At centroid `c`:

1. collect depths of nodes in one child component
2. count matches against depths already collected from earlier child components
3. then merge this child’s depths into the global counter

This counts exactly the paths that pass through `c` without double-counting paths fully inside one child component.

Then recurse on those child components.

That is the standard “process-through-centroid, recurse-away-from-centroid” skeleton.

## Pseudocode Skeleton

```text
decompose(entry, cd_parent):
    c = centroid_of_component(entry)
    record c in the centroid tree
    optionally attach per-node info against c
    mark c as removed

    for each neighbor-side component T after removing c:
        decompose(any node in T, c)
```

For nearest-marked-node style problems, the “attach per-node info” step often means:

- add `c` to every node’s centroid-ancestor list
- store distance from that node to `c`

For path-counting problems, it often means:

- process all paths through `c`
- then recurse

## Implementation Notes

- Prefer a `removed[]` array. Do **not** erase edges from adjacency lists mid-iteration.
- An iterative DFS for subtree sizes is a good default on `n = 2e5`.
- Distances to centroid ancestors can be precomputed during decomposition, so later updates/queries avoid extra LCA work.
- Decide one ancestor order and document it. The starter in this repo exposes centroid ancestors **nearest first**.
- The centroid tree recursion depth is only `O(log n)`, but ordinary tree DFS depth is not. That is why the helper DFSes matter more than the decomposition recursion itself.

## Practice Archetypes

- build the centroid tree directly -> [Ciel the Commander](../../../practice/ladders/graphs/centroid-decomposition/cielthecommander.md)
- find one centroid only -> [Finding a Centroid](https://cses.fi/problemset/task/2079)
- nearest active / colored node -> [Xenia and Tree](https://codeforces.com/problemset/problem/342/E)
- count paths by exact length -> [Fixed-Length Paths I](https://cses.fi/problemset/task/2080)
- count paths by length range -> [Fixed-Length Paths II](https://cses.fi/problemset/task/2081)

## References

- [USACO Guide: Centroid Decomposition](https://usaco.guide/plat/centroid?lang=java)
- [OI Wiki: Tree Centroid](https://en.oi-wiki.org/graph/tree-centroid/)
- [OI Wiki: Tree Divide](https://en.oi-wiki.org/graph/tree-divide/)
- [CSES: Finding a Centroid](https://cses.fi/problemset/task/2079)

## Repo Anchors

- [Centroid Decomposition ladder](../../../practice/ladders/graphs/centroid-decomposition/README.md)
- [Exact starter template](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/centroid-decomposition.cpp)
- [Centroid hot sheet](../../../notebook/centroid-hot-sheet.md)
- [Ciel the Commander note](../../../practice/ladders/graphs/centroid-decomposition/cielthecommander.md)
- [Trees](../trees/README.md)
- [Euler Tour / Subtree Queries](../euler-tour-subtree/README.md)
- [Heavy-Light Decomposition](../hld/README.md)
