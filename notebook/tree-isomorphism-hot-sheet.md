# Tree Isomorphism Hot Sheet

Use this sheet when the statement is really about **tree shape equality** and child order does not matter.

## Do Not Use When

- the task is about distances, ancestors, subtree sums, or path aggregates -> [Graph cheatsheet](graph-cheatsheet.md)
- labels or weights dominate the comparison
- the object is not a tree
- you actually need full graph isomorphism

## Choose By Signal

- two rooted trees, root fixed, child order irrelevant -> `Tree Isomorphism`
- two unrooted trees, still only shape matters -> same lane, but root at one or two centers first
- one query only marks a small subset and wants one compressed structural tree -> [Virtual Tree hot sheet](virtual-tree-hot-sheet.md)

## Core Invariants

- all leaves share one empty-child signature
- a node type depends only on the sorted multiset of child types
- both trees must use one shared signature interner
- rooted trees are isomorphic exactly when their root types match
- unrooted trees reduce to rooted ones by trying valid centers

## Main Traps

- assigning subtree IDs independently in the two trees
- forgetting to sort child labels before interning
- mixing rooted and unrooted cases
- using string canonicalization so naively that performance becomes the bottleneck

## Exact Starter Route

- exact starter -> [tree-isomorphism-rooted.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/tree-isomorphism-rooted.cpp)
- flagship in-lane rep -> [Tree Isomorphism I](../practice/ladders/graphs/tree-isomorphism/treeisomorphism1.md)
- stretch sibling -> `Tree Isomorphism II` by center rooting
- broader tree context -> [Trees](../topics/graphs/trees/README.md)

## Reopen Paths

- full topic page -> [Tree Isomorphism](../topics/graphs/tree-isomorphism/README.md)
- broader chooser -> [Graph cheatsheet](graph-cheatsheet.md)
- static-tree modeling context -> [Trees](../topics/graphs/trees/README.md)
- marked-subset compression compare route -> [Virtual Tree / Auxiliary Tree](../topics/graphs/virtual-tree/README.md)
