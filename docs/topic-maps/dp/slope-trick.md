# DP -> Slope Trick

Convex piecewise-linear DP over one integer coordinate maintained by hinge additions and bounded argmin shifts.

- Topic slug: `dp/slope-trick`
- Tutorial page: [Open tutorial](../../../topics/dp/slope-trick/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/dp/slope-trick/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `4`
- Curated external problems: `4`

## Microtopics

- convex-piecewise-linear-dp
- two-heaps
- hinge-penalties
- argmin-interval
- shift-min
- movement-relaxation

## Learning Sources

| Source | Type |
| --- | --- |
| [AtCoder ABC217 H Editorial](https://atcoder.jp/contests/abc217/editorial/2620?lang=en) | `Reference` |
| [AtCoder ABC406 G Editorial](https://atcoder.jp/contests/abc406/editorial/13055) | `Reference` |
| [AtCoder ARC163 F Editorial](https://atcoder.jp/contests/arc163/editorial/6731?lang=en) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [AtCoder ABC127 F Absolute Minima](https://atcoder.jp/contests/abc127/tasks/abc127_f) | `Practice` |
| [AtCoder ABC217 H Snuketoon](https://atcoder.jp/contests/abc217/tasks/abc217_h) | `Practice` |
| [AtCoder ABC406 G Travelling Salesman Problem](https://atcoder.jp/contests/abc406/tasks/abc406_g) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Slope Trick hot sheet](../../../notebook/slope-trick-hot-sheet.md) | `quick reference` |
| [Snuketoon note](../../../practice/ladders/dp/slope-trick/snuketoon.md) | `flagship note` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |
| [Convex Hull Trick / Li Chao Tree tutorial](../../../topics/dp/cht-li-chao/README.md) | `compare point` |

## Curated External Problems

### Warm-Up

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Absolute Minima](https://atcoder.jp/contests/abc127/tasks/abc127_f) | `AtCoder` | `Hard` | - | Online Queries; Median Structure | Absolute Value Cost; Convex Minimizers | Absolute Value Updates; Median Maintenance; Convex Function | The clean warm-up where the same convex-function family appears without movement-style shift_min, so a lighter same-family route becomes visible. |

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Snuketoon](https://atcoder.jp/contests/abc217/tasks/abc217_h) | `AtCoder` | `Hard` | - | Convex DP; Data-Structure-Heavy | Convex Function State; One-Sided Hinges; Lazy Shifts | One-Sided Penalties; Shift Min; Convex DP | The cleanest flagship where time gaps become bounded argmin shifts and each event adds one one-sided hinge penalty. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Travelling Salesman Problem](https://atcoder.jp/contests/abc406/tasks/abc406_g) | `AtCoder` | `Hard` | - | Convex DP; Follow-Up | Slope Trick; Absolute Distance DP | Absolute Distance; Shift Min; Follow-Up | A strong follow-up where the same slope-trick machinery survives a different story skin and both movement and meeting costs shape the convex state. |

### Challenge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Many Increasing Problems](https://atcoder.jp/contests/arc163/tasks/arc163_f) | `AtCoder` | `Hard` | - | Convex DP; Theory-Heavy | Slope Trick; Sequence DP | Monotone Sequence DP; Convex DP; Advanced | The advanced follow-up where the slope-trick view still applies, but the problem is no longer a direct event-by-event coordinate process. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `SNUKETOON` | Snuketoon | `primary` | `hard` | - | [Note](../../../practice/ladders/dp/slope-trick/snuketoon.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/slope-trick/snuketoon.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
