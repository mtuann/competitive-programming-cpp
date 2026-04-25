# Lagrangian Relaxation / Aliens Trick Ladder

This ladder is for the exact-count optimization lane where:

- the original problem wants the best answer with exactly `K` choices
- direct DP over `K` is too slow
- adding a penalty per choice makes the relaxed DP cheap

## Who This Is For

Use this lane if:

- you already know how to write the direct exact-`K` DP
- the only issue is that the count dimension is too expensive
- the relaxed problem for fixed penalty becomes much simpler

This lane is intentionally narrow:

- one exact starter
- one official flagship rep
- a few official follow-ups that reuse the same worldview in different skins

## Warm-Up

- direct exact-`K` DP when constraints still allow it

Target skill:

- see the expensive count dimension before reaching for Aliens trick

## Core

- exact starter -> [`aliens-trick-nonadjacent-max.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/aliens-trick-nonadjacent-max.cpp)
- exact flagship -> [Red and Blue Lamps](redandbluelamps.md)

Target skill:

- rewrite "exactly `K`" as one global penalty `lambda`
- solve the penalized DP
- binary search `lambda`
- recover the original answer

## Stretch

- sequence / day-partition follow-up -> [AtCoder ABC305 Ex - Shojin](https://atcoder.jp/contests/abc305/tasks/abc305_h)
- pairing / parity follow-up -> [AtCoder ABC400 G - Patisserie ABC 3](https://atcoder.jp/contests/abc400/tasks/abc400_g)
- interval-coverage / all-k follow-up -> [AtCoder WTF22 Day1 D - Welcome to Tokyo!](https://atcoder.jp/contests/wtf22-day1-open/tasks/wtf22_day1_d)

Target skill:

- distinguish "same penalty-search worldview" from "same exact DP recurrence"

## Retrieval Layer

- exact quick sheet -> [Aliens Trick hot sheet](../../../../notebook/aliens-trick-hot-sheet.md)
- exact starter -> [`aliens-trick-nonadjacent-max.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/aliens-trick-nonadjacent-max.cpp)
- parent DP retrieval -> [DP cheatsheet](../../../../notebook/dp-cheatsheet.md)
- broader route -> [DP ladders](../README.md)

## Repo Anchors And Compare Points

- topic page -> [Lagrangian Relaxation / Aliens Trick](../../../../topics/dp/lagrangian-relaxation/README.md)
- parent DP worldview -> [DP Foundations](../../../../topics/dp/foundations/README.md)
- compare split-point row optimization -> [Divide and Conquer DP](../../../../topics/dp/divide-and-conquer-dp/README.md)
- compare coordinate-function optimization -> [Slope Trick](../../../../topics/dp/slope-trick/README.md)
- flagship rep -> [Red and Blue Lamps](redandbluelamps.md)

The cleanest in-repo loop here is:

1. learn the exact penalty-search contract from the [Lagrangian Relaxation / Aliens Trick topic](../../../../topics/dp/lagrangian-relaxation/README.md)
2. trust the starter through [Red and Blue Lamps](redandbluelamps.md)
3. compare back against plain exact-`K` DP and other DP optimizations so the chooser becomes real

## Exit Criteria

You are ready to move on when:

- you can explain why the relaxed solver must return `(value, count)`
- you know the right tie-break direction for the maximization route
- you can binary search `lambda` without floating-point
- you can say when Aliens trick is unnecessary because direct `O(NK)` DP already fits

## External Practice

- [AtCoder ABC218 H - Red and Blue Lamps](https://atcoder.jp/contests/abc218/tasks/abc218_h)
- [AtCoder ABC305 Ex - Shojin](https://atcoder.jp/contests/abc305/tasks/abc305_h)
- [AtCoder ABC400 G - Patisserie ABC 3](https://atcoder.jp/contests/abc400/tasks/abc400_g)
- [AtCoder WTF22 Day1 D - Welcome to Tokyo!](https://atcoder.jp/contests/wtf22-day1-open/tasks/wtf22_day1_d)

## Tutorial Link

- [Lagrangian Relaxation / Aliens Trick](../../../../topics/dp/lagrangian-relaxation/README.md)
