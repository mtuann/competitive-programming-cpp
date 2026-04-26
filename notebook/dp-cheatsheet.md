# DP Cheatsheet

Use this page when the state is close, but you still need to stabilize what each transition is allowed to remember.

## Do Not Use When

- the problem is already greedy after sorting or scanning
- the real blocker is a missing graph / number-theory observation
- you still cannot say what the state forgets and what it must preserve

## Choose By Signal

- best answer on a prefix -> 1D DP
- extra small parameter on a prefix -> 2D or layered DP
- decimal representation with tight bound -> [Digit DP hot sheet](digit-dp-hot-sheet.md)
- shrinking subarray / interval -> interval DP
- subtree choices combine upward -> tree DP
- subsets or masks are the natural state -> bitmask DP
- one full mask cube needs all-submask or all-superset aggregates -> [SOS DP hot sheet](sos-dp-hot-sheet.md)
- two full mask functions combine by `xor`, or one exact subset split inside each mask is the real bottleneck -> [FWHT / XOR Convolution / Subset Convolution hot sheet](fwht-subset-convolution-hot-sheet.md)
- one huge boolean sum axis or component-size reachability row where word-packed shift-OR is the real implementation win -> [Bit-Parallelism / Bitset Optimization hot sheet](bit-parallelism-hot-sheet.md)
- one grid dimension is small and the state is the current frontier -> [Broken Profile hot sheet](broken-profile-hot-sheet.md)
- partition prefixes into groups with monotone best split points -> [Divide and Conquer DP hot sheet](divide-and-conquer-dp-hot-sheet.md)
- split-point interval DP with additive interval cost and monotone opt windows -> [Knuth Optimization hot sheet](knuth-optimization-hot-sheet.md)
- affine transition `m * x + b` over previous states -> [CHT / Li Chao hot sheet](cht-hot-sheet.md)
- one convex function over coordinate `x` is updated by hinge penalties or bounded argmin shifts -> [Slope Trick hot sheet](slope-trick-hot-sheet.md)
- exact `K` picks / segments become cheap after charging one integer penalty per use -> [Aliens Trick hot sheet](aliens-trick-hot-sheet.md)

## State Checklist

- what has been processed?
- what still matters?
- does the state forget any information needed later?

## Transition Checklist

- are all legal next moves covered?
- are any cases counted twice?
- what iteration order respects dependencies?

## Common Forms

```text
dp[i] = best answer on the first i elements
dp[i][j] = answer on prefix i with extra parameter j
```

## Retrieval Cues

- value or feasibility over prefixes -> classic 1D DP
- tree structure decides the subproblems -> tree DP
- digits with tight constraints -> [Digit DP hot sheet](digit-dp-hot-sheet.md)
- intervals shrink from both ends -> interval DP
- moving window contributes a min / max / median -> combine DP thinking with a window structure
- the answer for each mask needs all of its submasks or supersets -> [SOS DP hot sheet](sos-dp-hot-sheet.md)
- the answer needs one full-cube xor convolution or one subset-convolution family route -> [FWHT / XOR Convolution / Subset Convolution hot sheet](fwht-subset-convolution-hot-sheet.md)
- the DP is still boolean feasibility, but one wide sum axis should be packed and shifted wordwise -> [Bit-Parallelism / Bitset Optimization hot sheet](bit-parallelism-hot-sheet.md)
- local placements only depend on a small grid frontier -> [Broken Profile hot sheet](broken-profile-hot-sheet.md)
- one last segment `k + 1 .. i` plus monotone argmins -> [Divide and Conquer DP hot sheet](divide-and-conquer-dp-hot-sheet.md)
- one interval `[l, r]`, one split `k`, plus `cost(l, r)` only -> [Knuth Optimization hot sheet](knuth-optimization-hot-sheet.md)
- previous states become lines and current states become one query point -> [CHT / Li Chao hot sheet](cht-hot-sheet.md)
- the DP state itself is one convex piecewise-linear function of `x` -> [Slope Trick hot sheet](slope-trick-hot-sheet.md)
- the expensive exact-count dimension disappears after penalizing each use by `lambda` -> [Aliens Trick hot sheet](aliens-trick-hot-sheet.md)

## Core Invariant

The state must remember exactly the information needed for future decisions, and nothing more.

If two histories are indistinguishable for all future transitions, they should collapse into the same state.

## Window-Flavored DP

Useful snippets when a DP or greedy transition needs the best value over a recent window:

- monotone minimum -> [monotonic-deque-min.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/monotonic-deque-min.cpp)
- lower median / balanced split -> [sliding-median-two-multisets.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/sliding-median-two-multisets.cpp)

Repo anchor:

- [Sliding Window Minimum](../practice/ladders/dp/sliding-window/slidingwindowminimum.md)
- [TFIELD](../practice/ladders/dp/sliding-window/tfield.md)

## Safety Checks

- base case
- final answer location
- overflow type
- reconstruction needs parent or choice arrays

## Main Trap

The classic DP bug is not syntax. It is a state that silently throws away information the future still needs, or an iteration order that reads values before they are ready.

## Reopen Paths

- topic pages -> [DP Foundations](../topics/dp/foundations/README.md), [Digit DP](../topics/dp/digit-dp/README.md), [Tree DP](../topics/dp/tree-dp/README.md), [Interval DP](../topics/dp/interval-dp/README.md), [SOS DP](../topics/dp/sos-dp/README.md), [FWHT / XOR Convolution / Subset Convolution](../topics/dp/fwht-subset-convolution/README.md), [Bit-Parallelism / Bitset Optimization](../topics/dp/bit-parallelism/README.md), [Broken Profile / Plug DP](../topics/dp/broken-profile/README.md), [Divide and Conquer DP](../topics/dp/divide-and-conquer-dp/README.md), [Knuth Optimization](../topics/dp/knuth-optimization/README.md), [Convex Hull Trick / Li Chao Tree](../topics/dp/cht-li-chao/README.md), [Slope Trick](../topics/dp/slope-trick/README.md), [Lagrangian Relaxation / Aliens Trick](../topics/dp/lagrangian-relaxation/README.md)
- exact quick sheet -> [Digit DP hot sheet](digit-dp-hot-sheet.md), [SOS DP hot sheet](sos-dp-hot-sheet.md), [FWHT / XOR Convolution / Subset Convolution hot sheet](fwht-subset-convolution-hot-sheet.md), [Bit-Parallelism / Bitset Optimization hot sheet](bit-parallelism-hot-sheet.md), [Broken Profile hot sheet](broken-profile-hot-sheet.md), [Divide and Conquer DP hot sheet](divide-and-conquer-dp-hot-sheet.md), [Knuth Optimization hot sheet](knuth-optimization-hot-sheet.md), [CHT / Li Chao hot sheet](cht-hot-sheet.md), [Slope Trick hot sheet](slope-trick-hot-sheet.md), [Aliens Trick hot sheet](aliens-trick-hot-sheet.md)
- repo anchors -> [Counting Numbers](../practice/ladders/dp/digit-dp/countingnumbers.md), [Compatible Numbers](../practice/ladders/dp/sos-dp/compatiblenumbers.md), [Bitwise XOR Convolution](../practice/ladders/dp/fwht-subset-convolution/bitwisexorconvolution.md), [School Excursion](../practice/ladders/dp/bit-parallelism/schoolexcursion.md), [Removal Game](../practice/ladders/dp/interval-dp/removalgame.md), [Counting Tilings](../practice/ladders/dp/broken-profile/countingtilings.md), [Tree Matching](../practice/ladders/dp/tree-dp/treematching.md), [Tree Distances II](../practice/ladders/dp/tree-dp/treedistances2.md), [Ciel and Gondolas](../practice/ladders/dp/divide-and-conquer-dp/cielandgondolas.md), [Knuth Division](../practice/ladders/dp/knuth-optimization/knuthdivision.md), [Line Add Get Min](../practice/ladders/dp/cht-li-chao/lineaddgetmin.md), [Monster Game II](../practice/ladders/dp/cht-li-chao/monstergame2.md), [Snuketoon](../practice/ladders/dp/slope-trick/snuketoon.md), [Red and Blue Lamps](../practice/ladders/dp/lagrangian-relaxation/redandbluelamps.md)
