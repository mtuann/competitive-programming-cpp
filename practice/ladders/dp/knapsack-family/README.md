# Knapsack Family Ladder

This ladder should make the main knapsack variants feel like close relatives whose differences come from item reuse rules and transition direction.

## Who This Is For

Use this ladder if:

- loop direction still feels memorized rather than justified
- bounded and grouped variants still blur together
- subset-sum style tasks still feel separate from knapsack

## Warm-Up

- `0/1` knapsack
- subset sum
- simple feasibility DP

Target skill:

- connect the statement’s “use once or not” rule to downward iteration

## Core

- complete knapsack
- bounded knapsack
- grouped knapsack

Target skill:

- spot which variant the statement is really describing

## Stretch

- bitset subset sum -> [Bit-Parallelism / Bitset Optimization](../bit-parallelism/README.md)
- value-based knapsack
- monotone-queue bounded variants

Target skill:

- know when the classic `O(n * capacity)` form is not the best implementation

## Exit Criteria

You are ready to move on when:

- you can explain why the loop direction changes by variant
- you can rewrite one 2D knapsack into a correct 1D version
- grouped or bounded wording no longer throws off the recurrence

## External Practice

- [AtCoder Educational DP Contest](https://atcoder.jp/contests/dp)
- [OI Wiki - Knapsack](https://en.oi-wiki.org/dp/knapsack/)
- [CP-Algorithms - Knapsack](https://cp-algorithms.com/dynamic_programming/knapsack.html)

## Tutorial Link

- [Knapsack Family](../../../../topics/dp/knapsack-family/README.md)
