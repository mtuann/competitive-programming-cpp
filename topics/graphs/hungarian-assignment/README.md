# Hungarian / Assignment Problem

This lane is for the exact moment a pairing task stops being about **how many pairs** and starts being about:

- one worker per job
- one job per worker
- one dense cost matrix
- minimum total cost among all perfect assignments

The repo's exact first route for this family is:

- starter -> [hungarian-assignment.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hungarian-assignment.cpp)
- flagship note -> [Task Assignment](../../../practice/ladders/graphs/hungarian-assignment/taskassignment.md)
- compare point -> [Matching](../matching/README.md)
- compare point -> [Min-Cost Flow](../min-cost-flow/README.md)

This lane intentionally teaches the **square, dense, contest-useful Hungarian route first**. It does not try to start from arbitrary sparse weighted matchings or richer capacity models.

## At A Glance

- **Use when:** there are `n` left objects and `n` right objects, each must be used exactly once, and the objective is minimum total assignment cost
- **Core worldview:** keep dual row/column potentials so reduced costs stay nonnegative, then grow a perfect matching through zero-slack edges
- **Main tools:** assignment matrix, potentials `u / v`, reduced slack, and one `O(n^3)` primal-dual loop
- **Typical complexity:** `O(n^3)` for an `n x n` matrix
- **Main trap:** forcing a plain cardinality matcher onto a weighted assignment problem just because the story still sounds bipartite

Strong contest signals:

- "assign each worker to exactly one job"
- "there are `n` tasks and `n` employees"
- "minimize the total cost of a perfect assignment"
- "the input is already a square cost matrix"
- "return both the optimum cost and one assignment"

Strong anti-cues:

- the objective is only maximum number of pairs -> [Matching](../matching/README.md)
- the objective is stability under strict preferences, not additive cost -> [Stable Marriage](../stable-marriage/README.md)
- capacities larger than `1` or extra source/sink routing structure matter -> [Maximum Flow](../flow/README.md) or [Min-Cost Flow](../min-cost-flow/README.md)
- the graph is sparse / partial and you naturally think in edges with missing feasibility -> [Min-Cost Flow](../min-cost-flow/README.md) is often the cleaner first reduction
- the graph is not bipartite -> this lane is over; switch to [Edmonds Blossom / General Matching](../general-matching/README.md)

## Prerequisites

- [Matching](../matching/README.md), because you should already trust one-to-one pairing structure
- [Min-Cost Flow](../min-cost-flow/README.md) as the best compare route when the assignment story grows extra capacities or richer transport constraints
- [Optimization And Duality](../../advanced/optimization-and-duality/README.md) at the level of being comfortable with the idea that dual potentials can certify optimality

Helpful compare points:

- [Matching](../matching/README.md): use this first when the objective is still cardinality
- [Stable Marriage](../stable-marriage/README.md): use this when the story is two-sided preferences with a stability objective instead of a cost objective
- [Min-Cost Flow](../min-cost-flow/README.md): use this when assignment is only one part of a bigger costed flow network
- [Maximum Flow](../flow/README.md): use this when capacities dominate and costs do not

## Problem Model And Notation

Given an `n x n` cost matrix `A`, we want a permutation `p` minimizing:

$$
\sum_{i=0}^{n-1} A[i][p(i)].
$$

Equivalent statement:

- left side = workers / rows
- right side = jobs / columns
- edge `(i, j)` means assign row `i` to column `j`
- every row and every column must appear exactly once

This is the **minimum-cost perfect matching** problem in a complete bipartite graph.

The dual potentials view uses arrays:

$$
u[i],\ v[j]
$$

such that:

$$
u[i] + v[j] \le A[i][j].
$$

Define the reduced slack:

$$
s(i,j) = A[i][j] - u[i] - v[j].
$$

Then:

- `s(i, j) >= 0` on every edge
- edges with `s(i, j) = 0` are **tight**
- the matching is grown only through this tight-edge structure

## From Brute Force To The Right Idea

### Brute Force

Enumerate all permutations of columns.

That is:

$$
O(n!)
$$

and dies immediately.

### The First Compression

This is not a generic graph problem first. It is a **matrix assignment** problem:

- one pick in every row
- one pick in every column
- total cost matters

So the right state is not "which path did I route?" but:

- which columns are already claimed
- what dual potentials currently certify
- how far one unmatched row is from a new tight augmenting step

### The Second Compression

Instead of searching directly in original costs, Hungarian maintains potentials so every reduced cost is nonnegative.

That means:

- zero-slack edges are the current candidate equality graph
- one Dijkstra-like / shortest-slack growth step from an unmatched row finds how to extend the matching cheapest
- when no tight augmenting step exists yet, shift potentials by the smallest uncovered slack

This is the assignment analogue of "preserve a clean residual search space and only move when one local improvement is justified."

## Core Invariant And Why It Works

The repo starter keeps three invariants.

### 1. Potentials Are Always Feasible

At all times:

$$
u[i] + v[j] \le A[i][j].
$$

So every reduced slack is nonnegative.

This is why the algorithm never breaks optimality structure while it grows the matching.

### 2. Only Tight Edges Can Join The Current Equality Matching

If:

$$
A[i][j] - u[i] - v[j] = 0,
$$

then `(i, j)` is tight.

The Hungarian search only augments through these tight edges.
That is the primal-dual heart of the method:

- the dual potentials define which edges are currently legal equality edges
- the primal matching grows inside that equality graph

### 3. Potential Shifts Create New Tight Edges Without Breaking Old Feasibility

When one unmatched row cannot yet reach a free column through tight edges, the algorithm computes the smallest uncovered slack `delta` and shifts:

- matched rows / visited columns potentials one way
- unvisited columns' tentative distances the other way

The effect is:

- all reduced slacks stay nonnegative
- at least one new edge becomes tight
- the search frontier strictly advances

That is why the whole method finishes in `O(n^3)` instead of flailing through arbitrary rematch attempts.

## Complexity And Tradeoffs

The standard dense Hungarian implementation runs in:

$$
O(n^3)
$$

for an `n x n` matrix.

Rule of thumb:

- dense square cost matrix with exact one-to-one assignment -> Hungarian is the natural first tool
- sparse edge set, capacities, or broader transport model -> [Min-Cost Flow](../min-cost-flow/README.md) is often easier to reason about

## Worked Examples

### Example 1: CSES Task Assignment

This repo's flagship note:

- [Task Assignment](../../../practice/ladders/graphs/hungarian-assignment/taskassignment.md)

The statement is already the assignment problem with almost no disguise:

- `n` employees
- `n` tasks
- full `n x n` cost matrix
- output optimum cost and one assignment

That is the cleanest first benchmark for this lane.

### Example 2: Maximize Instead Of Minimize

If the statement asks for a **maximum-profit** perfect assignment on a square matrix, the standard contest conversion is:

$$
\text{maximize } w(i,j)
\quad\Longleftrightarrow\quad
\text{minimize } -w(i,j).
$$

This is still the same lane, but it is a compare point rather than the starter contract.

### Example 3: Rectangular Variant As A Boundary

If there are `n` workers and `m` jobs with `n != m`, one classical route is padding to a square matrix with dummy rows or columns.

That is a valid extension, but it is intentionally **not** the first-route snippet in this repo.

## Implementation Notes

### 1. The Starter Is Narrow On Purpose

The starter contract is:

- one square matrix
- minimum total cost
- perfect assignment
- return total cost plus `row -> column` matching

That keeps the lane honest and retrieval fast.

### 2. Costs May Be Negated For Max Problems

That is safe as a modeling trick, but remember:

- keep the arithmetic in `long long`
- think about overflow if raw weights are large

### 3. Sparse Graphs Are A Modeling Fork

If many assignments are forbidden, you can:

- encode them as huge cost / infinity
- or model the problem as [Min-Cost Flow](../min-cost-flow/README.md)

The second route is often clearer once sparsity and extra capacities matter.

### 4. This Lane Is Not Blossom

Hungarian is for weighted **bipartite** assignment.

If odd cycles and general-graph weighted matching matter, that is a different world.

## References And Repo Anchors

Research sweep refreshed on `2026-04-25`.

Reference:

- [cp-algorithms: Hungarian algorithm](https://cp-algorithms.com/graph/hungarian-algorithm.html)
- [KACTL WeightedMatching / Hungarian](https://pages.cs.wisc.edu/~dieter/ICPC/21-22/kactl.pdf)
- [OI Wiki: weighted bipartite matching](https://en.oi-wiki.org/graph/graph-matching/bigraph-weight-match/)

Practice:

- [CSES - Task Assignment](https://cses.fi/problemset/task/2129)

Repo anchors:

- practice ladder -> [Hungarian / Assignment Problem ladder](../../../practice/ladders/graphs/hungarian-assignment/README.md)
- flagship note -> [Task Assignment](../../../practice/ladders/graphs/hungarian-assignment/taskassignment.md)
- starter template -> [hungarian-assignment.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hungarian-assignment.cpp)
- notebook refresher -> [Hungarian hot sheet](../../../notebook/hungarian-hot-sheet.md)
- compare point -> [Matching](../matching/README.md)
- compare point -> [Min-Cost Flow](../min-cost-flow/README.md)

## Related Topics

- [Matching](../matching/README.md)
- [Min-Cost Flow](../min-cost-flow/README.md)
- [Optimization And Duality](../../advanced/optimization-and-duality/README.md)
