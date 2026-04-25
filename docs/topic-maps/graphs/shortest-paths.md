# Graphs -> Shortest Paths

From BFS and DAG DP to Dijkstra and Bellman-Ford, pick the shortest-path tool that matches the edge model.

- Topic slug: `graphs/shortest-paths`
- Tutorial page: [Open tutorial](../../../topics/graphs/shortest-paths/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/graphs/shortest-paths/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `0`
- Curated external problems: `9`

## Microtopics

- unweighted
- dijkstra
- bellman-ford
- dag-sp
- 0-1-bfs
- negative-cycle
- all-pairs

## Learning Sources

| Source | Type |
| --- | --- |
| [Princeton Shortest Paths](https://algs4.cs.princeton.edu/44sp/) | `Course` |
| [MIT 6.006 Dijkstra and DAG shortest paths](https://courses.csail.mit.edu/6.006/fall09/lecture_notes/lecture16.pdf) | `Course` |
| [OI Wiki shortest path](https://en.oi-wiki.org/graph/shortest-path/) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Problem Set](https://cses.fi/problemset/) | `Practice` |
| [Library Checker shortest path](https://judge.yosupo.jp/problem/shortest_path) | `Practice` |
| [USACO contest archive](https://usaco.org/index.php?page=contests) | `Practice` |

## Curated External Problems

### All Pairs DP

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Shortest Routes II](https://cses.fi/problemset/task/1672) | `CSES` | `Medium` | APSP | Floyd-Warshall; Dense-Graph DP; Distance Matrix | Matrix DP; Transitive Relaxation; INF Handling | All-Pairs Shortest Path; Floyd-Warshall; All-Pairs; Undirected Weighted | Dense-graph shortest paths with repeated queries. |

### All Pairs Shortest Paths

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [バスと避けられない運命](https://atcoder.jp/contests/abc012/tasks/abc012_4) | `AtCoder` | `Hard` | APSP | All-Pairs DP; Radius Minimization; Dense Graph Reasoning | Floyd-Warshall; Graph Distances; Minimax Thinking | Floyd-Warshall; Graph Center; Minimax Distance | A modeling-heavy shortest-path problem where the answer is a graph center. |

### Classic Dijkstra

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Dijkstra?](https://codeforces.com/problemset/problem/20/C) | `Codeforces` | `Medium` | Dijkstra | Priority Queue Dijkstra; Parent Pointers; Simple Path Output | Priority Queue; Weighted Graphs; Path Recovery | Weighted Graph; Shortest Route; Path Reconstruction | The iconic shortest-path path-reconstruction problem every graph learner should know. |

### Dijkstra

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Shortest Routes I](https://cses.fi/problemset/task/1671) | `CSES` | `Easy` | Dijkstra | Priority Queue Relaxation; Distance Array; Outdated-State Skipping | Weighted Graphs; Priority Queues; Adjacency Lists | Single-Source Shortest Path; Weighted Digraph; Priority Queue; Single-Source; Directed Weighted | Straight Dijkstra baseline from one source. |

### Dijkstra Plus Counting

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Investigation](https://cses.fi/problemset/task/1202) | `CSES` | `Medium` | Dijkstra | Augmented Relaxations; Path Counting; Tie Handling | Modular Arithmetic; Shortest-Path DAG Intuition | Count Shortest Paths; Min/Max Edges; Mod Arithmetic; Counts; Min/Max Hops | Shortest paths plus route counting and hop-range metadata. |

### Layered Dijkstra

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Flight Discount](https://cses.fi/problemset/task/1195) | `CSES` | `Medium` | Dijkstra | Two-State Dijkstra; Forward And Reverse Distances; Coupon Use | State Expansion; Graph Modeling | One-Time Discount; Layered Graph; Stateful Shortest Path; State Expansion | Shortest path with one special edge-use state. |

### Negative Cycle Handling

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [High Score](https://cses.fi/problemset/task/1673) | `CSES` | `Hard` | Bellman-Ford | Bellman-Ford; Cycle Reachability; Score Inversion | Negative Weights; Reachability | Negative Cycles; Maximum Path; Cycle Detection; Longest Path Transform | A classic transformation from maximum-score routing to negative-cycle detection. |

### Negative Cycle Witness

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Cycle Finding](https://cses.fi/problemset/task/1197) | `CSES` | `Hard` | Bellman-Ford | Bellman-Ford Witness Extraction; Parent Recovery; Cycle Backtracking | Parent Pointers; Negative Edges | Negative Cycle; Witness Cycle; Directed Graph; Cycle Reconstruction | Canonical negative-cycle detection and extraction problem. |

### Path Restoration

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Shortest Path](https://judge.yosupo.jp/problem/shortest_path) | `Library Checker` | `Medium` | Path Reconstruction | Distance Predecessor Arrays; Path Rebuilding; Single-Source SSSP | Dijkstra; Parent Recovery; Directed Graphs | Weighted Digraph; Route Output; Dijkstra | A very clean verification-style shortest path problem with route restoration. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `QOS` | Chất lượng dịch vụ | `primary` | `hard` | shortest path plus dp; kth lexicographic path; bounded slack states | [Note](../../../practice/ladders/graphs/shortest-paths/qos.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/shortest-paths/qos.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
