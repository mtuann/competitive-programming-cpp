# Knuth Optimization Ladder

This ladder is for the narrow interval-DP lane where the baseline `O(n^3)` split-point recurrence can be reduced to `O(n^2)` by a monotone `opt` window.

## Who This Is For

Use this ladder if:

- you already recognize plain [Interval DP](../../../../topics/dp/interval-dp/README.md)
- you can write the merge-style recurrence
- you now need the exact stronger optimization, not a broader theory tour

## Core

- split-point interval recurrence
- `cost(l, r)` independent of `k`
- `opt[l][r-1] <= opt[l][r] <= opt[l+1][r]`

Target skill:

- know when Knuth is the exact optimization family, not divide-and-conquer DP

## Exact Starter

- [knuth-optimization.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/knuth-optimization.cpp)

Target skill:

- turn a proven `O(n^3)` merge-style interval DP into the standard `O(n^2)` table fill

## Flagship Rep

- [Knuth Division](knuthdivision.md)

Target skill:

- combine prefix-sum interval cost with the exact `opt` search window

## Stretch

- compare with [AtCoder DP N - Slimes](https://atcoder.jp/contests/dp/tasks/dp_n?lang=en)
- compare with [Interval DP](../../../../topics/dp/interval-dp/README.md)
- compare with [Divide and Conquer DP](../../../../topics/dp/divide-and-conquer-dp/README.md)

Target skill:

- separate `interval-state speedup` from `partition-row speedup`

## Exit Criteria

You are ready to move on when:

- you can state the recurrence shape from memory
- you know why `cost(l, r)` must not depend on `k`
- you can write the `opt[l][r-1] .. opt[l+1][r]` window without re-deriving loop order each time

## External Practice

- [CSES - Knuth Division](https://cses.fi/problemset/task/2088/)
- [AtCoder DP N - Slimes](https://atcoder.jp/contests/dp/tasks/dp_n?lang=en)
- [CP-Algorithms - Knuth's Optimization](https://cp-algorithms.com/dynamic_programming/knuth-optimization.html)

## Tutorial Link

- [Knuth Optimization](../../../../topics/dp/knuth-optimization/README.md)
