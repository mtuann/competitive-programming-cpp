# Build the Permutation

- Title: `Build the Permutation`
- Judge / source: `Codeforces`
- Original URL: [https://codeforces.com/problemset/problem/1608/B](https://codeforces.com/problemset/problem/1608/B)
- Secondary topics: `Alternating pattern`, `Local extrema counting`, `Case split construction`
- Difficulty: `medium`
- Subtype: `Construct a permutation with exactly a requested number of local maxima and local minima`
- Status: `solved`
- Solution file: [buildthepermutation.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/constructive/buildthepermutation.cpp)

## Why Practice This

This is a very good second constructive anchor after `VMCOINS` because the search space looks enormous, but the accepted solution is a tiny pattern once you identify the right invariant.

The key shift is:

- stop thinking about arbitrary permutations
- start thinking about how local extrema appear inside one alternating core

That turns the whole problem into:

- one feasibility check
- one small case split
- one explicit construction

## Key Idea

Two facts control the whole problem.

### 1. Feasibility conditions

If you walk through a permutation, local maxima and local minima must alternate.

So:

- `|a - b| <= 1`

Also, every local extremum must live at an interior index, so the total number is bounded by:

- `a + b <= n - 2`

If either condition fails, the answer is `-1`.

### 2. Build one alternating core

Let:

```text
m = a + b + 2
```

We only need the first `m` positions to create all requested extrema. The remaining numbers can be placed in a monotone tail that creates no new ones.

#### Case A: `a >= b`

Use the **largest** `m` values, and put all smaller leftover values in increasing order in front.

Inside the core, write:

```text
L, L+2, L+1, L+4, L+3, ...
```

where `L = n - m + 1`.

This creates:

- one local maximum at each “high” element
- one local minimum at each “low” element between them

Because the leftover prefix is strictly increasing and smaller than the core, it does not create any extra extremum at the boundary.

#### Case B: `b > a`

Use the **smallest** `m` values, and append all larger leftover values in increasing order after the core.

Inside the core, write:

```text
2, 1, 4, 3, 6, 5, ...
```

This is the symmetric pattern, now giving one extra local minimum.

Because the leftover suffix is increasing and larger than the core tail, it also creates no extra extremum.

## Complexity

- per test case: `O(n)`
- total: linear in the sum of all `n`

## Pitfalls / Judge Notes

- The alternation rule is the real feasibility test. If `|a-b| > 1`, there is no construction.
- `a + b <= n - 2` is the other mandatory bound because only interior indices can be extrema.
- Do not try to “adjust” a random permutation greedily. Build the whole alternating core directly.
- The leftover numbers must be placed on the correct side. Putting them on the wrong side can create one unintended extremum at the boundary.

## Reusable Pattern

- Topic page: [Constructive](../../../../topics/advanced/constructive/README.md)
- Practice ladder: [Constructive ladder](README.md)
- Starter template: [sort-and-comparator.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/sort-and-comparator.cpp)
- Notebook refresher: [Stress testing workflow](../../../../notebook/stress-testing-workflow.md)
- Carry forward: when a statement asks for exact counts of local structures, try building one explicit alternating core that realizes all of them at once.
- This note adds: the “core plus monotone tail” construction that prevents accidental extra extrema.

## Solutions

- Code: [buildthepermutation.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/constructive/buildthepermutation.cpp)
