# Advanced -> Machine Learning Algorithms

Textbook-breadth algorithmic ML taught first through the perceptron update rule on linearly separable binary data.

- Topic slug: `advanced/machine-learning-algorithms`
- Tutorial page: [Open tutorial](../../../topics/advanced/machine-learning-algorithms/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/advanced/machine-learning-algorithms/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `4`
- Curated external problems: `2`

## Microtopics

- perceptron
- binary-classification
- linear-separability
- mistake-driven-update
- bias-term
- online-learning-compare
- gradient-descent-boundary

## Learning Sources

| Source | Type |
| --- | --- |
| [Stanford CS229 materials](https://cs229.stanford.edu/materials.html-withcomments) | `Course` |
| [Stanford CS229 notes: Perceptron](https://cs229.stanford.edu/notes2021fall/cs229-notes6.pdf) | `Course` |
| [MIT OCW 6.867 lec2](https://ocw.mit.edu/courses/6-867-machine-learning-fall-2006/resources/lec2/) | `Course` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Machine Learning hot sheet](../../../notebook/machine-learning-hot-sheet.md) | `quick reference` |
| [Perceptron Classification Benchmark](../../../practice/ladders/advanced/machine-learning-algorithms/perceptronclassification.md) | `flagship note` |
| [Online Algorithms tutorial](../../../topics/advanced/online-algorithms/README.md) | `compare point` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Perceptron Classification Benchmark](https://cs229.stanford.edu/notes2021fall/cs229-notes6.pdf) | `Stanford CS229` | `Theory` | Machine Learning, Perceptron | Theory Benchmark; Online Update Rule | Dot Product; Signs And Margins; Basic Online Updates | Binary Classification; Linear Separability; Mistake-Driven Update | The cleanest first algorithmic ML benchmark for this repo because the update rule is tiny, explicit, and honest about the separability boundary. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Perceptron, convergence, and generalization](https://ocw.mit.edu/courses/6-867-machine-learning-fall-2006/resources/lec2/) | `MIT OCW 6.867` | `Theory` | Machine Learning, Margins | Lecture Notes; Theory Breadth | Perceptron; Linear Separability | Perceptron; Convergence; Generalization | A strong follow-up once the repo benchmark is clear and you want the surrounding theory without widening the lane into full modern ML. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `PERCEPTRONCLASSIFICATION` | Perceptron Classification Benchmark | `primary` | `medium` | - | [Note](../../../practice/ladders/advanced/machine-learning-algorithms/perceptronclassification.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/machine-learning-algorithms/perceptronclassification.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
