# Suffix Automaton

Suffix automaton is the compact state-machine view of all substrings of a string. It is deeper than suffix array, but extremely powerful once the state meaning clicks.

## Prerequisites

- [Suffix Array And LCP](../suffix-array-lcp/README.md)
- [Trie](../trie/README.md)

## When To Suspect It

- substring queries over one growing string
- distinct substring counting or longest common substring variants
- you want the automaton of all substrings rather than all prefixes

## Core Idea

Each state represents an equivalence class of substrings sharing the same set of end positions.

The automaton grows online one character at a time, with suffix links handling fallback.

## Theory / Proof Sketch

The core invariant is that each state represents all substrings whose lengths lie in:

```text
(len(link[state]), len(state)]
```

This compactly stores every substring of the processed text.

## Complexity And Tradeoffs

- build: `O(n)` amortized
- many queries become linear or near-linear in the query size

Tradeoffs:

- very powerful
- much harder to learn and debug than KMP, Z, or suffix array

## Canonical Pattern

Start with:

- state `0` as the initial state
- extend one character at a time
- use suffix links and clones

## Worked Examples

Example 1: count distinct substrings

Example 2: longest common substring with another string

Example 3: frequency or occurrence aggregation on states

## Common Mistakes

- not understanding what a state means before coding
- forgetting clone behavior
- using suffix automaton for tasks where suffix array or hashing is easier

## Practice Ladder

- [Suffix automaton ladder](../../../practice/ladders/strings/suffix-automaton/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Suffix Automaton](https://cp-algorithms.com/string/suffix-automaton.html)
- Reference: [OI Wiki - Suffix Automaton](https://en.oi-wiki.org/string/sam/)

## Related Topics

- [Suffix Array And LCP](../suffix-array-lcp/README.md)
- [Aho-Corasick](../aho-corasick/README.md)
