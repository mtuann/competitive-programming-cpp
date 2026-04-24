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

## Start Here If You Are New

If local C++ practice still feels shaky, do not browse randomly. Use this very small route:

1. [C++ Language For Contests](cpp-language/README.md)
2. [Foundations ladders](../../practice/ladders/foundations/README.md)
3. [Foundations Cheatsheet](../../notebook/foundations-cheatsheet.md)

The idea is simple:

- learn one compile/run loop
- solve one tiny anchor note
- only then widen the toolkit

## How To Use This Section

Treat foundations as a loop, not a one-time read:

1. read one tutorial page until the core idea feels simple
2. open the matching ladder and solve one warm-up or anchor note
3. keep one tiny template or pattern in your head, not ten
4. after each bug, come back here and tighten the habit that failed

The supporting layers in this repo are:

- `topics/`: the teaching pages
- `practice/ladders/`: practice order and anchor notes
- `templates/`: compact code you should be able to recognize quickly
- `notebook/`: short reminders for review and contest-time recall

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

## Suggested First Route

If you are new enough that even local C++ workflow still feels shaky, this is the cleanest order:

1. [C++ Language For Contests](cpp-language/README.md)
2. [Reasoning And Implementation Discipline](reasoning/README.md)
3. [Sorting](patterns/sorting/README.md)
4. [Binary Search](patterns/binary-search/README.md)
5. [Prefix Sums](patterns/prefix-sums/README.md)
6. [Difference Arrays](patterns/difference-arrays/README.md)
7. [Two Pointers](patterns/two-pointers/README.md)

This route works well because:

- C++ language removes syntax friction first
- reasoning gives you a way to debug and justify code
- sorting and binary search teach order and invariants early
- prefix sums and difference arrays teach precompute vs update thinking
- two pointers trains monotone scans and window discipline

## First Repo Notes To Open

If you want actual internal notes instead of only theory pages, start with:

1. [Missing Number](../../practice/ladders/foundations/cpp-language/missingnumber.md)
2. [Distinct Numbers](../../practice/ladders/foundations/stl/distinctnumbers.md)
3. [Increasing Array](../../practice/ladders/foundations/complexity-and-invariants/increasingarray.md)
4. [Movie Festival](../../practice/ladders/foundations/sorting/moviefestival.md)
5. [Factory Machines](../../practice/ladders/foundations/binary-search/factorymachines.md)
6. [Static Range Sum Queries](../../practice/ladders/foundations/prefix-sums/staticrangesumqueries.md)
7. [Apartments](../../practice/ladders/foundations/two-pointers/apartments.md)

That order gives a smoother beginner climb than jumping straight into harder multi-pattern tasks.

## Starter Toolkit

Open these alongside the tutorial pages:

- [Foundations ladders](../../practice/ladders/foundations/README.md)
- [Template Library](../../template-library.md)
- [Foundations Cheatsheet](../../notebook/foundations-cheatsheet.md)

Use them in different roles:

- tutorial page -> slower explanation
- ladder -> what to solve next
- cheatsheet -> what to remember during implementation
- template library -> which snippet to borrow once the pattern is clear

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
- Notes: [Foundations Cheatsheet](../../notebook/foundations-cheatsheet.md)
