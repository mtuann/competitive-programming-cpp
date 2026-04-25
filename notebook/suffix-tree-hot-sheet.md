# Suffix Tree Hot Sheet

Use this page when one static lowercase text should behave like a compressed substring index.

## Do Not Use When

- one exact pattern match is all you need
- suffix order or adjacent LCP is the real object
- many patterns are known first and a pattern trie is the cleaner view
- online string extension is central

## Choose By Signal

- one fixed text, many substring existence / earliest-occurrence queries -> [`suffix-tree.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/suffix-tree.cpp)
- pattern may finish in the middle of a compressed edge -> suffix tree still works; subtree metadata lives on the edge child
- lexicographic suffix tasks -> reopen [Suffix Array / LCP hot sheet](suffix-array-lcp-hot-sheet.md)
- online all-substring aggregation -> reopen [Suffix Automaton](../topics/strings/suffix-automaton/README.md)

## Core Invariants

- build on `text + terminator`
- every leaf corresponds to one suffix start
- one edge is an interval `[l, r)` inside the built string
- if a pattern walk succeeds, every leaf in that final matched subtree contains the pattern as a prefix
- earliest occurrence can be cached as subtree minimum suffix start

## Main Traps

- forgetting the unique terminator
- matching node-by-node instead of char-by-char across an edge interval
- assuming the walk must stop exactly at an explicit node
- using suffix tree where suffix array is simpler and more stable to reason about

## Exact Starter In This Repo

- compressed substring index with earliest occurrence -> [`suffix-tree.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/suffix-tree.cpp)
- flagship repo note -> [Pattern Positions](../practice/ladders/strings/suffix-tree/patternpositions.md)
- neighboring chooser -> [String cheatsheet](string-cheatsheet.md)

## Reopen Paths

- tutorial route -> [Suffix Tree](../topics/strings/suffix-tree/README.md)
- static suffix-order compare point -> [Suffix Array / LCP hot sheet](suffix-array-lcp-hot-sheet.md)
- online substring-state compare point -> [Suffix Automaton](../topics/strings/suffix-automaton/README.md)
