# Toposort And SCC Ladder

This ladder should make directed-graph structure feel cleaner: first order a DAG, then learn how SCC compression turns a cyclic graph into a DAG.

## Who This Is For

Use this ladder if:

- directed dependencies still feel messy
- you know the algorithms, but not when SCC must come before DP
- cycles in directed graphs still lead to ad hoc reasoning

## Warm-Up

- topological order in a DAG
- cycle detection in a directed graph

Target skill:

- know when a DAG order exists and when it cannot

## Core

- Kahn topological sort
- SCC decomposition
- condensation DAG reasoning

Target skill:

- move from original graph to component DAG cleanly

## Stretch

- DAG DP after SCC compression
- compare Kosaraju and Tarjan conceptually

Target skill:

- use SCC as a preprocessing step for later graph logic

## Exit Criteria

You are ready to move on when:

- you can detect a failed toposort as a cycle signal
- you can explain why SCC condensation is acyclic
- you no longer attempt DAG DP directly on a cyclic graph

## External Practice

- [CP-Algorithms - SCC](https://cp-algorithms.com/graph/strongly-connected-components.html)
- [CSES Graph Algorithms](https://cses.fi/problemset/)
- [CP-Algorithms - Topological Sort](https://cp-algorithms.com/graph/topological-sort.html)

## Tutorial Link

- [Topological Sort And SCC](../../../../topics/graphs/scc-toposort/README.md)
