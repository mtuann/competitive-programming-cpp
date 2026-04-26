# Linear Regression Gradient Descent Benchmark

- Title: `Linear Regression Gradient Descent Benchmark`
- Judge / source: `Canonical first-order optimization benchmark`
- Original URL: [https://cs229.stanford.edu/summer2020/cs229-notes1.pdf](https://cs229.stanford.edu/summer2020/cs229-notes1.pdf)
- Secondary topics: `Batch gradient descent`, `Squared loss`, `Linear regression`
- Difficulty: `medium`
- Subtype: `Fixed-step full-batch gradient descent on one-feature linear regression`
- Status: `solved`
- Solution file: [linearregressiongd.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/gradient-descent/linearregressiongd.cpp)

## Why Practice This

This is the cleanest first in-repo anchor for `Gradient Descent`.

The benchmark is intentionally narrow:

- one feature
- one affine model
- one squared loss
- one batch gradient
- one deterministic update loop

So the whole lesson is exactly the lane itself:

- write the gradient
- update in the correct direction
- choose one stable learning rate
- watch the parameters move toward the optimum

## Recognition Cue

Reach for this route when:

- the benchmark explicitly wants gradient descent
- the loss is smooth and differentiable
- one tiny regression model is enough to teach the update rule

The strongest smell is:

```text
I want one honest first-order optimization benchmark, not a full ML or convex-optimization curriculum.
```

That is exactly this note.

## Problem-Specific Route

This repo's benchmark uses:

- one integer `n`
- one learning rate `alpha`
- one epoch count `epochs`
- `n` pairs `(x_i, y_i)`

The route is:

1. initialize `w = 0`, `b = 0`
2. repeat `epochs` times:
   - compute `dw` and `db` from the full batch
   - update `w` and `b`
3. print the final parameters

This is exactly the batch gradient-descent route in simulator form.

## Core Idea

The first route is not about solving linear regression in the smartest exact way.

It is about:

- the gradient as local direction information
- taking steps against that direction
- understanding the role of the learning rate

### 1. Loss

Use:

$$
J(w,b)=\frac{1}{2n}\sum_{i=1}^{n}(wx_i+b-y_i)^2.
$$

### 2. Gradient

Compute:

$$
dw=\frac{1}{n}\sum_{i=1}^{n}(wx_i+b-y_i)x_i,
\qquad
db=\frac{1}{n}\sum_{i=1}^{n}(wx_i+b-y_i).
$$

### 3. Update

Move against the gradient:

$$
w \leftarrow w-\alpha dw,
\qquad
b \leftarrow b-\alpha db.
$$

## Worked Example

For points:

```text
(0,1), (1,3), (2,5), (3,7)
```

the ideal line is:

```text
y = 2x + 1
```

Starting from zero, a moderate `alpha` and enough epochs move:

- `w` toward `2`
- `b` toward `1`

The benchmark prints those final learned parameters.

## Complexity

With `n` data points and `T` epochs:

- time = `O(Tn)`
- memory = `O(1)` beyond the input arrays

The benchmark is update-rule-first, not asymptotic-performance-first.

## Input / Output Contract For This Repo

This repo's benchmark uses:

- one line: `n alpha epochs`
- then `n` lines, each with `x y`

The solution prints exactly one line:

- `w b`

with fixed decimal formatting.

This is a repo-native benchmark, not one standard online judge task.

## Pitfalls / Judge Notes

- This is **batch** gradient descent, not SGD.
- The update is against the gradient, not with it.
- Large `alpha` can diverge.
- This benchmark is deterministic and fixed-step by design.
- This note does not stand in for momentum, Adam, or full optimizer engineering.

## Reusable Pattern

- Topic page: [Gradient Descent](../../../../topics/advanced/gradient-descent/README.md)
- Practice ladder: [Gradient Descent ladder](README.md)
- Starter template: [gradient-descent-linear-regression-1d.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/advanced/gradient-descent-linear-regression-1d.cpp)
- Notebook refresher: [Gradient Descent hot sheet](../../../../notebook/gradient-descent-hot-sheet.md)
- Compare points:
  - [Machine Learning Algorithms](../../../../topics/advanced/machine-learning-algorithms/README.md)
  - [Optimization And Duality](../../../../topics/advanced/optimization-and-duality/README.md)

## Solutions

- Code: [linearregressiongd.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/gradient-descent/linearregressiongd.cpp)
