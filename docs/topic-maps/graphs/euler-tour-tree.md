# Graphs -> Euler Tour Tree

Dynamic-forest subtree structure for online link/cut, reroot by sequence rotation, and subtree-side aggregates on one changing tree forest.

- Topic slug: `graphs/euler-tour-tree`
- Tutorial page: [Open tutorial](../../../topics/graphs/euler-tour-tree/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/graphs/euler-tour-tree/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `6`
- Curated external problems: `2`

## Microtopics

- self-loop-token
- directed-edge-token
- make-root-by-rotation
- split-merge-sequence
- dynamic-forest
- subtree-interval
- edge-oriented-subtree

## Learning Sources

| Source | Type |
| --- | --- |
| [OI Wiki Euler Tour Tree](https://en.oi-wiki.org/ds/ett/) | `Reference` |
| [Library Checker Dynamic Tree Vertex Add Subtree Sum statement](https://github.com/yosupo06/library-checker-problems/blob/master/tree/dynamic_tree_vertex_add_subtree_sum/task.md) | `Primary` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Library Checker Dynamic Tree Vertex Add Subtree Sum](https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum) | `Practice` |
| [Library Checker Dynamic Tree Subtree Add Subtree Sum](https://judge.yosupo.jp/problem/dynamic_tree_subtree_add_subtree_sum) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Euler Tour Tree hot sheet](../../../notebook/euler-tour-tree-hot-sheet.md) | `quick reference` |
| [Euler Tour Tree starter route](../../../template-library.md) | `starter route` |
| [Dynamic Tree Vertex Add Subtree Sum note](../../../practice/ladders/graphs/euler-tour-tree/dynamictreevertexaddsubtreesum.md) | `anchor note` |
| [Link-Cut Tree tutorial](../../../topics/graphs/link-cut-tree/README.md) | `compare point` |
| [Euler Tour / Subtree Queries tutorial](../../../topics/graphs/euler-tour-subtree/README.md) | `compare point` |
| [Treap / Implicit Treap tutorial](../../../topics/data-structures/treap-implicit/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Dynamic Tree Vertex Add Subtree Sum](https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum) | `Library Checker` | `Very Hard` | Dynamic Trees | Dynamic Trees; Subtree Aggregate; Verifier | Rooted Tree Intuition; Split / Merge Sequence; Make Root By Rotation | Dynamic Forest; Subtree Sum; Vertex Add | The cleanest exact verifier for the first narrow Euler-tour-tree route: dynamic forest, point add on vertices, and subtree-side sums on one existing edge. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Dynamic Tree Subtree Add Subtree Sum](https://judge.yosupo.jp/problem/dynamic_tree_subtree_add_subtree_sum) | `Library Checker` | `Very Hard` | Dynamic Trees | Dynamic Trees; Lazy Range Update; Verifier | Euler Tour Tree; Subtree Interval View; Lazy Propagation | Dynamic Forest; Lazy Propagation; Subtree Sum | A natural stretch once the point-add route is trusted and the same subtree-side interval view must carry a stronger lazy update. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `DYNAMICTREEVERTEXADDSUBTREESUM` | Dynamic Tree Vertex Add Subtree Sum | `primary` | `very hard` | - | [Note](../../../practice/ladders/graphs/euler-tour-tree/dynamictreevertexaddsubtreesum.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/euler-tour-tree/dynamictreevertexaddsubtreesum.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
