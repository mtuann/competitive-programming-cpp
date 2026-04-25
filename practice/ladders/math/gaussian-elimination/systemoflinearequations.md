# System of Linear Equations

- Title: `System of Linear Equations`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/3154](https://cses.fi/problemset/task/3154)
- Secondary topics: `Gaussian elimination`, `Linear algebra`, `Modular inverse`
- Difficulty: `hard`
- Subtype: `Solve one linear system modulo one prime and print any valid assignment`
- Status: `solved`
- Solution file: [systemoflinearequations.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/gaussian-elimination/systemoflinearequations.cpp)

## Why Practice This

This is the cleanest in-repo anchor for the `Gaussian elimination / linear algebra` lane because it forces the exact first route:

- one full augmented matrix
- one prime modulus
- any valid assignment is acceptable

So the lesson is not determinant, inverse, or floating-point numerics.

It is:

- pivot by column
- isolate pivot variables
- set free variables to `0`
- reject only when elimination produces an inconsistent row

## Recognition Cue

Reach for Gaussian elimination when:

- the statement gives `n` linear equations in `m` unknowns
- every coefficient lives modulo one prime
- the output may be **any** satisfying assignment
- brute force over assignments is obviously impossible

The strongest smell is:

- "solve `Ax = b mod p` and print any one solution, or `-1`"

That is exactly the contest contract this starter is built for.

## Problem-Specific Transformation

Write the system as one augmented matrix:

$$
[A \mid b]
$$

Then process columns left to right.

For each column:

1. find a row with a nonzero coefficient there
2. swap it into the current pivot row
3. normalize the pivot to `1`
4. eliminate that column from every other row

After elimination:

- pivot columns correspond to dependent variables
- non-pivot columns are free variables
- any row of the form `0 ... 0 | c` with `c != 0` means no solution

For this judge, one valid solution is enough, so the standard reconstruction is:

- set every free variable to `0`
- read pivot variables from the reduced system

## Core Idea

Use Gauss-Jordan elimination over the field:

$$
\mathbb{F}_{10^9+7}
$$

Because the modulus is prime, every nonzero pivot has an inverse, so row normalization is always legal.

The invariant is:

```text
after processing some columns, every chosen pivot column has exactly one 1 and zeros everywhere else
```

That makes reconstruction trivial:

- `where[col]` tells you which row owns that variable
- free variables remain `0`

## Complexity

For `n` equations and `m` variables:

- time: `O(min(n, m) * n * m)`
- memory: `O(nm)`

This is exactly the standard contest cost for dense Gaussian elimination.

## Pitfalls / Judge Notes

- The modulus is prime, so Fermat inverse is safe here.
- This exact starter is **not** the right first route for composite-mod systems.
- Free variables are allowed; you do not need a unique solution.
- Always normalize after subtraction.
- Check for inconsistent rows before printing the vector.

## Reusable Pattern

- Topic page: [Gaussian Elimination / Linear Algebra](../../../../topics/math/gaussian-elimination/README.md)
- Practice ladder: [Gaussian Elimination / Linear Algebra ladder](README.md)
- Starter template: [gaussian-elimination-mod-prime.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/gaussian-elimination-mod-prime.cpp)
- Notebook refresher: [Gaussian Elimination hot sheet](../../../../notebook/gaussian-elimination-hot-sheet.md)
- Compare points:
  - [XMAX - XOR Maximization](../../../../practice/ladders/math/xor-basis/xmax.md)
  - [Modular Arithmetic hot sheet](../../../../notebook/modular-arithmetic-hot-sheet.md)
- This note adds: the first exact `solve Ax = b over one prime field` route in the repo.

## Solutions

- Code: [systemoflinearequations.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/gaussian-elimination/systemoflinearequations.cpp)
