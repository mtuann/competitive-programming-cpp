# Increasing Array

- Title: `Increasing Array`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1094](https://cses.fi/problemset/task/1094)
- Secondary topics: `Loop invariant`, `Greedy repair`, `Running maximum`
- Difficulty: `easy`
- Subtype: `Minimum total increments to make an array nondecreasing`
- Status: `solved`
- Solution file: [increasingarray.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/complexity-and-invariants/increasingarray.cpp)

## Why Practice This

This is one of the cleanest first "reasoning over a scan" problems in the whole repo.

The code is tiny, but the real lesson is bigger:

- what state does the processed prefix already guarantee?
- what is the cheapest legal repair for the next element?
- why is that greedy choice forced rather than lucky?

That is exactly the mindset this ladder is trying to build.

## Recognition Cue

Reach for this one-pass greedy repair when:

- you scan left to right
- each new position only needs to satisfy one invariant against the previous repaired prefix
- only increases are allowed
- choosing anything larger than the minimum legal repair would only add wasted cost

The strongest smell is:

- "minimum increments to make the array nondecreasing"

That usually means the repaired prefix itself is the only state you need.

## Problem-Specific Transformation

The statement sounds like many small increment operations, but the reusable rewrite is:

- forget individual `+1` moves
- ask what the current position must become in any valid repaired prefix

That collapses the problem to:

- keep the smallest legal ending value of the repaired prefix
- add exactly the gap when the next value is too small

So the algorithm is driven by one invariant, not by explicit simulation of increments.

## Core Idea

Let `fixed[i]` be the value of position `i` after we repair the array.

Because we may only **increase** values, any feasible nondecreasing result must satisfy:

```text
fixed[i] >= a[i]
fixed[i] >= fixed[i - 1]
```

So once the previous repaired value is known, the smallest legal value for the current position is:

```text
fixed[i] = max(a[i], fixed[i - 1])
```

That is the whole greedy repair.

If `a[i]` is already large enough, keep it. Otherwise we are forced to raise it to the previous repaired value. Choosing anything larger would only spend extra moves now, and it cannot help later because future positions only need the array to stay nondecreasing.

### Loop Invariant

After processing positions `0..i`, maintain:

- the repaired prefix is nondecreasing
- `moves` is the minimum total number of increments needed for that prefix
- `need` is the repaired value at position `i`, and also the smallest value the repaired prefix can legally end with

Now consider the next number `x`.

- If `x >= need`, we can keep `x`, and the new ending value becomes `x`.
- If `x < need`, every valid repaired array must raise this position to at least `need`, so the extra cost is forced to be `need - x`.

That preserves the invariant and proves the greedy scan is optimal.

## Complexity

- one left-to-right scan: `O(n)`
- extra memory: `O(1)`

This is optimal.

## Pitfalls / Judge Notes

- The answer can be much larger than one array value, so use `long long` for the move count.
- Nondecreasing means `a[i] >= a[i - 1]` is already fine; equality is allowed.
- Track the **repaired** previous value, not the original previous value.
- Do not think in terms of simulating one increment at a time. The needed increase is computed directly.

## Reusable Pattern

- Topic page: [Complexity And Invariants](../../../../topics/foundations/reasoning/README.md)
- Practice ladder: [Complexity And Invariants ladder](README.md)
- Starter template: [contest-main.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/contest-main.cpp)
- Notebook refresher: [Foundations cheatsheet](../../../../notebook/foundations-cheatsheet.md)
- Carry forward: state the loop invariant in words before you trust the one-pass solution.
- This note adds: the exact invariant or exchange argument that makes this scan or greedy step safe.

## Solutions

- Code: [increasingarray.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/complexity-and-invariants/increasingarray.cpp)
