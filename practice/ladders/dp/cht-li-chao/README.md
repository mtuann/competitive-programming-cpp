# CHT / Li Chao Ladder

This ladder is for the first DP-optimization lane where previous states become lines and current states become point queries.

## Who This Is For

Use this lane if:

- you can already derive a clean recurrence
- the hard part is no longer "what is the state?"
- the recurrence has become affine in one query variable

This is a thin lane on purpose:

- one family
- two exact starters
- one direct in-repo DP flagship rep
- one direct structure-verifier rep
- strong compare points back into `DP Foundations`, `DP cheatsheet`, and lighter hull routes

## Warm-Up

- derive `dp[i] = min_j(m_j x_i + b_j)` cleanly
- identify which part is slope, intercept, and query
- check whether slope order or query order is monotone before building a Li Chao tree

Target skill:

- explain why `Monster Game I` is still the same family even if it can use a lighter monotone hull

Warm-up compare points:

- [Monster Game I](https://cses.fi/problemset/task/2084)
- [Library Checker: Line Add Get Min](https://judge.yosupo.jp/problem/line_add_get_min)

## Core

- exact LineContainer route -> [`line-container.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/line-container.cpp) -> [Line Add Get Min](lineaddgetmin.md)
- exact Li Chao route -> [`li-chao-tree.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/li-chao-tree.cpp) -> [Monster Game II](monstergame2.md)

Target skill:

- know when generic online insertion + query order wants LineContainer, when bounded-domain midpoint recursion wants Li Chao, and when a deque hull is still lighter

## Stretch

- raw structure verification -> [Library Checker: Line Add Get Min](https://judge.yosupo.jp/problem/line_add_get_min)
- segment-limited lines -> [Library Checker: Segment Add Get Min](https://judge.yosupo.jp/problem/segment_add_get_min)
- monotone-hull compare point -> [Monster Game I](https://cses.fi/problemset/task/2084)

Target skill:

- distinguish "full-domain line container" from "segment Li Chao" and "monotone hull"

## Retrieval Layer

- exact quick sheet -> [CHT / Li Chao hot sheet](../../../../notebook/cht-hot-sheet.md)
- exact starters -> [`line-container.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/line-container.cpp), [`li-chao-tree.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/li-chao-tree.cpp)
- parent DP retrieval -> [DP cheatsheet](../../../../notebook/dp-cheatsheet.md)
- broader route -> [DP ladders](../README.md)

## Repo Anchors And Compare Points

- topic page -> [Convex Hull Trick / Li Chao Tree](../../../../topics/dp/cht-li-chao/README.md)
- parent DP worldview -> [DP Foundations](../../../../topics/dp/foundations/README.md)
- broader DP router -> [Dynamic Programming](../../../../topics/dp/README.md)
- direct verifier rep -> [Line Add Get Min](lineaddgetmin.md)
- exact flagship rep -> [Monster Game II](monstergame2.md)

The cleanest in-repo loop here is:

1. derive the line transformation from the [Convex Hull Trick / Li Chao Tree topic](../../../../topics/dp/cht-li-chao/README.md)
2. trust one exact implementation through [Monster Game II](monstergame2.md) or [Line Add Get Min](lineaddgetmin.md)
3. compare it back against `Monster Game I` so the chooser between monotone hull, LineContainer, and Li Chao becomes real

## Exit Criteria

You are ready to move on when:

- you can derive `m`, `b`, and `x` cleanly from the recurrence
- you can say when monotone hull is enough, when LineContainer fits, and when Li Chao is safer
- you can explain why a Li Chao node stores the line that wins at its midpoint
- you can explain why a LineContainer line owns one breakpoint interval on the lower envelope

## External Practice

- [CSES - Monster Game I](https://cses.fi/problemset/task/2084)
- [CSES - Monster Game II](https://cses.fi/problemset/task/2085)
- [Library Checker - Line Add Get Min](https://judge.yosupo.jp/problem/line_add_get_min)
- [Library Checker - Segment Add Get Min](https://judge.yosupo.jp/problem/segment_add_get_min)

## Tutorial Link

- [Convex Hull Trick / Li Chao Tree](../../../../topics/dp/cht-li-chao/README.md)
