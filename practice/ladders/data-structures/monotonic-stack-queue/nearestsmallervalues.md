# Nearest Smaller Values

- Title: `Nearest Smaller Values`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1645](https://cses.fi/problemset/task/1645)
- Secondary topics: `Monotonic stack`, `Previous smaller`, `Boundary scan`
- Difficulty: `medium`
- Subtype: `For each position, find the nearest strictly smaller value to the left`
- Status: `solved`
- Solution file: [nearestsmallervalues.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/monotonic-stack-queue/nearestsmallervalues.cpp)

## Why Practice This

This is the cleanest stack-side anchor for the monotonic family.

Nothing is hidden behind:

- complex range queries
- dynamic updates
- or a second modeling layer

The whole lesson is just:

- which old indices survive as candidates
- and why a dominated one never comes back

That makes it the right first internal note for the bridge.

## Recognition Cue

Reach for a monotonic stack when:

- each index asks for the first smaller or greater witness on one side
- the scan direction is fixed
- once a candidate is dominated, it can never become useful again

The strongest smell is:

- "nearest smaller / greater to the left / right"

That is usually a stack problem before it is anything else.

## Problem-Specific Transformation

The statement sounds like:

- "for each position, scan left until you hit a smaller value"

but the reusable rewrite is:

- maintain an increasing stack of indices whose values are still viable previous-smaller witnesses

For the current value `a[i]`:

- any previous index with value `>= a[i]` is dead forever
- the new stack top, if it exists, is the nearest strictly smaller index

So the solution is not "search left faster."

It is:

- keep only the indices that are still legally answerable later

## Core Idea

Scan left to right with a stack of indices.

Invariant:

- values on the stack are strictly increasing from bottom to top

At index `i`:

1. pop while `a[stack.top] >= a[i]`
2. after those pops, the top is the nearest strictly smaller value to the left
3. if the stack is empty, answer `0`
4. push `i`

Why the stack top is the nearest answer:

- every larger or equal candidate was removed
- the surviving top is the closest remaining smaller element

Each index is pushed once and popped once, so the whole scan is linear.

## Complexity

- time: `O(n)`
- memory: `O(n)` in the worst case for the stack

## Pitfalls / Judge Notes

- The judge wants **1-based positions** and uses `0` when no answer exists.
- Use `>=` in the pop loop, not just `>`, because the answer must be **strictly smaller**.
- Store indices, not only values, because the output is positional.
- This is a stack-side route. If the question changes to fixed-width window minima, pivot to the deque-side sibling instead of forcing this exact code shape.

## Reusable Pattern

- Topic page: [Monotonic Stack / Queue](../../../../topics/data-structures/monotonic-stack-queue/README.md)
- Practice ladder: [Monotonic Stack / Queue ladder](README.md)
- Starter template: [monotonic-stack-nearest-smaller.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/monotonic-stack-nearest-smaller.cpp)
- Notebook refresher: [Monotonic Stack / Queue hot sheet](../../../../notebook/monotonic-stack-queue-hot-sheet.md)
- Queue-side compare point: [Sliding Window Minimum](../../dp/sliding-window/slidingwindowminimum.md)
- Carry forward: define the domination rule first, then let the stack keep only still-viable candidates.
- This note adds: the strict-smaller tie policy and the positional output contract.

## Solutions

- Code: [nearestsmallervalues.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/monotonic-stack-queue/nearestsmallervalues.cpp)
