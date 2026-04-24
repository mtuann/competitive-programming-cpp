# DP -> Tree DP

DP on rooted trees, rerooting, subtree merges, and local state design for hierarchical structures.

- Topic slug: `dp/tree-dp`
- Tutorial page: [Open tutorial](../../../topics/dp/tree-dp/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/dp/tree-dp/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `0`
- Curated external problems: `10`

## Microtopics

- subtree-dp
- include-exclude
- rerooting
- tree-knapsack
- merge-small-to-large-dp
- edge-vs-node-states

## Learning Sources

| Source | Type |
| --- | --- |
| [USACO Guide DP on Trees](https://usaco.guide/gold/dp-trees) | `trusted guide` |
| [OI Wiki tree DP](https://en.oi-wiki.org/dp/tree/) | `trusted guide` |
| [USACO Guide Combining Subtrees](https://usaco.guide/adv/comb-sub) | `trusted guide` |

## Practice Sources

| Source | Type |
| --- | --- |
| [AtCoder DP P](https://atcoder.jp/contests/dp/tasks/dp_p) | `problem` |
| [CSES Tree Matching](https://cses.fi/problemset/task/1130/) | `problem` |
| [USACO Guide tree DP modules](https://usaco.guide/gold/dp-trees) | `problem bank` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Tree Matching](https://cses.fi/problemset/task/1130) | `CSES` | `Medium` | - | - | - | Matching | child-combination DP on trees |
| [Subtree](https://atcoder.jp/contests/dp/tasks/dp_v) | `AtCoder DP Contest` | `Medium-Hard` | - | - | - | Rerooting | rerooting / subtree accumulation |

### All Roots Distance DP

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Sum of Distances in Tree](https://leetcode.com/problems/sum-of-distances-in-tree) | `LeetCode` | `Hard` | Rerooting | DFS; Rerooting | Subtree Sizes; Tree Traversal | - | A very common rerooting problem that teaches how to propagate global answers across all nodes. |

### Best Path Through A Node

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum) | `LeetCode` | `Hard` | Path-Aggregation | DFS; Postorder | Tree Recursion; Max Subarray Intuition | Path | A classic tree aggregation problem where each node contributes one-sided path values upward. |

### Maximum Distance Per Node

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Tree Distances I](https://cses.fi/problemset/task/1132) | `CSES` | `Medium` | Rerooting | DFS; Rerooting | Tree Traversal; DFS Order | Distance | A clean rerooting example that asks for a per-node aggregate over the whole tree. |

### Root Choice Optimization

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Directory Traversal](https://usaco.org/index.php?cpid=814&page=viewproblem2) | `USACO Gold` | `Medium` | Rerooting | DFS; Rerooting | Tree Distance Basics; Prefix Sums | - | A great rerooting-style tree DP where the answer depends on where you stand in the tree. |

### Sum Of Distances

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Tree Distances II](https://cses.fi/problemset/task/1133) | `CSES` | `Medium` | Rerooting | DFS; Rerooting | Tree Distances I; Subtree Sizes | - | The sum-of-distances sibling to Tree Distances I, and a classic rerooting benchmark. |

### Tree Coloring

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Barn Painting](https://usaco.org/index.php?cpid=766&page=viewproblem2) | `USACO Gold` | `Easy` | Coloring-DP | DFS; Postorder | Tree Traversal; State Compression | Coloring | A classic colored-tree DP that cleanly illustrates parent-state dependency. |

### Tree Independent Set

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Independent Set](https://atcoder.jp/contests/dp/tasks/dp_p) | `AtCoder DP Contest` | `Medium` | Subtree-DP | DFS; Postorder | Tree Traversal; Basic Recursion | Independent-Set; 2-State | The textbook tree DP for choosing or skipping each node under parent-child constraints. |

### Tree Skip Take

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [House Robber III](https://leetcode.com/problems/house-robber-iii) | `LeetCode` | `Medium` | Tree-Structure | DFS; Postorder | Binary Tree Traversal; State Pairs | Binary-Tree; Skip-Take | A highly recognizable tree DP where each node returns take and skip values. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `VOSTRIP` | VOSTRIP | `secondary` | `hard` | tree endpoint pairing; path decomposition; local imbalance formula | [Note](../../../practice/ladders/graphs/tree-dp/vostrip.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/tree-dp/vostrip.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
