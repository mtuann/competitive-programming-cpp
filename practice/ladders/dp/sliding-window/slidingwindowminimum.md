# Sliding Window Minimum

- Title: `Sliding Window Minimum`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/3221](https://cses.fi/problemset/task/3221)
- Secondary topics: `Monotonic deque`, `Generated input`, `Window aggregate`
- Difficulty: `medium`
- Subtype: `Xor of fixed-window minimums over a generated stream`
- Status: `solved`
- Solution file: [slidingwindowminimum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/sliding-window/slidingwindowminimum.cpp)

## Why Practice This

This is the cleanest exact note for the monotonic deque template.

The core task is pure:

- every window has the same length
- only the minimum matters
- the valid set moves strictly left to right

The generated input makes the implementation feel more “contest-real,” but the reusable engine is still just a monotonic deque.

## Recognition Cue

Reach for a monotonic deque when:

- the active set is one forward-moving contiguous window
- each step adds one new element and expires at most one old prefix index
- you need only the minimum or maximum of the active window

The strongest smell is:

- "minimum of every window of length `k`"

That is usually the textbook monotonic deque use case.

## Problem-Specific Transformation

The statement includes a generator and asks for the xor of all window minimums, but the reusable rewrite is:

- treat the generated sequence as an ordinary stream of values
- maintain the minimum of the current window
- fold the minima into one final xor instead of storing the whole output list

So the generator is input plumbing, not the algorithm.

## Core Idea

Maintain a deque of candidate minima.

For each new value at index `i`:

1. pop from the back while the new value is smaller or equal
2. push `(i, value)` onto the back
3. pop from the front while the stored index is outside the current window
4. once the first full window is formed, the front is the minimum

Every index enters once and leaves once, so the whole process is linear.

The only extra problem-specific step is:

- xor the window minima together instead of printing each one

## Complexity

- sequence generation: `O(n)`
- deque maintenance: `O(n)` total
- memory: `O(k)` in the usual interpretation, bounded by the deque size

## Pitfalls / Judge Notes

- Use `long long` in the generator multiplication before taking `% c`.
- The deque stores indices, not just values, because expiry depends on position.
- Remove expired indices from the front **after** the new push policy is applied, but before reading the current answer.
- The task asks for the xor of all window minima, not the list of minima.

## Reusable Pattern

- Topic page: [Heaps And Ordered Sets](../../../../topics/data-structures/heaps-and-ordered-sets/README.md)
- Practice ladder: [Sliding Window ladder](README.md)
- Starter template: [monotonic-deque-min.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/monotonic-deque-min.cpp)
- Notebook refresher: [Data structures cheatsheet](../../../../notebook/data-structures-cheatsheet.md)
- Carry forward: define exactly which indices are alive and which values dominate later candidates.
- This note adds: the generated-input wrapper and xor fold on top of the standard monotonic-window minimum primitive.

## Solutions

- Code: [slidingwindowminimum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/sliding-window/slidingwindowminimum.cpp)
