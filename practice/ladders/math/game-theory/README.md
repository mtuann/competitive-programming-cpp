# Game Theory / Sprague-Grundy Ladder

This ladder covers impartial normal-play games where:

- positions are finite
- `mex`-defined Grundy values make sense
- independent components combine by xor

Use it when a game problem has moved beyond:

- plain parity
- one interval minimax DP
- one direct Nim formula you can quote from memory

## Recommended Route

1. single-component winning/losing subtraction game
2. exact SG precompute for one move set
3. xor of multiple heaps / independent components
4. pattern-heavy or arithmetic SG tasks only after the route above feels routine

## Anchor Problems

- [S-Nim](snim.md): the repo's exact first route, with one subtraction set and many multi-heap positions

## Retrieval / Build Path

- topic page -> [Game Theory / Sprague-Grundy](../../../../topics/math/game-theory/README.md)
- hot sheet -> [Sprague-Grundy hot sheet](../../../../notebook/sprague-grundy-hot-sheet.md)
- starter -> [sprague-grundy-subtract-set.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/sprague-grundy-subtract-set.cpp)

## Compare Points

- [CSES Stick Game](https://cses.fi/problemset/task/1729/): single-heap win/lose doorway before xor of heaps matters
- [CSES Nim Game II](https://cses.fi/problemset/task/1098/): same lane, but with a closed-form SG pattern instead of a bounded precompute
- [CSES Grundy's Game](https://cses.fi/problemset/task/2207/): pattern-heavy split game; do not expect the starter to solve it unchanged
- [Removal Game](../../dp/interval-dp/removalgame.md): anti-cue when the statement sounds like game theory but the reusable route is score-difference DP

## Exit Criteria

You are ready to leave this ladder when you can:

- define `SG(state)` without hesitation
- tell when xor across components is legal
- spot when a game is actually score DP or misere and should leave this lane
- use a small SG table or observed pattern without mixing up the two routes

## External Practice

- [S-Nim](https://open.kattis.com/problems/snim)
- [CSES Stick Game](https://cses.fi/problemset/task/1729/)
- [CSES Nim Game II](https://cses.fi/problemset/task/1098/)
- [CSES Grundy's Game](https://cses.fi/problemset/task/2207/)
- [AtCoder ABC368 F - Dividing Game](https://atcoder.jp/contests/abc368/tasks/abc368_f)
