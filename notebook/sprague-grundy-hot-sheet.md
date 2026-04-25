# Sprague-Grundy Hot Sheet

Use this sheet when the game is:

- impartial
- normal play
- finite
- and either one position or a sum of independent positions

Then the right invariant is usually:

```text
SG(state) = mex(reachable SG values)
```

and the whole position is losing iff the xor of component Grundy values is `0`.

## Do Not Use When

- the game is really score maximization -> [Removal Game](../practice/ladders/dp/interval-dp/removalgame.md)
- the players have different legal moves
- the rule is misere instead of normal play
- the state graph can cycle and you do not have a safe finite reduction

## Choose By Signal

- one bounded heap/state with fixed decreasing moves -> SG table / win-lose DP
- many independent heaps using the same move rules -> precompute SG once, xor all heaps
- one move splits the state into independent subgames -> xor child SG values inside the transition, then take `mex`
- only one interval and score difference matter -> [Interval DP](../topics/dp/interval-dp/README.md)

## Core Invariants

- terminal states have Grundy `0`
- a state is losing iff its Grundy value is `0`
- `SG(state) = mex(reachable Grundy values)`
- the sum of independent games has Grundy equal to the xor of component Grundy values

## Main Traps

- xor-ing positions that are not independent
- using Sprague-Grundy on misere or partisan games
- computing only win/lose values when the multi-heap answer needs exact nimbers
- forgetting that many SG-heavy tasks are solved by a pattern after a small precompute, not by brute force forever

## Exact Starter In This Repo

- exact starter -> [sprague-grundy-subtract-set.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/sprague-grundy-subtract-set.cpp)
- flagship in-lane rep -> [S-Nim](../practice/ladders/math/game-theory/snim.md)
- compare points -> [Stick Game](https://cses.fi/problemset/task/1729/), [Removal Game](../practice/ladders/dp/interval-dp/removalgame.md)

## Reopen Paths

- full topic page -> [Game Theory / Sprague-Grundy](../topics/math/game-theory/README.md)
- compare against score-game DP -> [Interval DP](../topics/dp/interval-dp/README.md)
- bitwise compare point for xor semantics -> [XOR Basis / Linear Basis](../topics/math/xor-basis/README.md)
- snippet chooser -> [Template Library](../template-library.md)
- retrieval router -> [Build Kit](../docs/build-kit.md)
