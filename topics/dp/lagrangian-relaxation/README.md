# Lagrangian Relaxation / Aliens Trick

This lane is about one very specific optimization pattern:

- the original problem asks for the best value with **exactly** `K` choices / segments / operations
- the direct DP over that count is too expensive
- but if each choice costs a penalty `lambda`, the relaxed problem becomes easy

Then we:

1. solve the relaxed problem for a fixed `lambda`
2. also track how many choices the relaxed optimum uses
3. binary search `lambda`
4. recover the answer for the exact count `K`

This is the exact contest meaning of:

- `Alien DP`
- `Aliens Trick`
- `wqs binary search`
- `Lagrangian relaxation`

This page is not about generic Lagrange multipliers in continuous optimization.

It is about the discrete contest lane that sits next to:

- [DP Foundations](../foundations/README.md)
- [Divide and Conquer DP](../divide-and-conquer-dp/README.md)
- [Knuth Optimization](../knuth-optimization/README.md)
- [Slope Trick](../slope-trick/README.md)

## At A Glance

- **Use when:** the statement wants the best answer with exactly `K` picks / segments / operations, and adding one global penalty per pick makes the relaxed DP much cheaper
- **Core worldview:** replace "use exactly `K`" by "each use costs `lambda`", solve that penalized DP, and search for the slope where the optimal count crosses `K`
- **Main tools:** penalized objective, pair states `(penalized_value, count)`, tie-breaking by count, integer binary search on `lambda`
- **Typical complexity:** `solve_relaxed(lambda)` multiplied by `O(log V)` search over the penalty range
- **Main trap:** using the trick before proving or importing the needed monotonicity / concavity, or tie-breaking the count in the wrong direction

Strong contest signals:

- "choose exactly `K` segments / facilities / picks"
- the direct DP over `K` is too slow, but the unconstrained or penalized version is linear / near-linear
- official editorials mention `Alien DP`, `wqs binary search`, `concavity of f(K)`, or `Lagrangian relaxation`

Strong anti-cues:

- `K` is small enough that ordinary `O(NK)` DP is already fine
- the expensive part is still one split-point row -> [Divide and Conquer DP](../divide-and-conquer-dp/README.md)
- the state is one convex function over position/value -> [Slope Trick](../slope-trick/README.md)
- the transition is affine and previous states become lines -> [Convex Hull Trick / Li Chao Tree](../cht-li-chao/README.md)

## Prerequisites

- [DP Foundations](../foundations/README.md)
- [Reasoning](../../foundations/reasoning/README.md) for "relaxed solver first" intuition and exchange-style proof habits

Helpful neighboring topics:

- [Divide and Conquer DP](../divide-and-conquer-dp/README.md)
- [Knuth Optimization](../knuth-optimization/README.md)
- [Slope Trick](../slope-trick/README.md) as another "optimize the DP family, not the raw table" lane

## Problem Model And Notation

Let:

$$
f(k) = \text{best original objective using exactly } k \text{ choices}.
$$

The exact first route in this repo is a maximization problem.

For a fixed integer penalty `lambda`, define the relaxed objective:

$$
g_{\lambda}(x) = \text{original value}(x) - \lambda \cdot \text{count}(x).
$$

The relaxed solver returns:

- the maximum penalized value
- and, among all optima with that value, the **largest** count

So the relaxed answer is one pair:

$$
(\text{best penalized value},\ \text{count at that optimum})
$$

That tie-break direction is part of the algorithm, not a cosmetic choice.

## Why Binary Search On `lambda` Works

When we increase `lambda`, every extra choice becomes less attractive.

So the optimal count in the relaxed problem moves downward.

The exact math language is:

- `f(k)` behaves like a concave discrete function in many contest lanes where Aliens trick applies
- `lambda` acts like the slope we use to probe that concave envelope

In practice, the usable contest rule is:

- if `count(lambda) >= K`, the penalty is still cheap enough to allow at least `K` choices
- if `count(lambda) < K`, the penalty is too expensive

So we binary search the **largest** `lambda` such that the relaxed optimum still uses at least `K` choices.

Then:

$$
f(K) = \text{best penalized value at } \lambda + \lambda \cdot K.
$$

## Core Invariants

## 1. The Relaxed Solver Must Return `(value, count)`

A scalar DP value is not enough.

You must also know how many choices that relaxed optimum used.

## 2. Tie-Breaking Controls Boundary Correctness

For a maximization route with penalty subtraction:

- maximize penalized value
- on equal penalized value, prefer the **larger** count

This is exactly what keeps the count monotone and makes flat slopes recoverable.

Without the right tie-break, binary search may land on the wrong side of a plateau.

## 3. Search On Integers When The Slopes Are Integral

Do not default to floating-point binary search.

If the objective and marginal slopes are integral, integer search is safer and exact.

This is especially important when the answer scale is large.

## 4. Recover The Original Objective At The End

The relaxed solver returns:

$$
\text{original} - \lambda \cdot \text{count}.
$$

So after finding the final penalty:

```text
answer = penalized_value + lambda * K
```

Forgetting this last step is the most common implementation bug.

## Worked Example: Red and Blue Lamps

In [Red and Blue Lamps](../../../practice/ladders/dp/lagrangian-relaxation/redandbluelamps.md), after the standard transformation:

- choose exactly `R` positions
- no two chosen positions are adjacent
- each chosen position `i` contributes weight `B_i`

Let:

$$
f(k) = \text{maximum total weight using exactly } k \text{ non-adjacent picks}.
$$

For fixed penalty `lambda`, the relaxed problem is:

$$
\max \left(\sum B_i - \lambda \cdot \#\text{picks}\right).
$$

That relaxed problem is just a linear DP on a path:

- skip this position
- or take it and force the previous one to be skipped

So the expensive exact-`R` constraint disappears into:

- one linear DP
- one count field
- one binary search

This is the cleanest in-repo first route for Aliens trick.

## Variant Chooser

### Use Plain `O(NK)` DP When

- `K` is small enough
- or the direct table already fits comfortably

### Use Lagrangian / Aliens Trick When

- exact `K` is the only expensive dimension
- the relaxed problem becomes much cheaper
- and you can trust the needed monotonicity / concavity behavior

### Use Divide and Conquer DP Instead When

- the real optimized object is still one partition-DP row
- and the exact `K` dimension is solved directly by row transitions

### Use Slope Trick Instead When

- the state is a convex function over coordinate/value
- not an exact-count family `f(k)`

## Implementation Notes

- represent the relaxed DP state as `(value, count)`
- for maximization with penalized subtraction, compare by:
  1. larger `value`
  2. on tie, larger `count`
- binary search the largest `lambda` with `count >= K`
- recover by adding `lambda * K` back
- if the penalty range is wide, use `__int128` internally for penalized values

## Common Failure Modes

- tie-breaking by the smaller count in a maximization route
- binary-searching decimals when the real slope is integral
- forgetting to add back `lambda * K`
- using Aliens trick with no evidence that the count moves monotonically
- opening this lane when plain `O(NK)` DP was already enough

## Reopen Paths

- exact starter and quick refresher -> [Aliens Trick hot sheet](../../../notebook/aliens-trick-hot-sheet.md)
- exact flagship anchor -> [Red and Blue Lamps](../../../practice/ladders/dp/lagrangian-relaxation/redandbluelamps.md)
- compare direct-row optimization -> [Divide and Conquer DP](../divide-and-conquer-dp/README.md)
- broader router -> [Dynamic Programming](../README.md)
