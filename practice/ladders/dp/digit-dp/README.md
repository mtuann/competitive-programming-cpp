# Digit DP Ladder

This ladder should make digit DP feel like a small-position counting problem rather than a mysterious number-theory trick.

## Who This Is For

Use this ladder if:

- digit-based counting problems still feel impossible to brute force but also hard to model
- tight and started flags are still confusing
- `[l, r]` interval counting still causes mistakes

## Warm-Up

- count numbers by digit sum
- count numbers avoiding one local digit pattern

Target skill:

- define the minimal extra state beyond `pos`, `tight`, and `started`

## Core

- tight flag
- started flag
- small extra state such as remainder or previous digit

Target skill:

- turn a digit property into a compact DP state cleanly

## Stretch

- combine digit DP with automata
- multiple bounds and inclusion-exclusion style counting

Target skill:

- see when digit DP is the correct representation-layer DP and when direct combinatorics may be simpler

## Retrieval Layer

- exact quick sheet -> [Digit DP hot sheet](../../../../notebook/digit-dp-hot-sheet.md)
- prev-digit flavored starter -> [digit-dp-skeleton.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/digit-dp-skeleton.cpp)
- general state-design refresher -> [DP cheatsheet](../../../../notebook/dp-cheatsheet.md)

## Exit Criteria

You are ready to move on when:

- you can write `solve(r) - solve(l - 1)` instinctively
- you handle leading zeros correctly
- you can choose the extra state without storing irrelevant history

## External Practice

- [USACO Guide - Digit DP](https://usaco.guide/gold/digit-dp)
- [OI Wiki - Digit DP](https://en.oi-wiki.org/dp/number/)
- [AtCoder Educational DP Contest](https://atcoder.jp/contests/dp)

## Tutorial Link

- [Digit DP](../../../../topics/dp/digit-dp/README.md)
