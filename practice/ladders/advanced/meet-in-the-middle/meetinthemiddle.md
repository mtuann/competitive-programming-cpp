# Meet in the Middle

- Title: `Meet in the Middle`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1628](https://cses.fi/problemset/task/1628)
- Secondary topics: `Subset sums`, `Sort + equal_range`, `Exact search`
- Difficulty: `medium-hard`
- Subtype: `Count how many subsets sum to x when n is too large for plain 2^n enumeration`
- Status: `solved`
- Solution file: [meetinthemiddle.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/meet-in-the-middle/meetinthemiddle.cpp)

## Why Practice This

This is the cleanest exact-search anchor for the meet-in-the-middle bridge.

It teaches the real square-root win without adding extra modeling layers like:

- graph structure
- pruning heuristics
- or algebraic transformations

The whole route is:

- split the array
- enumerate both halves
- and merge half-sum summaries correctly

That makes it the right first internal note for the lane.

## Recognition Cue

Reach for meet-in-the-middle when:

- the state is subset-like
- `n` is around `35` to `45`
- full `2^n` search is too large
- but one left/right split plus sorting or hashing still looks cheap enough

The strongest smell is:

- "count / find subsets with sum x" under `n <= 40`

That is often not DP first. It is square-root exact search first.

## Problem-Specific Transformation

The statement asks:

- in how many ways can we choose a subset whose sum is `x`?

The brute-force route would enumerate all `2^n` subsets.

The reusable rewrite is:

- split the array into two halves
- enumerate all sums in each half
- for each left-half sum `s`, count how many right-half sums equal `x - s`

So the real object is not one full subset anymore.

It is:

- one pair of half-subsets whose sums add to `x`

## Core Idea

Let:

- `L` be the left half
- `R` be the right half

Compute:

- all subset sums of `L`
- all subset sums of `R`

Then sort the right-half sums.

For each left sum `s`:

- we need the number of right sums equal to `x - s`

That is exactly:

```text
equal_range(right_sums, x - s)
```

and the width of that range is the number of matching right-half subsets.

This duplicate handling matters.

The task counts subsets, not distinct sum values.

## Complexity

- enumerate left sums: `O(2^{n/2})`
- enumerate right sums: `O(2^{n/2})`
- sort one side: `O(2^{n/2} log 2^{n/2})`
- merge by binary search: `O(2^{n/2} log 2^{n/2})`

This is the intended improvement over `O(2^n)`.

## Pitfalls / Judge Notes

- Count multiplicity. Equal right-half sums correspond to different subsets and must all be counted.
- The answer can exceed `int`, so store it in `long long`.
- If you only check feasibility, you can miss the real lesson of this benchmark, which is multiplicity-aware merging.
- This note is the subset-sum counting route. When overlapping subproblems dominate instead, the cleaner route may be DP rather than MITM.

## Reusable Pattern

- Topic page: [Meet-In-The-Middle](../../../../topics/advanced/meet-in-the-middle/README.md)
- Practice ladder: [Meet-In-The-Middle ladder](README.md)
- Starter template: [meet-in-the-middle-subset-sum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/advanced/meet-in-the-middle-subset-sum.cpp)
- Notebook refresher: [Meet-In-The-Middle hot sheet](../../../../notebook/meet-in-the-middle-hot-sheet.md)
- Compare points: [Recursion And Backtracking](../../../../topics/foundations/recursion-backtracking/README.md), [Bitmask DP](../../../../topics/dp/bitmask-dp/README.md), [Discrete Logarithm Mod](../../math/bsgs-discrete-log/discretelogarithmmod.md)
- Carry forward: design the half summary and the merge layer before you write the enumeration loops.
- This note adds: multiplicity-aware merge through one sorted half and `equal_range`.

## Solutions

- Code: [meetinthemiddle.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/meet-in-the-middle/meetinthemiddle.cpp)
