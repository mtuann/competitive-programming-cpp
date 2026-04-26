# Gradient Descent Hot Sheet

Use this page when the repo's exact gradient-descent route is:

- one smooth squared loss
- one feature `x`
- one affine model `wx + b`
- one full-batch gradient
- one fixed learning rate and epoch count

## Do Not Use When

- the task really wants a closed-form exact solver
- the real topic is perceptron / separability, not smooth loss descent
- the route needs SGD, momentum, Adam, or line search
- the task is normal CP modeling with full offline input and no reason to optimize iteratively

## Exact Route In This Repo

- model: `wx + b`
- loss:
  - `J(w,b) = (1 / 2n) * sum (wx + b - y)^2`
- batch gradients:
  - `dw = (1 / n) * sum (pred - y) * x`
  - `db = (1 / n) * sum (pred - y)`
- update:
  - `w <- w - alpha * dw`
  - `b <- b - alpha * db`

## Recognition Cues

- smooth differentiable loss
- learning rate / epochs are explicit inputs
- one update loop is the whole lesson
- the benchmark wants gradient descent specifically

## Core Invariants

- subtract the gradient, do not add it
- batch mode means all examples contribute before each update
- feature scale and learning rate matter directly
- the first route is deterministic and fixed-step

## Main Traps

- forgetting the bias term
- using ascent by mistake
- mixing batch GD language with SGD behavior
- picking an `alpha` that makes the benchmark explode
- overclaiming this lane into full modern optimization coverage

## Exact Starter In This Repo

- starter -> [`gradient-descent-linear-regression-1d.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/advanced/gradient-descent-linear-regression-1d.cpp)
- flagship rep -> [Linear Regression Gradient Descent Benchmark](../practice/ladders/advanced/gradient-descent/linearregressiongd.md)
- compare siblings:
  - [Machine Learning Algorithms](../topics/advanced/machine-learning-algorithms/README.md)
  - [Optimization And Duality](../topics/advanced/optimization-and-duality/README.md)

## Reopen Paths

- full tutorial -> [Gradient Descent](../topics/advanced/gradient-descent/README.md)
- parent router -> [Advanced overview](../topics/advanced/README.md)
- retrieve layer -> [Build Kit](../docs/build-kit.md) and [Template Library](../template-library.md)
