# Online Algorithms

This lane is for the first honest situation where the main difficulty is not raw computational power, but lack of future information.

The repo's exact first route is intentionally narrow:

- one repeated `rent or buy` decision
- no access to the future trip length
- one deterministic threshold policy
- one competitive-ratio analysis against the offline optimum

That means this page is **not** a full textbook on online algorithms.

It is the first clean contest-adjacent route for:

- competitive ratio
- adversarial futures
- deterministic online policy design

with [Ski Rental](../../../practice/ladders/advanced/online-algorithms/skirental.md) as the flagship benchmark.

This page sits next to:

- [Randomized Algorithms](../randomized-algorithms/README.md) when randomness is the next real tool
- [Optimization And Duality](../optimization-and-duality/README.md) when you want a stronger benchmark / certificate worldview
- [Algorithm Engineering](../algorithm-engineering/README.md) when the bottleneck is implementation quality, not missing future information

## At A Glance

- **Use when:**
  - decisions must be made before the full future is known
  - the right quality metric is comparison against an offline optimum that knows the whole future
  - you want the first concrete benchmark for competitive analysis
  - the statement smells like `rent or buy`, `wait or commit`, or `act now without knowing horizon`
- **Prerequisites:**
  - [Reasoning](../../foundations/reasoning/README.md)
  - [Randomized Algorithms](../randomized-algorithms/README.md) only as a sibling, not as a strict prereq
- **Boundary with nearby pages:**
  - use [Randomized Algorithms](../randomized-algorithms/README.md) when the missing move is randomized design or oblivious-adversary analysis
  - use this page when the core lesson is deterministic competitive analysis with hidden future
  - use ordinary graph / DP / greedy pages when the full input is already known offline
- **Strongest cues:**
  - "I must make a decision now and cannot revise it after seeing the future"
  - the benchmark explicitly compares against `OPT` that knows the whole sequence
  - threshold-policy analysis is the natural first proof
  - the simplest motivating example is `rent vs buy`
- **Strongest anti-cues:**
  - the whole input is already known, so there is no real online aspect
  - the challenge is numerical optimization, not adversarial future uncertainty
  - the real topic is paging / caching with long request sequences and eviction invariants
  - the statement already demands randomized guarantees as the main object
- **Success after studying this page:**
  - you can state the competitive-ratio benchmark cleanly
  - you can analyze the deterministic ski-rental threshold policy
  - you know why the worst adversary stops right after you buy

## Problem Model And Notation

The exact starter route in this repo uses the normalized ski-rental model:

- renting for one day costs `1`
- buying once costs `B`
- the total number of ski days `d` is unknown when decisions are made
- after you buy, you never rent again

The benchmark policy is:

- rent for the first `B - 1` ski days
- if a `B`-th ski day ever arrives, buy on that day

The offline optimum knows `d` in advance, so:

$$
\mathrm{OPT}(d) = \min(d, B).
$$

The deterministic online threshold policy pays:

$$
\mathrm{ALG}(d) =
\begin{cases}
d, & d < B \\\\
2B - 1, & d \ge B.
\end{cases}
$$

So the worst-case deterministic competitive ratio on this exact route is:

$$
\frac{2B - 1}{B}.
$$

This repo keeps the first route at `rent = 1` on purpose.

Why:

- it keeps the benchmark algebra small
- it makes the threshold `B - 1` visually obvious
- it teaches the competitive-analysis idea before any generalization noise

## Why This Exists Next To Randomized Algorithms

[Randomized Algorithms](../randomized-algorithms/README.md) teaches:

- random choices as a design resource
- expectation and amplification
- probabilistic guarantees

This page teaches a different first lesson:

- sometimes the barrier is not `time`
- sometimes the barrier is `future information`
- the benchmark is not "faster than brute force"
- the benchmark is "how far from offline optimum am I forced to be?"

So the division of labor is:

- **randomized page:** probability-backed algorithm design
- **online-algorithms page:** first competitive-analysis benchmark under hidden future

## Core Route In This Repo

The exact route is:

1. normalize the benchmark to unit rent and buy cost `B`
2. study one deterministic threshold policy
3. compare it against the offline optimum
4. identify the adversarial worst case
5. report the exact ratio

The exact starter contract is intentionally tiny:

- input object: one `buy_cost_days = B` and one realized trip length `d`
- output object:
  - online cost under the fixed threshold rule
  - offline optimum cost
  - worst-case ratio for that `B`

The exact non-promises are important:

- no paging implementation
- no randomized online algorithm
- no list-update machinery
- no general adversary framework beyond the first benchmark

## Core Invariants

### 1. Compare Against Offline Optimum, Not Against A Guess

Online analysis is only meaningful if the benchmark is fixed:

- your algorithm must decide without knowing the future
- the offline optimum may see the whole future

If you compare against another partial-information heuristic, you are no longer doing the core ski-rental analysis.

### 2. The Policy Is A Threshold Rule, Not A Prediction Rule

The policy does **not** try to predict how many days remain.

It simply says:

- rent until buying would have been better in hindsight
- then buy at the next opportunity

That discipline is the whole point of the route.

### 3. The Worst Adversary Stops Right After You Buy

If you buy too early, the adversary ends the season immediately after that purchase.

That is what creates the classic bad case:

- you already paid for many rent days
- then you also paid the full buy cost
- but offline optimum would have just bought once

This is why the critical bad horizon is the first day on which you buy.

## Worked Example: Ski Rental

Use [Ski Rental](../../../practice/ladders/advanced/online-algorithms/skirental.md).

Let:

- rent cost per ski day = `1`
- buy cost = `B = 5`

The repo's exact policy is:

- rent on days `1, 2, 3, 4`
- buy on day `5` if that day ever arrives

Then:

- if `d = 1`, online cost = `1`, offline cost = `1`
- if `d = 4`, online cost = `4`, offline cost = `4`
- if `d = 5`, online cost = `9`, offline cost = `5`
- if `d = 10`, online cost = `9`, offline cost = `5`

So the worst-case ratio is:

$$
\frac{9}{5}.
$$

This is the first benchmark the lane wants you to internalize.

## Variant Chooser

| Situation | Best first move | Why it fits | Where it fails |
| --- | --- | --- | --- |
| one rent-vs-buy decision with hidden horizon and deterministic analysis is the whole lesson | use this lane | the benchmark is exactly competitive ratio under missing future information | weak once the real structure is paging, randomized adversaries, or a richer online sequence model |
| the missing move is randomized design against oblivious adversaries | use [Randomized Algorithms](../randomized-algorithms/README.md) | randomization changes the benchmark and the proof style | weak if the first goal is still just understanding deterministic competitive ratio |
| the whole input is already known and you only need one optimum value | use the normal graph / DP / greedy topic | there is no true online barrier anymore | weak if decisions are irrevocable before the future is revealed |
| the statement is really about LP / flow / DP modeling, not hidden future | use the exact specialized family | online framing would be artificial | weak if the benchmark itself is lack of future information |

## Complexity And Tradeoffs

On this first route, the code is trivial:

- `O(1)` per evaluated horizon
- `O(1)` memory

The point of the lane is not implementation difficulty.

The real difficulty is:

- choosing the right benchmark
- proving the bad case honestly
- not confusing "simple code" with "trivial theory"

That is why this lane belongs in `advanced` even though the starter is tiny.

## Main Traps

- treating the benchmark input horizon `d` as if the online algorithm knew it in advance
- forgetting that the threshold policy buys on day `B`, not after day `B`
- comparing against another heuristic instead of the offline optimum
- overgeneralizing from ski rental to all of online algorithms
- pretending paging or randomized online algorithms are already covered by this first route

## Reopen Path

- Topic page: [Online Algorithms](README.md)
- Practice ladder: [Online Algorithms ladder](../../../practice/ladders/advanced/online-algorithms/README.md)
- Starter template: [ski-rental-threshold.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/advanced/ski-rental-threshold.cpp)
- Notebook refresher: [Online Algorithms hot sheet](../../../notebook/online-algorithms-hot-sheet.md)
- Compare points:
  - [Randomized Algorithms](../randomized-algorithms/README.md)
  - [Optimization And Duality](../optimization-and-duality/README.md)
  - [Ski Rental](../../../practice/ladders/advanced/online-algorithms/skirental.md)

## References And Practice

- [Stanford CS369 notes](https://web.stanford.edu/class/cs369/files/cs369-notes.pdf)
- [MIT OCW lecture note on ski rental](https://ocw.mit.edu/courses/6-854j-advanced-algorithms-fall-2005/resources/lec19_2003/)
- [Princeton COS 521 lecture note](https://faculty.cc.gatech.edu/~ssingla7/courses/Fall20cos521/lec18.pdf)
- [JHU Lecture 24: Online Algorithms](https://www.cs.jhu.edu/~mdinitz/classes/IntroAlgorithms/Fall2021/Lectures/Lecture24/lecture24slides.pdf)
