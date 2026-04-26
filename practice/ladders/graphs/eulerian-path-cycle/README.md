# Eulerian Path / Cycle Ladder

This lane should make `use every edge exactly once` feel like one reusable graph family instead of a bag of one-off construction problems.

## Who This Is For

Use this lane if:

- parity and indegree/outdegree conditions still feel memorized rather than structural
- you know the word `Hierholzer`, but cannot yet derive when a trail exists
- the name clash with [Euler Tour / Subtree Queries](../../../../topics/graphs/euler-tour-subtree/README.md) still causes hesitation

## Warm-Up

- graph connectivity versus isolated vertices
- odd degree in undirected graphs
- indegree/outdegree balance in directed graphs

Target skill:

- say the path-versus-cycle existence rule in words before coding

## Core

- [Mail Delivery](maildelivery.md)
- iterative `Hierholzer`
- edge ids for multiedges
- final `path.size() == m + 1` guard

Target skill:

- move cleanly from degree feasibility to one exact constructive traversal

## Stretch

- directed path with fixed endpoints -> [CSES - Teleporters Path](https://cses.fi/problemset/task/1693)
- overlap graph / sequence reconstruction -> [De Bruijn Sequence](../de-bruijn-sequence/debruijnsequence.md)
- compare against [Euler Tour / Subtree Queries](../../../../topics/graphs/euler-tour-subtree/README.md) so the naming boundary stays clean

Target skill:

- know whether the next task is still one Eulerian trail problem, or whether the hard part is now graph modeling first

## Retrieval Layer

- quickest in-repo reminder -> [Eulerian hot sheet](../../../../notebook/eulerian-hot-sheet.md)
- exact starter -> [eulerian-path-cycle.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/eulerian-path-cycle.cpp)
- flagship in-lane rep -> [Mail Delivery](maildelivery.md)
- compare point for the name clash -> [Euler Tour / Subtree Queries](../../../../topics/graphs/euler-tour-subtree/README.md)
- hidden-overlap modeling sibling -> [De Bruijn Sequence](../de-bruijn-sequence/debruijnsequence.md)

## Repo Anchors And Compare Points

- topic page -> [Eulerian Path / Cycle](../../../../topics/graphs/eulerian-path-cycle/README.md)
- traversal prerequisite -> [BFS And DFS](../../../../topics/graphs/bfs-dfs/README.md)
- modeling compare point -> [Graph Modeling](../../../../topics/graphs/graph-modeling/README.md)
- broader graph routing -> [Graphs ladder](../README.md)

The strongest in-repo loop here is:

1. learn the degree / balance split from the [topic page](../../../../topics/graphs/eulerian-path-cycle/README.md)
2. solve or revisit [Mail Delivery](maildelivery.md) as the clean undirected flagship
3. reopen the [Eulerian hot sheet](../../../../notebook/eulerian-hot-sheet.md) until `Hierholzer + m + 1` is automatic
4. then move to `Teleporters Path` and [De Bruijn Sequence](../de-bruijn-sequence/debruijnsequence.md)

## Exit Criteria

You are ready to move on when:

- you can separate undirected and directed existence conditions without notes
- you reach for edge ids automatically
- you check `m + 1` as a connectivity guard without being reminded
- the word `Euler` no longer sends you to the wrong tree topic

## External Practice

- [CSES - Mail Delivery](https://cses.fi/problemset/task/1691)
- [CSES - Teleporters Path](https://cses.fi/problemset/task/1693)
- [CSES - De Bruijn Sequence](https://cses.fi/problemset/task/1692)

## Tutorial Link

- [Eulerian Path / Cycle](../../../../topics/graphs/eulerian-path-cycle/README.md)
