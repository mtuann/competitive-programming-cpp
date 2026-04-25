# Data Structures -> Splay Tree

Self-adjusting ordered multiset with parent-pointer rotations, subtree-size order statistics, duplicate counts, and a direct bridge into link-cut tree auxiliary splay machinery.

- Topic slug: `data-structures/splay-tree`
- Tutorial page: [Open tutorial](../../../topics/data-structures/splay-tree/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/data-structures/splay-tree/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `3`

## Microtopics

- self-adjusting-bst
- zig-zig-zag
- subtree-size-order-statistics
- duplicate-counts
- amortized-logarithmic
- auxiliary-splay-bridge

## Learning Sources

| Source | Type |
| --- | --- |
| [OI Wiki Splay](https://en.oi-wiki.org/ds/splay/) | `Reference` |
| [Self-Adjusting Binary Search Trees](https://www.cs.cmu.edu/~sleator/papers/self-adjusting.pdf) | `Primary` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Luogu P3369 - 普通平衡树](https://www.luogu.com.cn/problem/P3369) | `Practice` |
| [SPOJ ORDERSET](https://www.spoj.com/problems/ORDERSET/) | `Practice` |
| [Luogu P3391 - 文艺平衡树](https://www.luogu.com.cn/problem/P3391) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Splay Tree hot sheet](../../../notebook/splay-tree-hot-sheet.md) | `quick reference` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |
| [Ordinary Balanced Tree note](../../../practice/ladders/data-structures/splay-tree/ordinarybalancedtree.md) | `anchor note` |
| [Link-Cut Tree tutorial](../../../topics/graphs/link-cut-tree/README.md) | `bridge topic` |
| [Balanced BSTs For Contests](../../../topics/data-structures/balanced-bsts/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Luogu P3369 - 普通平衡树](https://www.luogu.com.cn/problem/P3369) | `Luogu` | `Hard` | Order Statistics | Data-Structure-Heavy; Implementation-Heavy | Bst Order; Subtree Sizes; Rotate And Splay | Rank-Query; Kth-Smallest; Predecessor-Successor | The cleanest first benchmark where the whole statement is one self-adjusting ordered multiset interface and the splay machinery itself is the lesson. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Luogu P3391 - 文艺平衡树](https://www.luogu.com.cn/problem/P3391) | `Luogu` | `Hard` | Sequence Route | Data-Structure-Heavy; String-Like | Rotate And Splay; Lazy Reversal Tag; Sequence View | Sequence; Reverse-Interval | A natural stretch once ordered-set splaying is stable and you want to see the same rotation machinery move into sequence edits with lazy reversal. |

### Compare

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [ORDERSET - Order Statistic Set](https://www.spoj.com/problems/ORDERSET/) | `SPOJ` | `Medium` | Compare Route | Data-Structure-Heavy; Classic | Rotate And Splay; Rank Queries; K-Th Queries | Order-Statistics | A useful compare rep once the splay implementation is trusted, because the same interface can then be contrasted directly against PBDS. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `ORDINARYBALANCEDTREE` | 普通平衡树 | `primary` | `hard` | - | [Note](../../../practice/ladders/data-structures/splay-tree/ordinarybalancedtree.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/splay-tree/ordinarybalancedtree.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
