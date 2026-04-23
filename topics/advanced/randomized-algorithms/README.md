# Randomized Algorithms

Randomized algorithms belong in the advanced layer because they teach a different way to reason: "very likely correct and fast" rather than purely worst-case deterministic guarantees.

## Prerequisites

- [Reasoning And Proof Habits](../../foundations/reasoning/README.md)
- [Algorithm Engineering](../algorithm-engineering/README.md)

## When To Suspect It

- deterministic structure is awkward, but random sampling simplifies it
- hashing, treaps, or randomized pivots appear naturally
- the problem admits a high-probability guarantee
- a clean expected-time solution is much simpler than the strongest deterministic one

## Core Idea

Use randomness either to:

- simplify a data structure
- balance expected performance
- sample a representative witness
- avoid adversarial worst-case structure

In contest settings, the most common uses are:

- random priorities in treaps
- randomized hashing/fingerprints
- randomized pivot or partition choices
- randomized verification and stress generation

## Theory / Proof Sketch

The proof style changes from exact deterministic invariants to expectation or high-probability arguments. You must identify:

1. the random experiment
2. the bad event
3. why that bad event is unlikely or has bounded expected cost

Typical proof targets:

- expected running time
- expected balance
- collision probability
- success probability after one or more trials

## Complexity And Tradeoffs

- often easier to implement than the strongest deterministic alternative
- depends on expected time or low failure probability

Tradeoffs:

- elegant and practical in contests
- requires comfort with probability-style reasoning
- some users and judges prefer deterministic solutions when both are easy

## Canonical Pattern

Typical workflow:

1. define what is random
2. isolate the failure event or costly event
3. bound its probability or expected contribution
4. keep the implementation reproducible enough for debugging

Common examples:

- treap priority chosen uniformly at insertion
- rolling hash base/mod strategy treated as low-collision fingerprinting
- randomized test generator used to destroy weak assumptions

## Worked Examples

Example 1: treap balancing

Random priorities make the expected tree height logarithmic.

Example 2: hashing collision risk

One hash is probabilistic; two independent hashes make collisions much less likely.

Example 3: randomized stress testing

Generate many small random cases and compare a fast solution against a brute-force checker.

## Recognition Cues

- expected-time arguments are acceptable
- a deterministic structure exists but is much harder to implement
- collision probability or witness sampling is part of the intended solution
- the editorial language uses "with high probability" or "in expectation"

## Common Mistakes

- using randomness without understanding what is probabilistic
- forgetting to seed or isolate random state carefully
- treating probabilistic equality as absolute proof
- choosing randomized tools when a simpler deterministic solution already exists
- mixing debugging randomness and production randomness in confusing ways

## Standard Variants

- expected-balance data structures
- randomized selection or partitioning
- fingerprinting / hashing
- Monte Carlo vs Las Vegas algorithms
- randomized verification and test generation

## Practice Ladder

- [Randomized algorithms ladder](../../../practice/ladders/advanced/randomized-algorithms/README.md)

## Go Deeper

- Course: [MIT Randomized Algorithms](https://courses.csail.mit.edu/6.856/current/)
- Course: [Berkeley CS174](https://people.eecs.berkeley.edu/~sinclair/cs174/s25.html)
- Reference: [CP-Algorithms - Randomized Treap](https://cp-algorithms.com/data_structures/treap.html)
- Reference: [CP-Algorithms - String Hashing](https://cp-algorithms.com/string/string-hashing.html)

## Related Topics

- [Algorithm Engineering](../algorithm-engineering/README.md)
- [Complexity And Hardness](../complexity-and-hardness/README.md)
