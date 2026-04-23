# Strings -> Hashing

Rolling hashes for substring equality, borders, Rabin-Karp style matching, and collision-aware verification.

- Topic slug: `strings/hashing`
- Tutorial page: [Open tutorial](../../../topics/strings/hashing/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/strings/hashing/README.md)
- Repo problems currently tagged here: `1`
- Curated external problems: `7`

## Microtopics

- rolling-hash
- prefix-hash
- substring-equality
- double-hash
- Rabin-Karp
- collision-analysis

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms string hashing](https://cp-algorithms.com/string/string-hashing.html) | `trusted guide` |
| [USACO Guide hashing](https://usaco.guide/gold/hashing) | `trusted guide` |
| [Princeton substring search](https://algs4.cs.princeton.edu/53substring/) | `course` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Finding Periods](https://cses.fi/problemset/task/1733) | `problem` |
| [CSES Finding Borders](https://cses.fi/problemset/task/1732) | `problem` |
| [USACO Guide hashing problems](https://usaco.guide/gold/hashing) | `problem bank` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [String Hashing](https://open.kattis.com/problems/hashing) | `Kattis` | `Easy` | Rolling Hash, Substring Comparison | - | - | LCS; Equality | Direct, judge-style hashing practice with low overhead and clean input. |
| [Good Substrings](https://codeforces.com/problemset/problem/271/D) | `Codeforces` | `Medium` | Distinct Substrings | Enumeration; Deduplication | Rolling Hash; Set Or Map Deduplication | Trie; Substrings; Hash Or Trie | A standard distinct-substring counting problem where hashing trims the search space. |
| [Watto and Mechanism](https://codeforces.com/problemset/problem/514/C) | `Codeforces` | `Medium` | Dictionary Matching | - | - | One-Change; String-Lookup; Collision-Safe | Canonical one-edit string membership problem; hashing is a standard solution. |
| [rolling_hash](https://judge.yosupo.jp/problem/rolling_hash) | `Library Checker` | `Medium` | Rolling Hash | - | - | Substring Comparison | Purpose-built official hashing benchmark; very close to the core technique. |
| [Palindrome Queries](https://cses.fi/problemset/task/2420) | `CSES` | `Hard` | Rolling Hash, Dynamic Queries | Data-Structure-Heavy; Offline/Online Hybrid | Prefix Hashes; Modular Arithmetic; Segment Trees | Palindrome; Range Queries; Substring-Equality; Updates | Classic rolling-hash use case for fast substring equality under updates. |

### Challenge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| ["a" String Problem](https://codeforces.com/problemset/problem/1984/D) | `Codeforces` | `Hard` | - | Query Processing; Invariant Maintenance | Rolling Hash; Suffix Structures; Substring Comparison | Suffix Structures | A modern hard string problem where hashing is one of the intended tools. |
| [String Set Queries](https://codeforces.com/problemset/problem/710/F) | `Codeforces` | `Hard` | - | Online; Dynamic Data Structures | Rolling Hash; Online Processing; Prefix Sums | Online Queries; String Sets | Strong fit for hash-based substring matching in a fully online setting. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `FINDINGBORDERS` | Finding Borders | `primary` | `easy` | rolling hash; prefix-suffix equality; proper borders enumeration | [Note](../../../practice/ladders/strings/hashing/findingborders.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/hashing/findingborders.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
