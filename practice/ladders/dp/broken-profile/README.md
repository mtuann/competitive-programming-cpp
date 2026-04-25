# Broken Profile / Plug DP Ladder

This lane is for the first time a mask stops meaning "chosen subset" and starts meaning "current grid frontier."

It is intentionally a narrow lane:

- one exact occupancy-mask starter
- one flagship domino-tiling rep
- a clear warning that full plug DP is a stronger follow-up, not the first snippet

## Who This Is For

Use this lane if:

- [Bitmask DP](../../../../topics/dp/bitmask-dp/README.md) already feels comfortable
- one small grid dimension is visible in the constraints
- the real state is a frontier between processed and unprocessed cells

## Warm-Up

- rotate the grid so the smaller dimension is the masked one
- define exactly what a `1` bit means in the current frontier
- generate one legal `next_mask` by scanning rows inside a column

Target skill:

- tell the difference between subset masks and frontier masks

## Core

- occupancy-mask broken profile
- row DFS that generates `next_mask`
- exact flagship rep: [Counting Tilings](countingtilings.md)

Target skill:

- compute one column transition without mixing current-column and next-column meaning

## Stretch

- plug DP where the frontier stores connectivity labels rather than only occupancy
- [USACO Guide - DP on Broken Profile](https://usaco.guide/adv/dp-broken-profile)
- [OI Wiki - Plug DP](https://en.oi-wiki.org/dp/plug/)

Target skill:

- know that full plug DP is the next escalation after occupancy-mask frontier DP, not the same thing

## Retrieval Layer

- exact quick sheet -> [Broken Profile hot sheet](../../../../notebook/broken-profile-hot-sheet.md)
- exact starter -> [broken-profile-domino-tiling.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/broken-profile-domino-tiling.cpp)
- parent chooser -> [DP cheatsheet](../../../../notebook/dp-cheatsheet.md)
- subset-mask compare point -> [Bitmask DP](../../../../topics/dp/bitmask-dp/README.md)

## Exit Criteria

You are ready to move on when:

- you can explain the frontier mask without talking vaguely about "processed stuff"
- you can generate `next_mask` by local placements only
- you know when occupancy masks stop being enough and full plug labels are needed

## External Practice

- [CSES - Counting Tilings](https://cses.fi/problemset/task/2181/)
- [USACO Guide - DP on Broken Profile](https://usaco.guide/adv/dp-broken-profile)

## Tutorial Link

- [Broken Profile / Plug DP](../../../../topics/dp/broken-profile/README.md)
