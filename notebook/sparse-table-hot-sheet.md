# Sparse Table Hot Sheet

Use this page when the array is immutable and the remaining question is whether a static idempotent range primitive is enough.

## Do Not Use When

- updates exist, so the structure is not static anymore
- the operation is not idempotent, so the two-block overlap trick is invalid
- prefix sums or one simpler static formula already solve the task

## Choose By Signal

- static range minimum -> [`sparse-table-rmq.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/sparse-table-rmq.cpp)
- static range maximum, `gcd`, or another idempotent associative operation -> sparse table pattern, not an exact repo starter
- LCA through Euler tour plus RMQ -> sparse table as the RMQ layer
- any static range query where overlap double-counts information -> do not force sparse table

## Core Invariants

- `st[k][i]` stores the answer on the length-`2^k` block starting at `i`
- one query `[l, r]` is answered by two length-`2^k` blocks that both sit inside the range
- overlap is harmless only because the operation is idempotent
- the repo starter is an inclusive-index RMQ wrapper for `min`

## Main Traps

- copying the RMQ starter into a `sum` problem and forgetting overlap breaks correctness
- mixing inclusive statement ranges with a half-open mental model from segment trees
- choosing sparse table when only one offline sweep or one prefix structure already finishes the job
- forgetting that `O(n log n)` memory is still real on larger static instances

## Exact Starters In This Repo

- static range minimum on immutable data -> [`sparse-table-rmq.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/sparse-table-rmq.cpp)
- flagship repo note -> [Static Range Minimum Queries](../practice/ladders/data-structures/sparse-table/staticrangeminimumqueries.md)
- compare against heavier mutable structures -> [Segment Tree hot sheet](segment-tree-hot-sheet.md)

## Reopen Paths

- proof, idempotence boundary, and Euler-tour RMQ -> [Sparse Table](../topics/data-structures/sparse-table/README.md)
- broader structure chooser -> [Data structures cheatsheet](data-structures-cheatsheet.md)
- snippet map -> [Template Library](../template-library.md)
