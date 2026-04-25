# Graphs -> Bridges, Articulation, And BCC

Low-link structure in undirected graphs: critical edges, critical vertices, and block-cut style decomposition.

- Topic slug: `graphs/bridges-articulation`
- Tutorial page: [Open tutorial](../../../topics/graphs/bridges-articulation/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/graphs/bridges-articulation/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `4`
- Curated external problems: `5`

## Microtopics

- low-link
- bridge
- articulation
- two-edge-connected
- block-cut-tree
- biconnected-component

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms bridges](https://cp-algorithms.com/graph/bridge-searching.html) | `Reference` |
| [cp-algorithms articulation points](https://cp-algorithms.com/graph/cutpoints.html) | `Reference` |
| [USACO Guide BCCs and 2CCs](https://usaco.guide/adv/BCC-2CC) | `Reference` |
| [OI Wiki biconnected components](https://en.oi-wiki.org/graph/bcc/) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Problem Set](https://cses.fi/problemset/) | `Practice` |
| [Library Checker Two-Edge-Connected Components](https://judge.yosupo.jp/problem/two_edge_connected_components) | `Practice` |
| [USACO contest archive](https://usaco.org/index.php?page=contests) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Low-Link hot sheet](../../../notebook/lowlink-hot-sheet.md) | `quick reference` |
| [Low-Link starter route](../../../template-library.md) | `starter route` |
| [Necessary Roads note](../../../practice/ladders/graphs/bridges-articulation/necessaryroads.md) | `anchor note` |
| [Graph cheatsheet](../../../notebook/graph-cheatsheet.md) | `quick reference` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Necessary Cities](https://cses.fi/problemset/task/2077) | `CSES` | `Medium` | Low-Link | Low-Link DFS; Root Special Case; Critical Vertex Output | DFS; Undirected Graphs; Low-Link Inequalities | Critical Vertices; Root Case; Cut Vertices | The matching articulation-point counterpart to Necessary Roads. |
| [Necessary Roads](https://cses.fi/problemset/task/2076) | `CSES` | `Medium` | Low-Link | Low-Link DFS; Bridge Detection; Critical Edge Output | DFS; Undirected Graphs; Entry Times | Critical Edges; DFS Tree; Bridge Detection | The cleanest bridge-only contest problem for learning the strict low-link inequality. |

### Practice

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Two-Edge-Connected Components](https://judge.yosupo.jp/problem/two_edge_connected_components) | `Library Checker` | `Medium` | Two-Edge-Connected Components | Bridge Removal; Component Compression; Tree Of Components | Bridge Detection; DFS; Connected Components | Bridge Compression; 2-Edge Connectivity | A direct verifier once bridges themselves are trusted and you want the compression layer. |

### Classics

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Submerging Islands](https://www.spoj.com/problems/SUBMERGE/) | `SPOJ` | `Medium` | Classic | Low-Link DFS; Cut Vertex Counting; Root Handling | DFS; Undirected Graphs; Low-Link | Cut Vertices; Articulation Points | A classic articulation-point problem where the root case and repeated reporting both matter. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Forbidden Cities](https://cses.fi/problemset/task/1705) | `CSES` | `Hard` | Bcc, Block-Cut Tree | Block-Cut Tree; LCA On Reduced Structure; Query Reduction | Articulation Points; Trees; LCA | Vertex-Biconnected Components | The strongest practical reason to go beyond plain articulation points into full block-cut structure. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `NECESSARYROADS` | Necessary Roads | `primary` | `medium` | low-link; bridge detection; dfs tree critical edge | [Note](../../../practice/ladders/graphs/bridges-articulation/necessaryroads.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/bridges-articulation/necessaryroads.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
