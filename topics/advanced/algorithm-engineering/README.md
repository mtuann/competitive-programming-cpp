# Algorithm Engineering

Algorithm engineering is the practical layer between theory and accepted submissions: model choice, constants, memory layout, debugging discipline, and test design.

## Prerequisites

- [C++ Language For Contests](../../foundations/cpp-language/README.md)
- [Reasoning And Proof Habits](../../foundations/reasoning/README.md)

## When To Suspect It

- the algorithm is correct but too slow or too fragile
- multiple implementations have the same big-O but very different real performance
- debugging and verification are dominating the work
- the bottleneck is now systems-level detail rather than missing theory

## Core Idea

Strong contest performance is not just picking the right theorem. It is turning an idea into a reliable implementation with good constants and a good testing process.

Typical concerns:

- data layout
- memory traffic
- branchiness
- recursion depth
- I/O strategy
- reproducible debugging workflow

## Theory / Proof Sketch

The invariant here is process-oriented:

- model first
- define the contract of each helper
- test small cases
- stress against a slower checker
- optimize only after the bottleneck is known

This topic is less about proving a theorem and more about preserving correctness while moving from idea to accepted code.

## Complexity And Tradeoffs

- same asymptotic algorithm can win or lose depending on data layout and constant factors
- contest engineering choices can matter more than one layer of theory on old judges

Tradeoffs:

- high practical ROI
- easy to waste time micro-optimizing the wrong layer
- best combined with disciplined verification, not guesswork

## Canonical Pattern

Useful workflow:

1. write the clearest correct version
2. make a brute-force checker if possible
3. stress on small random cases
4. profile mentally or empirically for the bottleneck
5. optimize the bottleneck without rewriting everything at once

## Worked Examples

Example 1: same big-O, different constants

Flat arrays and contiguous edges often beat nested vectors or maps in tight graph routines.

Example 2: bug isolation through brute-force comparison

A small correct checker plus random tests catches more issues than ad hoc manual inputs.

Example 3: layout-aware implementation

Old judges often reward iterative loops, contiguous storage, and reduced allocation churn.

## Repo Case Studies

- [FFLOW](../../../practice/ladders/graphs/flow/fflow.md): a flow solution that leans into flat edge arrays, manual queues, and capacity scaling.
- [PRAVO](../../../practice/ladders/geometry/right-triangles/pravo.md): a geometry note with alternate buffered variants that is good for comparing engineering choices around the same core idea.

## Recognition Cues

- "should be AC, but TLE/MLE/WA keeps happening"
- two implementations of the same idea behave very differently
- your current blocker is robustness, not discovering the algorithm
- older judges or large constants make engineering details matter

## Common Mistakes

- tuning constants before checking the model
- optimizing the wrong bottleneck
- changing too many things without isolating bugs
- throwing away the clear version before a faster version is trusted
- using cleverness where a boring invariant would be safer

## Standard Variants

- memory/layout optimization
- faster I/O and parsing
- iterative vs recursive implementation choices
- stress testing and brute-force checking
- judge-specific engineering traps

## Practice Ladder

- [Algorithm engineering ladder](../../../practice/ladders/advanced/algorithm-engineering/README.md)

## Go Deeper

- Practice: [Notebook](../../../notebook/README.md)
- Practice: [Contest Playbooks](../../../practice/contest-playbooks/README.md)
- Reference: [KACTL](https://github.com/kth-competitive-programming/kactl)
- Blog/reference: [CP-Algorithms](https://cp-algorithms.com/)
- Repo companion: [Contest Checklist](../../../notebook/contest-checklist.md)

## Related Topics

- [Contest Engineering](../contest-engineering/README.md)
- [Randomized Algorithms](../randomized-algorithms/README.md)
