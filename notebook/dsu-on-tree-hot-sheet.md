# DSU On Tree / Small-To-Large Hot Sheet

Use this when every node needs one subtree answer and the natural subtree summary is a mergeable container:

- set of colors
- map of frequencies
- multiset-like subtree summary

## Use When

- the input is a rooted tree
- each child subtree contributes one mergeable container
- the expensive part is merging those child summaries
- the answer is read from the merged subtree container

## Do Not Use When

- one fixed-size subtree state already solves it -> [Tree DP](../topics/dp/tree-dp/README.md)
- subtree intervals plus one array structure are enough -> [Euler Tour / Subtree Queries](../topics/graphs/euler-tour-subtree/README.md)
- one active add/remove range is the real invariant -> [Mo's Algorithm](../topics/data-structures/mos-algorithm/README.md)
- the problem is online add/remove connectivity -> [DSU Rollback](dsu-rollback-hot-sheet.md)

## Core Rule

```text
always merge the smaller container into the larger one
```

Why it works:

- every moved item lands in a container at least twice as large
- so one item moves only `O(log n)` times

## Exact First Route

- one container per subtree
- process nodes bottom-up
- keep one surviving largest bag
- merge smaller child bags into it
- read answer from the final bag summary

## Main Traps

- using it when plain subtree DP was enough
- confusing `small-to-large container merging` with the heavier `sack / keep-heavy-child` pattern
- forgetting to discard merged-away child bags

## Exact Route

- topic: [DSU On Tree / Small-To-Large](../topics/data-structures/dsu-on-tree/README.md)
- starter: [small-to-large-subtree-merge.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/small-to-large-subtree-merge.cpp)
- flagship: [Distinct Colors](../practice/ladders/data-structures/dsu-on-tree/distinctcolors.md)
- compare points: [Tree DP](../topics/dp/tree-dp/README.md), [Euler Tour / Subtree Queries](../topics/graphs/euler-tour-subtree/README.md), [Mo's Algorithm](../topics/data-structures/mos-algorithm/README.md)
