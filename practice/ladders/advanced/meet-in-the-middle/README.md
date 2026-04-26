# Meet-In-The-Middle Ladder

This ladder is for the subset-search regime where `2^n` is too large but
splitting into two halves is still realistic.

## Who This Is For

Use this ladder when:

- the raw model is subset-like
- `n` is around `35` to `45`
- bitmask DP feels too large, but the halves can still be summarized cleanly

## Warm-Up

- split one set into two halves
- enumerate all half-sums
- sort one side and binary-search complements

## Core

- subset-sum style MITM
- best-feasible merge by sorting or hashing
- decide whether MITM or DP is the cleaner exact route

## Exact Repo Route

- exact starter -> [meet-in-the-middle-subset-sum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/advanced/meet-in-the-middle-subset-sum.cpp)
- flagship in-lane rep -> [Meet in the Middle](meetinthemiddle.md)
- compare exact-search lanes -> [Recursion And Backtracking](../../foundations/recursion-backtracking/README.md), [Bitmask DP](../../dp/bitmask-dp/README.md)
- algebraic square-root sibling -> [Discrete Logarithm Mod](../../math/bsgs-discrete-log/discretelogarithmmod.md)

## Compare Points Inside The Repo

- [Complexity And Hardness](../complexity-and-hardness/README.md)
- [Bitmask DP](../../dp/bitmask-dp/README.md)
- [BSGS / Discrete Log](../../math/bsgs-discrete-log/README.md)

## How To Use This Bridge

1. confirm the full state really factors into left half and right half
2. design the half summary before enumerating anything
3. make the merge cost explicit

## External Practice

- [CSES Problem Set](https://cses.fi/problemset/)
- [USACO Guide](https://usaco.guide/)

## Tutorial Link

- [Meet-In-The-Middle](../../../../topics/advanced/meet-in-the-middle/README.md)
