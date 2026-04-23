# String Hashing

String hashing is the lightweight substring-comparison tool. It is often the fastest way to compare many substrings or support binary search on answers over strings.

## Prerequisites

- [Prefix Sums](../../foundations/patterns/prefix-sums/README.md)
- [Modular Arithmetic](../../math/modular-arithmetic/README.md)

## When To Suspect It

- many substring equality checks
- binary search on common prefix length or answer length
- the solution benefits from fast substring fingerprints

## Core Idea

Precompute polynomial hashes and powers:

```text
hash[l..r] = pref[r] - pref[l - 1] * pow_base[len]
```

Then substring comparison becomes `O(1)` after preprocessing.

## Theory / Proof Sketch

The hash is a compact fingerprint, not a proof of equality. In contest settings, double hashing or strong 64-bit hashing makes collisions very unlikely, but it is still a randomized tool.

## Complexity And Tradeoffs

- preprocess: `O(n)`
- substring hash query: `O(1)`

Tradeoffs:

- extremely useful and simple
- probabilistic rather than exact

## Canonical Pattern

Template in this repo:

- [rolling-hash.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/rolling-hash.cpp)

## Worked Examples

Example 1: longest common prefix with binary search

Example 2: distinct substrings with hash sets

Example 3: string matching with hash verification

## Common Mistakes

- forgetting to normalize substring hashes
- using one weak modulus and treating collisions as impossible
- reaching for hashing when KMP or Z gives an exact linear solution

## Practice Ladder

- [Hashing ladder](../../../practice/ladders/strings/hashing/README.md)

## Go Deeper

- Reference: [CP-Algorithms - String Hashing](https://cp-algorithms.com/string/string-hashing.html)
- Reference: [USACO Guide - Hashing](https://usaco.guide/gold/hashing)

## Related Topics

- [KMP](../kmp/README.md)
- [Z-Function](../z-function/README.md)
- [Suffix Array And LCP](../suffix-array-lcp/README.md)
