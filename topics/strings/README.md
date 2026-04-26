# Strings

<div class="badge-row" markdown>
  <span class="route-badge route-badge--deep">Deep</span>
</div>

Strings matter because many pattern problems are really about structure in sequences.

## Use This Area When

- the problem is about repeated pattern checks, substring structure, or many string queries
- exact matching matters more than raw simulation
- the right mental model is prefixes, automata, palindromes, or suffix structures

## Start With One Route

| If your bottleneck is... | Open first | Then |
| --- | --- | --- |
| one-pattern exact matching | [KMP](kmp/README.md) | [Z-Function](z-function/README.md), then [Hashing](hashing/README.md) |
| many patterns or dictionary matching | [Trie](trie/README.md) | [Aho-Corasick](aho-corasick/README.md) |
| palindrome structure | [Palindromes / Manacher](palindromes/README.md) | [Eertree / Palindromic Tree](eertree/README.md) |
| full substring index structures | [Suffix Array And LCP](suffix-array-lcp/README.md) | [Suffix Automaton](suffix-automaton/README.md), [Suffix Tree](suffix-tree/README.md) |

## Core Progression

1. `Core first`
- KMP
- Z-Function
- Hashing

2. `Then add`
- Palindromes / Manacher
- Trie / Aho-Corasick
- Suffix Array And LCP

3. `Deep later`
- Eertree / Palindromic Tree
- Regular Expressions / Finite Automata
- Suffix Automaton
- Suffix Tree

## Good First Repo Anchors

- [Finding Borders](../../practice/ladders/strings/hashing/findingborders.md)
- [Finding Periods](../../practice/ladders/strings/z-function/findingperiods.md)
- [Longest Palindrome](../../practice/ladders/strings/palindromes/longestpalindrome.md)
- [Finding Patterns](../../practice/ladders/strings/aho-corasick/findingpatterns.md)
- [Pattern Positions](../../practice/ladders/strings/suffix-tree/patternpositions.md)

## Browse All Subtopics

- [Hashing](hashing/README.md)
- [KMP](kmp/README.md)
- [Z-Function](z-function/README.md)
- [Palindromes / Manacher](palindromes/README.md)
- [Eertree / Palindromic Tree](eertree/README.md)
- [Trie](trie/README.md)
- [Aho-Corasick](aho-corasick/README.md)
- [Regular Expressions / Finite Automata](regex-finite-automata/README.md)
- [Suffix Tree](suffix-tree/README.md)
- [Suffix Array And LCP](suffix-array-lcp/README.md)
- [Suffix Automaton](suffix-automaton/README.md)

## Go Deeper

- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Reference: [OI Wiki](https://en.oi-wiki.org/)
- Practice: [ICPC Problem Archive](https://foundation.icpc.global/archive/)
- Practice: [CSES Problem Set](https://cses.fi/)
- Reference: [KACTL](https://github.com/kth-competitive-programming/kactl)
