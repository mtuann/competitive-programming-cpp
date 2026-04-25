# Data Structures -> Wavelet Tree

Static range order-statistics and value-counting structure that rewrites one queried interval through value partitions with prefix-left counts.

- Topic slug: `data-structures/wavelet-tree`
- Tutorial page: [Open tutorial](../../../topics/data-structures/wavelet-tree/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/data-structures/wavelet-tree/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `3`

## Microtopics

- range-kth-smallest
- prefix-left-counts
- static-order-statistics
- coordinate-compression
- count-leq
- wavelet-vs-persistent

## Learning Sources

| Source | Type |
| --- | --- |
| [USACO Guide Wavelet Tree](https://usaco.guide/adv/wavelet?lang=java) | `Reference` |
| [IOI Journal Wavelet Trees for Competitive Programming](https://ioinformatics.org/files/volume10.pdf) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [SPOJ MKTHNUM](https://www.spoj.com/problems/MKTHNUM/) | `Practice` |
| [Library Checker Range K-th Smallest](https://judge.yosupo.jp/problem/range_kth_smallest) | `Practice` |
| [SPOJ KQUERY](https://www.spoj.com/problems/KQUERY/) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Wavelet Tree hot sheet](../../../notebook/wavelet-tree-hot-sheet.md) | `quick reference` |
| [Wavelet Tree starter route](../../../template-library.md) | `starter route` |
| [MKTHNUM note](../../../practice/ladders/data-structures/wavelet-tree/mkthnum.md) | `anchor note` |
| [Persistent Data Structures tutorial](../../../topics/data-structures/persistent-data-structures/README.md) | `compare point` |
| [Persistent Data Structures hot sheet](../../../notebook/persistent-data-structures-hot-sheet.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [MKTHNUM - K-th Number](https://www.spoj.com/problems/MKTHNUM/) | `SPOJ` | `Hard` | Order Statistics | Query-Heavy; Data-Structure-Heavy | Coordinate Compression; Wavelet Tree; Range Order Statistics | Range-Kth; Static-Queries | The canonical first static range k-th-smallest problem and the cleanest first benchmark for this lane. |

### Practice

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Range K-th Smallest](https://judge.yosupo.jp/problem/range_kth_smallest) | `Library Checker` | `Hard` | - | Query-Heavy; Data-Structure-Heavy | Wavelet Tree; Coordinate Compression; Static Queries | Range-Kth | An official verifier-style benchmark once the basic wavelet-tree descent is trusted. |

### Classics

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [K-query](https://www.spoj.com/problems/KQUERY/) | `SPOJ` | `Hard` | Threshold Counting, Classic | Query-Heavy; Classic | Wavelet Tree; Range Counting; Coordinate Compression | Threshold-Count | A classic follow-up showing the same lane extends naturally from k-th queries to value-threshold counts. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `MKTHNUM` | K-th Number | `primary` | `hard` | - | [Note](../../../practice/ladders/data-structures/wavelet-tree/mkthnum.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/wavelet-tree/mkthnum.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
