# Graphs -> Topological Sort And SCC

Compress directed graphs into DAGs, reason about dependencies, and detect strongly connected structure.

- Topic slug: `graphs/scc-toposort`
- Tutorial page: [Open tutorial](../../../topics/graphs/scc-toposort/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/graphs/scc-toposort/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `0`
- Curated external problems: `9`

## Microtopics

- dag
- indegree
- kahn
- kosaraju
- tarjan
- condensation-graph
- 2-sat

## Learning Sources

| Source | Type |
| --- | --- |
| [Princeton Directed Graphs](https://algs4.cs.princeton.edu/42directed/index.php) | `Course` |
| [cp-algorithms topological sort](https://cp-algorithms.com/graph/topological-sort.html) | `Reference` |
| [USACO Guide SCC](https://usaco.guide/adv/SCC) | `Reference` |

## Practice And Follow-Up Sources

| Source | Type |
| --- | --- |
| [CSES Problem Set](https://cses.fi/problemset/) | `Practice` |
| [Library Checker SCC](https://judge.yosupo.jp/problem/scc) | `Practice` |
| [IOI tasks archive](https://stats.ioinformatics.org/tasks/) | `Practice` |

## Curated External Problems

### Condensation DAG

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Coin Collector](https://cses.fi/problemset/task/1686) | `CSES` | `Hard` | DAG DP | SCC Compression; Post-Order DP; Component Aggregation | SCC; Component Weights | SCC Condensation; DP On DAG; Weighted Nodes; Max Path Weight | A strong SCC-to-DAG condensation problem with a useful optimization layer. |

### DAG DP

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Game Routes](https://cses.fi/problemset/task/1681) | `CSES` | `Medium` | DAG DP | Topo-Based DP; Path Counts; Mod Arithmetic | Topological Sort; DP On Dags; Modular Arithmetic | Path Counting; Topological Order; Mod Arithmetic | A classic DAG dynamic programming problem that depends on a topological order. |

### DAG Longest Path

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Longest Flight Route](https://cses.fi/problemset/task/1680) | `CSES` | `Medium` | DAG DP | Topo-Based DP; Parent Reconstruction; Reachability Filtering | Topological Sort; Path Recovery | Longest Path; Topological Order; Path Reconstruction | A very clean longest-path-in-DAG template with route reconstruction. |

### Lexicographic Topo

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Course Schedule II](https://cses.fi/problemset/task/1757) | `CSES` | `Medium` | Lexicographic | Priority-Queue Kahn; Smallest Available Node; Deterministic Order | Topological Sort; Priority Queue; Directed Acyclic Graphs | Lexicographic Order; Topological Sort; Directed Acyclic Graph; Lexicographic Topo; DAG; Ordering | Variant with a stronger ordering requirement. |

### SCC Basics

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Strongly Connected Components](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C) | `AOJ` | `Medium` | - | Kosaraju; Tarjan; Component Ids | DFS; Directed Graphs; Stack Order | Mutual Reachability; Tarjan; Kosaraju; Component Queries | The official SCC fundamentals problem from AOJ. |

### SCC Labeling

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Planets and Kingdoms](https://cses.fi/problemset/task/1683) | `CSES` | `Medium` | Condensation | Kosaraju Or Tarjan; Component Numbering; Condensation DAG | SCC; DFS; Component Compression | SCC Labels; Kingdoms; Directed Graph; Strongly Connected Components; Labels | The standard SCC labeling problem in a contest-friendly format. |

### Strong Connectivity

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Flight Routes Check](https://cses.fi/problemset/task/1682) | `CSES` | `Medium` | Reachability | SCC Decomposition; Condensation Reasoning; Counterexample Extraction | SCC; DFS | Strong Connectivity; Constructive Counterexample | A pure strong-connectivity check with a useful constructive witness if it fails. |

### Topological Sort

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Course Schedule](https://cses.fi/problemset/task/1679) | `CSES` | `Easy` | DAG | Kahn Queue; In-Degree Tracking; Valid Order Output | Directed Graphs; In-Degree; Queues | Topological Sort; Prerequisites; Ordering; Kahn | The simplest topological-ordering template with a clear feasibility check. |
| [Topological Sort](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B) | `AOJ` | `Medium` | DFS | DFS Finish Order; Stack Reversal; DAG Validation | Directed Graphs; Finish Times | DAG; Ordering; Directed Graph; Kahn | The official graph-library style topological sort problem. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `COURSESCHEDULE` | Course Schedule | `primary` | `medium` | kahn topological sort; indegree peeling; cycle by failed ordering | [Note](../../../practice/ladders/graphs/scc-toposort/courseschedule.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/scc-toposort/courseschedule.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
