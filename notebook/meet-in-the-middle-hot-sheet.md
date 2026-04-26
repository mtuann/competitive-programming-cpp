# Meet-In-The-Middle Hot Sheet

Use this sheet when the search is still exact, but `2^n` is too large and `2^{n/2}` is still realistic.

## Do Not Use When

- overlapping subproblems dominate -> [Bitmask DP](../topics/dp/bitmask-dp/README.md)
- pruning is strong enough that ordinary backtracking already kills most of the tree -> [Recursion And Backtracking](../topics/foundations/recursion-backtracking/README.md)
- the combine step is as expensive as the original search, so the split buys nothing
- the task is not subset-like or does not factor into two independent halves

## Choose By Signal

- `n ≈ 35 .. 45`, subset sum / count / best-feasible merge -> meet-in-the-middle
- exact subset count with duplicates in half-sums -> sort one side and use `equal_range`
- exact best sum `<= x` or exact feasibility -> sort one side and binary-search complements
- one algebraic square-root split in modular exponent recovery -> [Discrete Log hot sheet](discrete-log-hot-sheet.md)

## Core Invariants

- every full solution decomposes into exactly one left-half state and one right-half state
- the half summary preserves exactly the data the merge needs
- the true cost is `enumerate + store + sort/hash + merge`, not only `2^{n/2}`
- duplicates in the half summaries are part of correctness when the statement counts subsets, not only distinct sums

## Main Traps

- forgetting multiplicity when many half-sums are equal
- storing too much state in each half and killing the whole point of the split
- declaring MITM too early before proving the merge layer is cheap enough
- using `int` for answer counts that can reach `2^n`

## Exact Starter Route

- exact starter -> [meet-in-the-middle-subset-sum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/advanced/meet-in-the-middle-subset-sum.cpp)
- flagship in-lane rep -> [Meet in the Middle](../practice/ladders/advanced/meet-in-the-middle/meetinthemiddle.md)
- compare subset-search lanes -> [Recursion And Backtracking](../topics/foundations/recursion-backtracking/README.md), [Bitmask DP](../topics/dp/bitmask-dp/README.md)
- algebraic sibling -> [Discrete Log hot sheet](discrete-log-hot-sheet.md)

## Reopen Paths

- full topic page -> [Meet-In-The-Middle](../topics/advanced/meet-in-the-middle/README.md)
- broader judgment lane -> [Complexity And Hardness](../topics/advanced/complexity-and-hardness/README.md)
- retrieval router -> [Build Kit](../docs/build-kit.md)
