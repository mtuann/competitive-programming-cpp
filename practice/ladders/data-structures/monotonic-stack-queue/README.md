# Monotonic Stack / Queue Ladder

This ladder is for learning when one linear scan plus one domination rule is
enough, so you do not overbuild a heavier range-query structure.

## Who This Is For

Use this ladder when:

- nearest greater / smaller logic still turns into nested loops
- every sliding-window max/min problem looks like a heap or multiset problem first
- you want a cleaner boundary between monotone scans and real online data structures

## Warm-Up

- next greater / smaller
- previous greater / smaller

## Core

- histogram-style boundary scans
- fixed-width window extrema
- proving the `push once, pop once` amortized bound

## Exact Repo Route

- stack-side starter -> [monotonic-stack-nearest-smaller.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/monotonic-stack-nearest-smaller.cpp)
- queue-side starter -> [monotonic-deque-min.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/monotonic-deque-min.cpp)
- flagship in-lane rep -> [Nearest Smaller Values](nearestsmallervalues.md)
- queue-side compare rep -> [Sliding Window Minimum](../../dp/sliding-window/slidingwindowminimum.md)
- stretch sibling -> histogram / rectangle boundary tasks such as `Advertisement`

## Compare Points Inside The Repo

- [Two Pointers](../../foundations/two-pointers/README.md)
- [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md)
- [Sliding Window](../../dp/sliding-window/README.md)
- [Segment Tree](../segment-tree/README.md)

## External Practice

- [CSES Problem Set](https://cses.fi/problemset/)
- [CP-Algorithms - Minimum stack / queue](https://cp-algorithms.com/data_structures/stack_queue_modification.html)

## Tutorial Link

- [Monotonic Stack / Queue](../../../../topics/data-structures/monotonic-stack-queue/README.md)
