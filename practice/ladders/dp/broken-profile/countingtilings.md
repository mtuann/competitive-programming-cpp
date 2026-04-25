# Counting Tilings

- Title: `Counting Tilings`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/2181](https://cses.fi/problemset/task/2181)
- Secondary topics: `Frontier mask`, `Column sweep`, `Domino tilings`
- Difficulty: `hard`
- Subtype: `Count domino tilings of a grid with one small dimension`
- Status: `solved`
- Solution file: [countingtilings.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/broken-profile/countingtilings.cpp)

## Why Practice This

This is the cleanest first verifier for the repo's broken-profile lane.

The problem is not asking for a fancy optimization theorem.

It is asking you to learn one exact worldview:

- process the grid one column at a time
- summarize the future by the current frontier occupancy mask
- locally generate the next frontier

That is the canonical first broken-profile route.

## Recognition Cue

Reach for broken profile here when:

- the state is on a grid frontier, not on a subset of items
- one dimension is tiny
- the fill rule is local
- the board is tiled by small pieces

The strongest smell is:

- `n <= 10`, `m` large, and local domino placements only

## Problem-Specific Transformation

Let:

- `h = min(n, m)`
- `w = max(n, m)`

and process the board column-by-column over width `w`.

Define:

```text
dp[mask] = number of ways to finish all previous columns
           such that the current column begins with occupancy mask `mask`
```

A bit `1` in `mask` means:

```text
this cell is already occupied before we start filling this column
```

Then for each column:

1. run a DFS over rows
2. if a row is already occupied, skip it
3. otherwise place either:
   - a vertical domino inside the current column
   - or a horizontal domino, which sets a bit in `next_mask`
4. accumulate the result into `dp_next[next_mask]`

The answer after all columns is:

```text
dp[0]
```

because the last frontier must be empty.

## Core Idea

The hard part is not the modulo arithmetic.

The hard part is keeping one consistent interpretation of the frontier.

In this repo's route:

- current `mask` describes what is already occupied in the current column
- `next_mask` describes what will already be occupied in the next column because of horizontal dominos started now

So:

- vertical domino -> does not touch `next_mask`
- horizontal domino -> writes exactly one bit into `next_mask`

Once that invariant is clean, the whole solution becomes a rolled DP over columns plus a row DFS that generates legal next states.

## Complexity

- number of masks: `2^h`
- for each of `w` columns, each mask generates local placements by a DFS over `h` rows
- total: `O(w * 2^h * transitions)`

This is exactly why the problem caps one dimension at `10`.

## Pitfalls / Judge Notes

- If `n * m` is odd, the answer is immediately `0`.
- Always rotate so the smaller dimension is the masked frontier.
- Do not mix "occupied in current column" with "occupied in next column".
- The modulo is `10^9 + 7`.

## Reusable Pattern

- Topic page: [Broken Profile / Plug DP](../../../../topics/dp/broken-profile/README.md)
- Practice ladder: [Broken Profile / Plug DP ladder](README.md)
- Starter template: [broken-profile-domino-tiling.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/broken-profile-domino-tiling.cpp)
- Notebook refresher: [Broken Profile hot sheet](../../../../notebook/broken-profile-hot-sheet.md)
- Compare point: [Bitmask DP](../../../../topics/dp/bitmask-dp/README.md)
- This note adds: the exact current-mask to next-mask domino transition route for a small-width grid.

## Solutions

- Code: [countingtilings.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/broken-profile/countingtilings.cpp)
