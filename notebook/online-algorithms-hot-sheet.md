# Online Algorithms Hot Sheet

Use this page when the real difficulty is hidden future information and the first honest benchmark is competitive ratio, not offline optimization time.

## Do Not Use When

- the full input is already known before decisions are made
- the real lane is paging / caching rather than the first ski-rental benchmark
- the task already needs randomized online design as the main object -> [Randomized Algorithms](../topics/advanced/randomized-algorithms/README.md)
- the problem is really one LP / flow / DP model and "online" is only decorative wording

## Exact Route In This Repo

- unit rent cost `1`
- buy cost `B`
- deterministic threshold policy:
  - rent for the first `B - 1` ski days
  - buy on day `B` if that day ever arrives
- evaluate:
  - online cost `ALG(d)`
  - offline optimum `OPT(d) = min(d, B)`
  - worst-case ratio `(2B - 1) / B`

## Recognition Cues

- future horizon is unknown
- decisions are irrevocable
- the benchmark compares against an offline optimum that knows the whole future
- threshold policies are the natural first proof tool

## Core Invariants

- the online policy does **not** know the realized horizon `d`
- the offline optimum does know the whole future
- the critical worst case is the first day on which the threshold policy buys
- simple code does not mean trivial theory; the proof obligation is the whole lane

## Main Traps

- using the benchmark horizon as if it were visible to the online policy
- buying after day `B` instead of on day `B`
- comparing against another heuristic instead of offline optimum
- overclaiming from ski rental to paging or randomized online algorithms

## Exact Starter In This Repo

- starter -> [`ski-rental-threshold.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/advanced/ski-rental-threshold.cpp)
- flagship rep -> [Ski Rental](../practice/ladders/advanced/online-algorithms/skirental.md)
- theory sibling -> [Randomized Algorithms](../topics/advanced/randomized-algorithms/README.md)

## Reopen Paths

- full tutorial -> [Online Algorithms](../topics/advanced/online-algorithms/README.md)
- parent router -> [Advanced overview](../topics/advanced/README.md)
- retrieve layer -> [Build Kit](../docs/build-kit.md) and [Template Library](../template-library.md)
