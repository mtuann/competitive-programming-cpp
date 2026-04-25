# Divide and Conquer DP Ladder

This lane is for the first time a partition DP stops being "scan every split point for every state" and becomes one monotone-opt row computation.

It is intentionally a thin lane:

- one exact starter
- one flagship monotone-partition rep
- strong compare points back to interval DP and affine-DP optimization

## Who This Is For

Use this lane if:

- [DP Foundations](../../../../topics/dp/foundations/README.md) already feels comfortable
- you can already write the naive partition recurrence
- the real bottleneck is the `O(n^2)` split-point scan inside one DP row

## Warm-Up

- derive `dp[g][i] = min_k(prev[k] + cost(k + 1, i))`
- preprocess `cost(l, r)` until it is cheap
- understand why this is not an affine-line problem

Warm-up compare points:

- [Interval DP](../../../../topics/dp/interval-dp/README.md)
- [Convex Hull Trick / Li Chao Tree](../../../../topics/dp/cht-li-chao/README.md)

Target skill:

- say clearly why the next optimization is about split-point monotonicity, not line containers

## Core

- monotone argmins
- one row helper with `[L, R]` and `[optL, optR]`
- exact flagship rep: [Ciel and Gondolas](cielandgondolas.md)

Target skill:

- turn a partition DP into one exact divide-and-conquer row computation without losing the valid split range

## Stretch

- [Codeforces - Yet Another Minimization Problem](https://codeforces.com/problemset/problem/868/F)
- [USACO Guide - Divide & Conquer - DP](https://usaco.guide/plat/DC-DP)

Target skill:

- know when the exact starter still fits and when the cost preprocessing, not the row helper, becomes the real challenge

## Retrieval Layer

- exact quick sheet -> [Divide and Conquer DP hot sheet](../../../../notebook/divide-and-conquer-dp-hot-sheet.md)
- exact starter -> [divide-and-conquer-dp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/divide-and-conquer-dp.cpp)
- parent chooser -> [DP cheatsheet](../../../../notebook/dp-cheatsheet.md)
- affine compare point -> [CHT / Li Chao hot sheet](../../../../notebook/cht-hot-sheet.md)

## Exit Criteria

You are ready to move on when:

- you can write the partition recurrence before touching the optimization
- you know the starter only computes one row from `prev`
- you can explain why `best_k` shrinks the recursive search windows
- you know not to use this lane without monotone-opt evidence

## External Practice

- [Codeforces - Ciel and Gondolas](https://codeforces.com/problemset/problem/321/E)
- [Codeforces - Yet Another Minimization Problem](https://codeforces.com/problemset/problem/868/F)
- [USACO Guide - Divide & Conquer - DP](https://usaco.guide/plat/DC-DP)

## Tutorial Link

- [Divide and Conquer DP](../../../../topics/dp/divide-and-conquer-dp/README.md)
