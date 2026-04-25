# Slope Trick Hot Sheet

Use this page when your DP state is one convex piecewise-linear function `f(x)`, and each transition only:

- adds `max(0, x-a)`
- adds `max(0, a-x)`
- adds `|x-a|`
- or widens where the minimizer may move

## Do Not Use When

- the recurrence is really `min_j(m_j x + b_j)` over previous states -> use [CHT / Li Chao hot sheet](cht-hot-sheet.md)
- you only add `|x-a| + b` and never need a movement-style `shift_min`; a lighter median-maintenance route may be enough
- the DP state is not one convex function over a single coordinate

## Core Operations

- `add_x_minus_a(a)` -> add `max(0, x-a)`
- `add_a_minus_x(a)` -> add `max(0, a-x)`
- `add_abs(a)` -> add `|x-a|`
- `shift_min(dl, dr)` -> every minimizer `x` may move to `[x+dl, x+dr]`
- `expand_argmin_by(d)` -> shorthand for `shift_min(-d, d)`
- `seed_argmin_point(a, copies)` -> contest helper for start states like `f(a)=0`, `f(x)=+\infty` elsewhere

## Core Invariants

- `min_f` stores the current minimum value of the function
- left max-heap stores left-side breakpoints
- right min-heap stores right-side breakpoints
- lazy offsets shift all breakpoints without touching every heap entry
- current minimizer interval is `[top_left(), top_right()]` after offsets

## Recognition Cues

- "minimum cost if you end at coordinate `x`"
- movement between steps becomes `min_{|y-x|<=d} f(y)`
- each event adds one one-sided damage or penalty
- editorial says the function stays convex and piecewise linear

## Main Traps

- swapping the meanings of `add_x_minus_a` and `add_a_minus_x`
- forgetting that bounded movement by distance `d` means `shift_min(-d, d)`
- trying to reconstruct full `f(x)` from this starter
- using slope trick for an affine family that should be [CHT / Li Chao](../topics/dp/cht-li-chao/README.md)

## Exact Starter In This Repo

- starter -> [`slope-trick-basic.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/slope-trick-basic.cpp)
- flagship rep -> [Snuketoon](../practice/ladders/dp/slope-trick/snuketoon.md)
- warm-up compare point -> [AtCoder ABC127 F - Absolute Minima](https://atcoder.jp/contests/abc127/tasks/abc127_f)

## Reopen Paths

- full tutorial -> [Slope Trick](../topics/dp/slope-trick/README.md)
- parent router -> [DP cheatsheet](dp-cheatsheet.md)
- compare affine family -> [CHT / Li Chao hot sheet](cht-hot-sheet.md)
