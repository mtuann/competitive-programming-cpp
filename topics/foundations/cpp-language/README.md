# C++ Language For Contests

This page is about getting C++ out of your way. In competitive programming, the language is not the goal, but weak language habits create enough friction to hide good algorithmic ideas.

## Summary

Study this topic if:

- you know the idea but lose time to syntax, container choice, or indexing bugs
- you are unsure when to use `int`, `long long`, `vector`, `pair`, `struct`, `map`, or `set`
- your wrong answers come from implementation mistakes more often than from bad modeling

What success looks like:

- you can write a clean contest skeleton from memory
- you choose containers based on needed operations, not habit
- you can read and modify standard CP templates without fear

## Prerequisites

- basic programming experience in any language

## Core Idea

Contest C++ is mostly about four habits:

1. choose the simplest representation that matches the problem
2. keep variable meanings explicit
3. use standard-library tools you can trust
4. reduce repetition without hiding logic

The right mental model is:

```text
algorithm first
representation second
syntax last
```

When the representation is clean, correctness arguments and debugging both get easier.

## Theory / Proof Sketch

There is no theorem here, but there is a useful invariant:

- each variable should have one stable meaning
- each helper should remove repetition, not hide important decisions
- each container should match the operations you actually need

If that invariant breaks, bugs spread quickly:

- wrong type choice leads to overflow
- wrong container choice leads to awkward or slow code
- unclear helper behavior makes debugging much harder

## Complexity And Tradeoffs

Good C++ habits do not change big-O by themselves, but they matter a lot for:

- constant factors
- memory usage
- bug rate
- speed of implementation under pressure

Useful defaults:

- `vector` is the normal dynamic sequence container
- `array` is good for fixed-size small structures
- `pair` is fine when the meaning is obvious
- `struct` is better when named fields improve clarity
- `map` and `set` keep order
- `unordered_map` and `unordered_set` are hash-based and faster on average, but less predictable
- `priority_queue` is good when you only need the current extremum

Type defaults:

- `int` for indexes and small counts
- `long long` for sums, products, weights, and answers that may exceed about `2e9`
- `__int128` only when one multiplication can already exceed `long long`

## Canonical C++ Pattern

Start from a small contest skeleton and add helpers only when they remove real repetition.

Templates in this repo:

- [contest-main.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/contest-main.cpp)
- [fast-io.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/fast-io.cpp)
- [sort-and-comparator.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/sort-and-comparator.cpp)

Good contest habits:

- keep input parsing close to the data model
- prefer `struct` when field names explain the problem
- pass large objects by `const &` when read-only
- write comparators and helper functions with one clear job
- choose one indexing convention and keep it

Small example:

```cpp
struct Edge {
    int to;
    int weight;
};

long long total_weight(const vector<Edge> &edges) {
    long long sum = 0;
    for (const Edge &e : edges) sum += e.weight;
    return sum;
}
```

This is better than anonymous nested pairs if the fields matter later.

## Standard Toolkit

### Types

- prefer `int` until the range is not safe
- cast before multiplying if overflow is possible:

```cpp
long long area2 = 1LL * x1 * y2 - 1LL * y1 * x2;
```

- avoid mixing signed and unsigned types casually

### Containers

Ask which operations matter:

- append and iterate: `vector`
- FIFO: `queue`
- LIFO: `stack`
- min or max retrieval: `priority_queue`
- ordered membership / predecessor / successor: `set`
- key-value dictionary with order: `map`
- frequency table over small integer range: usually `vector<int>` beats any map

### Functions And Helpers

Use helpers for:

- repeated transitions
- geometry primitives
- compare / check predicates
- reusable data structures

Avoid helpers that force the reader to jump around just to understand the main algorithm.

## Worked Examples

### Example 1: `pair` vs `struct`

Use `pair<int, int>` when the meaning is obvious and local:

```cpp
vector<pair<int, int>> intervals;
```

Use a `struct` when fields carry meaning or there are more than two of them:

```cpp
struct Interval {
    int left;
    int right;
    int id;
};
```

### Example 2: passing vectors

Use:

- `const vector<int>& a` when only reading
- `vector<int>& a` when mutating
- plain `vector<int> a` only when you intentionally want a copy

This matters because accidental copies of `O(n)` containers are a common hidden slowdown.

### Example 3: choosing a frequency structure

If values are small and dense:

```cpp
vector<int> freq(max_value + 1);
```

If values are large or arbitrary:

```cpp
unordered_map<int, int> freq;
```

If you also need ordered iteration over keys:

```cpp
map<int, int> freq;
```

The right choice comes from operations, not style.

## Recognition Cues

You should revisit this topic when:

- coding time dominates thinking time
- you often patch the same syntax mistakes repeatedly
- your accepted solutions look much messier than editorial ones
- you cannot explain why you chose one container over another

This topic is often confused with “just learn more STL”. That is only part of it. The real goal is implementation fluency and representation discipline.

## Common Mistakes

- mixing `int` and `long long` carelessly in products
- using `unordered_map` when ordered iteration is part of the logic
- overusing macros that hide control flow or types
- copying large containers by value accidentally
- switching between 0-based and 1-based indexing mid-solution
- writing clever one-liners that are hard to debug under contest pressure

## Practice Ladder

- [Foundations ladder overview](../../../practice/ladders/foundations/README.md)
- [C++ language ladder](../../../practice/ladders/foundations/cpp-language/README.md)
- [STL ladder](../../../practice/ladders/foundations/stl/README.md)

Suggested order:

1. basic I/O and vector manipulation
2. pairs, structs, and sorting records
3. maps, sets, queues, and stacks
4. rewriting one messy solution into a clean version

## Go Deeper

- Course: [Princeton COS 226](https://www.cs.princeton.edu/~cos226)
- Reference: [CPPReference](https://en.cppreference.com/w/)
- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Practice: [CSES Problem Set](https://cses.fi/)
- Notes: [Template Library](https://github.com/mtuann/competitive-programming-cpp/blob/main/template-library.md)

## Related Topics

- [Reasoning](../reasoning/README.md)
- [Sorting](../patterns/sorting/README.md)
- [Binary Search](../patterns/binary-search/README.md)
- [Prefix Sums](../patterns/prefix-sums/README.md)
