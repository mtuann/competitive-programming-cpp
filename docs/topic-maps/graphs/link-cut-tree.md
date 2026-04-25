# Graphs -> Link-Cut Tree

Dynamic-forest path structure for online link/cut, connectivity, and path aggregates on one changing tree forest.

- Topic slug: `graphs/link-cut-tree`
- Tutorial page: [Open tutorial](../../../topics/graphs/link-cut-tree/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/graphs/link-cut-tree/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `6`
- Curated external problems: `2`

## Microtopics

- preferred-path
- access
- makeroot
- splay-auxiliary-tree
- dynamic-forest
- path-aggregate
- link-cut

## Learning Sources

| Source | Type |
| --- | --- |
| [Sleator and Tarjan - A Data Structure for Dynamic Trees](https://www.cs.cmu.edu/~sleator/papers/dynamic-trees.pdf) | `Primary` |
| [USACO Guide Link Cut Tree](https://usaco.guide/adv/link-cut-tree?lang=cpp) | `Reference` |
| [OI Wiki Link-Cut Tree](https://en.oi-wiki.org/ds/lct/) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Library Checker Dynamic Tree Vertex Add Path Sum](https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum) | `Practice` |
| [Library Checker Dynamic Tree Vertex Set Path Composite](https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Link-Cut Tree hot sheet](../../../notebook/link-cut-tree-hot-sheet.md) | `quick reference` |
| [Link-Cut starter route](../../../template-library.md) | `starter route` |
| [Dynamic Tree Vertex Add Path Sum note](../../../practice/ladders/graphs/link-cut-tree/dynamictreevertexaddpathsum.md) | `anchor note` |
| [Splay Tree tutorial](../../../topics/data-structures/splay-tree/README.md) | `bridge topic` |
| [Heavy-Light Decomposition tutorial](../../../topics/graphs/hld/README.md) | `compare point` |
| [Euler Tour / Subtree Queries tutorial](../../../topics/graphs/euler-tour-subtree/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Dynamic Tree Vertex Add Path Sum](https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum) | `Library Checker` | `Very Hard` | Dynamic Trees | Dynamic Trees; Path Aggregate; Verifier | Rooted Tree Intuition; Preferred Paths; Makeroot / Access | Dynamic Forest; Path Sum; Vertex Add | The cleanest exact verifier for the first narrow link-cut route: dynamic forest, point add on vertices, and path sums. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Dynamic Tree Vertex Set Path Composite](https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite) | `Library Checker` | `Very Hard` | Dynamic Trees | Dynamic Trees; Non-Commutative Query; Verifier | Link-Cut Tree; Path Query Ordering; Function Composition | Dynamic Forest; Path Composite; Non-Commutative | A natural stretch once the basic route is trusted and the path aggregate becomes non-commutative. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `DYNAMICTREEVERTEXADDPATHSUM` | Dynamic Tree Vertex Add Path Sum | `primary` | `very hard` | - | [Note](../../../practice/ladders/graphs/link-cut-tree/dynamictreevertexaddpathsum.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/link-cut-tree/dynamictreevertexaddpathsum.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
