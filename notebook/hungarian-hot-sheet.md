# Hungarian Hot Sheet

Use this sheet when the statement is really one **square weighted assignment** and you want the shortest route back to `O(n^3)` Hungarian.

## Do Not Use When

- the objective is only cardinality -> [Matching hot sheet](matching-hot-sheet.md)
- capacities, sparse feasibility edges, or extra routing structure dominate -> [Min-Cost Flow hot sheet](min-cost-flow-hot-sheet.md)
- the graph is not bipartite
- the problem is still fuzzy enough that you cannot state "one row, one column, minimum total cost"

## Choose By Signal

- dense `n x n` cost matrix + exact one-to-one assignment -> `Hungarian / Assignment Problem`
- sparse or capacity-rich costed assignment model -> [Min-Cost Flow hot sheet](min-cost-flow-hot-sheet.md)
- plain bipartite pairing with no weights -> [Matching hot sheet](matching-hot-sheet.md)

## Core Invariants

- dual potentials satisfy `u[i] + v[j] <= cost[i][j]`
- reduced slack `cost[i][j] - u[i] - v[j]` stays nonnegative
- only zero-slack edges are tight enough to join the current equality matching
- each augmentation increases the number of assigned rows by exactly `1`

## Main Traps

- using Hungarian when the graph is really sparse and min-cost flow is the clearer mental model
- forgetting the repo starter is intentionally square-matrix first
- mixing row/column indexing when reconstructing the assignment
- negating weights for max-assignment without upgrading to `long long`

## Exact Starter Route

- exact starter -> [hungarian-assignment.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hungarian-assignment.cpp)
- flagship in-lane rep -> [Task Assignment](../practice/ladders/graphs/hungarian-assignment/taskassignment.md)
- compare points -> [Matching](../topics/graphs/matching/README.md), [Min-Cost Flow](../topics/graphs/min-cost-flow/README.md)

## Reopen Paths

- full topic page -> [Hungarian / Assignment Problem](../topics/graphs/hungarian-assignment/README.md)
- broader graph-family chooser -> [Graph cheatsheet](graph-cheatsheet.md)
- reusable snippet map -> [Template Library](../template-library.md)
- retrieval router -> [Build Kit](../docs/build-kit.md)
