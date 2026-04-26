# Bit-Parallelism / Bitset Optimization Ladder

This lane is for when one boolean DP row is still the right model, but scalar state updates are no longer the right implementation.

It stays intentionally narrow:

- exact starter = dynamic bitset shift-OR reachability
- flagship rep = one problem where modeling reduces to component sizes, then bitset subset sum does the rest
- string-bitset and other packed-state tricks stay as later compare points

## Who This Is For

Use this lane if:

- [Knapsack Family](../../../../topics/dp/knapsack-family/README.md) already feels familiar
- you can recognize a boolean reachability DP quickly
- the main bottleneck is the width of one boolean row, not the recurrence shape itself

## Warm-Up

- ordinary subset-sum reachability
- why `reachable |= reachable << w` matches the boolean `0/1` transition
- why this is not the same family as [FWHT / XOR Convolution / Subset Convolution](../../../../topics/dp/fwht-subset-convolution/README.md)

Warm-up compare points:

- [Knapsack Family](../../../../topics/dp/knapsack-family/README.md)
- [FWHT / XOR Convolution / Subset Convolution](../../../../topics/dp/fwht-subset-convolution/README.md)

## Core

- packed shift-OR reachability
- tail trimming
- exact flagship rep: [School Excursion](schoolexcursion.md)

Target skill:

- see one feasibility DP on a large sum axis and know when word packing is the real win

## Stretch

- [CSES - Money Sums](https://cses.fi/problemset/task/1745/)
- string bitset speedups
- other boolean-state packed DP rows

Target skill:

- know when the bitset route is just a cleaner implementation of the same DP, and when it is the only practical implementation

## Retrieval Layer

- exact quick sheet -> [Bit-Parallelism / Bitset Optimization hot sheet](../../../../notebook/bit-parallelism-hot-sheet.md)
- exact starter -> [bitset-reachability-shift.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/bitset-reachability-shift.cpp)
- parent chooser -> [DP cheatsheet](../../../../notebook/dp-cheatsheet.md)
- compare point -> [Knapsack Family](../../../../topics/dp/knapsack-family/README.md)

## External Practice

- [CSES - School Excursion](https://cses.fi/problemset/task/1706/)
- [CSES - Money Sums](https://cses.fi/problemset/task/1745/)

## Tutorial Link

- [Bit-Parallelism / Bitset Optimization](../../../../topics/dp/bit-parallelism/README.md)
