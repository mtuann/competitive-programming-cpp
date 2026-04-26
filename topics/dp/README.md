# Dynamic Programming

Dynamic programming is about choosing a state that captures exactly what still matters. This area matters because many contest problems look different on the surface but collapse into the same state-transition mindset.

## Subtopics

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
- interval DP

3. Advanced later
- SOS / subset-superset transforms on the full mask cube
- xor / subset-style boolean-cube transforms after plain SOS sweeps stop being enough
- one huge boolean reachability row where word-packed shift-OR beats scalar subset-sum DP
- broken profile / frontier-mask DP on grids
- optimization techniques such as divide-and-conquer DP
- Knuth-style or other stronger interval / partition optimizations
- convex hull trick / Li Chao tree
- slope trick for convex piecewise-linear position/value DP
- Lagrangian relaxation / Aliens trick when exact `K` is the expensive dimension
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

## Solved Examples In This Repo

- [TFIELD - Ruộng bậc thang](../../practice/ladders/dp/sliding-window/tfield.md): weighted window reasoning over sorted polygon layers
- [Compatible Numbers](../../practice/ladders/dp/sos-dp/compatiblenumbers.md): complement-mask witness propagation over the full boolean cube
- [Bitwise XOR Convolution](../../practice/ladders/dp/fwht-subset-convolution/bitwisexorconvolution.md): xor-combining two full mask functions by Walsh-Hadamard transform
- [School Excursion](../../practice/ladders/dp/bit-parallelism/schoolexcursion.md): DSU component sizes reduced to one packed subset-sum reachability row
- [Ciel and Gondolas](../../practice/ladders/dp/divide-and-conquer-dp/cielandgondolas.md): partition DP with precomputed interval cost and monotone split optimization
- [Knuth Division](../../practice/ladders/dp/knuth-optimization/knuthdivision.md): merge-style interval DP where the split search shrinks to the Knuth window
- [Line Add Get Min](../../practice/ladders/dp/cht-li-chao/lineaddgetmin.md): direct online line-container verifier for the full-domain branch of the affine-DP family
- [Snuketoon](../../practice/ladders/dp/slope-trick/snuketoon.md): convex position-DP maintained by slope trick with one-sided penalties and bounded movement
- [Red and Blue Lamps](../../practice/ladders/dp/lagrangian-relaxation/redandbluelamps.md): exact-`R` path selection recovered from a penalized linear DP

## Go Deeper

- Course: [Stanford CS161](https://cs161-stanford.github.io)
- Course: [Cornell CS 4820](https://www.cs.cornell.edu/courses/cs4820/2025sp/syllabus/)
- Practice: [AtCoder](https://atcoder.jp/)
- Reference: [USACO Guide](https://usaco.guide/)
