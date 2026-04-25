# Strings -> Eertree / Palindromic Tree

Append-only palindrome dictionary with one node per distinct palindrome and suffix links over palindromic suffixes.

- Topic slug: `strings/eertree`
- Tutorial page: [Open tutorial](../../../topics/strings/eertree/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/strings/eertree/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `4`
- Curated external problems: `3`

## Microtopics

- eertree
- palindromic-tree
- distinct-palindromes
- palindromic-suffix-chain
- longest-palindromic-suffix
- append-only-palindrome-structure

## Learning Sources

| Source | Type |
| --- | --- |
| [Rubinchik and Shur - EERTREE](https://arxiv.org/abs/1506.04862) | `Primary` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Timus 1960 - Palindromes and Super Abilities](https://acm.timus.ru/problem.aspx?num=1960&space=1) | `Practice` |
| [Library Checker - Eertree](https://judge.yosupo.jp/problem/eertree) | `Practice` |
| [Codeforces 835D - Palindromic characteristics](https://codeforces.com/problemset/problem/835/D) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Eertree hot sheet](../../../notebook/eertree-hot-sheet.md) | `quick reference` |
| [Distinct Palindromic Substrings note](../../../practice/ladders/strings/eertree/distinctpalindromicsubstrings.md) | `anchor note` |
| [Palindromes / Manacher](../../../topics/strings/palindromes/README.md) | `compare point` |
| [Suffix Automaton](../../../topics/strings/suffix-automaton/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Palindromes and Super Abilities](https://acm.timus.ru/problem.aspx?num=1960&space=1) | `Timus` | `Medium` | Distinct Palindromes | Online Append; Data Structure; Per-Prefix Counting | Palindrome Basics; Suffix Links; Append-Only Updates | Palindromic Tree; Append-Only String; Per-Prefix Output | The cleanest first exact Eertree problem because each prefix answer is just the number of ordinary nodes after one append update. |

### Practice

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [eertree](https://judge.yosupo.jp/problem/eertree) | `Library Checker` | `Medium` | - | Verification; Construction | Eertree Basics; Suffix-Link Walk; Distinct Palindrome Nodes | Palindromic Tree; Construction | Official verifier for the exact family; useful once the basic append-only invariants feel stable. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Palindromic characteristics](https://codeforces.com/problemset/problem/835/D) | `Codeforces` | `Hard` | DP | DP; Palindrome Structure | Eertree Basics; Palindrome DP; Distinct Palindrome Worldview | Palindrome; Distinct Structure | A strong stretch problem once the basic tree is trusted and you are ready to layer extra palindrome DP on top. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `DISTINCTPALINDROMICSUBSTRINGS` | Distinct Palindromic Substrings | `primary` | `medium` | - | [Note](../../../practice/ladders/strings/eertree/distinctpalindromicsubstrings.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/eertree/distinctpalindromicsubstrings.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
