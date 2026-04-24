# Complexity And Hardness Ladder

## Who This Is For

Use this ladder when you want better judgment about what kinds of exact algorithms are realistic, not just better coding speed.

## Warm-Up

- compare polynomial vs exponential state spaces
- identify small parameters and pseudo-polynomial structure

## Core

- hardness as a modeling signal
- exact vs restricted vs approximate thinking

## Repo Case Study

- [Book Shop](../../dp/knapsack-family/bookshop.md): use it as the internal anchor for pseudo-polynomial reasoning before pushing deeper into theory material.
- [VMMARBLE](../../dp/bitmask-dp/vmmarble.md): a strong small-`n` exact-search compare point.
- [Counting Numbers](../../dp/digit-dp/countingnumbers.md): a reminder that enormous value ranges can still be tractable when the real state space is structured.

## Stretch

- parameterized exact algorithms
- pseudo-polynomial vs truly polynomial reasoning

## Compare Points

- pseudo-polynomial exact DP -> [Book Shop](../../dp/knapsack-family/bookshop.md)
- small-state exact search -> [VMMARBLE](../../dp/bitmask-dp/vmmarble.md)
- structured state compression -> [Counting Numbers](../../dp/digit-dp/countingnumbers.md)
- theory companions -> [Complexity And Hardness](../../../../topics/advanced/complexity-and-hardness/README.md) and [DP Foundations](../../../../topics/dp/foundations/README.md)

Use this ladder to build judgment, not only theorem vocabulary:

1. compare one pseudo-polynomial success
2. compare one small-`n` exponential success
3. compare one structured DP that looks impossible before the right state appears

## Exit Criteria

You are ready to move on when you can:

- explain why a brute-force model is doomed before coding it
- distinguish pseudo-polynomial from polynomial time
- spot when a small parameter changes feasibility completely
- use hardness intuition to reformulate a problem instead of thrashing

## External Reading / Courses

- [Princeton COS 521](https://www.cs.princeton.edu/~hy2/teaching/fall25-cos521/index.html)
- [Cornell CS 6820](https://www.cs.cornell.edu/courses/cs6820/2025fa/syllabus.html)

## Tutorial Link

- [Complexity And Hardness](../../../../topics/advanced/complexity-and-hardness/README.md)
