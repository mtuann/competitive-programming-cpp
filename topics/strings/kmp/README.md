# KMP

KMP is the exact linear-time pattern-matching tool when you need to find occurrences of one pattern in one text without hashing.

## Prerequisites

- [String Hashing](../hashing/README.md)

## When To Suspect It

- exact matching of one pattern in one text
- many questions about borders or prefix-suffix structure
- you want deterministic linear time

## Core Idea

Build the prefix-function array:

```text
pi[i] = length of the longest proper prefix of s[0..i] that is also a suffix
```

This captures how much of the pattern remains matched after a mismatch.

## Theory / Proof Sketch

When a mismatch happens after matching some prefix of the pattern, the best fallback is not zero by default. The prefix-function tells you the longest border that can still be valid, so the scan never reconsiders characters unnecessarily.

## Complexity And Tradeoffs

- prefix function: `O(n)`
- pattern matching: `O(n + m)`

Tradeoffs:

- exact and fast
- more specialized than hashing

## Canonical Pattern

Template in this repo:

- [kmp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/kmp.cpp)

## Worked Examples

Example 1: find all matches of pattern `p` in text `t`

Example 2: count borders of a string

Example 3: shortest string extension using borders

## Common Mistakes

- confusing `pi[i]` with the previous matched length in the text scan
- off-by-one errors when converting between indices and lengths
- using KMP where Z-function is simpler for prefix-heavy tasks

## Practice Ladder

- [KMP ladder](../../../practice/ladders/strings/kmp/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Prefix Function / KMP](https://cp-algorithms.com/string/prefix-function.html)
- Reference: [OI Wiki - KMP](https://en.oi-wiki.org/string/kmp/)

## Related Topics

- [Z-Function](../z-function/README.md)
- [String Hashing](../hashing/README.md)
