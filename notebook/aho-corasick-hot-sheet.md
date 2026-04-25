# Aho-Corasick Hot Sheet

Use this page when many exact patterns must be matched against one text and you already trust the trie-plus-failure-link idea.

## Do Not Use When

- the task is one exact pattern against one text, so KMP or Z is lighter
- the alphabet or transition model does not match the repo starter and you have not adapted it
- substring enumeration or suffix-order structure is the real bottleneck

## Choose By Signal

- many lowercase patterns in one text -> [`aho-corasick.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/aho-corasick.cpp)
- yes/no existence or count of matched patterns while scanning one text -> Aho-Corasick
- automaton DP that avoids forbidden patterns -> Aho-Corasick state graph
- need every match position or richer per-pattern bookkeeping -> reopen the topic before copying the starter

## Core Invariants

- every trie node is one dictionary prefix state
- failure links are KMP-style longest proper fallback states on trie prefixes
- once `build()` fills missing transitions, scanning never follows `-1`
- the repo starter assumes lowercase `a`-`z` and aggregates terminal counts through failure links

## Main Traps

- forgetting to call `build()` before scanning
- copying the lowercase fixed-array starter into a different alphabet without changing the transition layer
- assuming aggregated `out` counts automatically recover every pattern identity or every end position
- using Aho-Corasick when one deterministic single-pattern tool is cleaner

## Exact Starters In This Repo

- many lowercase patterns against one text -> [`aho-corasick.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/aho-corasick.cpp)
- flagship repo note -> [Finding Patterns](../practice/ladders/strings/aho-corasick/findingpatterns.md)
- compare against lighter exact tools -> [String cheatsheet](string-cheatsheet.md)

## Reopen Paths

- failure links, output semantics, and automaton DP -> [Aho-Corasick](../topics/strings/aho-corasick/README.md)
- neighboring string-family chooser -> [String cheatsheet](string-cheatsheet.md)
- template map -> [Template Library](../template-library.md)
