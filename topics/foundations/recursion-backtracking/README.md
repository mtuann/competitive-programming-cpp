# Recursion And Backtracking

Recursion and backtracking are the bridge between "generate everything" and
"search only the states that still have a chance to work."

This page is about learning that bridge cleanly before the search tree grows
into:

- bitmask DP
- meet-in-the-middle
- branch-and-bound
- or full complexity/hardness triage

## At A Glance

- **Use when:** the solution is an explicit search over choices, permutations, placements, subsets, or partial assignments
- **Core worldview:** define one state, one next-choice rule, and one prune rule before coding the recursive tree
- **Main tools:** recursive state definition, base cases, undo/redo updates, pruning, branch ordering
- **Typical complexity:** often exponential in the search depth, so pruning and state choice matter more than constant factors
- **Main trap:** writing recursion first and only later discovering what the state is supposed to mean

Strong contest signals:

- "try all placements / choices / assignments"
- the judge only needs one valid witness
- the state is small enough that a depth-first search tree is realistic
- pruning conditions are natural and cheap to test

Strong anti-cues:

- the true problem is already a clean DP, graph, or greedy model
- `n` is large enough that plain exponential branching is hopeless
- the search tree has no meaningful prune rule and no tiny side parameter

## Prerequisites

- [Reasoning And Implementation Discipline](../reasoning/README.md)
- [Complexity And Invariants ladder](../../../practice/ladders/foundations/complexity-and-invariants/README.md)

Helpful neighboring topics:

- [Bitmask DP](../../dp/bitmask-dp/README.md)
- [Knapsack Family](../../dp/knapsack-family/README.md)
- [Meet-In-The-Middle](../../advanced/meet-in-the-middle/README.md)
- [Complexity And Hardness](../../advanced/complexity-and-hardness/README.md)
- [Constructive](../../advanced/constructive/README.md)

## Problem Model And Notation

The clean recursive model has four pieces:

1. `state`
2. `choices(state)`
3. `base case`
4. `prune(state)`

Good recursive code is just these four pieces written honestly.

The recursive tree should answer:

- what information is fixed already?
- what remains undecided?
- how do we move to the next decision?
- when can we stop early?

## From Brute Force To The Right Idea

### Brute Force: Enumerate Without Structure

A beginner often writes:

- several nested loops when depth is tiny
- or a DFS that mutates global arrays without a clear invariant

That works for toy cases, but it breaks quickly when:

- the branching factor changes per state
- some branches are impossible early
- you need to undo partial work cleanly

### The First Shift: The Recursion Tree Is The Real Object

The question is not "can I recurse here?"

It is:

- what node of the search tree am I standing at?
- what do its children mean?

Once that is clear, recursion stops feeling magical and starts feeling like a
state machine with a call stack.

### The Second Shift: Pruning Is The Whole Skill

Raw backtracking is usually too slow.

The route becomes viable only after you identify:

- illegal partial states
- dominated branches
- symmetry you can quotient away
- bounds showing a branch cannot beat the current best

This is why the page belongs beside complexity triage, not only beside
"beginner recursion syntax."

## Core Invariants And Why They Work

### 1. Every Recursive Call Must Mean One Precise Partial Solution

The strongest invariant is:

- one call frame corresponds to one valid partial state

If the same call sometimes means "first `i` positions fixed" and sometimes
"some positions fixed in arbitrary order", bugs become inevitable.

### 2. Base Cases Must Be Semantic, Not Just Depth Checks

Do not stop only because:

- `idx == n`

Stop because:

- all required decisions are fixed
- and the partial state is now a complete legal answer

That wording keeps the code aligned with the model.

### 3. Undo Is Part Of Correctness

Backtracking code often uses shared mutable state.

Then the invariant is:

- after returning from one branch, the caller's state must be restored exactly

That is why careful `apply -> recurse -> undo` structure matters.

### 4. Complexity Depends On The Search Tree You Actually Leave Alive

The meaningful complexity is not "number of recursive calls in the worst fantasy
tree."

It is:

- the branching factor after pruning
- the depth
- and the cost per node

This is the boundary where you should escalate to:

- [Bitmask DP](../../dp/bitmask-dp/README.md) if overlapping subproblems dominate
- [Meet-In-The-Middle](../../advanced/meet-in-the-middle/README.md) if subset search hits `n ≈ 40`
- [Complexity And Hardness](../../advanced/complexity-and-hardness/README.md) if the model is still too large

## Variant Chooser

### Use Plain Recursive Generation When

- the search space is small and you only need enumeration

### Use Backtracking With Pruning When

- legality or score bounds can kill branches early

### Use Bitmask DP Instead When

- many branches reach the same subproblem state

### Use Meet-In-The-Middle Instead When

- the search is subset-like and the whole point is to replace `2^n` with
  `2^{n/2}`

## Repo Anchors And Compare Points

- [Recursion And Backtracking ladder](../../../practice/ladders/foundations/recursion-backtracking/README.md)
- [Bitmask DP](../../dp/bitmask-dp/README.md)
- [Constructive](../../advanced/constructive/README.md)
- [Complexity And Hardness](../../advanced/complexity-and-hardness/README.md)
- [Meet-In-The-Middle](../../advanced/meet-in-the-middle/README.md)

## Sources

- Reference: [Competitive Programmer's Handbook](https://www.cses.fi/book/book.pdf)
- Reference: [Jeff Erickson - Backtracking notes](https://jeffe.cs.illinois.edu/teaching/algorithms/)
- Practice: [CSES Problem Set](https://cses.fi/problemset/)
