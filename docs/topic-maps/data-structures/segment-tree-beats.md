# Data Structures -> Segment Tree Beats

Richer segment-tree summaries for online range chmin / chmax / add / sum when ordinary lazy tags stop closing cleanly.

- Topic slug: `data-structures/segment-tree-beats`
- Tutorial page: [Open tutorial](../../../topics/data-structures/segment-tree-beats/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/data-structures/segment-tree-beats/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `2`

## Microtopics

- range-chmin
- range-chmax
- second-maximum
- second-minimum
- beats-pruning
- amortized-pushdown

## Learning Sources

| Source | Type |
| --- | --- |
| [Codeforces simple introduction to Segment Tree Beats](https://codeforces.com/blog/entry/57319) | `Essay / Blog` |
| [Library Checker Range Chmin Chmax Add Range Sum](https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum) | `Practice` |
| [ACL-based Segment Tree Beats reference](https://hitonanode.github.io/cplib-cpp/segmenttree/acl_beats.hpp.html) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Library Checker](https://judge.yosupo.jp/) | `Practice` |
| [Codeforces Problemset](https://codeforces.com/problemset) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Segment Tree Beats hot sheet](../../../notebook/segment-tree-beats-hot-sheet.md) | `quick reference` |
| [Range Chmin Chmax Add Range Sum note](../../../practice/ladders/data-structures/segment-tree-beats/rangechminchmaxaddrangesum.md) | `anchor note` |
| [Segment Tree Beats starter route](../../../template-library.md) | `starter route` |
| [Lazy Segment Tree tutorial](../../../topics/data-structures/lazy-segment-tree/README.md) | `adjacent tutorial` |
| [Segment Tree hot sheet](../../../notebook/segment-tree-hot-sheet.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Range Chmin Chmax Add Range Sum](https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum) | `Library Checker` | `Hard` | Range Queries | Data-Structure-Heavy; Verification | Lazy Segment Tree; Second Extremum Summaries; Amortized Pushdown | Range-Chmin; Range-Chmax; Range-Add | The cleanest official verifier for the exact canonical beats starter shipped in this repo. |

### Bridge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [The Child and Sequence](https://codeforces.com/problemset/problem/438/D) | `Codeforces` | `Hard` | Compare Point | Data-Structure-Heavy; Compare-Point | Segment Tree; Current Maximum Pruning; Amortized Reasoning | Beats-Like-Pruning; Range-Modulo; Range-Sum | The classic compare point where the same pruning mindset appears, but the exact canonical chmin/chmax/add/sum starter does not apply directly. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `RANGECHMINCHMAXADDRANGESUM` | Range Chmin Chmax Add Range Sum | `primary` | `hard` | segment tree beats; range chmin; range chmax; second extremum summaries | [Note](../../../practice/ladders/data-structures/segment-tree-beats/rangechminchmaxaddrangesum.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/segment-tree-beats/rangechminchmaxaddrangesum.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
