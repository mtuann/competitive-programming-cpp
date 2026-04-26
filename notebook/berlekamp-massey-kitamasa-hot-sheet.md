# Berlekamp-Massey / Kitamasa Hot Sheet

Use this page when a sequence is already known or suspected to be linearly recurrent over one fixed prime modulus, and matrix exponentiation is no longer the cleanest route.

## Do Not Use When

- the recurrence order is tiny and the matrix route is already simpler
- the sequence is not linear over the field you are working in
- the real task is ordinary DP or modular arithmetic, not recurrence jumping

## Choose By Signal

- recurrence coefficients and first `d` terms are already given -> use [`berlekamp-massey-kitamasa.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/berlekamp-massey-kitamasa.cpp) through the `linear_recurrence_kth()` half
- only a long enough prefix is given, and the shortest recurrence itself is hidden -> same starter, but open the `berlekamp_massey()` half first
- recurrence order is small enough that a companion matrix is clearer than recurrence-polynomial reduction -> reopen [Linear Recurrence hot sheet](linear-recurrence-hot-sheet.md)
- the task has become full generating-function / polynomial algebra rather than one recurrence jump -> reopen [Polynomial / FPS hot sheet](polynomial-fps-hot-sheet.md)

## Core Invariants

- recurrence convention in this repo is `a_n = c[0] a_{n-1} + ... + c[d-1] a_{n-d}`
- Kitamasa keeps polynomials reduced to degree `< d`, where coefficients mean "how to combine `a_0..a_{d-1}`"
- Berlekamp-Massey only changes the current recurrence when the discrepancy against the known prefix is nonzero
- the starter contract is fixed prime modulus `998244353`

## Main Traps

- reducing polynomial products with coefficients in the wrong order
- mixing 0-indexed initial terms with 1-indexed paper notation
- assuming Berlekamp-Massey works unchanged outside a trusted field
- reaching for this lane when the matrix route is still smaller and clearer

## Exact Starter In This Repo

- combined helper -> [`berlekamp-massey-kitamasa.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/berlekamp-massey-kitamasa.cpp)
- flagship in-lane rep -> [K-th Term of Linearly Recurrent Sequence](../practice/ladders/math/berlekamp-massey-kitamasa/kthtermoflinearlyrecurrentsequence.md)

## Reopen Paths

- full lane walkthrough -> [Berlekamp-Massey / Kitamasa](../topics/math/berlekamp-massey-kitamasa/README.md)
- smaller-order recurrence route -> [Linear Recurrence hot sheet](linear-recurrence-hot-sheet.md)
- modulo discipline -> [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md)
- later algebraic compare point -> [Polynomial / FPS hot sheet](polynomial-fps-hot-sheet.md)
