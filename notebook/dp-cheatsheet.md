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

## Core Invariant

The state must remember exactly the information needed for future decisions, and nothing more.

If two histories are indistinguishable for all future transitions, they should collapse into the same state.

## Window-Flavored DP

Useful snippets when a DP or greedy transition needs the best value over a recent window:

- monotone minimum -> [monotonic-deque-min.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/monotonic-deque-min.cpp)
- lower median / balanced split -> [sliding-median-two-multisets.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/sliding-median-two-multisets.cpp)

Repo anchor:

- [TFIELD](../practice/ladders/dp/sliding-window/tfield.md)

## Safety Checks

- base case
- final answer location
- overflow type
- reconstruction needs parent or choice arrays

## Main Trap

The classic DP bug is not syntax. It is a state that silently throws away information the future still needs, or an iteration order that reads values before they are ready.

## Reopen Paths

- topic pages -> [DP Foundations](../topics/dp/foundations/README.md), [Digit DP](../topics/dp/digit-dp/README.md), [Tree DP](../topics/dp/tree-dp/README.md), [Interval DP](../topics/dp/interval-dp/README.md)
- exact quick sheet -> [Digit DP hot sheet](digit-dp-hot-sheet.md)
- repo anchors -> [Counting Numbers](../practice/ladders/dp/digit-dp/countingnumbers.md), [Removal Game](../practice/ladders/dp/interval-dp/removalgame.md), [Tree Matching](../practice/ladders/dp/tree-dp/treematching.md)
