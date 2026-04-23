# Foundations

Foundations are the entry point for the whole repo. This area is about writing contest C++ comfortably, recognizing standard patterns, and building the proof habits that later topics assume.

## Subtopics

- [C++ Language For Contests](cpp-language/README.md)
- [Reasoning And Implementation Discipline](reasoning/README.md)
- Patterns:
  - [Sorting](patterns/sorting/README.md)
  - [Binary Search](patterns/binary-search/README.md)
  - [Prefix Sums](patterns/prefix-sums/README.md)
  - [Difference Arrays](patterns/difference-arrays/README.md)
  - [Two Pointers](patterns/two-pointers/README.md)

## Entry

- Prereqs: none beyond basic programming
- Defer for later: heavy data structures, graph theory, and advanced DP

## Learn In Order

1. Core now
- C++ workflow, STL, and debugging habits
- asymptotic analysis and time-complexity estimates
- sorting, binary search, prefix sums, difference arrays, two pointers

2. Contest core
- recursion and backtracking basics
- proof tools: invariants, induction, exchange arguments
- implementation discipline: edge cases, indexing, and overflow checks

3. Advanced later
- amortized reasoning
- recurrence analysis
- niche language and standard-library tricks

## Recognition Cues

- the bottleneck is basic implementation speed or language fluency
- the problem is solved by monotonic search, prefix precomputation, or sliding windows
- you know the idea informally but keep losing time to bugs or weak complexity estimates

## Common Pitfalls

- fighting the language instead of the algorithm
- using binary search without a clear invariant
- writing prefix or two-pointer code without a precise meaning for each variable

## Exit Criteria

After this section, you should be able to write clean C++ for standard beginner and lower-intermediate problems, estimate the complexity honestly, and explain why your implementation is correct.

## Go Deeper

- Course: [MIT 6.1210 / 6.1220](https://student.mit.edu/catalog/archive/fall/m6a.html)
- Course: [Stanford CS161](https://cs161-stanford.github.io)
- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Practice: [CSES Problem Set](https://cses.fi/)
