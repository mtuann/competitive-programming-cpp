# Gaussian Elimination Hot Sheet

Use this page when the statement is really one linear system

$$
Ax = b
$$

over one field, and the contest-safe first route is:

- build the augmented matrix
- pivot by column
- eliminate
- recover any valid assignment

## Do Not Use When

- the coefficients live under a composite modulus and you were about to invert every nonzero pivot
- the task is xor-subset span over bits -> use [XOR Basis hot sheet](xor-basis-hot-sheet.md)
- the matrix only describes repeated transitions -> use [Linear Recurrence hot sheet](linear-recurrence-hot-sheet.md)
- the real challenge is floating-point conditioning rather than exact contest algebra

## Choose By Signal

- solve one linear system modulo one prime and output any valid assignment -> [`gaussian-elimination-mod-prime.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/gaussian-elimination-mod-prime.cpp)
- subset xor span / maximum subset xor -> [XOR Basis hot sheet](xor-basis-hot-sheet.md)
- repeated linear transition / companion matrix -> [Linear Recurrence hot sheet](linear-recurrence-hot-sheet.md)
- you only need scalar inverses / powers under one prime modulus -> [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md)

## Core Invariants

- row swaps, row scaling by a nonzero constant, and row additions preserve the solution set
- one pivot column means that variable is fixed relative to previously chosen pivots
- a non-pivot column is a free variable; for "any solution" tasks, set it to `0`
- `all-zero left side + nonzero RHS` means the system is inconsistent
- the repo's exact first route assumes a **prime modulus**, so every nonzero pivot is invertible

## Main Traps

- using Fermat inverse under a composite modulus
- forgetting to normalize subtraction back into `[0, MOD)`
- assuming every variable receives a pivot
- outputting pivot-row RHS values without mapping them back through `where[col]`
- confusing this lane with xor-basis elimination over `GF(2)`

## Exact Starters In This Repo

- exact starter -> [`gaussian-elimination-mod-prime.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/gaussian-elimination-mod-prime.cpp)
- flagship in-lane rep -> [System of Linear Equations](../practice/ladders/math/gaussian-elimination/systemoflinearequations.md)
- nearby compare point -> [XOR Basis / Linear Basis](../topics/math/xor-basis/README.md)
- nearby foundation -> [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md)

## Reopen Paths

- full lesson -> [Gaussian Elimination / Linear Algebra](../topics/math/gaussian-elimination/README.md)
- broader chooser -> [Build Kit](../docs/build-kit.md)
- template chooser -> [Template Library](../template-library.md)
