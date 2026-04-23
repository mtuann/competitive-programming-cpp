# Constructive

Constructive problems ask you to build an object, a sequence of moves, or a witness that satisfies the rules.

They often look loose at first, but the real task is usually to exploit one strong promise from the statement and turn it into a repeatable recipe.

## Summary

Suspect constructive work when:

- the output is a sequence of operations, not just a number
- the statement guarantees a solution exists
- you only need to print any valid answer, not an optimal one

What success looks like:

- you can isolate the one promise that makes the instance manageable
- you can explain why every printed move is legal
- your construction is simple enough to verify, not just to invent

## Prerequisites

- [Reasoning](../../foundations/reasoning/README.md)
- [Algorithm Engineering](../algorithm-engineering/README.md)

## Core Idea

Constructive problems usually become easier after you do one of these:

- reduce the state to a canonical form
- keep a small invariant alive while you build the answer
- search over a tiny promised structure instead of the full state space

The hard part is rarely code volume. It is choosing the right invariant.

## Theory / Proof Sketch

A constructive proof should answer three questions clearly:

1. Why does each step stay legal?
2. Why does the process terminate?
3. Why is the final state valid?

If one of those is hand-wavy, the solution is usually still too fragile.

## Complexity And Tradeoffs

Constructive solutions vary a lot, but the main tradeoff is usually:

- shorter proof and smaller search space
versus
- more general but much harder construction

When a statement gives a strong promise, the right move is often to build the simplest construction that uses that promise directly.

## Worked Example

- [VMCOINS](../../../practice/ladders/advanced/constructive/vmcoins.md)

This note uses the promise that two special coins are the only ones whose exact positions matter. That collapses the search from “arbitrary long move sequence” to “find the right translation and the last `0..2` legal moves”.

## Recognition Cues

- “print any solution”
- “it is guaranteed that a solution exists”
- “there exist special elements with a helpful property”

## Common Mistakes

- ignoring a strong promise and trying to solve a much more general problem
- printing a sequence without proving that every step is legal
- inventing a large simulation when a tiny overlap or invariant search is enough

## Practice Ladder

- [Constructive ladder](../../../practice/ladders/advanced/constructive/README.md)

## Go Deeper

- Reference: [USACO Guide](https://usaco.guide/)
- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Practice: [Codeforces constructive tag](https://codeforces.com/problemset?tags=constructive+algorithms)

## Related Topics

- [Algorithm Engineering](../algorithm-engineering/README.md)
- [Reasoning](../../foundations/reasoning/README.md)
