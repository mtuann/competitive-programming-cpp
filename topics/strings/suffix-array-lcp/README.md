# Suffix Array And LCP

Suffix array is the contest-friendly suffix structure for sorted suffix order, substring comparison, and longest common prefix queries.

## Prerequisites

- [String Hashing](../hashing/README.md)
- [Sorting](../../foundations/patterns/sorting/README.md)

## When To Suspect It

- you need suffix order or substring rank
- the problem asks for repeated longest common prefix reasoning
- distinct substring or lexicographic suffix logic appears
- hashing feels too probabilistic, but suffix automaton feels too abstract for the task

## Core Idea

Sort suffixes indirectly by doubling prefix length:

```text
rank by 1 char
rank by 2 chars
rank by 4 chars
...
```

At each step, a suffix is represented by a pair of ranks:

```text
(rank[i], rank[i + 2^k])
```

Once the suffix array is built, compute `lcp[i]` between adjacent suffixes in suffix-array order.

## Theory / Proof Sketch

At doubling step `k`, suffixes are ordered by the pair of ranks for the first `2^k` characters. Once those pairs are sorted, the next doubling step is built from already-known shorter ranks.

That is why the structure works:

- shorter prefix ranks summarize earlier work
- sorting rank pairs refines the suffix order
- after enough doublings, all suffixes are uniquely ordered

Kasai's LCP algorithm is linear because the common-prefix length between consecutive suffixes can only decrease by at most one when advancing the starting index.

## Complexity And Tradeoffs

- classic doubling suffix array: `O(n log n)`
- Kasai LCP: `O(n)`
- many substring/rank queries become `O(1)` or `O(log n)` after preprocessing

Tradeoffs:

- exact and powerful
- heavier than hashing for simple substring equality
- easier to explain and debug than suffix automaton for many static-string tasks

## Canonical Pattern

Template in this repo:

- [suffix-array.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/suffix-array.cpp)

Standard workflow:

1. append a sentinel if your implementation expects one
2. build suffix array by doubling
3. build rank array from suffix array
4. run Kasai for LCP
5. answer distinct-substring, lexicographic, or repeated-substring questions from `sa`, `rank`, and `lcp`

## Worked Examples

Example 1: count distinct substrings

If the string length is `n`, then:

```text
total substrings = n * (n + 1) / 2
duplicate contribution = sum(lcp[i])
distinct substrings = total - duplicate contribution
```

Example 2: lexicographically smallest suffix or rotation variants

Suffix array order gives suffix rank directly. With suitable doubling/tricks, similar logic extends to cyclic shifts.

Example 3: longest repeated substring

The maximum value in `lcp` is the length of the longest repeated substring.

## Recognition Cues

- sorted suffix order matters
- repeated substring structure must be handled exactly
- many lexicographic substring comparisons appear
- one static string is queried heavily after preprocessing

## Common Mistakes

- confusing suffix array positions with original string indices
- forgetting sentinel handling or using a sentinel not smaller than all characters
- mixing up `rank[pos]` and `sa[idx]`
- building LCP against the wrong neighbors
- using suffix array when KMP, Z, or hashing already solves the narrower task

## Standard Variants

- doubling suffix array
- suffix array with sentinel
- Kasai LCP
- RMQ over LCP for fast arbitrary suffix LCP queries
- cyclic-shift / minimal-rotation style applications

## Practice Ladder

- [Suffix array and LCP ladder](../../../practice/ladders/strings/suffix-array-lcp/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Suffix Array](https://cp-algorithms.com/string/suffix-array.html)
- Reference: [OI Wiki - Suffix Array](https://en.oi-wiki.org/string/sa/)
- Blog/reference: [USACO Guide - Suffix Arrays](https://usaco.guide/adv/suffix-array?lang=cpp)
- Notes: [Stanford suffix-array related notes](https://web.stanford.edu/class/archive/cs/cs166/)

## Related Topics

- [Suffix Automaton](../suffix-automaton/README.md)
- [String Hashing](../hashing/README.md)
