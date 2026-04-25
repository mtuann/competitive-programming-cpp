# Distinct Colors

- Title: `Distinct Colors`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1139/](https://cses.fi/problemset/task/1139/)
- Secondary topics: `Tree traversal`, `Frequency maps`, `Subtree distinct count`
- Difficulty: `hard`
- Subtype: `Small-to-large subtree container merging`
- Status: `solved`
- Solution file: [distinctcolors.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/dsu-on-tree/distinctcolors.cpp)

## Why Practice This

This is the cleanest in-repo first anchor for the `DSU on tree / small-to-large` lane.

The problem asks for:

- one answer for every node
- over its whole subtree
- where the relevant subtree summary is "which colors appear here?"

That is exactly the kind of statistic that wants a mergeable container.

## Recognition Cue

Reach for small-to-large subtree merging when:

- each node needs one subtree answer
- each child subtree contributes a container of facts
- the answer for the parent comes from merging all child containers
- plain fixed-size [Tree DP](../../../../topics/dp/tree-dp/README.md) is too weak, but subtree flattening into one interval is not the intended first move

The smell here is:

- "for every node, how many distinct values appear in its subtree?"

## Problem-Specific Transformation

Let `bag[u]` store a frequency map:

```text
color -> count inside subtree(u)
```

Then:

- start `bag[u]` with `color[u]`
- solve every child `v`
- merge each child bag into `bag[u]`
- answer is:

```text
ans[u] = number of keys in bag[u]
```

The naive bottleneck is repeated map merging.

So the real algorithmic move is:

```text
always merge the smaller bag into the larger bag
```

## Why The Optimization Fits

If an item moves from a smaller bag into a larger one, the size of its host bag at least doubles.

So one color occurrence can only be moved `O(log n)` times across the whole tree.

That is why the total merge work stays controlled.

## Exact Route

This note uses the repo's exact first route:

- one map per surviving subtree container
- bottom-up processing
- swap so the larger bag survives
- merge smaller child bag into it

This is more direct for the first rep than the heavier `sack / keep-heavy-child` pattern.

## Implementation Plan

1. root the tree at `1`
2. build parent array and one postorder
3. for each node in reverse order:
   - create bag with own color
   - merge each child bag into the largest current bag
   - record `ans[u] = bag[u].size()`
4. print answers in node order

## Complexity

- tree traversal: `O(n)`
- small-to-large merges: typically near `O(n log n)` average with hash maps, or `O(n log^2 n)` with ordered maps/sets

## Main Traps

- forgetting that the bag summary is per subtree, not one global DFS path
- keeping all bags alive after merge instead of one surviving bag
- choosing the lighter bag as destination and destroying the amortized bound
- forcing Euler-tour or Mo logic onto a problem whose natural story is container merging

## Reopen Path

- Topic page: [DSU On Tree / Small-To-Large](../../../../topics/data-structures/dsu-on-tree/README.md)
- Practice ladder: [DSU On Tree / Small-To-Large ladder](README.md)
- Starter template: [small-to-large-subtree-merge.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/small-to-large-subtree-merge.cpp)
- Notebook refresher: [DSU On Tree hot sheet](../../../../notebook/dsu-on-tree-hot-sheet.md)
- Compare points: [Tree DP](../../../../topics/dp/tree-dp/README.md), [Euler Tour / Subtree Queries](../../../../topics/graphs/euler-tour-subtree/README.md), [Mo's Algorithm](../../../../topics/data-structures/mos-algorithm/README.md)

## Solution

- Code: [distinctcolors.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/dsu-on-tree/distinctcolors.cpp)
