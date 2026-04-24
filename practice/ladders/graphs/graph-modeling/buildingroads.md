# Building Roads

- Title: `Building Roads`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1666](https://cses.fi/problemset/task/1666)
- Secondary topics: `Connected components`, `Component representatives`, `Constructive output`
- Difficulty: `easy`
- Subtype: `Connect all components of an undirected graph with a minimum set of new edges`
- Status: `solved`
- Solution file: [buildingroads.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/graph-modeling/buildingroads.cpp)

## Why Practice This

This is a great early modeling problem because the main difficulty is not the DFS itself.

The real step is to notice:

- cities are vertices
- roads are undirected edges
- the missing requirement is simply “make all connected components become one”

After that, the minimum construction is almost forced.

## Recognition Cue

Reach for this pattern when:

- the graph is undirected
- you are asked to add the minimum number of extra edges to make it connected
- there are no weights or secondary costs on the new edges
- the natural first object to compute is connected components

The strongest reduction is:

- "connect all components" instead of "build some special road network"

## Problem-Specific Transformation

The statement is about roads between cities, but the reusable rewrite is:

- existing roads define connected components
- every new road can merge at most two components

So the optimization question becomes purely structural:

- if there are `k` components, at least `k - 1` new roads are necessary
- one representative per component is enough to explicitly build such a set

That turns the problem from graph construction into:

- find representatives
- connect them in a chain

## Core Idea

Build the undirected graph of the existing road network and find its connected components.

If the graph has component representatives:

```text
r1, r2, ..., rk
```

then:

- at least `k - 1` new roads are necessary, because each new road can reduce the component count by at most one
- `k - 1` roads are also sufficient, because connecting `r1-r2`, `r2-r3`, ..., `r(k-1)-rk` merges everything into one connected graph

So the task reduces to:

1. Find one representative city from each connected component.
2. Output roads linking consecutive representatives.

The graph-modeling payoff is that the constructive output falls directly out of the component structure.

## Complexity

- building the graph: `O(n + m)`
- finding components with DFS/BFS: `O(n + m)`
- printing the new roads: `O(k)`
- total: `O(n + m)`

## Pitfalls / Judge Notes

- Any valid set of `k - 1` connecting roads is accepted; you do not need a unique answer.
- The graph is undirected, so add both directions.
- The important object to store is one representative per component, not the whole component list.
- Do not overcomplicate this into MST logic. There are no edge weights and the task only asks to connect components.

## Reusable Pattern

- Topic page: [Graph Modeling](../../../../topics/graphs/graph-modeling/README.md)
- Practice ladder: [Graph Modeling ladder](README.md)
- Starter template: [dfs-iterative.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dfs-iterative.cpp)
- Notebook refresher: [Graph cheatsheet](../../../../notebook/graph-cheatsheet.md)
- Carry forward: once the graph splits into components, many “minimum extra links” tasks reduce to choosing one representative per component.
- This note adds: the constructive step that turns connected-component information into an explicit valid output.

## Solutions

- Code: [buildingroads.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/graph-modeling/buildingroads.cpp)
