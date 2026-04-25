# DP -> Convex Hull Trick / Li Chao Tree

Affine-DP optimization where previous states become lines and current states become point queries.

- Topic slug: `dp/cht-li-chao`
- Tutorial page: [Open tutorial](../../../topics/dp/cht-li-chao/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/dp/cht-li-chao/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `3`
- Curated external problems: `4`

## Microtopics

- affine-dp
- line-container
- li-chao-tree
- monotone-hull
- slope-intercept-transform
- online-min-query

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms Convex Hull Trick and Li Chao tree](https://cp-algorithms.com/geometry/convex_hull_trick.html) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Monster Game I](https://cses.fi/problemset/task/2084) | `Practice` |
| [CSES Monster Game II](https://cses.fi/problemset/task/2085) | `Practice` |
| [Library Checker Line Add Get Min](https://judge.yosupo.jp/problem/line_add_get_min) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [CHT / Li Chao hot sheet](../../../notebook/cht-hot-sheet.md) | `quick reference` |
| [Monster Game II note](../../../practice/ladders/dp/cht-li-chao/monstergame2.md) | `flagship note` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Line Add Get Min](https://judge.yosupo.jp/problem/line_add_get_min) | `Library Checker` | `Medium` | Li Chao Tree, Line Container | Implementation; Verification | Line Evaluation; Li Chao Midpoint Invariant | Point Queries | The most direct official verifier for the exact full-domain Li Chao starter. |
| [Monster Game I](https://cses.fi/problemset/task/2084) | `CSES` | `Hard` | Convex Hull Trick | Optimization; Monotone Structure | Affine DP Transform; Slope / Query Monotonicity | Affine DP; Monotone Hull; Line Container | The clean compare-point problem where the same affine DP family still admits a lighter monotone-hull route. |
| [Monster Game II](https://cses.fi/problemset/task/2085) | `CSES` | `Hard` | Li Chao Tree | Optimization; Data-Structure-Heavy | Affine DP Transform; Line Evaluation | Affine DP; Line Container | The cleanest flagship for generic online min queries over lines with arbitrary insertion/query order. |

### Challenge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Segment Add Get Min](https://judge.yosupo.jp/problem/segment_add_get_min) | `Library Checker` | `Hard` | Li Chao Tree, Segment Li Chao | Implementation; Verification | Segment Tree Thinking | Segment-Limited Lines; Advanced | The next-layer verifier once the basic full-domain Li Chao route is trusted and line activity ranges matter. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `MONSTERGAME2` | Monster Game II | `primary` | `hard` | li chao tree; affine dp; online line minimum | [Note](../../../practice/ladders/dp/cht-li-chao/monstergame2.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/cht-li-chao/monstergame2.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
