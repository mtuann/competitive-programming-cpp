# Strings -> Trie

Prefix trees for dictionary queries, prefix counting, lexicographic traversal, and automaton building blocks.

- Topic slug: `strings/trie`
- Tutorial page: [Open tutorial](../../../topics/strings/trie/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/strings/trie/README.md)
- Repo problems currently tagged here: `2`
- Repo companion pages: `0`
- Curated external problems: `4`

## Microtopics

- prefix-tree
- dictionary-queries
- terminal-nodes
- alphabet-optimization
- lexicographic-traversal
- compressed-trie

## Learning Sources

| Source | Type |
| --- | --- |
| [Princeton Tries](https://algs4.cs.princeton.edu/52trie/) | `Course` |
| [USACO Guide string searching](https://usaco.guide/adv/string-search) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Word Combinations](https://cses.fi/problemset/task/1731) | `Practice` |
| [CSES Finding Patterns](https://cses.fi/problemset/task/2102/) | `Practice` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Watto and Mechanism](https://codeforces.com/problemset/problem/514/C) | `Codeforces` | `Medium` | Hashing | Implementation; Branching Search | Trie Basics; Edit-Distance-1 Checking | Approximate Matching; One-Edit; Dictionary; Lookup | A very common trie exercise with one-character-mismatch queries. |
| [Word Combinations](https://cses.fi/problemset/task/1731) | `CSES` | `Medium` | DP | Dynamic Programming; Data-Structure-Heavy | Trie Basics; DP On Prefixes | Dictionary Matching; Dictionary; Prefixes; Counting | A classic trie-plus-DP word segmentation problem. |
| [trie](https://judge.yosupo.jp/problem/trie) | `Library Checker` | `Medium` | Data-Structure | - | - | Insert; Lookup | Pure trie implementation benchmark with the cleanest possible scope. |

### Challenge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [A Lot of Games](https://codeforces.com/problemset/problem/455/B) | `Codeforces` | `Hard` | Game-Theory | Game-State Analysis | Trie; Winning/Losing States | Games; Winning-States; Game-DP; Prefix-Tree | Trie structure is the whole game board here. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `FINDINGPATTERNS` | Finding Patterns | `secondary` | `medium` | aho-corasick automaton; failure links; multi-pattern presence queries | [Note](../../../practice/ladders/strings/aho-corasick/findingpatterns.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/aho-corasick/findingpatterns.cpp) |
| `WORDCOMBINATIONS` | Word Combinations | `primary` | `medium` | trie plus dp; dictionary segmentation; suffix counting | [Note](../../../practice/ladders/strings/trie/wordcombinations.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/trie/wordcombinations.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
