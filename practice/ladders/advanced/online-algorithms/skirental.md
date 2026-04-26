# Ski Rental

- Title: `Ski Rental`
- Judge / source: `Canonical online-algorithms benchmark`
- Original URL: [https://www.cs.jhu.edu/~mdinitz/classes/IntroAlgorithms/Fall2021/Lectures/Lecture24/lecture24slides.pdf](https://www.cs.jhu.edu/~mdinitz/classes/IntroAlgorithms/Fall2021/Lectures/Lecture24/lecture24slides.pdf)
- Secondary topics: `Competitive ratio`, `Threshold policy`, `Adversarial future`
- Difficulty: `medium`
- Subtype: `Deterministic ski-rental threshold benchmark`
- Status: `solved`
- Solution file: [skirental.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/online-algorithms/skirental.cpp)

## Why Practice This

This is the cleanest first in-repo anchor for `Online Algorithms`.

The benchmark is intentionally narrow:

- unit rent cost
- one buy cost `B`
- one hidden trip horizon
- one deterministic threshold rule
- one comparison against offline optimum

So the hard part is exactly the lane itself:

- what the online policy is allowed to know
- how to measure quality with competitive ratio
- why the adversary stops right after you buy

## Recognition Cue

Reach for this route when:

- the statement is really `keep paying per step or make one irreversible commitment`
- the future horizon is unknown
- the benchmark explicitly wants comparison against a hindsight optimum

The strongest smell is:

```text
I need the first competitive-ratio benchmark, not one offline optimizer.
```

That is exactly this note.

## Problem-Specific Route

This repo's benchmark normalizes the problem to:

- rent cost per ski day = `1`
- buy cost = `B`
- realized total ski days = `d`

The online policy does **not** know `d` ahead of time.

It simply follows:

1. rent for the first `B - 1` ski days
2. if a `B`-th ski day arrives, buy on that day

The offline optimum does know `d`, so:

$$
\mathrm{OPT}(d) = \min(d, B).
$$

The online threshold rule pays:

$$
\mathrm{ALG}(d) =
\begin{cases}
d, & d < B \\\\
2B - 1, & d \ge B.
\end{cases}
$$

So the worst-case deterministic competitive ratio is:

$$
\frac{2B - 1}{B}.
$$

## Core Idea

The key online-algorithms lesson is not a data structure.

It is the benchmark discipline.

### 1. The Rule Must Ignore The Future

The input to this repo benchmark includes `d` only so we can evaluate the rule after the fact.

The online rule itself must act as if the future is hidden.

### 2. The Threshold Is "Buy When Hindsight Starts Favoring Buy"

If buying costs `B`, then after renting for `B - 1` days:

- renting one more day would make pure renting cost `B`
- so the next ski day is exactly where the deterministic rule commits

### 3. The Worst Adversary Stops On The First Buy Day

If the season ends earlier, the rule is optimal.

If it continues much longer, buying eventually looks justified.

So the clean adversarial hit is:

- force the algorithm to buy
- then stop immediately

That is why `d = B` is the critical bad case on this exact route.

## Complexity

The benchmark itself is tiny:

- `O(1)` per queried horizon
- `O(1)` memory

The whole point is the analysis, not the implementation load.

## Input / Output Contract For This Repo

This repo's benchmark uses:

- one integer `B`
- one integer `q`
- one list of `q` realized trip lengths

The solution prints:

- for each trip length `d`, one line `ALG(d) OPT(d)`
- one final line with the reduced worst-case ratio numerator and denominator

This is a repo-native benchmark, not a standard judge I/O.
It exists to make the online-analysis contract concrete and reusable.

## Pitfalls / Judge Notes

- The rule must be analyzed as online even though the benchmark input reveals `d`.
- Buying happens on day `B`, not after day `B`.
- `OPT` is not another heuristic; it is the offline optimum with full future knowledge.
- This first lane does **not** already teach paging or randomized online algorithms.

## Reusable Pattern

- Topic page: [Online Algorithms](../../../../topics/advanced/online-algorithms/README.md)
- Practice ladder: [Online Algorithms ladder](README.md)
- Starter template: [ski-rental-threshold.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/advanced/ski-rental-threshold.cpp)
- Notebook refresher: [Online Algorithms hot sheet](../../../../notebook/online-algorithms-hot-sheet.md)
- Compare points:
  - [Randomized Algorithms](../../../../topics/advanced/randomized-algorithms/README.md)
  - [Optimization And Duality](../../../../topics/advanced/optimization-and-duality/README.md)

## Solutions

- Code: [skirental.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/online-algorithms/skirental.cpp)
