# SOS DP Hot Sheet

Use this page when every mask on the full boolean cube needs an aggregate over:

- all of its submasks
- all of its supersets
- or one witness propagated along the same sweep

## Do Not Use When

- the state evolves by adding one chosen bit -> [Bitmask DP](../topics/dp/bitmask-dp/README.md)
- the mask is a moving grid frontier -> [Broken Profile / Plug DP](../topics/dp/broken-profile/README.md)
- the intended transform is xor/and convolution beyond this starter
- the universe is too large for dense arrays of size `1 << bits`

## Choose By Signal

- need `sum_{submask ⊆ mask}` for every `mask` -> subset zeta sweep
- need `sum_{supermask ⊇ mask}` for every `mask` -> superset zeta sweep
- need one present submask witness for every `mask` -> same subset sweep, but overwrite instead of `+`
- bitwise condition like `x & y == 0` -> usually query the transformed array at `full ^ x`

## Core Invariants

- subset sweep: if `mask` has bit `b`, fold from `mask ^ (1 << b)` into `mask`
- superset sweep: if `mask` does not have bit `b`, fold from `mask | (1 << b)` into `mask`
- after processing all bits, every dimension of the boolean cube has been prefix-swept once
- the same loop skeleton works for sums, counts, booleans, and one witness value
- the main modeling step is often converting the original predicate into one subset/superset query, frequently via complement masks

## Main Traps

- reversing subset and superset directions
- forgetting that `x & y == 0` means `y ⊆ full ^ x`
- treating this as plain `dp[mask]` evolution instead of one offline cube sweep
- opening this lane when explicit submask enumeration is already enough

## Exact Starter Route

- exact starter -> [sos-dp-zeta.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/sos-dp-zeta.cpp)
- flagship rep -> [Compatible Numbers](../practice/ladders/dp/sos-dp/compatiblenumbers.md)
- compare point -> [Bitmask DP](../topics/dp/bitmask-dp/README.md)
- compare point -> [Broken Profile / Plug DP](../topics/dp/broken-profile/README.md)
- parent chooser -> [DP cheatsheet](dp-cheatsheet.md)

## Reopen Paths

- full lesson -> [SOS DP](../topics/dp/sos-dp/README.md)
- broader chooser -> [DP cheatsheet](dp-cheatsheet.md)
- snippet chooser -> [Template Library](../template-library.md)
- retrieval router -> [Build Kit](../docs/build-kit.md)
