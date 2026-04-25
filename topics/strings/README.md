# Strings

Strings matter because many pattern problems are really about structure in sequences. This area should move from lightweight tools to exact matching and then to suffix-style machinery.

## What This Area Covers

This section is about different levels of string thinking:

- lightweight fingerprints and exact one-pattern tools
- palindrome-center scans on one static string
- append-only palindrome dictionaries over one growing string
- dictionary and automaton structures for many patterns
- suffix-style structures for global substring reasoning

The goal is not to memorize every named algorithm. It is to learn which *view of a string* fits the problem:

- prefix view
- pattern-matching view
- palindrome-center view
- palindrome-dictionary view
- trie/automaton view
- suffix/substring view

## Subtopics

- [Hashing](hashing/README.md)
- [KMP](kmp/README.md)
- [Z-Function](z-function/README.md)
- [Palindromes / Manacher](palindromes/README.md)
- [Eertree / Palindromic Tree](eertree/README.md)
- [Trie](trie/README.md)
- [Aho-Corasick](aho-corasick/README.md)
- [Suffix Array And LCP](suffix-array-lcp/README.md)
- [Suffix Automaton](suffix-automaton/README.md)

## Entry

- Prereqs: [Foundations](../foundations/README.md)
- Start here if: array reasoning is comfortable and repeated substring/pattern questions are starting to show up
- Defer for later: suffix structures until exact matching tools feel familiar

## Learn In Order

1. Core now
- string hashing
- KMP
- Z-function

2. Contest core
- palindromes / Manacher
- Eertree / palindromic tree
- trie
- Aho-Corasick
- suffix array and LCP

3. Advanced later
- suffix automaton
- border-heavy variants
- substring data-structure combinations

## Recognition Cues

- the problem asks for repeated pattern checks, substring relations, or many string queries
- exact matching matters more than character-by-character simulation
- naive scanning is too slow but preprocessing one string or one pattern set could help many queries
- the problem is about borders, prefixes, suffixes, or repeated substrings

## Common Pitfalls

- using hashing where exact matching is required without collision discussion
- learning suffix structures before the simpler pattern tools are automatic
- forgetting that many string problems become array problems after encoding
- choosing a heavy structure when one linear-time exact tool already solves the task

## Exit Criteria

After this section, you should be able to:

- choose between hashing, KMP, and Z for one-pattern or substring-comparison tasks
- know when one static palindrome scan wants Manacher instead of hashing
- know when a growing string wants the dictionary of distinct palindromes instead of raw radii
- recognize when a trie or Aho-Corasick is the right many-pattern structure
- use suffix array for static-string substring structure
- know when suffix automaton is worth the extra conceptual weight

## Go Deeper

- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Reference: [OI Wiki](https://en.oi-wiki.org/)
- Practice: [ICPC Problem Archive](https://foundation.icpc.global/archive/)
- Practice: [CSES Problem Set](https://cses.fi/)
- Reference: [KACTL](https://github.com/kth-competitive-programming/kactl)
