# Graphs -> Trees

Tree structure, rooting, Euler tours, diameters, and decomposition ideas that power most advanced tree problems.

- Topic slug: `graphs/trees`
- Tutorial page: [Open tutorial](../topics/graphs/trees/README.md)
- Ladder page: [Open ladder](../practice/ladders/graphs/trees/README.md)
- Repo problems currently tagged here: `6`
- Curated external problems: `10`

## Microtopics

- rooted-tree
- subtree
- depth
- parent-child
- diameter
- centroid
- euler-tour

## Learning Sources

| Source | Type |
| --- | --- |
| [IOI 2025 syllabus PDF](https://ioinformatics.org/files/ioi-syllabus-2025.pdf) | `official curriculum` |
| [OI Wiki tree basics](https://en.oi-wiki.org/graph/tree-basic/) | `trusted guide` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Problem Set](https://cses.fi/problemset/) | `problem set` |
| [USACO contest archive](https://usaco.org/index.php?page=contests) | `contest archive` |
| [IOI tasks archive](https://stats.ioinformatics.org/tasks/) | `contest archive` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Diameter of a Tree](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A) | `AOJ` | `Easy` | - | - | - | Tree Diameter; DFS; Weighted Tree | Very clean tree baseline problem. |

### Centroid

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Finding a Centroid](https://cses.fi/problemset/task/2079) | `CSES` | `Medium` | Subtree Sizes, Centroid | Size DFS; Balance Check; Candidate Descent | DFS; Tree Balance | Balance; DFS | A compact tree problem that reinforces subtree-size reasoning. |

### DSU On Tree

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Distinct Colors](https://cses.fi/problemset/task/1139) | `CSES` | `Hard` | DSU On Tree, Subtrees | Small-To-Large Merging; Subtree Frequency Maps; Offline Aggregation | Tree Traversal; Frequency Maps; Subtree Processing | Distinct Values; Subtree Aggregation; Small-To-Large | A strong subtree-aggregation problem that rewards a nontrivial tree technique. |

### Euler Tour Bit

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Subtree Queries](https://cses.fi/problemset/task/1137) | `CSES` | `Medium` | Euler Tour, Fenwick | Flatten Tree; Fenwick Tree; Range Sum Queries | Fenwick Tree; Subtree Intervals | Subtree Sum; Updates | A canonical tree-to-array reduction for subtree updates and queries. |

### Rerooting DP

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Tree Distances I](https://cses.fi/problemset/task/1132) | `CSES` | `Medium` | Rerooting, Distances | Two-Pass DP; Downward And Upward Values; Distance Maxima | Tree DP; DFS; Rerooting Idea | Eccentricity; Distance Propagation; Tree DP | Per-node farthest-distance computation on a tree. |

### Rerooting Sums

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Tree Distances II](https://cses.fi/problemset/task/1133) | `CSES` | `Medium` | Rerooting, Sums | Subtree DP; Reroot Transition; Sum Aggregation | Tree DP; Prefix Sums On Trees | Sum Of Distances; Tree DP | A classic rerooting problem where each node needs an aggregate over the whole tree. |

### Root Path Queries

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Path Queries](https://cses.fi/problemset/task/1138) | `CSES` | `Medium` | Euler Tour, Fenwick | Euler Tour; Fenwick Tree; Prefix-On-Tree | Tree Flattening; Fenwick Tree; Rooted Tree | Root Path Sum; Updates; Tree Flattening | Pairs a tree traversal with range data structures in a very reusable way. |

### Subtree Sizes

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Subordinates](https://cses.fi/problemset/task/1674) | `CSES` | `Easy` | DFS, Subtree Sizes | Postorder DFS; Size Accumulation; Rooted Traversal | Tree Traversal; Parent-Child Relation | Subtree Size; Rooted Tree; Counting | A very approachable rooted-tree problem that builds subtree intuition. |

### Tree Diameter

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Tree Diameter](https://cses.fi/problemset/task/1131) | `CSES` | `Easy` | DFS, Diameter | Double Sweep; DFS/BFS Diameter; Farthest Node | Tree Basics; Graph Traversal; Distance Intuition | Two BFS; Longest Path | The classic tree diameter pattern that every tree toolkit should contain. |

### Tree DP

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Tree Matching](https://cses.fi/problemset/task/1130) | `CSES` | `Medium` | Tree DP, Greedy | Bottom-Up DP; Leaf Processing; Pairing Choices | DFS; Greedy Reasoning | Matching; Independent Edges; Independent Edge Set | A concise introduction to optimizing choices on trees. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `KINGDOMS` | KINGDOMS | `secondary` | `hard` | laminar regions; sweep events; containment tree | [Note](../practice/ladders/geometry/sweep-line/kingdoms.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/sweep-line/kingdoms.cpp) |
| `MCQUERY` | MinCut Query | `secondary` | `hard` | all-pairs min-cut; cut tree; count pairs by threshold | [Note](../practice/ladders/graphs/flow/mcquery.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/flow/mcquery.cpp) |
| `MTREECOL` | Color a tree | `primary` | `hard` | ratio greedy; tree contraction; exchange argument | [Note](../practice/ladders/graphs/trees/mtreecol.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/trees/mtreecol.cpp) |
| `VMWTREE` | Lại là cây khung | `primary` | `hard` | path reverse; path sequence queries; heavy-light decomposition | [Note](../practice/ladders/graphs/trees/vmwtree.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/trees/vmwtree.cpp) |
| `VOITSORT` | Cây hoán vị | `secondary` | `hard` | lexicographic enumeration; stack-sortability; cartesian tree view | [Note](../practice/ladders/combinatorics/lexicographic-enumeration/voitsort.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/combinatorics/lexicographic-enumeration/voitsort.cpp) |
| `VOSTRIP` | VOSTRIP | `secondary` | `hard` | tree endpoint pairing; path decomposition; local imbalance formula | [Note](../practice/ladders/graphs/tree-dp/vostrip.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/tree-dp/vostrip.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
