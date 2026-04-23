# Trie

A trie is the natural structure for many prefix problems over strings or bit patterns.

## Prerequisites

- [C++ Language For Contests](../../foundations/cpp-language/README.md)
- [BFS And DFS](../../graphs/bfs-dfs/README.md)

## When To Suspect It

- prefix lookup or prefix counting
- dictionary of many strings with shared prefixes
- bitwise xor trie problems

## Core Idea

Store one node per prefix. Each edge adds one character or bit.

Typical node data:

- next pointers
- count of words through this node
- count of words ending here

## Theory / Proof Sketch

Shared prefixes are represented once, so operations follow the queried string length rather than the total number of stored strings.

## Complexity And Tradeoffs

- insert/query: `O(length)`
- memory: proportional to total inserted characters

Tradeoffs:

- great for prefix structure
- memory-heavy if the alphabet is large and sparse

## Canonical Pattern

Template in this repo:

- [trie-basic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/trie-basic.cpp)

## Worked Examples

Example 1: count words with a given prefix

Example 2: dictionary membership

Example 3: xor trie for maximum xor

## Common Mistakes

- allocating too much memory with dense alphabets
- forgetting to store end counts separately from pass-through counts
- using trie when sorting plus binary search would be simpler

## Practice Ladder

- [Trie ladder](../../../practice/ladders/strings/trie/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Trie](https://cp-algorithms.com/string/aho_corasick.html)
- Reference: [USACO Guide - Trie](https://usaco.guide/gold/trie)

## Related Topics

- [Aho-Corasick](../aho-corasick/README.md)
- [KMP](../kmp/README.md)
