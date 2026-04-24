# VODIVIDE

- Title: `Chia phần`
- Judge / source: `VN SPOJ`
- Original URL: [https://vn.spoj.com/problems/VODIVIDE/](https://vn.spoj.com/problems/VODIVIDE/)
- Secondary topics: `Sorting`, `Laminar constraints`, `Pair reconstruction`
- Difficulty: `hard`
- Subtype: `Maximum reward perfect pairing under ordered dominance`
- Source contest: `VOI 2015 Day 2`
- Status: `solved`
- Solution file: [vodivide.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/greedy/prefix-constraints/vodivide.cpp)

## Why Practice This

This is a good greedy problem because the pairing story hides a clean ordered-selection model. After sorting by `a[i]`, the hard part is no longer matching itself, but choosing which coins should go to Vinh while respecting prefix feasibility.

## Key Idea

Sort the coins by increasing `a[i]`.

In any pair, Sơn receives the coin with smaller `a`, and Vinh receives the one with larger `a`. So after sorting, every pair matches:

- one earlier position for Sơn
- one later position for Vinh

If we mark Vinh's coins in the sorted order, then for every prefix of length `p`:

`Vinh_count(prefix) <= floor(p / 2)`

Why? In the first `p` positions, each coin given to Vinh needs an earlier partner already reserved for Sơn.

So the problem becomes:

- choose exactly `N / 2` positions for Vinh
- minimize the sum of their `b[i]`

Then Sơn's answer is:

`sum(b) - sum(b of Vinh's coins)`

This is a minimum-weight selection under nested prefix-capacity constraints. The greedy solution is:

1. scan the sorted coins from left to right
2. tentatively add the current coin to Vinh's set
3. if the chosen set size exceeds `floor(i / 2)` for the current prefix, remove the chosen coin with largest `b`

Use a max-heap for that.

After deciding which positions belong to Vinh, reconstruct an actual pairing by scanning left to right:

- if a position belongs to Sơn, push it into a stack
- if a position belongs to Vinh, pop one earlier Sơn position and pair them

## Complexity

- sorting: `O(n log n)`
- greedy selection with heap: `O(n log n)`
- reconstruction: `O(n)`

With `n <= 5000`, this is easily fast enough.

## Pitfalls / Judge Notes

- The key constraint is on **prefixes after sorting by `a`**, not on arbitrary subsets.
- It is easier to minimize the total `b` of Vinh's coins than to maximize Sơn's directly.
- Store original indices before sorting, because the output must use the original numbering.
- Reconstruct the pairs after the greedy choice; the heap only decides roles, not the actual pair list.

## Reusable Pattern

- Practice ladder: [Prefix Constraints ladder](README.md)
- Starter template: [Template library overview](../../../../template-library.md)
- Notebook refresher: [Foundations cheatsheet](../../../../notebook/foundations-cheatsheet.md)
- Carry forward: turn the prefix condition into a local invariant you can check after each decision.
- This note adds: the greedy commitment rule and repair logic for this prefix-constrained setting.

## Solutions

- Code: [vodivide.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/greedy/prefix-constraints/vodivide.cpp)
