# Euler Tour / Subtree Queries Ladder

This ladder is for the first tree-query lane where a subtree becomes one array interval and no heavy path machinery is needed.

## Who This Is For

Use this lane if:

- rooted-tree ideas already make sense
- subtree language feels stable
- path-query machinery like HLD still feels too heavy for the statement in front of you

## Warm-Up

- subtree sizes
- entry times `tin / tout`
- one DFS order that writes each node once

Good compare points:

- [Trees](../trees/README.md)
- [Subordinates](https://cses.fi/problemset/task/1674)

Target skill:

- say why a subtree becomes one contiguous interval in single-entry DFS order

## Core

- flatten the rooted tree into one entry-order array
- map node `u` to one position `tin[u]`
- answer subtree sum/count on `[tin[u], tout[u])`
- exact flagship rep: [Subtree Queries](subtreequeries.md)

Target skill:

- know when one subtree query is already just one range query

## Stretch

- compare [Subtree Queries](subtreequeries.md) against [Path Queries](https://cses.fi/problemset/task/1138)
- use [Distinct Colors](https://cses.fi/problemset/task/1139) as the first "same flattening, different engine" compare point
- move to [Heavy-Light Decomposition](../hld/README.md) only when the query leaves the subtree-only world

Target skill:

- distinguish subtree-only flattening from path-query decompositions

## Retrieval Layer

- exact quick sheet -> [Subtree Queries hot sheet](../../../../notebook/subtree-queries-hot-sheet.md)
- exact starter -> [euler-tour-subtree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/euler-tour-subtree.cpp)
- tree worldview refresher -> [Trees](../../../../topics/graphs/trees/README.md)
- lighter range engine compare point -> [Fenwick hot sheet](../../../../notebook/fenwick-hot-sheet.md)

## Exit Criteria

You are ready to move on when:

- you can explain why `[tin[u], tout[u])` is exactly the subtree of `u`
- you know when Fenwick is enough after flattening and when you need a segment tree instead
- you can say clearly why HLD is unnecessary for subtree-only queries

## External Practice

- [CSES - Subtree Queries](https://cses.fi/problemset/task/1137)
- [CSES - Path Queries](https://cses.fi/problemset/task/1138)
- [CSES - Distinct Colors](https://cses.fi/problemset/task/1139)
- [USACO Guide - Euler Tour Technique](https://usaco.guide/gold/tree-euler)

## Tutorial Link

- [Euler Tour / Subtree Queries](../../../../topics/graphs/euler-tour-subtree/README.md)
