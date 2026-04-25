# Fenwick Tree Ladder

Fenwick-tree practice should build the instinct for dynamic prefix structure: when one-based indexing, additive queries, and coordinate compression come together naturally.

## Who This Is For

Use this ladder if:

- prefix sums are comfortable, but online updates are not
- `lowbit` still feels magical
- you want a lighter alternative to segment tree

## Warm-Up

- dynamic prefix sums
- range sums via two prefix sums
- frequency counting

Target skill:

- understand what each Fenwick index stores

## Core

- inversion counting
- coordinate-compressed BIT
- order statistics on prefix counts

Target skill:

- use Fenwick as a dynamic frequency table, not just a sum structure

## Stretch

- range-update variants
- offline query patterns with BIT
- [CVP00001 - Ô ăn quan](cvp00001.md)

Target skill:

- recognize the BIT variants that still stay natural

## Retrieval Layer

- exact quick sheet -> [Fenwick hot sheet](../../../../notebook/fenwick-hot-sheet.md)
- point add plus prefix/range sum starter -> [fenwick-point-prefix.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/fenwick-point-prefix.cpp)
- compare against heavier range structures -> [Segment Tree hot sheet](../../../../notebook/segment-tree-hot-sheet.md)

## Exit Criteria

You are ready to move on when:

- you can write `add` and `sum_prefix` from memory
- you can explain the role of `lowbit`
- you know when segment tree is needed instead

## External Practice

- [USACO Guide - BIT / Fenwick Tree](https://usaco.guide/gold/PURS)
- [CSES Problem Set](https://cses.fi/problemset/)
- [CP-Algorithms - Fenwick Tree](https://cp-algorithms.com/data_structures/fenwick.html)

## Tutorial Link

- [Fenwick Tree](../../../../topics/data-structures/fenwick-tree/README.md)
