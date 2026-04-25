# Gaussian Elimination / Linear Algebra Ladder

## Who This Is For

Use this ladder when modular arithmetic basics feel comfortable, but whole linear systems still feel like "too much matrix ceremony."

## Warm-Up

- modular inverse under one prime modulus
- augmented-matrix notation
- why row operations preserve the solution set

## Core

- pivot one column at a time
- normalize the pivot row
- eliminate the pivot column from all other rows
- detect free variables versus inconsistency
- flagship rep: [System of Linear Equations](systemoflinearequations.md)

## Stretch

- explain why this route is really "solve over a field"
- compare prime-mod elimination with xor-basis elimination over `GF(2)`
- compare "find any solution" against full affine-solution-space output tasks

## Retrieval Layer

- exact starter -> [gaussian-elimination-mod-prime.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/gaussian-elimination-mod-prime.cpp)
- quick reminder sheet -> [Gaussian Elimination hot sheet](../../../../notebook/gaussian-elimination-hot-sheet.md)
- compare point -> [XOR Basis / Linear Basis](../../../../topics/math/xor-basis/README.md)

## Repo Anchors

- [System of Linear Equations](systemoflinearequations.md)

## Exit Criteria

You are ready to move on when you can:

- explain why one nonzero pivot is enough to own a column
- say exactly when a variable is free
- detect `0 = nonzero` rows without hesitation
- explain why the repo starter assumes a prime modulus
- distinguish this lane from both xor-basis and matrix-exponentiation lanes

## External Practice

- [CSES - System of Linear Equations](https://cses.fi/problemset/task/3154/)
- [Library Checker - System of Linear Equations](https://judge.yosupo.jp/problem/system_of_linear_equations)

## Tutorial Link

- [Gaussian Elimination / Linear Algebra](../../../../topics/math/gaussian-elimination/README.md)
