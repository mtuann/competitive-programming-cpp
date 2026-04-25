# Aho-Corasick Ladder

## Who This Is For

Use this ladder when one-pattern string matching is comfortable, and you are ready to preprocess a whole dictionary of patterns into one automaton.

This lane is still thin inside the repo, so the intended loop is:

- hot sheet for retrieval
- one flagship repo note
- topic page for deeper variants like automaton DP

## Warm-Up

- build trie and failure links
- one-text multi-pattern counting

## Core

- output propagation
- automaton-based DP later

## Retrieval Layer

- exact quick sheet -> [Aho-Corasick hot sheet](../../../../notebook/aho-corasick-hot-sheet.md)
- lowercase fixed-array starter -> [aho-corasick.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/aho-corasick.cpp)
- flagship repo note -> [Finding Patterns](findingpatterns.md)

## Exit Criteria

You are ready to move on when you can:

- explain failure links as KMP-style fallback on trie states
- scan one text against many patterns in linear time
- propagate terminal/output information correctly
- recognize when Aho-Corasick is worth the heavier preprocessing

## External Practice

- [CP-Algorithms - Aho-Corasick](https://cp-algorithms.com/string/aho_corasick.html)
- [OI Wiki - AC Automaton](https://en.oi-wiki.org/string/ac-automaton/)

## Tutorial Link

- [Aho-Corasick](../../../../topics/strings/aho-corasick/README.md)
