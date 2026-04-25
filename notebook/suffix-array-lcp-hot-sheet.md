# Suffix Array / LCP Hot Sheet

Use this page when the string is static and the missing step is recalling the exact suffix-order plus LCP route.

## Do Not Use When

- hashing, KMP, Z, or trie logic already solve the task more directly
- the task needs online substring updates
- the `O(n log^2 n)` starter is too slow for the limit and you have not accounted for that cost

## Choose By Signal

- exact suffix order on one static string -> [`suffix-array.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/suffix-array.cpp)
- longest repeated substring or distinct-substring counting -> suffix array plus LCP
- lexicographic suffix comparisons or suffix-rank reasoning -> suffix array
- only substring equality checks or binary-search LCP probes -> consider [String Hashing hot sheet](string-hashing-hot-sheet.md) first

## Core Invariants

- `sa[i]` is the start index of the `i`-th suffix in lexicographic order
- `rank[pos]` is the inverse position of one suffix in that order
- `lcp[i]` stores the common prefix length of suffixes at `sa[i]` and `sa[i + 1]`
- the repo starter exposes `build_suffix_array(s)` and `build_lcp(s, sa)` with an `O(n log^2 n)` doubling implementation

## Main Traps

- forgetting that the starter is exact but not the fastest asymptotic suffix-array build
- mixing suffix order questions with tasks that only need fingerprints or borders
- misreading `lcp` as aligned with string indices instead of adjacent suffix-array positions
- reaching for suffix array when suffix automaton or hashing gives a lighter route

## Exact Starters In This Repo

- static suffix order plus LCP -> [`suffix-array.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/suffix-array.cpp)
- flagship repo note -> [Repeating Substring](../practice/ladders/strings/suffix-array-lcp/repeatingsubstring.md)
- compare against lighter substring primitives -> [String cheatsheet](string-cheatsheet.md)

## Reopen Paths

- doubling invariant, Kasai, and chooser boundaries -> [Suffix Array And LCP](../topics/strings/suffix-array-lcp/README.md)
- neighboring string tools -> [String cheatsheet](string-cheatsheet.md)
- template map -> [Template Library](../template-library.md)
