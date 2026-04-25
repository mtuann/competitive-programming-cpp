# Digit DP Hot Sheet

Use this page when the real object is a decimal prefix construction under an upper bound and you need the shortest route back to `tight`, `started`, and the one extra state that matters.

## Do Not Use When

- the range is small enough to brute force directly
- the property is not really digit-structured
- direct combinatorics by length class is cleaner than carrying a bound flag

## Choose By Signal

- count valid numbers in `[L, R]` with a digit-local rule -> digit DP
- property depends on previous digit, remainder, digit sum, or automaton state -> digit DP
- standard range reduction `solve(R) - solve(L - 1)` -> digit DP
- starter with `prev_digit` baked in -> [`digit-dp-skeleton.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/digit-dp-skeleton.cpp)

## Core Invariants

- `tight = 1` means the built prefix is still glued to the bound prefix
- `started = 0` means you are still in the all-leading-zero zone
- the state should remember exactly the future-relevant digit property and nothing more
- the repo starter is **not** fully generic; it already bakes in one previous-digit dimension

## Main Traps

- forgetting `solve(R) - solve(L - 1)`
- mishandling the all-zero path through `started`
- copying the starter as if every digit DP has the same `prev_digit` state
- carrying extra history that explodes the state space

## Exact Starters In This Repo

- prev-digit flavored digit DP skeleton -> [`digit-dp-skeleton.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/digit-dp-skeleton.cpp)
- flagship repo note -> [Counting Numbers](../practice/ladders/dp/digit-dp/countingnumbers.md)
- compare-point for general DP state design -> [DP cheatsheet](dp-cheatsheet.md)

## Reopen Paths

- `tight`, `started`, and state design boundaries -> [Digit DP](../topics/dp/digit-dp/README.md)
- broader state-design refresher -> [DP cheatsheet](dp-cheatsheet.md)
- template map -> [Template Library](../template-library.md)
