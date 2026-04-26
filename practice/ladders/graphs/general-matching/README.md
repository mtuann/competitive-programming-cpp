# Edmonds Blossom / General Matching Ladder

This lane is for the first time matching remains the right model, but bipartiteness is gone and odd cycles actually matter.

## Who This Is For

Use this lane if:

- [Matching](../../../../topics/graphs/matching/README.md) already feels comfortable
- you trust augmenting-path logic in bipartite graphs
- you now need maximum cardinality matching in a general undirected graph

This lane is intentionally narrow:

- one exact starter
- one flagship note that is the plain template problem
- one transformation compare point through [QBFLOWER](../matching/qbflower.md)
- one firm boundary against weighted assignment and weighted blossom

## Warm-Up

- explain why an odd cycle breaks the naive bipartite alternating-tree picture
- explain why blossom is still augmenting-path matching, not a different objective
- compare one bipartite matching statement against one general matching statement

Target skill:

- recognize when "the graph is not bipartite" is the decisive signal, not just a side comment

## Core

- general undirected graph
- maximum number of disjoint edges
- odd-cycle contraction via blossom shrinking
- exact flagship rep: [General Matching](generalmatching.md)

Target skill:

- trust the `O(n^3)` blossom route and recover one valid maximum matching

## Stretch

- transformation route -> [QBFLOWER](../matching/qbflower.md)
- compare one direct general-matching problem against one [Task Assignment](../hungarian-assignment/taskassignment.md) instance
- compare one direct general-matching problem against one [MINCOST](../flow/mincost.md) instance

Target skill:

- separate unweighted general matching from weighted bipartite assignment and from costed flow models

## Retrieval Layer

- exact quick sheet -> [General Matching hot sheet](../../../../notebook/general-matching-hot-sheet.md)
- exact starter -> [edmonds-blossom.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/edmonds-blossom.cpp)
- compare route -> [Matching](../../../../topics/graphs/matching/README.md)
- compare route -> [Hungarian / Assignment Problem](../../../../topics/graphs/hungarian-assignment/README.md)
- broader chooser -> [Graph cheatsheet](../../../../notebook/graph-cheatsheet.md)

## Repo Anchors And Compare Points

- topic page -> [Edmonds Blossom / General Matching](../../../../topics/graphs/general-matching/README.md)
- flagship note -> [General Matching](generalmatching.md)
- transformation compare point -> [QBFLOWER](../matching/qbflower.md)
- bipartite sibling -> [Matching](../../../../topics/graphs/matching/README.md)
- broader routing -> [Graphs ladder](../README.md)

The cleanest in-repo loop here is:

1. reopen [Matching](../../../../topics/graphs/matching/README.md) just enough to remember alternating paths
2. learn the blossom route in [Edmonds Blossom / General Matching](../../../../topics/graphs/general-matching/README.md)
3. solve [General Matching](generalmatching.md)
4. revisit [QBFLOWER](../matching/qbflower.md) only after the direct template route feels stable

## Exit Criteria

You are ready to move on when:

- you stop trying to 2-color every matching problem by reflex
- you know that odd cycles are the reason blossom exists
- you can recover and print one maximum matching, not just its size

## External Practice

- [Library Checker - Matching on General Graph](https://judge.yosupo.jp/problem/general_matching)
- [Luogu P6113 - Template General Matching](https://www.luogu.com.cn/problem/P6113)
- [VN SPOJ - QBFLOWER](https://vn.spoj.com/problems/QBFLOWER/)

## Tutorial Link

- [Edmonds Blossom / General Matching](../../../../topics/graphs/general-matching/README.md)

