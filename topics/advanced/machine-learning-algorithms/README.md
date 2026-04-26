# Machine Learning Algorithms

This lane exists as a **textbook-breadth advanced lane**, not as a claim that competitive programming suddenly needs a full machine-learning toolkit.

The repo's exact first route is intentionally narrow:

- binary classification
- linear separator
- deterministic example order
- mistake-driven online updates
- linearly separable training data

That means this page is **not**:

- a general ML course
- a statistics page
- a deep-learning page
- a [Gradient Descent](../gradient-descent/README.md) lane

It is the first clean algorithmic route for:

- the perceptron update rule
- linearly separable data
- online mistake-driven learning
- a lightweight bridge from algorithms into one classical ML algorithm

with [Perceptron Classification Benchmark](../../../practice/ladders/advanced/machine-learning-algorithms/perceptronclassification.md) as the flagship benchmark.

This page sits next to:

- [Online Algorithms](../online-algorithms/README.md) because the perceptron is an online update rule driven by mistakes
- [Gradient Descent](../gradient-descent/README.md) when the real lesson is smooth loss minimization rather than mistake-driven separable classification
- [Randomized Algorithms](../randomized-algorithms/README.md) when the missing idea is probabilistic design rather than deterministic learning updates
- [Algorithm Engineering](../algorithm-engineering/README.md) when the question is scaling and systems practice, not the core learning rule

## At A Glance

- **Use when:**
  - you want the first algorithmic ML benchmark that still feels like an algorithms page
  - the data is linearly separable or intentionally benchmarked as such
  - the model is one hyperplane classifier with online updates
  - the real lesson is the update rule, not statistical evaluation or deployment
- **Prerequisites:**
  - [Reasoning](../../foundations/reasoning/README.md)
  - [Online Algorithms](../online-algorithms/README.md) as a useful sibling
- **Boundary with nearby pages:**
  - use this page when the exact first route is `perceptron on separable data`
  - use [Online Algorithms](../online-algorithms/README.md) when the primary lens is competitive ratio against offline OPT
  - do not use this lane when the problem is really optimization with known full input, or when you need modern ML pipelines
- **Strongest cues:**
  - binary labels such as `-1 / +1`
  - one linear separator is the model
  - the algorithm updates only on mistakes
  - the benchmark assumes linearly separable training data
- **Strongest anti-cues:**
  - the data is not separable and no surrogate-loss route is provided
  - the real topic is [Gradient Descent](../gradient-descent/README.md) or convex optimization
  - the task needs probabilities, calibration, or real-valued logistic outputs
  - the statement is a full ML system problem, not one learning-rule benchmark
- **Success after studying this page:**
  - you can state the perceptron update rule cleanly
  - you know the exact role of linear separability in convergence
  - you know why this lane is breadth, not CP-core

## Problem Model And Notation

The exact starter route in this repo uses:

- feature vectors `x_i in Z^d`
- labels `y_i in {-1, +1}`
- one affine classifier:

$$
f(x) = \operatorname{sign}(w \cdot x + b)
$$

The exact update rule is:

- if example `(x_i, y_i)` is classified correctly, do nothing
- if it is misclassified or lies on the wrong side of the boundary, update:

$$
w \leftarrow w + y_i x_i,\qquad b \leftarrow b + y_i
$$

The repo's exact first route assumes the training data is linearly separable, so one full pass with no mistakes is the stopping condition.

This is deliberate.

Why:

- it keeps the algorithmic invariant honest
- it makes convergence behavior clean to explain
- it avoids pretending the first repo route is full empirical ML

## Why This Exists Next To Online Algorithms

[Online Algorithms](../online-algorithms/README.md) teaches:

- future is hidden
- decisions are made online
- quality is measured against an offline optimum

This page teaches a different online-style benchmark:

- examples arrive in sequence
- the model changes only when it makes a mistake
- quality is not a competitive ratio
- quality is whether one separator can eventually classify the separable training set

So the division of labor is:

- **online-algorithms page:** adversarial future, benchmark against `OPT`
- **machine-learning page:** mistake-driven perceptron updates on labeled examples

## Core Route In This Repo

The exact route is:

1. start with `w = 0` and `b = 0`
2. scan training examples in deterministic input order
3. whenever `y_i (w · x_i + b) <= 0`, apply one perceptron update
4. stop after one full pass with no mistakes

The exact starter contract is intentionally narrow:

- binary labels only
- integer features
- deterministic order
- separable data assumed
- returned model supports only hard `-1 / +1` prediction

The exact non-promises matter:

- no logistic regression
- no probability estimates
- no [Gradient Descent](../gradient-descent/README.md)
- no nonseparable convergence guarantee
- no claim that this is a contest-high-ROI lane

## Core Invariants

### 1. The Model Is One Hyperplane

The whole exact route is about one linear separator.

If the real structure is nonlinear, kernelized, or probabilistic, this starter is no longer the right benchmark.

### 2. Updates Happen Only On Mistakes

The perceptron is not "nudge weights every step."

It is:

- predict
- check sign
- update only when the sign is wrong or zero

That mistake-driven discipline is the entire route.

### 3. Linear Separability Is The Honest Boundary

The first route assumes there exists some `(w*, b*)` that separates the two classes.

Without that assumption:

- convergence is no longer guaranteed
- "one clean pass means done" may never happen

So the lane must say this assumption out loud.

## Worked Example: Perceptron Classification Benchmark

Use [Perceptron Classification Benchmark](../../../practice/ladders/advanced/machine-learning-algorithms/perceptronclassification.md).

Take training points in `2D`:

- positive: `(2, 1)`, `(1, 2)`
- negative: `(-1, -2)`, `(-2, -1)`

These are linearly separable by a line through the origin with positive slope-normal.

Starting from zero weights, the perceptron updates until one full pass makes no mistakes.

After training, query points such as:

- `(3, 1)` should be predicted `+1`
- `(-1, -3)` should be predicted `-1`

The benchmark is intentionally about:

- update rule
- convergence on separable data
- hard-sign prediction

not about one statistically realistic dataset.

## Variant Chooser

| Situation | Best first move | Why it fits | Where it fails |
| --- | --- | --- | --- |
| one linearly separable binary classifier with online mistake-driven updates is the whole lesson | use this lane | the perceptron is exactly the intended first route | weak if the data is not separable or probabilities matter |
| the main lesson is adversarial online benchmarking against hindsight optimum | use [Online Algorithms](../online-algorithms/README.md) | the benchmark is competitive ratio, not training updates | weak if you really need a classifier |
| the real method is convex loss minimization or [Gradient Descent](../gradient-descent/README.md) | do not use this first route | the repo does not advertise that as part of this starter | weak if you force perceptron onto a smoother optimization problem |
| the problem is standard contest modeling with full offline input | use the specialized CP family | ML framing is probably artificial | weak if the statement truly is a learning-rule benchmark |

## Complexity And Tradeoffs

For `n` examples in dimension `d`, one pass costs:

- `O(nd)`

If convergence happens after `P` passes, the total route is:

- `O(Pnd)`

The important tradeoff is not asymptotic novelty.

It is:

- extremely small implementation surface
versus
- a very strong assumption boundary (`linearly separable`)

That is why this lane belongs in `advanced` and `breadth`, not in CP core.

## Main Traps

- forgetting the bias term
- updating on every example instead of only mistakes
- assuming convergence without checking separability assumptions
- treating the final weights as unique or canonical
- overclaiming from perceptron to "machine learning" in general

## Reopen Path

- Topic page: [Machine Learning Algorithms](README.md)
- Practice ladder: [Machine Learning Algorithms ladder](../../../practice/ladders/advanced/machine-learning-algorithms/README.md)
- Starter template: [perceptron-linear-separable.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/advanced/perceptron-linear-separable.cpp)
- Notebook refresher: [Machine Learning hot sheet](../../../notebook/machine-learning-hot-sheet.md)
- Compare points:
  - [Online Algorithms](../online-algorithms/README.md)
  - [Randomized Algorithms](../randomized-algorithms/README.md)
  - [Perceptron Classification Benchmark](../../../practice/ladders/advanced/machine-learning-algorithms/perceptronclassification.md)

## References And Practice

- [Stanford CS229 materials](https://cs229.stanford.edu/materials.html-withcomments)
- [Stanford CS229 notes: Perceptron](https://cs229.stanford.edu/notes2021fall/cs229-notes6.pdf)
- [MIT OCW 6.867 lec2](https://ocw.mit.edu/courses/6-867-machine-learning-fall-2006/resources/lec2/)
