# Probability Hot Sheet

Use this sheet when the statement itself defines a random experiment and the answer is one exact probability or expected value.

## Do Not Use When

- the algorithm is randomized rather than the statement -> [Randomized Algorithms](../topics/advanced/randomized-algorithms/README.md)
- the task is really deterministic counting or DP in disguise
- you only need one parity / invariant shortcut and no probability mass at all
- the intended route is continuous probability beyond standard contest finite-state modeling

## Choose By Signal

- repeated discrete trials with bounded total sum/state -> PMF DP
- expected value of a statistic once you can write its distribution -> weighted sum from that PMF
- expected value of a sum of local indicators -> linearity of expectation first
- solver randomness / failure probability / expected runtime -> [Randomized Algorithms](../topics/advanced/randomized-algorithms/README.md)

## Core Invariants

- total probability mass stays `1`
- each transition contributes `current_mass * transition_probability`
- expectation is `sum(value * probability)`
- many contest expectation tasks are shorter through linearity than through full joint distributions

## Main Traps

- simulating instead of computing exact probabilities
- confusing probability of an event with expected value of a random variable
- forgetting to check that all outgoing probabilities from a state sum correctly
- losing precision through repeated floating accumulation when `long double` is safer

## Exact Starter In This Repo

- exact starter -> [probability-distribution-dp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/probability-distribution-dp.cpp)
- flagship in-lane rep -> [Dice Probability](../practice/ladders/math/probability/diceprobability.md)
- compare points -> [Candy Lottery](https://cses.fi/problemset/task/1727/), [Moving Robots](https://cses.fi/problemset/task/1726/)

## Reopen Paths

- full topic page -> [Probability](../topics/math/probability/README.md)
- compare against solver-side randomness -> [Randomized Algorithms](../topics/advanced/randomized-algorithms/README.md)
- DP recall -> [DP cheatsheet](dp-cheatsheet.md)
- snippet chooser -> [Template Library](../template-library.md)
- retrieval router -> [Build Kit](../docs/build-kit.md)
