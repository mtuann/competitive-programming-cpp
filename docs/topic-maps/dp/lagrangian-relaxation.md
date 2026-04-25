# DP -> Lagrangian Relaxation / Aliens Trick

Exact-K DP optimization where one global integer penalty removes the count dimension and the relaxed solver returns both value and count.

- Topic slug: `dp/lagrangian-relaxation`
- Tutorial page: [Open tutorial](../../../topics/dp/lagrangian-relaxation/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/dp/lagrangian-relaxation/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `4`

## Microtopics

- exact-k-optimization
- lagrangian-relaxation
- aliens-trick
- wqs-binary-search
- count-tie-break
- concave-envelope

## Learning Sources

| Source | Type |
| --- | --- |
| [AtCoder ABC218 H Editorial](https://atcoder.jp/contests/abc218/editorial/2634?lang=en) | `Reference` |
| [AtCoder ABC305 Ex Shojin](https://atcoder.jp/contests/abc305/tasks/abc305_h) | `Practice` |

## Practice Sources

| Source | Type |
| --- | --- |
| [AtCoder ABC218 H Red and Blue Lamps](https://atcoder.jp/contests/abc218/tasks/abc218_h) | `Practice` |
| [AtCoder ABC400 G Patisserie ABC 3](https://atcoder.jp/contests/abc400/tasks/abc400_g) | `Practice` |
| [AtCoder WTF22 Day1 D Welcome to Tokyo!](https://atcoder.jp/contests/wtf22-day1-open/tasks/wtf22_day1_d) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Aliens Trick hot sheet](../../../notebook/aliens-trick-hot-sheet.md) | `quick reference` |
| [Red and Blue Lamps note](../../../practice/ladders/dp/lagrangian-relaxation/redandbluelamps.md) | `flagship note` |
| [DP cheatsheet](../../../notebook/dp-cheatsheet.md) | `quick reference` |
| [Slope Trick tutorial](../../../topics/dp/slope-trick/README.md) | `compare point` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Red and Blue Lamps](https://atcoder.jp/contests/abc218/tasks/abc218_h) | `AtCoder` | `Hard` | Aliens Trick | Penalty Search; Linear DP; Binary Search On Answer Space | Exact-K DP; Non-Adjacent DP; Count Tie-Breaking | Exact K; Penalty Search; Non-Adjacent Picks | The clean flagship where the exact-K non-adjacent selection constraint becomes one integer penalty and the relaxed solver is a linear path DP. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Shojin](https://atcoder.jp/contests/abc305/tasks/abc305_h) | `AtCoder` | `Hard` | Aliens Trick | Penalty Search; Follow-Up | Monotone Counts | Exact K; Penalty Search; Follow-Up | A strong follow-up where the same penalty-search worldview survives a different exact-K DP skin and the count dimension is still the true bottleneck. |

### Challenge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Patisserie ABC 3](https://atcoder.jp/contests/abc400/tasks/abc400_g) | `AtCoder` | `Hard` | Aliens Trick | Penalty Search; Advanced Modeling | Advanced DP Modeling | Exact K; Penalty Search; Advanced | An advanced same-family route where the core alien-DP idea remains, but the relaxed transition and structure are less direct than the flagship. |
| [Welcome to Tokyo!](https://atcoder.jp/contests/wtf22-day1-open/tasks/wtf22_day1_d) | `AtCoder` | `Hard` | Aliens Trick | Penalty Search; Theory-Heavy | DP Modeling | Exact K; Penalty Search; Challenge | A challenge anchor for recognizing the same exact-K penalty-search worldview once the flagship route feels routine. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `REDANDBLUELAMPS` | Red and Blue Lamps | `primary` | `hard` | - | [Note](../../../practice/ladders/dp/lagrangian-relaxation/redandbluelamps.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/lagrangian-relaxation/redandbluelamps.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
