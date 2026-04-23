# Approximation And Relaxation

Approximation and relaxation topics matter when exact optimization is too expensive, but you still want provable structure and useful bounds.

## Prerequisites

- [Complexity And Hardness](../complexity-and-hardness/README.md)
- [Algorithm Engineering](../algorithm-engineering/README.md)

## When To Suspect It

- the exact formulation is too expensive in general
- you see fractional, dual, or greedy-with-bound reasoning
- the goal is algorithmic maturity beyond the contest core

## Core Idea

Relax the hard problem into one that is easier to solve or analyze, then round or compare against the relaxed optimum.

## Theory / Proof Sketch

A relaxation provides a benchmark or certificate:

- LP or fractional optimum
- greedy charging argument
- local-ratio or primal-dual reasoning

## Complexity And Tradeoffs

- high theory value
- lower immediate CP return than graph/DP core topics

## Common Mistakes

- studying approximation too early instead of finishing contest fundamentals
- focusing on theorem statements without one concrete worked example

## Go Deeper

- Course: [Berkeley CS174](https://people.eecs.berkeley.edu/~sinclair/cs174/s25.html)
- Course: [Oxford Approximation Algorithms notes](https://www.cs.ox.ac.uk/teaching/courses/2025-2026/approxalg/)

## Related Topics

- [Complexity And Hardness](../complexity-and-hardness/README.md)
- [Randomized Algorithms](../randomized-algorithms/README.md)
