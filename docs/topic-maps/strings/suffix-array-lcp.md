# Strings -> Suffix Array And LCP

Sorted suffix views and LCP arrays for substring order, uniqueness, and offline pattern search.

- Topic slug: `strings/suffix-array-lcp`
- Tutorial page: [Open tutorial](../../../topics/strings/suffix-array-lcp/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/strings/suffix-array-lcp/README.md)
- Repo problems currently tagged here: `1`
- Curated external problems: `9`

## Microtopics

- doubling
- radix-sort
- kasai
- lcp-array
- substring-order
- pattern-search

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms suffix array](https://cp-algorithms.com/string/suffix-array.html) | `trusted guide` |
| [Princeton suffix arrays](https://algs4.cs.princeton.edu/63suffix/) | `course` |
| [USACO Guide suffix array](https://usaco.guide/adv/suffix-array?lang=cpp) | `trusted guide` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Library Checker Suffix Array](https://judge.yosupo.jp/problem/suffixarray) | `problem` |
| [Library Checker LCP Array](https://judge.yosupo.jp/problem/lcp_array) | `problem` |
| [CSES Distinct Substrings](https://cses.fi/problemset/task/2105/) | `problem` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Distinct Substrings](https://cses.fi/problemset/task/2105) | `CSES` | `Medium` | Suffix-Array | Counting; Suffix Processing | LCP Array | Distinct Substrings; Counting; Suffix-Structure | One of the standard suffix-array + LCP counting problems. |
| [Repeating Substring](https://cses.fi/problemset/task/2106) | `CSES` | `Medium` | Suffix-Array | Maximization; Substring Search | LCP Array | Repetition; Longest-Repeat; Binary-Search; Suffix-Structure | Longest repeated substring is a canonical LCP application. |
| [lcp_array](https://judge.yosupo.jp/problem/lcp_array) | `Library Checker` | `Medium` | Suffix-Array | - | - | Kasai; Adjacent-Suffixes | Natural companion to suffix array construction. |
| [longest_common_substring](https://judge.yosupo.jp/problem/longest_common_substring) | `Library Checker` | `Medium` | Suffix-Array | - | - | Two-Strings; Common-Substring | A very standard SA+LCP application problem. |
| [suffix_array](https://judge.yosupo.jp/problem/suffix_array) | `Library Checker` | `Medium` | Suffix-Array, String-Indexing | - | - | Lexicographic-Order; Core | Direct suffix-array construction benchmark from the official judge. |

### Challenge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Inverse Suffix Array](https://cses.fi/problemset/task/3225) | `CSES` | `Hard` | - | Construction; Consistency Checking | Suffix Array Semantics | Suffix Array; Construction; Inverse Problems | A reverse-engineering task that deepens suffix-array understanding. |
| [String Transform](https://cses.fi/problemset/task/1113) | `CSES` | `Hard` | - | Construction; Inverse Transform | Suffix Array; Sorted Rotations | Suffix Array; Burrows-Wheeler Transform; Reconstruction | This is a direct BWT-style inverse transform problem. |
| [Substring Order I](https://cses.fi/problemset/task/2108) | `CSES` | `Hard` | Suffix-Array, Lexicographic-Order | K-Th Selection; Suffix Processing | LCP Array | Order Statistics; Kth-Substring; Ranking | Selecting the k-th substring is a strong suffix-array/LCP exercise. |
| [Substring Order II](https://cses.fi/problemset/task/2109) | `CSES` | `Hard` | - | K-Th Selection; Suffix Processing | Suffix Array; LCP Array | Suffix Array; Order Statistics | Same core machinery as Substring Order I, but on all substrings. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `REPEATINGSUBSTRING` | Repeating Substring | `primary` | `medium` | suffix array doubling; kasai lcp; maximum adjacent lcp | [Note](../../../practice/ladders/strings/suffix-array-lcp/repeatingsubstring.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/suffix-array-lcp/repeatingsubstring.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
