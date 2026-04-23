# Algorithm Engineering

Algorithm engineering is the practical layer between theory and accepted submissions: model choice, constants, memory layout, debugging discipline, and test design.

## Prerequisites

- [C++ Language For Contests](../../foundations/cpp-language/README.md)
- [Reasoning And Proof Habits](../../foundations/reasoning/README.md)

## When To Suspect It

- the algorithm is correct but too slow or too fragile
- multiple implementations have the same big-O but very different real performance
- debugging and verification are dominating the work

## Core Idea

Strong contest performance is not just picking the right theorem. It is turning an idea into a reliable implementation with good constants and a good testing process.

## Theory / Proof Sketch

The invariant here is process-oriented:

- model first
- define the contract of each helper
- test small cases
- stress against a slower checker

## Complexity And Tradeoffs

- same asymptotic algorithm can win or lose depending on data layout and constant factors
- contest engineering choices can matter more than one layer of theory on old judges

## Common Mistakes

- tuning constants before checking the model
- optimizing the wrong bottleneck
- changing too many things without isolating bugs

## Go Deeper

- Practice: [Notebook](../../../notebook/README.md)
- Practice: [Contest Playbooks](../../../practice/contest-playbooks/README.md)
- Reference: [KACTL](https://github.com/kth-competitive-programming/kactl)

## Related Topics

- [Contest Engineering](../contest-engineering/README.md)
- [Randomized Algorithms](../randomized-algorithms/README.md)
