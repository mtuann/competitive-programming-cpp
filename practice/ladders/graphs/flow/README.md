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
- node splitting
- cut interpretation

Target skill:

- translate capacity statements into a correct network

## Stretch

- [MINCOST](mincost.md)
- compare bipartite matching reductions with plain flow reductions

Target skill:

- see flow as a modeling language, not just one algorithm

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
