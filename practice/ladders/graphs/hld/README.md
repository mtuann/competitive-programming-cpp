# Heavy-Light Decomposition Ladder

HLD practice should make path decomposition feel systematic instead of magical. The main goal is to understand why one tree path becomes only a few segment intervals.

## Who This Is For

Use this ladder if:

- tree path queries still tempt you into walking the path directly
- LCA is comfortable, but path aggregates still feel missing
- segment trees are fine alone, but combining them with trees is still shaky

## Warm-Up

- heavy child selection
- chain-head reasoning
- flattening a tree into one base array

Target skill:

- explain the decomposition before writing the code

## Core

- point update plus path maximum
- point update plus path sum
- same-chain versus cross-chain handling

Target skill:

- decompose any path into `O(log n)` contiguous segments without getting lost

## Stretch

- edge-valued variants
- path updates with lazy propagation
- compare HLD against Euler-tour flattening for subtree-only tasks

Target skill:

- know when HLD is the right hammer and when it is overkill

## Retrieval Layer

- exact quick sheet -> [HLD hot sheet](../../../../notebook/hld-hot-sheet.md)
- static node-update path-max starter -> [hld-path-max.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hld-path-max.cpp)
- compare against lighter tree tooling -> [Graph cheatsheet](../../../../notebook/graph-cheatsheet.md)

## Exit Criteria

You are ready to move on when:

- you can compute `heavy`, `head`, and `pos` confidently
- you know why the chain count is only `O(log n)`
- you can debug same-chain and cross-chain logic separately

## External Practice

- [CP-Algorithms - Heavy-Light Decomposition](https://cp-algorithms.com/graph/hld.html)
- [USACO Guide - HLD](https://usaco.guide/plat/hld?lang=cpp)
- [CSES Tree Algorithms](https://cses.fi/problemset/)
- [Library Checker - Vertex Add Path Sum](https://judge.yosupo.jp/problem/vertex_add_path_sum)

## Tutorial Link

- [Heavy-Light Decomposition](../../../../topics/graphs/hld/README.md)
