# VMCOINS

- Title: `VMCOINS - Trò chơi với những đồng xu`
- Judge / source: `VN SPOJ / VNOI`
- Original URL: [https://vn.spoj.com/problems/VMCOINS/](https://vn.spoj.com/problems/VMCOINS/)
- Mirror URL: [https://oj.vnoi.info/problem/vmcoins](https://oj.vnoi.info/problem/vmcoins)
- Secondary topics: `Promise-driven search`, `Translation matching`, `State BFS`
- Difficulty: `hard`
- Subtype: `Find an N-2 common core under some translation, then BFS the two free coins around that core`
- Status: `solved`
- Solution file: [vmcoins.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/constructive/vmcoins.cpp)

## Why Practice This

This is a classic “read the guarantee carefully” problem.

If you ignore the special promise about two coins in the starting state, the problem looks like a wide constructive search on an infinite grid. The accepted-style solution in this repo becomes small only because it uses that promise directly.

## Recognition Cue

Reach for this kind of constructive reduction when:

- the statement contains a strong promise that looks almost too specific
- a naive search space is huge, but one small invariant substructure might stay fixed
- the intended solution seems to depend more on exploiting the promise than on generic search

The strongest smell here is:

- "two special coins" plus acceptance up to translation

That is a signal to search for a fixed common core and isolate only a very small movable boundary.

## Problem-Specific Transformation

The raw problem looks like a large reconfiguration search on the whole board.

The reusable rewrite is:

- find a translated target where `N - 2` coins can remain fixed
- treat those fixed coins as the invariant core
- search only the state graph of the two remaining free coins

So the enormous global search collapses to:

- promise-driven core matching
- tiny state BFS for the free part

## Core Idea

The first repo version was wrong because it assumed:

- if we find a translated target with `N - 2` overlap
- then the last two coins can always be placed in at most two direct moves

That is too strong.

The corrected version still uses the same promise-driven spine:

1. search for a translation where a set of `N - 2` cells can stay fixed as a common core
2. let the remaining two coins be the free coins
3. BFS on the unordered positions of those two free coins while the core stays fixed

Each BFS transition moves exactly one free coin to a cell that has at least two neighbors among:

- the fixed core
- the other free coin

So the solver is no longer guessing “two direct moves”; it explicitly searches the legal reconfiguration graph of the two movable coins.

## Complexity

- candidate translations: `O(N^2)`
- core choices per translation: at most `O(N^2)` because only up to two common cells can be excluded
- BFS states: `O(B^2)` where `B` is the boundary-size candidate set around the fixed core

Overall:

- time: fast enough for `N <= 30` with the small fixed-core search
- memory: `O(N)`

This is fine for `N <= 30`.

## Pitfalls / Judge Notes

- This solution is **promise-driven**. It uses the strong guarantee to search for a fixed `N - 2` core plus two free coins.
- The target is accepted up to translation, so always test shifted copies of the target, not only the raw coordinates.
- A move is legal only if the destination has at least two adjacent coins after removing the source coin. In the BFS, that means the destination must see at least two neighbors in `core + other_free_coin`.
- The previous repo version was not correct enough for the full judge because it only tried direct finishing moves. The current version explicitly searches the intermediate helper positions.

## Reusable Pattern

- Topic page: [Constructive](../../../../topics/advanced/constructive/README.md)
- Practice ladder: [Constructive ladder](README.md)
- Starter template: [contest-main.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/contest-main.cpp)
- Carry forward: look for the smallest invariant that forces the construction to succeed.
- This note adds: a problem-specific constructive argument instead of a reusable code skeleton.

## Solutions

- Code: [vmcoins.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/constructive/vmcoins.cpp)
