# Bridges, Articulation Points, And Biconnected Components

This family is the undirected-graph `low-link` lane.

It answers questions like:

- which **edge** is critical?
- which **vertex** is critical?
- how do we compress the graph after removing all bridge edges?
- how do we turn articulation structure into a **block-cut tree**?

So this topic should be learned as:

- one DFS tree
- one `tin / low` invariant
- several different structural tests built on top of the same invariant

That is why this is one of the highest-leverage graph families after BFS / DFS, SCC, and trees.

## At A Glance

- **Use when:** the graph is undirected and the statement asks for critical roads, critical cities, "still connected after removing one vertex/edge", `2`-edge / `2`-vertex connectivity, or a block-cut style reduction
- **Core worldview:** one DFS tree plus `low-link` values tells you whether a subtree can reconnect upward without using its parent edge
- **Main tools:** DFS tree, entry times `tin`, low-link values `low`, root special case, optional edge stack for vertex-biconnected components
- **Typical complexity:** `O(n + m)`
- **Main trap:** mixing up the strict bridge test `>` with the articulation test `>=`, or forgetting the root special case

## Prerequisites

- [BFS And DFS](../bfs-dfs/README.md)

Helpful neighboring topics:

- [Graph Modeling](../graph-modeling/README.md)
- [Topological Sort And SCC](../scc-toposort/README.md)
- [Trees](../trees/README.md) once bridge trees or block-cut reductions become the next object
- [Heavy-Light Decomposition](../hld/README.md) for later block-cut-tree or bridge-tree work

## Problem Model And Notation

Let:

$$
G = (V, E)
$$

be an undirected graph.

Run DFS on each connected component and define:

- `tin[v]`: the DFS entry time of vertex `v`
- `low[v]`: the smallest entry time reachable from `v` or its DFS subtree using:
  - zero or more tree edges downward, then
  - at most one back edge upward

This is the one quantity that powers the whole lane.

The intuition is:

- `tin[v]` says when `v` entered the DFS tree
- `low[v]` says how high the subtree under `v` can reconnect without using the parent edge of `v`

## Low-Link Playground

<div class="visual-card" data-lowlink-visualizer>
  <p class="visual-caption">
    Inspect one DFS child subtree at a time. The point is not to replay DFS mechanically, but to see which back edge witnesses
    a low-link escape, and when the subtree is forced to stay attached only through its parent edge.
  </p>
  <div class="chip-row">
    <span class="chip">Blue nodes: current child subtree</span>
    <span class="chip">Gold nodes: ancestor chain</span>
    <span class="chip">Red edge: tree edge under test</span>
    <span class="chip">Green dashed edge: witness back edge</span>
  </div>
  <div class="visual-controls">
    <label>
      Inspect DFS child
      <select data-role="child">
        <option value="2">child 2 under parent 1</option>
        <option value="3">child 3 under parent 2</option>
        <option value="4" selected>child 4 under parent 2</option>
        <option value="5">child 5 under parent 4</option>
        <option value="6">child 6 under parent 5</option>
        <option value="7">child 7 under parent 4</option>
      </select>
    </label>
    <button type="button" data-role="inspect">Inspect subtree</button>
    <button type="button" data-role="reset">Reset to bridge case</button>
  </div>
  <div class="visual-grid">
    <div class="visual-panel">
      <div class="visual-surface graph-visual-surface" data-role="canvas"></div>
    </div>
    <div class="visual-panel">
      <h4>What to watch</h4>
      <div class="visual-stats">
        <div class="visual-stat">
          <strong>Invariant</strong>
          <div data-role="invariant"></div>
        </div>
        <div class="visual-stat">
          <strong>Current tree edge</strong>
          <code data-role="focus"></code>
        </div>
        <div class="visual-stat">
          <strong>Current subtree</strong>
          <code data-role="subtree"></code>
        </div>
        <div class="visual-stat">
          <strong>Witness back edge</strong>
          <code data-role="witness"></code>
        </div>
        <div class="visual-stat">
          <strong>Bridge test</strong>
          <code data-role="bridge"></code>
        </div>
        <div class="visual-stat">
          <strong>Articulation consequence</strong>
          <code data-role="articulation"></code>
        </div>
      </div>
      <p class="visual-note" data-role="note"></p>
    </div>
  </div>
</div>

### Visual Reading Guide

What to notice:

- every inspection is relative to one fixed DFS tree edge `(parent, child)`; the only question is whether the blue child subtree can touch the gold ancestor chain without using that red edge
- when a green back edge exists, `low[child]` drops to the corresponding ancestor level; when no such edge exists, the subtree is trapped and the red edge becomes a bridge

Why it matters:

- this is the shortest route from memorizing `low[child] > tin[parent]` to actually trusting why that inequality means the subtree has no alternate escape upward
- it also makes the `>` versus `>=` split feel structural instead of arbitrary: bridge tests ask whether the edge survives, articulation tests ask whether the parent vertex still separates the child subtree

Code bridge:

- the labels on each node are the exact `tin` and `low` values produced by the low-link DFS
- the widget is reading the same tests as the implementation: `low[to] > tin[v]` for bridges, `low[to] >= tin[v]` for non-root articulation points, and a separate root-child-count rule for the DFS root

Boundary:

- this visual is for undirected low-link only; directed reachability splits into [SCC](../scc-toposort/README.md), not bridge/articulation logic
- the graph is intentionally fixed so the low-link meaning stays legible; real problems compute these values dynamically during DFS rather than selecting from precomputed cases

## From Brute Force To The Right Idea

### Brute Force

If the statement asks:

- which roads are necessary?
- which cities are necessary?
- after deleting one edge/vertex, is the graph still connected?

the brute-force instinct is:

- remove each edge or vertex
- run connectivity check again

That is:

- `O(m * (n + m))` for edge checks
- `O(n * (n + m))` for vertex checks

which is usually far too slow.

### First Shift: A DFS Tree Already Encodes Separation

When DFS goes from `v` to a child `to`, there are only two ways for the subtree of `to` to stay attached to the rest of the graph:

1. the tree edge `(v, to)` itself
2. some back edge from inside that subtree to `v` or one of `v`'s ancestors

So the real question is not:

- "what happens if I delete this road?"

It is:

- "can this subtree reconnect upward without that tree edge?"

That is exactly what `low[to]` tells us.

### Second Shift: One Invariant, Many Tests

Once `low` is available:

- `low[to] > tin[v]` means `(v, to)` is a **bridge**
- `low[to] >= tin[v]` means `v` separates that child subtree from higher ancestors, so `v` is an **articulation point** unless `v` is the DFS root
- if you pop DFS edges whenever `low[to] >= tin[v]`, you obtain **vertex-biconnected components**

So the family is not three unrelated tricks.

It is one DFS invariant plus three different interpretations.

## Core Invariant And Why It Works

## 1. What `low[v]` Really Means

For every vertex `v`:

$$
low[v] = \min\Big(
tin[v],
\; tin[p] \text{ for back edges } (v', p) \text{ from the subtree of } v,
\; low[to] \text{ for DFS children } to
\Big)
$$

The key semantic meaning is:

```text
low[v] is the highest ancestor level that the subtree of v can still touch
without using the parent edge of v.
```

If `low[v]` stays large, that subtree is trapped lower in the DFS tree.

If `low[v]` reaches a small entry time, that subtree has another route upward.

## 2. Bridge Criterion

Suppose `(v, to)` is a DFS tree edge.

Then:

$$
low[to] > tin[v]
$$

if and only if `(v, to)` is a bridge.

Why?

- `low[to] > tin[v]` means the subtree of `to` cannot reach `v` or any ancestor of `v` by a back edge
- so the only attachment of that subtree to the rest of the component is exactly the tree edge `(v, to)`
- deleting that edge disconnects the graph

If instead:

$$
low[to] \le tin[v],
$$

then the subtree already has another route upward, so the edge is not a bridge.

This is the strict test:

```text
bridge <=> low[child] > tin[parent]
```

## 3. Articulation Criterion

For a non-root DFS vertex `v`, if some child `to` satisfies:

$$
low[to] \ge tin[v],
$$

then `v` is an articulation point.

Why is the comparison now `>=` instead of `>`?

Because if:

$$
low[to] = tin[v],
$$

then the subtree can reconnect upward only through `v` itself, not to a strict ancestor of `v`.

That still means:

- after deleting `v`, the subtree of `to` gets separated from the vertices above `v`

So:

```text
cut vertex for non-root <=> some child has low[child] >= tin[v]
```

## 4. Root Special Case

The DFS root has no parent, so the previous test is not enough.

The root is an articulation point if and only if it has more than one DFS child.

Why?

- each root child starts a separate DFS subtree
- if the root has at least two children, those subtrees only meet through the root
- deleting the root separates them

If the root has only one child, deleting it does not split the already-visited part into multiple pieces.

This root case is the most common low-link bug.

## 5. Edge-Biconnected Components

If you remove all bridges, each remaining connected component is a **2-edge-connected component**:

- no single edge deletion can disconnect it

So for edge-biconnected structure, the simplest route is often:

1. find all bridges
2. ignore or contract them
3. flood-fill the remaining graph

This gives a bridge tree / bridge forest view.

## 6. Vertex-Biconnected Components And Block-Cut Trees

For **vertex-biconnected components** (blocks), bridges are not enough.

Articulation points can belong to multiple blocks, so plain contraction is not enough.

The standard DFS-stack route is:

1. push DFS edges onto a stack
2. whenever a tree edge `(v, to)` satisfies `low[to] >= tin[v]`
3. pop until `(v, to)` appears
4. those popped edges form one block

Then:

- each block becomes one node
- each articulation point becomes one node
- connect articulation-node `<->` block-node when the articulation belongs to that block

This is the **block-cut tree**.

That is the main next-layer structure built on top of articulation points.

## Family Chooser

| If the statement asks... | Main object | First test / structure | Open first |
| --- | --- | --- | --- |
| which edges are critical? | bridges | `low[child] > tin[parent]` | bridge-first low-link |
| which vertices are critical? | articulation points | `low[child] >= tin[parent]` + root case | articulation low-link |
| contract everything that survives one edge deletion | 2-edge-connected components | remove bridges, then compress | bridge-first low-link |
| answer queries about avoiding a cut vertex / build block-cut tree | vertex-BCC / block-cut tree | edge stack + articulation structure | BCC / block-cut route |

Use this family only for **undirected** graphs.

If the graph is directed and the statement smells like mutual reachability:

- reopen [Topological Sort And SCC](../scc-toposort/README.md)

## Worked Examples

### 1. Necessary Roads

Statement shape:

- connected undirected graph
- output all roads whose removal disconnects the graph

This is the purest bridge test.

For each DFS tree edge `(v, to)`:

- if `low[to] > tin[v]`, print it

Nothing more is needed.

This is why [Necessary Roads](../../../practice/ladders/graphs/bridges-articulation/necessaryroads.md) is the flagship bridge note for this lane.

### 2. Necessary Cities

Statement shape:

- connected undirected graph
- output all vertices whose removal disconnects some other pair

Now we use:

- for non-root `v`: some child with `low[to] >= tin[v]`
- for root `v`: at least two DFS children

This is the articulation-point branch of the same DFS.

### 3. Forbidden Cities

Statement shape:

- many queries `(a, b, c)`
- ask whether `a` can still reach `b` without visiting city `c`

Here raw articulation detection is not enough.

The useful route is:

1. build vertex-biconnected components
2. build the block-cut tree
3. reduce the query to tree reasoning, often with LCA

This is the best example of why BCC is not just "articulation points but longer."

It is a new structure layer.

## Complexity And Tradeoffs

- one DFS pass: `O(n + m)`
- bridge list: `O(n + m)`
- articulation list: `O(n + m)`
- vertex-BCC via edge stack: still `O(n + m)`

Tradeoffs:

- bridges only: simplest and most robust
- bridges + articulation points: still standard contest-core
- full block-cut tree: stronger but more implementation-heavy

If the task only wants bridges, do not overbuild BCC machinery.

## Algorithm And Pseudocode

```text
run DFS on every connected component

on entry:
    tin[v] = low[v] = timer++

for each edge (v, to):
    if edge is the parent edge:
        skip
    else if to is unvisited:
        DFS(to)
        low[v] = min(low[v], low[to])

        if low[to] > tin[v]:
            (v, to) is a bridge

        if v is not root and low[to] >= tin[v]:
            v is an articulation point

        if building vertex-BCC and low[to] >= tin[v]:
            pop edge stack until (v, to)

    else if to is an ancestor:
        low[v] = min(low[v], tin[to])

after loop:
    if v is root and child_count > 1:
        v is an articulation point
```

## Implementation Notes

- Use **edge ids**, not just parent vertex, if multi-edges are possible.
- Bridge test is `>`; articulation test is `>=`.
- For undirected DFS, only ancestor back edges should update `low` through `tin[to]`.
- The root articulation rule is separate from the non-root rule.
- If you build vertex-BCCs, pop an **edge stack**, not a vertex stack.
- A block-cut tree duplicates articulation points across blocks; simple contraction is not enough.

## Practice Archetypes

The most common problems in this family are:

- **print all bridges**
- **print all articulation points**
- **count or compress 2-edge-connected components**
- **build a bridge tree**
- **answer path/avoidance queries through a block-cut tree**

The strongest smell is:

- "after deleting one road/city, something disconnects"

## References And Repo Anchors

- [CP-Algorithms - Finding bridges in a graph in O(N+M)](https://cp-algorithms.com/graph/bridge-searching.html)
- [CP-Algorithms - Finding articulation points in O(N+M)](https://cp-algorithms.com/graph/cutpoints.html)
- [USACO Guide - BCCs and 2CCs](https://usaco.guide/adv/BCC-2CC)
- [OI Wiki - Biconnected components](https://en.oi-wiki.org/graph/bcc/)
- [CSES - Necessary Roads](https://cses.fi/problemset/task/2076)
- [CSES - Necessary Cities](https://cses.fi/problemset/task/2077)
- [CSES - Forbidden Cities](https://cses.fi/problemset/task/1705)

Repo anchors:

- flagship note -> [Necessary Roads](../../../practice/ladders/graphs/bridges-articulation/necessaryroads.md)
- starter -> [bridges-articulation-lowlink.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bridges-articulation-lowlink.cpp)
- retrieval sheet -> [Low-Link hot sheet](../../../notebook/lowlink-hot-sheet.md)
- graph-family chooser -> [Graph cheatsheet](../../../notebook/graph-cheatsheet.md)
- simpler traversal prerequisite -> [BFS And DFS](../bfs-dfs/README.md)

## Related Topics

- [Trees](../trees/README.md)
- [Heavy-Light Decomposition](../hld/README.md)
- [Topological Sort And SCC](../scc-toposort/README.md)

Stay in this family when the graph is undirected and the cut structure is the point.

Leave it when:

- the graph is directed -> go to SCC
- the structure is a tree already -> go to tree topics directly
- the task becomes online or dynamic -> this static low-link pass is no longer enough
