# Bit-Parallelism / Bitset Optimization Hot Sheet

Use this page when a DP or reachability problem is still basically right, but a boolean state row is large enough that word packing should replace scalar transitions.

## Do Not Use When

- the DP stores best value, min cost, or number of ways instead of boolean reachability
- the state space is the full boolean cube and the real job is a transform -> [FWHT / XOR Convolution / Subset Convolution hot sheet](fwht-subset-convolution-hot-sheet.md)
- ordinary `O(nW)` is already tiny and simpler

## Choose By Signal

- `reachable |= reachable << w` is the exact update you want -> this lane
- the problem is still classic item/capacity DP without clear word-parallel leverage -> [Knapsack Family](../topics/dp/knapsack-family/README.md)
- every mask needs all-submask or all-superset aggregates -> [SOS DP hot sheet](sos-dp-hot-sheet.md)

## Core Invariants

- bit `x` represents whether state `x` is reachable
- left shift by `w` means "add item of weight `w` to every currently reachable state"
- OR merges old states and new states exactly like boolean `0/1` subset-sum DP
- dynamic implementations must trim tail bits above the maximum allowed index

## Main Traps

- using this starter for value DP or counting DP
- forgetting to trim bits above `max_sum`
- overcomplicating with the full boolean-cube transform family when one sum axis is all you need
- forgetting that the flagship route may have a light modeling step before the bitset DP starts

## Reopen Paths

- full lesson -> [Bit-Parallelism / Bitset Optimization](../topics/dp/bit-parallelism/README.md)
- parent compare -> [Knapsack Family](../topics/dp/knapsack-family/README.md)
- transform compare -> [FWHT / XOR Convolution / Subset Convolution](../topics/dp/fwht-subset-convolution/README.md)
- exact starter -> [bitset-reachability-shift.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/bitset-reachability-shift.cpp)
- flagship rep -> [School Excursion](../practice/ladders/dp/bit-parallelism/schoolexcursion.md)
