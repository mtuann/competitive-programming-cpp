# Algorithm Engineering Ladder

## Who This Is For

Use this ladder when you already know the algorithmic ideas, but accepted code is still inconsistent because of bugs, constants, or weak verification habits.

## Warm-Up

- brute-force checker design
- stress testing habits

## Core

- bottleneck identification
- data-layout and implementation tradeoffs

## Repo Case Studies

- [Minimum Euclidean Distance](minimumeuclideandistance.md)
- [FFLOW](../../graphs/flow/fflow.md)
- [PRAVO](../../geometry/right-triangles/pravo.md)

## Internal Material

- [Stress Testing Workflow](../../../../notebook/stress-testing-workflow.md)
- [Contest Checklist](../../../../notebook/contest-checklist.md)
- [Build Kit](../../../../docs/build-kit.md)
- [Problem Finder](../../../../docs/problem-finder.md)

## Stretch

- judge-specific performance traps
- rewrite a correct solution into a faster version without losing trust in it

## Repo Anchors And Compare Points

- closest-pair sweep case study -> [Minimum Euclidean Distance](minimumeuclideandistance.md)
- flow implementation under load -> [FFLOW](../../graphs/flow/fflow.md)
- geometry counting/performance tradeoffs -> [PRAVO](../../geometry/right-triangles/pravo.md)
- workflow companions -> [Algorithm Engineering](../../../../topics/advanced/algorithm-engineering/README.md) and [Contest Engineering](../../../../topics/advanced/contest-engineering/README.md)

This ladder only has one direct in-lane note, so use the compare points on purpose:

1. study one case where the algorithmic idea is already known
2. identify what the real bottleneck is: bugs, constants, memory layout, or validation discipline
3. reopen the workflow pages before changing code blindly

## Exit Criteria

You are ready to move on when you can:

- isolate a bug with a small failing case instead of guessing
- compare a fast solution against a checker systematically
- explain why one implementation of the same big-O wins in practice
- optimize only after you know the real bottleneck

## External Practice

- [KACTL](https://github.com/kth-competitive-programming/kactl)
- [CP-Algorithms](https://cp-algorithms.com/)

## Tutorial Link

- [Algorithm Engineering](../../../../topics/advanced/algorithm-engineering/README.md)
