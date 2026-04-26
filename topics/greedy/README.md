# Greedy

Greedy is where you stop asking "can I search all possibilities?" and start asking "what choice can I commit to now without painting myself into a corner later?"

In this repo, many beginner-friendly greedy ideas already live inside other sections:

- sorting-driven pairing in `foundations/sorting`
- pointer-style matching in `foundations/two-pointers`
- MST-style cut reasoning in `graphs/mst`

This area is for the more proof-first side of greedy: feasibility invariants, exchange arguments, and structures that repair local choices while preserving a global claim.

## Subtopics

- [Prefix Constraints](prefix-constraints/README.md)
- [Huffman / Data Compression](huffman-data-compression/README.md)

## Entry

- Prereqs: [Foundations](../foundations/README.md), especially [Sorting](../foundations/patterns/sorting/README.md) and [Reasoning](../foundations/reasoning/README.md)
- Start here if: you can code the obvious local choice, but you still struggle to justify why it stays globally safe
- Defer for later: if prefix sums, sorting, and invariant-writing still feel shaky

## Learn In Order

1. Core now
- sort by the quantity that makes feasibility easiest to state
- write the prefix invariant before writing the loop
- prove the local choice by an exchange or "largest safe so far" argument

2. Contest core
- combine greedy with heaps or ordered sets
- repair a local choice when a new item breaks feasibility
- reconstruct a witness, not just the objective value
- optimal merge trees and weighted-depth objectives like Huffman coding

3. Advanced later
- greedy with several interacting constraints
- geometry or flow flavored exchange arguments
- matroid-style or proof-heavy greedy theory

## Recognition Cues

- every prefix or partial solution must stay feasible
- one locally best choice looks plausible, but only if you can explain why
- a heap or ordered structure can "undo" the worst currently chosen item
- the task repeatedly merges the two lightest weights and the objective is weighted depth or merge cost
- DP feels too heavy because the state would only encode a monotone feasibility condition

## Common Pitfalls

- coding the choice rule before stating the invariant
- proving only that the chosen step looks good, not that bad alternatives can be swapped away
- mixing "maximize accepted items" with "minimize rejected items" without rephrasing the same invariant
- forgetting that many greedy problems are really about ordering the input first

## Exit Criteria

After this section, you should be able to:

- write the greedy choice in one sentence
- identify the feasibility condition that must remain true after every step
- explain the proof idea without relying on simulation alone
- tell when a heap or offline sorting pass is the missing ingredient

## Solved Examples In This Repo

- [Lemonade Line](../../practice/ladders/greedy/prefix-constraints/lemonadeline.md): order tolerant cows first so the line stays as small as possible
- [Prefix Sum Addicts](../../practice/ladders/greedy/prefix-constraints/prefixsumaddicts.md): turn sorted-prefix feasibility into monotone difference checks
- [VODIVIDE - Chia phần](../../practice/ladders/greedy/prefix-constraints/vodivide.md): maintain the cheapest feasible chosen set under a prefix quota
- [Huffman Coding Benchmark](../../practice/ladders/greedy/huffman-data-compression/huffmancoding.md): merge the two lightest subtrees until one optimal prefix-code tree remains

## Go Deeper

- Reference: [OI Wiki - Greedy](https://en.oi-wiki.org/basic/greedy/)
- Reference: [Competitive Programmer's Handbook](https://usaco.guide/CPH.pdf)
- Practice: [Greedy ladders](../../practice/ladders/greedy/README.md)
