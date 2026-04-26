# Meet-In-The-Middle

Meet-in-the-middle is the exact-search bridge you reach for when:

- the raw model is subset-like
- `2^n` is hopeless
- but `2^{n/2}` plus sorting or hashing is still realistic

This page intentionally treats MITM as a bridge topic:

- more practical than a broad hardness lecture
- but still more structural than one fixed DP pattern

## At A Glance

- **Use when:** the search space is subset-like or splitable, usually with `n` around `35` to `45`
- **Core worldview:** split the decision set into two halves, enumerate each half exactly, then combine the summaries
- **Main tools:** subset-sum enumeration, sort + binary search, hash maps, pair-sum compression
- **Typical complexity:** roughly `O(2^{n/2} poly(n))`
- **Main trap:** splitting the input without first checking whether the combine step is actually cheap enough to justify the split

Strong contest signals:

- subset sum or subset constraint with `n ≈ 40`
- "choose any subset" is the real model, but full `2^n` is too large
- the result of one half can be summarized independently and merged later

Strong anti-cues:

- overlapping subproblems dominate -> often DP instead
- the true state is tiny enough for ordinary bitmask DP
- the combine step is as hard as the original problem

## Prerequisites

- [Bitmask DP](../../dp/bitmask-dp/README.md)
- [Complexity And Hardness](../complexity-and-hardness/README.md)

Helpful neighboring topics:

- [BSGS / Discrete Log](../../math/bsgs-discrete-log/README.md)
- [Recursion And Backtracking](../../foundations/recursion-backtracking/README.md)

## Problem Model And Notation

Suppose a decision set of size `n` is split into:

- left half `L`
- right half `R`

with:

$$
|L| \approx |R| \approx n/2.
$$

The MITM pattern is:

1. enumerate all left-half states
2. enumerate all right-half states
3. store one summary per state
4. merge the two summary sets

The summary might be:

- subset sum
- chosen count
- xor
- best score under one compatibility condition

## From Brute Force To The Right Idea

### Brute Force: Enumerate All `2^n` States

If `n = 40`, then:

$$
2^{40}
$$

is already far too large for a raw exact search.

### The First Shift: Half-States Are Cheap Enough

But:

$$
2^{20}
$$

on each side is often very manageable.

That is the entire reason MITM exists.

### The Second Shift: The Combine Step Is The Real Design Problem

The split only helps if half-results can be merged cheaply.

Typical combine routes:

- sort one side, binary-search complements
- two-pointer over sorted lists
- hash map from summary to best witness
- compress pair sums first, then query

If no cheap combine exists, the split was not the right abstraction.

## Core Invariants And Why It Works

### 1. Every Full Solution Decomposes Into One Left State And One Right State

This is the structural invariant behind correctness.

You are not approximating the solution space.

You are factoring it exactly through the product:

$$
\mathcal{S} = \mathcal{S}_L \times \mathcal{S}_R.
$$

### 2. The Half Summary Must Preserve Exactly The Information Needed To Merge

If the final condition is:

- total sum at most `X`

then one half may only need to remember:

- its subset sum

If the final condition also depends on:

- chosen count
- parity
- best witness

then the summary must carry those too.

MITM fails when the half summary forgets something the merge needs.

### 3. `2^{n/2}` Is The Win, Not The Whole Story

The true cost is:

- enumerating both halves
- storing summaries
- sorting or hashing
- combining

So the win is not only smaller exponent. It is:

- smaller exponent with a cheap merge layer

## Variant Chooser

### Use MITM When

- subset-like exact search is real
- `n` is too large for `2^n`, but small enough for `2^{n/2}`
- the half summaries merge cleanly

### Use Bitmask DP Instead When

- many branches lead to the same subproblem state

### Use Backtracking Instead When

- strong prune rules make the live search tree far smaller than the full subset space

### Use BSGS As The Algebraic Sibling When

- the same square-root split appears inside one multiplicative modular problem

## Repo Anchors And Compare Points

- [Meet-In-The-Middle ladder](../../../practice/ladders/advanced/meet-in-the-middle/README.md)
- [Meet-In-The-Middle hot sheet](../../../notebook/meet-in-the-middle-hot-sheet.md)
- [Meet in the Middle](../../../practice/ladders/advanced/meet-in-the-middle/meetinthemiddle.md)
- [meet-in-the-middle-subset-sum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/advanced/meet-in-the-middle-subset-sum.cpp)
- [Complexity And Hardness](../complexity-and-hardness/README.md)
- [BSGS / Discrete Log](../../math/bsgs-discrete-log/README.md)
- [Bitmask DP](../../dp/bitmask-dp/README.md)

## Sources

- Reference: [Competitive Programmer's Handbook](https://www.cses.fi/book/book.pdf)
- Reference: [USACO Guide - Meet in the Middle](https://usaco.guide/gold/meet-in-the-middle?lang=cpp)
- Course: [Jeff Erickson - Algorithms](https://jeffe.cs.illinois.edu/teaching/algorithms/)
- Practice: [CSES Problem Set](https://cses.fi/problemset/)
