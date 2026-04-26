# Burnside / Pólya Hot Sheet

Use this page when the real task is counting **equivalence classes under symmetry**, not counting raw representations.

## Do Not Use When

- the objects are already distinct by statement and there is no quotient by symmetry
- the only missing tool is `powmod` or modular inverse
- the main problem is DP or graph modeling, not orbit counting

## Choose By Signal

- cyclic colorings up to rotation only -> [`burnside-cyclic-necklaces.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/combinatorics/burnside-cyclic-necklaces.cpp)
- same idea but on a square/grid with only a few named rotations -> reopen [Burnside / Pólya / Group Actions](../topics/combinatorics/burnside-polya/README.md) before copying the necklace formula blindly
- the statement says reflections also matter -> reopen the topic page; the starter is rotations-only
- the real issue is just `powmod`, inverse, or dividing by group size modulo one prime -> reopen [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md)

## Core Invariants

- Burnside counts **orbits** by averaging fixed representations over the group
- for colorings, one permutation with `c` position-cycles fixes exactly `k^c` assignments
- on a necklace, rotation by `r` has `gcd(n, r)` cycles
- the repo starter contract is narrow: `C_n` action, one fixed prime modulus, no reflections

## Main Traps

- counting raw strings and trying to divide by `n` heuristically
- forgetting that the group is rotations only, not dihedral symmetry
- dividing modulo `MOD` without checking that the inverse of `|G|` exists
- using the necklace formula on grid rotations or reflection problems

## Exact Starter In This Repo

- cyclic rotations on one necklace -> [`burnside-cyclic-necklaces.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/combinatorics/burnside-cyclic-necklaces.cpp)
- anchor note -> [Counting Necklaces](../practice/ladders/combinatorics/burnside-polya/countingnecklaces.md)

## Reopen Paths

- full route and stretch boundaries -> [Burnside / Pólya / Group Actions](../topics/combinatorics/burnside-polya/README.md)
- raw counting before symmetry enters -> [Combinatorics cheatsheet](combinatorics-cheatsheet.md)
- fixed-prime inverse / `powmod` helpers -> [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md)
- next symmetry rep with different cycle shapes -> [Counting Grids](https://cses.fi/problemset/task/2210)
