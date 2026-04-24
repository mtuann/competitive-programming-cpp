# VOSFENCE

- Title: `Xay hang rao`
- Judge / source: `VN SPOJ / VNOI`
- Original URL: [https://vn.spoj.com/problems/VOSFENCE/](https://vn.spoj.com/problems/VOSFENCE/)
- Mirror URL: [https://oj.vnoi.info/problem/vosfence](https://oj.vnoi.info/problem/vosfence)
- Secondary topics: `Run counting`, `DP counting`, `Stars and bars with upper bounds`
- Difficulty: `hard`
- Subtype: `Count colorings with no K consecutive whites and exactly M blue-red adjacencies`
- Source contest: `VOS Round 24`
- Status: `solved`
- Solution file: [vosfence.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/combinatorics/bounded-compositions/vosfence.cpp)

## Why Practice This

This is a nice example of splitting one messy counting problem into two much cleaner layers:

- count the red/blue skeleton by how many color changes it has
- count how to insert white bars into the gaps under upper-bound constraints

The final answer is the product of those two counts, summed over all possible skeleton transition counts.

## Recognition Cue

Reach for a decomposition like this when:

- one color or symbol behaves like separators or gaps
- adjacency constraints can be described on the non-separator skeleton first
- after fixing that skeleton, the leftover placements become bounded compositions

The strongest smell is:

- "count strings/colorings under both adjacency rules and maximum-run rules"

That often means split the structure into:

- a core sequence
- and bounded fillers between its parts

## Problem-Specific Transformation

The raw fence-coloring statement is messy because all three colors interact.

The reusable rewrite is:

- first ignore white and count only the `B/R` skeleton
- then reinsert white runs into the gaps

That turns one tangled counting problem into two smaller ones:

- skeleton counting by run structure
- bounded gap counting by DP / stars-and-bars-with-caps

## Core Idea

Let the non-white sequence be the `B/R` skeleton first.

If the skeleton has `t` adjacent `BR` or `RB` transitions, then after inserting white bars:

- exactly `M` of those `t` transition positions must stay adjacent
- the other `t - M` transition positions must get at least one white bar inserted between them

Now look at all `b + r + 1` white gaps around the skeleton:

- `t - M` special gaps must contain at least `1` white bar
- the remaining `b + r + 1 - t` free gaps may contain `0` or more
- every gap can contain at most `K - 1` white bars, because `K` consecutive whites are forbidden

So for a fixed skeleton transition count `t`, the white-placement problem becomes a bounded composition problem.

## Counting The Skeleton

For a `B/R` sequence with:

- `b` blue bars
- `r` red bars
- exactly `t` color changes

we count it by runs.

Examples:

- if `t` is odd, the sequence starts and ends with different colors
- if `t` is even, it starts and ends with the same color

That gives a direct composition formula with binomial coefficients.

## Counting The White Gaps

For a fixed `t`:

- choose which `M` of the `t` transition gaps stay empty: `C(t, M)`
- the other `t - M` transition gaps must be positive
- the remaining `b + r + 1 - t` gaps are nonnegative

After subtracting `1` from each forced-positive gap, we need to count:

- `t - M` variables in `[0, K - 2]`
- `b + r + 1 - t` variables in `[0, K - 1]`
- total sum `W - (t - M)`

The solution precomputes these bounded-composition counts with small DP because `W, B, R <= 100`.

## Complexity

- run-count layer: `O(B + R)`
- bounded-composition DP: `O((B + R) * W * K)`
- final summation over `t`: `O((B + R) * W)`

This is easily fast enough for the official limits.

## Pitfalls / Judge Notes

- The “every segment of length `K` contains a blue or red bar” rule is exactly the same as saying there is **no run of `K` consecutive white bars**.
- The official mirror shows `1 <= W, B, R <= 100`, but also notes a subtask with `W = 0`, so the accepted solution should handle `W = 0` safely.
- If `K = 1`, then no white bar can appear at all. The implementation handles this as a special edge case automatically.
- When `B = 0` or `R = 0`, the skeleton has only one color, so the number of `BR/RB` adjacencies is always `0`.

## Reusable Pattern

- Topic page: [Bounded Compositions](../../../../topics/combinatorics/bounded-compositions/README.md)
- Practice ladder: [Bounded Compositions ladder](README.md)
- Starter template: [Template library overview](../../../../template-library.md)
- Notebook refresher: [Combinatorics cheatsheet](../../../../notebook/combinatorics-cheatsheet.md)
- Carry forward: translate counting constraints into slots, gaps, or bounded choices before coding.
- This note adds: the combinatorial decomposition and edge-case bookkeeping for this exact counting model.

## Solutions

- Code: [vosfence.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/combinatorics/bounded-compositions/vosfence.cpp)
