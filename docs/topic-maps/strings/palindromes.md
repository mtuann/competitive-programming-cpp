# Strings -> Palindromes / Manacher

Odd/even palindrome radii on one static string, with Manacher as the exact linear-time baseline.

- Topic slug: `strings/palindromes`
- Tutorial page: [Open tutorial](../../../topics/strings/palindromes/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/strings/palindromes/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `3`
- Curated external problems: `3`

## Microtopics

- manacher
- odd-centers
- even-centers
- palindrome-radii
- longest-palindromic-substring
- center-expansion

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms Manacher](https://cp-algorithms.com/string/manacher.html) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Longest Palindrome](https://cses.fi/problemset/task/1111) | `Practice` |
| [CSES All Palindromes](https://cses.fi/problemset/task/3138) | `Practice` |
| [CSES Palindrome Queries](https://cses.fi/problemset/task/2420) | `Practice` |
| [Library Checker Enumerate Palindromes](https://judge.yosupo.jp/problem/enumerate_palindromes) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Palindromes hot sheet](../../../notebook/palindromes-hot-sheet.md) | `quick reference` |
| [Longest Palindrome note](../../../practice/ladders/strings/palindromes/longestpalindrome.md) | `flagship note` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Enumerate Palindromes](https://judge.yosupo.jp/problem/enumerate_palindromes) | `Library Checker` | `Medium` | Manacher, Palindrome Radii | Implementation; Verification | Odd/Even Centers | Odd-Even Centers; Radius Arrays | Official benchmark that asks for the raw palindrome-radii style output directly. |
| [Longest Palindrome](https://cses.fi/problemset/task/1111) | `CSES` | `Medium` | Manacher | Implementation; Static Scan | Odd/Even Centers | Longest Palindromic Substring; Odd-Even Centers; Exact Scan | The cleanest first Manacher task: recover one longest palindromic substring from a static string. |

### Challenge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [All Palindromes](https://cses.fi/problemset/task/3138) | `CSES` | `Hard` | Manacher, Palindrome Radii | Implementation; Output Transformation | Odd/Even Centers; Radius-To-Answer Conversion | Per-Position Output; Static String | Pushes past one longest answer into a full-radius style output problem. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `LONGESTPALINDROME` | Longest Palindrome | `primary` | `medium` | manacher; odd/even centers; longest palindromic substring | [Note](../../../practice/ladders/strings/palindromes/longestpalindrome.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/palindromes/longestpalindrome.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
