# DSU On Tree / Small-To-Large Ladder

This lane is for rooted-tree subtree queries where each child contributes a mergeable container and the merge itself is the real complexity bottleneck.

## Who This Is For

Use this ladder if:

- plain [Tree DP](../../../../topics/dp/tree-dp/README.md) feels too small-state for the subtree statistic
- [Euler Tour / Subtree Queries](../../../../topics/graphs/euler-tour-subtree/README.md) does not close the problem with one interval structure
- you keep seeing `map` or `set` merges inside DFS and want the exact contest-safe route

## Core

- rooted tree
- one subtree container per node
- merge small child container into large surviving container

Target skill:

- know why the amortized bound comes from doubling container size after every move

## Exact Starter

- [small-to-large-subtree-merge.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/small-to-large-subtree-merge.cpp)

Target skill:

- compute one subtree statistic for every node by bottom-up container merges

## Flagship Rep

- [Distinct Colors](distinctcolors.md)

Target skill:

- turn subtree distinct-count queries into `color -> frequency` map merges

## Stretch

- [Lomsat gelral](https://codeforces.com/problemset/problem/600/E)
- compare with [Tree DP](../../../../topics/dp/tree-dp/README.md)
- compare with [Mo's Algorithm](../../../../topics/data-structures/mos-algorithm/README.md)

Target skill:

- know when the statistic is still a mergeable subtree container and when you should switch to a different tree-query family

## Exit Criteria

You are ready to move on when:

- you can explain the doubling argument without code
- you know why `swap` is part of the algorithm, not micro-optimization
- you can tell when this route is lighter than Euler flattening plus another structure

## External Practice

- [CSES - Distinct Colors](https://cses.fi/problemset/task/1139/)
- [Codeforces - Lomsat gelral](https://codeforces.com/problemset/problem/600/E)
- [USACO Guide - Small-To-Large Merging](https://usaco.guide/plat/merging)

## Tutorial Link

- [DSU On Tree / Small-To-Large](../../../../topics/data-structures/dsu-on-tree/README.md)
