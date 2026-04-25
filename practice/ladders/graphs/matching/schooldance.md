# School Dance

- Title: `School Dance`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1696](https://cses.fi/problemset/task/1696)
- Secondary topics: `Hopcroft-Karp`, `Bipartite graph modeling`, `Matching reconstruction`
- Difficulty: `medium`
- Subtype: `Maximum bipartite matching with explicit pair output`
- Status: `solved`
- Solution file: [schooldance.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/matching/schooldance.cpp)

## Why Practice This

This is the cleanest in-repo anchor for the standard bipartite matching engine.

Nothing exotic is hiding in the statement:

- boys and girls already give you the two sides
- every allowed pair is one bipartite edge
- the task is simply to maximize the number of disjoint pairs and print one valid matching

That makes it a good flagship note for `Hopcroft-Karp`.

## Recognition Cue

Reach for bipartite matching when:

- the objects naturally split into two disjoint sides
- each valid relationship connects one left item and one right item
- each item can be used at most once
- the goal is to maximize the number of chosen pairs

The strong smell is:

- "maximum number of compatible boy-girl / job-worker / student-project pairs"

If both sides are explicit and every edge always crosses between them, this is usually bipartite matching first, not generic flow by default.

## Problem-Specific Transformation

The story is rewritten directly as:

- left side = boys
- right side = girls
- each allowed dance pair = one bipartite edge

Then the original task becomes:

- compute a maximum matching
- print any one optimal set of matched edges

So the problem is almost a textbook wrapper around the matching engine.

## Core Idea

Use `Hopcroft-Karp`.

It alternates between two steps:

1. BFS from all currently unmatched left-side vertices to build distance layers
2. DFS that only follows edges consistent with those layers, finding a batch of shortest augmenting paths

Every augmenting path increases the matching size by exactly `1`, and if no augmenting path remains, the matching is maximum.

Because the graph is already bipartite and the output can be any valid optimum matching, the implementation is straightforward:

- build the graph
- run `max_matching()`
- iterate over the matched left vertices and print the chosen pairs

## Complexity

- `O(k * sqrt(n + m))` for `Hopcroft-Karp` on this statement
- equivalently `O(E * sqrt(V))` in graph notation
- plus linear output of the matched pairs

This easily fits the CSES limits.

## Pitfalls / Judge Notes

- The graph is explicitly bipartite, so do not overbuild it as a general graph matching problem.
- Output uses `1`-based indices even if the starter uses `0`-based internals.
- Any valid maximum matching is accepted; there is no lexicographic requirement.
- The important extra step beyond “matching size” is reconstruction of the chosen pairs.

## Reusable Pattern

- Topic page: [Matching](../../../../topics/graphs/matching/README.md)
- Practice ladder: [Matching ladder](README.md)
- Starter template: [hopcroft-karp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hopcroft-karp.cpp)
- Notebook refresher: [Matching hot sheet](../../../../notebook/matching-hot-sheet.md)
- Carry forward: check bipartiteness and the two sides before touching the engine.
- This note adds: the clean output reconstruction layer on top of the standard bipartite matching primitive.

## Solutions

- Code: [schooldance.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/matching/schooldance.cpp)
