# Stable Marriage Hot Sheet

Use this page when the statement is really about two-sided preferences and the word that matters is **stable**, not maximum or minimum.

## Do Not Use When

- the objective is maximum number of pairs in a compatibility graph
- the objective is minimum total cost across a perfect assignment
- the model has quotas, ties, incomplete lists, or roommate-style one-set matching

## Choose By Signal

- two equal-sized sides, every participant ranks every participant on the other side, and any stable pairing is accepted -> [`gale-shapley-stable-marriage.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/gale-shapley-stable-marriage.cpp)
- maximum number of compatible pairs in a bipartite graph -> [Matching hot sheet](matching-hot-sheet.md)
- one-to-one weighted assignment on a dense square matrix -> [Hungarian hot sheet](hungarian-hot-sheet.md)
- capacities or transport structure dominate -> [Min-Cost Flow hot sheet](min-cost-flow-hot-sheet.md)
- odd cycles in an undirected compatibility graph matter -> [General Matching hot sheet](general-matching-hot-sheet.md)

## Core Invariants

- each proposer only moves forward through the preference list
- each accepter keeps the best proposer seen so far
- every rejection is permanent
- when the queue empties, the result is stable and proposer-optimal for this proposing side

## Main Traps

- mistaking stability for minimum total dissatisfaction
- forgetting that swapping the proposing side flips which side gets the optimal stable outcome
- rebuilding accepter preference comparisons on the fly instead of precomputing inverse ranks
- feeding ties or missing partners to a starter that assumes strict full rankings

## Exact Starters In This Repo

- stable matching under full strict preferences -> [`gale-shapley-stable-marriage.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/gale-shapley-stable-marriage.cpp)
- flagship in-lane rep -> [Stable Marriage](../practice/ladders/graphs/stable-marriage/stablemarriage.md)
- cardinality sibling lane -> [Matching](../practice/ladders/graphs/matching/README.md)
- weighted sibling lane -> [Hungarian / Assignment Problem](../practice/ladders/graphs/hungarian-assignment/taskassignment.md)

## Reopen Paths

- exact tutorial -> [Stable Marriage](../topics/graphs/stable-marriage/README.md)
- bipartite pairing by size, not stability -> [Matching](../topics/graphs/matching/README.md)
- weighted one-to-one pairing by cost -> [Hungarian / Assignment Problem](../topics/graphs/hungarian-assignment/README.md)
- broader chooser -> [Graph cheatsheet](graph-cheatsheet.md)
- practice lane -> [Stable Marriage ladder](../practice/ladders/graphs/stable-marriage/README.md)
