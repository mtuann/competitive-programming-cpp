# Interval DP

Interval DP is the right model when the subproblem is literally:

- solve this subarray
- solve this substring
- solve this polygon chain
- solve this contiguous segment after choosing a split

The keyword is not "DP" by itself.

The keyword is:

- **contiguous interval**

Once the problem truly decomposes into smaller intervals, the whole solution becomes about:

- defining `dp[l][r]` correctly
- processing intervals in dependency-safe order
- deciding whether the transition is:
  - split by `k`
  - remove one end
  - merge two neighboring solved pieces

## At A Glance

- **Use when:** every state is a contiguous interval and each transition depends only on smaller nested intervals
- **Core worldview:** solve small intervals first, then build larger intervals from them
- **Main tools:** `dp[l][r]`, length-order iteration, split-point transitions, score-difference modeling, interval helper arrays such as prefix sums
- **Typical complexity:** often `O(n^3)` baseline, sometimes `O(n^2)` with simpler transitions or later optimizations
- **Main trap:** using interval DP when the problem is not truly contiguous, or writing the right recurrence but filling states in the wrong order

## Prerequisites

- [DP Foundations](../foundations/README.md)
- [Prefix Sums](../../foundations/patterns/prefix-sums/README.md)

Helpful neighboring topics:

- [Knapsack Family](../knapsack-family/README.md)
- [Bitmask DP](../bitmask-dp/README.md)

## Problem Model And Notation

Let the objects live on a line:

$$
a_0, a_1, \dots, a_{n-1}.
$$

The canonical state is:

$$
\mathrm{dp}[l][r] = \text{answer for interval } [l, r].
$$

Depending on the problem, the state may mean:

- minimum merge cost on `[l, r]`
- maximum score difference on `[l, r]`
- whether substring `[l, r]` is feasible
- best partition of `[l, r]`

The most important design question is:

```text
What exactly does dp[l][r] mean?
```

If that sentence is vague, the recurrence will be vague too.

## From Brute Force To The Right Idea

### Brute Force: Enumerate All Parenthesizations Or All Play Sequences

Many interval problems look exponential at first:

- every split point is possible
- every order of merges seems possible
- every game move sequence seems different

That is because the same smaller intervals appear again and again inside different global choices.

### The First Shift: The State Is The Remaining Interval

In interval DP, all that history is compressed into:

- left boundary `l`
- right boundary `r`

because once the interval is fixed, the future choices inside it no longer care how that interval was reached.

### The Second Shift: Every Legal First Move Produces Smaller Intervals

A split point `k` creates:

- `[l, k]`
- `[k+1, r]`

Removing one end creates:

- `[l+1, r]`
- or `[l, r-1]`

So the recursive structure is always:

- one interval depends on strictly smaller intervals

That is why length order works.

### The Third Shift: Auxiliary Precomputation Often Simplifies The Transition

Many interval transitions need:

- sum of `[l, r]`
- weight of a segment
- whether boundaries match

Those helpers are often static and should be precomputed once:

- prefix sums
- match tables
- coordinate costs

The interval DP should then focus only on the true combinatorial choice.

## Core Invariants And Why They Work

## 1. Interval Meaning Must Be Exact

The central invariant is:

```text
dp[l][r] has one precise semantic meaning for every valid interval.
```

Typical bad start:

- "`dp[l][r]` is kind of the best answer around this segment"

Typical good start:

- "`dp[l][r]` is the maximum score difference the current player can force on subarray [l, r]`"

That exact wording determines:

- base cases
- transition signs
- final extraction formula

## 2. Length Order Guarantees Dependencies Are Ready

If every transition uses only smaller intervals, then processing by increasing interval length is correct.

For example:

- length `1` intervals are base cases
- length `2` intervals depend on length `1`
- length `3` intervals depend on lengths `1` and `2`

and so on.

This is the interval analogue of topological order for states.

## 3. Split-Point Recurrences Cover All Decompositions

A very common recurrence shape is:

$$
\mathrm{dp}[l][r] =
\min_{l \le k < r}
\bigl(
\mathrm{dp}[l][k] + \mathrm{dp}[k+1][r] + \mathrm{extraCost}(l, k, r)
\bigr).
$$

Why is this correct?

Because any full decomposition of `[l, r]` has a first split point `k`. Once that split is chosen, the left and right parts are independent subproblems of the same type.

So:

- if you try all legal `k`
- and each branch combines optimal smaller answers

then every legal decomposition is represented.

## 4. Game Interval DP Often Works Better With Score Difference

For two-player interval games, absolute scores can make the recurrence messy.

The cleaner state is often:

$$
\mathrm{dp}[l][r] = \text{best score difference current player can force on } [l, r].
$$

Then if the current player takes `a[l]`, the opponent faces `[l+1, r]` and the net advantage becomes:

$$
a[l] - \mathrm{dp}[l+1][r].
$$

This is exactly the modeling trick behind:

- [Removal Game](../../../practice/ladders/dp/interval-dp/removalgame.md)

## 5. Prefix Sums Often Remove A Hidden Inner Loop

If each transition needs the sum of `[l, r]`, recomputing that sum inside the DP creates unnecessary work.

Use prefix sums so interval costs become:

$$
\mathrm{sum}(l, r) = \mathrm{pref}[r+1] - \mathrm{pref}[l].
$$

That keeps the DP focused on the real combinatorial split.

## Variant Chooser

### Use Split-Point Interval DP When

- the interval is partitioned into two smaller intervals
- a split point `k` is the main choice

Canonical examples:

- matrix chain multiplication
- optimal merge/partition costs
- polygon triangulation style recurrences

### Use Remove-From-Ends Interval DP When

- each move removes the left or right endpoint
- the remaining problem is still a contiguous interval

Canonical examples:

- optimal play games
- take-from-ends scoring problems

### Use Merge-On-Interval DP When

- neighboring pieces are merged with some interval-dependent cost

### Do Not Use Interval DP When

- the structure is not contiguous
- the state is really "subset" rather than interval
- the order of chosen elements matters more than adjacency

Then you may need:

- [Bitmask DP](../bitmask-dp/README.md)
- [Knapsack Family](../knapsack-family/README.md)

## Worked Examples

### Example 1: Removal Game

This is the repo's main interval-game anchor:

- [Removal Game](../../../practice/ladders/dp/interval-dp/removalgame.md)

Define:

$$
\mathrm{dp}[l][r] = \text{best score difference current player can force on } [l, r].
$$

Then:

$$
\mathrm{dp}[l][r]
=
\max(a[l] - \mathrm{dp}[l+1][r],\ a[r] - \mathrm{dp}[l][r-1]).
$$

This is a perfect example of:

- state meaning first
- recurrence second

### Example 2: Matrix-Chain Style Split

Suppose you must choose the first split point `k`.

Then the answer on `[l, r]` is:

- optimal left interval
- plus optimal right interval
- plus cost caused by joining those two solved parts

That is the archetypal `O(n^3)` interval DP.

Here is the smallest concrete trace worth internalizing.

Suppose the interval is:

```text
[0, 3]
```

and the recurrence is:

$$
\mathrm{dp}[l][r]
=
\min_{l \le k < r}
\bigl(
\mathrm{dp}[l][k] + \mathrm{dp}[k+1][r] + \mathrm{cost}(l, k, r)
\bigr).
$$

Then `[0, 3]` has exactly three first-split candidates:

- `k = 0`: split into `[0, 0]` and `[1, 3]`
- `k = 1`: split into `[0, 1]` and `[2, 3]`
- `k = 2`: split into `[0, 2]` and `[3, 3]`

So:

$$
\mathrm{dp}[0][3] =
\min \begin{cases}
\mathrm{dp}[0][0] + \mathrm{dp}[1][3] + \mathrm{cost}(0, 0, 3), \\
\mathrm{dp}[0][1] + \mathrm{dp}[2][3] + \mathrm{cost}(0, 1, 3), \\
\mathrm{dp}[0][2] + \mathrm{dp}[3][3] + \mathrm{cost}(0, 2, 3).
\end{cases}
$$

This is the right mental model for split-point interval DP:

- do not think "one complicated recurrence"
- think "try every legal first split, then recurse on the two resulting intervals"

### Example 3: Interval Cost From Prefix Sums

Suppose merging `[l, r]` costs the total sum on that interval.

Then prefix sums provide:

$$
\mathrm{sum}(l, r)
$$

in `O(1)`, so the DP does not waste work recomputing interval totals.

That is one of the most common pairings:

- prefix sums + interval DP

## Algorithms And Pseudocode

### Split-Point Skeleton

```text
initialize dp for base intervals

for len from 2 to n:
    for l from 0 to n-len:
        r = l + len - 1
        dp[l][r] = worst_possible_value
        for k from l to r-1:
            dp[l][r] = best(
                dp[l][r],
                combine(dp[l][k], dp[k+1][r], extra_cost(l, k, r))
            )
```

### Remove-From-Ends Skeleton

```text
for i from 0 to n-1:
    dp[i][i] = base_case(a[i])

for len from 2 to n:
    for l from 0 to n-len:
        r = l + len - 1
        dp[l][r] = combine_take_left_or_right(
            dp[l+1][r],
            dp[l][r-1]
        )
```

## Implementation Notes

- Write the state meaning in words before coding.
- Decide explicitly whether `dp[l][r]` is defined only for `l <= r`, or whether empty intervals are real states in your recurrence.
- Check base cases separately for:
  - empty intervals if they exist
  - length `1`
  - sometimes length `2`
- The repo default mental model is: `dp[l][r]` is defined for valid non-empty intervals, and empty intervals are introduced only if the recurrence truly needs them.
- The most common loop bug is getting `len`, `l`, `r` ordering wrong.
- If the recurrence depends on interval sums, precompute them first.
- `O(n^3)` is normal for classic interval DP. Do not panic if the structure is correct and constraints allow it.

## Practice Archetypes

You should strongly suspect interval DP when you see:

- subarrays or substrings
- split point `k`
- removing from ends
- recursive definitions over smaller contiguous segments

Repo anchors:

- [Removal Game](../../../practice/ladders/dp/interval-dp/removalgame.md)

Starter template:

- [interval-dp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/interval-dp.cpp)

Notebook refresher:

- [DP cheatsheet](../../../notebook/dp-cheatsheet.md)

## References And Repo Anchors

Course / tutorial style:

- [USACO Guide: Range DP](https://usaco.guide/gold/dp-ranges)
- [HKUST: Interval DP / Matrix-Chain Multiplication](https://cse.hkust.edu.hk/~dimitris/3711/16_DP_interval.pdf)
- [AtCoder Educational DP Contest](https://atcoder.jp/contests/dp)

Reference:

- [CP-Algorithms: Knuth Optimization](https://cp-algorithms.com/dynamic_programming/knuth-optimization.html)

Practice / repo anchors:

- [Interval DP ladder](../../../practice/ladders/dp/interval-dp/README.md)
- [Removal Game](../../../practice/ladders/dp/interval-dp/removalgame.md)

## Related Topics

- [DP Foundations](../foundations/README.md)
- [Knapsack Family](../knapsack-family/README.md)
- [Bitmask DP](../bitmask-dp/README.md)
- [Prefix Sums](../../foundations/patterns/prefix-sums/README.md)
- [Knuth Optimization](../knuth-optimization/README.md)
- [Divide and Conquer DP](../divide-and-conquer-dp/README.md)
