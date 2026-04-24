# VMMARBLE

- Title: `VMMARBLE - Phân loại bi`
- Judge / source: `VN SPOJ`
- Original URL: [https://vn.spoj.com/problems/VMMARBLE/](https://vn.spoj.com/problems/VMMARBLE/)
- Secondary topics: `Assignment`, `Lower bound equals construction`, `Keeper-box selection`
- Difficulty: `medium`
- Subtype: `Choose one kept color per box so every present color has at least one keeper`
- Status: `solved`
- Solution file: [vmmarble.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/bitmask-dp/vmmarble.cpp)

## Why Practice This

This is a nice example of converting a movement story into a much smaller assignment DP.

At first glance it looks like a transportation problem, but the real structure is simpler: each box only needs to decide which color it will keep.

## Core Idea

Fix a final plan where each box keeps at most one color.

Consider one source-color group:

- box `i`
- color `j`
- `A[i][j]` marbles

If box `i` does **not** keep color `j`, then all `A[i][j]` marbles must leave box `i`.

That already gives a lower bound:

- one move carries at most `K` marbles
- so this group costs at least `ceil(A[i][j] / K)` moves

And that lower bound is also achievable:

- send those marbles directly to any box that keeps color `j`

So for a fixed keeper-color choice, the minimum cost is exactly:

```text
sum over all groups not kept in their original box of ceil(A[i][j] / K)
```

Now the problem becomes:

- every box chooses one color to keep, or effectively keeps none
- every color that actually appears must be kept by at least one box
- maximize the total saved cost from groups that do stay in place

That is a standard bitmask DP over the set of already-covered colors.

## Complexity

- states: `2^M`
- transitions: `N * M * 2^M`

This matches the scored subtasks well:

- `M <= 10` when `K = 1`
- `M <= 3` when `K = 2`

## Pitfalls / Judge Notes

- You only need to require keeper boxes for colors whose total count is positive.
- Multiple boxes may keep the same color. Boxes are allowed to end up empty.
- The important proof step is that each unwanted source-color group has an exact cost:
  `ceil(A[i][j] / K)`.
  Without that, the DP looks unjustified.

## Reusable Pattern

- Topic page: [Bitmask DP](../../../../topics/dp/bitmask-dp/README.md)
- Practice ladder: [Bitmask DP ladder](README.md)
- Starter template: [bitmask-subset-iterate.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/bitmask-subset-iterate.cpp)
- Notebook refresher: [DP cheatsheet](../../../../notebook/dp-cheatsheet.md)
- Carry forward: define what the mask means in plain language before writing transitions.
- This note adds: the state compression and transition ordering specific to this marble DP.

## Solutions

- Code: [vmmarble.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/bitmask-dp/vmmarble.cpp)
