# Dynamic Programming

Dynamic programming is about choosing a state that captures exactly what still matters.

## Use This Area When

- greedy feels unsafe but the remaining information can be summarized
- the answer depends on overlapping subproblems
- the real challenge is state design, not raw graph traversal or data-structure maintenance

## Start With One Route

| If your bottleneck is... | Open first | Then |
| --- | --- | --- |
| you still need the DP mindset itself | [DP Foundations](foundations/README.md) | [Knapsack Family](knapsack-family/README.md) |
| subset-state problems | [Bitmask DP](bitmask-dp/README.md) | [SOS DP](sos-dp/README.md), [FWHT / XOR Convolution / Subset Convolution](fwht-subset-convolution/README.md) |
| structural state on trees or ranges | [Tree DP](tree-dp/README.md) | [Interval DP](interval-dp/README.md), [Digit DP](digit-dp/README.md) |
| optimization-heavy DP | [Divide and Conquer DP](divide-and-conquer-dp/README.md) | [Knuth Optimization](knuth-optimization/README.md), [CHT / Li Chao](cht-li-chao/README.md) |

## Core Progression

1. `Core first`
- DP Foundations
- Knapsack Family
- Bitmask DP

2. `Then add`
- Tree DP
- Digit DP
- Interval DP
- SOS DP

3. `Deep later`
- FWHT / XOR Convolution / Subset Convolution
- Bit-Parallelism / Bitset Optimization
- Broken Profile / Plug DP
- Divide and Conquer DP / Knuth
- CHT / Li Chao / LineContainer
- Slope Trick / Aliens Trick

## Good First Repo Anchors

- [TFIELD](../../practice/ladders/dp/sliding-window/tfield.md)
- [Compatible Numbers](../../practice/ladders/dp/sos-dp/compatiblenumbers.md)
- [Bitwise XOR Convolution](../../practice/ladders/dp/fwht-subset-convolution/bitwisexorconvolution.md)
- [School Excursion](../../practice/ladders/dp/bit-parallelism/schoolexcursion.md)
- [Ciel and Gondolas](../../practice/ladders/dp/divide-and-conquer-dp/cielandgondolas.md)
- [Snuketoon](../../practice/ladders/dp/slope-trick/snuketoon.md)

## Browse All Subtopics

- [DP Foundations](foundations/README.md)
- [Knapsack Family](knapsack-family/README.md)
- [Bitmask DP](bitmask-dp/README.md)
- [SOS DP](sos-dp/README.md)
- [FWHT / XOR Convolution / Subset Convolution](fwht-subset-convolution/README.md)
- [Bit-Parallelism / Bitset Optimization](bit-parallelism/README.md)
- [Broken Profile / Plug DP](broken-profile/README.md)
- [Tree DP](tree-dp/README.md)
- [Digit DP](digit-dp/README.md)
- [Interval DP](interval-dp/README.md)
- [Divide and Conquer DP](divide-and-conquer-dp/README.md)
- [Knuth Optimization](knuth-optimization/README.md)
- [Convex Hull Trick / Li Chao Tree](cht-li-chao/README.md)
- [Slope Trick](slope-trick/README.md)
- [Lagrangian Relaxation / Aliens Trick](lagrangian-relaxation/README.md)

## Go Deeper

- Course: [Stanford CS161](https://cs161-stanford.github.io)
- Course: [Cornell CS 4820](https://www.cs.cornell.edu/courses/cs4820/2025sp/syllabus/)
- Practice: [AtCoder](https://atcoder.jp/)
- Reference: [USACO Guide](https://usaco.guide/)
