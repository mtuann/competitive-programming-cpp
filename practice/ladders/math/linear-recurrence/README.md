# Linear Recurrence / Matrix Exponentiation Ladder

## Who This Is For

Use this ladder when you can derive a recurrence correctly, but the statement makes `n` too large for step-by-step DP.

## Warm-Up

- binary exponentiation
- modulo-safe multiplication and addition
- state vectors with a fixed small dimension

## Core

- companion matrix for a fixed-order recurrence
- fast matrix power by repeated squaring
- base-state selection and exponent offset

## Stretch

- compare matrix exponentiation with Fibonacci fast doubling
- compare recurrence lifting with adjacency-matrix walk counting
- explain when dense `O(k^3 log n)` is no longer the right route

## Retrieval Layer

- exact starter -> [matrix-exponentiation.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/matrix-exponentiation.cpp)
- quick reminder sheet -> [Linear Recurrence hot sheet](../../../../notebook/linear-recurrence-hot-sheet.md)
- modulo sanity companion -> [Modular Arithmetic hot sheet](../../../../notebook/modular-arithmetic-hot-sheet.md)

## Repo Anchors

- [Throwing Dice](throwingdice.md)

## Exit Criteria

You are ready to move on when you can:

- turn one fixed-width recurrence into a state vector without guessing
- write the companion matrix in the right state order
- explain why `T^p` means "apply the recurrence `p` times"
- decide when matrix exponentiation is cleaner than direct DP

## External Practice

- [CSES - Fibonacci Numbers](https://cses.fi/problemset/task/1722)
- [CSES - Throwing Dice](https://cses.fi/problemset/task/1096)
- [CSES - Graph Paths I](https://cses.fi/problemset/task/1723)

## Tutorial Link

- [Linear Recurrence / Matrix Exponentiation](../../../../topics/math/linear-recurrence/README.md)
