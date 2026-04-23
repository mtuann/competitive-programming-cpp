# Randomized Algorithms

Randomized algorithms belong in the advanced layer because they teach a different way to reason: "very likely correct and fast" rather than purely worst-case deterministic guarantees.

## Prerequisites

- [Reasoning And Proof Habits](../../foundations/reasoning/README.md)
- [Algorithm Engineering](../algorithm-engineering/README.md)

## When To Suspect It

- deterministic structure is awkward, but random sampling simplifies it
- hashing, treaps, or randomized pivots appear naturally
- the problem admits a high-probability guarantee

## Core Idea

Use randomness either to:

- simplify a data structure
- balance expected performance
- sample a representative witness

## Theory / Proof Sketch

The proof style changes from exact deterministic invariants to expectation or high-probability arguments. You must identify the random experiment and what event is unlikely to fail.

## Complexity And Tradeoffs

- often easier to implement than the strongest deterministic alternative
- depends on expected time or low failure probability

## Common Mistakes

- using randomness without understanding what is probabilistic
- forgetting to seed or isolate random state carefully
- choosing randomized tools when a simpler deterministic solution already exists

## Go Deeper

- Course: [MIT Randomized Algorithms](https://courses.csail.mit.edu/6.856/current/)
- Reference: [CP-Algorithms - Randomized Treap](https://cp-algorithms.com/data_structures/treap.html)

## Related Topics

- [Algorithm Engineering](../algorithm-engineering/README.md)
- [Complexity And Hardness](../complexity-and-hardness/README.md)
