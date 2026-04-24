# Z-Function

The Z-function is another exact linear-time string tool. It is especially clean for questions about matches against the whole prefix.

## Prerequisites

- [KMP](../kmp/README.md)

## When To Suspect It

- you want to know how much the prefix matches at every position
- the problem is about borders, repetitions, or prefix matches
- a concatenation like `pattern + '#' + text` suggests itself naturally
- KMP would work, but the problem language is "prefix against suffix positions"

## Core Idea

Define:

```text
z[i] = longest length such that s[0..z[i]) = s[i..i+z[i])
```

Maintain the current best `[l, r)` segment already known to match the prefix.

If `i < r`, then part of `z[i]` is inherited from the mirrored position inside that segment. Only the extension beyond `r` needs fresh comparisons.

## Theory / Proof Sketch

The key invariant is:

```text
s[l..r) = s[0..r-l)
```

for the current best segment.

If `i` lies inside that segment, the matching information is partially reusable. Because every fresh character comparison extends `r`, the total number of new comparisons over the whole algorithm is linear.

## Complexity And Tradeoffs

- build Z array: `O(n)`

Tradeoffs:

- often simpler than KMP for prefix-match tasks
- very natural for concatenation-based pattern matching
- less obvious than KMP for border chaining or automaton-style transitions

## Canonical Pattern

Template in this repo:

- [z-function.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/z-function.cpp)

Notebook:

- [String cheatsheet](../../../notebook/string-cheatsheet.md)

Standard workflow:

1. initialize `l = r = 0`
2. if `i < r`, seed `z[i]` from the mirrored position
3. extend by direct comparison while possible
4. update `[l, r)` if the new segment is better

## Worked Examples

Example 1: pattern matching via concatenation

Build:

```text
pattern + '#' + text
```

Then every position where `z[i] >= pattern_length` is a match.

Example 2: counting prefix occurrences

The Z array directly tells how strongly the prefix appears at every shift.

Example 3: detecting periodic structure

If `i + z[i] = n` and `n % i = 0`, then `i` is a candidate period.

Repo anchors:

- [String Functions](../../../practice/ladders/strings/z-function/stringfunctions.md)
- [Finding Periods](../../../practice/ladders/strings/z-function/findingperiods.md)

## Recognition Cues

- repeated references to "prefix matches"
- pattern matching with one concatenated string
- problems about borders, periods, or repeated blocks
- you want exact answers and the prefix viewpoint feels more natural than fallback links

## Common Mistakes

- mixing inclusive and exclusive `r`
- forgetting that `z[0]` is usually set to `0` by convention
- writing the mirrored-position formula incorrectly
- using Z where KMP border chaining is more direct
- forgetting to separate pattern and text with a delimiter not in the alphabet

## Standard Variants

- prefix-match array for one string
- concatenation-based pattern matching
- period detection
- counting border/prefix occurrences
- hybrids with suffix or prefix frequency arrays

## Practice Ladder

- [Z-function ladder](../../../practice/ladders/strings/z-function/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Z-Function](https://cp-algorithms.com/string/z-function.html)
- Reference: [OI Wiki - Z Function](https://en.oi-wiki.org/string/z-func/)
- Blog/reference: [USACO Guide - String Searching](https://usaco.guide/adv/string-search?lang=cpp)

## Related Topics

- [KMP](../kmp/README.md)
- [String Hashing](../hashing/README.md)
