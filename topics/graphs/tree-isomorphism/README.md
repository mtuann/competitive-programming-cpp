# Tree Isomorphism

This lane is for the moment the tree task is not about:

- distances
- subtree aggregates
- path queries

but about one structural question:

- are these two trees the same shape if child order does not matter?

The repo's exact first route for this family is:

- starter -> [tree-isomorphism-rooted.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/tree-isomorphism-rooted.cpp)
- flagship note -> [Tree Isomorphism I](../../../practice/ladders/graphs/tree-isomorphism/treeisomorphism1.md)
- compare point -> [Trees](../trees/README.md)
- stretch compare point -> `unrooted tree isomorphism by trying one or two centers`

This lane intentionally teaches the **rooted unordered route first**:

- fixed root
- child order irrelevant
- canonical bottom-up subtree encoding

It does not start from full graph isomorphism, labeled trees, or randomized hashing.

## At A Glance

- **Use when:** two rooted trees must be compared up to child permutation, or one unrooted tree question clearly reduces to "try the center roots"
- **Core worldview:** every rooted subtree can be assigned a canonical type from the multiset of its child types, so two rooted trees are isomorphic exactly when their root types match
- **Main tools:** postorder traversal, sorted child-type vectors, one shared interner/map for subtree signatures, and tree centers for the unrooted follow-up
- **Typical complexity:** `O(n log n)` with sorted child signatures
- **Main trap:** forgetting that IDs must be assigned in one shared canonical universe when comparing two trees

Strong contest signals:

- "given two rooted trees, are they isomorphic?"
- "children may be reordered"
- "tree shape only"
- "compare two trees, not values on paths"
- "for unrooted trees, root them at a center or one of two centers"

Strong anti-cues:

- the statement is really about path sums, ancestors, or subtree updates -> [Trees](../trees/README.md), [LCA](../lca/README.md), [Euler Tour / Subtree Queries](../euler-tour-subtree/README.md)
- labels or values on vertices dominate the comparison
- the object is not a tree anymore -> this lane is too narrow
- the intended route is random hashing with collision risk instead of canonical structure

## Prerequisites

- [Trees](../trees/README.md)
- [BFS And DFS](../bfs-dfs/README.md)

Helpful compare points:

- [Trees](../trees/README.md): use this first when the task is still about distance, center, diameter, or rooted reasoning
- [Virtual Tree / Auxiliary Tree](../virtual-tree/README.md): use that when the query only marks a small subset and you still need one compressed structural tree

## Problem Model And Notation

For rooted tree isomorphism, we compare two rooted trees:

$$
T_1, T_2
$$

with designated roots:

$$
r_1, r_2.
$$

The children of a node are considered an **unordered family**.

So two rooted trees are isomorphic if there exists a bijection between vertices that:

- maps root to root
- preserves adjacency
- ignores the order in which children are written

For the unrooted follow-up:

- first find the center set of each tree
- each tree has either one center or two adjacent centers
- try all valid center-rooted combinations

That reduces the unrooted task back to the rooted one.

## From Brute Force To Canonical Encoding

### What The Brute Force Tries

At a node `u`, you could try to match:

- each child subtree of `u`
- against child subtrees of another node `v`
- under every permutation

That explodes immediately.

### The Real Shift

Do not match child subtrees by search.

Instead:

1. assign every leaf the same canonical type
2. process nodes bottom-up
3. collect the canonical types of all children
4. sort that list
5. use the sorted list itself as the signature of the subtree

Then two rooted subtrees are isomorphic if and only if their signatures match.

### Why One Shared Interner Matters

The implementation usually compresses each child-signature vector into one integer ID.

That is fine, but only if equal signatures in both compared trees receive the same ID.

So the clean contest route is:

- use one shared map/interner while encoding both trees

and not two completely separate local ID systems.

## Core Invariants And Why They Matter

The repo starter keeps four contest-facing invariants.

### 1. Parent Order Makes The Tree Rooted

For one chosen root:

- every node except the root has one parent
- every non-parent neighbor is a child

This makes each undirected input tree behave like a rooted tree.

### 2. Leaves Share One Base Signature

Every leaf has:

- an empty child-signature vector

so all leaves must map to the same canonical type.

This is the base layer of the whole encoding.

### 3. A Node Type Depends Only On The Multiset Of Child Types

For a node `u`, its signature is:

- the sorted list of child types

not the DFS visitation order.

That is exactly what removes child-order dependence.

### 4. Root Equality Is The Whole Answer

Once every subtree has a canonical type:

- rooted trees are isomorphic iff `type[root1] == type[root2]`

All local structure has already been folded into that root type.

## Complexity And Tradeoffs

The rooted route here is usually:

$$
O(n \log n)
$$

because each node sorts its child-type list.

Rule of thumb:

- rooted unordered comparison -> this lane
- unrooted unordered comparison -> same lane, but try one or two centers first
- tree queries over values -> [Trees](../trees/README.md), [LCA](../lca/README.md), [Euler Tour / Subtree Queries](../euler-tour-subtree/README.md)

## Worked Examples

### Example 1: CSES Tree Isomorphism I

The repo's flagship note:

- [Tree Isomorphism I](../../../practice/ladders/graphs/tree-isomorphism/treeisomorphism1.md)

The statement already gives:

- two rooted trees
- root fixed at node `1`
- no labels beyond structure

So this is the cleanest first benchmark:

- bottom-up canonical encoding
- compare root signatures

### Example 2: CSES Tree Isomorphism II

This is the natural stretch sibling:

- trees are not rooted

The route becomes:

1. find the center set of each tree
2. root each tree at its one center, or try both centers if there are two
3. compare rooted canonical types

So the unrooted version is not a different family.

It is one extra center-normalization step before the same rooted primitive.

## Repo Starter Contract

The starter:

- expects two trees as adjacency lists
- exposes `rooted_isomorphic(g1, root1, g2, root2)`
- assumes both inputs are trees and child order is irrelevant

The exact engine is:

- one shared canonical-signature interner
- postorder processing inside each rooted tree

This starter intentionally does **not** promise:

- labeled-tree matching
- general graph isomorphism
- collision-prone hash equality as the proof object

## Main Traps

- assigning subtree IDs separately in the two trees
- forgetting to sort child types before interning the signature
- confusing rooted and unrooted versions
- using recursive string concatenation so aggressively that performance becomes the real problem

## Reopen Paths

- exact starter -> [tree-isomorphism-rooted.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/tree-isomorphism-rooted.cpp)
- hot sheet -> [Tree Isomorphism hot sheet](../../../notebook/tree-isomorphism-hot-sheet.md)
- flagship note -> [Tree Isomorphism I](../../../practice/ladders/graphs/tree-isomorphism/treeisomorphism1.md)
- broader tree context -> [Trees](../trees/README.md)
- broader chooser -> [Graph cheatsheet](../../../notebook/graph-cheatsheet.md)
