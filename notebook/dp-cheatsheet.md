# DP Cheatsheet

Use this page when the state is close, but you still need to stabilize what each transition is allowed to remember.

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
- digits with tight constraints -> digit DP
- intervals shrink from both ends -> interval DP
- moving window contributes a min / max / median -> combine DP thinking with a window structure

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
