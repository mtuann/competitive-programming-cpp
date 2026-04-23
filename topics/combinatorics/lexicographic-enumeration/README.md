# Lexicographic Enumeration

This topic is about counting or locating objects in lexicographic order without generating all of them explicitly.

## Prerequisites

- [Binary Search](../../foundations/patterns/binary-search/README.md)
- [DP Foundations](../../dp/foundations/README.md)

## When To Suspect It

- the statement asks for the `k`-th object
- lexicographic order matters
- brute-force generation is impossible, but counting a whole prefix or subtree is feasible

## Core Idea

At each step:

1. decide the next symbol, choice, or permutation block
2. count how many valid objects sit under that choice
3. skip whole blocks until you find the one containing the target

This is often “construct greedily, count with DP.”

## Theory / Proof Sketch

If choices are processed in lexicographic order and the counting function for each prefix is correct, then skipping complete prefixes preserves the target object.

## Complexity And Tradeoffs

- the hard part is usually the counting DP
- reconstruction is then linear in the output length times the branching factor

## Worked Examples

Example 1: `k`-th valid string under prefix constraints

Example 2: count valid permutations under a machine or automaton model

Example 3: [VOITSORT](../../../practice/ladders/combinatorics/lexicographic-enumeration/voitsort.md)

## Common Mistakes

- not capping counts when only comparisons with `k` matter
- processing choices in the wrong lexicographic order
- confusing “count exact suffixes” with “count all suffixes under a prefix”

## Practice Ladder

- [Lexicographic enumeration ladder](../../../practice/ladders/combinatorics/lexicographic-enumeration/README.md)

## Go Deeper

- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Practice: [VOITSORT note](../../../practice/ladders/combinatorics/lexicographic-enumeration/voitsort.md)

## Related Topics

- [DP Foundations](../../dp/foundations/README.md)
- [Binary Search](../../foundations/patterns/binary-search/README.md)
