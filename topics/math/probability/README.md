# Probability

This lane is for the moment when a math problem stops being:

- deterministic counting
- one direct modular/combinatorial identity
- randomized algorithm design

and becomes:

- a **random process** given directly in the statement
- with a finite discrete state space or finite support
- where the right object is a probability distribution or an expectation

In contest terms, the key shift is:

- stop simulating one sample path
- track the whole distribution or one expectation recurrence
- use linearity, total probability, and small-state DP to aggregate exactly

This is the exact lane for the repo's first `probability` route.

## At A Glance

- **Use when:** the statement itself defines a random experiment and asks for one exact probability or expected value
- **Core worldview:** treat the process as a distribution over states, not a random simulation
- **Main tools:** PMFs, expectation, linearity of expectation, total probability, finite-state DP
- **Typical complexity:** `O(steps * states * transitions)` or one direct summation over a derived PMF
- **Main trap:** confusing "randomness inside the statement" with [Randomized Algorithms](../../advanced/randomized-algorithms/README.md)

Strong contest signals:

- "what is the probability that ..."
- "what is the expected number/value after ..."
- "each step chooses uniformly at random from a small move set"
- "sum of outcomes after `n` trials"
- "compute the answer exactly, not by simulation"

Strong anti-cues:

- the algorithm itself uses randomization for speed or correctness -> [Randomized Algorithms](../../advanced/randomized-algorithms/README.md)
- the task is really deterministic DP or greedy dressed up as a story
- the state space is continuous or measure-theoretic, not a contest finite-state model
- the probability can be avoided entirely by one simple invariant or parity argument

The repo's exact first route for this family is:

- starter -> [probability-distribution-dp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/probability-distribution-dp.cpp)
- flagship note -> [Dice Probability](../../../practice/ladders/math/probability/diceprobability.md)
- compare point -> [Randomized Algorithms](../../advanced/randomized-algorithms/README.md)

## Prerequisites

- [Counting Basics](../../combinatorics/counting-basics/README.md) for sample-space counting and small discrete distributions
- [Dynamic Programming Foundations](../../dp/foundations/README.md) for state transitions and table reuse
- [C++ Language For Contests](../../foundations/cpp-language/README.md) for floating-point formatting and careful accumulation

Helpful neighboring topics:

- [Randomized Algorithms](../../advanced/randomized-algorithms/README.md): use this when the **algorithm** is random rather than the statement's process
- [Linear Recurrence / Matrix Exponentiation](../linear-recurrence/README.md): a compare point when repeated transitions become deterministic linear algebra
- [Digit DP](../../dp/digit-dp/README.md): another finite-state DP lane, but deterministic rather than probabilistic

## Problem Model And Notation

Let a random process have finite state set:

$$
S = \{0, 1, \dots, M\}
$$

and let:

$$
dp_t[x] = \Pr(\text{state } x \text{ after } t \text{ steps})
$$

Then every exact probability question is really:

- build the relevant distribution
- sum the mass of the requested outcomes

and every expectation question is really:

$$
\mathbb{E}[f(X)] = \sum_x f(x)\Pr(X=x)
$$

or an equivalent recurrence from total expectation.

The mental rewrite is:

```text
one random process  ->  one deterministic table over probability mass
```

## From Brute Force To The Right Idea

### Brute Force

The tempting route is simulation:

- sample random trials
- approximate the answer by Monte Carlo

That is almost never allowed in standard contest math tasks because:

- the answer must be exact or numerically stable to tight precision
- randomness in the solver is unnecessary

### Structural Observation

If the state space is small enough, then after each step:

- every probability mass fragment moves deterministically to successor states

So instead of simulating one run, we propagate the full PMF.

For repeated independent trials, this often looks like:

- one convolution-like DP over sums

For expectations, it often looks like:

- linearity of expectation
- or one recurrence from conditional expectation

### Why Distribution DP Works

Suppose at step `t` the process is at state `x` with probability `dp_t[x]`.

If one move takes `x` to `y` with transition probability `p(x -> y)`, then:

$$
dp_{t+1}[y] += dp_t[x] \cdot p(x \to y)
$$

That is the law of total probability in DP form.

So one random process becomes one deterministic weighted transition table.

## Core Invariant And Why It Works

### 1. Probability Mass Is Conserved

At every step:

$$
\sum_x dp_t[x] = 1
$$

if the process description is complete.

This is the main implementation sanity check.

### 2. Each Transition Adds Weighted Mass

If state `x` branches to several next states, each branch contributes:

$$
dp_t[x] \cdot p(x \to y)
$$

to the target state.

So every update is just:

- current mass times branch probability

### 3. Expectations Are Weighted Sums

Once the final PMF is known, for any value function `f`:

$$
\mathbb{E}[f(X)] = \sum_x f(x)dp[x]
$$

This is why many contest expectation tasks reduce to:

- build one PMF
- or derive one direct probability formula
- then take one weighted sum

### 4. Linearity Saves Work

For random variables `X_1, X_2, \dots, X_n`:

$$
\mathbb{E}[X_1 + \dots + X_n] = \mathbb{E}[X_1] + \dots + \mathbb{E}[X_n]
$$

even when full joint distributions are painful.

This is often the shortest route in harder probability tasks.

## Worked Examples

### Example 1: Repeated Fair Die Sums

This repo's flagship note:

- [Dice Probability](../../../practice/ladders/math/probability/diceprobability.md)

Let:

$$
dp[i][s] = \Pr(\text{sum } s \text{ after } i \text{ throws})
$$

Then:

$$
dp[i+1][s+f] += \frac{dp[i][s]}{6}
$$

for each face `f in {1,2,3,4,5,6}`.

The final answer is:

$$
\sum_{s=a}^{b} dp[n][s]
$$

This is the cleanest exact first benchmark because:

- the sample space is explicit
- the state is one bounded sum
- the answer is directly one PMF range sum

### Example 2: Expected Maximum

In:

- [Candy Lottery](https://cses.fi/problemset/task/1727/)

the shortest route is not a DP table over all children.

It is:

- compute the distribution of the maximum
- then sum `value * probability`

So this is a good compare point for:

- "expectation from a distribution formula" instead of one transition DP

### Example 3: Many Independent Random Walkers

In:

- [Moving Robots](https://cses.fi/problemset/task/1726/)

one robot's distribution is small enough to track exactly, and the whole answer uses independence plus complementary probabilities.

This is a stretch route after the flagship.

### Example 4: Why This Is Not Randomized Algorithms

In [Randomized Algorithms](../../advanced/randomized-algorithms/README.md):

- the algorithm flips coins
- the proof is about failure probability or expected runtime

Here:

- the random process is part of the **problem statement**
- your solver itself should stay deterministic

## Variant Chooser

### Route A: One Bounded Sum / One Small State Process

Use this when:

- there are `n` independent identical trials
- or one finite random process with small integer state

Then a PMF DP is usually the exact route.

This is the repo starter's exact fit.

### Route B: Expectation From A Known Distribution

Use this when:

- the answer is expected value
- and deriving the distribution of the target statistic is easier than full state DP

Examples:

- expected maximum
- expected count of marked events

### Route C: Expectation By Linearity

Use this when:

- the target is a sum of indicator variables or local contributions

Then:

- compute each component expectation separately
- sum them

Often this is much shorter than a full distribution DP.

### Route D: Not This Lane

Do **not** use this topic first when:

- the algorithm is randomized rather than the statement
- the process is continuous and the intended route is outside standard contest finite-state modeling
- the answer is actually deterministic after one invariant

## Complexity And Tradeoffs

For the repo's exact first route:

- `n` steps
- `M` reachable sum states
- `k` possible outcomes per step

Time:

$$
O(n \cdot M \cdot k)
$$

Space:

$$
O(M)
$$

with rolling arrays.

Tradeoff:

- this is great for bounded discrete support
- it is not the right first snippet for symbolic distributions, continuous variables, or giant-state Markov chains

## Starter Fit

The starter in this repo is intentionally narrow:

- one fixed discrete step distribution
- repeated for many steps
- one bounded sum state
- final probability and expectation can be derived from the PMF

It does **not** directly advertise:

- arbitrary continuous distributions
- absorbing Markov-chain linear systems
- Bayes-heavy conditional-probability derivations
- high-end expectation/combinatorics transforms

## Common Pitfalls

- simulating instead of computing the exact PMF
- forgetting that probability mass should sum to `1`
- mixing up probability of a value with expected value of that value
- using `double` carelessly when a longer accumulation path benefits from `long double`
- confusing "random experiment in the statement" with [Randomized Algorithms](../../advanced/randomized-algorithms/README.md)

## Repo Routes

- topic lane -> [Math overview](../README.md)
- practice ladder -> [Probability ladder](../../../practice/ladders/math/probability/README.md)
- exact starter -> [probability-distribution-dp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/probability-distribution-dp.cpp)
- flagship note -> [Dice Probability](../../../practice/ladders/math/probability/diceprobability.md)
- hot sheet -> [Probability hot sheet](../../../notebook/probability-hot-sheet.md)
- compare point -> [Randomized Algorithms](../../advanced/randomized-algorithms/README.md)

## References

- [Harvard Stat 110: Probability](https://stat110.hsites.harvard.edu/)
- [MIT 18.600 Probability and Random Variables notes](https://ocw.mit.edu/courses/18-600-probability-and-random-variables-fall-2019/resources/lecture-notes/)
- [CSES: Dice Probability](https://cses.fi/problemset/task/1725/)
- [CSES: Candy Lottery](https://cses.fi/problemset/task/1727/)
- [CSES: Moving Robots](https://cses.fi/problemset/task/1726/)
