# Flow Ladder

This ladder should build the instinct that maximum flow is mostly about modeling: once the right network is built, Dinic is often the straightforward part.

## Who This Is For

Use this ladder if:

- flow still feels like a black box
- node splitting and cut interpretations are not yet automatic
- you want to know when flow is the right reduction and when it is overkill

## Warm-Up

- classic max flow
- edge-disjoint path reductions

Target skill:

- trust the residual-network model and reverse edges

## Core

- [FFLOW](fflow.md)
- [Police Chase](policechase.md)
- node splitting
- cut interpretation

Target skill:

- translate capacity statements into a correct network

## Stretch

- [MCQUERY](mcquery.md)
- [MINCOST](mincost.md)
- compare bipartite matching reductions with plain flow reductions

Transition note:

- `MINCOST` is not just “Dinic with costs”; it switches to a min-cost-flow engine with shortest augmenting paths, reduced costs, and potentials

Target skill:

- see flow as a modeling language, not just one algorithm
- recognize when a whole family of min-cuts can be compressed into one tree

## Retrieval Layer

- max flow / min cut route -> [Flow hot sheet](../../../../notebook/flow-hot-sheet.md)
- clean max-flow starter -> [dinic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dinic.cpp)
- costed flow route -> [Min-Cost Flow hot sheet](../../../../notebook/min-cost-flow-hot-sheet.md)
- cost-aware starter -> [min-cost-flow.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/min-cost-flow.cpp)
- compare against matching when the reduction is ambiguous -> [Matching hot sheet](../../../../notebook/matching-hot-sheet.md)

## Exit Criteria

You are ready to move on when:

- you can explain why reverse edges exist
- you can spot vertex-capacity problems and apply node splitting
- you can tell whether matching or flow is the cleaner reduction

## External Practice

- [CP-Algorithms - Dinic](https://cp-algorithms.com/graph/dinic.html)
- [CP-Algorithms - Min-Cost Flow](https://cp-algorithms.com/graph/min_cost_flow.html)
- [CSES Graph Algorithms](https://cses.fi/problemset/)

## Tutorial Links

- [Maximum Flow](../../../../topics/graphs/flow/README.md)
- [Min-Cost Flow](../../../../topics/graphs/min-cost-flow/README.md)
