# Slope Trick Ladder

This ladder is for the exact convex-function DP lane where:

- the state is one convex piecewise-linear function `f(x)`
- one update adds a hinge like `max(0, x-a)` or `max(0, a-x)`
- and movement sometimes widens the minimizer interval

## Who This Is For

Use this lane if:

- you can already define the DP state as "best answer when ending at coordinate `x`"
- the state remains convex in that coordinate
- the next step is no longer generic state design, but function maintenance

This lane is intentionally narrow:

- one exact starter
- one flagship in-repo rep with `shift_min`
- one warm-up compare point where the same family is lighter

## Warm-Up

- repeated `f(x) += |x-a| + b` plus query for one minimizer -> [AtCoder ABC127 F - Absolute Minima](https://atcoder.jp/contests/abc127/tasks/abc127_f)

Target skill:

- recognize when plain median maintenance is the lighter route inside the same convex-function family

## Core

- exact starter -> [`slope-trick-basic.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/slope-trick-basic.cpp)
- exact flagship -> [Snuketoon](snuketoon.md)

Target skill:

- map each contest event to one of:
  - `add max(0, x-a)`
  - `add max(0, a-x)`
  - `add |x-a|`
  - `shift_min`

## Stretch

- movement + absolute-distance variant -> [AtCoder ABC406 G - Travelling Salesman Problem](https://atcoder.jp/contests/abc406/tasks/abc406_g)
- monotone-sequence convex DP follow-up -> [AtCoder ARC163 F - Many Increasing Problems](https://atcoder.jp/contests/arc163/tasks/arc163_f)

Target skill:

- distinguish "same slope-trick machinery, different recurrence skin" from genuinely different optimization families

## Retrieval Layer

- exact quick sheet -> [Slope Trick hot sheet](../../../../notebook/slope-trick-hot-sheet.md)
- exact starter -> [`slope-trick-basic.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/slope-trick-basic.cpp)
- parent DP retrieval -> [DP cheatsheet](../../../../notebook/dp-cheatsheet.md)
- broader route -> [DP ladders](../README.md)

## Repo Anchors And Compare Points

- topic page -> [Slope Trick](../../../../topics/dp/slope-trick/README.md)
- parent DP worldview -> [DP Foundations](../../../../topics/dp/foundations/README.md)
- compare affine family -> [Convex Hull Trick / Li Chao Tree](../../../../topics/dp/cht-li-chao/README.md)
- compare lighter same-family route -> [AtCoder ABC127 F - Absolute Minima](https://atcoder.jp/contests/abc127/tasks/abc127_f)
- flagship rep -> [Snuketoon](snuketoon.md)

The cleanest in-repo loop here is:

1. learn the exact operations from the [Slope Trick topic](../../../../topics/dp/slope-trick/README.md)
2. trust the starter through [Snuketoon](snuketoon.md)
3. compare back against `Absolute Minima` so "slope trick vs lighter median route" becomes real

## Exit Criteria

You are ready to move on when:

- you can explain why the state stays convex
- you can translate a transition into one hinge or one `shift_min`
- you can say when `Absolute Minima` is the lighter same-family route
- you can say why [CHT / Li Chao](../../../../topics/dp/cht-li-chao/README.md) is a different family

## External Practice

- [AtCoder ABC127 F - Absolute Minima](https://atcoder.jp/contests/abc127/tasks/abc127_f)
- [AtCoder ABC217 H - Snuketoon](https://atcoder.jp/contests/abc217/tasks/abc217_h)
- [AtCoder ABC406 G - Travelling Salesman Problem](https://atcoder.jp/contests/abc406/tasks/abc406_g)
- [AtCoder ARC163 F - Many Increasing Problems](https://atcoder.jp/contests/arc163/tasks/arc163_f)

## Tutorial Link

- [Slope Trick](../../../../topics/dp/slope-trick/README.md)
