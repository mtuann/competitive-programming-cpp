# Strings -> Suffix Automaton

Compact automaton of all substrings, with endpos classes, clones, and counting applications.

- Topic slug: `strings/suffix-automaton`
- Tutorial page: [Open tutorial](../../../topics/strings/suffix-automaton/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/strings/suffix-automaton/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `0`
- Curated external problems: `8`

## Microtopics

- endpos-equivalence
- suffix-links
- clone-states
- distinct-substrings
- occurrence-counts
- kth-substring

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms suffix automaton](https://cp-algorithms.com/string/suffix-automaton.html) | `Reference` |
| [USACO Guide string suffix structures](https://usaco.guide/adv/string-suffix) | `Reference` |

## Practice And Follow-Up Sources

| Source | Type |
| --- | --- |
| [CSES Distinct Substrings](https://cses.fi/problemset/task/2105/) | `Practice` |
| [CSES Substring Order I](https://cses.fi/problemset/task/2108) | `Practice` |
| [USACO Guide string suffix structures](https://usaco.guide/adv/string-suffix) | `Practice` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Distinct Substrings](https://cses.fi/problemset/task/2105) | `CSES` | `Medium` | Counting | - | - | Substrings; States; Endpos | Distinct-substring counting is one of SAM’s core uses. |
| [Good Substrings](https://codeforces.com/problemset/problem/271/D) | `Codeforces` | `Medium` | - | Enumeration; Deduplication | Suffix Automaton; Distinct Substring Counting | Distinct Substrings; Trie | Not only hash/trie territory; suffix automaton also fits naturally. |
| [Repeating Substring](https://cses.fi/problemset/task/2106) | `CSES` | `Medium` | Longest-Repeat | - | - | Repeat; Substring; Suffix-Structure | Another canonical SAM application with strong overlap. |
| [suffix_automaton](https://judge.yosupo.jp/problem/suffix_automaton) | `Library Checker` | `Medium` | String-Indexing | - | - | States; Transitions | Direct official SAM construction benchmark. |
| [Substring Order I](https://cses.fi/problemset/task/2108) | `CSES` | `Hard` | Kth-Substring | - | - | Ranking; Distinct-Substrings; Advanced | K-th substring ranking is a strong suffix-structure benchmark. |

### Challenge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [A Trivial String Problem](https://codeforces.com/problemset/problem/2209/E) | `Codeforces` | `Hard` | - | Query Processing; Hybrid Techniques | Suffix Automaton; Hashing | Hashing | Modern hard string problem where suffix structures are a key ingredient. |
| [Cyclical Quest](https://codeforces.com/problemset/problem/235/C) | `Codeforces` | `Hard` | - | String Compression; Counting | Suffix Automaton; String Rotation Intuition | Cyclic Strings; Counting | A standard suffix automaton problem for counting cyclic matches. |
| [Martian Strings](https://codeforces.com/problemset/problem/149/E) | `Codeforces` | `Hard` | - | Multi-Pattern Checking | Suffix Automaton; Substring Occurrence | Substring Queries; Pattern Matching | A classic suffix-structure problem with a strong automaton solution. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `DISTINCTSUBSTRINGS` | Distinct Substrings | `primary` | `medium` | suffix automaton construction; clone states; state contribution counting | [Note](../../../practice/ladders/strings/suffix-automaton/distinctsubstrings.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/suffix-automaton/distinctsubstrings.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
