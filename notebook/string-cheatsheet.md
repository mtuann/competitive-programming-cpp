# String Cheatsheet

Use this page when the string task is close to a known family but you want the fastest route back to the right tool.

## Do Not Use When

- the bottleneck is still parsing the statement into a string model
- you need the full derivation of KMP / Z / suffix structures
- probabilistic hashing is unacceptable for the task but you are still reaching for it by habit

## Choose Fast

- one exact pattern in one text: KMP or Z
- one static longest-palindrome scan: [Palindromes hot sheet](palindromes-hot-sheet.md)
- one growing string, distinct palindromes, or longest palindromic suffix: [Eertree hot sheet](eertree-hot-sheet.md)
- many substring equality checks: [String Hashing hot sheet](string-hashing-hot-sheet.md)
- many patterns in one text: [Aho-Corasick hot sheet](aho-corasick-hot-sheet.md)
- one fixed text used as a compressed substring index: [Suffix Tree hot sheet](suffix-tree-hot-sheet.md)
- suffix-order / repeated-substring / lexicographic suffix tasks: [Suffix Array / LCP hot sheet](suffix-array-lcp-hot-sheet.md)

## KMP

```text
pi[i] = longest proper prefix that is also a suffix for s[0..i]
```

## Z-Function

```text
z[i] = longest prefix match starting at i
```

## Hashing Checklist

- normalize substring hashes
- use double hash or strong 64-bit style hashing
- remember it is probabilistic

## Trie Checklist

- pass count
- end count
- alphabet representation

## Core Invariants

- KMP / prefix function: longest proper border of each prefix
- Z-function: prefix match length starting at each position
- rolling hash: equal normalized hashes are evidence, not proof, unless the method is deterministic
- trie-based methods: node meaning must stay explicit

## Main Trap

The classic string failure is choosing a heavier structure than the task needs, or using hashing where deterministic matching would already be simpler and safer.

## Reopen Paths

- topic pages -> [KMP](../topics/strings/kmp/README.md), [Z-Function](../topics/strings/z-function/README.md), [Palindromes / Manacher](../topics/strings/palindromes/README.md), [Eertree / Palindromic Tree](../topics/strings/eertree/README.md), [Hashing](../topics/strings/hashing/README.md), [Aho-Corasick](../topics/strings/aho-corasick/README.md), [Suffix Tree](../topics/strings/suffix-tree/README.md), [Suffix Array And LCP](../topics/strings/suffix-array-lcp/README.md), [Suffix Automaton](../topics/strings/suffix-automaton/README.md)
- exact quick sheets -> [Palindromes hot sheet](palindromes-hot-sheet.md), [Eertree hot sheet](eertree-hot-sheet.md), [String Hashing hot sheet](string-hashing-hot-sheet.md), [Aho-Corasick hot sheet](aho-corasick-hot-sheet.md), [Suffix Tree hot sheet](suffix-tree-hot-sheet.md), [Suffix Array / LCP hot sheet](suffix-array-lcp-hot-sheet.md)
- template layer -> [Template library](../template-library.md)
- repo anchors -> [String Matching](../practice/ladders/strings/kmp/stringmatching.md), [String Functions](../practice/ladders/strings/z-function/stringfunctions.md), [Longest Palindrome](../practice/ladders/strings/palindromes/longestpalindrome.md), [Distinct Palindromic Substrings](../practice/ladders/strings/eertree/distinctpalindromicsubstrings.md), [Finding Patterns](../practice/ladders/strings/aho-corasick/findingpatterns.md)
