# Advanced -> Gradient Descent

Theory-breadth smooth optimization taught first through fixed-step batch gradient descent on one-feature linear regression with squared loss.

- Topic slug: `advanced/gradient-descent`
- Tutorial page: [Open tutorial](../../../topics/advanced/gradient-descent/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/advanced/gradient-descent/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `4`
- Curated external problems: `2`

## Microtopics

- gradient-descent
- batch-gradient
- squared-loss
- linear-regression
- learning-rate
- epochs
- smooth-optimization

## Learning Sources

| Source | Type |
| --- | --- |
| [Stanford CS229 notes on linear regression](https://cs229.stanford.edu/summer2020/cs229-notes1.pdf) | `Course` |
| [MIT Open Learning Library gradient descent chapter](https://openlearninglibrary.mit.edu/courses/course-v1%3AMITx%2B6.036%2B1T2019/courseware/Week4/gradient_descent/) | `Course` |
| [MIT nonlinear optimization notes on gradient descent](https://www.mit.edu/~gfarina/2024/67220s24_L07_gradient_descent/) | `Course` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Gradient Descent hot sheet](../../../notebook/gradient-descent-hot-sheet.md) | `quick reference` |
| [Linear Regression Gradient Descent Benchmark](../../../practice/ladders/advanced/gradient-descent/linearregressiongd.md) | `flagship note` |
| [Machine Learning Algorithms tutorial](../../../topics/advanced/machine-learning-algorithms/README.md) | `compare point` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Linear Regression Gradient Descent Benchmark](https://cs229.stanford.edu/summer2020/cs229-notes1.pdf) | `Stanford CS229` | `Theory` | Smooth Optimization | Theory Benchmark; Deterministic Update Rule | Affine Models; Derivatives; Basic Algebra | Linear Regression; Squared Loss; Learning Rate | The cleanest first gradient-descent benchmark for this repo because one affine model and one smooth loss make the update rule completely explicit without pretending to cover modern optimizer families. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Gradient descent](https://openlearninglibrary.mit.edu/courses/course-v1%3AMITx%2B6.036%2B1T2019/courseware/Week4/gradient_descent/) | `MIT Open Learning Library` | `Theory` | Further Theory | Course Notes; Theory Breadth | Gradient; Learning Rate | Convexity; Step Size; Convergence; Optimization | A good follow-up once the repo benchmark is clear and you want broader smooth-optimization intuition without widening the lane into full numerical optimization coverage. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `LINEARREGRESSIONGD` | Linear Regression Gradient Descent Benchmark | `primary` | `medium` | - | [Note](../../../practice/ladders/advanced/gradient-descent/linearregressiongd.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/gradient-descent/linearregressiongd.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
