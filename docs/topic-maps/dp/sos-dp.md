# DP -> SOS DP

Subset/superset zeta sweeps on the full boolean cube, including witness propagation after complement-mask modeling.

- Topic slug: `dp/sos-dp`
- Tutorial page: [Open tutorial](../../../topics/dp/sos-dp/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/dp/sos-dp/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `2`

## Microtopics

- subset-zeta
- superset-zeta
- mask-cube-sweep
- subset-aggregates
- complement-masks
- witness-propagation

## Learning Sources

| Source | Type |
| --- | --- |
| [USACO Guide Sum over Subsets DP](https://usaco.guide/plat/dp-sos?lang=py) | `Reference` |
| [OI Wiki prefix sum and SOS subsection](https://oi-wiki.org/basic/prefix-sum/) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Codeforces Compatible Numbers](https://codeforces.com/problemset/problem/165/E) | `Practice` |
| [CSES SOS Bit Problem](https://cses.fi/problemset/task/1654/) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [SOS DP hot sheet](../../../notebook/sos-dp-hot-sheet.md) | `quick reference` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |
| [Compatible Numbers](../../../practice/ladders/dp/sos-dp/compatiblenumbers.md) | `flagship note` |
| [Bitmask DP](../../../topics/dp/bitmask-dp/README.md) | `compare point` |
| [DP cheatsheet](../../../notebook/dp-cheatsheet.md) | `quick reference` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Compatible Numbers](https://codeforces.com/problemset/problem/165/E) | `Codeforces` | `Very Hard` | Bitmask | Full-Cube Sweep; Complement Modeling; Offline Propagation | Bitmask States; Complement Masks; Subset Direction | Bitmasks; Subset Zeta; Witness Propagation; Bitwise Complement | The cleanest first rep where one subset-direction SOS sweep carries a witness value and the real modeling step is querying the complement mask. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [SOS Bit Problem](https://cses.fi/problemset/task/1654) | `CSES` | `Hard` | Bitmask | Full-Cube Sweep; Count Aggregation; Complement Counting | Sos DP; Bitwise Predicates; Mask Bucketing | Subset Zeta; Superset Zeta; Bitwise Or; Bitwise And | A strong follow-up where the same lane has to support both subset-side and superset-side counting in one problem. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `COMPATIBLENUMBERS` | Compatible Numbers | `primary` | `2200` | - | [Note](../../../practice/ladders/dp/sos-dp/compatiblenumbers.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/sos-dp/compatiblenumbers.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
