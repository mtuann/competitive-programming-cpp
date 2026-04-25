# Data Structures -> Lazy Segment Tree

Deferred-tag segment tree for online range updates and range queries when a full segment can absorb the update in closed form.

- Topic slug: `data-structures/lazy-segment-tree`
- Tutorial page: [Open tutorial](../../../topics/data-structures/lazy-segment-tree/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/data-structures/lazy-segment-tree/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `4`
- Curated external problems: `4`

## Microtopics

- lazy-propagation
- range-add
- range-sum
- apply
- push
- tag-composition
- range-assign

## Learning Sources

| Source | Type |
| --- | --- |
| [AtCoder ACL Lazy Segtree](https://atcoder.github.io/ac-library/production/document_en/lazysegtree.html) | `Primary` |
| [cp-algorithms segment tree](https://cp-algorithms.com/data_structures/segment_tree.html) | `Reference` |
| [OI Wiki segment tree](https://en.oi-wiki.org/ds/seg/) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [SPOJ Classical](https://www.spoj.com/problems/classical/) | `Practice` |
| [CSES Problem Set](https://cses.fi/problemset) | `Practice` |
| [AtCoder Library Practice Contest](https://atcoder.jp/contests/practice2/tasks?lang=en) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Lazy Segment Tree hot sheet](../../../notebook/lazy-segment-tree-hot-sheet.md) | `quick reference` |
| [Lazy starter route](../../../template-library.md) | `starter route` |
| [HORRIBLE note](../../../practice/ladders/data-structures/lazy-segment-tree/horriblequeries.md) | `anchor note` |
| [Segment Tree hot sheet](../../../notebook/segment-tree-hot-sheet.md) | `quick reference` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [HORRIBLE](https://www.spoj.com/problems/HORRIBLE/) | `SPOJ` | `Medium` | Range Queries, Lazy Propagation | Data-Structure-Heavy; Query-Heavy | Segment Tree Basics; Difference Arrays Contrast; Range Updates | Range-Add; Range-Sum; Classic | The cleanest exact range add + range sum benchmark for a first lazy segment tree. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Polynomial Queries](https://cses.fi/problemset/task/1736) | `CSES` | `Hard` | Range Queries | Data-Structure-Heavy; Math-Heavy | Lazy Propagation; Range Arithmetic; Tag Design | Lazy-Propagation; Range-Update; Arithmetic-Progression | A memorable benchmark where the update itself carries structure, not just one additive delta. |
| [Range Updates and Sums](https://cses.fi/problemset/task/1735) | `CSES` | `Hard` | Range Queries | Data-Structure-Heavy | Lazy Propagation; Tag Composition; Range Assign | Lazy-Propagation; Range-Add; Range-Assign | The natural next benchmark once plain additive tags are stable and tag precedence becomes the real challenge. |

### Advanced

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Range Affine Range Sum](https://atcoder.jp/contests/practice2/tasks/practice2_k) | `AtCoder` | `Hard` | - | Data-Structure-Heavy; Verification | Lazy Propagation; Modular Arithmetic; Affine Tags | Lazy-Propagation; Affine-Update; Acl-Style | The cleanest external verifier once you want to think in generic lazy actions rather than one bespoke additive tag. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `HORRIBLEQUERIES` | Horrible Queries | `primary` | `medium` | lazy segment tree; range add range sum; deferred propagation | [Note](../../../practice/ladders/data-structures/lazy-segment-tree/horriblequeries.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/lazy-segment-tree/horriblequeries.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
