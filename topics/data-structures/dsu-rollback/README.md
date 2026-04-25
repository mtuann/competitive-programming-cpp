# DSU Rollback / Offline Dynamic Connectivity

DSU rollback is the first serious answer when the problem still looks like connectivity,
but the timeline now contains **deletions**.

Plain [DSU](../dsu/README.md) is built for:

- merge-only connectivity
- monotonically growing components
- path compression plus union by size/rank

That is exactly why it breaks on:

- remove this edge
- answer after every add/remove event
- undo the changes from one branch of an offline recursion

The repair is not "plain DSU with one more helper."

It is a different lane with two linked moves:

1. use a **rollback-friendly DSU**
2. turn add/remove events into **edge-active time intervals**, then traverse a segment tree over time

This topic is best learned as a bridge between:

- [DSU](../dsu/README.md)
- [Offline Tricks](../offline-tricks/README.md)

## At A Glance

- **Use when:** the statement asks connectivity or component counts under edge additions and deletions, but the whole timeline is known in advance
- **Core worldview:** do not maintain the graph online; instead, assign each edge to the time interval where it is active, batch those intervals onto a segment tree over time, and use rollback DSU while DFSing that tree
- **Main tools:** union by size without normal path compression, snapshots, rollback stack, edge lifetime intervals `[l, r)`, segment tree over time
- **Typical complexity:** `O((m + q) log q log n)` with the safe repo starter
- **Main trap:** modeling the lifetime interval wrong, or sneaking ordinary path compression into a rollback DSU

Strong contest signals:

- "create edge", "remove edge", "how many components now?"
- all events are given first
- the online dynamic-connectivity version feels much harder than the intended difficulty
- the answer is needed after each step, but the whole timeline is still static input

Strong anti-cues:

- the problem is truly online or interactive
- deletions must be handled immediately without knowing future events
- the real question is path aggregate / shortest path / subtree data, not connectivity
- only additions exist, so plain [DSU](../dsu/README.md) already solves it

## Prerequisites

- [DSU](../dsu/README.md)
- [Offline Tricks](../offline-tricks/README.md)

Helpful neighboring topics:

- [Graph Modeling](../../graphs/graph-modeling/README.md)
- [Trees](../../graphs/trees/README.md) only for understanding segment-tree-over-time traversal structure

## Problem Model And Notation

Assume we have:

- `n` vertices
- some initial edges
- `q` events

We care about the graph state:

- before any event
- and after every event

It is cleanest to index these graph states by:

$$
t \in \{0, 1, \dots, q\},
$$

where state `t` means:

- the graph **after** the first `t` events

So:

- `t = 0` is the initial graph
- `t = q` is the final graph

For each edge `e`, define its active lifetime as a half-open interval:

$$
[l_e, r_e)
$$

meaning:

- edge `e` is present in every graph state `t` with `l_e \le t < r_e`

This half-open convention is the cleanest way to model:

- initial edges as starting at `0`
- created edges as starting right after the create event
- removed edges as stopping exactly at the removal state

## From Brute Force To The Right Idea

### Brute Force: Recompute Connectivity After Every Event

The direct approach is:

- replay events one by one
- after each step, run DFS/BFS or rebuild connectivity somehow

This is far too slow at `n, q = 10^5`.

The underlying reason is:

- deletions destroy the monotone merge-only structure that plain DSU relies on

### Why Plain DSU Stops Working

Plain DSU succeeds because components only merge.

Once an edge disappears, components may split.

Ordinary DSU has no operation for:

```text
undo this union
```

and normal path compression makes the forest shape even harder to reverse safely.

So if you keep thinking in input order, you are forced into fully dynamic connectivity, which is a much stronger topic.

### The Key Offline Move

If all events are known in advance, each edge is not really "created and deleted repeatedly."

It is:

- active on one or more time intervals

So the real question becomes:

```text
how do we answer all graph states t if we know exactly which edges are alive during which time intervals?
```

### The Second Structural Observation

A segment tree over time lets us store:

- each edge on all time-tree nodes whose segments are fully covered by that edge's active interval

Then every edge is copied only:

$$
O(\log q)
$$

times.

During a DFS of that time tree:

- entering a node means "apply all edges that are active for this whole time segment"
- leaving a node means "undo those unions"

That is exactly what rollback DSU is built for.

### Why Rollback DSU, Not Path Compression DSU

Rollback needs to undo state **exactly**.

That means every parent/size change must be reversible.

Ordinary path compression does many implicit parent rewrites during `find`, which is excellent for plain DSU but hostile to exact rollback.

So the standard safe tradeoff is:

- keep **union by size**
- drop ordinary path compression

Then the forest remains shallow enough:

$$
O(\log n)
$$

per `find`, and every merge can be undone by popping one recorded change.

## Core Invariants And Why They Work

### 1. Rollback DSU Represents One Current Connectivity Snapshot

At any moment during the DFS over time, the DSU should represent:

- exactly the edges that were added on the current recursion path

This means the DSU is never "approximately current."

It is the exact graph snapshot for the whole time segment owned by that DFS node.

### 2. Each Time-Tree Node Stores Edges Active For Its Entire Segment

If a node of the segment tree covers:

$$
[L, R),
$$

then every edge stored in that node must be active for **all** times in `[L, R)`.

That is why it is legal to unite those edges once when entering the node and keep them active throughout the whole subtree.

### 3. Every Edge Is Applied On O(log q) Nodes, Not Every Time Point

An interval `[l, r)` is decomposed into `O(log q)` disjoint segment-tree nodes.

So the whole offline trick is:

- do not replay an edge at every time it is alive
- replay it only on the structural nodes that cover its whole active interval

This is the main complexity win.

### 4. Snapshot / Rollback Restores The Parent State Exactly

Before entering a time-tree node, take:

```text
snap = dsu.snapshot()
```

Then apply the unions stored at this node.

After processing its children, do:

```text
dsu.rollback(snap)
```

Now the DSU is **exactly** what it was before entering the node.

That is the invariant that makes DFS over the time tree safe.

### 5. No Ordinary Path Compression

Rollback DSU usually keeps:

- `parent[root] = root`
- `size[root]`
- one stack of reversible changes

and uses union by size only.

Why?

Because a normal compressed `find(x)` silently rewrites many parent pointers.

Undoing all those rewrites correctly is much more delicate than this lane needs.

The repo starter therefore uses the safe contest contract:

- no ordinary path compression
- union by size
- one explicit rollback stack

### 6. Leaf t Means "Graph After t Events"

At a leaf corresponding to one time state `t`, the DSU now contains exactly the edges active in graph state `t`.

So a query like:

- number of connected components
- `same(u, v)`

can be answered directly at that leaf.

That is why the time indexing convention matters so much.

## Variant Chooser

### Use Plain DSU When

- edges only get added
- components only merge
- you need connectivity or root-only component metadata

That is the merge-only baseline from [DSU](../dsu/README.md).

### Use Offline Tricks Without Rollback When

- one monotone sweep key exists
- all updates only move forward
- one Fenwick / DSU / sorted pass already answers everything

Canonical examples:

- threshold sweeps
- right-endpoint sweeps
- static distinct/count queries

### Use DSU Rollback / Offline Dynamic Connectivity When

- deletions are the hard part
- the full event sequence is known first
- the state you need is still basically connectivity / component structure

This is the exact lane for:

- add edge
- remove edge
- ask component count or connectivity

### Do Not Use This Lane When

- the deletions are truly online
- the graph question is not reducible to component merges
- you need general dynamic graph data far beyond connectivity

Then the right structure is outside the intended scope of this repo wave.

## Worked Examples

### Example 1: Extracting Edge Lifetimes

Suppose states are `t = 0, 1, 2, 3, 4`.

Events:

1. add `(1, 2)`
2. add `(2, 3)`
3. remove `(1, 2)`
4. add `(4, 5)`

Then the active lifetimes are:

- `(1, 2)` active on `[1, 3)`
- `(2, 3)` active on `[2, 5)`
- `(4, 5)` active on `[4, 5)`

Why `[1, 3)` for `(1, 2)`?

- it exists after event `1`
- it no longer exists after event `3`

So it is present in graph states:

- `t = 1`
- `t = 2`

and absent from `t = 3`.

This half-open modeling is the whole foundation of the lane.

### Example 2: Segment Tree Over Time

Suppose the time axis is `[0, 5)`.

An edge active on `[1, 5)` is not copied to leaves `1, 2, 3, 4` separately.

Instead it is assigned to the `O(log q)` segment-tree nodes whose union is exactly `[1, 5)`.

Then during DFS:

- when you enter such a node, unite its edge once
- all descendant times automatically inherit that edge
- when you leave the node, rollback removes its effect

This is why the whole algorithm stays near-logarithmic.

### Example 3: Why Union By Size Alone Is Enough

Suppose we repeatedly attach the smaller component under the larger one.

Whenever a node's depth increases by `1`, the size of the component above it at least doubles.

So one node's depth can increase only:

$$
O(\log n)
$$

times.

That is the rollback-friendly substitute for path compression:

- weaker than plain DSU asymptotically
- much easier to undo exactly

### Example 4: Dynamic Connectivity Components

In [Dynamic Connectivity](https://cses.fi/problemset/task/2133), the query at every state is:

```text
how many connected components exist now?
```

Rollback DSU tracks this with one integer:

```text
components
```

Each successful union decrements it by `1`.

Each rollback of that union increments it by `1`.

So the leaf answer is immediate once the DSU state is correct.

## Algorithm And Pseudocode

### Step 1: Convert The Timeline Into Active Intervals

```text
active_since[edge] = start time when this edge became alive

put all initial edges in the map with start time 0

for event i from 1 to q:
    if event i adds edge e:
        active_since[e] = i
    else if event i removes edge e:
        add interval [active_since[e], i) for e
        erase e from active_since

for each edge still alive at the end:
    add interval [active_since[e], q + 1)
```

### Step 2: Place Each Interval On The Segment Tree Over Time

```text
add_interval(node, L, R, ql, qr, edge):
    if [ql, qr) and [L, R) do not intersect:
        return
    if [ql, qr) fully covers [L, R):
        bucket[node].push(edge)
        return
    recurse into children
```

### Step 3: DFS With Rollback DSU

```text
dfs(node, L, R):
    snap = dsu.snapshot()

    for edge in bucket[node]:
        dsu.unite(edge.u, edge.v)

    if R - L == 1:
        ans[L] = dsu.components
    else:
        dfs(left child)
        dfs(right child)

    dsu.rollback(snap)
```

The correctness comes from two facts:

- every edge stored at a node is active for the whole segment of that node
- rollback restores the DSU state before we leave that segment

## Implementation Notes

### 1. Normalize Undirected Edges

Always store an undirected edge as:

```text
(min(u, v), max(u, v))
```

Otherwise create/remove events on the same edge may not match in your map.

### 2. Use Half-Open Time Intervals

This lane becomes much easier if you commit to:

$$
[l, r)
$$

everywhere.

Then:

- initial graph -> start at `0`
- add at event `i` -> start at `i`
- remove at event `i` -> end at `i`
- final alive edge -> end at `q + 1`

### 3. Do Not Hide Rollback State

A safe rollback DSU starter should expose:

- `snapshot()`
- `rollback(snap)`
- current `components`

Do not bury the state so deeply that you cannot reason about what DFS over time is doing.

### 4. Path Compression Is The Wrong Default Here

For this lane, trust:

- union by size
- reversible stack

before trying any clever reversible compression tricks.

The repo starter deliberately favors correctness and transparency over squeezing out a tiny asymptotic constant.

### 5. Build State t, Not Event i

The answer array usually has length:

$$
q + 1
$$

because it includes:

- the initial graph before event `1`
- then the graph after every event

This off-by-one is the single most common modeling bug in the flagship problem.

## Practice Archetypes

The most common problems in this lane are:

- **component count under add/remove timeline**
- **connectivity queries under add/remove timeline**
- **offline dynamic graph queries where the maintained structure is still DSU-shaped**
- **component-value variants built on top of rollback DSU**

Strong contest smells include:

- "initial edges + add/remove events"
- "after every event"
- "online version looks much harder than expected"
- "deletions are the only thing blocking plain DSU"

## References

- [CP-Algorithms: Deleting from a data structure in $O(T(n)\\log n)$](https://cp-algorithms.com/data_structures/deleting_in_log_n.html)
- [USACO Guide: Offline Deletion](https://usaco.guide/adv/offline-del)
- [CSES: Dynamic Connectivity](https://cses.fi/problemset/task/2133/)
- [Library Checker: Dynamic Graph Vertex Add Component Sum](https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum)

## Repo Anchors

- [DSU Rollback ladder](../../../practice/ladders/data-structures/dsu-rollback/README.md)
- [DSU Rollback hot sheet](../../../notebook/dsu-rollback-hot-sheet.md)
- [Dynamic Connectivity note](../../../practice/ladders/data-structures/dsu-rollback/dynamicconnectivity.md)
- [starter template](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/dsu-rollback-dynamic-connectivity.cpp)
- [DSU](../dsu/README.md)
- [Offline Tricks](../offline-tricks/README.md)
