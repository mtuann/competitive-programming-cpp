# Graphs -> BFS And DFS

Traversal for reachability, layering, components, bipartiteness, and DFS-tree structure.

- Topic slug: `graphs/bfs-dfs`
- Tutorial page: [Open tutorial](../../../topics/graphs/bfs-dfs/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/graphs/bfs-dfs/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `0`
- Curated external problems: `7`

## Microtopics

- reachability
- connected-components
- layering
- dfs-tree
- cycle-detection
- bipartite-check

## Learning Sources

| Source | Type |
| --- | --- |
| [MIT 6.006 notes page](https://courses.csail.mit.edu/6.006/fall10/notes.shtml) | `course` |
| [cp-algorithms BFS](https://cp-algorithms.com/graph/breadth-first-search.html) | `trusted guide` |
| [USACO Guide graph traversal](https://usaco.guide/silver/graph-traversal?lang=cpp) | `trusted guide` |

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
| [Monsters](https://cses.fi/problemset/task/1194) | `CSES` | `Medium` | Multi-Source BFS, Grid BFS | Two-Phase BFS; Distance Grid; Path Reconstruction | Queue BFS; Distance Arrays; Grid Moves | Grid; Timing | Classic BFS timing problem where monster arrival times reshape the reachable state space. |

### BFS Shortest Path

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Labyrinth](https://cses.fi/problemset/task/1193) | `CSES` | `Easy` | Grid | BFS Tree; Parent Array; Route Recovery | Queue BFS; Parent Pointers; 4-Direction Moves | Shortest Path; Path Reconstruction; Maze | A clean way to practice BFS plus path reconstruction on an unweighted graph. |

### Bipartite Check

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Building Teams](https://cses.fi/problemset/task/1668) | `CSES` | `Easy` | Bipartite | DFS Coloring; Conflict Detection; Component Handling | Graph Traversal; Parity Coloring; Visited States | Two-Coloring; Bipartite Graph | A canonical traversal problem that turns friendship constraints into bipartite checking. |

### Connected Components

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Counting Rooms](https://cses.fi/problemset/task/1192) | `CSES` | `Easy` | Grid | DFS Flood Fill; Component Sweep; Boundary Checks | DFS; Visited Array; Grid Traversal | Flood Fill; Components; Visited Cells | A textbook first traversal problem with no extra graph tricks. |

### Directed Cycle

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Round Trip II](https://cses.fi/problemset/task/1678) | `CSES` | `Medium` | Directed Graphs | DFS State Colors; Stack-Based Recovery; Cycle Witness | Directed DFS; Back-Edge Detection; Parent Pointers | Directed Cycle; Recursion Stack; Witness Path; Topological Intuition; Reconstruction | The directed counterpart to Round Trip, with trickier cycle recovery. |

### Undirected Cycle

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Round Trip](https://cses.fi/problemset/task/1669) | `CSES` | `Medium` | Cycles | DFS Parent Tracking; Cycle Reconstruction; Component Scan | DFS; Parent Pointers; Recursion Stack | Undirected Cycle; Back Edge; Witness Path; Cycle Detection; Undirected Graph; Reconstruction | Great practice for detecting and reconstructing a cycle in an undirected graph. |

### Unweighted BFS

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Message Route](https://cses.fi/problemset/task/1667) | `CSES` | `Easy` | Paths | Layered BFS; Parent Tracking; Shortest Route Recovery | BFS; Adjacency Lists; Backtracking | Unweighted Shortest Path; Path Reconstruction; Network; Shortest Path | The standard shortest-path-in-an-unweighted-graph template. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `MESSAGEROUTE` | Message Route | `primary` | `easy` | breadth-first search; unweighted shortest path; parent reconstruction | [Note](../../../practice/ladders/graphs/bfs-dfs/messageroute.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/bfs-dfs/messageroute.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
