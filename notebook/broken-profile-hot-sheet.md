# Broken Profile Hot Sheet

Use this page when one grid dimension is small and the real state is the frontier between processed and unprocessed cells.

## Do Not Use When

- the mask is really a subset of items instead of a grid frontier
- both grid dimensions are large enough that `2^min(n, m)` is already dead
- the frontier must store connectivity labels and the simple occupancy starter is no longer enough

## Choose By Signal

- domino tiling or local-fill DP on a small-width grid -> [`broken-profile-domino-tiling.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/broken-profile-domino-tiling.cpp)
- same family, but frontier must remember pairings / connectivity -> reopen the full topic page before coding
- subset of items / tasks / vertices -> [Bitmask DP](../topics/dp/bitmask-dp/README.md)

## Core Invariants

- rotate so the smaller dimension becomes the masked frontier
- `mask` means which cells of the current column are already occupied before filling it
- row DFS builds one `next_mask`
- vertical placement stays inside the current column
- horizontal placement writes a bit into `next_mask`

## Main Traps

- mixing current-column occupancy with next-column occupancy
- not fixing one consistent meaning for bit `1`
- trying to jump straight to plug DP with connectivity labels
- forgetting odd-area boards have zero domino tilings

## Exact Starter Route

- exact starter -> [`broken-profile-domino-tiling.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/broken-profile-domino-tiling.cpp)
- flagship rep -> [Counting Tilings](../practice/ladders/dp/broken-profile/countingtilings.md)
- parent chooser -> [DP cheatsheet](dp-cheatsheet.md)
- compare point -> [Bitmask DP](../topics/dp/bitmask-dp/README.md)

## Reopen Paths

- full lesson -> [Broken Profile / Plug DP](../topics/dp/broken-profile/README.md)
- subset-mask cousin -> [Bitmask DP](../topics/dp/bitmask-dp/README.md)
- retrieval router -> [Build Kit](../docs/build-kit.md)
