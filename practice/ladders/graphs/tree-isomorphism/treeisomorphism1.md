# Tree Isomorphism I

- Title: `Tree Isomorphism I`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1700](https://cses.fi/problemset/task/1700)
- Secondary topics: `Rooted trees`, `Canonical encoding`, `AHU-style subtree types`
- Difficulty: `hard`
- Subtype: `Rooted unordered tree isomorphism`
- Status: `solved`
- Solution file: [treeisomorphism1.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/tree-isomorphism/treeisomorphism1.cpp)

## Why Practice This

This is the cleanest first in-repo flagship for `Tree Isomorphism`.

The statement already gives:

- two rooted trees
- root fixed at node `1`
- no labels beyond structure

So the hard part is exactly the algorithmic one:

- forget child order
- canonicalize subtrees bottom-up
- compare the two root types

## Recognition Cue

Reach for this route when:

- both objects are trees
- the root is fixed
- children may be reordered
- the question is only whether the shapes match

The strongest smell here is:

- "given two rooted trees, are they isomorphic?"

That is exactly this lane.

## Problem-Specific Route

This task does **not** want:

- LCA, because there are no ancestor/path queries
- subtree sums or rerooting, because there are no numeric aggregates
- random graph hashing as the proof object

The clean route is:

1. root both trees at node `1`
2. process both trees in postorder
3. for each node, sort the list of child subtree types
4. map that sorted list to one canonical ID in a shared interner
5. compare the root IDs

## Core Idea

Every leaf has the same type because it has no children.

For an internal node:

- collect the canonical types of all children
- sort them
- use the sorted list itself as the subtree signature

If two nodes in the two trees produce the same signature, their rooted subtrees are isomorphic.

So once all nodes are processed bottom-up, the entire answer is:

- `YES` if the root signatures match
- `NO` otherwise

## Complexity

- per test case: `O(n log n)` from sorting child-type lists
- memory: `O(n)`

That is fully comfortable for the CSES limits.

## Pitfalls / Judge Notes

- The trees are rooted at node `1`.
- Child order does not matter.
- Use one shared signature map for both trees in the same test case.
- Separate local ID systems can silently make equal structures look different.

## Reusable Pattern

- Topic page: [Tree Isomorphism](../../../../topics/graphs/tree-isomorphism/README.md)
- Practice ladder: [Tree Isomorphism ladder](README.md)
- Starter template: [tree-isomorphism-rooted.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/tree-isomorphism-rooted.cpp)
- Notebook refresher: [Tree Isomorphism hot sheet](../../../../notebook/tree-isomorphism-hot-sheet.md)
- Compare points:
  - [Trees](../../../../topics/graphs/trees/README.md)
  - [Virtual Tree / Auxiliary Tree](../../../../topics/graphs/virtual-tree/README.md)
- This note adds: the clean rooted-template route before the unrooted center-rooting sibling enters

## Solutions

- Code: [treeisomorphism1.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/tree-isomorphism/treeisomorphism1.cpp)
