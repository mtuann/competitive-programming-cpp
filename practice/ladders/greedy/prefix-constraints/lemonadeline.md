# Lemonade Line

- Title: `Lemonade Line`
- Judge / source: `USACO 2018 US Open Silver`
- Original URL: [https://usaco.org/index.php?cpid=835&page=viewproblem2](https://usaco.org/index.php?cpid=835&page=viewproblem2)
- Secondary topics: `Sorting`, `Threshold feasibility`, `Exchange argument`
- Difficulty: `easy`
- Subtype: `Choose an arrival order that minimizes how many cows can still join a line`
- Status: `solved`
- Solution file: [lemonadeline.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/greedy/prefix-constraints/lemonadeline.cpp)

## Why Practice This

This is the cleanest first anchor for `prefix constraints`.

The whole problem is one sentence:

- a cow joins only if the current line size is at most her tolerance

That makes it a perfect place to practice two habits:

- choose an order that makes the prefix condition easiest to satisfy
- explain why that order is globally best, not just locally plausible

## Recognition Cue

Reach for descending-threshold greedy when:

- each item only cares about how many items are already accepted
- the condition is easier to satisfy for more permissive thresholds
- the final order is under your control

The strongest smell is:

- "an item joins only if the current prefix size is at most its threshold"

That usually means put the most permissive items first.

## Problem-Specific Transformation

The line-joining story is rewritten as:

- after sorting by tolerance, the only state is current accepted count

So the problem becomes:

- choose an order
- scan once
- accept if the current prefix count satisfies the threshold

That removes the queue story and exposes one prefix-feasibility greedy.

## Core Idea

Let `cnt` be the number of cows already in line.

If we process cows with **larger** tolerances first, then every accepted cow is as permissive as possible about the current prefix size.

So:

1. Sort all tolerances in descending order.
2. Scan from largest to smallest.
3. If `w[i] >= cnt`, this cow can stand behind the current `cnt` cows, so include her and increment `cnt`.
4. Otherwise skip her.

Why does this minimize the final line size?

- if a cow with small tolerance were placed early, she only makes later cows face a larger prefix
- placing large-tolerance cows first is the safest way to keep the active line as small as possible while still allowing every accepted cow to satisfy her own threshold

The final `cnt` is the minimum achievable number of cows in line.

## Complexity

- sorting: `O(n log n)`
- scan: `O(n)`

## Pitfalls / Judge Notes

- The statement asks for the **minimum possible** number of cows who join, not the maximum.
- Sorting descending is the whole trick. Ascending order pushes too many tolerant cows to the back and usually grows the line unnecessarily.
- The state you maintain is just the current line size, not the exact order after that point.

## Reusable Pattern

- Topic page: [Prefix Constraints](../../../../topics/greedy/prefix-constraints/README.md)
- Practice ladder: [Prefix Constraints ladder](README.md)
- Starter template: [sort-and-comparator.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/sort-and-comparator.cpp)
- Notebook refresher: [Foundations cheatsheet](../../../../notebook/foundations-cheatsheet.md)
- Carry forward: if each item only cares about how large the current prefix is, try sorting by the most permissive threshold first.
- This note adds: the descending-threshold ordering that collapses the state to a single prefix count.

## Solutions

- Code: [lemonadeline.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/greedy/prefix-constraints/lemonadeline.cpp)
