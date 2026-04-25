# Math -> Game Theory / Sprague-Grundy

Impartial normal-play game modeling with mex-defined Grundy values and xor across independent subgames.

- Topic slug: `math/game-theory`
- Tutorial page: [Open tutorial](../../../topics/math/game-theory/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/math/game-theory/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `4`
- Curated external problems: `4`

## Microtopics

- sprague-grundy
- impartial-game
- mex
- normal-play
- nim-sum
- subtraction-game

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms Sprague-Grundy theorem](https://cp-algorithms.com/game_theory/sprague-grundy-nim.html) | `Reference` |
| [OI Wiki Impartial Game](https://en.oi-wiki.org/math/game-theory/impartial-game/) | `Reference` |
| [Competitive Programmer's Handbook](https://usaco.guide/CPH.pdf) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Kattis S-Nim](https://open.kattis.com/problems/snim) | `Practice` |
| [CSES Stick Game](https://cses.fi/problemset/task/1729/) | `Practice` |
| [CSES Nim Game II](https://cses.fi/problemset/task/1098/) | `Practice` |
| [AtCoder ABC368 F Dividing Game](https://atcoder.jp/contests/abc368/tasks/abc368_f) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Sprague-Grundy hot sheet](../../../notebook/sprague-grundy-hot-sheet.md) | `quick reference` |
| [S-Nim](../../../practice/ladders/math/game-theory/snim.md) | `flagship note` |
| [Sprague-Grundy starter route](../../../template-library.md) | `starter route` |
| [Interval DP](../../../topics/dp/interval-dp/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [S-Nim](https://open.kattis.com/problems/snim) | `Kattis` | `Medium` | Sprague-Grundy | Math; Implementation | Impartial Game; Mex; XOR | Subtraction-Game; Nim-Sum | The cleanest exact starter route where one subtraction-game Grundy table is reused across many multi-heap positions. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Nim Game II](https://cses.fi/problemset/task/1098) | `CSES` | `Medium` | Sprague-Grundy, Multi-Heap Games | Math; Observation | XOR | Nim-Sum; Pattern; Subtraction-Game | A strong follow-up where the SG values collapse to a short pattern, so the contest solution is theorem plus simplification rather than a full table. |

### Challenge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Dividing Game](https://atcoder.jp/contests/abc368/tasks/abc368_f) | `AtCoder` | `Hard` | Number Theory | Math; Observation | Sprague-Grundy; Prime Factorization | Sprague-Grundy; Prime-Factor-Count; Independent-Heaps | A challenge compare point where the heap nimber is recognized through arithmetic structure instead of direct DP over all states. |

### Bridge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Stick Game](https://cses.fi/problemset/task/1729) | `CSES` | `Medium` | Single-Heap Games, Sprague-Grundy | Math; Dynamic Programming | Impartial Game; State DP | Winning-Losing-DP; Subtraction-Game; Mex | The simplest compare point where SG precompute starts on one heap before xor across heaps matters. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `SNIM` | S-Nim | `primary` | `medium` | - | [Note](../../../practice/ladders/math/game-theory/snim.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/game-theory/snim.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
