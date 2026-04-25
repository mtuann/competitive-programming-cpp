# Eertree / Palindromic Tree Ladder

Use this lane when palindrome problems stop being "find the longest one" and start asking for the distinct-palindrome structure itself.

## Who This Is For

Use this ladder if:

- [Palindromes / Manacher](../../../../topics/strings/palindromes/README.md) already feels comfortable
- you can explain odd/even centers, but the statement now wants **distinct** palindromes or per-prefix updates
- you want one exact append-only palindrome structure before reopening suffix-style alternatives

This lane is intentionally focused:

- one exact starter
- one direct in-repo flagship rep
- strong compare points back into `Manacher`, `Hashing`, and `Suffix Automaton`

## Warm-Up

- explain why one append creates at most one new distinct palindrome
- explain why any new palindrome must end at the new last position
- state what the odd and even roots are fixing

Target skill:

- see append-only palindrome tasks as suffix-link updates, not repeated center expansion

## Core

- two-root setup
- `last` as current longest palindromic suffix
- suffix-link fallback until extension becomes possible
- exact flagship rep: [Distinct Palindromic Substrings](distinctpalindromicsubstrings.md)

Target skill:

- maintain one node per distinct palindrome and recover prefix answers from `node_count - 2`

## Stretch

- official structure benchmark -> [Library Checker - Eertree](https://judge.yosupo.jp/problem/eertree)
- static distinct-palindrome analytics with heavier DP -> [Codeforces 835D - Palindromic characteristics](https://codeforces.com/problemset/problem/835/D)
- only go there after prefix distinct-count maintenance feels routine

Target skill:

- distinguish plain distinct-palindrome maintenance from richer DP or query layers built on top of the tree

## Retrieval Layer

- exact quick sheet -> [Eertree hot sheet](../../../../notebook/eertree-hot-sheet.md)
- exact starter -> [eertree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/eertree.cpp)
- compare static route -> [Palindromes hot sheet](../../../../notebook/palindromes-hot-sheet.md)
- compare all-substrings route -> [Suffix Automaton](../../../../topics/strings/suffix-automaton/README.md)

## Exit Criteria

You are ready to move on when:

- you can explain the purpose of the two roots without guessing
- you know why `last` is the right starting node for each append
- you can state when an append creates a new node and when it only follows an existing transition
- you know when `Eertree` is the right exact tool and when `Manacher` is still the simpler answer

## External Practice

- [Timus 1960 - Palindromes and Super Abilities](https://acm.timus.ru/problem.aspx?num=1960&space=1)
- [Library Checker - Eertree](https://judge.yosupo.jp/problem/eertree)
- [Codeforces 835D - Palindromic characteristics](https://codeforces.com/problemset/problem/835/D)

## Tutorial Link

- [Eertree / Palindromic Tree](../../../../topics/strings/eertree/README.md)
