# Dynamic Programming

Dynamic programming is about choosing a state that captures exactly what still matters. This area matters because many contest problems look different on the surface but collapse into the same state-transition mindset.

## Entry

- Prereqs: [Foundations](../foundations/README.md)
- Defer for later: DP optimizations and niche advanced variants until state design feels natural

## Learn In Order

1. Core now
- classic 1D / 2D DP
- state meaning and transition design
- knapsack family

2. Contest core
- bitmask DP
- tree DP
- digit DP

3. Advanced later
- optimization techniques
- rerooting-style DP patterns
- profile and divide-and-conquer style DP

## Recognition Cues

- the answer depends on overlapping subproblems
- greedy choices feel unsafe but small state summaries seem possible
- the problem asks for best value, count of ways, or feasibility over prefixes, subsets, or subtrees

## Common Pitfalls

- defining a state that is too vague or too large
- writing transitions before the state meaning is precise
- using DP where a simpler greedy or graph model is enough

## Exit Criteria

After this section, you should be able to define states deliberately, justify transition correctness, and move from classic DP to structured variants without treating each one as a separate trick.

## Go Deeper

- Course: [Stanford CS161](https://cs161-stanford.github.io)
- Course: [Cornell CS 4820](https://www.cs.cornell.edu/courses/cs4820/2025sp/syllabus/)
- Practice: [AtCoder](https://atcoder.jp/)
- Reference: [USACO Guide](https://usaco.guide/)
