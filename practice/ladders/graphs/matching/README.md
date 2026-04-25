# Matching Ladder

This ladder should make bipartite matching feel like a natural modeling tool and help you separate it cleanly from flow, edge cover, and general matching.

## Who This Is For

Use this ladder if:

- pairing problems still feel story-specific instead of graph-structured
- you know augmenting paths, but not yet the modeling cues
- you are unsure when the graph is bipartite and when blossom-level machinery appears

## Warm-Up

- bipartite matching basics
- augmenting path intuition

Target skill:

- identify the two sides of the bipartite graph clearly

## Core

- [School Dance](schooldance.md)
- maximum bipartite matching
- matching as a reduction target

Target skill:

- turn assignment and compatibility statements into clean matching graphs

## Stretch

- [QBFLOWER](qbflower.md)
- compare matching reductions with flow reductions
- understand where edge-cover relationships appear

Target skill:

- distinguish bipartite matching, flow, and general matching on structure rather than terminology

## Retrieval Layer

- bipartite maximum matching -> [hopcroft-karp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hopcroft-karp.cpp)
- flagship in-lane rep -> [School Dance](schooldance.md)
- when the cleaner model is actually capacity flow -> [dinic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dinic.cpp)
- quick reminder sheet -> [Matching hot sheet](../../../../notebook/matching-hot-sheet.md)

## Repo Anchors And Compare Points

- boundary note, not the core bipartite rep -> [QBFLOWER](qbflower.md)
- compare against flow modeling -> [Police Chase](../flow/policechase.md)
- compare the teaching pages -> [Matching](../../../../topics/graphs/matching/README.md) and [Maximum Flow](../../../../topics/graphs/flow/README.md)
- reopen the broader graph routing layer -> [Matching ladder hub](README.md) and [Graphs ladder](../README.md)

The strongest in-repo loop here is:

1. learn the bipartite-first modeling cues from the [Matching topic](../../../../topics/graphs/matching/README.md)
2. solve or revisit [School Dance](schooldance.md) as the clean in-lane `Hopcroft-Karp` rep
3. solve or revisit [QBFLOWER](qbflower.md) only to see the boundary where blossom-level structure appears
4. compare one matching reduction against one flow reduction before moving on

## Exit Criteria

You are ready to move on when:

- you check bipartiteness before reaching for stronger machinery
- augmenting paths feel intuitive rather than memorized
- you can explain why a pairing problem is really matching and not just generic flow

## External Practice

- [CP-Algorithms - Kuhn / Bipartite Matching](https://cp-algorithms.com/graph/kuhn_maximum_bipartite_matching.html)
- [USACO Guide](https://usaco.guide/)

## Tutorial Link

- [Matching](../../../../topics/graphs/matching/README.md)
