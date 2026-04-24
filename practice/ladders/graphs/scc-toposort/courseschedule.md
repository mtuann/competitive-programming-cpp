# Course Schedule

- Title: `Course Schedule`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1679](https://cses.fi/problemset/task/1679)
- Main topic: `Graphs -> Topological Sort And SCC`
- Secondary topics: `Kahn topological sort`, `Indegree counting`, `Directed cycle detection`
- Difficulty: `medium`
- Subtype: `Find a topological order or prove a directed cycle exists`
- Status: `solved`
- Solution file: [courseschedule.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/scc-toposort/courseschedule.cpp)

## Why Practice This

This is the cleanest topological-sort problem on CSES. It teaches the exact reason Kahn's algorithm works:

- indegree `0` means "no remaining prerequisites"
- removing such a node preserves the same structure on the smaller graph
- if the process gets stuck early, a cycle must exist

## Key Idea

For each course, store its current indegree.

Then:

1. Push every node with indegree `0` into a queue.
2. Repeatedly pop one node, append it to the answer, and "remove" all outgoing edges by decrementing neighbor indegrees.
3. Whenever a neighbor's indegree becomes `0`, push it into the queue.

This is Kahn's algorithm.

Why does it detect cycles?

- In a DAG, there is always at least one node with indegree `0`, so the process can keep going until all nodes are removed.
- If some nodes remain but none has indegree `0`, then every remaining node still depends on another remaining node, which means a directed cycle exists.

So the final check is:

```text
if answer size < n, print IMPOSSIBLE
```

Otherwise the produced order is a valid topological ordering.

## Complexity

- build indegrees and adjacency lists: `O(n + m)`
- Kahn traversal: `O(n + m)`
- total: `O(n + m)`

## Pitfalls / Judge Notes

- The graph is directed. Add only `a -> b`, not both directions.
- Decrement indegree exactly once per outgoing edge.
- Multiple valid topological orders can exist; any one is accepted.
- A failed topological sort is a cycle signal, not just "bad luck with queue order".

## Reusable Pattern

- Topic page: [Topological Sort And SCC](../../../../topics/graphs/scc-toposort/README.md)
- Practice ladder: [Topological Sort And SCC ladder](README.md)
- Starter template: [toposort-kahn.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/toposort-kahn.cpp)
- Notebook refresher: [Graph cheatsheet](../../../../notebook/graph-cheatsheet.md)
- Carry forward: state what becomes acyclic or what order must be preserved before choosing the graph algorithm.
- This note adds: the cycle detection or condensation reasoning specific to this problem.

## Solutions

- Code: [courseschedule.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/scc-toposort/courseschedule.cpp)
