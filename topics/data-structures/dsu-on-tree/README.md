# DSU On Tree / Small-To-Large

This lane is about subtree queries on a rooted tree where each child subtree contributes a mergeable container:

- a set of colors
- a map of frequencies
- or another summary that can be merged into a bigger container

The key optimization is:

```text
always merge the smaller container into the larger one
```

That is why the lane is often called:

- `small-to-large merging`
- `DSU on tree`
- or `sack`

This repo's exact first route is the **container-merging** version:

- one container per subtree
- merge child containers bottom-up
- swap so the bigger container stays alive

The heavier `keep heavy child / clear light children` sack pattern is a natural follow-up once the statistic is update-friendly and a single global frequency table is cleaner than one container per node.

## At A Glance

- **Use when:** every node needs one subtree answer, each child contributes a mergeable container, and the merge cost dominates the tree traversal
- **Core worldview:** each subtree owns one container; keep the biggest child container and pour smaller ones into it
- **Main tools:** rooted tree, postorder traversal, container `swap`, merge-small-into-large proof
- **Typical complexity:** often `O(n log^2 n)` with ordered maps/sets, or near `O(n log n)` average with hash maps
- **Main trap:** calling everything "DSU on tree" even when the easier route is plain tree DP, Euler tour + Fenwick, or [Mo's Algorithm](../mos-algorithm/README.md)

Strong contest signals:

- "for every node, answer something about its subtree"
- the subtree answer is a distinct-count, frequency map, or mergeable statistic
- each child subtree can be summarized independently, but merging all children naively is too slow
- you see repeated `map / set / multiset` merges inside DFS

Strong anti-cues:

- the answer is just one scalar subtree DP state -> [Tree DP](../../dp/tree-dp/README.md)
- subtree intervals plus one static array structure already solve it -> [Euler Tour / Subtree Queries](../../graphs/euler-tour-subtree/README.md)
- one active current range with symmetric add/remove is the real invariant -> [Mo's Algorithm](../mos-algorithm/README.md)
- the timeline has edge additions and removals -> [DSU Rollback / Offline Dynamic Connectivity](../dsu-rollback/README.md)

## Prerequisites

- [DSU](../dsu/README.md)
- [Trees](../../graphs/trees/README.md)
- [Tree DP](../../dp/tree-dp/README.md)

Helpful neighboring topics:

- [Offline Tricks](../offline-tricks/README.md)
- [Mo's Algorithm](../mos-algorithm/README.md)
- [Euler Tour / Subtree Queries](../../graphs/euler-tour-subtree/README.md)

## Problem Model And Notation

We root the tree at node `1`.

Each node `u` has:

- one parent `p`
- zero or more children
- a subtree `sub(u)`

For every node, we want one subtree statistic such as:

- number of distinct colors in `sub(u)`
- max frequency inside `sub(u)`
- sum over keys that appear in `sub(u)`

The exact first route stores one container:

$$
bag[u]
$$

for each subtree, then merges child containers upward.

## From Naive Merging To Small-To-Large

### Naive Idea

For each node `u`:

1. start a fresh container containing `u`
2. recursively solve every child `v`
3. merge every element of `bag[v]` into `bag[u]`

This is correct, but if we always merge child into parent without caring about size, one element may be recopied too many times.

### The Small-To-Large Rule

Before merging two containers:

```text
if size(a) < size(b), swap(a, b)
```

Then insert everything from `b` into `a`.

Why does this help?

If one item moves from a smaller container into a larger one, the size of its host container at least doubles.

So each item can only be moved:

$$
O(\log n)
$$

times before it ends up inside a container of size at least `n`.

That is the whole amortization argument.

## Why The Name Sounds Weird

This technique is called `DSU on tree` because it copies the same heuristic spirit as ordinary DSU:

- in DSU, union smaller component into larger one
- here, merge smaller subtree container into larger one

But the exact data structure is usually:

- `set`
- `map`
- `unordered_map`
- or some custom bucket/frequency container

not a union-find forest.

## Exact First Route In This Repo

The starter in this repo teaches:

- bottom-up rooted-tree processing
- one frequency map per current surviving subtree container
- merge-small-into-large
- `answer[u] = number of distinct keys in bag[u]`

This is the cleanest first route for:

- [Distinct Colors](../../../practice/ladders/data-structures/dsu-on-tree/distinctcolors.md)

The exact starter is:

- [small-to-large-subtree-merge.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/small-to-large-subtree-merge.cpp)

## Worked Example: Distinct Colors

In [Distinct Colors](../../../practice/ladders/data-structures/dsu-on-tree/distinctcolors.md), every node has one color and we want:

$$
ans[u] = \#\{\text{distinct colors in } sub(u)\}.
$$

The container for one subtree can be:

- a map `color -> count`

Then:

- add `u`'s own color
- merge every child map into the largest one
- after all child merges, `bag[u].size()` is the number of distinct colors in `sub(u)`

This is the canonical first rep because:

- the statistic is truly a merged subtree summary
- no path queries or online updates distract from the merging idea

## The Heavier Sack Variant

There is a second common style:

- find heavy child
- keep the heavy child's contribution alive
- add light subtrees temporarily
- clear light contributions when needed

That route is often better when:

- updates to one global statistic are very cheap
- carrying one mutable frequency table is simpler than owning a container per node

This page treats that as a **follow-up variant**, not the first route.

## Variant Chooser

### Use Tree DP When

- every child only contributes one small fixed-size state
- there is no real container merge

### Use Small-To-Large Merging When

- each subtree naturally owns a container
- the answer can be read directly from the merged container summary
- one container per subtree is still the clean mental model

### Use Sack / Heavy-Child Keep When

- one global frequency structure plus subtree add/remove is cleaner
- the statistic has cheap incremental updates
- the container-per-node route becomes too memory- or constant-heavy

### Use Euler Tour / Subtree Queries When

- one subtree is just one interval in DFS order
- and a Fenwick / segment tree / offline sweep already answers the query

### Use Mo On Trees When

- you really need add/remove over an Euler-tour walk order
- and the maintained state is one active range, not one container per subtree

## Implementation Notes

- root the tree first
- process nodes in postorder
- if a child bag is larger than the current bag, swap pointers
- merge the smaller bag into the larger bag
- delete or discard merged-away child bags so one logical container survives per processed subtree

## Common Failure Modes

- forgetting that `std::swap(a, b)` is only cheap if the container's swap itself is cheap
- using ordered maps when an ordinary frequency array or hash map would be the real intended route
- trying to force this lane onto path queries
- keeping all child bags alive after merge and accidentally blowing memory
- calling the technique "online" even though the whole tree is solved in one rooted offline pass

## Sources

- reference: [USACO Guide - Small-To-Large Merging](https://usaco.guide/plat/merging)
- reference: [OI Wiki - DSU on Tree](https://en.oi-wiki.org/graph/dsu-on-tree/)
- compare point: [SOI Wiki - Smaller to Larger](https://soi.ch/wiki/smaller-to-larger/)
- practice statement: [CSES - Distinct Colors](https://cses.fi/problemset/task/1139/)

## Repo Routes

- starter: [small-to-large-subtree-merge.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/small-to-large-subtree-merge.cpp)
- hot sheet: [DSU On Tree hot sheet](../../../notebook/dsu-on-tree-hot-sheet.md)
- flagship note: [Distinct Colors](../../../practice/ladders/data-structures/dsu-on-tree/distinctcolors.md)
- compare point: [Tree DP](../../dp/tree-dp/README.md)
- compare point: [Euler Tour / Subtree Queries](../../graphs/euler-tour-subtree/README.md)
- compare point: [Mo's Algorithm](../mos-algorithm/README.md)
