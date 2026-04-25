# Graphs -> Maximum Flow

Residual graphs, augmenting paths, and cut structure for max-flow and min-cut modeling.

- Topic slug: `graphs/flow`
- Tutorial page: [Open tutorial](../../../topics/graphs/flow/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/graphs/flow/README.md)
- Repo problems currently tagged here: `5`
- Repo companion pages: `2`
- Curated external problems: `8`

## Microtopics

- residual-graph
- augmenting-path
- dinic
- push-relabel
- maxflow-mincut
- edge-disjoint-paths

## Learning Sources

| Source | Type |
| --- | --- |
| [Princeton Max Flow](https://algs4.cs.princeton.edu/64maxflow/) | `Course` |
| [MIT 6.854 flow notes](https://courses.csail.mit.edu/6.854/21/Notes/n06-flow.html) | `Course` |
| [OI Wiki max flow](https://en.oi-wiki.org/graph/flow/max-flow/) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Problem Set](https://cses.fi/problemset/) | `Practice` |
| [USACO contest archive](https://usaco.org/index.php?page=contests) | `Practice` |
| [IOI tasks archive](https://stats.ioinformatics.org/tasks/) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Police Chase note](../../../practice/ladders/graphs/flow/policechase.md) | `anchor note` |
| [Graph cheatsheet](../../../notebook/graph-cheatsheet.md) | `quick reference` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Download Speed](https://cses.fi/problemset/task/1694) | `CSES` | `Medium` | - | Dinic; S-T Max Flow | Network Flow Basics; Residual Graph | Directed Graphs; S-T Cut; Max Flow; Capacity; Network Throughput | Clean source-sink max-flow application. |
| [Maximum Flow](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A) | `AOJ` | `Medium` | - | - | - | Max Flow; Dinic; Network | Official max-flow baseline. |
| [Police Chase](https://cses.fi/problemset/task/1695) | `CSES` | `Medium` | - | - | - | Min Cut; Max Flow; Edge Cut | Exact minimum cut with an output certificate. |

### Classics

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Fast Maximum Flow](https://www.spoj.com/SPOJ/problems/FASTFLOW) | `SPOJ` | `Medium` | Min Cut | Dinic; Residual Graph | Augmenting Paths; Capacity Residuals | Undirected Graphs; Capacity | The standard introductory max-flow/min-cut baseline. |

### Advanced

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Angry Programmer](https://onlinejudge.org/external/115/11506.pdf) | `UVa` | `Hard` | Min Cut, Node Splitting | Node/Edge Splitting; Min Cut Modeling | Flow Modeling; Min Cut Interpretation | Vertex Cuts; Security Model | Combines vertex and edge cuts, which is the classic split-node flow pattern. |
| [Distinct Routes](https://cses.fi/problemset/task/1711) | `CSES` | `Hard` | Path Decomposition | Unit-Capacity Flow; Path Extraction | Augmenting Paths; Route Decomposition | Route Packing; Max Flow; Edge-Disjoint Paths; Route Recovery | Transforms edge-disjoint paths into a flow problem. |

### Cross-Topic

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [The Problem with the Problem Setter](https://onlinejudge.org/external/100/10092.pdf) | `UVa` | `Medium` | Bipartite Flow | Bipartite Flow; Source-Sink Layering | Bipartite Modeling; Flow Conservation | Matching; Assignment | A classic bipartite flow reduction with multiple source groups. |
| [Power Transmission](https://onlinejudge.org/external/103/10330.pdf) | `UVa` | `Hard` | Node Splitting | Vertex Splitting; Capacity Constraints | Flow Modeling; Vertex Capacity To Edge Capacity | Vertex Capacities | Uses node capacities, so it is a textbook vertex-splitting model. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `FFLOW` | Fast Maximum Flow | `primary` | `medium` | maximum flow; undirected capacities; capacity scaling | [Note](../../../practice/ladders/graphs/flow/fflow.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/flow/fflow.cpp) |
| `MCQUERY` | MinCut Query | `primary` | `hard` | all-pairs min-cut; cut tree; count pairs by threshold | [Note](../../../practice/ladders/graphs/flow/mcquery.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/flow/mcquery.cpp) |
| `MINCOST` | Luồng với chi phí nhỏ nhất | `primary` | `hard` | transportation network; flow reconstruction; duplicate-edge overwrite | [Note](../../../practice/ladders/graphs/flow/mincost.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/flow/mincost.cpp) |
| `POLICECHASE` | Police Chase | `primary` | `medium` | unit capacity max flow; residual reachable cut; minimum edge cut certificate | [Note](../../../practice/ladders/graphs/flow/policechase.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/flow/policechase.cpp) |
| `REACTORCOOLING` | Reactor Cooling | `primary` | `hard` | feasible circulation; lower bounds; flow reconstruction | [Note](../../../practice/ladders/graphs/flow/reactorcooling.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/flow/reactorcooling.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
