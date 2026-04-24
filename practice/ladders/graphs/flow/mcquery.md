# MCQUERY

- Title: `MCQUERY - MinCut Query`
- Judge / source: `VN SPOJ / VNOI`
- Original URL: [https://vn.spoj.com/problems/MCQUERY/](https://vn.spoj.com/problems/MCQUERY/)
- Mirror URL: [https://oj.vnoi.info/problem/mcquery](https://oj.vnoi.info/problem/mcquery)
- Source contest: `Code Craft 09`
- Secondary topics: `Gomory-Hu tree`, `DSU`, `All-pairs min-cut`
- Difficulty: `hard`
- Subtype: `Count unordered pairs with minCut(s, t) <= x`
- Status: `solved`
- Solution file: [mcquery.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/flow/mcquery.cpp)

## Why Practice This

This is a great example of an “all-pairs cut” problem where the direct interpretation is too expensive, but a classical structure compresses everything almost perfectly.

The statement asks about all unordered pairs `(s, t)`, which makes naive repeated max-flow look impossible. The key observation is that for undirected weighted graphs, all pairwise min-cuts can be represented by one tree.

## Recognition Cue

Reach for a cut tree or compressed all-pairs structure when:

- the statement asks about min-cuts for many or all node pairs
- direct repeated max-flow would be too expensive
- the graph is undirected

The strongest smell is:

- "all unordered pairs `(s, t)` and their min-cuts"

That is the natural home of a Gomory-Hu tree.

## Problem-Specific Transformation

The all-pairs query is rewritten as:

- build one tree where path minimum encodes every pairwise min-cut

Then the counting question becomes:

- for each threshold `x`, count how many tree paths have minimum edge weight `<= x`

That is why the problem splits cleanly into:

- expensive tree construction once
- cheap DSU-based offline counting afterward

## Core Idea

For an undirected weighted graph, a **Gomory-Hu tree** has the property:

```text
minCut(s, t) = minimum edge weight on the unique path from s to t in the tree
```

So the problem becomes:

1. build the Gomory-Hu tree with `n - 1` max-flow computations
2. for each query `x`, count how many unordered pairs have path minimum `<= x`

Now work only on the tree.

Sort the Gomory-Hu tree edges by weight descending, and use DSU to add them one by one.

When one edge of weight `w` connects components of sizes `a` and `b`, exactly:

```text
a * b
```

new unordered pairs become connected for the first time, and their path minimum is exactly `w`.

That gives the number of pairs whose `minCut` equals each edge weight. After sorting these `(weight, count)` values ascending and taking prefix sums, every query is just one binary search.

## Complexity

For one test case:

- build Gomory-Hu tree: `n - 1` max-flow runs
- each max-flow uses Dinic on `n <= 150`, `m <= 3000`
- tree query preprocessing: `O(n log n)`
- each query: `O(log n)`

This is the intended scale for the official limits.

## Pitfalls / Judge Notes

- The graph is undirected and may contain multiple edges.
- Disconnected pairs have `minCut = 0`, which naturally appears as `0`-weight edges in the Gomory-Hu tree.
- The output requires a blank line between test cases.
- Edge capacities can accumulate to more than `2^31`, so use `long long`.
- After each max-flow in Gomory-Hu, the min-cut side is the set reachable from `s` in the final residual graph.

## Reusable Pattern

- Topic page: [Maximum Flow](../../../../topics/graphs/flow/README.md)
- Practice ladder: [Maximum Flow ladder](README.md)
- Starter template: [dinic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dinic.cpp)
- Notebook refresher: [Graph cheatsheet](../../../../notebook/graph-cheatsheet.md)
- Carry forward: separate the reusable residual-network engine from the problem-specific source/sink modeling.
- This note adds: repeated max-flow runs plus cut-tree construction on top of the base flow engine.

## Solutions

- Code: [mcquery.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/flow/mcquery.cpp)
