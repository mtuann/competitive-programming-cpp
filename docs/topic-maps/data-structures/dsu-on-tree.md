# Data Structures -> DSU On Tree / Small-To-Large

Rooted-tree subtree queries where each child contributes a mergeable container and smaller containers are merged into larger surviving ones.

- Topic slug: `data-structures/dsu-on-tree`
- Tutorial page: [Open tutorial](../../../topics/data-structures/dsu-on-tree/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/data-structures/dsu-on-tree/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `6`
- Curated external problems: `2`

## Microtopics

- small-to-large-merging
- subtree-container
- frequency-map-merge
- sack-compare-point
- subtree-distinct
- amortized-doubling

## Learning Sources

| Source | Type |
| --- | --- |
| [USACO Guide Small-To-Large Merging](https://usaco.guide/plat/merging) | `Reference` |
| [OI Wiki DSU on Tree](https://en.oi-wiki.org/graph/dsu-on-tree/) | `Reference` |
| [SOI Wiki Smaller to Larger](https://soi.ch/wiki/smaller-to-larger/) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Distinct Colors](https://cses.fi/problemset/task/1139/) | `Practice` |
| [Codeforces Lomsat gelral](https://codeforces.com/problemset/problem/600/E) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [DSU On Tree hot sheet](../../../notebook/dsu-on-tree-hot-sheet.md) | `quick reference` |
| [Distinct Colors note](../../../practice/ladders/data-structures/dsu-on-tree/distinctcolors.md) | `anchor note` |
| [DSU on tree starter route](../../../template-library.md) | `starter route` |
| [DSU tutorial](../../../topics/data-structures/dsu/README.md) | `adjacent tutorial` |
| [Tree DP tutorial](../../../topics/dp/tree-dp/README.md) | `compare point` |
| [Mo's Algorithm tutorial](../../../topics/data-structures/mos-algorithm/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Distinct Colors](https://cses.fi/problemset/task/1139) | `CSES` | `Hard` | Subtree Queries | Small-To-Large Merging; Subtree Frequency Maps; Offline Aggregation | Rooted Tree; Frequency Maps; Subtree Traversal | Distinct Values; Subtree Aggregation; Small-To-Large | The cleanest first benchmark where each subtree owns a mergeable color-frequency container and the whole optimization is just small-to-large merging. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Lomsat gelral](https://codeforces.com/problemset/problem/600/E) | `Codeforces` | `Hard` | Subtree Queries | Small-To-Large Merging; Frequency Aggregation; Heavy Child Compare Point | DSU On Tree; Frequency Maps; Subtree Traversal | Color Frequency; Subtree Aggregation; Small-To-Large | A classic follow-up where the merged container must track richer frequency information than just distinct-count size. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `DISTINCTCOLORS` | Distinct Colors | `primary` | `hard` | - | [Note](../../../practice/ladders/data-structures/dsu-on-tree/distinctcolors.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/dsu-on-tree/distinctcolors.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
