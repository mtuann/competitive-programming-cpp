# DP -> Divide and Conquer DP

Monotone-opt partition DP where one row cur[i] = min(prev[k] + cost(k+1, i)) is computed by recursive split-range shrinking.

- Topic slug: `dp/divide-and-conquer-dp`
- Tutorial page: [Open tutorial](../../../topics/dp/divide-and-conquer-dp/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/dp/divide-and-conquer-dp/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `2`

## Microtopics

- partition-dp
- monotone-argmin
- row-optimization
- interval-cost-precompute
- opt-range-shrink
- divide-and-conquer-row

## Learning Sources

| Source | Type |
| --- | --- |
| [CP-Algorithms Divide and Conquer DP](https://cp-algorithms.com/dynamic_programming/divide-and-conquer-dp.html) | `Reference` |
| [USACO Guide Divide & Conquer - DP](https://usaco.guide/plat/DC-DP) | `Reference` |
| [Competitive Programmer's Handbook](https://usaco.guide/CPH.pdf) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Codeforces Ciel and Gondolas](https://codeforces.com/problemset/problem/321/E) | `Practice` |
| [Codeforces Yet Another Minimization Problem](https://codeforces.com/problemset/problem/868/F) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Divide and Conquer DP hot sheet](../../../notebook/divide-and-conquer-dp-hot-sheet.md) | `quick reference` |
| [Ciel and Gondolas](../../../practice/ladders/dp/divide-and-conquer-dp/cielandgondolas.md) | `flagship note` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |
| [DP cheatsheet](../../../notebook/dp-cheatsheet.md) | `quick reference` |
| [Convex Hull Trick / Li Chao Tree tutorial](../../../topics/dp/cht-li-chao/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Ciel and Gondolas](https://codeforces.com/problemset/problem/321/E) | `Codeforces` | `Very Hard` | Partition DP | Partition DP; Cost Preprocessing; Decision Monotonicity | Prefix Sums; Monotone Argmins | Monotone Opt; 2D Prefix Sums; Contiguous Groups | The canonical first benchmark where interval-cost preprocessing and monotone split decisions combine into one exact divide-and-conquer DP row optimization. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Yet Another Minimization Problem](https://codeforces.com/problemset/problem/868/F) | `Codeforces` | `Very Hard` | Partition DP | Partition DP; Cost Maintenance; Decision Monotonicity | Divide And Conquer DP; Incremental Cost Updates; Two Pointers Or Mo Intuition | Monotone Opt; Mo-Style Cost Maintenance; Distinct Pair Cost | A strong follow-up where the row optimization stays the same but the real challenge becomes maintaining the interval cost fast enough. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `CIELANDGONDOLAS` | Ciel and Gondolas | `primary` | `very hard` | - | [Note](../../../practice/ladders/dp/divide-and-conquer-dp/cielandgondolas.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/divide-and-conquer-dp/cielandgondolas.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
