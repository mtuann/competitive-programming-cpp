# Trie

A trie is the natural structure for many prefix problems over strings or bit patterns.

## Prerequisites

- [C++ Language For Contests](../../foundations/cpp-language/README.md)
- [BFS And DFS](../../graphs/bfs-dfs/README.md)

## When To Suspect It

- prefix lookup or prefix counting
- dictionary of many strings with shared prefixes
- bitwise xor trie problems
- you need to process queries by character/bit, not by whole-string sorting

## Core Idea

Store one node per prefix. Each edge adds one character or bit.

Typical node data:

- next pointers
- count of words through this node
- count of words ending here

Operations walk the query string character by character and move through the prefix tree.

## Theory / Proof Sketch

Shared prefixes are represented once, so operations follow the queried string length rather than the total number of stored strings.

That is the main structural win:

- sorting + binary search works on whole strings
- trie walks only the needed prefix path

For bitwise tries, the same idea becomes a binary tree over bits, which is why maximum-xor queries fit the same template.

## Complexity And Tradeoffs

- insert/query: `O(length)`
- memory: proportional to total inserted characters

Tradeoffs:

- great for prefix structure
- memory-heavy if the alphabet is large and sparse
- sometimes slower in practice than sorting for small static dictionaries

## Canonical Pattern

Template in this repo:

- [trie-basic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/trie-basic.cpp)

Standard workflow:

1. choose alphabet representation
2. insert all strings while updating pass/end counts
3. answer prefix or membership queries by walking edges
4. add extra metadata only when the problem truly needs it

## Worked Examples

Example 1: count words with a given prefix

Store `pass_count` on each node. After walking the prefix, return the count at that node.

Example 2: dictionary membership

Store `end_count` or `is_terminal` and check it after consuming all characters.

Example 3: xor trie for maximum xor

Over bits, greedily prefer the opposite bit when maximizing xor.

## Recognition Cues

- many strings, many prefix queries
- autocomplete-style or dictionary-style tasks
- words share long prefixes
- maximum xor / minimum xor with online insertions

## Common Mistakes

- allocating too much memory with dense alphabets
- forgetting to store end counts separately from pass-through counts
- mixing string trie and xor trie intuitions
- using trie when sorting plus binary search would be simpler
- not clearing or pooling nodes carefully across test cases

## Standard Variants

- lowercase-letter trie
- sparse-map trie for large alphabets
- xor trie
- compressed trie / radix ideas
- trie with extra DP or counting metadata

## Practice Ladder

- [Trie ladder](../../../practice/ladders/strings/trie/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Trie / Aho-Corasick background](https://cp-algorithms.com/string/aho_corasick.html)
- Reference: [USACO Guide - Trie](https://usaco.guide/gold/trie)
- Blog/reference: [OI Wiki - Trie](https://en.oi-wiki.org/string/trie/)

## Related Topics

- [Aho-Corasick](../aho-corasick/README.md)
- [KMP](../kmp/README.md)
