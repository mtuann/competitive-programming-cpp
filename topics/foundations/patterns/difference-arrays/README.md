# Difference Arrays

Difference arrays are the offline sibling of prefix sums. They are the right tool when you need many range additions and only need the final values after all updates.

## Prerequisites

- [Prefix Sums](../prefix-sums/README.md)

## When To Suspect It

- many range updates
- no need to answer intermediate queries
- you only need the final array or one final scan

## Core Idea

Instead of adding `x` to every position in `[l, r]`, store only the change points:

```text
diff[l] += x
diff[r + 1] -= x
```

Then rebuild the final values with a prefix sum:

```text
a[i] = a[i - 1] + diff[i]
```

## Theory / Proof Sketch

Each update starts contributing at `l` and stops contributing after `r`.

When you take the prefix sum of the difference array, every active update is counted exactly on the positions where it should apply.

## Complexity And Tradeoffs

- each range update: `O(1)`
- rebuild: `O(n)`
- memory: `O(n)`

Tradeoffs:

- perfect for offline updates
- not enough when you need online query/update interleaving

## Canonical C++ Pattern

Template in this repo:

- [difference-array.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/difference-array.cpp)

## Worked Examples

Example 1: many interval increments

- apply all changes in `O(q)`
- rebuild once in `O(n)`

Example 2: event sweep

- convert interval starts and ends into signed changes

## Common Mistakes

- forgetting the `r + 1` bound check
- rebuilding with the wrong initial value
- using this pattern when online queries are required

## Practice Ladder

- [Prefix sums ladder](../../../../practice/ladders/foundations/prefix-sums/README.md)

## Go Deeper

- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Practice: [CSES Problem Set](https://cses.fi/problemset/)

## Related Topics

- [Prefix Sums](../prefix-sums/README.md)
- [Fenwick Tree](../../../data-structures/fenwick-tree/README.md)
