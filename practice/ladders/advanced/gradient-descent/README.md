# Gradient Descent Ladder

## Who This Is For

Use this ladder only when you intentionally want one smooth-loss optimization benchmark inside an algorithms repo, not because you expect high contest ROI.

## Warm-Up

- state the squared-loss objective for one-feature linear regression
- derive the gradients with respect to `w` and `b`
- explain why the sign must be `-gradient`

## Core

- one deterministic batch gradient step
- one fixed learning rate
- one fixed epoch count
- convergence intuition on a tiny regression benchmark

## Repo Anchors

- [Linear Regression Gradient Descent Benchmark](linearregressiongd.md)
- [Machine Learning Algorithms](../machine-learning-algorithms/README.md)
- [Optimization And Duality](../optimization-and-duality/README.md)

## Stretch

- explain why SGD is not the same contract as this lane
- compare gradient descent with the perceptron update rule
- explain why feature scaling changes practical convergence speed

## Compare Points

- first smooth-loss optimizer benchmark -> [Linear Regression Gradient Descent Benchmark](linearregressiongd.md)
- hard classification sibling -> [Machine Learning Algorithms](../machine-learning-algorithms/README.md)
- certificate / benchmark sibling -> [Optimization And Duality](../optimization-and-duality/README.md)

This ladder is intentionally tiny.

The point is not to turn the repo into a full numerical optimization course.
The point is to keep one source-backed `gradient -> step -> iterate` lane explicit and honest.

## Exit Criteria

You are ready to move on when you can:

- write the batch gradient correctly
- explain the role of `alpha`
- say clearly why this repo lane is fixed-step breadth, not full modern optimization coverage

## External Practice

- [Stanford CS229 notes on linear regression and gradient descent](https://cs229.stanford.edu/summer2020/cs229-notes1.pdf)
- [MIT Open Learning Library: Gradient Descent](https://openlearninglibrary.mit.edu/courses/course-v1%3AMITx%2B6.036%2B1T2019/courseware/Week4/gradient_descent/)
- [MIT nonlinear optimization notes: Gradient descent and descent lemmas](https://www.mit.edu/~gfarina/2024/67220s24_L07_gradient_descent/)

## Tutorial Link

- [Gradient Descent](../../../../topics/advanced/gradient-descent/README.md)
