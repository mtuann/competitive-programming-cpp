# DSU Ladder

DSU practice should build fast instinct for “merge-only connectivity” problems and teach when component metadata still fits the DSU model.

## Who This Is For

Use this ladder if:

- you know the structure, but not yet the modeling cues
- you still hesitate between DFS/BFS and DSU on connectivity tasks
- Kruskal feels like a memorized recipe instead of a natural reduction

## Warm-Up

- static connectivity
- count connected components
- cycle detection in an undirected graph

Target skill:

- see connected components as mergeable sets

## Core

- Kruskal
- component sizes and metadata
- offline connectivity with only additions

Target skill:

- attach useful component data safely to roots only

## Stretch

- parity constraints
- rollback DSU
- dynamic connectivity in offline form

Target skill:

- understand the limits of plain DSU and when variants appear

## Exit Criteria

You are ready to move on when:

- you can implement `find` and `unite` from memory
- you know why path compression and union by size help
- you can tell when deletions make plain DSU the wrong tool

## External Practice

- [USACO Guide - DSU](https://usaco.guide/gold/dsu)
- [CSES Graph Algorithms](https://cses.fi/problemset/)
- [CP-Algorithms - DSU](https://cp-algorithms.com/data_structures/disjoint_set_union.html)

## Tutorial Link

- [DSU](../../../../topics/data-structures/dsu/README.md)
