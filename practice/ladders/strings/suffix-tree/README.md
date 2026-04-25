# Suffix Tree Ladder

## Who This Is For

Use this ladder when heavier string tools are already comfortable and you want the compressed-index view of one static text.

The intended loop here is:

- hot sheet for retrieval
- one flagship repo note
- topic page when you need the full terminator / compressed-edge refresher

## Warm-Up

- understand why every suffix needs a unique terminator
- get comfortable matching across edge intervals, not node-by-node characters

## Core

- one static text as a substring index
- earliest occurrence from subtree minimum suffix start

## Retrieval Layer

- exact quick sheet -> [Suffix Tree hot sheet](../../../../notebook/suffix-tree-hot-sheet.md)
- compressed substring-index starter -> [suffix-tree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/suffix-tree.cpp)
- flagship repo note -> [Pattern Positions](patternpositions.md)

## Exit Criteria

You are ready to move on when you can:

- explain why a pattern may end in the middle of a compressed edge
- answer earliest occurrence from subtree metadata instead of rescanning the text
- say when suffix tree is a better mental model than suffix array or automaton

## External Practice

- [CSES - Pattern Positions](https://cses.fi/problemset/task/2104)
- [CSES - Distinct Substrings](https://cses.fi/problemset/task/2105/)
- [USACO Guide - String Suffix Structures](https://usaco.guide/adv/string-suffix)

## Tutorial Link

- [Suffix Tree](../../../../topics/strings/suffix-tree/README.md)
