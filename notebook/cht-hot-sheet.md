# CHT / Li Chao Hot Sheet

Use this page when a DP or optimization layer has already become:

$$
\min_j (m_j x + b_j)
$$

or the max analogue, and the real question is which line-container variant fits.

## Do Not Use When

- the recurrence is not truly affine after expansion
- interval partitioning or quadrangle inequalities are the real structure
- the problem is already monotone enough for a deque hull and you are about to overbuild
- the line is active only on part of the domain, but you only have a full-domain Li Chao starter in mind

## Choose By Signal

- slopes inserted in monotone order and query `x` values are monotone -> lighter monotone hull route -> reopen the topic
- online inserts + online queries on one known integer domain -> Li Chao tree -> [`li-chao-tree.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/li-chao-tree.cpp)
- segment-limited line insertion -> reopen the full topic first; the starter here is too narrow
- the statement still feels like generic DP state design -> go back to [DP cheatsheet](dp-cheatsheet.md)

## Core Invariants

- every previous candidate is represented as one line `y = m x + b`
- each query is just "best line at one x"
- in a Li Chao node, the stored line is best at that node midpoint
- the losing line can still matter on at most one side of the interval
- query answer is the best value among the lines stored on one root-to-leaf path

## Main Traps

- forgetting to insert the initial/base line
- mixing up min and max conventions
- using a domain that does not cover every query `x`
- ignoring overflow in `m * x + b`
- shipping a Li Chao tree when `Monster Game I`-style monotonicity would have made a deque hull cleaner

## Exact Starters In This Repo

- exact starter -> [`li-chao-tree.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/li-chao-tree.cpp)
- flagship in-lane rep -> [Monster Game II](../practice/ladders/dp/cht-li-chao/monstergame2.md)
- compare lighter hull route -> [Monster Game I](https://cses.fi/problemset/task/2084)
- raw official verifier -> [Library Checker: Line Add Get Min](https://judge.yosupo.jp/problem/line_add_get_min)

## Reopen Paths

- full chooser and Li Chao midpoint invariant -> [Convex Hull Trick / Li Chao Tree](../topics/dp/cht-li-chao/README.md)
- parent DP router -> [DP cheatsheet](dp-cheatsheet.md)
- snippet chooser -> [Template Library](../template-library.md)
