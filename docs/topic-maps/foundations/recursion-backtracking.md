# Foundations -> Recursion And Backtracking

Model explicit search trees cleanly, then decide when pruning is enough and when you should escalate to DP or meet-in-the-middle.

- Topic slug: `foundations/recursion-backtracking`
- Tutorial page: [Open tutorial](../../../topics/foundations/recursion-backtracking/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/foundations/recursion-backtracking/README.md)
- Repo problems currently tagged here: `0`
- Repo companion pages: `2`
- Curated external problems: `3`

## Microtopics

- dfs-generation
- backtracking
- pruning
- branch-ordering
- undo-redo
- search-tree

## Learning Sources

| Source | Type |
| --- | --- |
| [Competitive Programmer's Handbook](https://www.cses.fi/book/book.pdf) | `Reference` |
| [Jeff Erickson - Algorithms](https://jeffe.cs.illinois.edu/teaching/algorithms/index.html) | `Course` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Introductory Problems](https://cses.fi/problemset/list/1/) | `Practice` |
| [CSES Problem Set](https://cses.fi/problemset) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Meet-In-The-Middle tutorial](../../../topics/advanced/meet-in-the-middle/README.md) | `related tutorial` |
| [Bitmask DP tutorial](../../../topics/dp/bitmask-dp/README.md) | `related tutorial` |

## Curated External Problems

### Warm-Up

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Apple Division](https://cses.fi/problemset/task/1623) | `CSES` | `Easy` | - | Implementation | Recursion | Subset Search; Brute Force | A tiny subset-search benchmark that teaches clean recursive branching before heavier optimization. |

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Creating Strings](https://cses.fi/problemset/task/1622) | `CSES` | `Easy` | - | Implementation | Recursion; Sorting | Permutations; Duplicates | A clean permutation-generation route where choice ordering and duplicate handling are the whole lesson. |

### Classics

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Chessboard and Queens](https://cses.fi/problemset/task/1624) | `CSES` | `Medium` | - | Implementation; Pruning | Recursion; Constraint Checks | Pruning; Board Search | A classic pruning benchmark where the search tree is still explicit and understandable. |

## Repo Problems

_No repo problem note is attached yet. Use the repo companion material above for this theory/process-heavy topic._

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
