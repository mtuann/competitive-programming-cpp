# Knapsack Family

Knapsack is the DP family where tiny wording changes in the statement completely change the recurrence.

That is why it is such good training.

At first glance, these problems all look like:

- items
- costs or weights
- one resource limit
- maximize value, count ways, or check feasibility

But the real question is:

- can each item be used at most once?
- any number of times?
- only a bounded number of times?
- or at most one from each group?

Once that is clear, the recurrence and the capacity-loop direction become almost forced.

## At A Glance

- **Use when:** the statement is about selecting items under one resource constraint
- **Core worldview:** `dp[capacity]` stores the best or feasible answer for a resource budget, and the update order encodes whether current items may be reused
- **Main tools:** `0/1` knapsack, complete knapsack, bounded knapsack, grouped knapsack, boolean/counting/value variants
- **Typical complexity:** classical pseudo-polynomial `O(nW)` when capacity `W` is moderate
- **Main trap:** using the wrong loop direction and accidentally turning `0/1` into complete knapsack or vice versa

## Problem Model And Notation

We usually have items indexed by `i`.

Each item has:

- weight or cost $w_i$
- value, reward, or contribution $v_i$

There is one capacity limit:

$$
W.
$$

The canonical one-dimensional state is:

$$
dp[j] = \text{best answer for capacity } j.
$$

Depending on the problem, "best answer" may mean:

- maximum value
- feasibility
- number of ways
- minimum cost for achieving something

The shape of the state stays similar; the interpretation changes.

## From Brute Force To The Right Idea

### Brute Force: Enumerate All Subsets Or Multisets

The naive solution is:

- decide independently for every item how many copies to use

This becomes:

- exponential for `0/1` variants
- even worse when multiplicities are allowed

That is too expensive unless the number of items is tiny.

### The First Shift: Capacity Is The Natural DP Axis

Instead of thinking:

- "which exact set of items have I taken?"

we think:

- "what is the best answer achievable under capacity `j`?"

This collapses many different subsets into one summary state.

### The Second Shift: Item Usage Rule Determines Loop Direction

The single biggest lesson in this family is:

- the direction of the capacity loop is part of correctness

If the current item may be used at most once, then while processing that item:

- transitions must read only from the previous layer

If the current item may be reused immediately, then while processing that item:

- transitions are allowed to see states already updated by the same item

That is why loop direction matters.

### The Third Shift: Many Variants Share The Same Skeleton

Once you learn to classify the item-usage rule, many variants become "same DP skeleton, different transition discipline":

- `0/1` knapsack
- subset sum
- complete knapsack
- bounded knapsack
- grouped knapsack

The family is broad, but it is not chaotic.

## Core Invariants And Why They Work

### 1. `0/1` Knapsack

Suppose we process items one by one and define:

$$
dp[j] = \text{best value using processed items with capacity limit } j.
$$

For one item `(w_i, v_i)`, the transition is:

$$
dp[j] = \max(dp[j], dp[j - w_i] + v_i)
$$

for all `j >= w_i`.

The crucial detail is that capacities are scanned **downward**:

```text
for j from W down to w_i
```

Why?

Because then `dp[j - w_i]` still refers to the state before item `i` was used in this iteration.

So item `i` cannot be reused accidentally.

### 2. Complete Knapsack

If an item may be used unlimited times, the recurrence is still:

$$
dp[j] = \max(dp[j], dp[j - w_i] + v_i),
$$

but now capacities are scanned **upward**:

```text
for j from w_i up to W
```

Why?

Because reusing the current item is legal, so reading a state already updated in the same item iteration is exactly what we want.

### 3. Bounded Knapsack

If item `i` has at most `c_i` copies, then neither plain downward nor plain upward looping fully captures the rule.

Common approaches are:

- binary splitting into several `0/1` items
- monotone-queue optimization for stronger settings
- direct bounded transitions when constraints are small

The modeling question is still the same:

- how many copies may one item contribute?

### 4. Grouped / Multiple-Choice Knapsack

If items come in groups and you may choose at most one from each group, then while processing one group:

- transitions for that group must not chain through another choice from the same group

So you usually:

- keep a snapshot of the previous layer
- or build a new layer from the old one

This is the grouped analogue of "do not reuse the current layer illegally."

### 5. Boolean, Counting, And Max-Value Versions Share The State Shape

The family is not only about maximizing values.

You can reinterpret the same capacity axis as:

- `reachable[j]`
- `ways[j]`
- `min_items[j]`

The classification by item-usage rule still matters first.

## Variant Chooser

### Use `0/1` Knapsack When

- each item can be chosen at most once
- the statement says "take or skip"
- every physical object is unique

Canonical examples:

- books, tasks, projects, items, offers

The repo anchor here is:

- [Book Shop](../../../practice/ladders/dp/knapsack-family/bookshop.md)

### Use Subset-Sum Style DP When

- the objective is feasibility rather than value
- the state still depends on one sum or capacity axis

Canonical examples:

- can we make sum `S`?
- which sums are reachable?

This is still usually a `0/1` or complete-knapsack variant under a boolean interpretation.

### Use Complete Knapsack When

- each item type can be reused unlimited times
- the statement is about unlimited coins, rods, packs, or repetitions

The telltale signal is:

- the same item type may appear again immediately in the optimal solution

### Use Bounded Knapsack When

- each item has a limited multiplicity
- neither "once" nor "unlimited" matches the statement

This is the point where implementation choices start to matter more:

- small bounds may allow direct DP
- larger bounds often want binary splitting

### Use Grouped Knapsack When

- items are partitioned into groups
- you may choose at most one from each group

Canonical examples:

- one course per time slot
- one weapon per category
- one option from each project stage

### Switch Away From Capacity DP When

- `W` is too large for `O(nW)`
- but values are small enough for value-based DP
- or bitset optimization fits a feasibility version

The knapsack worldview still applies, but the axis changes.

## Worked Examples

### Example 1: `Book Shop`

The repo anchor here is:

- [Book Shop](../../../practice/ladders/dp/knapsack-family/bookshop.md)

Each book may be bought at most once.

So the state is:

$$
dp[j] = \text{maximum pages with budget } j.
$$

For one book `(price, pages)`, update:

$$
dp[j] = \max(dp[j], dp[j - price] + pages)
$$

for decreasing `j`.

The downward loop is the real content of the solution.

### Example 2: Why Wrong Loop Direction Breaks `0/1`

Suppose one item has:

- weight `3`
- value `5`

and capacity is `6`.

If you iterate upward in a `0/1` problem:

- `dp[3]` may become `5`
- then `dp[6]` may read that freshly updated `dp[3]` and become `10`

That illegally uses the same item twice.

This is the shortest proof that loop direction is not cosmetic.

### Example 3: Complete Knapsack Really Wants Upward Order

Now suppose unlimited copies are allowed.

The same upward behavior becomes correct:

- once `dp[3]` is improved by one copy
- `dp[6]` should indeed be allowed to build on it with another copy

So the exact same code shape flips meaning depending on the item-usage rule.

### Example 4: Grouped Choice

Suppose one group contains three options.

If you update `dp` in place and let one option immediately build on another option from the same group, you accidentally allow selecting two choices from one group.

That is why grouped knapsack often uses:

- a previous layer snapshot
- then all options in the group transition from that snapshot only

### Example 5: Counting Ways Versus Maximizing Value

For coin-style problems, you might store:

$$
ways[j]
$$

instead of best value.

The transition discipline still follows the same family classification:

- `0/1` counting -> downward
- unlimited-counting -> upward

So the recurrence target changes, but the usage logic does not.

## Algorithms And Pseudocode

Repo starter template:

- [knapsack-01.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/knapsack-01.cpp)

### `0/1` Knapsack

```text
initialize dp[0..W]

for each item (w, v):
    for j from W down to w:
        dp[j] = max(dp[j], dp[j - w] + v)
```

### Complete Knapsack

```text
initialize dp[0..W]

for each item (w, v):
    for j from w up to W:
        dp[j] = max(dp[j], dp[j - w] + v)
```

### Grouped Knapsack

```text
initialize dp[0..W]

for each group G:
    old = dp
    for each item (w, v) in G:
        for j from w to W:
            dp[j] = max(dp[j], old[j - w] + v)
```

The exact loop direction may vary by implementation style, but the logical rule does not:

- all choices in one group must transition from the layer before the group

### Binary Splitting For Bounded Knapsack

If an item has count `c`, split it into bundles:

$$
1, 2, 4, \dots
$$

plus one remainder bundle if needed.

Then run `0/1` knapsack on those bundles.

This turns a bounded-multiplicity item into a logarithmic number of `0/1` items.

## Implementation Notes

### 1. Write The 2D Meaning First

Before compressing to 1D, write the conceptual layer meaning:

```text
after processing the first i items / groups,
what does dp[j] mean?
```

Compression is easy only after the dependency direction is clear.

### 2. Loop Direction Is A Proof Obligation

Do not memorize:

- downward for `0/1`
- upward for complete

as a chant.

Always explain:

- what state `dp[j - w]` is allowed to represent during this iteration

That explanation is the proof.

### 3. Capacity DP Is Pseudo-Polynomial

The standard complexity:

$$
O(nW)
$$

depends on the numeric size of `W`, not only the input length in bits.

That is why some knapsack problems need:

- value-based DP
- bitsets
- approximation

instead of plain capacity DP.

### 4. `dp[j]` Usually Means "At Most `j`"

In many contest implementations:

$$
dp[j]
$$

means the best answer using capacity **at most** `j`, not exactly `j`.

That is why printing `dp[W]` is usually right even if the optimal solution does not fill capacity exactly.

Be explicit about this interpretation.

### 5. Counting Versions Need Overflow Or Mod Discipline

If the task counts ways, then:

- use modular arithmetic if required
- or a larger numeric type if exact counts are small enough

Do not casually reuse max-value code patterns in counting DPs.

### 6. Grouped Constraints Change The Whole Layer Contract

This is one of the most common family-level mistakes.

Grouped knapsack is not:

- ordinary `0/1` with prettier wording

It changes the transition discipline because one group must not chain through itself.

### 7. Bound Size Often Decides The Bounded-Knapsack Technique

For bounded multiplicity, always check:

- how large are the counts?

Small counts may allow direct transitions.

Large counts often want binary splitting or stronger optimizations.

## Practice Archetypes

The most common knapsack-shaped tasks are:

- **take-or-skip items under one budget**
- **subset-sum feasibility**
- **unlimited item reuse**
- **bounded multiplicity**
- **choose at most one per group**

Strong contest smells include:

- capacity / weight / cost / budget
- each item has one local resource usage
- global objective under one constrained resource
- the wording "at most once", "unlimited", or "at most `c_i` copies"

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Course:

- [MIT 6.006 Recitation 21: Dynamic Programming, Knapsack Problem](https://live.ocw.mit.edu/courses/6-006-introduction-to-algorithms-fall-2011/resources/recitation-21-dynamic-programming-knapsack-problem/)
- [University of Washington CSE 421: Dynamic Programming II, The Knapsack Problem](https://courses.cs.washington.edu/courses/cse421/25sp/)
- [Colorado State: Knapsack Problem and Dynamic Programming](https://www.cs.colostate.edu/~cs475/f17/Lectures/Lec04Knapsack.pdf)

Reference:

- [CP-Algorithms: Knapsack Problem](https://cp-algorithms.com/dynamic_programming/knapsack.html)
- [OI Wiki: Knapsack DP](https://en.oi-wiki.org/dp/knapsack/)
- [USACO Guide: Knapsack DP](https://usaco.guide/gold/knapsack?lang=cpp)

Practice:

- [AtCoder Educational DP Contest](https://atcoder.jp/contests/dp)

Repo anchors:

- practice ladder: [Knapsack Family ladder](../../../practice/ladders/dp/knapsack-family/README.md)
- practice note: [Book Shop](../../../practice/ladders/dp/knapsack-family/bookshop.md)
- starter template: [knapsack-01.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/knapsack-01.cpp)
- notebook refresher: [DP cheatsheet](../../../notebook/dp-cheatsheet.md)
- adjacent topic: [DP Foundations](../foundations/README.md)
- adjacent topic: [Bitmask DP](../bitmask-dp/README.md)

## Related Topics

- [DP Foundations](../foundations/README.md)
- [Bitmask DP](../bitmask-dp/README.md)
- [Tree DP](../tree-dp/README.md)
- [Modular Arithmetic](../../math/modular-arithmetic/README.md)
