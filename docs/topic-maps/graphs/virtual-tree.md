# Graphs -> Virtual Tree / Auxiliary Tree

Compress one marked subset of a static rooted tree into the LCAs and branch points that still matter, then run the real query-local DP on that smaller tree.

- Topic slug: `graphs/virtual-tree`
- Tutorial page: [Open tutorial](../../../topics/graphs/virtual-tree/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/graphs/virtual-tree/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `2`

## Microtopics

- marked-subset
- dfs-order
- consecutive-lca
- ancestor-stack
- compressed-tree
- query-local-dp

## Learning Sources

| Source | Type |
| --- | --- |
| [OI Wiki virtual tree](https://en.oi-wiki.org/graph/virtual-tree/) | `Reference` |
| [Codeforces Round #339 editorial](https://codeforces.com/topic/22942/en1) | `Reference` |
| [Codeforces 613D - Kingdom and its Cities](https://codeforces.com/problemset/problem/613/D) | `Practice` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Codeforces problemset](https://codeforces.com/problemset) | `Practice` |
| [AtCoder problems archive](https://atcoder.jp/contests/archive) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Virtual Tree hot sheet](../../../notebook/virtual-tree-hot-sheet.md) | `quick reference` |
| [Virtual Tree starter route](../../../template-library.md) | `starter route` |
| [Kingdom and its Cities note](../../../practice/ladders/graphs/virtual-tree/kingdomanditscities.md) | `anchor note` |
| [LCA tutorial](../../../topics/graphs/lca/README.md) | `prerequisite tutorial` |
| [Tree DP tutorial](../../../topics/dp/tree-dp/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Kingdom and its Cities](https://codeforces.com/problemset/problem/613/D) | `Codeforces` | `Very Hard` | - | Marked-Subset Compression; LCA; Query-Local DP | LCA; DFS Order; Tree DP | Marked Nodes; LCA; Tree DP; Minimum Separator | The classic first full virtual-tree problem: each query marks only a small set, and the whole solution is compress-then-DP. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Leaf Color](https://atcoder.jp/contests/abc340/tasks/abc340_g) | `AtCoder` | `Very Hard` | - | Marked-Subset Compression; Per-Color Processing; Tree DP | Virtual Tree Build; LCA; Compressed-Tree Reasoning | Marked Nodes; Color Grouping; Compressed Tree | A strong stretch rep once the build step feels automatic and the real challenge becomes choosing the right summary on the compressed tree. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `KINGDOMANDITSCITIES` | Kingdom and its Cities | `primary` | `very hard` | - | [Note](../../../practice/ladders/graphs/virtual-tree/kingdomanditscities.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/virtual-tree/kingdomanditscities.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
