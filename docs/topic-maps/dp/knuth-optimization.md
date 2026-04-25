# DP -> Knuth Optimization

O(n^2) optimization for split-point interval DP dp[l][r] = min(dp[l][k] + dp[k+1][r] + cost(l, r)) when the opt window is monotone.

- Topic slug: `dp/knuth-optimization`
- Tutorial page: [Open tutorial](../../../topics/dp/knuth-optimization/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/dp/knuth-optimization/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `6`
- Curated external problems: `2`

## Microtopics

- interval-dp-optimization
- knuth-window
- opt-monotonicity
- quadrangle-inequality
- merge-cost-dp
- rightmost-argmin

## Learning Sources

| Source | Type |
| --- | --- |
| [CP-Algorithms Knuth's Optimization](https://cp-algorithms.com/dynamic_programming/knuth-optimization.html) | `Reference` |
| [Competitive Programmer's Handbook](https://usaco.guide/CPH.pdf) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Knuth Division](https://cses.fi/problemset/task/2088/) | `Practice` |
| [AtCoder DP N - Slimes](https://atcoder.jp/contests/dp/tasks/dp_n) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Knuth Optimization hot sheet](../../../notebook/knuth-optimization-hot-sheet.md) | `quick reference` |
| [Knuth Division](../../../practice/ladders/dp/knuth-optimization/knuthdivision.md) | `flagship note` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |
| [DP cheatsheet](../../../notebook/dp-cheatsheet.md) | `quick reference` |
| [Interval DP tutorial](../../../topics/dp/interval-dp/README.md) | `compare point` |
| [Divide and Conquer DP tutorial](../../../topics/dp/divide-and-conquer-dp/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Knuth Division](https://cses.fi/problemset/task/2088) | `CSES` | `Hard` | Interval DP | Interval DP; Cost Preprocessing; Opt Window Monotonicity | Prefix Sums; Split-Point Recurrence | Prefix Sums; Merge Cost | The cleanest first benchmark where the classic merge-cost interval recurrence matches the exact Knuth optimization window. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Slimes](https://atcoder.jp/contests/dp/tasks/dp_n) | `AtCoder DP Contest` | `Hard` | Interval DP | Interval DP; Cost Preprocessing; Optimization Compare Point | Prefix Sums; Split-Point Recurrence | Merge Cost; Prefix Sums; Optimization Compare Point | A canonical compare point with the same merge-style recurrence, useful for seeing the structure before or after importing the stronger Knuth optimization lens. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `KNUTHDIVISION` | Knuth Division | `primary` | `hard` | - | [Note](../../../practice/ladders/dp/knuth-optimization/knuthdivision.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/knuth-optimization/knuthdivision.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
