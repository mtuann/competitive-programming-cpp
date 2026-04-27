# Broken Profile / Plug DP

This lane is about DP over a **small grid frontier**.

The exact first route in this repo is the standard broken-profile pattern:

- one grid dimension is small
- you sweep the other dimension
- a bitmask describes which cells on the current frontier are already occupied

The title also mentions **plug DP** because that is the stronger follow-up family where the frontier no longer stores just `filled / empty`.

Instead, it may store:

- border-connectivity labels
- path endpoints
- loop structure

That follow-up is real and important, but it is **not** the first starter route here.

This page teaches the contest route that matters first:

1. choose the smaller dimension as the masked frontier
2. define `dp[col][mask]` or rolled `dp[mask]`
3. generate legal `next_mask` states by filling the current column row-by-row

## At A Glance

Reach for broken profile when:

- the task is on a 2D grid
- one dimension is much smaller than the other
- local adjacency is what matters
- the frontier between processed and unprocessed cells is enough to summarize the future

Strong contest triggers:

- "count tilings of an `n x m` board"
- "`n <= 10`, `m <= 1000`" or the other way around
- the board is processed column-by-column or row-by-row
- each local placement only touches nearby cells

Strong anti-cues:

- the state is really a subset of items, not a grid frontier -> [Bitmask DP](../bitmask-dp/README.md)
- both dimensions are large enough that even `2^min(n, m)` is hopeless
- transitions are over partitions / prefixes, not local grid placement
- the frontier must remember **connectivity labels**, not just occupancy bits

What success looks like after studying this page:

- you can explain what the frontier mask means in plain language
- you know why the smaller grid dimension should usually be the masked one
- you can generate `next_mask` by a DFS over rows of one column
- you can say clearly when simple occupancy-mask broken profile stops being enough and full plug DP begins

## Prerequisites

- [DP Foundations](../foundations/README.md)
- [Bitmask DP](../bitmask-dp/README.md)

Helpful neighboring topics:

- [Interval DP](../interval-dp/README.md) for another "structured state" family
- [Tree DP](../tree-dp/README.md) for a different local-composition worldview

## Problem Model

The exact first route here is:

- tile a rectangular grid with dominoes
- count the valid full tilings modulo `1e9+7`

Let:

- `h = min(n, m)` be the masked frontier height
- `w = max(n, m)` be the sweep length

We process one column at a time.

The central state is:

```text
dp[col][mask]
```

or its rolled version `dp[mask]`, where:

- `col` columns have already been completed
- `mask` says which cells of the current column are already occupied before we start filling it

In the repo starter, a bit `1` means:

```text
this cell is already occupied because a horizontal domino from the previous column enters here
```

That convention is the whole lane.

Everything else is just careful generation of the next frontier.

## Transition Playground

<div class="visual-card" data-broken-profile-visualizer>
  <p class="visual-caption">
    Explore how one `cur_mask` generates legal `next_mask` values for the domino-tiling starter. Here a bit `1` means
    "this row of the current column is already occupied before we start filling it."
  </p>
  <div class="visual-controls">
    <label>
      Current mask
      <select data-role="mask-select"></select>
    </label>
    <label>
      Legal branch
      <select data-role="branch-select"></select>
    </label>
    <button type="button" data-role="prev-step">Previous step</button>
    <button type="button" data-role="next-step">Next step</button>
    <button type="button" data-role="reset">Reset branch</button>
  </div>
  <div class="visual-grid">
    <div class="visual-panel">
      <div class="visual-surface" data-role="canvas"></div>
    </div>
    <div class="visual-panel">
      <h4>What to watch</h4>
      <div class="visual-stats">
        <div class="visual-stat">
          <strong>Invariant</strong>
          <div data-role="invariant"></div>
        </div>
        <div class="visual-stat">
          <strong>Current frontier</strong>
          <code data-role="mask"></code>
        </div>
        <div class="visual-stat">
          <strong>Chosen completion</strong>
          <code data-role="branch"></code>
        </div>
        <div class="visual-stat">
          <strong>Accumulated next frontier</strong>
          <code data-role="partial"></code>
        </div>
        <div class="visual-stat">
          <strong>Latest step</strong>
          <code data-role="result"></code>
        </div>
        <div class="visual-stat">
          <strong>Branch steps</strong>
          <ul data-role="actions"></ul>
        </div>
      </div>
      <p class="visual-note" data-role="note"></p>
    </div>
  </div>
</div>

### Visual Reading Guide

What to notice:

- the scan pointer moves top to bottom, and every row above it is already fully resolved for the current column
- a horizontal domino does not just fill the current cell; it also writes a `1` bit into `next_mask`, because that row will already be occupied in the next column

Why it matters:

- this is the shortest route from the abstract sentence "generate next masks by DFS" to the exact recursion the starter template uses
- it also makes the biggest beginner trap visible: `cur_mask` describes occupancy entering the current column, while `next_mask` describes occupancy exported to the next one

Code bridge:

- each branch here is exactly one path through `generate_next_masks(row, height, cur_mask, next_mask, ...)`
- `skip` matches the `if (cur_mask & (1 << row))` branch, `horizontal` matches `next_mask | (1 << row)`, and `vertical` matches the `row + 2` recursion

Boundary:

- this widget teaches the occupancy-mask starter only; it does not cover full plug DP where the frontier must store connectivity labels
- the real DP still multiplies this one-column transition generator across many columns and sums all branches into `dp_next[next_mask]`

## From Brute Force To The Right Idea

### Brute Force

For domino tilings, the naive search is:

- try every legal local placement recursively
- branch at every empty cell

This becomes enormous quickly.

Even though each local move is simple, the total number of partial fillings explodes.

### Structural Observation

When you sweep column-by-column, the future does **not** care about the exact internal history of the finished columns.

It only cares about:

- which cells in the current column are already blocked from the left

That frontier is small when one grid dimension is small, so the whole remaining future can be summarized by one mask.

This is why broken profile is a DP topic, not just a search trick.

## Core Invariant

For the domino-tiling route:

- `mask` describes cells in the current column that are already occupied before processing this column
- while generating one column, you scan rows from top to bottom
- at each row, only local placements touching the current cell are legal

The row-generation DFS has three relevant cases:

1. current row bit is already `1`
- the cell is already filled
- move to the next row

2. current cell is empty and you place a **vertical domino**
- this consumes two cells in the same current column
- so no bit is added to `next_mask`

3. current cell is empty and you place a **horizontal domino**
- this uses the current cell plus the matching cell in the next column
- so you set that row bit inside `next_mask`

When all rows are processed:

- one full legal completion of the current column contributes to `dp_next[next_mask]`

That is the invariant the starter exposes.

## Why This Is Still Only The First Half Of The Family

Simple broken profile uses frontier bits like:

- filled / empty
- blocked / open
- maybe a tiny finite local state

Full **plug DP** is stronger.

There the frontier may encode:

- which open path endpoints are connected together
- how partial components are paired
- whether adding a local piece opens, merges, or closes a connection

So plug DP is the natural follow-up once occupancy masks alone are no longer expressive enough.

This repo's first starter does **not** attempt that.

It deliberately teaches the clean occupancy-mask route first.

## Complexity

For the exact first route in this repo:

- states per column: `2^h`
- transition generation per state: row DFS over height `h`
- total: `O(w * 2^h * transitions)`

With `h <= 10`, this is very manageable.

That is exactly why problems like CSES `Counting Tilings` are designed this way.

## Variant Chooser

### Use Plain Broken Profile When

- the frontier is only a small occupancy-style mask
- local placements only care about nearby cells
- one dimension is small enough for `2^h`

### Escalate To Plug DP When

- the frontier must remember connectivity, not just occupancy
- paths / loops / pairings across the cut matter
- labels on frontier edges or cells become necessary

### Stay In Bitmask DP Instead When

- the mask describes items / vertices / categories
- not a spatial frontier

## Main Traps

- forgetting to rotate the grid so the smaller dimension becomes the masked frontier
- mixing what a `1` bit means between current and next frontier
- trying to teach full plug DP before simple occupancy-mask profile DP is comfortable
- assuming every grid problem with a small dimension is automatically broken profile

## Exact First Route In This Repo

Use the starter when the signal is:

- domino tilings or close local-fill variants
- one dimension is small
- occupancy of the next frontier is enough

Repo route:

- hot sheet -> [Broken Profile hot sheet](../../../notebook/broken-profile-hot-sheet.md)
- starter -> [broken-profile-domino-tiling.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/broken-profile-domino-tiling.cpp)
- flagship note -> [Counting Tilings](../../../practice/ladders/dp/broken-profile/countingtilings.md)

## Compare Points

- [Bitmask DP](../bitmask-dp/README.md) when the mask is a subset of items, not a frontier
- [Knuth Optimization](../knuth-optimization/README.md) and [Convex Hull Trick / Li Chao Tree](../cht-li-chao/README.md) when the state is prefix/partition/line based rather than local-grid frontier based
- full plug DP as the follow-up when connectivity labels must live on the frontier

## Go Deeper

- Reference: [CP-Algorithms - Dynamic Programming on Broken Profile](https://cp-algorithms.com/dynamic_programming/profile-dynamics.html)
- Reference: [USACO Guide - DP on Broken Profile](https://usaco.guide/adv/dp-broken-profile)
- Reference: [OI Wiki - Plug DP](https://en.oi-wiki.org/dp/plug/)
- Practice: [CSES - Counting Tilings](https://cses.fi/problemset/task/2181/)
