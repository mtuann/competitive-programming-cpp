# Strings -> Z-Function

Maintain a Z-box to measure longest prefix matches at every position and solve period/border problems efficiently.

- Topic slug: `strings/z-function`
- Tutorial page: [Open tutorial](../../../topics/strings/z-function/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/strings/z-function/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `0`
- Curated external problems: `5`

## Microtopics

- z-function
- z-box
- prefix-occurrences
- pattern-search
- string-periods
- border-array

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms Z-function](https://cp-algorithms.com/string/z-function.html) | `trusted guide` |
| [USACO Guide string searching](https://usaco.guide/adv/string-search) | `trusted guide` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Library Checker Z Algorithm](https://judge.yosupo.jp/problem/zalgorithm) | `problem` |
| [CSES String Functions](https://cses.fi/problemset/task/2107) | `problem` |
| [CSES Finding Periods](https://cses.fi/problemset/task/1733) | `problem` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [String Functions](https://cses.fi/problemset/task/2107) | `CSES` | `Easy` | Prefix-Function | Implementation | Z-Function Definition | String Processing; Z-Array; Pi-Array; Fundamentals | This task directly computes the z-array, so it is the cleanest Z-function drill. |
| [String Matching](https://cses.fi/problemset/task/1753) | `CSES` | `Easy` | Pattern-Matching | Implementation | Z-Function | Linear-Time String Algorithms; Single-Pattern; Occurrences; Linear-Time | Single-pattern matching is a textbook Z-function application. |
| [Finding Periods](https://cses.fi/problemset/task/1733) | `CSES` | `Medium` | Periodicity | Proof; Implementation | Z-Function; Prefix-Suffix Structure | Borders; Periods; Prefix-Structure; String-Analysis | Periods can be extracted naturally from prefix comparisons that Z handles well. |
| [Password](https://codeforces.com/problemset/problem/126/B) | `Codeforces` | `Medium` | Borders | - | - | Prefix-Suffix; Longest-Border; Classic | A textbook border problem where Z is a natural route. |
| [Prefixes and Suffixes](https://codeforces.com/problemset/problem/432/D) | `Codeforces` | `Medium` | Border-Enumeration | - | - | Prefixes; Suffixes; Counts | Canonical Z-function task for collecting all prefix-suffix matches. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `STRINGFUNCTIONS` | String Functions | `primary` | `easy` | z function; prefix function; prefix structure diagnostics | [Note](../../../practice/ladders/strings/z-function/stringfunctions.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/z-function/stringfunctions.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
