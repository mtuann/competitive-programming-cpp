# Data Structures -> PBDS / Order Statistics Tree

GNU PBDS ordered tree for online rank, k-th, and count-smaller queries, with a pair-key wrapper when duplicates matter.

- Topic slug: `data-structures/pbds-order-statistics`
- Tutorial page: [Open tutorial](../../../topics/data-structures/pbds-order-statistics/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/data-structures/pbds-order-statistics/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `3`

## Microtopics

- order-of-key
- find-by-order
- dynamic-rank
- kth-smallest
- pair-key-wrapper
- gnu-pbds

## Learning Sources

| Source | Type |
| --- | --- |
| [GCC tree_order_statistics_node_update](https://gcc.gnu.org/onlinedocs/libstdc%2B%2B/ext/pb_ds/tree_order_statistics_node_update.html) | `Primary` |
| [GCC PBDS manual](https://gcc.gnu.org/onlinedocs/gcc-9.3.0/libstdc%2B%2B/manual/manual/policy_data_structures.html) | `Primary` |
| [Competitive Programmer's Handbook](https://cses.fi/book/book.pdf) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [SPOJ ORDERSET](https://www.spoj.com/problems/ORDERSET/) | `Practice` |
| [CSES Josephus Problem II](https://cses.fi/problemset/task/2163) | `Practice` |
| [CSES Salary Queries](https://cses.fi/problemset/task/1144) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Order Statistics Tree hot sheet](../../../notebook/order-statistics-tree-hot-sheet.md) | `quick reference` |
| [PBDS starter route](../../../template-library.md) | `starter route` |
| [ORDERSET note](../../../practice/ladders/data-structures/pbds-order-statistics/orderset.md) | `anchor note` |
| [Heaps And Ordered Sets tutorial](../../../topics/data-structures/heaps-and-ordered-sets/README.md) | `compare point` |
| [Fenwick Tree tutorial](../../../topics/data-structures/fenwick-tree/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [ORDERSET - Order Statistic Set](https://www.spoj.com/problems/ORDERSET/) | `SPOJ` | `Medium` | Order Statistics | Data-Structure-Heavy; Classic | Ordered Set Invariant; Order Of Key; Find By Order | Kth-Smallest; Rank-Query | The cleanest first benchmark where the whole problem is insert, delete, k-th, and count-smaller on one dynamic ordered set. |

### Practice

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Josephus Problem II](https://cses.fi/problemset/task/2163) | `CSES` | `Hard` | Circular Elimination | Simulation-Heavy; Data-Structure-Heavy | Find By Order; Alive Set Maintenance; Modulo Indexing | Find-By-Order; Josephus | A clean follow-up where the alive set stays explicit and find_by_order drives repeated circular removals. |

### Bridge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Salary Queries](https://cses.fi/problemset/task/1144) | `CSES` | `Medium` | Order Statistics | Query-Heavy; Data-Structure-Heavy | Pair-Key Wrapper; Order Of Key; Count In Range | Duplicate-Safe-Wrapper; Range-Count | A very teachable bridge from unique sets to duplicate-safe pair-key wrappers for count-in-range queries under updates. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `ORDERSET` | Order Statistic Set | `primary` | `medium` | - | [Note](../../../practice/ladders/data-structures/pbds-order-statistics/orderset.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/pbds-order-statistics/orderset.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
