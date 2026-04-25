# Mobius Hot Sheet

Use this page when the statement has already collapsed into:

```text
count something over gcd/divisor structure by summing over all d <= MAX
```

and the real choice is whether plain divisor frequencies are enough or Mobius cancellation is the exact next step.

## Do Not Use When

- the prime set is explicit and small enough for ordinary inclusion-exclusion
- you only need a monotone divisor fact like "largest d that divides at least two numbers"
- the task is really congruence solving or prime-mod arithmetic

## Choose By Signal

- unordered pairs with `gcd = 1` in one bounded array -> build `mu`, count multiples, sum `mu[d] * C(cnt[d], 2)` -> [`mobius-linear-sieve.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/mobius-linear-sieve.cpp)
- exact gcd layer after counting pairs divisible by `d` -> same Mobius worldview on scaled divisors -> reopen the topic
- only need "some divisor appears in at least two values" -> direct divisor-frequency route -> compare [Common Divisors](../practice/ladders/math/gcd-lcm/commondivisors.md)
- one small explicit set of forbidden/required primes -> ordinary inclusion-exclusion -> compare [Prime Multiples](../practice/ladders/combinatorics/inclusion-exclusion/primemultiples.md)

## Core Invariants

- `sum_{d | n} mu[d] = 1` if `n = 1`, otherwise `0`
- `cnt[d]` means the number of input values divisible by `d`
- `C(cnt[d], 2)` counts unordered pairs whose gcd is divisible by `d`
- the Mobius-weighted sum cancels every pair whose gcd is not the target one

## Main Traps

- counting ordered pairs when the statement wants unordered pairs
- forgetting that squareful divisors contribute `mu[d] = 0`
- factoring every pair instead of using one frequency array plus multiples loops
- jumping to Mobius when a simpler divisor-frequency scan already answers the task

## Exact Starter In This Repo

- exact starter -> [`mobius-linear-sieve.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/mobius-linear-sieve.cpp)
- flagship in-lane rep -> [Counting Coprime Pairs](../practice/ladders/math/mobius-multiplicative/countingcoprimepairs.md)
- compare points:
  - [Common Divisors](../practice/ladders/math/gcd-lcm/commondivisors.md)
  - [Prime Multiples](../practice/ladders/combinatorics/inclusion-exclusion/primemultiples.md)

## Reopen Paths

- full derivation and chooser -> [Mobius And Multiplicative Counting](../topics/math/mobius-multiplicative/README.md)
- divisor/gcd refresh -> [Number theory cheatsheet](number-theory-cheatsheet.md)
- explicit subset IE compare -> [Inclusion-Exclusion](../topics/combinatorics/inclusion-exclusion/README.md)
- snippet chooser -> [Template Library](../template-library.md)
