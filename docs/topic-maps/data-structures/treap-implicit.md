# Data Structures -> Treap / Implicit Treap

Randomized split/merge tree family for ordered-set-by-key treaps and mutable-sequence-by-position implicit treaps.

- Topic slug: `data-structures/treap-implicit`
- Tutorial page: [Open tutorial](../../../topics/data-structures/treap-implicit/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/data-structures/treap-implicit/README.md)
- Repo problems currently tagged here: `2`
- Repo companion pages: `9`
- Curated external problems: `4`

## Microtopics

- random-priorities
- key-order-statistics
- split-merge
- implicit-key
- subtree-size
- sequence-surgery
- ordered-set-vs-sequence
- pair-key-wrapper

## Learning Sources

| Source | Type |
| --- | --- |
| [USACO Guide Treaps](https://usaco.guide/adv/treaps) | `Reference` |
| [CP-Algorithms Treap](https://cp-algorithms.com/data_structures/treap.html) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Salary Queries](https://cses.fi/problemset/task/1144) | `Practice` |
| [CSES Cut and Paste](https://cses.fi/problemset/task/2072) | `Practice` |
| [CSES Substring Reversals](https://cses.fi/problemset/task/2073) | `Practice` |
| [Library Checker Dynamic Sequence Range Affine Range Sum](https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Treap / Implicit Treap hot sheet](../../../notebook/treap-hot-sheet.md) | `quick reference` |
| [Key-based Treap starter route](../../../template-library.md) | `starter route` |
| [Implicit Treap family route](../../../practice/ladders/data-structures/treap-implicit/README.md) | `family route` |
| [Salary Queries note](../../../practice/ladders/data-structures/treap-implicit/salaryqueries.md) | `anchor note` |
| [Cut and Paste note](../../../practice/ladders/data-structures/treap-implicit/cutandpaste.md) | `anchor note` |
| [Persistent Treap tutorial](../../../topics/data-structures/persistent-treap/README.md) | `compare point` |
| [PBDS / Order Statistics Tree tutorial](../../../topics/data-structures/pbds-order-statistics/README.md) | `compare point` |
| [Heaps And Ordered Sets tutorial](../../../topics/data-structures/heaps-and-ordered-sets/README.md) | `compare point` |
| [Lazy Segment Tree tutorial](../../../topics/data-structures/lazy-segment-tree/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Salary Queries](https://cses.fi/problemset/task/1144) | `CSES` | `Medium` | Key-Based Treap, Order Statistics | Data-Structure-Heavy; Query-Heavy | Split And Merge; Pair Key Wrapper | Range-Count; Pair-Key-Wrapper | A strong first key-based benchmark where duplicate-safe pair keys and rank differences are the whole story. |

### Practice

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Cut and Paste](https://cses.fi/problemset/task/2072) | `CSES` | `Hard` | Implicit Treap, Sequence Surgery | Data-Structure-Heavy; Modeling-Heavy | Split And Merge; Subtree Sizes; Implicit Position | Split-Merge; Sequence-Edits | The cleanest first benchmark where cut/paste by position becomes a short split/merge script. |
| [Substring Reversals](https://cses.fi/problemset/task/2073) | `CSES` | `Hard` | Implicit Treap, Sequence Lazy Tags | Data-Structure-Heavy; String-Like | Split And Merge; Lazy Reversal Tag | Reverse; Lazy-Tag | A direct follow-up once split/merge is trusted and one reverse tag becomes the next natural extension. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Dynamic Sequence Range Affine Range Sum](https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum) | `Library Checker` | `Very Hard` | Implicit Treap, Advanced | Data-Structure-Heavy; Verification | Lazy Propagation; Split And Merge | Affine-Lazy; Range-Sum | The canonical verifier-style stretch once the implicit-treap family is extended with aggregates and lazy tags. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `CUTANDPASTE` | Cut and Paste | `primary` | `hard` | - | [Note](../../../practice/ladders/data-structures/treap-implicit/cutandpaste.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/treap-implicit/cutandpaste.cpp) |
| `SALARYQUERIES` | Salary Queries | `primary` | `medium` | - | [Note](../../../practice/ladders/data-structures/treap-implicit/salaryqueries.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/treap-implicit/salaryqueries.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
