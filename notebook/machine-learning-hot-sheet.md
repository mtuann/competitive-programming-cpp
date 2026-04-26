# Machine Learning Hot Sheet

Use this page when the repo's exact ML route is:

- binary labels
- one linear separator
- perceptron updates only on mistakes
- linearly separable training data

## Do Not Use When

- probabilities or calibrated scores matter
- the data is not separable and no surrogate-loss route is being taught
- the real topic is [Gradient Descent](../topics/advanced/gradient-descent/README.md), logistic regression, or neural networks
- the task is normal CP modeling with full offline input

## Exact Route In This Repo

- classifier: `sign(w · x + b)`
- labels: `-1 / +1`
- update on mistake:
  - `w <- w + yx`
  - `b <- b + y`
- stop after one full pass with no mistakes

## Recognition Cues

- linearly separable data
- deterministic online update rule
- one hard classifier, not one probability model
- benchmark wants the perceptron specifically

## Core Invariants

- include a bias term
- update only when `y (w · x + b) <= 0`
- one clean pass is the convergence signal only under separability
- final weights are not unique; correctness is classification, not one exact parameter vector

## Main Traps

- forgetting the bias update
- silently assuming nonseparable data will still converge
- interpreting perceptron as a generic optimizer for all classifiers
- overclaiming this lane into full ML coverage

## Exact Starter In This Repo

- starter -> [`perceptron-linear-separable.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/advanced/perceptron-linear-separable.cpp)
- flagship rep -> [Perceptron Classification Benchmark](../practice/ladders/advanced/machine-learning-algorithms/perceptronclassification.md)
- compare sibling -> [Online Algorithms](../topics/advanced/online-algorithms/README.md)

## Reopen Paths

- full tutorial -> [Machine Learning Algorithms](../topics/advanced/machine-learning-algorithms/README.md)
- parent router -> [Advanced overview](../topics/advanced/README.md)
- retrieve layer -> [Build Kit](../docs/build-kit.md) and [Template Library](../template-library.md)
