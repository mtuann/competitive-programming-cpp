# Tree Isomorphism Ladder

This lane is for the first time a tree problem stops being about values on the tree and becomes purely about **whether two trees have the same shape**.

## Who This Is For

Use this lane if:

- [Trees](../../../../topics/graphs/trees/README.md) already feels comfortable
- you can root a tree and think parent/child without trouble
- child order is irrelevant and that is now the whole point

This lane is intentionally narrow:

- one exact starter
- one flagship rooted benchmark
- one clear unrooted stretch by trying centers

## Warm-Up

- explain the difference between rooted and unrooted tree isomorphism
- explain why child order must be forgotten
- explain why sorted child signatures beat brute-force child permutation

Target skill:

- recognize when a tree statement is about canonical structure, not path/query data

## Core

- rooted unordered trees
- postorder canonical encoding
- one shared interner across both trees
- exact flagship rep: [Tree Isomorphism I](treeisomorphism1.md)

Target skill:

- trust the bottom-up canonical-type route and compare root types directly

## Stretch

- unrooted route -> try one or two centers first
- compare rooted-first [Tree Isomorphism I](treeisomorphism1.md) against the unrooted sibling `Tree Isomorphism II`
- compare this lane against [Virtual Tree](../virtual-tree/README.md) when the problem is still structural but query-local

Target skill:

- see unrooted tree isomorphism as one center-normalization step, not as a different family

## Retrieval Layer

- exact quick sheet -> [Tree Isomorphism hot sheet](../../../../notebook/tree-isomorphism-hot-sheet.md)
- exact starter -> [tree-isomorphism-rooted.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/tree-isomorphism-rooted.cpp)
- broader tree context -> [Trees](../../../../topics/graphs/trees/README.md)
- broader chooser -> [Graph cheatsheet](../../../../notebook/graph-cheatsheet.md)

## Repo Anchors And Compare Points

- topic page -> [Tree Isomorphism](../../../../topics/graphs/tree-isomorphism/README.md)
- flagship note -> [Tree Isomorphism I](treeisomorphism1.md)
- rooted-tree context -> [Trees](../../../../topics/graphs/trees/README.md)
- query-local structural compare point -> [Virtual Tree / Auxiliary Tree](../../../../topics/graphs/virtual-tree/README.md)
- broader routing -> [Graphs ladder](../README.md)

The cleanest in-repo loop here is:

1. reopen [Trees](../../../../topics/graphs/trees/README.md) just enough to stabilize rooted-tree language
2. learn the rooted canonical route in [Tree Isomorphism](../../../../topics/graphs/tree-isomorphism/README.md)
3. solve [Tree Isomorphism I](treeisomorphism1.md)
4. only then stretch to the unrooted center-rooting sibling

## Exit Criteria

You are ready to move on when:

- you stop thinking in terms of child permutations directly
- you know rooted tree isomorphism is one bottom-up canonicalization problem
- you know unrooted tree isomorphism means one or two center roots, not arbitrary rooting

## External Practice

- [CSES - Tree Isomorphism I](https://cses.fi/problemset/task/1700)
- [CSES - Tree Isomorphism II](https://cses.fi/problemset/task/1701)

## Tutorial Link

- [Tree Isomorphism](../../../../topics/graphs/tree-isomorphism/README.md)
