# Data Structures -> Interval Trees

Augmented BST for one live set of half-open intervals, supporting online insert / erase and any-overlap queries through subtree max-right summaries.

- Topic slug: `data-structures/interval-trees`
- Tutorial page: [Open tutorial](../../../topics/data-structures/interval-trees/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/data-structures/interval-trees/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `6`
- Curated external problems: `1`

## Microtopics

- half-open-intervals
- interval-overlap
- subtree-max-right
- augmented-bst
- stabbing-search
- dynamic-interval-set

## Learning Sources

| Source | Type |
| --- | --- |
| [Introduction to Algorithms, 4th ed. TOC PDF](https://mitp-content-server.mit.edu/books/content/sectbyfn/books_pres_0/11599/4e_toc.pdf) | `Reference` |
| [AOJ 0360 Reservation System](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0360) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Interval Tree hot sheet](../../../notebook/interval-tree-hot-sheet.md) | `quick reference` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |
| [Reservation System note](../../../practice/ladders/data-structures/interval-trees/reservationsystem.md) | `anchor note` |
| [Balanced BSTs For Contests](../../../topics/data-structures/balanced-bsts/README.md) | `compare point` |
| [Heaps And Ordered Sets tutorial](../../../topics/data-structures/heaps-and-ordered-sets/README.md) | `compare point` |
| [ODT / Chtholly tutorial](../../../topics/data-structures/odt-chtholly/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Reservation System](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0360) | `AOJ` | `Easy` | Interval Tree, Interval Overlap | Data-Structure-Heavy; Query-Heavy | Half-Open Interval Overlap; Dynamic Interval Set; Subtree Max-Right | Half-Open-Intervals; Overlap-Query; Augmented-Bst | A gentle first benchmark where the real invariant is 'does the new interval overlap anything in the live set?', so subtree max-right augmentation can be practiced directly even though a lighter ordered-set route also exists. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `RESERVATIONSYSTEM` | Reservation System | `primary` | `easy` | - | [Note](../../../practice/ladders/data-structures/interval-trees/reservationsystem.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/interval-trees/reservationsystem.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
