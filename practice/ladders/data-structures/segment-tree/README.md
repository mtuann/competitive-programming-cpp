# Segment Tree Ladder

Segment-tree practice should teach you to define node meaning and merge logic before code, because most segment-tree bugs come from poor state design, not from the tree skeleton itself.

## Who This Is For

Use this ladder if:

- Fenwick feels too limited for your query type
- you need dynamic range queries with richer node data
- lazy propagation still feels intimidating

## Warm-Up

- range sum with point updates
- range minimum with point updates

Target skill:

- define node value, merge, and identity cleanly

## Core

- custom merge states
- descent queries
- compare iterative and recursive implementations

Target skill:

- use segment tree for more than plain sums

## Stretch

- compare segment tree against Fenwick on the same problem
- lazy propagation later
- persistent or dynamic variants later

Target skill:

- understand why the structure is more general, and what extra complexity that buys

## Retrieval Layer

- exact quick sheet -> [Segment Tree hot sheet](../../../../notebook/segment-tree-hot-sheet.md)
- array sum starter -> [segment-tree-iterative.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/segment-tree-iterative.cpp)
- compare against tree-path usage -> [hld-path-max.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hld-path-max.cpp)

## Exit Criteria

You are ready to move on when:

- you can state the node invariant before coding
- you can choose the correct identity element
- you can tell whether a problem needs lazy propagation or not

## External Practice

- [CP-Algorithms - Segment Tree](https://cp-algorithms.com/data_structures/segment_tree.html)
- [CSES Range Queries](https://cses.fi/problemset/)
- [USACO Guide - Segment Tree](https://usaco.guide/plat/segtree-ext/)

## Tutorial Link

- [Segment Tree](../../../../topics/data-structures/segment-tree/README.md)
