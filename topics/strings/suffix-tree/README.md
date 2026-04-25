# Suffix Tree

Suffix tree is the compressed suffix-trie view of one static string.

Among the heavy exact string structures in this repo:

- [Suffix Array And LCP](../suffix-array-lcp/README.md) is usually the cleanest static suffix-order tool
- [Suffix Automaton](../suffix-automaton/README.md) is the strongest online "all substrings of one base string" state machine
- suffix tree is the direct compressed-index view when you want to walk substring queries on edge intervals

This page teaches the contest route that matters most:

1. append one unique terminator
2. build the compressed suffix tree once
3. answer substring existence or earliest-occurrence queries by walking compressed edges and reading subtree metadata

## At A Glance

Reach for suffix tree when:

- one text is fixed in advance
- many substring queries will be asked against that one text
- you want a literal compressed-index view instead of suffix order
- earliest occurrence or "does this pattern exist?" can be stored as subtree data on suffix leaves

Strong contest triggers:

- "one static text, many patterns"
- "walk a pattern through compressed suffix edges"
- "find the first position where a pattern appears"
- "use one static string as an exact substring index"

Strong anti-cues:

- one exact pattern only: [KMP](../kmp/README.md) or [Z-Function](../z-function/README.md) is lighter
- many patterns in one text from the pattern-trie direction: [Aho-Corasick](../aho-corasick/README.md) is usually cleaner
- suffix order, lexicographic ranking, or adjacent LCP is the real object: [Suffix Array And LCP](../suffix-array-lcp/README.md) is the natural fit
- the base string grows online and substring-state aggregation matters more than tree edges: [Suffix Automaton](../suffix-automaton/README.md) fits better

What success looks like after studying this page:

- you can explain why a unique terminator is mandatory
- you can walk a pattern across compressed edge intervals instead of node-by-node characters
- you know why a pattern may end in the middle of an edge and still be fully matched
- you can store subtree metadata such as earliest suffix start and answer occurrence queries from it

## Prerequisites

- [Trie](../trie/README.md)
- [Suffix Array And LCP](../suffix-array-lcp/README.md) for neighboring static-string intuition

Helpful neighbors:

- [Suffix Automaton](../suffix-automaton/README.md)
- [Aho-Corasick](../aho-corasick/README.md)

## Problem Model

Let `s` be one string of length `n`.

The suffix tree of `s` is the trie of all suffixes after compressing every maximal single-child chain into one edge interval.

To make every suffix end at a unique leaf, we append one character:

- smaller or larger than every real character is fine
- but it must be unique
- and it must not appear inside the original text

In this repo's starter, we append `'{'`, which is one step after `'z'` in ASCII and is safe because the text is restricted to lowercase `a-z`.

So the real built string is:

```text
s + '{'
```

Every suffix then ends at a distinct leaf.

## Why Compression Changes The Right Mental Model

In an ordinary trie, every edge stores one character.

In a suffix tree, an edge stores an interval:

```text
s[l..r)
```

inside the original text.

That means matching is no longer:

- move one node per character

It becomes:

- choose the outgoing edge by its first character
- then keep consuming characters while you stay inside that edge interval

This is the first trap that makes suffix tree feel harder than suffix array or automaton if the matching model is still too node-centric.

## Core Invariant

Every leaf corresponds to one suffix start.

If a pattern `p` is matched completely while walking from the root:

- whether the match ends exactly at a node
- or in the middle of a compressed edge

the whole subtree below that point represents suffixes whose prefixes start with `p`.

So many useful answers become subtree aggregates:

- existence -> does the walk succeed?
- earliest occurrence -> minimum suffix start in that subtree
- counts -> number of suffix leaves in that subtree

For the exact first route in this repo, the key metadata is:

```text
min_start[v] = minimum original suffix start among leaves in subtree(v)
```

Then:

- if a pattern walk fails, answer is `-1`
- if a pattern walk succeeds, answer is `min_start` of the last matched edge child

This stays correct even when the pattern ends in the middle of that child edge, because every leaf below that child still contains the matched prefix.

## Ukkonen Route In Contest Terms

You do not need to memorize every proof detail to use the structure.

What matters in contest practice:

1. the active point says where the next extension currently ends
2. `go` walks over compressed edges
3. `split` creates an explicit node when the active point sits inside an edge
4. suffix links let the next extension restart from the correct smaller suffix context

The repo starter uses the standard Ukkonen contest shape:

- nodes store edge interval `[l, r)`
- transitions are fixed-array for lowercase plus terminator
- build is linear in the string length for this fixed alphabet

## Complexity

For the exact route in this repo:

- build: `O(n * alphabet)` with fixed-array transitions, which is linear for the fixed lowercase alphabet
- one pattern query of length `m`: `O(m)`
- nodes: `O(n)`
- memory: `O(n * alphabet)` because each node stores a fixed transition array

## Main Traps

- forgetting the unique terminator, so suffixes are no longer guaranteed to end at distinct leaves
- matching edge-by-edge but forgetting the pattern can finish in the middle of a compressed edge
- treating suffix tree as a better suffix array for every static-string problem, even when suffix order is the real object
- storing leaf answers but forgetting many tasks want subtree aggregates over all leaves below a matched edge

## Exact First Route In This Repo

Use the starter when the signal is:

- one fixed lowercase text
- exact substring existence or earliest-occurrence queries
- compressed edge walking feels more natural than suffix order

Repo route:

- hot sheet -> [Suffix Tree hot sheet](../../../notebook/suffix-tree-hot-sheet.md)
- starter -> [suffix-tree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/suffix-tree.cpp)
- flagship note -> [Pattern Positions](../../../practice/ladders/strings/suffix-tree/patternpositions.md)

## Compare Points

- choose [Suffix Array And LCP](../suffix-array-lcp/README.md) when lexicographic suffix order or adjacent LCP is the main object
- choose [Suffix Automaton](../suffix-automaton/README.md) when the string grows online and state aggregation over all substrings matters
- choose [Aho-Corasick](../aho-corasick/README.md) when many patterns are known first and one text is scanned against the pattern trie

## Go Deeper

- Reference: [CP-Algorithms - Suffix Tree (Ukkonen)](https://cp-algorithms.com/string/suffix-tree-ukkonen.html)
- Reference: [OI Wiki - Suffix Tree](https://en.oi-wiki.org/string/suffix-tree/)
- Reference: [USACO Guide - String Suffix Structures](https://usaco.guide/adv/string-suffix)
- Practice: [CSES Pattern Positions](https://cses.fi/problemset/task/2104)
