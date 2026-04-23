# Aho-Corasick

Aho-Corasick is the multi-pattern extension of trie matching. Use it when many patterns are matched against one text.

## Prerequisites

- [Trie](../trie/README.md)
- [BFS And DFS](../../graphs/bfs-dfs/README.md)

## When To Suspect It

- many patterns, one long text
- you need all occurrences of many keywords
- pattern matching with shared prefixes should be reused

## Core Idea

Build a trie of the patterns, then add failure links that point to the next best suffix state after a mismatch.

This turns the trie into an automaton.

## Theory / Proof Sketch

Failure links play the same role as KMP fallback, but on trie states instead of a single string. BFS over the trie builds those links in increasing depth order, which ensures each state's fallback is already known.

## Complexity And Tradeoffs

- build: `O(total pattern length * alphabet handling)`
- scan text: `O(text length + matches)`

Tradeoffs:

- perfect for multi-pattern exact matching
- heavier than KMP or Z for one pattern

## Canonical Pattern

Template in this repo:

- [aho-corasick.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/aho-corasick.cpp)

## Worked Examples

Example 1: count keyword occurrences in a document

Example 2: forbidden substring DP using automaton states

Example 3: output all matches of many patterns

## Common Mistakes

- forgetting to propagate output links or terminal counts through failure links
- using a dense alphabet table when the alphabet is large and sparse
- overusing Aho-Corasick when the pattern count is tiny

## Practice Ladder

- [Aho-Corasick ladder](../../../practice/ladders/strings/aho-corasick/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Aho-Corasick](https://cp-algorithms.com/string/aho_corasick.html)
- Reference: [OI Wiki - AC Automaton](https://en.oi-wiki.org/string/ac-automaton/)

## Related Topics

- [Trie](../trie/README.md)
- [Digit DP](../../dp/digit-dp/README.md)
