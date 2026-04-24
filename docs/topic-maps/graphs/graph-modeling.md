# Graphs -> Graph Modeling

Before running graph algorithms, decide what the nodes, edges, states, and weights actually represent.

- Topic slug: `graphs/graph-modeling`
- Tutorial page: [Open tutorial](../../../topics/graphs/graph-modeling/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/graphs/graph-modeling/README.md)
- Repo problems currently tagged here: `3`
- Repo companion pages: `2`
- Curated external problems: `9`

## Microtopics

- adjacency-list
- adjacency-matrix
- directed
- undirected
- weighted
- multigraph
- state-graph

## Learning Sources

| Source | Type |
| --- | --- |
| [Princeton Graphs](https://algs4.cs.princeton.edu/40graphs) | `course` |
| [IOI 2025 syllabus PDF](https://ioinformatics.org/files/ioi-syllabus-2025.pdf) | `official curriculum` |
| [OI Wiki graph intro](https://en.oi-wiki.org/graph/) | `trusted guide` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Problem Set](https://cses.fi/problemset/) | `problem set` |
| [USACO contest archive](https://usaco.org/index.php?page=contests) | `contest archive` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Graph cheatsheet](../../../notebook/graph-cheatsheet.md) | `quick reference` |
| [Templates overview](../../../template-library.md) | `template guide` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Building Roads](https://cses.fi/problemset/task/1666) | `CSES` | `Easy` | Components | - | - | Connected Components; Construction; Union-Find | Simple component-based modeling: connect all components with minimum new edges. |
| [Message Route](https://cses.fi/problemset/task/1667) | `CSES` | `Easy` | BFS | - | - | Unweighted Graph; Path Reconstruction; Shortest Path | Bare-bones graph modeling for shortest path with a concrete route output. |
| [Third Avenue](https://atcoder.jp/contests/abc184/tasks/abc184_e) | `AtCoder` | `Medium` | Grid BFS | - | - | Teleporters; Implicit Graph; Grid | A textbook teleporter-state modeling problem on a grid. |

### 2 SAT Modeling

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Giant Pizza](https://cses.fi/problemset/task/1684) | `CSES` | `Medium` | 2-SAT, SCC | Implication Graph; SCC Condensation; Assignment Extraction | Logical Reductions; Directed Graphs | Implication Graph; Boolean Constraints | A very strong modeling problem: clauses become graph edges and satisfiability becomes SCC. |

### Coordinate MST

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Built?](https://atcoder.jp/contests/abc065/tasks/arc076_b) | `AtCoder` | `Medium` | MST, Geometry | Edge Generation By Sorting; DSU; Kruskal | DSU; Sorting; Greedy MST | Coordinate Graph; Kruskal; Sparse Edges | A classic geometry-to-graph reduction before running Kruskal. |

### Grid Cycle

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Fox And Two Dots](https://codeforces.com/problemset/problem/510/B) | `Codeforces` | `Medium` | Grid DFS | DFS With Parent Tracking; Cycle Witness; Component Scan | DFS; Visited States; Parent Pointers | Cycle Detection; Same-Color Regions; Grid Graph | Teaches how to find a cycle in an implicit graph hidden inside a board. |

### Grid Flood Fill

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Counting Rooms](https://cses.fi/problemset/task/1192) | `CSES` | `Easy` | Grid DFS | Iterative DFS; Visited Marking; 4-Neighbor Traversal | Graph Traversal; Stack Or Recursion; Grid Indexing | Flood Fill; Connected Components; Implicit Graph | The cleanest example of turning a matrix into a graph and counting components. |

### Grid Shortest Path

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Labyrinth](https://cses.fi/problemset/task/1193) | `CSES` | `Easy` | Grid BFS | Single-Source BFS; Parent Pointers; Route Recovery | BFS; Parent Tracking; 4-Direction Moves | Shortest Path; Path Reconstruction; Maze; Grid | The standard implicit-grid shortest path with an explicit reconstructed route. |

### Multi Source BFS

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Monsters](https://cses.fi/problemset/task/1194) | `CSES` | `Medium` | Grid BFS | Two-Phase BFS; Distance Grid; Path Reconstruction | Queue BFS; Distance Arrays; Grid Moves | Multi-Source BFS; Escape Path; Timing Constraints; Timing; Escape | A classic hidden-state problem where enemy arrival times change the search space. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `BUILDINGROADS` | Building Roads | `primary` | `easy` | connected components; component representatives; constructive graph connection | [Note](../../../practice/ladders/graphs/graph-modeling/buildingroads.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/graph-modeling/buildingroads.cpp) |
| `COUNTINGROOMS` | Counting Rooms | `primary` | `easy` | grid graph modeling; iterative flood fill; connected components | [Note](../../../practice/ladders/graphs/graph-modeling/countingrooms.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/graph-modeling/countingrooms.cpp) |
| `MESSAGEROUTE` | Message Route | `secondary` | `easy` | breadth-first search; unweighted shortest path; parent reconstruction | [Note](../../../practice/ladders/graphs/bfs-dfs/messageroute.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/bfs-dfs/messageroute.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
