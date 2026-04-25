# Lagrangian Relaxation / Aliens Trick Hot Sheet

Use this page when the original problem asks for the best answer with **exactly** `K` choices, but the same problem becomes much cheaper if each choice costs a penalty `lambda`.

## Do Not Use When

- plain `O(NK)` DP already fits
- the expensive part is still one DP row with monotone argmins -> [Divide and Conquer DP hot sheet](divide-and-conquer-dp-hot-sheet.md)
- the state is one convex function over coordinate/value -> [Slope Trick hot sheet](slope-trick-hot-sheet.md)

## Exact Maximization Route

For fixed integer penalty `lambda`, solve:

$$
\max(\text{original value} - \lambda \cdot \text{count})
$$

and return:

- `penalized_value`
- `count`

For equal penalized values, prefer the **larger** count.

Then:

- binary search the largest `lambda` with `count >= K`
- recover:

```text
answer = penalized_value + lambda * K
```

## Recognition Cues

- "choose exactly `K` intervals / segments / facilities / positions"
- the count dimension is the only thing making the DP too expensive
- editorial mentions `Alien DP`, `wqs binary search`, `concavity`, or `Lagrangian relaxation`

## Core Invariants

- the relaxed solver must return both value and count
- count must move monotonically as `lambda` changes
- tie-break direction is part of correctness, not style
- integer slopes want integer binary search

## Main Traps

- tie-breaking equal values by smaller count in a maximization route
- using floating-point search when the slopes are integral
- forgetting to add `lambda * K` back
- assuming a penalty with exact count `K` always exists

## Exact Starter In This Repo

- starter -> [`aliens-trick-nonadjacent-max.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/aliens-trick-nonadjacent-max.cpp)
- flagship rep -> [Red and Blue Lamps](../practice/ladders/dp/lagrangian-relaxation/redandbluelamps.md)
- compare direct optimization lanes -> [Divide and Conquer DP hot sheet](divide-and-conquer-dp-hot-sheet.md), [Knuth Optimization hot sheet](knuth-optimization-hot-sheet.md)

## Reopen Paths

- full tutorial -> [Lagrangian Relaxation / Aliens Trick](../topics/dp/lagrangian-relaxation/README.md)
- parent router -> [DP cheatsheet](dp-cheatsheet.md)
- compare coordinate-function family -> [Slope Trick hot sheet](slope-trick-hot-sheet.md)
