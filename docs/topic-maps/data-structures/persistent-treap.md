# Data Structures -> Persistent Treap

Persistent split/merge treap for branching list or sequence versions where old roots remain alive.

- Topic slug: `data-structures/persistent-treap`
- Tutorial page: [Open tutorial](../../../topics/data-structures/persistent-treap/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/data-structures/persistent-treap/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `1`

## Microtopics

- persistent-treap
- persistent-implicit-treap
- split-merge-persistence
- branching-list-versions
- path-copying
- subtree-sum

## Learning Sources

| Source | Type |
| --- | --- |
| [OI Wiki persistent balanced tree](https://en.oi-wiki.org/ds/persistent-balanced/) | `Reference` |
| [USACO Guide treaps](https://usaco.guide/adv/treaps) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [E-olymp Persistent list](https://eolymp.com/en/problems/2957) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Persistent Treap hot sheet](../../../notebook/persistent-treap-hot-sheet.md) | `quick reference` |
| [Persistent List note](../../../practice/ladders/data-structures/persistent-treap/persistentlist.md) | `anchor note` |
| [Persistent Treap starter route](../../../template-library.md) | `starter route` |
| [Persistent Data Structures tutorial](../../../topics/data-structures/persistent-data-structures/README.md) | `compare point` |
| [Treap / Implicit Treap tutorial](../../../topics/data-structures/treap-implicit/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Persistent List](https://eolymp.com/en/problems/2957) | `E-olymp` | `Hard` | Implicit Treap, Persistence | Data-Structure-Heavy; Modeling-Heavy | Split And Merge | Split-Merge; Branching-Versions; Sequence-Persistence | The cleanest first benchmark where merge/head/tail on old list roots force persistent split/merge treap rather than fixed-array path copying. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `PERSISTENTLIST` | Persistent List | `primary` | `hard` | - | [Note](../../../practice/ladders/data-structures/persistent-treap/persistentlist.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/persistent-treap/persistentlist.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
