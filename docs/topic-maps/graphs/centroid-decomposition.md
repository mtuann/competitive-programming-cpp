# Graphs -> Centroid Decomposition

Balanced recursive tree splitting, centroid-tree ancestors, and path-through-centroid divide and conquer on static trees.

- Topic slug: `graphs/centroid-decomposition`
- Tutorial page: [Open tutorial](../../../topics/graphs/centroid-decomposition/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/graphs/centroid-decomposition/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `5`

## Microtopics

- centroid
- centroid-tree
- balanced-split
- centroid-ancestor-chain
- nearest-marked
- path-count-through-centroid

## Learning Sources

| Source | Type |
| --- | --- |
| [USACO Guide Centroid Decomposition](https://usaco.guide/plat/centroid?lang=java) | `Reference` |
| [OI Wiki tree centroid](https://en.oi-wiki.org/graph/tree-centroid/) | `Reference` |
| [OI Wiki tree divide](https://en.oi-wiki.org/graph/tree-divide/) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Problem Set](https://cses.fi/problemset/) | `Practice` |
| [Codeforces problemset](https://codeforces.com/problemset) | `Practice` |
| [USACO contest archive](https://usaco.org/index.php?page=contests) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Centroid hot sheet](../../../notebook/centroid-hot-sheet.md) | `quick reference` |
| [Centroid starter route](../../../template-library.md) | `starter route` |
| [Ciel the Commander note](../../../practice/ladders/graphs/centroid-decomposition/cielthecommander.md) | `anchor note` |
| [Trees tutorial](../../../topics/graphs/trees/README.md) | `adjacent tutorial` |
| [Heavy-Light Decomposition tutorial](../../../topics/graphs/hld/README.md) | `compare point` |

## Curated External Problems

### Warm-Up

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Finding a Centroid](https://cses.fi/problemset/task/2079) | `CSES` | `Medium` | Trees | Subtree Sizes; Balance Check; Candidate Descent | DFS; Subtree Sizes; Rooted Tree | Subtree Sizes; Balance Check | The cleanest warm-up for the centroid existence proof and the heavy-child walk used before full decomposition. |

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Ciel the Commander](https://codeforces.com/problemset/problem/321/C) | `Codeforces` | `Hard` | Construction | Centroid Decomposition; Recursive Labeling; Tree Partition | Centroid Basics; Static Trees; Subtree Sizes | Centroid Tree; Recursive Labeling; Balanced Split | The strongest first full decomposition problem because the answer is literally the centroid-tree depth labeling. |

### Practice

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Xenia and Tree](https://codeforces.com/problemset/problem/342/E) | `Codeforces` | `Hard` | Queries | Centroid Ancestors; Distance Aggregation; Online Queries | Centroid Decomposition; Tree Distances; O(log N) Ancestor Walk | Nearest Marked Node; Centroid Ancestors; Distance Aggregation | The canonical update/query problem where each operation becomes a walk over one logarithmic centroid-ancestor chain. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Fixed-Length Paths I](https://cses.fi/problemset/task/2080) | `CSES` | `Hard` | Path Counting | Path Counting; Depth Collection; Frequency Merge | Centroid Decomposition; DFS Depth Collection; Frequency Counting | Exact Length; Depth Histogram; Through-Centroid Counting | The cleanest path-counting benchmark once you trust that every path is handled at the first centroid where its endpoints split. |

### Advanced

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Fixed-Length Paths II](https://cses.fi/problemset/task/2081) | `CSES` | `Hard` | Path Counting | Path Counting; Range Counting; Prefix Merge | Centroid Decomposition; Fixed-Length Paths I; Prefix Sums | Length Range; Depth Prefix Counts; Through-Centroid Counting | A natural next step after exact-length counting, where the merge logic becomes the real difficulty rather than the decomposition itself. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `CIELTHECOMMANDER` | Ciel the Commander | `primary` | `hard` | centroid decomposition; centroid tree labeling; balanced recursive split | [Note](../../../practice/ladders/graphs/centroid-decomposition/cielthecommander.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/centroid-decomposition/cielthecommander.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
