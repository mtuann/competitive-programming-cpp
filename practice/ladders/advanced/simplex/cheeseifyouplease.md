# Cheese, If You Please

- Title: `Cheese, If You Please`
- Judge / source: `Kattis`
- Original URL: [https://open.kattis.com/problems/cheeseifyouplease](https://open.kattis.com/problems/cheeseifyouplease)
- Secondary topics: `Linear programming`, `Simplex`, `Resource allocation`
- Difficulty: `hard`
- Subtype: `Continuous blend-planning LP with one variable per product`
- Status: `solved`
- Solution file: [cheeseifyouplease.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/simplex/cheeseifyouplease.cpp)

## Why Practice This

This is the cleanest in-repo anchor for the `Simplex` lane because the statement already wants one continuous linear program.

Nothing meaningful is gained by forcing it into:

- max flow
- DP
- greedy exchange

The right move is just:

1. create one variable for each blend
2. write one cheese-supply inequality per cheese type
3. maximize total profit
4. solve the LP directly

## Recognition Cue

Reach for simplex when:

- the variables are "how much of each blend / product do we make?"
- every resource limit is linear
- the objective is linear profit
- fractional quantities are completely legal

The strongest smell is:

```text
each product consumes fixed percentages of each ingredient,
and I want the best profit
```

## Problem-Specific Transformation

Let:

- `x_j` = pounds of blend `j`

For each cheese type `i`, the input gives:

- stock `w_i`
- percentage `p_ij` of cheese `i` used in one pound of blend `j`

So the resource constraint is:

$$
\sum_j \frac{p_{ij}}{100} x_j \le w_i.
$$

The profit objective is:

$$
\max \sum_j t_j x_j,
$$

where `t_j` is the profit per pound of blend `j`.

This is already the exact starter route:

$$
\max c^T x
\quad
\text{s.t. } Ax \le b,\ x \ge 0.
$$

## Core Idea

The hard part is not a hidden combinatorial invariant. The hard part is trusting the modeling step and then calling the right solver.

### 1. One Variable Per Blend

Do **not** model decisions cheese-by-cheese.

The business decision is:

- how much of blend `j` to produce

So the LP variables are the blend amounts themselves.

### 2. One Upper Bound Per Cheese Type

Every cheese shipment gives one constraint.

If a blend uses `p_ij%` of cheese `i`, then one pound of that blend consumes:

$$
\frac{p_{ij}}{100}
$$

pounds of cheese `i`.

So the entire stock of cheese `i` becomes one linear inequality.

### 3. Profit Is Already Linear

Each pound of blend `j` adds profit `t_j`.

So the objective is simply:

$$
\sum_j t_j x_j.
$$

No nonlinear interaction survives the transformation.

## Implementation Plan

1. read the stock vector `w`
2. build an `n x m` matrix `A` where row `i`, column `j` is `p_ij / 100`
3. let `b = w`
4. let `c_j = t_j`
5. run simplex for:
   - `maximize c^T x`
   - `Ax <= b`
   - `x >= 0`
6. print the optimum rounded to the nearest cent

## Complexity

The practical contest complexity is:

- one dense simplex solve on at most `50 x 50`-style dimensions in the flagship task

That is exactly the scale where this generic route is still reasonable.

## Main Traps

- forgetting to divide the percentages by `100`
- modeling ingredient amounts as variables instead of blend amounts
- overthinking the problem into a graph or DP model
- assuming simplex gives an integer solution because the answer "looks like money"

## Reopen Path

- Topic page: [Simplex](../../../../topics/advanced/simplex/README.md)
- Practice ladder: [Simplex ladder](README.md)
- Starter template: [simplex-max-ax-le-b.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/advanced/simplex-max-ax-le-b.cpp)
- Notebook refresher: [Simplex hot sheet](../../../../notebook/simplex-hot-sheet.md)
- Compare points:
  - [Optimization And Duality](../../../../topics/advanced/optimization-and-duality/README.md)
  - [Min-Cost Flow](../../../../topics/graphs/min-cost-flow/README.md)

## Solutions

- Code: [cheeseifyouplease.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/simplex/cheeseifyouplease.cpp)

