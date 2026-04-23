# String Hashing

String hashing is the lightweight substring-comparison tool. It is often the fastest way to compare many substrings or support binary search on answers over strings.

## Prerequisites

- [Prefix Sums](../../foundations/patterns/prefix-sums/README.md)
- [Modular Arithmetic](../../math/modular-arithmetic/README.md)

## When To Suspect It

- many substring equality checks
- binary search on common prefix length or answer length
- the solution benefits from fast substring fingerprints
- exact linear tools exist, but you need more flexible arbitrary-substring comparison

## Core Idea

Treat a string as a polynomial over character values and precompute prefix hashes and base powers.

Typical form:

```text
pref[i] = hash of s[0..i)
pow_base[i] = base^i
```

Then:

```text
hash(l, r) = pref[r] - pref[l] * pow_base[r - l]
```

so substring comparison becomes `O(1)` after preprocessing.

## Theory / Proof Sketch

The hash is a compact fingerprint, not a proof of equality. If two substrings are equal, their hashes must match. If the hashes match, the substrings are only *probably* equal.

That is why hashing is a randomized or Monte Carlo style tool in contest settings. In practice, collisions are made extremely unlikely with:

- double hashing
- strong 64-bit hashing
- careful choice of base and modulus

## Complexity And Tradeoffs

- preprocess: `O(n)`
- substring hash query: `O(1)`
- lcp by binary search + hashing: `O(log n)` per query

Tradeoffs:

- extremely useful and simple
- probabilistic rather than exact
- more flexible than KMP/Z for arbitrary substring questions

## Canonical Pattern

Template in this repo:

- [rolling-hash.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/rolling-hash.cpp)

Standard workflow:

1. choose base and modulus strategy
2. build prefix hashes and base powers
3. write a `get(l, r)` function
4. compare hashes or binary-search on the first mismatch

## Worked Examples

Example 1: longest common prefix with binary search

To compare suffixes starting at `i` and `j`, binary search the largest `len` such that:

```text
hash(i, i + len) = hash(j, j + len)
```

Example 2: distinct substrings with hash sets

For each fixed length `len`, insert all `hash(i, i + len)` into a set.

Example 3: string matching with hash verification

Compute the hash of the pattern once, then compare it against every text window of the same length.

## Recognition Cues

- "compare these two substrings many times"
- "find the longest repeated/common substring" with a binary search flavor
- suffix array or suffix automaton would work, but the constraints allow a simpler probabilistic tool
- the statement is about equality, lexicographic comparison, or repeated substring membership

## Common Mistakes

- forgetting to normalize substring hashes after subtraction
- using one weak modulus and treating collisions as impossible
- mixing inclusive and exclusive endpoints
- using hashing where KMP or Z gives an exact linear solution
- reusing the same weak base/mod pair across many adversarial tests without care

## Standard Variants

- one-mod rolling hash
- double hash
- unsigned 64-bit overflow hash
- forward + reverse hashes for palindrome queries
- hash + binary search hybrids

## Practice Ladder

- [Hashing ladder](../../../practice/ladders/strings/hashing/README.md)

## Go Deeper

- Reference: [CP-Algorithms - String Hashing](https://cp-algorithms.com/string/string-hashing.html)
- Reference: [USACO Guide - Hashing](https://usaco.guide/gold/hashing)
- Blog/reference: [KACTL string hashing notes](https://github.com/kth-competitive-programming/kactl)
- Paper/notes: [Rabin-Karp and fingerprinting background](https://en.wikipedia.org/wiki/Rabin%E2%80%93Karp_algorithm)

## Related Topics

- [KMP](../kmp/README.md)
- [Z-Function](../z-function/README.md)
- [Suffix Array And LCP](../suffix-array-lcp/README.md)
