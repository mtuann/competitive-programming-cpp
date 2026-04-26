# De Bruijn Sequence Ladder

This lane should make `every length-n block exactly once` feel like one reusable overlap-modeling family instead of a magical construction trick.

## Who This Is For

Use this lane if:

- you know `Hierholzer`, but do not yet see when a string task secretly becomes an Eulerian-cycle task
- the phrase "windows overlap by `n - 1`" still does not immediately trigger a state graph
- you want one clean binary benchmark before touching more general overlap-graph constructions

## Warm-Up

- directed Eulerian cycle intuition
- bitmask states for short suffix windows
- linear versus cyclic answer conventions

Target skill:

- say what the vertices and edges mean before coding the traversal

## Core

- [De Bruijn Sequence](debruijnsequence.md)
- `(n - 1)`-bit states
- one outgoing edge per appended bit
- linearize one Eulerian cycle into one witness string

Target skill:

- move cleanly from overlap modeling to one exact constructive string

## Stretch

- larger alphabets with the same overlap-state idea
- overlap-graph reconstruction where not every possible block exists
- compare against [Eulerian Path / Cycle](../../../../topics/graphs/eulerian-path-cycle/README.md) so feasibility-only tasks stay in the broader lane

Target skill:

- know whether the next task is still this exact binary route, or whether the graph model itself is the harder part

## Retrieval Layer

- quickest in-repo reminder -> [De Bruijn Sequence hot sheet](../../../../notebook/de-bruijn-sequence-hot-sheet.md)
- exact starter -> [de-bruijn-sequence-binary.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/de-bruijn-sequence-binary.cpp)
- flagship in-lane rep -> [De Bruijn Sequence](debruijnsequence.md)
- compare point -> [Eulerian Path / Cycle](../../../../topics/graphs/eulerian-path-cycle/README.md)

## Repo Anchors And Compare Points

- topic page -> [De Bruijn Sequence](../../../../topics/graphs/de-bruijn-sequence/README.md)
- graph-modeling compare point -> [Graph Modeling](../../../../topics/graphs/graph-modeling/README.md)
- Eulerian compare point -> [Eulerian Path / Cycle](../../../../topics/graphs/eulerian-path-cycle/README.md)
- broader graph routing -> [Graphs ladder](../README.md)

The strongest in-repo loop here is:

1. learn the overlap-state model from the [topic page](../../../../topics/graphs/de-bruijn-sequence/README.md)
2. solve or revisit [De Bruijn Sequence](debruijnsequence.md) as the clean binary flagship
3. reopen the [De Bruijn Sequence hot sheet](../../../../notebook/de-bruijn-sequence-hot-sheet.md) until `states = windows of length n - 1` is automatic
4. then branch to more irregular overlap-graph constructions only if needed

## Exit Criteria

You are ready to move on when:

- you instinctively model vertices as overlap states
- you can explain why the graph is Eulerian before touching code
- you can derive the final answer length `2^n + n - 1` without notes
- you no longer confuse this lane with ordinary string matching or plain explicit-graph Eulerian tasks

## External Practice

- [CSES - De Bruijn Sequence](https://cses.fi/problemset/task/1692)

## Tutorial Link

- [De Bruijn Sequence](../../../../topics/graphs/de-bruijn-sequence/README.md)
