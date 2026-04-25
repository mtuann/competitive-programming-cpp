# Red and Blue Lamps

- Title: `Red and Blue Lamps`
- Judge / source: `AtCoder ABC218 H`
- Original URL: [https://atcoder.jp/contests/abc218/tasks/abc218_h](https://atcoder.jp/contests/abc218/tasks/abc218_h)
- Secondary topics: `Aliens Trick`, `Weighted independent set on a path`, `Penalty search`
- Difficulty: `hard`
- Subtype: `Exact-K non-adjacent picks via integer penalty binary search`
- Status: `solved`
- Solution file: [redandbluelamps.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/lagrangian-relaxation/redandbluelamps.cpp)

## Why Practice This

This is the cleanest official flagship for the exact Aliens-trick route in the repo.

The core lesson is:

- the direct DP over "choose exactly `R`" is too expensive
- but once every chosen item costs `lambda`, the problem becomes one linear path DP

So the trick is not "magic binary search."

It is:

- move the exact-count constraint into the objective
- solve the relaxed problem fast
- search the penalty where the optimal count crosses `R`

## Recognition Cue

Reach for Lagrangian relaxation when:

- the statement asks for an answer with exactly `R` chosen objects
- a direct DP over that exact count is too large
- the relaxed "each chosen object costs `C`" problem is dramatically simpler

The strongest smell here is:

- "exactly `K`" is the expensive dimension, not the structural transition itself

## Problem-Specific Transformation

First, swap red and blue if needed so:

$$
R \le \left\lfloor \frac{N}{2} \right\rfloor.
$$

The official editorial then reduces the problem to:

- choose exactly `R` lamps
- no two chosen lamps are adjacent
- choosing lamp `i` gives weight

$$
B_i = A_{i-1} + A_i
$$

with the convention:

$$
A_0 = A_N = 0.
$$

So the problem becomes:

> maximize the total weight of exactly `R` non-adjacent chosen positions on a path

Let:

$$
f(k) = \text{maximum total weight using exactly } k \text{ chosen positions}.
$$

## Penalized Version

For a fixed integer penalty `lambda`, solve:

$$
\max \left(\sum B_i - \lambda \cdot \#\text{chosen}\right).
$$

Now the exact count disappears.

We only need the best penalized path-independent-set DP.

## Relaxed DP

Scan left to right with two states:

- `skip` = best penalized answer up to here if current position is not chosen
- `take` = best penalized answer up to here if current position is chosen

Transition:

- `new_skip = max(skip, take)`
- `new_take = skip + B_i - lambda`

But each state is not just one scalar.

It is:

```text
(penalized_value, count)
```

For equal penalized values, prefer the **larger** count.

That tie-break is exactly what keeps the boundary cases correct when no penalty yields count exactly `R`.

## Binary Search Step

As `lambda` increases, choosing one more lamp becomes less attractive.

So the optimal count decreases.

Binary search the largest `lambda` such that:

```text
count(lambda) >= R
```

Then recover:

$$
f(R) = \text{penalized\_value} + \lambda R.
$$

## Why The Optimization Fits

This note is not about proving every piece of discrete concavity from scratch.

It is about recognizing the exact contest lane:

- exact `R`
- relaxed penalty per choice
- count-returning DP
- integer binary search over the penalty

That is enough to route safely to the exact starter.

## Complexity

If the relaxed solver is `O(N)` and we binary search an integer penalty range, total complexity is:

$$
O(N \log V)
$$

where `V` is the searched penalty width.

For this task, that is fast enough for:

- `N <= 2 * 10^5`

## Main Traps

- forgetting the initial transformation to non-adjacent weighted picks
- tie-breaking equal penalized values by smaller count
- using floating-point search
- forgetting to add back `lambda * R`

## Reopen Path

- Topic page: [Lagrangian Relaxation / Aliens Trick](../../../../topics/dp/lagrangian-relaxation/README.md)
- Practice ladder: [Lagrangian Relaxation / Aliens Trick ladder](README.md)
- Starter template: [`aliens-trick-nonadjacent-max.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/aliens-trick-nonadjacent-max.cpp)
- Notebook refresher: [Aliens Trick hot sheet](../../../../notebook/aliens-trick-hot-sheet.md)
- Compare points: [Divide and Conquer DP](../../../../topics/dp/divide-and-conquer-dp/README.md), [Slope Trick](../../../../topics/dp/slope-trick/README.md)

## Solution

- Code: [redandbluelamps.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/lagrangian-relaxation/redandbluelamps.cpp)
