# Graphs -> Tree Isomorphism

Canonical subtree encoding for rooted unordered trees, with unrooted comparison handled by trying one or two tree centers first.

- Topic slug: `graphs/tree-isomorphism`
- Tutorial page: [Open tutorial](../../../topics/graphs/tree-isomorphism/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/graphs/tree-isomorphism/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `2`

## Microtopics

- rooted-tree-isomorphism
- canonical-encoding
- ahu-style
- tree-centers
- unordered-children
- subtree-signatures

## Learning Sources

| Source | Type |
| --- | --- |
| [Competitive Programming 4 contents](https://cpbook.net/details?cp=4) | `Reference` |
| [CSES Tree Isomorphism I](https://cses.fi/problemset/task/1700) | `Practice` |
| [CSES Tree Isomorphism II](https://cses.fi/problemset/task/1701) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Tree Isomorphism hot sheet](../../../notebook/tree-isomorphism-hot-sheet.md) | `quick reference` |
| [Tree Isomorphism I note](../../../practice/ladders/graphs/tree-isomorphism/treeisomorphism1.md) | `flagship note` |
| [Trees tutorial](../../../topics/graphs/trees/README.md) | `compare point` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |
| [Graph cheatsheet](../../../notebook/graph-cheatsheet.md) | `quick reference` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Tree Isomorphism I](https://cses.fi/problemset/task/1700) | `CSES` | `Hard` | Canonical Encoding | Bottom-Up Canonicalization; Postorder; Structural Comparison | Rooted Tree; DFS; Parent-Child Structure | Rooted Tree; Canonical Form; Unordered Children | The clean rooted benchmark where the whole task is comparing two unordered rooted trees by canonical subtree types. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Tree Isomorphism II](https://cses.fi/problemset/task/1701) | `CSES` | `Hard` | Tree Centers | Center Rooting; Bottom-Up Canonicalization; Structural Comparison | Tree Isomorphism I; Rooted Tree | Unrooted Tree; Centers; Canonical Form | The natural unrooted sibling: normalize by one or two centers, then reuse the rooted canonical-encoding primitive. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `TREEISOMORPHISM1` | Tree Isomorphism I | `primary` | `hard` | - | [Note](../../../practice/ladders/graphs/tree-isomorphism/treeisomorphism1.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/tree-isomorphism/treeisomorphism1.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
