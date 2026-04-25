# Palindromes Hot Sheet

Use this page when one static string is the whole world and the task is really about palindrome centers or longest palindromic substring.

## Do Not Use When

- the string changes online
- the task is many arbitrary substring palindrome queries, not one full static scan
- exact one-pattern matching or suffix order is the real bottleneck

## Choose By Signal

- one static string, longest palindromic substring, or all center radii -> [`manacher.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/manacher.cpp)
- many substring palindrome checks or updates -> compare [String Hashing hot sheet](string-hashing-hot-sheet.md)
- prefix/border reasoning is the real structure -> compare [Z-Function](../topics/strings/z-function/README.md)
- the modeling still feels fuzzy -> reopen [Palindromes / Manacher](../topics/strings/palindromes/README.md)

## Core Invariants

- `d1[i]` is the odd radius count at center `i`, so odd length is `2 * d1[i] - 1`
- `d2[i]` is the even radius count at split `i`, so even length is `2 * d2[i]`
- each pass keeps one current rightmost palindrome interval and reuses mirrored information inside it
- new expansion work only happens when the right boundary moves farther right

## Main Traps

- confusing center index with split index for even palindromes
- treating `d1[i]` as a half-length without the `-1` correction
- extracting substring bounds with the wrong left endpoint
- reaching for hashing when one exact static scan already solves the task

## Exact Starters In This Repo

- exact static palindrome-radii starter -> [`manacher.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/manacher.cpp)
- flagship repo note -> [Longest Palindrome](../practice/ladders/strings/palindromes/longestpalindrome.md)
- compare query-style route -> [String Hashing hot sheet](string-hashing-hot-sheet.md)

## Reopen Paths

- odd/even radii, mirror reuse, and bound formulas -> [Palindromes / Manacher](../topics/strings/palindromes/README.md)
- neighboring string-family chooser -> [String cheatsheet](string-cheatsheet.md)
- template map -> [Template Library](../template-library.md)
