# Lucas Theorem Hot Sheet

Use this page when the problem has already collapsed into:

```text
nCk mod p, with p prime and some queries crossing n >= p
```

and the real question is whether one factorial table still works or the query must be broken into base-`p` digits.

## Do Not Use When

- every query satisfies `max_n < p`, so an ordinary factorial table is enough
- the modulus is composite
- `p` is so large that `O(p)` precompute is already a bad idea

## Choose By Signal

- one prime modulus, some queries with `n >= p` -> Lucas digit decomposition -> [`lucas-binomial.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/lucas-binomial.cpp)
- one prime modulus, all queries with `max_n < p` -> ordinary factorial table -> compare [`factorial-binomial-mod.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/factorial-binomial-mod.cpp)
- composite modulus -> Lucas alone is not enough -> reopen CRT / future generalized lane
- parity of Pascal/binomial structure -> think Lucas with `p = 2` before brute force

## Core Invariants

- Lucas works digit by digit in base `p`
- the answer is the product of all digit-level binomials
- one digit with `ki > ni` makes the whole answer `0`
- the small helper `C(ni, ki)` is ordinary prime-mod binomial again

## Main Traps

- forcing Lucas when the lighter `max_n < p` table route already solves the whole judge
- forgetting Lucas needs `p` prime
- building `fact[0..p-1]` when `p` is too large for memory/time
- mixing up the lane with composite-mod binomial reconstruction

## Exact Starter In This Repo

- exact starter -> [`lucas-binomial.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/lucas-binomial.cpp)
- flagship in-lane rep -> [Binomial Coefficient (Prime Mod)](../practice/ladders/math/lucas-theorem/binomialcoefficientprimemod.md)
- compare point -> [Distributing Apples](../practice/ladders/combinatorics/counting-basics/distributingapples.md)

## Reopen Paths

- full theorem boundary and worked examples -> [Lucas Theorem / Large Binomial Mod Prime](../topics/math/lucas-theorem/README.md)
- prime-mod arithmetic sanity -> [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md)
- snippet chooser -> [Template Library](../template-library.md)
