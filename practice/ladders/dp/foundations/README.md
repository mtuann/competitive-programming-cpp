# DP Foundations Ladder

This ladder is about learning to design states deliberately, not just filling tables by pattern matching.

## Who This Is For

Use this ladder if:

- DP still feels like memorizing recurrences
- you struggle to explain what `dp[i]` or `dp[i][j]` actually means
- greedy ideas fail, but you are not yet sure what the state should be

## Warm-Up

- prefix DP
- one-dimensional maximize / minimize
- counting ways on prefixes

Target skill:

- write the state meaning before writing code

## Core

- reconstruction
- top-down vs bottom-up reformulation
- two-dimensional state design

Target skill:

- treat state, transition, and answer location as one coherent contract

## Stretch

- convert a statement into state meaning before coding
- compare a DP solution against a tempting greedy idea and explain why greedy fails

Target skill:

- reason about DP design instead of only recognizing familiar formulas

## Exit Criteria

You are ready to move on when:

- you can count states and transitions before implementation
- you know where the final answer lives
- you can compress memory only when dependencies allow it

## External Practice

- [AtCoder Educational DP Contest](https://atcoder.jp/contests/dp)
- [CP-Algorithms - Intro to DP](https://cp-algorithms.com/dynamic_programming/intro-to-dp.html)
- [USACO Guide](https://usaco.guide/)

## Tutorial Link

- [DP Foundations](../../../../topics/dp/foundations/README.md)

## Representative Solved Note

- [VMSCALE](vmscale.md): a minimax decision-tree DP where the transition cost comes from balanced ternary rather than a uniform comparison price
