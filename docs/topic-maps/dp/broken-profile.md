# DP -> Broken Profile / Plug DP

Frontier-mask DP on small-width grids, with occupancy masks first and connectivity-labeled plug states as the stronger follow-up.

- Topic slug: `dp/broken-profile`
- Tutorial page: [Open tutorial](../../../topics/dp/broken-profile/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/dp/broken-profile/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `2`

## Microtopics

- frontier-mask
- profile-dp
- column-sweep
- next-mask-generation
- domino-tiling
- plug-dp

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms broken profile](https://cp-algorithms.com/dynamic_programming/profile-dynamics.html) | `Reference` |
| [USACO Guide broken profile](https://usaco.guide/adv/dp-broken-profile) | `Reference` |
| [OI Wiki plug DP](https://en.oi-wiki.org/dp/plug/) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Counting Tilings](https://cses.fi/problemset/task/2181/) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Broken Profile hot sheet](../../../notebook/broken-profile-hot-sheet.md) | `quick reference` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |
| [Counting Tilings note](../../../practice/ladders/dp/broken-profile/countingtilings.md) | `anchor note` |
| [Bitmask DP](../../../topics/dp/bitmask-dp/README.md) | `compare point` |
| [DP cheatsheet](../../../notebook/dp-cheatsheet.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Counting Tilings](https://cses.fi/problemset/task/2181) | `CSES` | `Hard` | Grid DP | Counting; Frontier DP | Bitmask Basics; Local Placements | Domino Tiling; Frontier Mask; Column Sweep | The cleanest first verifier for occupancy-mask profile DP on a small-width grid. |

### Challenge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Compound Escape](https://usaco.org/index.php?cpid=949&page=viewproblem2) | `USACO Platinum` | `Very Hard` | Plug-DP | Counting; Frontier DP | Occupancy Masks; Grid Frontier Thinking | Frontier State; Counting; Challenge | A challenge-level extension once simple occupancy masks are no longer the only frontier information you can reason about. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `COUNTINGTILINGS` | Counting Tilings | `primary` | `hard` | - | [Note](../../../practice/ladders/dp/broken-profile/countingtilings.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/broken-profile/countingtilings.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
