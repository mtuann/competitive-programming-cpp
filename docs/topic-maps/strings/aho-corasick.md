# Strings -> Aho-Corasick

Dictionary automaton for multi-pattern matching with failure and output links.

- Topic slug: `strings/aho-corasick`
- Tutorial page: [Open tutorial](../../../topics/strings/aho-corasick/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/strings/aho-corasick/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `0`
- Curated external problems: `7`

## Microtopics

- multi-pattern-matching
- failure-links
- output-links
- dictionary-automaton
- occurrence-counting
- stream-processing

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms Aho-Corasick](https://cp-algorithms.com/string/aho_corasick.html) | `Reference` |
| [USACO Guide string searching](https://usaco.guide/adv/string-search) | `Reference` |

## Practice And Follow-Up Sources

| Source | Type |
| --- | --- |
| [CSES Finding Patterns](https://cses.fi/problemset/task/2102/) | `Practice` |
| [CSES Counting Patterns](https://cses.fi/problemset/task/2103/) | `Practice` |
| [CSES Pattern Positions](https://cses.fi/problemset/task/2104) | `Practice` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Finding Patterns](https://cses.fi/problemset/task/2102) | `CSES` | `Medium` | - | Offline Matching | Trie; Failure Links | Multi-Pattern Matching; Automata | Direct multi-pattern presence queries are the textbook Aho-Corasick use case. |
| [String Multimatching](https://open.kattis.com/problems/stringmultimatching) | `Kattis` | `Medium` | Multi-Pattern-Matching | - | - | Text Scanning; Output-All | The standard “find all patterns in one text” AC problem. |
| [Word Combinations](https://cses.fi/problemset/task/1731) | `CSES` | `Medium` | DP | - | - | Dictionary; Segmentation; Prefix-Automaton | Can be accelerated by automaton-style prefix matching in the dictionary. |
| [aho_corasick](https://judge.yosupo.jp/problem/aho_corasick) | `Library Checker` | `Medium` | Multi-Pattern-Matching | - | - | Failure Links; Dictionary | Direct official benchmark for building and querying the automaton. |
| [Counting Patterns](https://cses.fi/problemset/task/2103) | `CSES` | `Hard` | - | Aggregation; Offline Matching | Trie; Failure Links; Output Links | Multi-Pattern Matching; Counting | Counts all occurrences, which is where Aho-Corasick becomes especially useful. |
| [Pattern Positions](https://cses.fi/problemset/task/2104) | `CSES` | `Hard` | Trie | Offline Matching | Failure Links | Multi-Pattern Matching; First Occurrence; Many-Patterns; Text-Search | A clean extension of Aho-Corasick that asks for earliest matches per pattern. |

### Challenge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Genetic engineering](https://codeforces.com/problemset/problem/86/C) | `Codeforces` | `Hard` | - | DP On Automaton; Pattern Exclusion | Trie; Failure Links; Automaton DP | DP; Automata | A classic AC-plus-DP problem for constrained string construction. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `FINDINGPATTERNS` | Finding Patterns | `primary` | `medium` | aho-corasick automaton; failure links; multi-pattern presence queries | [Note](../../../practice/ladders/strings/aho-corasick/findingpatterns.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/aho-corasick/findingpatterns.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
