# Data Structures -> Binary Trie / XOR Queries

Fixed-width bit-prefix trie for live insert / erase / maximum-xor queries against one multiset of non-negative integers.

- Topic slug: `data-structures/binary-trie-xor`
- Tutorial page: [Open tutorial](../../../topics/data-structures/binary-trie-xor/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/data-structures/binary-trie-xor/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `3`

## Microtopics

- binary-trie
- xor-queries
- fixed-bit-width
- subtree-counts
- max-xor-greedy
- prefix-xor-insertions

## Learning Sources

| Source | Type |
| --- | --- |
| [OI Wiki Trie](https://en.oi-wiki.org/string/trie/) | `Reference` |
| [USACO Guide Trie](https://usaco.guide/gold/trie) | `Reference` |
| [Competitive Programmer's Handbook](https://cses.fi/book/book.pdf) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Codeforces problemset](https://codeforces.com/problemset) | `Practice` |
| [CSES Maximum Xor Subarray](https://cses.fi/problemset/task/1655) | `Practice` |
| [SPOJ SUBXOR](https://www.spoj.com/problems/SUBXOR/) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Binary Trie hot sheet](../../../notebook/binary-trie-hot-sheet.md) | `quick reference` |
| [Binary Trie starter route](../../../template-library.md) | `starter route` |
| [Vasiliy's Multiset note](../../../practice/ladders/data-structures/binary-trie-xor/vasiliysmultiset.md) | `anchor note` |
| [Trie tutorial](../../../topics/strings/trie/README.md) | `compare point` |
| [Prefix Sums tutorial](../../../topics/foundations/patterns/prefix-sums/README.md) | `adjacent tutorial` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Vasiliy's Multiset](https://codeforces.com/problemset/problem/706/D) | `Codeforces` | `Medium` | Binary Trie, XOR Queries | Data-Structure-Heavy; Bitwise | Bitwise Prefix Walk; Subtree Counts; Dynamic Multiset | Dynamic-Multiset; Maximum-XOR | The cleanest first dynamic benchmark where insert, erase-one, and maximum-xor queries are the whole problem. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [SUBXOR](https://www.spoj.com/problems/SUBXOR/) | `SPOJ` | `Hard` | Binary Trie, Counting Variant, Classic | Bitwise; Classic | Prefix XOR; Bitwise Counting | Prefix-XOR; Counting | A classic stretch problem showing that the same family extends beyond maximum-xor queries into richer counting variants. |

### Bridge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Maximum Xor Subarray](https://cses.fi/problemset/task/1655) | `CSES` | `Hard` | Bitwise Operations, Prefix XOR, Binary Trie | Bitwise; Array Transformation | Maximum XOR Query | Maximum-XOR | The canonical bridge from one dynamic xor set to prefix-xor scans over an array. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `VASILIYSMULTISET` | Vasiliy's Multiset | `primary` | `medium` | - | [Note](../../../practice/ladders/data-structures/binary-trie-xor/vasiliysmultiset.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/binary-trie-xor/vasiliysmultiset.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
