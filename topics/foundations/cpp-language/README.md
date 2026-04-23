# C++ Language For Contests

This page is about writing contest C++ without fighting the language. The goal is not to cover every feature of modern C++, but to build a stable toolkit for fast and reliable implementation.

## Prerequisites

- basic programming experience in any language

## When To Study This

Study this page if:

- you know the algorithm but lose time to syntax, indexing, or container mistakes
- you are unsure when to use `int`, `long long`, `vector`, `pair`, `map`, or `set`
- your submissions fail more often from implementation bugs than from wrong ideas

## Core Idea

Contest C++ is mostly about three habits:

1. keep data representations simple
2. use standard-library tools you can trust
3. choose types and helper functions deliberately

The language layer should reduce cognitive load, not increase it.

## Theory / Proof Sketch

There is no deep theorem here, but there is an invariant worth keeping:

- every variable should have one clear meaning
- every helper should hide repetition, not hide logic
- every container choice should match the operations you need

If your representation stays clean, later proofs about the algorithm become much easier to state and check.

## Complexity And Tradeoffs

Good C++ habits do not change big-O by themselves, but they do change constant factors and bug rate.

Typical tradeoffs:

- `vector` is usually the default sequence container
- `array` is good when the size is fixed at compile time
- `map` is ordered but slower than `unordered_map`
- `set` keeps order, while `priority_queue` only gives access to the current extremum

Use the lightest tool that matches the required operations.

## Canonical C++ Pattern

Start from a clean contest skeleton and only add helpers when they remove real repetition.

Useful building blocks:

- fast I/O setup
- small `struct` types for edges, intervals, or events
- helper functions for repeated transitions or checks
- `const` and references for read-only parameters

Templates in this repo:

- [contest-main.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/contest-main.cpp)
- [fast-io.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/fast-io.cpp)
- [sort-and-comparator.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/sort-and-comparator.cpp)

## Worked Examples

Example 1: storing pairs of values

- use `pair<int, int>` when the meaning is obvious
- use a `struct` when field names clarify the problem

Example 2: passing vectors

- use `const vector<int>& a` when you only read
- use `vector<int>& a` when you mutate
- avoid copying a large vector by value unless you need a separate copy

Example 3: choosing numeric types

- use `int` for counts and indexes when the range is safe
- use `long long` for sums, products, or weights that may exceed about `2e9`

## Common Mistakes

- mixing `int` and `long long` carelessly in products
- using `unordered_map` when ordering is part of the logic
- hiding important algorithmic choices inside clever macros
- copying large containers accidentally
- switching between 0-based and 1-based indexing without a plan

## Practice Ladder

- [Foundations ladder overview](../../../practice/ladders/foundations/README.md)
- [C++ language ladder](../../../practice/ladders/foundations/cpp-language/README.md)
- [STL ladder](../../../practice/ladders/foundations/stl/README.md)

## Go Deeper

- Course: [Princeton COS 226](https://www.cs.princeton.edu/~cos226)
- Reference: [CPPReference](https://en.cppreference.com/w/)
- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Practice: [CSES Problem Set](https://cses.fi/)

## Related Topics

- [Reasoning](../reasoning/README.md)
- [Sorting](../patterns/sorting/README.md)
- [Binary Search](../patterns/binary-search/README.md)
