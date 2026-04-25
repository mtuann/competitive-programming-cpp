# Strings -> KMP

Prefix-function reasoning for exact pattern matching, borders, periods, and automaton interpretations.

- Topic slug: `strings/kmp`
- Tutorial page: [Open tutorial](../../../topics/strings/kmp/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/strings/kmp/README.md)
- Repo problems currently tagged here: `3`
- Repo companion pages: `0`
- Curated external problems: `5`

## Microtopics

- prefix-function
- failure-links
- borders
- periodicity
- online-matching
- automaton-view

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms prefix function](https://cp-algorithms.com/string/prefix-function.html) | `Reference` |
| [Princeton substring search](https://algs4.cs.princeton.edu/53substring/) | `Course` |
| [USACO Guide string searching](https://usaco.guide/adv/string-search) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES String Matching](https://cses.fi/problemset/task/1753) | `Practice` |
| [CSES String Functions](https://cses.fi/problemset/task/2107) | `Practice` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Finding Borders](https://cses.fi/problemset/task/1732) | `CSES` | `Easy` | Borders | Proof; Implementation | Prefix Function | Prefix-Suffix; Periods; Prefix-Function | Borders are exactly the structural output KMP-style preprocessing exposes. |
| [String Functions](https://cses.fi/problemset/task/2107) | `CSES` | `Easy` | Z-Function | Implementation | Prefix Function; Basic String Indexing | Prefix-Function; Z-Array; Pi-Array | It explicitly asks for the KMP prefix-function output. |
| [String Matching](https://cses.fi/problemset/task/1753) | `CSES` | `Easy` | Pattern-Matching | Implementation | Prefix Function | Prefix-Function; Single-Pattern; Occurrences | The most direct single-pattern matching exercise for prefix-function/KMP. |
| [Finding Periods](https://cses.fi/problemset/task/1733) | `CSES` | `Medium` | Periodicity | Implementation; Pattern Analysis | Prefix Function; Border Chains | Prefix-Function; Periods; String-Structure | A canonical periodicity problem built on prefix-function reasoning. |
| [Required Substring](https://cses.fi/problemset/task/1112) | `CSES` | `Medium` | Automaton-DP | - | - | DP; Forbidden-States; Substring-Automaton | Uses the KMP automaton as the backbone of a counting DP. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `FINDINGPERIODS` | Finding Periods | `secondary` | `easy` | period detection; z function prefix matches; suffix prefix coverage | [Note](../../../practice/ladders/strings/z-function/findingperiods.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/z-function/findingperiods.cpp) |
| `STRINGFUNCTIONS` | String Functions | `secondary` | `easy` | z function; prefix function; prefix structure diagnostics | [Note](../../../practice/ladders/strings/z-function/stringfunctions.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/z-function/stringfunctions.cpp) |
| `STRINGMATCHING` | String Matching | `primary` | `easy` | prefix function; border fallback; overlapping occurrence counting | [Note](../../../practice/ladders/strings/kmp/stringmatching.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/kmp/stringmatching.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
