# Graphs -> Gomory-Hu Tree

Cut-tree compression for all-pairs min-cut structure in one undirected weighted graph, built with n - 1 max-flow calls.

- Topic slug: `graphs/gomory-hu`
- Tutorial page: [Open tutorial](../../../topics/graphs/gomory-hu/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/graphs/gomory-hu/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `7`

## Microtopics

- all-pairs-mincut
- cut-tree
- gusfield
- maxflow-calls
- undirected-cuts
- mincut-query

## Learning Sources

| Source | Type |
| --- | --- |
| [MIT Gomory-Hu paper mirror](https://web.mit.edu/tabbott/www/papers/gomory-hu.pdf) | `Primary` |
| [UC Davis advanced algorithms](https://www.cs.ucdavis.edu/~martel/222b/) | `Course` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Library Checker Gomory-Hu Tree](https://judge.yosupo.jp/problem/gomory_hu_tree) | `Practice` |
| [Codeforces 343E - Pumping Stations](https://codeforces.com/problemset/problem/343/E) | `Practice` |
| [UVa 11594 - All Pairs Maximum Flow](https://onlinejudge.org/external/115/11594.pdf) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Gomory-Hu hot sheet](../../../notebook/gomory-hu-hot-sheet.md) | `quick reference` |
| [Gomory-Hu starter route](../../../template-library.md) | `starter route` |
| [MCQUERY note](../../../practice/ladders/graphs/gomory-hu/mcquery.md) | `anchor note` |
| [Maximum Flow tutorial](../../../topics/graphs/flow/README.md) | `compare point` |
| [DSU tutorial](../../../topics/data-structures/dsu/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Download Speed](https://cses.fi/problemset/task/1694) | `CSES` | `Medium` | Cuts | - | - | Max Flow; Source-Sink Cut; Network | Good single-pair cut practice before all-pairs cuts. |
| [Maximum Flow](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A) | `AOJ` | `Medium` | Cuts | - | - | Max Flow; Min Cut; Baseline | Core primitive behind Gomory-Hu construction. |
| [Police Chase](https://cses.fi/problemset/task/1695) | `CSES` | `Medium` | Min Cut, Edge-Disjoint Separation, Cuts | S-T Min Cut; Edge Extraction | Max Flow; Cut Extraction | Flow; Roads; Edge Cut; Certificate | Single-pair min cut, useful as the entry point before GH-tree compression. |
| [Gomory-Hu Tree](https://judge.yosupo.jp/problem/gomory_hu_tree) | `Library Checker` | `Hard` | Cut-Trees | - | - | All-Pairs Min-Cut; Tree Of Cuts | The direct canonical problem for the topic. |

### Classics

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Sabotage](https://onlinejudge.org/external/104/10480.pdf) | `UVa` | `Medium` | Min Cut, Global Min Cut | Undirected Min Cut; Cut Extraction | Max Flow; Minimum Cut | Flow; Cuts; Graph Partition | A classic minimum-cut problem that motivates cut-tree thinking. |

### Advanced

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Pumping Stations](https://codeforces.com/problemset/problem/343/E) | `Codeforces` | `Very Hard` | Gomory-Hu Tree, Pairwise Min Cuts | Gh Tree Reasoning; Cut-Tree Structure | Max Flow; Min Cut; Tree Compression | Flow; Trees; Divide And Conquer | A famous Codeforces problem whose intended insight is cut-tree structure. |

### Theory / Course

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [All Pairs Maximum Flow](https://onlinejudge.org/external/115/11594.pdf) | `UVa` | `Hard` | Gomory-Hu Tree, All-Pairs Min Cut | Build Cut Tree; Query Path Minima | Max Flow; Min Cut; Tree Path Minima | Flow; Trees | This is essentially the GH-tree use case: compress all pairwise min-cuts. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `MCQUERY` | MinCut Query | `primary` | `hard` | all-pairs min-cut; cut tree; count pairs by threshold | [Note](../../../practice/ladders/graphs/gomory-hu/mcquery.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/flow/mcquery.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
