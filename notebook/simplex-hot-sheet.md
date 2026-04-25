# Simplex Hot Sheet

Use this page when the story is already one small continuous LP and the honest contest route is:

$$
\max c^T x
\quad
\text{s.t. } Ax \le b,\ x \ge 0.
$$

## Do Not Use When

- the variables must be integral or binary
- the structure is obviously [Min-Cost Flow](../topics/graphs/min-cost-flow/README.md) or [Maximum Flow](../topics/graphs/flow/README.md)
- the problem needs proof language more than one numeric solver -> [Optimization And Duality](../topics/advanced/optimization-and-duality/README.md)
- the constraints still need heavy normalization before they even look like one small LP

## Exact Route In This Repo

- maximize `c^T x`
- constraints already normalized to `Ax <= b`
- variables already nonnegative
- return:
  - `OPTIMAL`
  - `INFEASIBLE`
  - `UNBOUNDED`
  - and one primal solution vector when feasible

## Recognition Cues

- blend / mixture / diet / resource allocation
- "how much of each product should we make?"
- all coefficients are linear and real-valued
- output is a real optimum, not a combinatorial witness

## Core Invariants

- every constraint must mean one upper bound in the same variable space
- `x >= 0` is part of the route, not an optional detail
- `unbounded` usually means a missing upper bound, not a random floating bug
- floating-point `eps` comparisons are part of the implementation contract

## Main Traps

- forgetting to divide percentages by `100`
- accidentally solving the continuous relaxation of an integer problem
- mixing `<=`, `>=`, and equality constraints without finishing the normalization step
- trusting the solver on wildly scaled coefficients without sanity checks

## Exact Starter In This Repo

- starter -> [`simplex-max-ax-le-b.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/advanced/simplex-max-ax-le-b.cpp)
- flagship rep -> [Cheese, If You Please](../practice/ladders/advanced/simplex/cheeseifyouplease.md)
- theory sibling -> [Optimization And Duality](../topics/advanced/optimization-and-duality/README.md)

## Reopen Paths

- full tutorial -> [Simplex](../topics/advanced/simplex/README.md)
- parent router -> [Optimization And Duality](../topics/advanced/optimization-and-duality/README.md)
- retrieve layer -> [Build Kit](../docs/build-kit.md) and [Template Library](../template-library.md)

