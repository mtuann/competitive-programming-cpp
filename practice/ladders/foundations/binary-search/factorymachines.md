# Factory Machines

- Title: `Factory Machines`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1620](https://cses.fi/problemset/task/1620)
- Secondary topics: `Answer binary search`, `Monotone feasibility`, `Saturating accumulation`
- Difficulty: `medium`
- Subtype: `Minimum time to reach a production target`
- Status: `solved`
- Solution file: [factorymachines.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/binary-search/factorymachines.cpp)

## Why Practice This

This is one of the cleanest "binary search on the answer" problems in the whole topic. The monotone predicate is easy to state, but the implementation still forces careful thinking about search boundaries, overflow, and what exactly `mid` means.

## Recognition Cue

Reach for answer-space binary search when:

- the asked quantity is a minimum or first time threshold
- checking one candidate answer is much easier than constructing the exact answer directly
- feasibility only moves one way as the candidate grows
- the brute-force search space is numeric and huge, but the checker is linear or near-linear

The strongest wording smell here is:

- "minimum time so that production reaches at least `t`"

That is almost a request for the first true value of a monotone predicate.

## Problem-Specific Transformation

The statement talks about machines producing products over time. The reusable rewrite is:

- guess a time `x`
- ask whether the machines can produce at least `t` items by time `x`

For one machine with speed `k[i]`, the contribution under that guess is `floor(x / k[i])`. So the raw scheduling story collapses into one monotone boolean checker:

- `can_make(x) := sum floor(x / k[i]) >= t`

Once the problem is in that form, we are no longer searching over schedules. We are only searching for the first feasible time.

## Core Idea

Let `can_make(x)` mean:

```text
in x time units, all machines together can produce at least t products
```

If a time `x` is feasible, then any larger time is also feasible, so the answer is the first `x` where `can_make(x)` becomes true.

For one machine with production time `k[i]`, the number of products completed within `x` time units is:

```text
floor(x / k[i])
```

So the total production is:

```text
sum floor(x / k[i])
```

That gives a direct monotone feasibility check.

The binary-search boundaries can be:

- `lo = 0`, which is always infeasible unless `t = 0`
- `hi = min(k) * t`, because the fastest machine alone can finish all products within that time

Then we run a standard first-true binary search on `[lo, hi]`.

## Complexity

- feasibility check: `O(n)`
- binary search iterations: `O(log(min(k) * t))`
- total: `O(n log answer)`

This is easily fast enough for the CSES limits.

## Pitfalls / Judge Notes

- Do not binary-search over machine indices or counts; the searched value is **time**.
- Use `long long` for the search range and machine times.
- The running sum `sum(x / k[i])` can grow beyond what we actually need. Cap it at `t` or stop early once it reaches `t`.
- The clean invariant is "answer is in `[lo, hi]` and `hi` is feasible". That makes the final answer simply `lo` after the loop.
- `hi = min(k) * t` is the right upper bound; choosing something ad hoc like `1e18` works too, but gives a weaker argument.

## Reusable Pattern

- Topic page: [Binary Search](../../../../topics/foundations/patterns/binary-search/README.md)
- Practice ladder: [Binary Search ladder](README.md)
- Starter template: [binary-search-first-true.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/binary-search-first-true.cpp)
- Notebook refresher: [Foundations cheatsheet](../../../../notebook/foundations-cheatsheet.md)
- Carry forward: write the monotone predicate first, then binary-search the first true answer.
- This note adds: the saturating feasibility check for this answer-space search.

## Solutions

- Code: [factorymachines.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/binary-search/factorymachines.cpp)
