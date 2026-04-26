# General Matching Hot Sheet

Use this sheet when the statement is really one **unweighted maximum matching on a general undirected graph** and odd cycles are no longer optional details.

## Do Not Use When

- the graph is bipartite -> [Matching hot sheet](matching-hot-sheet.md)
- the graph is bipartite and the objective is weighted assignment -> [Hungarian hot sheet](hungarian-hot-sheet.md)
- capacities or costs dominate the model -> [Flow hot sheet](flow-hot-sheet.md) or [Min-Cost Flow hot sheet](min-cost-flow-hot-sheet.md)
- the graph is weighted

## Choose By Signal

- arbitrary undirected graph + maximize number of disjoint edges -> `Edmonds Blossom / General Matching`
- bipartite compatibility graph + cardinality only -> [Matching hot sheet](matching-hot-sheet.md)
- dense square row/column assignment cost matrix -> [Hungarian hot sheet](hungarian-hot-sheet.md)
- story is really minimum edge cover on a general graph -> often `n - maximum_matching`, compare [QBFLOWER](../practice/ladders/graphs/matching/qbflower.md)

## Core Invariants

- `match[v]` always describes a legal matching partner or `-1`
- the alternating search forest is rooted at one exposed vertex
- `base[v]` stores the current blossom representative after contractions
- shrinking one blossom preserves whether an augmenting path exists
- one successful augmentation increases the matching size by exactly `1`

## Main Traps

- trying to force Hopcroft-Karp onto a non-bipartite graph
- forgetting this lane is unweighted only
- messing up `0`-based output when the judge wants `1`-based pairs
- confusing a maximal matching with a maximum matching

## Exact Starter Route

- exact starter -> [edmonds-blossom.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/edmonds-blossom.cpp)
- flagship in-lane rep -> [General Matching](../practice/ladders/graphs/general-matching/generalmatching.md)
- compare-point transformation note -> [QBFLOWER](../practice/ladders/graphs/matching/qbflower.md)
- bipartite sibling -> [School Dance](../practice/ladders/graphs/matching/schooldance.md)

## Reopen Paths

- full topic page -> [Edmonds Blossom / General Matching](../topics/graphs/general-matching/README.md)
- broader chooser -> [Graph cheatsheet](graph-cheatsheet.md)
- bipartite-first compare route -> [Matching](../topics/graphs/matching/README.md)
- weighted bipartite compare route -> [Hungarian / Assignment Problem](../topics/graphs/hungarian-assignment/README.md)

