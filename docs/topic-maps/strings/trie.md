# Strings -> Trie

Prefix trees for dictionary queries, prefix counting, lexicographic traversal, and automaton building blocks.

- Topic slug: `strings/trie`
- Tutorial page: [Open tutorial](../topics/strings/trie/README.md)
- Ladder page: [Open ladder](../practice/ladders/strings/trie/README.md)
- Repo problems currently tagged here: `0`
- Curated external problems: `5`

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
| [Princeton Tries](https://algs4.cs.princeton.edu/52trie/) | `course` |
| [USACO Guide string searching](https://usaco.guide/adv/string-search) | `trusted guide` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Word Combinations](https://cses.fi/problemset/task/1731) | `problem` |
| [CSES Finding Patterns](https://cses.fi/problemset/task/2102/) | `problem` |
| [USACO Guide string searching](https://usaco.guide/adv/string-search) | `problem bank` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Vasiliy's Multiset](https://codeforces.com/problemset/problem/706/D) | `Codeforces` | `Medium` | XOR | - | - | Binary-Trie; Bitwise | Binary trie plus updates and maximum-xor queries is canonical. |
| [Watto and Mechanism](https://codeforces.com/problemset/problem/514/C) | `Codeforces` | `Medium` | Hashing | Implementation; Branching Search | Trie Basics; Edit-Distance-1 Checking | Approximate Matching; One-Edit; Dictionary; Lookup | A very common trie exercise with one-character-mismatch queries. |
| [Word Combinations](https://cses.fi/problemset/task/1731) | `CSES` | `Medium` | DP | Dynamic Programming; Data-Structure-Heavy | Trie Basics; DP On Prefixes | Dictionary Matching; Dictionary; Prefixes; Counting | A classic trie-plus-DP word segmentation problem. |
| [trie](https://judge.yosupo.jp/problem/trie) | `Library Checker` | `Medium` | Data-Structure | - | - | Insert; Lookup | Pure trie implementation benchmark with the cleanest possible scope. |

### Challenge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [A Lot of Games](https://codeforces.com/problemset/problem/455/B) | `Codeforces` | `Hard` | Game-Theory | Game-State Analysis | Trie; Winning/Losing States | Games; Winning-States; Game-DP; Prefix-Tree | Trie structure is the whole game board here. |

## Repo Problems

_No repo note has been tagged to this topic yet._

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
