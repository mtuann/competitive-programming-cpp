# 321C - Ciel the Commander

- Title: `Ciel the Commander`
- Judge / source: `Codeforces`
- Original URL: [https://codeforces.com/problemset/problem/321/C](https://codeforces.com/problemset/problem/321/C)
- Secondary topics: `Centroid decomposition`, `Centroid tree`, `Balanced recursive labeling`
- Difficulty: `hard`
- Subtype: `Build the centroid decomposition tree itself and label nodes by centroid depth`
- Status: `solved`
- Solution file: [cielthecommander.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/centroid-decomposition/cielthecommander.cpp)

## Why Practice This

This is the cleanest in-repo anchor for trusting the centroid decomposition structure itself.

The problem does **not** hide behind a second data structure or a later query trick.

It asks for a labeling whose proof is exactly the decomposition:

- choose one balanced centroid
- give it the highest available rank
- recurse on the remaining components

So the real lesson is:

- how to find a centroid repeatedly
- how the centroid tree is built
- why nodes with the same centroid depth automatically satisfy the path rule

## Recognition Cue

Reach for centroid decomposition when:

- the tree is static
- the statement wants a balanced recursive partition
- or every solution argument sounds like “pick one central node, solve paths through it, recurse on the rest”

The strong smell here is:

- if two nodes share the same rank, some higher-ranked node must lie on their path

That is exactly what centroid levels provide.

## Problem-Specific Transformation

Let the rank of a node be determined by its depth in the centroid tree:

- root centroid -> `A`
- its centroid-tree children -> `B`
- next level -> `C`
- and so on

Then if two nodes `x` and `y` receive the same rank, they lie in different child components of some higher centroid chosen earlier.

So the unique path between `x` and `y` passes through that earlier centroid, which has a strictly higher rank.

That matches the statement directly.

## Core Idea

Build the centroid decomposition tree of the original tree.

For each recursive component:

1. find its centroid `c`
2. label `c` with the current letter
3. remove `c`
4. recurse on every remaining component with the next letter

Why is the labeling valid?

Because equal letters correspond to equal centroid-tree depth.

Two nodes at the same centroid depth were separated earlier by some ancestor centroid with a smaller depth, hence a higher rank.

Therefore the path between them contains a higher-ranked node.

This is one of the rare problems where the centroid decomposition is not just a helper.

It is the whole proof.

## Complexity

- each decomposition level touches every live node once
- centroid-tree depth is `O(log n)`
- total time: `O(n log n)`
- memory: `O(n)`

This is easily fast enough for `n <= 10^5`.

## Pitfalls / Judge Notes

- The rank depends on **centroid depth**, not ordinary tree depth.
- Do not confuse the centroid tree with the original tree.
- Using a `removed[]` array is safer than erasing edges from adjacency lists.
- In this constraint range, centroid depth stays well below `26`, so a valid labeling exists.

## Reusable Pattern

- Topic page: [Centroid Decomposition](../../../../topics/graphs/centroid-decomposition/README.md)
- Practice ladder: [Centroid Decomposition ladder](README.md)
- Starter template: [centroid-decomposition.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/centroid-decomposition.cpp)
- Notebook refresher: [Centroid hot sheet](../../../../notebook/centroid-hot-sheet.md)
- Compare points: [Trees](../../../../topics/graphs/trees/README.md), [Euler Tour / Subtree Queries](../../../../topics/graphs/euler-tour-subtree/README.md), [Heavy-Light Decomposition](../../../../topics/graphs/hld/README.md)
- This note adds: the direct “build the centroid tree and use its depth as the answer” pattern.

## Solutions

- Code: [cielthecommander.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/centroid-decomposition/cielthecommander.cpp)
