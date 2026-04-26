# Gradient Descent

This lane exists as a **textbook-breadth advanced lane**, not as a claim that competitive programming now needs a full numerical-optimization or deep-learning stack.

The repo's exact first route is intentionally narrow:

- one differentiable loss
- one feature `x`
- one scalar prediction `wx + b`
- one full-batch gradient
- one fixed learning rate
- one fixed number of epochs

That means this page is **not**:

- a deep-learning page
- a stochastic-optimization page
- a momentum / Adam / RMSProp page
- a line-search or second-order optimization page
- a general unconstrained optimization curriculum

It is the first clean algorithmic route for:

- smooth differentiable loss minimization
- batch gradient descent
- learning-rate sensitivity
- one deterministic update loop for linear regression

with [Linear Regression Gradient Descent Benchmark](../../../practice/ladders/advanced/gradient-descent/linearregressiongd.md) as the flagship benchmark.

This page sits next to:

- [Machine Learning Algorithms](../machine-learning-algorithms/README.md) because this lane is the smooth-loss sibling of the perceptron route
- [Optimization And Duality](../optimization-and-duality/README.md) because that page owns benchmark / certificate language rather than iterative descent updates
- [Algorithm Engineering](../algorithm-engineering/README.md) when the real problem is scaling, numerics, or systems behavior rather than the first update rule itself

## At A Glance

- **Use when:**
  - you want the first honest route for minimizing one smooth loss by repeated gradient steps
  - the benchmark is fixed-step batch gradient descent
  - one-feature linear regression is enough to teach the update rule
  - the real lesson is `gradient -> step -> iterate`, not dual certificates or one closed-form exact solver
- **Prerequisites:**
  - [Reasoning](../../foundations/reasoning/README.md)
  - [Machine Learning Algorithms](../machine-learning-algorithms/README.md) only as a compare-point sibling, not a strict prerequisite
- **Boundary with nearby pages:**
  - use this page when the exact first route is `batch gradient descent on squared loss`
  - use [Machine Learning Algorithms](../machine-learning-algorithms/README.md) when the route is perceptron on separable data with mistake-driven updates
  - use [Optimization And Duality](../optimization-and-duality/README.md) when the missing piece is a benchmark, lower bound, or certificate instead of an update rule
- **Strongest cues:**
  - `loss`
  - `learning rate`
  - `epochs`
  - `gradient`
  - `convergence or divergence depending on step size`
- **Strongest anti-cues:**
  - the task really wants a closed-form exact solver and the update loop teaches nothing
  - the real topic is stochastic gradient descent or modern optimizer variants
  - the loss is nondifferentiable and the route really needs subgradients or another method
  - the lane would have to pretend this is high-ROI contest material
- **Success after studying this page:**
  - you can write the gradient update rule correctly
  - you know why the sign is `-gradient`, not `+gradient`
  - you know why feature scale and learning rate matter
  - you know why this lane is breadth, not CP-core

## Problem Model And Notation

The exact starter route in this repo uses one-feature linear regression:

$$
\hat y_i = wx_i + b.
$$

The loss is the half mean squared error:

$$
J(w,b)=\frac{1}{2n}\sum_{i=1}^{n}(wx_i+b-y_i)^2.
$$

Its batch gradients are:

$$
\frac{\partial J}{\partial w}=\frac{1}{n}\sum_{i=1}^{n}(wx_i+b-y_i)x_i,
\qquad
\frac{\partial J}{\partial b}=\frac{1}{n}\sum_{i=1}^{n}(wx_i+b-y_i).
$$

The update step with learning rate `alpha > 0` is:

$$
w \leftarrow w - \alpha \frac{\partial J}{\partial w},
\qquad
b \leftarrow b - \alpha \frac{\partial J}{\partial b}.
$$

The exact repo route starts from:

- `w = 0`
- `b = 0`

and repeats the batch update for a fixed number of epochs.

This is deliberate.

Why:

- it keeps the route deterministic
- it keeps the update rule completely explicit
- it avoids pretending the first lane is already about optimizer engineering or nonconvex training

## Why This Exists Next To Machine Learning Algorithms

[Machine Learning Algorithms](../machine-learning-algorithms/README.md) teaches:

- hard classification
- mistake-driven updates
- linear separability
- the perceptron

This page teaches a different first lens:

- smooth loss
- full-batch gradients
- learning-rate choice
- descent over a real-valued objective

So the division of labor is:

- **machine-learning page:** perceptron and separability
- **gradient-descent page:** smooth loss minimization through deterministic gradient steps

## Core Route In This Repo

The exact route is:

1. initialize `w = 0`, `b = 0`
2. for each epoch:
   - compute the full-batch gradients on all examples
   - update `w` and `b` once
3. return the final parameters

The exact starter contract is intentionally narrow:

- one feature only
- one affine model `wx + b`
- one squared loss only
- one fixed learning rate
- one full-batch update per epoch

The exact non-promises matter:

- no stochastic or mini-batch route
- no momentum / Adam / RMSProp
- no logistic regression
- no automatic convergence detection
- no claim that this is the right contest tool for ordinary offline problems

## Core Invariants

### 1. The Update Goes Against The Gradient

The gradient points toward local increase.

So the step must be:

$$
\theta \leftarrow \theta - \alpha \nabla J(\theta).
$$

Using `+gradient` is ascent, not descent.

### 2. Batch Gradient Means All Examples Contribute Before Each Step

This exact route is not online and not stochastic.

Each epoch:

- scans every training example
- sums their contribution
- performs one update

That full-batch invariant is the whole starter route.

### 3. The Learning Rate Is Part Of The Algorithm

Too small:

- convergence is slow

Too large:

- the loss may oscillate or diverge

The first route must say this out loud because the update rule is meaningless without step-size discipline.

## Worked Example: Linear Regression Gradient Descent Benchmark

Use [Linear Regression Gradient Descent Benchmark](../../../practice/ladders/advanced/gradient-descent/linearregressiongd.md).

Take points on the exact line:

- `(0, 1)`
- `(1, 3)`
- `(2, 5)`
- `(3, 7)`

The ideal parameters are:

- `w = 2`
- `b = 1`

Starting from zero and using a moderate learning rate, batch gradient descent moves the parameters toward that optimum over repeated epochs.

The benchmark is intentionally about:

- writing the gradient correctly
- updating in the right direction
- seeing stable convergence on one smooth, tiny loss

not about modern large-scale ML practice.

## Variant Chooser

| Situation | Best first move | Why it fits | Where it fails |
| --- | --- | --- | --- |
| one smooth differentiable loss and a deterministic update loop are the whole lesson | use this lane | gradient descent is exactly the intended first route | weak if the real task needs certificates, exact closed forms, or advanced optimizers |
| one hard linear classifier with separable labels is the intended benchmark | use [Machine Learning Algorithms](../machine-learning-algorithms/README.md) | the perceptron is the right first route there | weak if the real structure is smooth loss minimization |
| the proof is benchmark / certificate driven | use [Optimization And Duality](../optimization-and-duality/README.md) | that page owns the witness language | weak if the missing piece is still just the update rule |
| the real problem is scaling, numerics, or systems performance | use [Algorithm Engineering](../algorithm-engineering/README.md) | that page is better for engineering questions | weak if the route is still first-order optimization basics |

## Complexity And Tradeoffs

For `n` samples and `T` epochs, the exact route is:

- time = `O(Tn)`
- memory = `O(1)` beyond the input arrays

The main tradeoff is:

- very explicit smooth-loss update mechanics
versus
- zero pretense that this is already modern optimization practice

That is why the lane belongs in `advanced` and `breadth`.

## Main Traps

- using `+gradient` instead of `-gradient`
- forgetting the bias gradient
- mixing batch gradient descent with stochastic or mini-batch language
- choosing a learning rate that is so large the benchmark diverges
- pretending this first route already covers logistic regression or Adam

## Reopen Path

- Topic page: [Gradient Descent](README.md)
- Practice ladder: [Gradient Descent ladder](../../../practice/ladders/advanced/gradient-descent/README.md)
- Starter template: [gradient-descent-linear-regression-1d.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/advanced/gradient-descent-linear-regression-1d.cpp)
- Notebook refresher: [Gradient Descent hot sheet](../../../notebook/gradient-descent-hot-sheet.md)
- Compare points:
  - [Machine Learning Algorithms](../machine-learning-algorithms/README.md)
  - [Optimization And Duality](../optimization-and-duality/README.md)
  - [Linear Regression Gradient Descent Benchmark](../../../practice/ladders/advanced/gradient-descent/linearregressiongd.md)

## References And Practice

- [Stanford CS229 notes on linear regression and gradient descent](https://cs229.stanford.edu/summer2020/cs229-notes1.pdf)
- [MIT Open Learning Library: Gradient Descent](https://openlearninglibrary.mit.edu/courses/course-v1%3AMITx%2B6.036%2B1T2019/courseware/Week4/gradient_descent/)
- [MIT nonlinear optimization notes: Gradient descent and descent lemmas](https://www.mit.edu/~gfarina/2024/67220s24_L07_gradient_descent/)
