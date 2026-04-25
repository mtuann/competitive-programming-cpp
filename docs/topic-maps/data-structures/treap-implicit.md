# Data Structures -> Treap / Implicit Treap

Randomized split/merge tree family for ordered-set-by-key treaps and mutable-sequence-by-position implicit treaps.

- Topic slug: `data-structures/treap-implicit`
- Tutorial page: [Open tutorial](../../../topics/data-structures/treap-implicit/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/data-structures/treap-implicit/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `3`

## Microtopics

- random-priorities
- split-merge
- implicit-key
- subtree-size
- sequence-surgery
- ordered-set-vs-sequence

## Learning Sources

| Source | Type |
| --- | --- |
| [USACO Guide Treaps](https://usaco.guide/adv/treaps) | `Reference` |
| [CP-Algorithms Treap](https://cp-algorithms.com/data_structures/treap.html) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Cut and Paste](https://cses.fi/problemset/task/2072) | `Practice` |
| [CSES Substring Reversals](https://cses.fi/problemset/task/2073) | `Practice` |
| [Library Checker Dynamic Sequence Range Affine Range Sum](https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Treap / Implicit Treap hot sheet](../../../notebook/treap-hot-sheet.md) | `quick reference` |
| [Treap starter route](../../../template-library.md) | `starter route` |
| [Cut and Paste note](../../../practice/ladders/data-structures/treap-implicit/cutandpaste.md) | `anchor note` |
| [Heaps And Ordered Sets tutorial](../../../topics/data-structures/heaps-and-ordered-sets/README.md) | `compare point` |
| [Lazy Segment Tree tutorial](../../../topics/data-structures/lazy-segment-tree/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Cut and Paste](https://cses.fi/problemset/task/2072) | `CSES` | `Hard` | Implicit Treap, Sequence Surgery | Data-Structure-Heavy; Modeling-Heavy | Split And Merge; Subtree Sizes; Implicit Position | Split-Merge; Sequence-Edits | The cleanest first benchmark where cut/paste by position becomes a short split/merge script. |

### Practice

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Substring Reversals](https://cses.fi/problemset/task/2073) | `CSES` | `Hard` | Implicit Treap, Sequence Lazy Tags | Data-Structure-Heavy; String-Like | Split And Merge; Lazy Reversal Tag | Reverse; Lazy-Tag | A direct follow-up once split/merge is trusted and one reverse tag becomes the next natural extension. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Dynamic Sequence Range Affine Range Sum](https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum) | `Library Checker` | `Very Hard` | Implicit Treap, Advanced | Data-Structure-Heavy; Verification | Lazy Propagation; Split And Merge | Affine-Lazy; Range-Sum | The canonical verifier-style stretch once the implicit-treap family is extended with aggregates and lazy tags. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `CUTANDPASTE` | Cut and Paste | `primary` | `hard` | - | [Note](../../../practice/ladders/data-structures/treap-implicit/cutandpaste.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/treap-implicit/cutandpaste.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
