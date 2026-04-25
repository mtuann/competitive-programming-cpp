# LCA

Lowest Common Ancestor is the standard preprocessing layer for repeated path and ancestor queries on a rooted tree.

It is worth learning as more than "that one binary lifting trick", because once LCA becomes automatic, several other formulas become immediate:

- tree distance
- ancestor checks
- path decomposition through a meeting point
- "move upward by `k` steps"
- many later tree techniques, especially [Virtual Tree / Auxiliary Tree](../virtual-tree/README.md) and [Heavy-Light Decomposition](../hld/README.md)

This page treats LCA as a reusable tree-query toolkit, not just one function.

## At A Glance

Reach for LCA when:

- the input is a rooted tree, or can be rooted once
- there are many queries about two vertices
- the query asks about common ancestor, distance, or path structure
- upward movement by powers of two sounds natural

Strong contest triggers:

- "lowest common ancestor"
- "lowest common boss"
- "distance between two tree nodes"
- "is `u` an ancestor of `v`?"
- "`k`-th ancestor of a node"
- "split the path `u -> v` through one meeting point"

Strong anti-cues:

- there is only one query, so a simple climb may be enough
- the real task is subtree aggregation, not path ancestry
- the path query needs online updates or associative aggregates, which is more [HLD](../hld/README.md) than plain LCA
- the graph is not a tree and rooting does not produce a unique-path structure

What success looks like after studying this page:

- you can define `up[k][v]` cleanly and build it without guessing
- you know why equalizing depths is the first step of `lca(u, v)`
- you can derive tree distance from LCA immediately
- you know when binary lifting is enough and when Euler-tour RMQ is worth considering
- you can treat LCA as a preprocessing layer for other tree problems

## Prerequisites

- [Trees](../trees/README.md)
- [BFS And DFS](../bfs-dfs/README.md)

Helpful neighboring topics:

- [Virtual Tree / Auxiliary Tree](../virtual-tree/README.md) when each query only marks a small subset but still needs LCAs and one compressed tree
- [Heavy-Light Decomposition](../hld/README.md) when path queries also need online updates or aggregates
- [Sparse Table](../../data-structures/sparse-table/README.md) for the Euler-tour RMQ viewpoint

## Problem Model And Notation

Let the tree be rooted at some node `root`.

We use:

- `parent[v]`: the direct parent of `v`
- `depth[v]`: the number of edges from the root to `v`

For binary lifting, define:

$$
up[k][v] = \text{the } 2^k\text{-th ancestor of } v.
$$

So:

- `up[0][v]` is the parent
- `up[1][v]` is the grandparent
- `up[2][v]` is the `4`-th ancestor
- and so on

The **lowest common ancestor** of two nodes `u` and `v` is the deepest node that is an ancestor of both.

If one node is already an ancestor of the other, then that ancestor is the answer.

## From Brute Force To The Right Idea

### Brute Force

Suppose we only have one query.

A direct method is:

1. walk from `u` to the root, marking all ancestors
2. walk from `v` to the root until you hit a marked vertex

This is easy, but costs `O(height)` or `O(n)` in a deep tree.

With many queries, that becomes too slow.

### First Observation: Trees Have Unique Paths

In a rooted tree:

- every node has one ancestor chain to the root
- any two nodes meet at exactly one deepest common ancestor

So LCA is really a question about comparing two ancestor chains efficiently.

### Second Observation: Upward Movement Can Be Decomposed Into Powers Of Two

If you want to move up `13` steps, you do not need a separate precomputed jump for `13`.

Just write:

$$
13 = 8 + 4 + 1 = 2^3 + 2^2 + 2^0.
$$

Then:

- jump by `8`
- then by `4`
- then by `1`

That is the core reason binary lifting works.

### Why LCA Reduces To Controlled Upward Jumps

If `u` and `v` are at different depths, the deeper one must climb first.

After depth equalization:

- either the two nodes are already equal, so that node is the LCA
- or they are distinct but lie at the same depth below their LCA

At that point, the right strategy is:

- try large jumps first
- only take a jump when it keeps the two nodes distinct
- stop just below the LCA

This becomes a logarithmic algorithm once powers-of-two jumps are precomputed.

## Core Invariant And Why It Works

### Invariant 1: `up[k][v]` Really Is The `2^k`-th Ancestor

The recurrence is:

$$
up[k][v] = up[k-1][\;up[k-1][v]\;].
$$

Why it is correct:

- `up[k-1][v]` moves up `2^{k-1}` steps
- applying the same jump again moves up another `2^{k-1}` steps
- total jump length is `2^k`

So the table is valid by induction on `k`.

### Invariant 2: Lifting By Bits Gives The Correct `k`-th Ancestor

Suppose we want to move node `v` upward by `dist`.

Write:

$$
dist = \sum b_k 2^k,
$$

where each `b_k` is a bit.

Then jumping on exactly those set bits moves upward by:

$$
\sum b_k 2^k = dist.
$$

That is why binary lifting is also a general `k`-th ancestor tool, not just an LCA trick.

### Invariant 3: Equalizing Depth Preserves The True LCA

Assume `depth[u] > depth[v]`.

If we lift `u` upward until:

$$
depth[u] = depth[v],
$$

then the true LCA of the original pair is still the true LCA of the new pair.

Why?

- every lifted version of `u` remains on the ancestor chain from the original `u` to the root
- the LCA must lie on that chain
- all we did was remove the unmatched suffix below the depth of `v`

So equalizing depth throws away irrelevant edges, not the answer.

### Invariant 4: Simultaneous Lifting Stops Just Below The LCA

After equalizing depths, suppose `u != v`.

We iterate `k` from large to small and do:

- if `up[k][u] != up[k][v]`, lift both nodes by `2^k`

The invariant is:

- the true LCA remains an ancestor of both current nodes
- the current nodes stay strictly below the LCA

Why this is safe:

- if `up[k][u] == up[k][v]`, then lifting by `2^k` would jump to or above the meeting point too early
- if `up[k][u] != up[k][v]`, then both jumps remain below the LCA, so we can safely take them

After the loop, the nodes are distinct children of the LCA, so:

$$
\text{LCA}(u, v) = up[0][u].
$$

### Optional Enhancement: Ancestor Checks With Euler Tour Time

Another common LCA toolbox item is:

- `tin[v]`: entry time in DFS
- `tout[v]`: exit time in DFS

Then:

$$
u \text{ is an ancestor of } v
$$

if and only if:

$$
tin[u] \le tin[v] \quad \text{and} \quad tout[v] \le tout[u].
$$

This is useful because:

- ancestor checks become `O(1)`
- one binary-lifting flavor uses those checks directly during the LCA climb

You do not strictly need `tin/tout` for binary lifting, but they are often worth carrying in the same preprocessing pass.

## Complexity And Tradeoffs

For binary lifting:

- preprocessing: `O(n log n)`
- one `k`-th ancestor query: `O(log n)`
- one LCA query: `O(log n)`
- memory: `O(n log n)`

Practical tradeoffs:

| Tool | Best when | Query time | Main tradeoff |
| --- | --- | --- | --- |
| naive ancestor climb | one or very few queries | `O(height)` | no reusable preprocessing |
| binary lifting | standard contest default for repeated tree queries | `O(log n)` | `O(n log n)` memory |
| Euler tour + RMQ | many pure LCA queries and you want very fast queries | `O(1)` after RMQ preprocessing | conceptually heavier |
| Tarjan offline LCA | all queries known in advance | near-linear total | offline-only and less reusable as a toolkit |
| HLD | path aggregates or updates matter | often `O(log^2 n)` | more machinery than plain LCA |

Rule of thumb:

- if the tree is static and you need LCA, distance, ancestor jumps, or ancestry logic, binary lifting is usually the cleanest first choice
- if the only task is raw LCA at massive query volume, Euler tour + RMQ is a strong alternative
- if the path also carries values and updates, LCA alone is not the whole solution anymore

## Variant Chooser

| Variant | Use it when | Main data kept | Where it gets awkward |
| --- | --- | --- | --- |
| plain binary lifting | repeated LCA, distance, and `k`-th ancestor queries | `depth`, `up` | `O(log n)` per query, not `O(1)` |
| binary lifting + `tin/tout` | ancestor checks are frequent too | `depth`, `up`, `tin`, `tout` | slightly more preprocessing state |
| Euler tour + RMQ | LCA is the star query and static | Euler tour, depth array, RMQ | heavier to teach and implement correctly |
| offline Tarjan LCA | all queries known in advance | DSU + DFS state | not a good general reusable contest layer |

## Worked Examples

### Example 1: `k`-th Ancestor By Bits

Suppose node `v` is at depth `20`, and we want its `13`-th ancestor.

Write:

$$
13 = 8 + 4 + 1.
$$

So we apply:

- `up[3][v]`
- then `up[2][...]`
- then `up[0][...]`

This is worth internalizing because LCA queries rely on the exact same decomposition idea.

### Example 2: Plain LCA Query

Consider this rooted tree:

```text
1
├── 2
│   ├── 4
│   └── 5
└── 3
    ├── 6
    └── 7
```

Find `lca(4, 7)`.

Depths:

- `depth[4] = 2`
- `depth[7] = 2`

They are already at the same depth.

Now inspect powers from large to small. At the smallest meaningful jump:

- parent of `4` is `2`
- parent of `7` is `3`

These are still different, so both nodes can be lifted once:

- `4 -> 2`
- `7 -> 3`

Now their parents are both `1`, so:

$$
\text{LCA}(4, 7) = 1.
$$

### Example 3: One Node Is An Ancestor Of The Other

Find `lca(2, 5)` in the same tree.

Depths differ, so lift `5` by one step:

- `5 -> 2`

Now the nodes are equal, so:

$$
\text{LCA}(2, 5) = 2.
$$

This is why every clean implementation checks:

- after depth equalization, if the nodes are equal, return immediately

### Example 4: Tree Distance From LCA

Once LCA is known, the distance formula is immediate:

$$
dist(u, v) = depth[u] + depth[v] - 2 \cdot depth[\text{lca}(u, v)].
$$

For `u = 4`, `v = 7`:

$$
dist(4, 7) = 2 + 2 - 2 \cdot 0 = 4.
$$

This one formula is responsible for a large fraction of "tree distance" problems becoming trivial after LCA preprocessing.

### Example 5: Why LCA Is Not Yet Enough For Path Aggregates

Suppose the query changes from:

- "what is the LCA of `u` and `v`?"

to:

- "what is the maximum value on the path from `u` to `v`, with updates?"

LCA still helps conceptually because the path splits through the meeting point, but plain LCA does not maintain path aggregates.

That is the signal to move to [Heavy-Light Decomposition](../hld/README.md), as in [Path Queries II](../../../practice/ladders/graphs/hld/pathqueries2.md).

## Common Contest Formulas

Once `l = lca(u, v)` is known, several formulas become immediate.

### 1. Tree Distance

$$
dist(u, v) = depth[u] + depth[v] - 2 \cdot depth[l].
$$

This is usually the first derived formula you should memorize.

### 2. `k`-th Ancestor

To move node `v` upward by `k` edges, decompose `k` into binary and apply the corresponding jumps:

$$
v \leftarrow up[i][v] \quad \text{for every set bit } i \text{ in } k.
$$

This is binary lifting in its most direct form.

### 3. `k`-th Node On The Path From `u` To `v`

Let:

$$
l = lca(u, v),
$$

and define:

$$
left = depth[u] - depth[l], \qquad right = depth[v] - depth[l].
$$

If `k` counts edges from `u` starting at `0`, then:

- if `k <= left`, the node lies on the segment `u -> l`, so it is the `k`-th ancestor of `u`
- otherwise it lies on the segment `l -> v`

The second case can be rewritten as an upward jump from `v`:

$$
kth\_node(u, v, k) =
\begin{cases}
\text{lift}(u, k), & k \le left \\
\text{lift}(v, left + right - k), & k > left
\end{cases}
$$

This pattern appears often in tree-routing and path-index problems.

### 4. Check Whether `x` Lies On The Path From `u` To `v`

In a tree, `x` lies on the unique path from `u` to `v` if and only if:

$$
dist(u, x) + dist(x, v) = dist(u, v).
$$

LCA turns that condition into an `O(log n)` test, or better if distances are already cached from repeated queries.

## Algorithm And Pseudocode

The repo starter implementation is:

- [lca-binary-lifting.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/lca-binary-lifting.cpp)

### Preprocessing

```text
build(root):
    compute depth[root] = 0
    traverse the tree once
    set up[0][v] = parent[v]
    for each k from 1 to LOG-1:
        up[k][v] = up[k-1][ up[k-1][v] ]
```

If you also want ancestor checks:

```text
dfs(v, p):
    tin[v] = timer++
    up[0][v] = p
    fill higher jumps
    visit children
    tout[v] = timer++
```

### Lift By Distance

```text
lift(v, dist):
    for k from 0 to LOG-1:
        if dist has bit k:
            v = up[k][v]
    return v
```

### LCA By Depth Equalization

```text
lca(a, b):
    if depth[a] < depth[b]:
        swap(a, b)

    a = lift(a, depth[a] - depth[b])

    if a == b:
        return a

    for k from LOG-1 down to 0:
        if up[k][a] != up[k][b]:
            a = up[k][a]
            b = up[k][b]

    return up[0][a]
```

### Ancestor Check With Euler Times

```text
is_ancestor(u, v):
    return tin[u] <= tin[v] and tout[v] <= tout[u]
```

This enables another binary-lifting style:

- first test ancestor cases directly
- then lift one node upward while preserving "still not ancestor"

That version is especially popular in CP-Algorithms style writeups.

## Implementation Notes

### 1. Pick One Root Convention And Make It Total

Two common safe choices:

- `up[0][root] = root`
- every higher ancestor of the root also equals `root`

or:

- use a sentinel parent like `-1`
- then guard every jump carefully

The first approach is often simpler in contest code.

### 2. Compute `LOG` Carefully

You need enough levels so that the largest possible upward jump is covered.

Typical pattern:

```text
LOG = 1
while (1 << LOG) <= n:
    LOG++
```

Off-by-one mistakes here are very common.

### 3. Return Early After Equalizing Depths

If one node is an ancestor of the other, then after the deeper node is lifted:

- the nodes become equal
- that equal node is the answer

If you skip this early return, later logic may still work in some implementations, but the proof becomes uglier and bugs become easier.

### 4. Recursive DFS Is Fine Until It Is Not

For large contest limits like `n = 2 * 10^5`, a long chain can blow the recursion stack.

So:

- recursive preprocessing is pedagogically clean
- iterative DFS/BFS is often the safer production choice

The repo note [Company Queries II](../../../practice/ladders/graphs/lca/companyqueries2.md) explicitly uses an iterative traversal for that reason.

### 5. `tin/tout` Is Optional, Not Mandatory

You can solve plain LCA perfectly well with:

- `depth`
- `up`

and no Euler times.

Add `tin/tout` when:

- ancestor checks are themselves useful
- you like the ancestor-test style of binary lifting

### 6. Distances, Path Lengths, And "Meet Point" Questions Usually Reduce Immediately

Once LCA is built, many queries stop being tree-specific mysteries.

Examples:

- tree distance
- number of edges on the path
- is one node on the path between two others?

That is why LCA is best learned as a toolkit layer rather than an isolated problem.

### 7. Keep Node Indexing Stable

If the judge is `1`-indexed, decide once:

- either keep everything `1`-indexed throughout
- or convert everything to `0`-indexed immediately

Do not mix conventions across:

- adjacency lists
- `depth`
- `up`
- query input

## Practice Archetypes

The most common LCA-flavored patterns are:

- **plain LCA queries**: direct ancestor meeting point
- **distance queries**: apply the depth formula after LCA
- **ancestor checks**: root one tree, then answer "is `u` above `v`?"
- **`k`-th ancestor**: binary lifting directly, even without an LCA question
- **path decomposition**: split a path around the LCA, then hand the pieces to another technique

The contest smell is usually:

- rooted tree
- many pair queries
- repeated use of ancestry or path structure

If the statement says "many path queries" but also includes:

- online updates
- path maxima/sums/minima

then LCA is often only the prelude, not the full answer.

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Course:

- [CS 491 CAP: Least Common Ancestor and Binary Lifting](https://cs491-web-fa24.pages.dev/lectures/lca_binary_lifting/)
- [USACO Guide: Binary Jumping](https://usaco.guide/plat/binary-jump)
- [MCPT LCA notes](https://mcpt.ca/media/Lowest_Common_Ancestor.pdf)

Reference:

- [CP-Algorithms: Lowest Common Ancestor - Binary Lifting](https://cp-algorithms.com/graph/lca_binary_lifting.html)

Practice:

- [CSES Tree Algorithms](https://cses.fi/problemset/)
- [Library Checker: Lowest Common Ancestor](https://judge.yosupo.jp/problem/lca)

Repo anchors:

- practice ladder: [LCA ladder](../../../practice/ladders/graphs/lca/README.md)
- practice note: [Company Queries II](../../../practice/ladders/graphs/lca/companyqueries2.md)
- starter template: [lca-binary-lifting.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/lca-binary-lifting.cpp)
- notebook refresher: [Graph cheatsheet](../../../notebook/graph-cheatsheet.md)
- next path-query layer: [Path Queries II](../../../practice/ladders/graphs/hld/pathqueries2.md)

## Related Topics

- [Trees](../trees/README.md)
- [Heavy-Light Decomposition](../hld/README.md)
- [Sparse Table](../../data-structures/sparse-table/README.md)
- [Tree DP](../../dp/tree-dp/README.md)
