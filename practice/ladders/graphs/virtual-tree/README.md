# Virtual Tree Ladder

This ladder is for the first tree-query lane where the main trick is:

- keep only the marked vertices from the query
- add the LCAs that still matter
- and run the real DP on that compressed tree

It is intentionally a thin lane:

- one exact starter
- one classic flagship rep
- strong compare points back to `LCA`, `Tree DP`, and `HLD`

## Who This Is For

Use this lane if:

- [LCA](../../../../topics/graphs/lca/README.md) already feels comfortable
- you can root the tree once and trust `tin/tout`
- your current query set is small compared with the whole tree, but pairwise paths between those marked nodes still matter

## Warm-Up

- ancestor checks by `tin/tout`
- why LCAs of consecutive marked vertices in DFS order are enough
- stack-building one compressed ancestor tree

Target skill:

- explain why one query with `k` marked vertices can be reduced to `O(k)` relevant vertices

Warm-up compare points:

- [LCA topic](../../../../topics/graphs/lca/README.md)
- [Company Queries II](../lca/companyqueries2.md)

## Core

- sort marked vertices by `tin`
- add consecutive LCAs
- sort/unique again
- build the parent relation by one stack
- attach original-path metadata such as depth difference or "can this segment be cut with one non-important vertex?"
- flagship rep: [Kingdom and its Cities](kingdomanditscities.md)

Target skill:

- know when the hard part is not one whole-tree DP, but one query-local DP on a compressed tree

## Stretch

- [AtCoder ABC340 G - Leaf Color](https://atcoder.jp/contests/abc340/tasks/abc340_g)
- [Codeforces Round #339 Editorial](https://codeforces.com/topic/22942/en1)
- [OI Wiki - Virtual Tree](https://en.oi-wiki.org/graph/virtual-tree/)

Target skill:

- separate "build the auxiliary tree" from "what summary/DP lives on the compressed edges and nodes"

## Retrieval Layer

- exact quick sheet -> [Virtual Tree hot sheet](../../../../notebook/virtual-tree-hot-sheet.md)
- exact starter -> [virtual-tree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/virtual-tree.cpp)
- LCA refresher -> [LCA topic](../../../../topics/graphs/lca/README.md)
- tree-DP compare point -> [Tree DP](../../../../topics/dp/tree-dp/README.md)
- path-query compare point -> [HLD hot sheet](../../../../notebook/hld-hot-sheet.md)

## Repo Anchors And Compare Points

- topic page -> [Virtual Tree / Auxiliary Tree](../../../../topics/graphs/virtual-tree/README.md)
- LCA prerequisite -> [LCA](../../../../topics/graphs/lca/README.md)
- whole-tree child-merge compare point -> [Tree DP](../../../../topics/dp/tree-dp/README.md)
- static path-query compare point -> [Heavy-Light Decomposition](../../../../topics/graphs/hld/README.md)
- broader routing -> [Graphs ladder](../README.md)

The cleanest in-repo loop here is:

1. reopen [LCA](../../../../topics/graphs/lca/README.md) until `tin/tout` and `lca()` feel automatic
2. trust the build step from [`virtual-tree.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/virtual-tree.cpp)
3. solve or revisit [Kingdom and its Cities](kingdomanditscities.md)
4. only then jump to heavier marked-subset DPs like `Leaf Color`

## Exit Criteria

You are ready to move on when:

- you can explain why consecutive-by-`tin` LCAs are enough
- you can build the compressed tree without guessing the stack logic
- you can say what metadata a compressed edge must carry for the current query DP
- you can distinguish `virtual tree` from `HLD path decomposition` and from `whole-tree DP`

## External Practice

- [Codeforces 613D - Kingdom and its Cities](https://codeforces.com/problemset/problem/613/D)
- [Codeforces Round #339 Editorial](https://codeforces.com/topic/22942/en1)
- [AtCoder ABC340 G - Leaf Color](https://atcoder.jp/contests/abc340/tasks/abc340_g)
- [OI Wiki - Virtual Tree](https://en.oi-wiki.org/graph/virtual-tree/)

## Tutorial Link

- [Virtual Tree / Auxiliary Tree](../../../../topics/graphs/virtual-tree/README.md)

