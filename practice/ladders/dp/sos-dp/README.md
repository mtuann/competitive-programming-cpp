# SOS DP Ladder

This lane is for the first time a mask problem stops being "add one bit to the state" and becomes "precompute one aggregate for every mask on the full cube."

It is intentionally narrow:

- one exact starter
- one flagship complement-mask witness rep
- strong compare points back to Bitmask DP and Broken Profile

## Who This Is For

Use this lane if:

- [Bitmask DP](../../../../topics/dp/bitmask-dp/README.md) already feels comfortable
- you can already read complement masks and subset relations without hesitation
- the real bottleneck is repeated all-submask or all-supermask aggregation

## Warm-Up

- complement-mask modeling
- subset direction vs superset direction
- why this is not ordinary `dp[mask]` with add-one-bit transitions

Warm-up compare points:

- [Bitmask DP](../../../../topics/dp/bitmask-dp/README.md)
- [Broken Profile / Plug DP](../../../../topics/dp/broken-profile/README.md)

Target skill:

- say clearly whether the task wants subset aggregation, superset aggregation, or one witness carried along the same sweep

## Core

- subset zeta sweep
- superset zeta sweep
- exact flagship rep: [Compatible Numbers](compatiblenumbers.md)

Target skill:

- turn a bitwise predicate into one complement-mask query on a transformed full-cube array

## Stretch

- [CSES - SOS Bit Problem](https://cses.fi/problemset/task/1654/)
- [USACO Guide - Sum over Subsets DP](https://usaco.guide/plat/dp-sos?lang=py)

Target skill:

- know when the starter still fits directly and when the real work is modeling several subset/superset counts in one problem

## Retrieval Layer

- exact quick sheet -> [SOS DP hot sheet](../../../../notebook/sos-dp-hot-sheet.md)
- exact starter -> [sos-dp-zeta.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/sos-dp-zeta.cpp)
- parent chooser -> [DP cheatsheet](../../../../notebook/dp-cheatsheet.md)
- compare point -> [Bitmask DP](../../../../topics/dp/bitmask-dp/README.md)

## Exit Criteria

You are ready to move on when:

- you can state whether the query wants submasks or supersets before coding
- you know when to query `mask` directly and when to query `full ^ mask`
- you can reuse the same sweep skeleton for sums and for one witness value
- you know not to use this lane when the state is really one evolving subset DP

## External Practice

- [Codeforces - Compatible Numbers](https://codeforces.com/problemset/problem/165/E)
- [CSES - SOS Bit Problem](https://cses.fi/problemset/task/1654/)
- [USACO Guide - Sum over Subsets DP](https://usaco.guide/plat/dp-sos?lang=py)

## Tutorial Link

- [SOS DP](../../../../topics/dp/sos-dp/README.md)
