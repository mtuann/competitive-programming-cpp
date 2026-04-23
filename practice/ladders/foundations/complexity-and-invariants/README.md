# Complexity And Invariants Ladder

This ladder is not about one algorithm. It is about learning to justify, test, and debug your implementation.

## Who This Is For

Use this ladder if:

- your sample tests pass but hidden tests fail
- you often cannot explain what a pointer, state, or endpoint means
- you want a repeatable debugging process

## Warm-Up

- estimate the complexity of a simple loop nest
- explain what each variable means in one accepted solution
- identify one invariant in prefix sums or a running maximum scan

Target skill:

- stop writing code whose state meaning is vague

## Core

- binary search invariant checks
- prefix-sum correctness arguments
- two-pointer window invariants
- greedy-after-sorting proof sketches

Target skill:

- describe the algorithm as state + invariant + transition

## Stretch

- write a short proof sketch before coding
- build custom edge cases before running samples
- restate one accepted solution as invariants plus transitions only

Target skill:

- debug by reasoning, not by random edits

## Exit Criteria

You are ready to move on when:

- you routinely state the invariant before or during coding
- you estimate time complexity before implementation
- you can create small counterexamples for weak ideas quickly

## External Practice

- [AtCoder Educational DP Contest](https://atcoder.jp/contests/dp)
- [CSES Problem Set](https://cses.fi/problemset/)
- [CP-Algorithms](https://cp-algorithms.com/)

## Tutorial Link

- [Reasoning And Implementation Discipline](../../../../topics/foundations/reasoning/README.md)
