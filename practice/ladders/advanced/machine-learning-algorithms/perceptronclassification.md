# Perceptron Classification Benchmark

- Title: `Perceptron Classification Benchmark`
- Judge / source: `Canonical perceptron benchmark`
- Original URL: [https://cs229.stanford.edu/notes2021fall/cs229-notes6.pdf](https://cs229.stanford.edu/notes2021fall/cs229-notes6.pdf)
- Secondary topics: `Perceptron`, `Linear separability`, `Online updates`
- Difficulty: `medium`
- Subtype: `Linearly separable binary classification with mistake-driven updates`
- Status: `solved`
- Solution file: [perceptronclassification.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/machine-learning-algorithms/perceptronclassification.cpp)

## Why Practice This

This is the cleanest first in-repo anchor for `Machine Learning Algorithms`.

The benchmark is intentionally narrow:

- binary labels `-1 / +1`
- one linear separator
- one deterministic training order
- updates only on mistakes
- separable training data

So the whole lesson is exactly the lane itself:

- what the model is
- when updates happen
- why separability matters

## Recognition Cue

Reach for this route when:

- the benchmark explicitly wants perceptron-style learning
- one hard linear classifier is enough
- the training examples are separable or intentionally benchmarked as such

The strongest smell is:

```text
I want the first algorithmic ML update rule, not a whole statistics pipeline.
```

That is exactly this note.

## Problem-Specific Route

This repo's benchmark uses:

- `n` labeled training examples in `d` dimensions
- labels in `{-1, +1}`
- `q` query points to classify after training

The training rule is:

1. start from `w = 0`, `b = 0`
2. scan examples in deterministic input order
3. if `y (w · x + b) <= 0`, update:
   - `w <- w + yx`
   - `b <- b + y`
4. stop after one full pass with no mistakes

Then classify each query by:

$$
\operatorname{sign}(w \cdot x + b).
$$

## Core Idea

The perceptron is not a statistical black box in this route.

It is an algorithm with a tiny, explicit update rule.

### 1. One Hyperplane Model

The classifier is one sign test against one affine hyperplane.

### 2. Mistake-Driven Update

Nothing changes unless the current example is wrong or on the boundary.

### 3. Separability Is The Real Contract

This benchmark is honest only because the route assumes a separator exists.

Without that, the "train until a clean pass" story is no longer guaranteed.

## Complexity

If training converges after `P` full passes:

- training cost = `O(Pnd)`
- query cost = `O(qd)`

The point is not that this beats CP staples.
The point is that the update rule is algorithmically crisp and self-contained.

## Input / Output Contract For This Repo

This repo's benchmark uses:

- one line: `n d q`
- next `n` lines: `y x1 x2 ... xd`
- next `q` lines: `x1 x2 ... xd`

The solution prints:

- one line per query
- each line is either `1` or `-1`

This is a repo-native benchmark, not one standard OJ task.

## Pitfalls / Judge Notes

- The bias term is part of the model and must be updated.
- The route assumes separability; if you drop that assumption, convergence is no longer the same story.
- The final weight vector is not unique, so the benchmark checks predictions, not one exact parameter vector.
- This note is not a stand-in for logistic regression, SVMs, or deep learning.

## Reusable Pattern

- Topic page: [Machine Learning Algorithms](../../../../topics/advanced/machine-learning-algorithms/README.md)
- Practice ladder: [Machine Learning Algorithms ladder](README.md)
- Starter template: [perceptron-linear-separable.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/advanced/perceptron-linear-separable.cpp)
- Notebook refresher: [Machine Learning hot sheet](../../../../notebook/machine-learning-hot-sheet.md)
- Compare points:
  - [Online Algorithms](../../../../topics/advanced/online-algorithms/README.md)
  - [Randomized Algorithms](../../../../topics/advanced/randomized-algorithms/README.md)

## Solutions

- Code: [perceptronclassification.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/machine-learning-algorithms/perceptronclassification.cpp)
