# Sliding Window Ladder

## Who This Is For

Use this ladder when a problem sits between DP and window techniques, and the main challenge is maintaining the right bounded state while scanning.

## Warm-Up

- variable-window reasoning
- weighted windows over sorted structure

## Core

- combine window invariants with DP-style state interpretation
- avoid recomputing window contributions from scratch

## Retrieval Layer

- moving minimum / best recent transition -> [monotonic-deque-min.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/monotonic-deque-min.cpp)
- balanced lower median in a dynamic window -> [sliding-median-two-multisets.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/sliding-median-two-multisets.cpp)
- short reminder sheet -> [DP cheatsheet](../../../../notebook/dp-cheatsheet.md)
- exact monotone-window rep -> [Sliding Window Minimum](slidingwindowminimum.md)

## Example Notes

- [Sliding Window Minimum](slidingwindowminimum.md)
- [TFIELD](tfield.md)

## Exit Criteria

You are ready to move on when you can:

- explain what the active window means at every step
- tell whether a problem is really two-pointers, really DP, or a hybrid
- maintain weighted contributions incrementally
- move between geometric preprocessing and windowed counting without losing the model

## External Practice

- [USACO Guide - Two Pointers](https://usaco.guide/silver/two-pointers)
- [CSES Problem Set](https://cses.fi/problemset/)

## Related Tutorials

- [Two Pointers](../../../../topics/foundations/patterns/two-pointers/README.md)
- [DP Foundations](../../../../topics/dp/foundations/README.md)
