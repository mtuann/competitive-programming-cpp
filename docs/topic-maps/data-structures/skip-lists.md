# Data Structures -> Skip Lists

Probabilistically balanced ordered dictionary with random-height towers, forward pointers, and one update-array search path for expected-logarithmic search / insert / erase.

- Topic slug: `data-structures/skip-lists`
- Tutorial page: [Open tutorial](../../../topics/data-structures/skip-lists/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/data-structures/skip-lists/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `1`

## Microtopics

- random-height
- forward-pointer-towers
- update-array
- expected-logarithmic
- ordered-dictionary
- probabilistic-balancing

## Learning Sources

| Source | Type |
| --- | --- |
| [Open Data Structures - 4.1 Basic Structure](https://opendatastructures.org/ods-cpp/4_1_Basic_Structure.html) | `Reference` |
| [Pugh - Skip Lists: A Probabilistic Alternative to Balanced Trees](https://epaperpress.com/sortsearch/download/skiplist.pdf) | `Reference` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Skiplist hot sheet](../../../notebook/skiplist-hot-sheet.md) | `quick reference` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |
| [Skiplist Dictionary note](../../../practice/ladders/data-structures/skip-lists/skiplistdictionary.md) | `anchor note` |
| [PBDS / Order Statistics Tree tutorial](../../../topics/data-structures/pbds-order-statistics/README.md) | `compare point` |
| [Treap / Implicit Treap tutorial](../../../topics/data-structures/treap-implicit/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Skiplist Dictionary Benchmark](https://opendatastructures.org/ods-cpp/4_1_Basic_Structure.html) | `Open Data Structures` | `Medium` | Skiplist, Textbook Breadth | Data-Structure-Heavy; Implementation-Heavy | Random Height; Update Array; Tower Search Path | Random Heights; Expected Logarithmic | A clean breadth benchmark where the whole lesson is probabilistic balancing through forward-pointer towers and one update[] search path, not contest-first rank queries or split/merge. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `SKIPLISTDICTIONARY` | Skiplist Dictionary | `primary` | `medium` | - | [Note](../../../practice/ladders/data-structures/skip-lists/skiplistdictionary.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/skip-lists/skiplistdictionary.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
