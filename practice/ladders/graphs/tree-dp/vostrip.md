# VOSTRIP

- Title: `VOSTRIP`
- Judge / source: `VN SPOJ / VNOI`
- Original URL: [https://vn.spoj.com/problems/VOSTRIP/](https://vn.spoj.com/problems/VOSTRIP/)
- Mirror URL: [https://oj.vnoi.info/problem/vostrip](https://oj.vnoi.info/problem/vostrip)
- Main topic: `Graphs -> Tree DP`
- Secondary topics: `Path decomposition`, `Degree pairing`, `Counting endpoints`
- Difficulty: `hard`
- Subtype: `Minimum number of simple paths that realize edge-usage counts on a tree`
- Status: `solved`
- Solution file: [vostrip.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/tree-dp/vostrip.cpp)

## Why Practice This

This is a great tree problem because the final solution is much simpler than it first looks. Instead of building the paths directly, you only need to understand what must happen locally at each vertex.

## Key Idea

Each tour is a simple path on the tree. Every time a path uses an edge, that edge count decreases by `1`.

Think locally at a vertex `u`. Suppose the incident edges of `u` have required usage counts:

`c1, c2, ..., ck`

Let:

- `S = c1 + c2 + ... + ck`
- `M = max(ci)`

Every path copy that reaches `u` through one incident edge can:

- continue through a **different** incident edge, or
- stop at `u`, which creates one endpoint there

So at `u`, we want to pair as many incident edge-copies as possible, but we are never allowed to pair two copies from the **same** edge together.

That means the minimum number of unpaired copies left at `u` is:

`need(u) = max(S mod 2, 2 * M - S)`

Why:

- `S mod 2` handles parity: if `S` is odd, at least one copy must stay unmatched
- `2 * M - S` handles domination: if one edge contributes more copies than all other incident edges combined, the excess cannot be paired away

Those unmatched copies are exactly path endpoints at `u`.

So the minimum total number of tours is:

`answer = (sum of need(u) over all vertices) / 2`

because every path has exactly two endpoints.

## Complexity

- time: `O(N)`
- memory: `O(N)`

This is important because the largest tests go up to `N <= 10^6`, while the edge counts can be as large as `10^12`.

## Pitfalls / Judge Notes

- You do **not** need adjacency lists or DFS. The answer depends only on:
  - the sum of incident weights at each vertex
  - the maximum incident weight at each vertex
- Use `long long`.
- The official statement comments mention that the test data avoids pathological looping ambiguities from the story interpretation. The endpoint formula is still the correct accepted model.

## Reusable Pattern

- Topic page: [Tree DP](../../../../topics/dp/tree-dp/README.md)
- Practice ladder: [Tree DP ladder](README.md)
- Starter template: [tree-dp-subtree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/tree-dp-subtree.cpp)
- Notebook refresher: [Graph cheatsheet](../../../../notebook/graph-cheatsheet.md)
- Carry forward: root the tree and make every subtree contribution local before combining children.
- This note adds: the exact aggregation rule and path interpretation needed here.

## Solutions

- Code: [vostrip.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/tree-dp/vostrip.cpp)
