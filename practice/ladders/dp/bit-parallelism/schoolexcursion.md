# School Excursion

- Title: `School Excursion`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1706/](https://cses.fi/problemset/task/1706/)
- Secondary topics: `DSU`, `Component sizes`, `Boolean reachability`
- Difficulty: `hard`
- Subtype: `Component-size subset sum via dynamic bitset shift-OR`
- Status: `solved`
- Solution file: [schoolexcursion.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/bit-parallelism/schoolexcursion.cpp)

## Why Practice This

This is the cleanest in-repo flagship for the first exact `bit-parallelism / bitset optimization` route.

The point is not a fancy new recurrence.

The point is:

1. compress the graph into connected-component sizes
2. ask which total group sizes are reachable
3. run boolean subset-sum DP by packed shift-OR instead of scalar `O(nW)`

That keeps the first lane honest:

- one light modeling step
- one large boolean reachability row
- one exact bitset implementation win

## Recognition Cue

Reach for this lane when:

- the answer is a set of reachable totals, not one max value
- the post-modeling state is:

$$
reachable[s] = \text{can we realize total } s ?
$$

- the transition is "add one component size"
- a scalar boolean DP would still be correct but feels too wide or too constant-heavy

The strongest smell here is:

- the statement reduces to subset-sum reachability on one large axis after one preprocessing step

## Problem-Specific Transformation

First, build connected components with DSU.

Let their sizes be:

$$
c_1, c_2, \dots, c_k.
$$

Then the whole graph part disappears.

The real problem becomes:

```text
which totals can be formed by choosing some component sizes?
```

So maintain one bitset `reachable` where:

- bit `s` means total `s` is possible

Initialize:

- only sum `0` is reachable

For each component size `c`:

$$
reachable \mathrel{|}= reachable \ll c.
$$

Finally output bits `1..n`.

## Main Traps

- forgetting the preprocessing step and trying to DP directly on vertices
- using scalar subset-sum DP when the packed version is the intended implementation win
- confusing this with max-value knapsack; the state here is purely boolean

## Repo Links

- topic page: [Bit-Parallelism / Bitset Optimization](../../../../topics/dp/bit-parallelism/README.md)
- practice ladder: [Bit-Parallelism / Bitset Optimization ladder](README.md)
- starter template: [bitset-reachability-shift.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/bitset-reachability-shift.cpp)
- notebook refresher: [Bit-Parallelism / Bitset Optimization hot sheet](../../../../notebook/bit-parallelism-hot-sheet.md)
