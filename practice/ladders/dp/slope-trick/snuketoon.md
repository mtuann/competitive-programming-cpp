# Snuketoon

- Title: `Snuketoon`
- Judge / source: `AtCoder ABC217 H`
- Original URL: [https://atcoder.jp/contests/abc217/tasks/abc217_h](https://atcoder.jp/contests/abc217/tasks/abc217_h)
- Secondary topics: `Slope trick`, `Convex DP`, `Two heaps`
- Difficulty: `hard`
- Subtype: `Convex piecewise-linear DP with bounded movement and one-sided hinge penalties`
- Status: `solved`
- Solution file: [snuketoon.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/slope-trick/snuketoon.cpp)

## Why Practice This

This is the cleanest in-repo flagship for the exact slope-trick route.

The DP state is:

- one convex function of the final coordinate
- widened by movement over time
- then hit by one one-sided damage term

So the lesson is not "some weird AtCoder trick."

It is:

- define `f_i(x)` as a convex function
- map movement to `shift_min`
- map each shot to one hinge penalty
- maintain only breakpoints and the current minimum

## Recognition Cue

Reach for slope trick when:

- the answer is "best total cost if I end at position `x`"
- the position line is one-dimensional
- every new event adds a penalty like `max(0, X-x)` or `max(0, x-X)`
- movement over time becomes `min_{|y-x|<=d} f(y)`

The strongest smell here is:

- "my DP state is a whole convex function, but every update is local and structured"

## Problem-Specific Transformation

Let:

$$
f_i(x) = \text{minimum total damage after the first } i \text{ shots, standing at } x \text{ at time } T_i.
$$

Initially:

$$
f_0(0) = 0, \qquad f_0(x) = +\infty \text{ for } x \neq 0.
$$

In practice, we encode this exact starting point by seeding enough copies of breakpoint `0` into both heaps before processing the shots.

Now consider the `i`-th shot.

If `dt = T_i - T_{i-1}`, then Snuke may move by at most `dt`, so:

$$
f(x) \leftarrow \min_{|y-x| \le dt} f(y).
$$

This is exactly the slope-trick operation:

```text
shift_min(-dt, +dt)
```

Then the shot adds a one-sided damage term:

- if `D_i = 0`, damage is `max(0, X_i - x)`
- if `D_i = 1`, damage is `max(0, x - X_i)`

So the full update is:

- widen the minimizer interval by movement
- add one hinge penalty

That is the exact first route for slope trick in this repo.

## Exact Slope-Trick Route

Maintain one `SlopeTrick` structure with:

- `min_f`
- one left max-heap
- one right min-heap
- lazy offsets for both heaps

Before processing the shots, seed the hard start-at-zero state:

```text
seed_argmin_point(0, N + 10)
```

Each update can consume only `O(1)` breakpoint copies, so `N + 10` sentinel copies are enough for the whole run.

For each shot:

1. `expand_argmin_by(T_i - T_{i-1})`
2. if `D_i = 0`, call `add_a_minus_x(X_i)`
3. else call `add_x_minus_a(X_i)`

At the end, the answer is:

```text
min_f
```

## Why The Optimization Fits

This note is not about reconstructing the full DP table over all positions.

It is about recognizing that:

- the DP state stays convex
- the only updates are hinge additions and bounded shifts
- the minimum can therefore be maintained by the standard two-heap slope-trick structure

That is enough to route safely to the exact starter.

## Complexity

Each shot performs:

- one lazy interval expansion in `O(1)`
- one heap-based hinge update in `O(log N)`

So total complexity is:

$$
O(N \log N)
$$

with `O(N)` extra memory.

## Main Traps

- swapping the meaning of `D_i = 0` and `D_i = 1`
- forgetting that movement happens before the current shot penalty is applied
- using `shift_min(dt, dt)` instead of `shift_min(-dt, dt)`
- trying to rebuild the whole function, when only the minimum matters

## Reopen Path

- Topic page: [Slope Trick](../../../../topics/dp/slope-trick/README.md)
- Practice ladder: [Slope Trick ladder](README.md)
- Starter template: [`slope-trick-basic.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/slope-trick-basic.cpp)
- Notebook refresher: [Slope Trick hot sheet](../../../../notebook/slope-trick-hot-sheet.md)
- Compare points: [AtCoder ABC127 F - Absolute Minima](https://atcoder.jp/contests/abc127/tasks/abc127_f), [Convex Hull Trick / Li Chao Tree](../../../../topics/dp/cht-li-chao/README.md)

## Solution

- Code: [snuketoon.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/slope-trick/snuketoon.cpp)
