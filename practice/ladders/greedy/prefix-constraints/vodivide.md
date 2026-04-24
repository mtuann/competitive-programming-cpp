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

## Recognition Cue

This is a `sort first, then enforce prefix feasibility` greedy pattern:

- the pairing relation is determined by an order key `a[i]`
- one side of every pair must come earlier after sorting
- the objective depends on choosing a subset with minimum or maximum weight
- feasibility can be stated on every prefix, not on arbitrary subsets

When a pairing problem becomes a laminar family of prefix capacities after sorting, a heap-based greedy is often the right tool.

## Problem-Specific Transformation

After sorting by increasing `a[i]`, the pairing story is rewritten as:

- choose exactly `N / 2` positions that will belong to Vinh
- in every prefix of length `p`, at most `floor(p / 2)` chosen positions may belong to Vinh
- minimize the total `b[i]` on those chosen positions

That turns the problem into a minimum-weight selection under nested prefix constraints. The actual pair list is reconstructed only after the role set is fixed.

## Core Idea

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

- if a position belongs to Sơn, store it as one available earlier partner
- if a position belongs to Vinh, match it with any still-unused earlier Sơn position

### Why The Heap Greedy Is Safe

The prefix constraints are nested: every later prefix contains every earlier one. So whenever the current chosen set becomes too large for the current prefix, we must delete **some** chosen coin from that prefix.

Removing the chosen coin with largest `b` is always optimal, because every feasible solution for later prefixes must still respect this current prefix cap. Keeping a larger `b` coin can only make the objective worse while using the same amount of prefix capacity.

That is exactly the exchange argument behind the max-heap repair step.

### Why Reconstruction Is Guaranteed

The prefix condition is not only necessary. It is also sufficient.

While scanning left to right, suppose we arrive at one position chosen for Vinh. The prefix rule says that among all positions seen so far, at most half belong to Vinh. Therefore there must be at least one earlier unused Sơn position available to pair with this Vinh position.

So any structure that stores earlier unused Sơn positions works for reconstruction; a stack is just one convenient implementation choice.

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

- Topic page: [Prefix Constraints](../../../../topics/greedy/prefix-constraints/README.md)
- Practice ladder: [Prefix Constraints ladder](README.md)
- Starter template: [contest-main.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/contest-main.cpp)
- Notebook refresher: [Foundations cheatsheet](../../../../notebook/foundations-cheatsheet.md)
- Carry forward: turn the prefix condition into a local invariant you can check after each decision.
- This note adds: the greedy commitment rule and repair logic for this prefix-constrained setting.

## Solutions

- Code: [vodivide.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/greedy/prefix-constraints/vodivide.cpp)
