# Strings

Strings matter because many pattern problems are really about structure in sequences. This area should move from lightweight tools to exact matching and then to suffix-style machinery.

## Entry

- Prereqs: [Foundations](../foundations/README.md)
- Defer for later: suffix structures until exact matching tools feel familiar

## Learn In Order

1. Core now
- string hashing
- KMP and Z-function

2. Contest core
- trie
- Aho-Corasick
- suffix array

3. Advanced later
- suffix automaton
- palindromic and border-heavy variants
- advanced substring data-structure combinations

## Recognition Cues

- the problem asks for repeated pattern checks, substring relations, or many string queries
- exact matching matters more than character-by-character simulation
- naive scanning is too slow but preprocessing one string could help many queries

## Common Pitfalls

- using hashing where exact matching is required without collision discussion
- learning suffix structures before the simpler pattern tools are automatic
- forgetting that many string problems become array problems after encoding

## Exit Criteria

After this section, you should be able to choose between lightweight matching tools, trie-based preprocessing, and suffix-style structures based on what the query pattern actually needs.

## Go Deeper

- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Reference: [OI Wiki](https://en.oi-wiki.org/)
- Practice: [ICPC Problem Archive](https://foundation.icpc.global/archive/)
- Practice: [CSES Problem Set](https://cses.fi/)
