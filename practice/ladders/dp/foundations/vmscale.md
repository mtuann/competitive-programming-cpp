# VMSCALE

- Title: `VMSCALE - Chiếc cân kỳ diệu`
- Judge / source: `VN SPOJ / VNOI`
- Original URL: [https://vn.spoj.com/problems/VMSCALE/](https://vn.spoj.com/problems/VMSCALE/)
- Mirror URL: [https://oj.vnoi.info/problem/vmscale](https://oj.vnoi.info/problem/vmscale)
- Secondary topics: `Decision tree`, `Balanced ternary`, `Minimax DP`
- Difficulty: `hard`
- Subtype: `Minimum worst-case total weighing cost on an integer interval`
- Status: `solved`
- Solution file: [vmscale.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/foundations/vmscale.cpp)

## Why Practice This

This is a very good “DP hidden inside a story problem” exercise.

At first glance it looks like a weighing puzzle or information-theory problem. The real structure is a minimax decision tree where every comparison pivot has a non-uniform price.

## Recognition Cue

Reach for minimax DP on a decision tree when:

- each question partitions the remaining answer range into branches
- the objective is worst-case total cost, not expected cost
- different questions have different prices
- the statement looks like a guessing game or measuring puzzle

The strongest smell is:

- "minimum worst-case total cost to identify one hidden value"

That usually means states are intervals and transitions are chosen questions.

## Problem-Specific Transformation

The weighing story is rewritten as:

- each chosen target `T` is one ternary comparison question
- asking that question costs `cost(T)`
- after the answer, the remaining candidate set is one sub-interval

So the whole problem becomes:

- choose pivots
- pay their balanced-ternary cost
- minimize the worst-case future budget

That is why the right state is not one current weight configuration, but an interval budget DP.

## Core Idea

One weighing can place powers of `3` on both sides, so any integer pivot `T` can be written in balanced ternary:

```text
T = sum d_i * 3^i, where d_i in {-1, 0, 1}
```

The weighing result tells us whether:

```text
x < T, x = T, or x > T
```

and the money spent for that weighing is exactly:

```text
cost(T) = number of nonzero digits d_i
```

So the original problem becomes:

- unknown integer `x` lies in `[L, R]`
- one question chooses a pivot `T`
- asking that question costs `cost(T)`
- we want the minimum worst-case total cost

Define:

```text
far[B][L] = farthest R such that every x in [L, R]
            can be identified with worst-case total cost <= B
```

If the first pivot is `T` with cost `c`, then:

- the left branch `[L, T - 1]` must fit in budget `B - c`
- the right branch `[T + 1, R]` must fit in budget `B - c`

So `T` is usable exactly when:

```text
T - 1 <= far[B - c][L]
```

and then the best right endpoint we can guarantee is:

```text
far[B - c][T + 1]
```

This gives a budget DP from small budgets upward.

## Complexity

Let `W = 10000`.

- balanced ternary cost preprocessing: `O(W log W)`
- DP: `O(Bmax * W * C)`
- here `C <= 10` is the maximum balanced-ternary weight for numbers up to `10000`
- in practice `Bmax = 61`
- each query is answered with binary search on the budget: `O(log Bmax)`

That is fast enough even for `Q <= 10^6`.

## Pitfalls / Judge Notes

- The objective is **worst-case total money**, not the number of weighings.
- A pivot with many nonzero balanced-ternary digits may still be worth it if it splits the interval well.
- The cost of `T` is not the number of ternary digits, but the number of nonzero digits in **balanced ternary**.
- Because `Q` is huge, slow per-query logic will time out even if the recurrence is correct.
- The hidden trick is to precompute the whole answer table by budget, then answer each query with only a binary search.

## Reusable Pattern

- Topic page: [Foundations](../../../../topics/dp/foundations/README.md)
- Practice ladder: [Foundations ladder](README.md)
- Starter template: [Template library overview](../../../../template-library.md)
- Notebook refresher: [DP cheatsheet](../../../../notebook/dp-cheatsheet.md)
- Carry forward: write the state meaning in one sentence before you derive any recurrence.
- This note adds: the recurrence shape and optimization that belong to this specific problem.

## Solutions

- Code: [vmscale.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/foundations/vmscale.cpp)
