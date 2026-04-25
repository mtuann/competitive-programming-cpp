# Slope Trick

This lane is about one narrow optimization pattern:

- the DP state is a convex piecewise-linear function `f(x)`
- each transition adds one simple convex hinge like `max(0, x - a)` or `max(0, a - x)`
- and sometimes the minimizer interval may slide by a bounded amount

The point is not "advanced heaps for no reason."

The point is that many one-dimensional convex DPs can be updated online if we store only:

- the current minimum value
- the breakpoints where the slope changes
- and lazy offsets for how those breakpoints shift

This page is not about generic convex optimization.

It is about the exact contest lane that sits next to:

- [DP Foundations](../foundations/README.md)
- [Convex Hull Trick / Li Chao Tree](../cht-li-chao/README.md)
- the later follow-up lane `Lagrangian Relaxation / Aliens Trick`

## At A Glance

- **Use when:** the DP over one integer coordinate stays convex and piecewise linear, and every step adds one hinge penalty or widens the minimizer interval
- **Core worldview:** maintain the convex function itself through its slope-change points, not the full DP table
- **Main tools:** two heaps of breakpoints, lazy offsets, current minimum value, operations like `add max(0, x-a)`, `add max(0, a-x)`, `add |x-a|`, and `shift_min`
- **Typical complexity:** `O(log n)` per local update
- **Main trap:** reaching for slope trick before checking whether the problem is really just median maintenance, or whether the transition is actually affine and wants [CHT / Li Chao](../cht-li-chao/README.md)

Strong contest signals:

- `dp_i(x)` is the minimum cost to end at coordinate / value `x`
- each new event adds a one-sided damage or penalty like `max(0, X-x)` or `max(0, x-X)`
- movement between states creates a transition like `min_{|y-x| <= d} f(y)`
- editorials talk about a convex function, slope changes, breakpoints, or two heaps

Strong anti-cues:

- the transition is `min_j(m_j x + b_j)` over previous states -> [Convex Hull Trick / Li Chao Tree](../cht-li-chao/README.md)
- you only ever add `|x-a| + b` and query the smallest minimizer -> often a lighter median-maintenance route is enough
- the real bottleneck is one partition split or interval split -> [Divide and Conquer DP](../divide-and-conquer-dp/README.md) or [Knuth Optimization](../knuth-optimization/README.md)
- you are tuning a penalty parameter over counts / resources, not maintaining one convex function in `x`

## Prerequisites

- [DP Foundations](../foundations/README.md)
- [Heaps And Ordered Sets](../../data-structures/heaps-and-ordered-sets/README.md)

Helpful neighboring topics:

- [Convex Hull Trick / Li Chao Tree](../cht-li-chao/README.md)
- [Lagrangian Relaxation / Aliens Trick](../lagrangian-relaxation/README.md) when the real move is penalizing a count dimension rather than maintaining one convex piecewise-linear state

## Problem Model And Notation

The canonical setup is:

$$
f_i(x) = \text{best value after processing the first } i \text{ events and ending at } x.
$$

The function stays convex and piecewise linear over integer `x`.

The exact starter in this repo is built around four operations:

1. add a right hinge:

$$
f(x) \leftarrow f(x) + \max(0, x-a)
$$

2. add a left hinge:

$$
f(x) \leftarrow f(x) + \max(0, a-x)
$$

3. add an absolute-value penalty:

$$
f(x) \leftarrow f(x) + |x-a|
$$

4. widen the minimizer interval:

$$
f(x) \leftarrow \min_{y \in [x-r,\,x-l]} f(y)
$$

The starter exposes the widening step as `shift_min(delta_left, delta_right)`, meaning:

- every minimizing point `x` may move to the interval `[x + delta_left, x + delta_right]`

The common movement relaxation `|y-x| <= d` is therefore:

```text
shift_min(-d, +d)
```

## Why Two Heaps Are Enough

The function is convex, so its slope only changes at breakpoint positions.

We keep:

- a max-heap for breakpoints on the left side
- a min-heap for breakpoints on the right side
- lazy offsets for both heaps
- the current minimum value `min_f`

The heaps encode the current minimizer interval:

- left boundary = top of the left heap after its lazy offset
- right boundary = top of the right heap after its lazy offset

When we add a hinge:

- if the hinge does not cut through the minimizer interval, `min_f` stays the same
- otherwise, the function minimum rises by exactly how far the hinge cuts past the interval boundary

That is why each update is just:

- compare against one heap top
- move one breakpoint across heaps
- update `min_f`

## Core Invariants

## 1. `min_f` Is The Current Global Minimum

We do not reconstruct the whole function value table.

We only maintain the minimum value itself, and how the breakpoint multiset changes around that minimum.

## 2. The Left Heap Tracks "Too-Far-Right" Breakpoints

After lazy offsets are restored, the left heap top is the greatest breakpoint still relevant on the left side of the minimizer interval.

When `max(0, x-a)` is added, this left boundary decides whether the minimum must rise.

## 3. The Right Heap Tracks "Too-Far-Left" Breakpoints

Symmetrically, the right heap top is the smallest breakpoint still relevant on the right side.

When `max(0, a-x)` is added, this right boundary decides whether the minimum must rise.

## 4. `shift_min` Moves Breakpoints Lazily

If the transition only widens where the minimizer may live, we do not touch every breakpoint.

We shift the left and right heap coordinate systems lazily.

That is the exact reason `Snuketoon` becomes `O(n log n)` instead of a huge coordinate DP.

## Worked Example: Snuketoon

In [Snuketoon](../../../practice/ladders/dp/slope-trick/snuketoon.md), define:

$$
f_i(x) = \text{minimum total damage after the first } i \text{ shots, standing at } x \text{ at time } T_i.
$$

The exact start state is:

$$
f_0(0) = 0, \qquad f_0(x) = +\infty \text{ for } x \neq 0.
$$

In code, a standard contest convention is to encode this pinned starting point by seeding enough copies of breakpoint `0` into both heaps before the updates begin.

If time advances by `dt = T_i - T_{i-1}`, then movement by at most `dt` means:

$$
f(x) \leftarrow \min_{|y-x| \le dt} f(y),
$$

which is the exact `shift_min(-dt, +dt)` operation.

Then one shot adds a one-sided hinge:

- `D_i = 0` adds `max(0, X_i - x)`
- `D_i = 1` adds `max(0, x - X_i)`

So the whole problem is nothing more than:

1. widen the minimizer interval by movement
2. add one hinge penalty

That is the cleanest in-repo first flagship for slope trick.

## Variant Chooser

### Use A Lighter Median / Two-Heaps Route When

- the only update is `f(x) += |x-a| + b`
- you only need one minimizer and the minimum value
- there is no `shift_min` / movement relaxation

The official warm-up compare point here is `Absolute Minima`.

### Use Slope Trick When

- the state is truly one convex function `f(x)`
- updates are hinge penalties or small convex local edits
- movement / relaxation widens where the minimum can occur

### Use CHT / Li Chao When

- previous states turn into lines
- and current state is one point query `min_j(m_j x + b_j)`

That is a different family from this one.

### Use Lagrangian / Aliens Trick Later When

- you are not maintaining `f(x)` over a coordinate
- instead, you are binary searching or sweeping a penalty parameter to control how many segments / operations are used

## Implementation Notes

- store `min_f` as `long long`
- represent the left heap as a max-heap and the right heap as a min-heap
- keep two lazy offsets instead of eagerly shifting all breakpoints
- `add_abs(a)` is just `add_x_minus_a(a)` followed by `add_a_minus_x(a)`
- for `shift_min(left, right)`, ensure `left <= right`
- if the initial function is the constant zero function, both heaps may start empty

## Common Failure Modes

- reversing the semantics of `add max(0, x-a)` and `add max(0, a-x)`
- forgetting that `shift_min(-d, d)` corresponds to bounded movement by distance `d`
- using slope trick when only an affine hull is needed
- overclaiming that the starter reconstructs the full function, when it only tracks the minimum and minimizer interval
- mixing integer-coordinate slope trick with floating geometry / continuous optimization

## Reopen Paths

- exact starter and quick refresher -> [Slope Trick hot sheet](../../../notebook/slope-trick-hot-sheet.md)
- flagship in-repo anchor -> [Snuketoon](../../../practice/ladders/dp/slope-trick/snuketoon.md)
- compare affine family -> [Convex Hull Trick / Li Chao Tree](../cht-li-chao/README.md)
- broader router -> [Dynamic Programming](../README.md)
