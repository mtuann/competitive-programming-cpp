# Tree Matching

- Title: `Tree Matching`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1130](https://cses.fi/problemset/task/1130)
- Secondary topics: `Maximum matching on a tree`, `Rooted subtree states`, `Child contribution swap`
- Difficulty: `medium`
- Subtype: `Choose the largest set of pairwise disjoint tree edges`
- Status: `solved`
- Solution file: [treematching.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/tree-dp/treematching.cpp)

## Why Practice This

This is one of the cleanest first tree-DP matchings:

- the global constraint is local: each vertex may be used by at most one chosen edge
- once the tree is rooted, child subtrees become independent
- the only extra choice is whether the current node matches one child or none

It is a good checkpoint for whether your tree states are actually minimal.

## Key Idea

Root the tree anywhere, for example at node `1`.

For each node `u`, keep two values:

```text
skip[u] = best matching size in u's subtree if u is not matched to any child
take[u] = best matching size in u's subtree if u is matched to exactly one child
```

Suppose `v` is a child of `u`.

If `u` is not matched to any child, then each child subtree can choose its own best outcome:

```text
skip[u] = sum over children v of max(skip[v], take[v])
```

To make `u` matched to one specific child `v`, we add edge `(u, v)`, so:

- `v` cannot also be matched to one of its own children
- every other child keeps its independent best value

If:

```text
base = sum over children w of max(skip[w], take[w])
```

then choosing child `v` gives:

```text
1 + skip[v] + (base - max(skip[v], take[v]))
```

So:

```text
take[u] = max over children v of
          1 + skip[v] + base - max(skip[v], take[v])
```

The answer is:

```text
max(skip[root], take[root])
```

## Complexity

- time: `O(n)`
- memory: `O(n)`

Each edge is processed only a constant number of times.

## Pitfalls / Judge Notes

- `take[u]` means matching `u` with exactly one child, not “at least one”.
- When `(u, v)` is chosen, child `v` must contribute `skip[v]`, not `take[v]`.
- A recursive DFS is fine conceptually, but an iterative postorder is safer on deep trees near the CSES limit.
- The answer is a count of edges in the matching, not vertices.

## Reusable Pattern

- Topic page: [Tree DP](../../../../topics/dp/tree-dp/README.md)
- Practice ladder: [Tree DP ladder](README.md)
- Starter template: [tree-dp-subtree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/tree-dp-subtree.cpp)
- Notebook refresher: [DP cheatsheet](../../../../notebook/dp-cheatsheet.md)
- Carry forward: make every state answer a rooted-subtree question with no hidden side conditions.
- This note adds: the specific child-combination rule and state split required here.

## Solutions

- Code: [treematching.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/tree-dp/treematching.cpp)
