# Palindromes Ladder

Use this lane when palindrome tasks stop feeling like ad-hoc center expansion and start asking for one reusable exact primitive.

## Who This Is For

Use this ladder if:

- KMP and Z already feel comfortable
- "expand around every center" is your first instinct, but you know it is too slow
- you want one exact static-string palindrome baseline before reopening hashing or heavier suffix views

This lane is still intentionally thin:

- one exact starter
- one direct in-repo flagship rep
- strong compare points back into `Hashing` and `Z-Function`

## Warm-Up

- odd center vs even split center
- write the interval formulas back from one radius
- explain why brute force over all centers is `O(n^2)`

Target skill:

- see palindrome tasks as center-radius tasks, not as repeated ad-hoc expansions

## Core

- odd and even Manacher passes
- current rightmost palindrome interval
- mirror bootstrap plus boundary extension
- exact flagship rep: [Longest Palindrome](longestpalindrome.md)

Target skill:

- recover the longest palindromic substring directly from `d1` and `d2`

## Stretch

- output one palindrome summary per position -> [CSES All Palindromes](https://cses.fi/problemset/task/3138)
- compare against query-style palindrome checks -> [CSES Palindrome Queries](https://cses.fi/problemset/task/2420)
- only move there after longest-palindrome extraction feels routine

Target skill:

- distinguish static-radius preprocessing from substring-query or update-heavy palindrome routes

## Retrieval Layer

- exact quick sheet -> [Palindromes hot sheet](../../../../notebook/palindromes-hot-sheet.md)
- exact starter -> [manacher.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/manacher.cpp)
- compare query-style route -> [String Hashing hot sheet](../../../../notebook/string-hashing-hot-sheet.md)
- compare prefix-style route -> [Z-Function](../../../../topics/strings/z-function/README.md)

## Exit Criteria

You are ready to move on when:

- you can state clearly what `d1[i]` and `d2[i]` mean
- you can reconstruct substring bounds from one radius without guesswork
- you know when `Manacher` is the right exact static tool and when hashing is the better neighbor

## External Practice

- [CSES - Longest Palindrome](https://cses.fi/problemset/task/1111)
- [CSES - All Palindromes](https://cses.fi/problemset/task/3138)
- [Library Checker - Enumerate Palindromes](https://judge.yosupo.jp/problem/enumerate_palindromes)

## Tutorial Link

- [Palindromes / Manacher](../../../../topics/strings/palindromes/README.md)
