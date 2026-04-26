# Data Structures -> B-Trees

High-fanout multiway search tree for textbook ordered-dictionary breadth, with search and insert taught through root splitting and split-full-child.

- Topic slug: `data-structures/b-trees`
- Tutorial page: [Open tutorial](../../../topics/data-structures/b-trees/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/data-structures/b-trees/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `1`

## Microtopics

- minimum-degree
- multiway-search
- split-full-child
- root-split
- separator-keys
- high-fanout

## Learning Sources

| Source | Type |
| --- | --- |
| [Open Data Structures - 14.2 B-Trees](https://opendatastructures.org/ods-cpp/14_2_B_Trees.html) | `Reference` |
| [Introduction to Algorithms, 4th ed. TOC PDF](https://mitp-content-server.mit.edu/books/content/sectbyfn/books_pres_0/11599/4e_toc.pdf) | `Reference` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [B-Tree hot sheet](../../../notebook/b-tree-hot-sheet.md) | `quick reference` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |
| [B-Tree Dictionary note](../../../practice/ladders/data-structures/b-trees/btreedictionary.md) | `anchor note` |
| [Balanced BSTs For Contests](../../../topics/data-structures/balanced-bsts/README.md) | `compare point` |
| [PBDS / Order Statistics Tree tutorial](../../../topics/data-structures/pbds-order-statistics/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [B-Tree Dictionary Benchmark](https://opendatastructures.org/ods-cpp/14_2_B_Trees.html) | `Open Data Structures` | `Medium` | B-Tree, Textbook Breadth | Data-Structure-Heavy; Implementation-Heavy | Minimum Degree; Separator Keys; Split Full Child | Split-Full-Child; Multiway-Search | The cleanest breadth-first benchmark source where search, root split, and split-full-child are the whole lesson before deletion or B+ tree variants. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `BTREEDICTIONARY` | B-Tree Dictionary | `primary` | `medium` | - | [Note](../../../practice/ladders/data-structures/b-trees/btreedictionary.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/b-trees/btreedictionary.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
