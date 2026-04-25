# Eertree Hot Sheet

Use this page when one string is built left to right and the task really wants the dictionary of distinct palindromic substrings.

## Do Not Use When

- the string is static and the job is only longest palindrome or raw odd/even radii
- the task is many arbitrary substring palindrome checks instead of a palindrome dictionary
- the real object is all substrings, not all palindromic substrings

## Choose By Signal

- one growing string, distinct palindromes by prefix, or longest palindromic suffix -> [`eertree.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/eertree.cpp)
- one static string, longest palindrome, or all center radii -> compare [Palindromes hot sheet](palindromes-hot-sheet.md)
- all substrings / endpos-style aggregation -> compare [Suffix Automaton](../topics/strings/suffix-automaton/README.md)
- many substring palindrome checks -> compare [String Hashing hot sheet](string-hashing-hot-sheet.md)

## Core Invariants

- there are two roots: odd root `len = -1` and even root `len = 0`
- every ordinary node is one distinct nonempty palindrome
- `link[v]` is the longest proper palindromic suffix of node `v`
- `last` is the longest palindromic suffix of the current processed prefix
- one append creates at most one new ordinary node

## Main Traps

- starting the suffix-link walk from the wrong node
- forgetting that new palindromes must end at the newly appended position
- creating a new node even though the transition already exists
- reaching for Eertree when `Manacher` already solves the static task more simply

## Exact Starters In This Repo

- exact append-only palindrome-dictionary starter -> [`eertree.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/eertree.cpp)
- flagship repo note -> [Distinct Palindromic Substrings](../practice/ladders/strings/eertree/distinctpalindromicsubstrings.md)
- compare static route -> [Palindromes hot sheet](palindromes-hot-sheet.md)
- compare all-substrings route -> [Suffix Automaton](../topics/strings/suffix-automaton/README.md)

## Reopen Paths

- full theory and worked examples -> [Eertree / Palindromic Tree](../topics/strings/eertree/README.md)
- neighboring string-family chooser -> [String cheatsheet](string-cheatsheet.md)
- template map -> [Template Library](../template-library.md)
