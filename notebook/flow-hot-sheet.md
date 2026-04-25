# Flow Hot Sheet

Use this page when capacities, cuts, disjoint routes, or source-sink transport are already visible in the statement and you want the lightest reliable flow route.

## Do Not Use When

- the cleaner model is just bipartite matching
- the task is shortest path or tree-path aggregation, not capacity transport
- the statement still needs graph modeling before algorithm choice

## Choose By Signal

- maximum throughput / minimum cut certificate / edge-disjoint paths -> [`dinic.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dinic.cpp)
- each unit of flow also pays a cost -> [`min-cost-flow.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/min-cost-flow.cpp)
- vertex capacities -> node splitting on top of max flow or min-cost flow
- pure bipartite pairing with no costs -> check [Matching hot sheet](matching-hot-sheet.md) before defaulting to flow

## Core Invariants

- every residual reverse edge means “we can undo part of an earlier choice”
- if no augmenting path remains, the current flow is maximum
- in min-cost flow, reduced costs plus potentials keep Dijkstra valid after reweighting

## Main Traps

- mutating only the forward edge and breaking the residual invariant
- forgetting node splitting when the statement constrains vertices rather than edges
- asking plain Dinic for a cost-sensitive answer
- feeding the min-cost-flow starter negative-cost edges without first ensuring valid initial potentials

## Exact Starters In This Repo

- max flow / min cut -> [`dinic.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dinic.cpp)
- min-cost flow -> [`min-cost-flow.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/min-cost-flow.cpp)
- clean cut certificate note -> [Police Chase](../practice/ladders/graphs/flow/policechase.md)
- costed transport note -> [MINCOST](../practice/ladders/graphs/flow/mincost.md)

## Reopen Paths

- modeling, cuts, and Dinic discipline -> [Maximum Flow](../topics/graphs/flow/README.md)
- reduced costs and fixed-value transport -> [Min-Cost Flow](../topics/graphs/min-cost-flow/README.md)
- broader graph-family chooser -> [Graph cheatsheet](graph-cheatsheet.md)
- practice lane -> [Flow ladder](../practice/ladders/graphs/flow/README.md)
