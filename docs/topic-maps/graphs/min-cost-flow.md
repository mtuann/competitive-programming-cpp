# Graphs -> Min-Cost Flow

Successive shortest augmenting paths, potentials, and reduced costs for transportation-style optimization.

- Topic slug: `graphs/min-cost-flow`
- Tutorial page: [Open tutorial](../topics/graphs/min-cost-flow/README.md)
- Ladder page: [Open ladder](../practice/ladders/graphs/flow/README.md)
- Repo problems currently tagged here: `1`
- Curated external problems: `10`

## Microtopics

- potentials
- reduced-cost
- successive-shortest-path
- negative-cycle
- assignment
- circulation

## Learning Sources

| Source | Type |
| --- | --- |
| [MIT 6.854 min-cost flow notes](https://courses.csail.mit.edu/6.854/20/Notes/n09-mincostflow.html) | `course` |
| [cp-algorithms min-cost flow](https://cp-algorithms.com/graph/min_cost_flow.html) | `trusted guide` |
| [USACO Guide min-cost flow](https://usaco.guide/adv/min-cost-flow?lang=cpp) | `trusted guide` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Library Checker min_cost_b_flow](https://judge.yosupo.jp/problem/min_cost_b_flow) | `problem` |
| [CSES Problem Set](https://cses.fi/problemset/) | `problem set` |
| [USACO contest archive](https://usaco.org/index.php?page=contests) | `contest archive` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Crime Wave - The Sequel](https://onlinejudge.org/external/107/10746.pdf) | `UVa` | `Medium` | Min-Cost Max-Flow, Assignment | Assignment Model; Min-Cost Matching | Bipartite Matching; Shortest Augmenting Path | Bipartite Matching | A classic costed matching problem on a bipartite graph. |
| [Minimum Cost Flow](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B) | `AOJ` | `Medium` | - | - | - | Min-Cost Max-Flow; Potentials; Shortest Augmenting Path | Official min-cost-flow baseline. |
| [Distinct Routes II](https://cses.fi/problemset/task/2130) | `CSES` | `Hard` | - | - | - | K Routes; Path Reconstruction | A direct cost-minimization variant over route decompositions. |
| [Parcel Delivery](https://cses.fi/problemset/task/2121) | `CSES` | `Hard` | - | - | - | Capacitated Edges; Transport | Natural costed transport network formulation. |
| [Task Assignment](https://cses.fi/problemset/task/2129) | `CSES` | `Hard` | - | - | - | Assignment; Bipartite Matching; Cost Matrix | Classic assignment problem, often solved as min-cost flow. |

### Classics

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Another Assignment Problem](https://www.spoj.com/problems/ASSIGN4) | `SPOJ` | `Medium` | Assignment | Costed Bipartite Matching; Successive Shortest Augmenting Path | Bipartite Matching; Costed Residual Graphs | Matching | Direct minimum-cost assignment, ideal for MCMF practice. |

### Advanced

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Data Flow](https://onlinejudge.org/external/105/10594.pdf) | `UVa` | `Hard` | Capacity Planning | Binary Search Over Time; Min-Cost Flow Feasibility | Capacity Constraints; Cost-Aware Flow | Latency; Throughput | Blends feasibility, capacity, and path cost into one MCMF model. |
| [Dijkstra, Dijkstra.](https://onlinejudge.org/external/108/10806.pdf) | `UVa` | `Hard` | Min-Cost Max-Flow, Disjoint Paths | Successive Shortest Augmenting Path | Shortest Path On Residual Graph; Potentials | Shortest Path | Classic two-disjoint-paths min-cost-flow problem. |
| [Yet Another Assignment Problem](https://www.spoj.com/problems/ASSIGN5) | `SPOJ` | `Hard` | Scheduling | Time-Expanded Scheduling; Cost Minimization | Min-Cost Flow Modeling; Job Assignment | Assignment | Scheduling with costs and capacities is a richer MCMF variant. |

### Cross-Topic

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Warehouse](https://onlinejudge.org/external/108/10888.pdf) | `UVa` | `Hard` | Grid Modeling | Graph Construction From Grid; Minimum Cost Assignment | Shortest Path Distances; Min-Cost Matching | Grid; Movement Cost | Grid movement costs map neatly to min-cost assignment. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `MINCOST` | Luồng với chi phí nhỏ nhất | `secondary` | `hard` | transportation network; flow reconstruction; duplicate-edge overwrite | [Note](../practice/ladders/graphs/flow/mincost.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/flow/mincost.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
