# Dice Probability

- Title: `Dice Probability`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1725](https://cses.fi/problemset/task/1725)
- Secondary topics: `Probability DP`, `Distributions`, `Expected value compare`
- Difficulty: `medium`
- Subtype: `Repeated finite distribution DP over bounded sums`
- Status: `solved`
- Solution file: [diceprobability.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/probability/diceprobability.cpp)

## Why Practice This

This is the cleanest in-repo anchor for the `Probability` lane because it forces the exact first route:

- one repeated random experiment
- one bounded integer state (the running sum)
- one probability query over a final PMF range

So the solution is neither simulation nor a fancy closed form.

It is:

1. build the distribution of sums after each throw
2. sum the probability mass in the requested interval

## Recognition Cue

Reach for probability-DP thinking when:

- the process repeats `n` times
- each step has a small finite support
- the state can be summarized by one bounded sum/value
- the question is exact probability of landing in some final range

The strongest smell is:

- "after `n` random steps, what is the probability that the total lies in `[a, b]`?"

That is exactly when a PMF table beats any simulation instinct.

## Problem-Specific Transformation

Let:

$$
dp[i][s] = \Pr(\text{sum } s \text{ after } i \text{ throws})
$$

Base case:

$$
dp[0][0] = 1
$$

Transition:

$$
dp[i+1][s+f] += \frac{dp[i][s]}{6}
$$

for each die face `f in {1,2,3,4,5,6}`.

The requested answer is then:

$$
\sum_{s=a}^{b} dp[n][s]
$$

So the random process becomes one deterministic DP over probability mass.

## Core Idea

Track the full distribution of the sum after each number of throws.

Each current sum `s` contributes its probability mass equally to:

- `s+1`
- `s+2`
- ...
- `s+6`

The invariant is:

```text
after processing i throws, dp[s] equals the exact probability that the current sum is s
```

Once the final row is built, range probability is just one summation.

The implementation below uses rolling arrays, because only the previous step is needed.

## Complexity

Let `max_sum = 6n`.

Then:

- states: `O(n * max_sum)`
- each state has `6` transitions
- total: `O(n * 6n * 6)` in the naive bound, which is fine for `n <= 100`
- memory: `O(6n)` with rolling arrays

## Pitfalls / Judge Notes

- Do not simulate random throws; exact DP is intended.
- Probability mass should stay very close to `1`.
- Use `long double` or careful `double` accumulation; repeated additions can amplify rounding noise.
- The final output wants six decimals.
- This is probability of an event, not expected value of the sum.

## Reusable Pattern

- Topic page: [Probability](../../../../topics/math/probability/README.md)
- Practice ladder: [Probability ladder](README.md)
- Starter template: [probability-distribution-dp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/probability-distribution-dp.cpp)
- Notebook refresher: [Probability hot sheet](../../../../notebook/probability-hot-sheet.md)
- Compare points:
  - [Candy Lottery](https://cses.fi/problemset/task/1727/)
  - [Moving Robots](https://cses.fi/problemset/task/1726/)
  - [Randomized Algorithms](../../../../topics/advanced/randomized-algorithms/README.md)
- This note adds: the exact PMF-DP doorway for repeated small-support random steps.

## Solutions

- Code: [diceprobability.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/probability/diceprobability.cpp)
