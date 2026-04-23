# Suffix Array And LCP

Suffix array is the contest-friendly suffix structure for sorted suffix order, substring comparison, and longest common prefix queries.

## Prerequisites

- [String Hashing](../hashing/README.md)
- [Sorting](../../foundations/patterns/sorting/README.md)

## When To Suspect It

- you need suffix order or substring rank
- the problem asks for repeated longest common prefix reasoning
- distinct substring or lexicographic suffix logic appears

## Core Idea

Sort suffixes indirectly by doubling prefix length:

```text
rank by 1 char
rank by 2 chars
rank by 4 chars
...
```

Then build LCP to compare adjacent suffixes.

## Theory / Proof Sketch

At doubling step `k`, suffixes are ordered by the pair of ranks for the first `2^k` characters. Once those pairs are sorted, the next doubling step is built from already-known shorter ranks.

## Complexity And Tradeoffs

- classic doubling suffix array: `O(n log n)`
- Kasai LCP: `O(n)`

Tradeoffs:

- exact and powerful
- heavier than hashing for simple substring equality

## Canonical Pattern

Template in this repo:

- [suffix-array.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/suffix-array.cpp)

## Worked Examples

Example 1: count distinct substrings

Example 2: lexicographically smallest suffix / rotation variants

Example 3: longest repeated substring

## Common Mistakes

- confusing suffix array positions with original string indices
- forgetting sentinel handling
- using suffix array when KMP, Z, or hashing already solves the narrower task

## Practice Ladder

- [Suffix array and LCP ladder](../../../practice/ladders/strings/suffix-array-lcp/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Suffix Array](https://cp-algorithms.com/string/suffix-array.html)
- Reference: [OI Wiki - Suffix Array](https://en.oi-wiki.org/string/sa/)

## Related Topics

- [Suffix Automaton](../suffix-automaton/README.md)
- [String Hashing](../hashing/README.md)
