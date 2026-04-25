# Centroid Decomposition Hot Sheet

Use this page when the tree is static and the clean split is “paths or updates through one balanced pivot” rather than one rooted subtree or one segment-tree-on-path reduction.

## Do Not Use When

- you only need one centroid node, not the full centroid tree
- queries are subtree-only, so Euler flattening already solves the problem
- the real primitive is online path aggregate / path update, so HLD fits better
- the tree DP is just one child-merge or rerooting pass
- the tree structure itself changes online

## Choose By Signal

- one centroid only -> stay in [Trees](../topics/graphs/trees/README.md) or start from [Finding a Centroid](https://cses.fi/problemset/task/2079)
- static tree, many operations over `O(log n)` centroid ancestors -> centroid decomposition -> [`centroid-decomposition.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/centroid-decomposition.cpp)
- subtree-only aggregation -> [Subtree Queries hot sheet](subtree-queries-hot-sheet.md)
- online path max/sum/min with updates -> [HLD hot sheet](hld-hot-sheet.md)
- child-state merges or reroot formulas -> [DP cheatsheet](dp-cheatsheet.md) or [Tree DP](../topics/dp/tree-dp/README.md)

## Core Invariants

- every recursive component has a centroid
- after removing the centroid, every remaining component has size at most half
- centroid-tree depth is `O(log n)`
- every original node has only `O(log n)` centroid ancestors
- many standard update/query routes become “walk centroid ancestors and combine”
- path-counting versions process all paths through the current centroid, then recurse on paths that avoid it

## Main Traps

- confusing the centroid tree with the original rooted tree
- erasing edges while iterating instead of using `removed[]`
- reaching for centroid decomposition when Euler flattening or HLD is the simpler exact fit
- forgetting to document whether centroid ancestors are stored nearest-first or root-first
- recomputing distances with an extra LCA factor when the decomposition pass could have stored them already

## Exact Starters In This Repo

- exact starter -> [`centroid-decomposition.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/centroid-decomposition.cpp)
- flagship in-lane rep -> [Ciel the Commander](../practice/ladders/graphs/centroid-decomposition/cielthecommander.md)
- warm-up compare point -> [Finding a Centroid](https://cses.fi/problemset/task/2079)
- path-query contrast -> [HLD hot sheet](hld-hot-sheet.md)
- subtree-only contrast -> [Subtree Queries hot sheet](subtree-queries-hot-sheet.md)

## Reopen Paths

- full lesson and chooser -> [Centroid Decomposition](../topics/graphs/centroid-decomposition/README.md)
- rooted-tree worldview first -> [Trees](../topics/graphs/trees/README.md)
- arbitrary path aggregates instead -> [Heavy-Light Decomposition](../topics/graphs/hld/README.md)
- family chooser -> [Graph cheatsheet](graph-cheatsheet.md)
- snippet chooser -> [Template Library](../template-library.md)
