# Trees

Tree problems feel easier than general graph problems because trees give you one structural gift for free:

- between any two vertices, there is exactly one simple path

That single fact eliminates a huge amount of ambiguity.

It is why notions like:

- parent
- subtree
- ancestor
- reroot
- diameter
- path through LCA

become clean instead of messy.

This page is not about one algorithm.

It is the family page that teaches what tree structure gives you *before* you specialize into:

- [Euler Tour / Subtree Queries](../euler-tour-subtree/README.md)
- [LCA](../lca/README.md)
- [Virtual Tree / Auxiliary Tree](../virtual-tree/README.md)
- [Tree DP](../../dp/tree-dp/README.md)
- [Heavy-Light Decomposition](../hld/README.md)

## At A Glance

- **Use when:** the graph is a tree or can be rooted into a tree-like hierarchy
- **Core worldview:** unique paths make rooted structure, subtree structure, and path formulas stable
- **Main tools:** rooting, parent/depth, subtree sizes, Euler tour order, diameter, reroot perspective
- **Typical complexity:** most structural preprocessing is `O(n)`
- **Main trap:** mixing rooted and unrooted viewpoints mid-solution, or jumping to a heavy technique before extracting the simple tree invariant first

## Prerequisites

- [Graph Modeling](../graph-modeling/README.md)
- [BFS And DFS](../bfs-dfs/README.md)

Helpful neighboring topics:

- [Euler Tour / Subtree Queries](../euler-tour-subtree/README.md)
- [LCA](../lca/README.md)
- [Virtual Tree / Auxiliary Tree](../virtual-tree/README.md)
- [Tree DP](../../dp/tree-dp/README.md)
- [Heavy-Light Decomposition](../hld/README.md)

## Problem Model And Notation

Let:

$$
T = (V, E)
$$

be a tree with:

$$
|E| = |V| - 1.
$$

After choosing a root `r`, every node `u` gains:

- `parent[u]`
- `depth[u]`
- `children[u]`
- `size[u]`: the number of vertices in the subtree of `u`

This rooted view is the standard coordinate system for tree algorithms.

The unrooted view is still useful for:

- diameter
- center / eccentricity style reasoning
- symmetry arguments

Strong tree work is really about switching between these two views at the right time.

## From Brute Force To The Right Idea

### Brute Force: Treat The Tree Like A Generic Graph Every Time

A beginner often re-solves each tree query from scratch:

- run DFS again
- rediscover parents again
- walk paths directly
- not store subtree facts

That works only for tiny inputs.

### The First Shift: Root The Tree Once

Many tree problems become much simpler after one traversal computes:

- `parent`
- `depth`
- subtree sizes

This is often the real first algorithm.

After that, a lot of later logic becomes algebra on these arrays.

### The Second Shift: The Unique Path Property Does The Hard Work

In a general graph, multiple paths create ambiguity.

In a tree:

- the path between `u` and `v` is unique
- "ancestor" becomes meaningful once rooted
- subtree intervals do not overlap in unexpected ways

That is why so many formulas on trees are simple.

### The Third Shift: Trees Are A Launchpad, Not A Single Technique

Once the rooted facts are available, you can branch into specialized tools:

- subtree interval queries -> [Euler Tour / Subtree Queries](../euler-tour-subtree/README.md)
- subtree aggregation by merging child states -> [Tree DP](../../dp/tree-dp/README.md)
- ancestor queries -> [LCA](../lca/README.md)
- many path queries -> [Heavy-Light Decomposition](../hld/README.md)

So the point of this page is to make those later topics feel like natural extensions of the same structure.

## Core Invariants And Why They Work

## 1. Unique Path Invariant

The defining tree fact is:

```text
Between any two vertices, there is exactly one simple path.
```

This powers almost every later argument:

- if `u` is in the subtree of `v`, every path from `u` to the root passes through `v`
- distances decompose cleanly through LCAs
- subtree aggregation does not double-count across independent branches

## 2. Rooted Parent/Depth Invariant

After one BFS or DFS from the root:

- every non-root node has exactly one parent
- `depth[u]` is well-defined

That is enough to turn an undirected tree into a directed parent-child hierarchy for reasoning.

## 3. Subtree Size Invariant

For a rooted tree:

$$
\mathrm{size}[u] = 1 + \sum_{v \text{ child of } u} \mathrm{size}[v].
$$

This is the first nontrivial tree invariant most later techniques depend on.

It underlies:

- heavy-child choice in HLD
- many greedy-on-tree arguments
- reroot formulas
- subtree cost aggregation

## 4. Euler Tour Interval Invariant

If DFS records entry times `tin[u]`, then all vertices in the subtree of `u` occupy one contiguous DFS-order interval.

This is one of the most useful tree reductions:

- subtree query on a tree
- becomes interval query on an array

It is the bridge from trees to range structures.

## 5. Diameter Two-DFS/BFS Invariant

If you run BFS/DFS from any node `s` and reach a farthest node `x`, then `x` is an endpoint of some diameter.

Running BFS/DFS again from `x` reaches a farthest node `y`, and:

$$
\mathrm{dist}(x, y)
$$

is the tree diameter.

This works because trees have unique paths and no cycles to create competing shortest-route structures.

## 6. Rerooting Changes Perspective, Not The Tree

Many tree problems ask:

- what if every node were treated as the root?

The important viewpoint is:

- the tree does not change
- only the decomposition of "inside subtree" vs "outside subtree" changes

That is the mental bridge to reroot DP.

## Variant Chooser

### Root The Tree And Stop There When

- you only need parent, depth, subtree size, or one simple traversal invariant

### Use Diameter Logic When

- the target is longest path, farthest node, or tree center style reasoning

### Use Euler Tour Flattening When

- queries are subtree-based
- contiguous subtree intervals on an array are enough
- exact next stop: [Euler Tour / Subtree Queries](../euler-tour-subtree/README.md)

### Use LCA When

- the problem asks for many ancestor or path-structure queries

### Use Tree DP When

- each node combines information from children

### Use HLD When

- the tree is static
- updates or queries are on arbitrary paths

## Worked Examples

### Example 1: Subtree Sizes

This is the first rooted-tree recurrence everyone should trust:

$$
\mathrm{size}[u] = 1 + \sum \mathrm{size}[child].
$$

It is not just a warm-up.

It is the quantity used later in:

- [Heavy-Light Decomposition](../hld/README.md)
- many greedy contractions on trees
- reroot transitions

### Example 2: Diameter

Pick any node `s`.

Run BFS/DFS to find a farthest node `x`.

Run BFS/DFS again from `x` to find a farthest node `y`.

Then the path from `x` to `y` is a diameter.

This is one of the cleanest examples of how the unique-path property makes a graph problem much simpler on trees.

### Example 3: Trees As A Base Layer For Harder Problems

The repo has several notes where the first step is simply "extract the rooted-tree structure correctly," and the harder idea comes later:

- [Subtree Queries](../../../practice/ladders/graphs/euler-tour-subtree/subtreequeries.md)
- [MTREECOL](../../../practice/ladders/graphs/trees/mtreecol.md)
- [VMWTREE](../../../practice/ladders/graphs/trees/vmwtree.md)

In both cases, solving the problem begins with a stable rooted or path decomposition view of the tree.

## Algorithms And Pseudocode

### Basic Rooting DFS

```text
dfs(u, p):
    parent[u] = p
    size[u] = 1
    for v in adj[u]:
        if v == p:
            continue
        depth[v] = depth[u] + 1
        dfs(v, u)
        size[u] += size[v]
```

### Diameter Skeleton

```text
x = farthest vertex from any start s
y = farthest vertex from x
diameter = dist(x, y)
```

### Euler Tour Skeleton

```text
timer = 0
dfs(u, p):
    tin[u] = timer
    timer += 1
    for v in children:
        dfs(v, u)
    tout[u] = timer
```

Then subtree `u` corresponds to:

$$
[\mathrm{tin}[u], \mathrm{tout}[u)).
$$

## Implementation Notes

- In undirected trees, always skip the parent edge in DFS/BFS.
- Decide early whether your reasoning is rooted or unrooted.
- Store `parent`, `depth`, and `size` even if the current problem seems simple; they often become useful one page later.
- Recursive DFS is natural for trees, but iterative traversals may still be safer for long chains.
- For subtree-based reductions, Euler tour order is often the cleanest bridge to arrays.

## Practice Archetypes

You should strongly suspect this tree family page when you see:

- connected graph with `n - 1` edges
- subtree or ancestor language
- path uniqueness
- repeated queries on the same fixed tree

Repo anchors:

- [MTREECOL](../../../practice/ladders/graphs/trees/mtreecol.md)
- [VMWTREE](../../../practice/ladders/graphs/trees/vmwtree.md)

Starter pieces:

- [bfs.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bfs.cpp)
- [dfs-iterative.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dfs-iterative.cpp)
- [tree-dp-subtree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/tree-dp-subtree.cpp)
- [tree-dp-rerooting.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/tree-dp-rerooting.cpp)

Notebook refresher:

- [Graph cheatsheet](../../../notebook/graph-cheatsheet.md)

## References And Repo Anchors

Course / notes style:

- [UTA CSE 3318 Notes: Rooted Trees](https://ranger.uta.edu/~weems/NOTES3318/notes11.pdf)
- [USACO Guide](https://usaco.guide/)
- [Competitive Programmer's Handbook](https://usaco.guide/CPH.pdf)

Practice / repo anchors:

- [Trees ladder](../../../practice/ladders/graphs/trees/README.md)
- [MTREECOL](../../../practice/ladders/graphs/trees/mtreecol.md)
- [VMWTREE](../../../practice/ladders/graphs/trees/vmwtree.md)

## Related Topics

- [LCA](../lca/README.md)
- [Tree DP](../../dp/tree-dp/README.md)
- [Heavy-Light Decomposition](../hld/README.md)
- [BFS And DFS](../bfs-dfs/README.md)
