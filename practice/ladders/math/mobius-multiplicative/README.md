# Mobius And Multiplicative Counting Ladder

## Who This Is For

Use this ladder when you are comfortable with gcd/divisibility basics and ordinary inclusion-exclusion, but divisor-side counting formulas still feel magical instead of mechanical.

## Warm-Up

- gcd / lcm and divisor vocabulary
- bounded-value frequency arrays
- ordinary inclusion-exclusion on a small explicit prime set
- linear sieve as a preprocessing pattern

## Core

- recognize when `cnt[d] = number of values divisible by d` is the right state
- derive `C(cnt[d], 2)` as the number of unordered pairs whose gcd is divisible by `d`
- use Mobius cancellation to isolate `gcd = 1`
- distinguish "direct divisor-frequency scan is enough" from "exact Mobius inversion is cleaner"

## Stretch

- recover exact gcd layers like `gcd = g`
- explain Mobius as divisor-side inclusion-exclusion, not just a memorized formula
- connect the lane to multiplicative-function and divisor-sum viewpoints without overreaching to heavier machinery

## Retrieval Layer

- exact starter -> [mobius-linear-sieve.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/mobius-linear-sieve.cpp)
- quick reminder sheet -> [Mobius hot sheet](../../../../notebook/mobius-hot-sheet.md)
- compare points:
  - [Common Divisors](../gcd-lcm/commondivisors.md)
  - [Prime Multiples](../../combinatorics/inclusion-exclusion/primemultiples.md)

## Repo Anchors

- [Counting Coprime Pairs](countingcoprimepairs.md)

## Exit Criteria

You are ready to move on when you can:

- derive the pair-count formula from divisor frequencies instead of memorizing it
- explain why Mobius weights isolate `gcd = 1`
- decide when ordinary inclusion-exclusion is still the simpler route
- implement one linear sieve + multiples loop solution without pairwise gcd checks

## External Practice

- [CSES - Counting Coprime Pairs](https://cses.fi/problemset/task/2417)

## Tutorial Link

- [Mobius And Multiplicative Counting](../../../../topics/math/mobius-multiplicative/README.md)
