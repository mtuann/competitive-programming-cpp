# KMP

KMP is the exact linear-time pattern-matching tool when you need to find occurrences of one pattern in one text without hashing.

## Prerequisites

- [String Hashing](../hashing/README.md)

## When To Suspect It

- exact matching of one pattern in one text
- many questions about borders or prefix-suffix structure
- you want deterministic linear time
- the pattern itself has useful internal repetition that should not be recomputed after mismatches

## Core Idea

Build the prefix-function array:

```text
pi[i] = length of the longest proper prefix of s[0..i] that is also a suffix
```

This captures how much of the pattern remains matched after a mismatch.

In matching, if you have currently matched `j` characters and the next character fails, jump to:

```text
j = pi[j - 1]
```

instead of starting from zero.

## Theory / Proof Sketch

When a mismatch happens after matching some prefix of the pattern, the best fallback is not zero by default. The prefix-function tells you the longest border that can still be valid, so the scan never reconsiders characters unnecessarily.

That is the whole KMP idea:

- reuse already-proved prefix/suffix overlap
- never move the text pointer backward
- only move the pattern state using border information

## Complexity And Tradeoffs

- prefix function: `O(n)`
- pattern matching: `O(n + m)`

Tradeoffs:

- exact and fast
- more specialized than hashing
- often the cleanest tool for one-pattern exact matching or border questions

## Canonical Pattern

Template in this repo:

- [kmp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/kmp.cpp)

Standard workflow:

1. build `pi` for the pattern or for one combined string
2. scan the text while maintaining current matched length
3. fall back with `pi` on mismatches
4. record a match when matched length reaches `pattern_length`

## Worked Examples

Example 1: find all matches of pattern `p` in text `t`

The classic KMP scan reports every occurrence in linear time.

Example 2: count borders of a string

Repeatedly jump:

```text
x = pi[n - 1]
x = pi[x - 1]
...
```

to enumerate all border lengths.

Example 3: shortest string extension using borders

If you need to append the fewest characters so a string gains a certain periodic or border property, `pi` often gives the exact overlap to reuse.

## Recognition Cues

- one pattern, one text
- exact matching, not approximate matching
- borders, prefix-suffix overlaps, periods, or repeated prefixes appear
- a concatenation trick like `pattern + '#' + text` looks plausible

## Common Mistakes

- confusing `pi[i]` with the previous matched length in the text scan
- off-by-one errors when converting between indices and lengths
- forgetting to continue from the border after a full match
- using KMP where Z-function is simpler for prefix-heavy tasks
- building `pi` on the wrong string for the intended interpretation

## Standard Variants

- single-pattern matching
- border enumeration
- minimal period checks
- prefix-function on `pattern + '#' + text`
- DP or automaton transitions built from prefix-function states

## Practice Ladder

- [KMP ladder](../../../practice/ladders/strings/kmp/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Prefix Function / KMP](https://cp-algorithms.com/string/prefix-function.html)
- Reference: [OI Wiki - KMP](https://en.oi-wiki.org/string/kmp/)
- Blog/reference: [USACO Guide - String Searching](https://usaco.guide/adv/string-search?lang=cpp)
- Paper/notes: [Knuth-Morris-Pratt original paper background](https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm)

## Related Topics

- [Z-Function](../z-function/README.md)
- [String Hashing](../hashing/README.md)
