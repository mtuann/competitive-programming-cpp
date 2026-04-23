# Z-Function

The Z-function is another exact linear-time string tool. It is especially clean for questions about matches against the whole prefix.

## Prerequisites

- [KMP](../kmp/README.md)

## When To Suspect It

- you want to know how much the prefix matches at every position
- the problem is about borders, repetitions, or prefix matches
- a concatenation like `pattern + '#' + text` suggests itself naturally

## Core Idea

Define:

```text
z[i] = longest length such that s[0..z[i)-1] = s[i..i+z[i)-1]
```

Maintain the current best `[l, r)` segment already known to match the prefix.

## Theory / Proof Sketch

If `i` lies inside a known matching segment, part of `z[i]` is inherited for free. Only the part extending beyond the segment requires new comparisons, which keeps the total work linear.

## Complexity And Tradeoffs

- build Z array: `O(n)`

Tradeoffs:

- often simpler than KMP for prefix-match tasks
- not the first tool people learn, so it is easy to overlook

## Canonical Pattern

Template in this repo:

- [z-function.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/z-function.cpp)

## Worked Examples

Example 1: pattern matching via concatenation

Example 2: counting prefix occurrences

Example 3: detecting periodic structure

## Common Mistakes

- mixing inclusive and exclusive `r`
- forgetting that `z[0]` is usually set to `0` by convention
- using Z where KMP border chaining is more direct

## Practice Ladder

- [Z-function ladder](../../../practice/ladders/strings/z-function/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Z-Function](https://cp-algorithms.com/string/z-function.html)
- Reference: [OI Wiki - Z Function](https://en.oi-wiki.org/string/z-func/)

## Related Topics

- [KMP](../kmp/README.md)
- [String Hashing](../hashing/README.md)
