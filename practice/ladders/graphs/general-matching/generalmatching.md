# General Matching

- Title: `Matching on General Graph`
- Judge / source: `Library Checker`
- Original URL: [https://judge.yosupo.jp/problem/general_matching](https://judge.yosupo.jp/problem/general_matching)
- Secondary topics: `Edmonds blossom`, `Maximum cardinality matching`, `Odd-cycle contraction`
- Difficulty: `hard`
- Subtype: `Unweighted maximum matching on a simple undirected graph`
- Status: `solved`
- Solution file: [generalmatching.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/general-matching/generalmatching.cpp)

## Why Practice This

This is the cleanest first in-repo flagship for `Edmonds Blossom / General Matching`.

The statement is almost pure template:

- simple undirected graph
- arbitrary odd cycles allowed
- find the maximum matching
- print one witness matching

So the hard part is exactly the algorithmic one:

- know when bipartite matching is no longer enough
- trust blossom shrinking as the right augmenting-path repair

## Recognition Cue

Reach for blossom when:

- the graph is undirected
- each chosen edge must use two endpoints exclusively
- the graph is not guaranteed bipartite
- the objective is the size of the matching, not a cost sum

The strongest smell here is:

- "output any maximum matching in a general graph"

That is exactly this lane.

## Problem-Specific Route

This task does **not** want:

- Hopcroft-Karp, because the graph is not split into two sides
- Hungarian, because there is no assignment matrix or weight objective
- min-cost flow, because there is no transport/cost network to model first

The clean route is:

1. build the undirected graph
2. run blossom-based augmenting-path search
3. recover the partner of each matched vertex
4. print each matched pair once

## Core Idea

Start from the usual matching worldview:

- if an augmenting path exists, flip it and gain one matched edge

The only new issue is odd alternating cycles.

When BFS from one exposed root reaches another outer vertex in the same alternating forest, we found a blossom. Contract that odd cycle into one base, continue the search, and later expand implicitly through `base[]` and `parent[]`.

That keeps the augmenting-path theorem alive in a graph that is no longer bipartite.

## Complexity

- standard blossom implementation here: `O(n^3)`
- memory: `O(n^2)` worst case for the adjacency list on dense graphs

For the Library Checker limits `n <= 500`, this is comfortable.

## Pitfalls / Judge Notes

- The judge uses `0`-based vertices.
- Any maximum matching is accepted.
- Print each matched pair only once.
- Self-loops should not participate in the matching.

## Reusable Pattern

- Topic page: [Edmonds Blossom / General Matching](../../../../topics/graphs/general-matching/README.md)
- Practice ladder: [General Matching ladder](README.md)
- Starter template: [edmonds-blossom.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/edmonds-blossom.cpp)
- Notebook refresher: [General Matching hot sheet](../../../../notebook/general-matching-hot-sheet.md)
- Compare points:
  - [Matching](../../../../topics/graphs/matching/README.md)
  - [Hungarian / Assignment Problem](../../../../topics/graphs/hungarian-assignment/README.md)
  - [QBFLOWER](../matching/qbflower.md)
- This note adds: the clean direct template route where blossom is the engine itself, not only a hidden subroutine inside a transformed problem.

## Solutions

- Code: [generalmatching.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/general-matching/generalmatching.cpp)

