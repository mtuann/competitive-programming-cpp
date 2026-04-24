# Book Shop

- Title: `Book Shop`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1158](https://cses.fi/problemset/task/1158)
- Main topic: `DP -> Knapsack Family`
- Secondary topics: `0/1 knapsack`, `Downward capacity loop`, `Budget maximization`
- Difficulty: `easy`
- Subtype: `Choose books once each to maximize pages within a budget`
- Status: `solved`
- Solution file: [bookshop.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/knapsack-family/bookshop.cpp)

## Why Practice This

This is the cleanest `0/1` knapsack in the whole CSES set:

- each book can be bought at most once
- each book has one cost and one value
- the state dimension is just the remaining budget

If this recurrence feels natural, the rest of the knapsack family becomes much easier to organize.

## Key Idea

Let:

```text
dp[money] = maximum pages achievable with total cost at most money
```

For one book with:

- price `h`
- pages `s`

the `0/1` transition is:

```text
dp[money] = max(dp[money], dp[money - h] + s)
```

but only for `money >= h`.

The crucial detail is **loop direction**:

```text
for money from budget down to h
```

Why downward?

Because each book may be used at most once. When iterating downward, `dp[money - h]` still refers to the previous layer, before this book has been applied to larger capacities. That prevents accidental reuse of the same book multiple times.

If we iterated upward, we would drift toward complete-knapsack behavior and allow the current book to be counted repeatedly.

## Complexity

- number of books: `n`
- budget: `x`
- total: `O(n * x)`
- memory: `O(x)`

This is the standard compressed `0/1` knapsack bound.

## Pitfalls / Judge Notes

- Iterate capacity downward for `0/1` knapsack.
- Use `max`, not addition-only updates; this is a maximization problem under a budget cap.
- `dp[money]` means “best value with budget at most `money`”, so printing `dp[x]` is correct even if the exact budget is not fully used.
- A 2D DP is valid too, but the 1D compressed version is the intended clean implementation here.

## Reusable Pattern

- Topic page: [Knapsack Family](../../../../topics/dp/knapsack-family/README.md)
- Practice ladder: [Knapsack Family ladder](README.md)
- Starter template: [knapsack-01.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/knapsack-01.cpp)
- Notebook refresher: [DP cheatsheet](../../../../notebook/dp-cheatsheet.md)
- Carry forward: match the problem to item / capacity / value language before coding loops.
- This note adds: the one-dimensional capacity update and value maximization for this budget constraint.

## Solutions

- Code: [bookshop.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/knapsack-family/bookshop.cpp)
