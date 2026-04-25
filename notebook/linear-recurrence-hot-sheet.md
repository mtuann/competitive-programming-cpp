# Linear Recurrence Hot Sheet

Use this page when a problem has already collapsed into:

```text
one small linear state transition, repeated many times
```

and the real question is whether to ship a companion matrix.

## Do Not Use When

- `n` is small enough for ordinary DP
- the transition is not linear after algebraic cleanup
- the state dimension is too large for dense `O(k^3 log n)` powers
- a specialized route like Fibonacci fast doubling is clearly lighter

## Choose By Signal

- fixed-order recurrence like `f(n) = c1 f(n-1) + ... + ck f(n-k)` -> companion matrix -> [`matrix-exponentiation.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/matrix-exponentiation.cpp)
- repeated small linear transition on counts or walks -> matrix exponentiation route -> reopen the topic
- same huge-index recurrence but only Fibonacci-like structure -> compare fast doubling first before copying a full matrix starter
- the problem is really only about modulo-safe arithmetic -> go back to [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md)

## Core Invariants

- the state vector meaning must stay fixed for every power application
- one matrix multiplication must represent exactly one time step
- the first row computes the new value; the remaining rows usually shift old values down
- `T^p` means "apply the same linear transition `p` times"

## Main Traps

- mixing up the order `[f(i), f(i-1), ...]`
- using the wrong base index before exponentiating
- forgetting that matrix multiply order matters
- ignoring overflow inside one cell accumulation before taking `% MOD`

## Exact Starter In This Repo

- exact starter -> [`matrix-exponentiation.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/matrix-exponentiation.cpp)
- flagship in-lane rep -> [Throwing Dice](../practice/ladders/math/linear-recurrence/throwingdice.md)
- compare point -> [CSES - Fibonacci Numbers](https://cses.fi/problemset/task/1722)

## Reopen Paths

- full state-vector and companion-matrix walkthrough -> [Linear Recurrence / Matrix Exponentiation](../topics/math/linear-recurrence/README.md)
- modulo discipline and overflow sanity -> [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md)
- snippet chooser -> [Template Library](../template-library.md)
