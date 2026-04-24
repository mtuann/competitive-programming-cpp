# Reasoning And Implementation Discipline

This page is the bridge between “I know the technique” and “I can explain why this implementation is correct.” It is one of the highest-leverage topics in the repo because many contest failures are really reasoning failures in disguise.

## Summary

Spend time here if:

- your code works on samples but breaks on hidden tests
- you get off-by-one errors in binary search, prefix sums, or two pointers
- you can repeat an editorial idea but cannot explain why it works
- your debugging process feels random instead of systematic

The outcome to aim for:

- you can state what each variable means
- you can describe the loop or state invariant
- you can estimate complexity before coding
- you can test edge cases deliberately instead of hoping the sample is enough

## Prerequisites

- [C++ Language For Contests](../cpp-language/README.md)

## Core Idea

Most contest bugs come from missing invariants, unclear state meaning, or ignored boundary conditions.

The questions to ask constantly are:

- what does this variable mean right now?
- what stays true after each iteration or transition?
- why does the process stop in the correct state?
- what is the claimed complexity, and why is it believable?

If you cannot answer those questions, the code may still compile, but it is not under control.

## Theory / Proof Sketch

Five reasoning tools recur everywhere in competitive programming:

### 1. Invariants

An invariant is something that remains true throughout a loop, sweep, or recursive process.

Example:

```text
Before processing a[i], pref[i - 1] is the sum of the first i - 1 values.
After processing a[i], pref[i] is the sum of the first i values.
```

### 2. Induction On Processed Work

This is the natural proof style for:

- DP
- prefix processing
- tree traversals
- divide and conquer

Typical shape:

```text
Assume the claim is true for smaller states or earlier positions.
Show one transition preserves correctness.
```

### 3. Exchange Arguments

This is common in sorting and greedy problems.

Typical shape:

```text
Take an optimal solution.
Show one local swap or reorder never hurts.
Repeat until the solution matches the desired structure.
```

### 4. Monotonicity

This powers binary search on answers.

Typical shape:

```text
If x works, then every larger value also works.
```

Without a monotone predicate, binary search is just guesswork.

### 5. Counterexample Thinking

When testing a solution idea, ask:

- what is the smallest input that could break this?
- what happens at empty, single-element, all-equal, or maximum-value cases?

This habit catches many wrong models before code is even written.

## Complexity And Tradeoffs

Always estimate before coding.

Useful rough habits:

- `O(n)` is usually fine up to about `1e6`
- `O(n log n)` is the normal contest workhorse
- `O(n^2)` is only safe for moderate `n`
- `O(2^n)` needs a very small `n`
- recursion depth itself can be a limitation even when the asymptotic bound looks fine

Instead of memorizing one fixed table, estimate:

- how many states or loop iterations exist
- what each transition costs
- whether sorting or hashing changes the constant factor significantly
- how much memory the state table or graph needs

## Canonical C++ Pattern

Before or while coding, write a tiny contract for the solution:

```text
State:
Invariant:
Boundary convention:
Complexity:
```

Examples:

```text
Binary search:
l is bad
r is good
answer lies in (l, r]
```

```text
Two pointers:
window is [l, r]
current_sum is the sum on that window
all moves preserve the target predicate
```

```text
DP:
dp[i][j] = answer for the first i items with extra parameter j
```

This is often enough to prevent half the common bugs.

## Two-Minute Pre-Code Routine

Before writing the full solution, force yourself to answer five short questions:

1. what does the state or main variable mean?
2. what stays true after each iteration?
3. what is the boundary convention?
4. what is the time and memory cost?
5. what is one tiny case that could break the model?

This sounds small, but it is one of the fastest ways to reduce wrong-answer churn for beginner and intermediate problems.

## Worked Examples

### Example 1: prefix sums

Definition:

```text
pref[i] = a[1] + a[2] + ... + a[i]
```

Then:

```text
sum(l..r) = pref[r] - pref[l - 1]
```

Why it works:

- `pref[r]` includes everything up to `r`
- subtracting `pref[l - 1]` removes the prefix before `l`

The implementation bug risk is almost always indexing convention, not the formula.

### Example 2: binary search on answer

Suppose `check(x)` is monotone.

Maintain:

```text
l = a bad value
r = a good value
```

Then shrink until they are adjacent.

The key proof obligation is not the loop itself. It is proving that:

- the initial endpoints are valid
- the update preserves the bad/good split

### Example 3: greedy after sorting

In interval scheduling:

- sort by finishing time
- take the earliest finishing compatible interval

Why this is safe:

- if an optimal solution does not take the earliest finishing compatible interval first, swapping that first chosen interval with the earlier-finishing one never reduces future room

That is an exchange argument.

## Debugging Discipline

When a solution fails, check in this order:

1. is the model correct?
2. is the state meaning precise?
3. are the boundaries consistent?
4. is there overflow?
5. does one tiny custom case break the invariant?

This is much better than randomly editing lines until the sample passes again.

## Small-Case Test Routine

For foundations-level problems, a very good default is:

- one smallest legal input
- one all-equal case
- one already-good case
- one case that forces the repair logic or boundary update

Examples:

- binary search: smallest bad/good split you can think of
- prefix sums: one query touching the left boundary
- two pointers: one window that becomes invalid immediately
- greedy scan: one case where the tempting local choice is wrong

## Recognition Cues

You should revisit this topic when:

- you write code faster than you can justify it
- many of your bugs are one-line boundary mistakes
- you repeatedly say “the idea is right, but implementation is hard”
- you do not yet have a stable way to test or explain your own loops and states

This topic is often confused with “proofs are only for olympiad theory.” In practice, small proof habits are one of the most practical debugging tools in CP.

## Common Mistakes

- writing transitions before the state meaning is precise
- mixing half-open and closed intervals without noticing
- using binary search without checking monotonicity
- proving the algorithm informally but not the actual implementation
- trusting samples too much and not creating edge cases

## Practice Ladder

- [Complexity and invariants ladder](../../../practice/ladders/foundations/complexity-and-invariants/README.md)
- [Binary search ladder](../../../practice/ladders/foundations/binary-search/README.md)
- [Prefix sums ladder](../../../practice/ladders/foundations/prefix-sums/README.md)
- [Two pointers ladder](../../../practice/ladders/foundations/two-pointers/README.md)

Suggested order:

1. explain one accepted prefix-sum solution line by line
2. write binary search with explicit bad/good endpoints
3. annotate one two-pointer solution with its maintained invariant
4. write a one-paragraph proof sketch before coding one greedy problem

## Go Deeper

- Course: [Stanford CS161](https://cs161-stanford.github.io)
- Course: [Cornell CS 4820](https://www.cs.cornell.edu/courses/cs4820/2025sp/syllabus/)
- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Practice: [AtCoder Educational DP Contest](https://atcoder.jp/contests/dp)
- Notes: [Markdown Math Style](../../../docs/authoring/markdown-math-style.md)

## Related Topics

- [Binary Search](../patterns/binary-search/README.md)
- [Prefix Sums](../patterns/prefix-sums/README.md)
- [Two Pointers](../patterns/two-pointers/README.md)
- [Sorting](../patterns/sorting/README.md)
