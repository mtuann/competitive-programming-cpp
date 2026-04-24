# Combinatorics -> Lexicographic Enumeration

Generate, count, or skip combinatorial objects in lexicographic order using ranks, next-state transitions, and pruning.

- Topic slug: `combinatorics/lexicographic-enumeration`
- Tutorial page: [Open tutorial](../../../topics/combinatorics/lexicographic-enumeration/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/combinatorics/lexicographic-enumeration/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `0`
- Curated external problems: `7`

## Microtopics

- next_permutation
- ranking
- unranking
- lexicographic-skip
- windowed-enumeration
- combinatorial-generation

## Learning Sources

| Source | Type |
| --- | --- |
| [cppreference next_permutation](https://en.cppreference.com/w/cpp/algorithm/next_permutation) | `Primary` |
| [cp-algorithms generating combinations](https://cp-algorithms.com/combinatorics/generating_combinations.html) | `Reference` |
| [OI Wiki enumerate](https://en.oi-wiki.org/basic/enumerate/) | `Reference` |

## Practice And Follow-Up Sources

| Source | Type |
| --- | --- |
| [CSES Creating Strings](https://cses.fi/problemset/task/1622/) | `Practice` |
| [CSES Problem Set](https://cses.fi/problemset) | `Practice` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Count Order](https://atcoder.jp/contests/abc150/tasks/abc150_c) | `AtCoder` | `Easy` | Permutation Ranking | Math; Permutation | Factorials; Permutation Order | Permutations; Lexicographic Rank | The textbook k-th-permutation problem, ideal for rank/unrank practice. |
| [Creating Strings](https://cses.fi/problemset/task/1622) | `CSES` | `Easy` | Multiset Permutations, Lexicographic Order | Backtracking; Enumeration | Sorting; Multisets | Duplicate Permutations; Generation; Sorting | A classic generation task that teaches lexicographic enumeration of unique strings. |
| [C - One More aab aba baa](https://atcoder.jp/contests/abc215/tasks/abc215_c) | `AtCoder` | `Medium` | Multiset Permutations | - | - | K-Th Permutation; Duplicate Letters; Sorting | Classic k-th lexicographic permutation of a multiset string. |
| [Permutation Order](https://cses.fi/problemset/task/3397) | `CSES` | `Medium` | Permutation Ranking, Lexicographic Order | Implementation; Math | Factorials | K-Th Permutation; Factoradic; Inverse Permutation Order | A direct bidirectional rank/unrank permutation problem with multiple query types. |

### Practice

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Creating Strings II](https://cses.fi/problemset/task/1715) | `CSES` | `Medium` | Multiset Permutations, Ranking And Counting, Lexicographic Combinatorics | Math; Precomputation | Multinomial Counting; Lexicographic Order | Counting Strings; Factorials; Mod Arithmetic | Useful if you want both counting and ordering over repeated characters. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Lexicographically Smallest Permutation](https://atcoder.jp/contests/abc371/tasks/abc371_g) | `AtCoder` | `Hard` | Permutation-Cycles | Construction; Greedy | Permutations; Cycle Decomposition; Lexicographic Order | Lexicographic Order; Permutations; Cycle Decomposition | A strong advanced permutation problem where lexicographic minimization is the central goal. |
| [Reverse and Count](https://atcoder.jp/contests/arc160/tasks/arc160_a) | `AtCoder` | `Hard` | Permutation Ranking | Construction; Combinatorics | Lexicographic Order | Lexicographic Order | A more specialized lexicographic ranking problem with a nice combinatorial twist. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `VOITSORT` | Cây hoán vị | `primary` | `hard` | lexicographic enumeration; stack-sortability; cartesian tree view | [Note](../../../practice/ladders/combinatorics/lexicographic-enumeration/voitsort.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/combinatorics/lexicographic-enumeration/voitsort.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
