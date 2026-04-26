# Matching Hot Sheet

Use this page when the statement is really about pairing two sides of a compatibility graph and you want the smallest reliable route back to bipartite matching.

## Do Not Use When

- the graph is not actually bipartite
- capacities or costs make a flow model cleaner than a plain matching model
- the problem is really edge cover, blossom, or weighted assignment and you still need to identify that boundary first

## Choose By Signal

- maximum number of compatible pairs in a bipartite graph -> [`hopcroft-karp.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hopcroft-karp.cpp)
- small bipartite modeling but retrieval is fuzzy -> reopen the [Matching](../topics/graphs/matching/README.md) page for Kuhn/Hopcroft-Karp chooser first
- equal-size two-sided preferences with a stability objective -> [Stable Marriage hot sheet](stable-marriage-hot-sheet.md)
- one-to-one weighted assignment on a dense square matrix -> [Hungarian hot sheet](hungarian-hot-sheet.md)
- capacities, source groups, or transport story dominate -> check [Flow hot sheet](flow-hot-sheet.md)
- undirected graph is not guaranteed bipartite -> [General Matching hot sheet](general-matching-hot-sheet.md)
- general graph / edge-cover transformation boundary -> treat [QBFLOWER](../practice/ladders/graphs/matching/qbflower.md) as a compare point, not as the in-lane baseline

## Core Invariants

- one augmenting path increases the matching size by exactly `1`
- if no augmenting path remains, the current matching is maximum
- the repo starter assumes the left and right parts are fixed in advance

## Main Traps

- feeding a non-bipartite graph to `Hopcroft-Karp`
- mixing statement indexing with the starter's `0`-based interface
- forgetting that some tasks ask for vertex cover / edge cover / weighted assignment after the matching, not just the matching size

## Exact Starters In This Repo

- bipartite maximum matching -> [`hopcroft-karp.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hopcroft-karp.cpp)
- flagship in-lane rep -> [School Dance](../practice/ladders/graphs/matching/schooldance.md)
- stable-preference sibling lane -> [Stable Marriage](../practice/ladders/graphs/stable-marriage/stablemarriage.md)
- weighted sibling lane -> [Task Assignment](../practice/ladders/graphs/hungarian-assignment/taskassignment.md)
- non-bipartite sibling lane -> [General Matching](../practice/ladders/graphs/general-matching/generalmatching.md)
- compare-point boundary note -> [QBFLOWER](../practice/ladders/graphs/matching/qbflower.md)
- when the cleaner reduction is capacity flow -> [`dinic.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dinic.cpp)

## Reopen Paths

- bipartite-first modeling and Kuhn/Hopcroft-Karp chooser -> [Matching](../topics/graphs/matching/README.md)
- stable pairing under strict preferences -> [Stable Marriage](../topics/graphs/stable-marriage/README.md)
- weighted one-to-one assignment chooser -> [Hungarian / Assignment Problem](../topics/graphs/hungarian-assignment/README.md)
- non-bipartite unweighted chooser -> [Edmonds Blossom / General Matching](../topics/graphs/general-matching/README.md)
- broader graph-family routing -> [Graph cheatsheet](graph-cheatsheet.md)
- practice lane -> [Matching ladder](../practice/ladders/graphs/matching/README.md)
- compare against flow modeling -> [Flow hot sheet](flow-hot-sheet.md)
