# Flow Hot Sheet

Use this page when capacities, cuts, disjoint routes, or source-sink transport are already visible in the statement and you want the lightest reliable flow route.

## Do Not Use When

- the cleaner model is just bipartite matching
- the task is shortest path or tree-path aggregation, not capacity transport
- the statement still needs graph modeling before algorithm choice

## Choose By Signal

- maximum throughput / minimum cut certificate / edge-disjoint paths -> [`dinic.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dinic.cpp)
- plain max flow / min cut, but you want a highest-label preflow engine or a denser hard-benchmark fallback -> [Push-Relabel hot sheet](push-relabel-hot-sheet.md)
- one undirected weighted graph, no source/sink, cheapest disconnection cut -> [Global Min-Cut hot sheet](global-min-cut-hot-sheet.md)
- many pairwise min-cuts on one undirected graph -> [Gomory-Hu hot sheet](gomory-hu-hot-sheet.md)
- every directed edge has mandatory lower and upper flow bounds -> [Flow With Lower Bounds hot sheet](flow-lower-bounds-hot-sheet.md)
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
- forgetting that lower bounds change the model before Dinic is the right engine
- asking plain Dinic for a cost-sensitive answer
- feeding the min-cost-flow starter negative-cost edges without first ensuring valid initial potentials

## Exact Starters In This Repo

- max flow / min cut -> [`dinic.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dinic.cpp)
- max flow / min cut with a preflow engine sibling -> [`push-relabel-max-flow.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/push-relabel-max-flow.cpp)
- global min-cut on one undirected weighted graph -> [Global Min-Cut hot sheet](global-min-cut-hot-sheet.md)
- lower / upper bounded circulation -> [Flow With Lower Bounds hot sheet](flow-lower-bounds-hot-sheet.md)
- min-cost flow -> [`min-cost-flow.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/min-cost-flow.cpp)
- all-pairs min-cut compression on one undirected graph -> [Gomory-Hu hot sheet](gomory-hu-hot-sheet.md)
- in-family engine rep -> [Maximum Flow (Push-Relabel route)](../practice/ladders/graphs/flow/maximumflowpushrelabel.md)
- clean cut certificate note -> [Police Chase](../practice/ladders/graphs/flow/policechase.md)
- costed transport note -> [MINCOST](../practice/ladders/graphs/flow/mincost.md)

## Reopen Paths

- modeling, cuts, and Dinic discipline -> [Maximum Flow](../topics/graphs/flow/README.md)
- engine sibling and preflow worldview -> [Push-Relabel hot sheet](push-relabel-hot-sheet.md)
- no-source/sink cut family -> [Randomized / Global Min-Cut](../topics/graphs/global-min-cut/README.md)
- repeated undirected min-cut compression -> [Gomory-Hu Tree](../topics/graphs/gomory-hu/README.md)
- mandatory lower bounds on edges -> [Flow With Lower Bounds](../topics/graphs/flow-lower-bounds/README.md)
- reduced costs and fixed-value transport -> [Min-Cost Flow](../topics/graphs/min-cost-flow/README.md)
- broader graph-family chooser -> [Graph cheatsheet](graph-cheatsheet.md)
- practice lane -> [Flow ladder](../practice/ladders/graphs/flow/README.md)
