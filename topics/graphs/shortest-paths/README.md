# Shortest Paths

Shortest paths is not one algorithm. It is a **chooser family** built around one question:

> What kind of relaxations are valid for this graph model?

That is why this topic should not be learned as "Dijkstra plus some edge cases." The real skill is:

- read the edge model
- identify the strongest guarantee you have
- use the lightest algorithm that is still correct

This page is written as a family / chooser page, not as one single-technique lesson.

## At A Glance

Reach for shortest paths when:

- the problem asks for minimum distance, minimum cost, minimum time, or minimum number of moves
- the graph may be explicit or hidden inside state transitions
- later logic depends on distances as a base layer
- path reconstruction matters, not just the final numeric answer

Strong contest triggers:

- "shortest path"
- "minimum travel cost / minimum number of edges / minimum moves"
- "cheapest route"
- "best path with one or two extra constraints"
- "distance to a target for many later queries"

Strong anti-cues:

- the graph is unweighted and you are reaching for Dijkstra out of habit
- the structure is actually a tree DP or LCA problem with path queries, not shortest paths
- the weights are all nonnegative but the graph is tiny and all-pairs is the real target
- the problem is really about max-flow / matching / MST rather than additive path cost

What success looks like after studying this page:

- you choose between BFS, `0-1 BFS`, Dijkstra, Bellman-Ford, and Floyd-Warshall from the model
- you can explain why Dijkstra fails on negative edges
- you know when reverse-graph distances simplify the whole problem
- you know when all-pairs is actually easier than repeated single-source runs
- you treat relaxation as the core invariant, not as an implementation detail

## Prerequisites

- [Graph Modeling](../graph-modeling/README.md)
- [BFS And DFS](../bfs-dfs/README.md)
- [Heaps And Ordered Sets](../../data-structures/heaps-and-ordered-sets/README.md)

Helpful neighboring topics:

- [Minimum Spanning Tree](../mst/README.md)
- [Flow](../flow/README.md)
- [Graph Cheatsheet](../../../notebook/graph-cheatsheet.md)

## Problem Model And Notation

Let:

- $G = (V, E)$ be a graph
- $w(u, v)$ be the edge weight if the edge exists
- $s$ be the source
- `dist[v]` be the current best known distance from `s` to `v`

The universal shortest-path inequality is:

$$
dist[v] \le dist[u] + w(u, v).
$$

A **relaxation** on edge $(u, v)$ means:

$$
\text{if } dist[u] + w(u, v) < dist[v], \text{ then update } dist[v].
$$

Every shortest-path algorithm in this family is built around the same relaxation rule. What changes is:

- which vertices / edges you process next
- what guarantees let you finalize an answer
- what weight model makes that strategy sound

## From Brute Force To The Right Idea

### Brute Force

The brute-force view is:

- try all paths from `s` to `t`
- take the minimum total cost

This is useless in general because the number of paths can explode exponentially.

So the right compression is:

- many different paths can end at the same vertex
- only the best cost to each state matters

That is the dynamic-programming heart of shortest paths.

### Relaxation Is The Real Primitive

Suppose we already know a good path to `u`.

Then every outgoing edge gives a candidate path to `v`:

$$
dist[u] + w(u, v).
$$

If that candidate is better than the current `dist[v]`, we should keep it.

That is all relaxation means.

The entire family can be summarized like this:

- BFS chooses vertices in increasing number of edges
- `0-1 BFS` chooses them with a deque because distances differ by at most `1`
- Dijkstra chooses the smallest current tentative distance
- Bellman-Ford relaxes all edges repeatedly until path lengths by edge-count are exhausted
- Floyd-Warshall adds allowed intermediate vertices one layer at a time

### The First Question Is Always The Weight Model

Before writing any code, ask:

1. are edges unweighted?
2. are weights only `0/1`?
3. are all weights nonnegative?
4. do negative edges exist?
5. do I need all-pairs instead of one source?
6. is the graph actually a DAG, grid, or reversed graph model in disguise?

That one checklist determines most shortest-path solutions correctly.

## Core Invariant And Why It Works

This section is organized by family member, because the proof boundary is different for each one.

### 1. BFS: Unit-Weight Shortest Paths

If every edge has weight `1` (or the graph is unweighted), BFS processes vertices layer by layer.

Invariant:

- when a vertex is first popped from the queue, it is reached with the minimum number of edges from the source

Why?

Because all vertices discovered from the current layer belong to the next layer, and no later discovery can use fewer edges.

So BFS is exactly the shortest-path algorithm for unit weights.

### 2. `0-1 BFS`: Deque-Ordered Relaxation

If every edge weight is either `0` or `1`, then the distances of active frontier states differ by at most `1`.

That is why a deque is enough:

- relax by `0` -> push to the front
- relax by `1` -> push to the back

The deque stays in nondecreasing tentative distance order, which gives the same spirit as Dijkstra but cheaper.

This is not a hack. It is Dijkstra specialized to a tighter queue geometry.

### 3. Dijkstra: Greedy Finalization Needs Nonnegative Weights

Dijkstra’s invariant is the famous one:

- when the smallest-distance unprocessed vertex `u` is extracted, `dist[u]` is already final

Why does this work?

Because every not-yet-processed path to some other vertex must be at least as large as the current minimum tentative distance, and nonnegative edges cannot later reduce the already-finalized value.

That last clause is the whole theorem boundary:

- **nonnegative edges are required**

If a negative edge exists, a later path may improve a node that Dijkstra already finalized.

### 4. Bellman-Ford: Shortest Paths By Edge Count

Bellman-Ford does not try to finalize nodes greedily.

Instead, it uses this invariant:

- after `k` full passes over the edge list, every shortest path using at most `k` edges has been found

So after `n - 1` passes:

- every shortest simple path has been found, if no reachable negative cycle exists

This is why Bellman-Ford works with negative edges:

- it never assumes "smallest tentative distance means done"
- it only assumes that shortest simple paths use at most `n - 1` edges

The negative-cycle detection pass is then natural:

- if one more pass can still improve something reachable from `s`, there is a reachable negative cycle

### 5. Floyd-Warshall: Dynamic Programming On Allowed Intermediates

For all-pairs shortest paths on small `n`, Floyd-Warshall uses:

$$
dp[k][i][j] = \text{shortest path from } i \text{ to } j \text{ using only intermediates in } \{1,\dots,k\}.
$$

The transition is:

$$
dp[k][i][j] = \min(dp[k-1][i][j],\ dp[k-1][i][k] + dp[k-1][k][j]).
$$

The usual in-place version compresses away the first dimension.

This is not a single-source algorithm at all. It is all-pairs DP over intermediate-vertex sets.

### 6. Reverse Shortest Paths Are The Same Problem

If you need distances **to** one fixed target in a directed graph:

- reverse all edges
- run the same single-source algorithm from the target

This works because every path from `u` to `t` in the original graph corresponds to a path from `t` to `u` in the reversed graph with the same total weight.

This modeling trick is one of the highest-value shortest-path habits in contests.

## Complexity And Tradeoffs

Let `n = |V|` and `m = |E|`.

Typical bounds:

- BFS: `O(n + m)`
- `0-1 BFS`: `O(n + m)`
- Dijkstra with binary heap: `O((n + m) log n)`
- Bellman-Ford: `O(nm)`
- Floyd-Warshall: `O(n^3)`

Practical tradeoffs:

| Tool | Best when | Time | Main tradeoff |
| --- | --- | --- | --- |
| BFS | unweighted graph / unit costs | linear | only valid for unit weights |
| `0-1 BFS` | weights in `{0, 1}` | linear | specialized model |
| Dijkstra | nonnegative weights | near-linear on sparse graphs | fails on negative edges |
| Bellman-Ford | negative edges or negative-cycle detection | slower but general | too expensive if nonnegative structure exists |
| Floyd-Warshall | all-pairs on small `n`, dense graphs, clean DP transitions | cubic | impossible on large `n` |

Rule of thumb:

- use the simplest valid model
- weighted algorithms are not automatically better
- if all-pairs is truly the task and `n` is small, Floyd-Warshall may be cleaner than many single-source runs

## Variant Chooser

| Situation | Best first tool | Why it fits | Main danger |
| --- | --- | --- | --- |
| unweighted / every move costs `1` | BFS | layer order is exact shortest-path order | overengineering with Dijkstra |
| weights only `0` or `1` | `0-1 BFS` | deque maintains distance order cheaply | treating it as plain BFS |
| sparse graph, nonnegative weights | Dijkstra | greedy finalization is valid | stale heap entries or negative edges |
| negative edges, no huge constraints | Bellman-Ford | repeated relaxations remain valid | forgetting reachable negative-cycle logic |
| all-pairs, `n` small | Floyd-Warshall | direct DP on intermediates | using it when `n` is too large |
| many queries to one target | reverse graph + one shortest-path run | distances to target become distances from source in reversed graph | forgetting to reverse directed edges |
| DAG shortest paths | topological DP | no cycles, one pass in topological order | using heavier machinery than needed |

Two quick reject rules:

- negative edge present -> reject Dijkstra immediately
- unit-weight graph -> reject Dijkstra unless there is some extra modeling reason

## Beyond The Core Family

This page is deliberately centered on the **core contest family**:

- BFS
- `0-1 BFS`
- Dijkstra
- Bellman-Ford
- Floyd-Warshall
- DAG shortest paths

Those are the tools that solve the overwhelming majority of shortest-path tasks in standard contest sets.

There are also important **advanced / specialized** shortest-path tools:

- `A*` for one-source, one-target search when you have a strong heuristic
- bidirectional BFS / Dijkstra when the start and target are both fixed and the graph model is friendly
- Dial's algorithm or radix-heap style Dijkstra when edge weights are nonnegative integers with extra structure
- Johnson's algorithm when you want all-pairs shortest paths on sparse graphs with negative edges but no negative cycles

These tools are valuable, but they belong to the next layer for a reason:

- their correctness depends on extra assumptions beyond the core weight model
- their payoff is often about constants, heuristics, or preprocessing strategy
- many contest problems do not provide the clean heuristic or graph structure they need

For example, `A*` is not "faster Dijkstra by magic." It is correct when the heuristic never overestimates the remaining distance, and it is especially clean when that heuristic is also consistent. In route planning or pathfinding on geometric maps, that often happens naturally. In many contest graphs, it does not.

So the study order should be:

1. master the core family on this page
2. learn how relaxation order changes with the weight model
3. only then add goal-directed or specialized speedups such as `A*`, bidirectional search, or integer-weight optimizations

## Worked Examples

### Example 1: `Message Route` Is Just BFS

In [Message Route](../../../practice/ladders/graphs/bfs-dfs/messageroute.md), every edge represents one hop.

So the path cost is:

$$
\text{number of edges}.
$$

That is exactly the BFS model.

Why not Dijkstra?

Because Dijkstra would be solving a more general problem than the one actually present. BFS already processes vertices in shortest-hop order.

This is the cleanest reminder that:

- BFS is not "graph traversal only"
- it is the correct shortest-path tool when all edges cost `1`

### Example 2: `0-1 BFS` Is Dijkstra With A Deque

Suppose the graph edges are:

- `u -> v` with cost `0`
- `u -> w` with cost `1`

If `dist[u] = 7`, then new tentative distances are:

- `7` for `v`
- `8` for `w`

So the active frontier differs by at most one layer of cost.

That is why a deque is enough:

- `v` goes to the front
- `w` goes to the back

This tiny local example is the whole reason `0-1 BFS` works.

### Example 3: Why Dijkstra Fails On Negative Edges

Consider:

```text
s -> a (2)
s -> b (5)
b -> a (-10)
```

At first, Dijkstra sees:

- `dist[a] = 2`
- `dist[b] = 5`

so it would finalize `a` first.

But the true best path to `a` is:

```text
s -> b -> a
```

with total cost:

$$
5 + (-10) = -5.
$$

That later improvement is exactly what nonnegative edges are supposed to forbid. Once you see this counterexample clearly, the Dijkstra boundary becomes impossible to forget.

### Example 4: Bellman-Ford As "Paths With At Most k Edges"

Suppose the shortest path to some node uses exactly three edges.

Then:

- after one pass, shortest paths using one edge are correct
- after two passes, shortest paths using up to two edges are correct
- after three passes, that target becomes correct too

This is the mental model that makes Bellman-Ford feel clean instead of brute-force:

- one pass = one more allowed edge in the path

### Example 5: Reverse Shortest Paths

Suppose a problem asks:

- for every city `u`, what is the cheapest cost to reach target city `t`?

In a directed graph, running one shortest-path computation from every `u` is often wasteful.

Instead:

1. reverse every edge
2. start one run from `t`

Then the answer read at `dist[u]` in the reversed graph equals the original distance from `u` to `t`.

This is one of the most useful graph-modeling transformations in the whole topic.

### Example 6: Floyd-Warshall Is Sometimes The Cleaner Choice

Suppose:

- `n <= 500`
- you need all-pairs distances
- maybe also path existence or negative-cycle influence between many pairs

Then repeated Dijkstra may be more code and not even asymptotically better on dense graphs.

Floyd-Warshall gives:

- direct all-pairs DP
- one simple recurrence
- easy extension for transitive-closure-style reasoning

This is why "all-pairs" should appear in your chooser before you reflexively think about single-source runs.

## Algorithm And Pseudocode

Repo starter templates:

- [bfs.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bfs.cpp)
- [zero-one-bfs.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/zero-one-bfs.cpp)
- [dijkstra.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dijkstra.cpp)
- [bellman-ford.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bellman-ford.cpp)

There is not yet a dedicated Floyd-Warshall starter template in this repo.

### BFS

```text
dist[*] = INF
dist[s] = 0
queue q = [s]

while q not empty:
    u = pop front
    for each neighbor v:
        if dist[v] is INF:
            dist[v] = dist[u] + 1
            parent[v] = u
            push v
```

### `0-1 BFS`

```text
dist[*] = INF
dist[s] = 0
deque dq = [s]

while dq not empty:
    u = pop front
    for each edge (u, v, w):
        if dist[u] + w < dist[v]:
            dist[v] = dist[u] + w
            parent[v] = u
            if w == 0:
                push_front(v)
            else:
                push_back(v)
```

### Dijkstra

```text
dist[*] = INF
dist[s] = 0
priority queue pq = {(0, s)}

while pq not empty:
    (du, u) = pop minimum
    if du != dist[u]:
        continue   // stale entry

    for each edge (u, v, w):
        cand = dist[u] + w
        if cand < dist[v]:
            dist[v] = cand
            parent[v] = u
            push (dist[v], v)
```

### Bellman-Ford

```text
dist[*] = INF
dist[s] = 0

repeat n - 1 times:
    changed = false
    for each edge (u, v, w):
        if dist[u] != INF and dist[u] + w < dist[v]:
            dist[v] = dist[u] + w
            parent[v] = u
            changed = true
    if not changed:
        break

one more pass:
    if some reachable edge still relaxes:
        reachable negative cycle exists
```

### Floyd-Warshall

```text
dist[i][j] = edge weight or INF
dist[i][i] = 0

for k in vertices:
    for i in vertices:
        for j in vertices:
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
```

## Implementation Notes

### 1. Relaxation Is The Unifying Operation

If you are stuck, return to the primitive:

```text
can I improve dist[v] through u?
```

This viewpoint makes algorithm switching much easier than memorizing four unrelated code blocks.

### 2. `long long` Is The Default Distance Type

Path totals overflow `int` surprisingly often.

The safe contest habit is:

- use `long long`
- define `INF` as something like `numeric_limits<long long>::max() / 4`

so addition does not overflow immediately.

### 3. Heap Dijkstra Needs Stale-Entry Skipping

The repo template uses:

```text
if current_dist != dist[u]: continue
```

That is not a cosmetic optimization. It is the standard correctness-preserving way to ignore outdated heap entries after a better path was found later.

### 4. Reverse Graph Is A Modeling Tool, Not A New Algorithm

When distances **to** one target matter, do not invent a custom DP first.

Ask whether reversing edges turns the task back into a standard single-source shortest-path problem.

### 5. Bellman-Ford And Negative Cycles Need Reachability Language

The only negative cycles that matter are those reachable from the source, and for answer corruption, often those from which the destination is also reachable.

So "graph has a negative cycle" is not the right contest statement. The real question is usually:

- does a **relevant reachable** negative cycle affect the requested distances?

### 6. Floyd-Warshall Needs Tiny `n`, But Gives Clean Extensions

Floyd-Warshall is easy to dismiss because of `O(n^3)`, but on small `n` it is often the cleanest route for:

- all-pairs distances
- transitive closure
- path existence + path cost hybrids
- negative-cycle influence between many pairs

### 7. Shortest Paths Is Often A Base Layer

Many advanced problems do not end with distances. They start there.

Examples:

- shortest path + path counting
- shortest path + one coupon / one discount
- shortest path + reconstruction under constraints

The point of this family page is to help you choose the correct base layer first.

## Practice Archetypes

The most common shortest-path-flavored tasks are:

- **unit-cost shortest path**
- **nonnegative weighted shortest path**
- **negative-edge shortest path**
- **distance-to-target preprocessing via reverse graph**
- **shortest path as a subroutine for later DP / reconstruction**

The strongest contest smell is:

- additive path cost
- local edge/state transitions
- and a weight model that tells you which relaxation order is valid

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Primary / course:

- [MIT 6.006 Lecture 15: Shortest Paths I](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-fall-2011/7a2abc9bc568c743404e85e85cf6dc59_MIT6_006F11_lec15.pdf)
- [CMU 15-210 Recitation 11: Shortest Paths, Dijkstra, and Bellman-Ford](https://www.cs.cmu.edu/afs/cs/academic/class/15210-s15/www/recitations/rec11.pdf)
- [Stanford CS106B: Graph Shortest Path Algorithms](https://web.stanford.edu/class/archive/cs/cs106b/cs106b.1206/lectures/dijkstra/)

Reference:

- [CP-Algorithms: Dijkstra](https://cp-algorithms.com/graph/dijkstra.html)
- [CP-Algorithms: 0-1 BFS](https://cp-algorithms.com/graph/01_bfs.html)
- [CP-Algorithms: Bellman-Ford](https://cp-algorithms.com/graph/bellman_ford.html)

Practice:

- [CSES Graph Algorithms](https://cses.fi/problemset/)

Repo anchors:

- practice ladder: [Shortest paths ladder](../../../practice/ladders/graphs/shortest-paths/README.md)
- practice note: [Message Route](../../../practice/ladders/graphs/bfs-dfs/messageroute.md)
- practice note: [QOS](../../../practice/ladders/graphs/shortest-paths/qos.md)
- starter template: [bfs.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bfs.cpp)
- starter template: [zero-one-bfs.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/zero-one-bfs.cpp)
- starter template: [dijkstra.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dijkstra.cpp)
- starter template: [bellman-ford.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bellman-ford.cpp)
- notebook refresher: [Graph cheatsheet](../../../notebook/graph-cheatsheet.md)

## Related Topics

- [BFS And DFS](../bfs-dfs/README.md)
- [Graph Modeling](../graph-modeling/README.md)
- [Flow](../flow/README.md)
- [Minimum Spanning Tree](../mst/README.md)
