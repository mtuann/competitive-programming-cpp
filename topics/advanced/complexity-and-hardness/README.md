# Complexity And Hardness

This page is not about memorizing complexity classes for their own sake. It is about building the instinct for what kinds of exact solutions are realistic in contest settings.

## Prerequisites

- [Reasoning And Proof Habits](../../foundations/reasoning/README.md)

## When To Suspect It

- the brute-force search space explodes combinatorially
- exact optimization looks intractable for large inputs
- the intended solution relies on small constraints, parameterization, or approximation

## Core Idea

Learn to classify problems by what kind of exact algorithm is plausible:

- polynomial
- pseudo-polynomial
- exponential on a small parameter
- likely intractable without extra structure

## Theory / Proof Sketch

Complexity classes explain why some tools recur:

- small-state DP because the parameter is small
- greedy because the structure is special
- approximation because exact optimization is too expensive in general

## Complexity And Tradeoffs

- the payoff is better modeling, not direct code
- this topic helps you stop chasing impossible exact formulations

## Common Mistakes

- treating NP-hardness as contest trivia instead of a modeling signal
- applying hardness language to problems whose constraints clearly enable exact solutions
- forgetting the role of pseudo-polynomial time

## Go Deeper

- Course: [Princeton COS 521](https://www.cs.princeton.edu/~hy2/teaching/fall25-cos521/index.html)
- Course: [Cornell CS 6820](https://www.cs.cornell.edu/courses/cs6820/2025fa/syllabus.html)

## Related Topics

- [Approximation And Relaxation](../approximation-and-relaxation/README.md)
- [Algorithm Engineering](../algorithm-engineering/README.md)
