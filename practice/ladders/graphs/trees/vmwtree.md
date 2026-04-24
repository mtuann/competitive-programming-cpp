# VMWTREE

- Title: `VMWTREE - Lại là cây khung`
- Judge / source: `VN SPOJ / VNOI`
- Original URL: [https://vn.spoj.com/problems/VMWTREE/](https://vn.spoj.com/problems/VMWTREE/)
- Mirror URL: [https://oj.vnoi.info/problem/vmwtree](https://oj.vnoi.info/problem/vmwtree)
- Secondary topics: `Heavy-light decomposition`, `Implicit treap`, `Path sequence updates`
- Difficulty: `hard`
- Subtype: `Query min/max on a path and reverse the whole path-value sequence`
- Status: `solved`
- Solution file: [vmwtree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/trees/vmwtree.cpp)

## Why Practice This

This is a good reminder that not every tree-path update is a normal segment-tree lazy tag.

The query types look close to standard HLD:

- path minimum
- path maximum
- path reverse

But the reverse operation does **not** just flip a direction flag on an Euler interval. It changes which value belongs to which vertex along the path.

## Core Idea

Decompose the tree path into heavy-chain intervals.

Store each chain as a mutable sequence in `top -> bottom` order. Then:

1. break a path into `O(log N)` chain pieces
2. extract those pieces in true `u -> v` path order
3. concatenate them into one temporary sequence
4. reverse that temporary sequence once
5. split it back by original piece lengths
6. reinsert each piece into its original chain position

That is why the repo solution uses:

- `HLD` for path decomposition
- `implicit treap` for sequence split / merge / reverse

## Complexity

- preprocessing: `O(N)`
- each query: `O(log^2 N)`
- memory: `O(N)`

This is safe for `N, Q <= 10^5`.

## Pitfalls / Judge Notes

- A plain segment tree over HLD order is **not** enough if you only store aggregates. Reversing the path sequence moves actual values between vertices.
- The common-path piece on the LCA chain must be handled with the correct orientation:
  - deeper to ancestor means reverse relative to chain order
  - ancestor to deeper means keep chain order
- Query order does not matter for min/max, but update order does matter for path reversal.

## Reusable Pattern

- Topic page: [Trees](../../../../topics/graphs/trees/README.md)
- Practice ladder: [Trees ladder](README.md)
- Starter template: [segment-tree-iterative.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/segment-tree-iterative.cpp)
- Notebook refresher: [Graph cheatsheet](../../../../notebook/graph-cheatsheet.md)
- Carry forward: flatten the path logic until the segment-tree operations become obvious.
- This note adds: the tree-specific path representation layered on top of the range structure.

## Solutions

- Code: [vmwtree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/trees/vmwtree.cpp)
