# Min-Cost Flow Hot Sheet

Use this page when flow value and edge cost both matter and you want the shortest route back to a trustworthy cost-aware transport model.

## Do Not Use When

- plain max flow or min cut already answers the problem
- the statement is really matching with no costs
- the starter's reduced-cost assumptions are not satisfied and you have no plan for initial potentials

## Choose By Signal

- send a fixed amount as cheaply as possible with nonnegative initial forward costs -> [`min-cost-flow.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/min-cost-flow.cpp)
- send as much flow as possible while minimizing total transport cost -> min-cost max-flow framing, but the repo starter still exposes a fixed-`need` API
- each unit also pays a path-dependent cost -> min-cost flow, not plain Dinic
- costed assignment or transport with capacities -> model first, then min-cost flow

## Core Invariants

- residual reverse edges still mean “undo part of an earlier choice,” but now costs matter too
- shortest augmenting paths are chosen in reduced-cost space, not raw edge-cost space
- node potentials reweight edges so Dijkstra stays valid once reduced costs are nonnegative
- the repo starter assumes the initial residual network already has nonnegative reduced costs and starts with zero potentials

## Main Traps

- feeding negative-cost edges into the starter without seeding valid initial potentials first
- forgetting that fixed-value transport and min-cost max-flow are different stopping conditions
- modeling a costed pairing/transport problem as plain max flow and losing the objective
- assuming one min-cost-flow starter covers every circulation or lower-bound variant without extra modeling

## Exact Starters In This Repo

- fixed-value costed flow with nonnegative initial forward costs -> [`min-cost-flow.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/min-cost-flow.cpp)
- flagship repo note -> [MINCOST](../practice/ladders/graphs/flow/mincost.md)
- compare plain throughput first -> [Flow hot sheet](flow-hot-sheet.md)
- compare lower / upper edge demands first -> [Flow With Lower Bounds hot sheet](flow-lower-bounds-hot-sheet.md)

## Reopen Paths

- reduced costs, potentials, and modeling boundary -> [Min-Cost Flow](../topics/graphs/min-cost-flow/README.md)
- lower-bound feasibility before costs -> [Flow With Lower Bounds](../topics/graphs/flow-lower-bounds/README.md)
- broader capacity-family chooser -> [Flow hot sheet](flow-hot-sheet.md)
- snippet map -> [Template Library](../template-library.md)
