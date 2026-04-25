# Math -> Probability

Finite-state probability modeling with PMFs, expectation, total probability, and exact discrete-process DP.

- Topic slug: `math/probability`
- Tutorial page: [Open tutorial](../../../topics/math/probability/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/math/probability/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `4`
- Curated external problems: `4`

## Microtopics

- probability-dp
- pmf
- expected-value
- linearity-of-expectation
- total-probability
- finite-state-process

## Learning Sources

| Source | Type |
| --- | --- |
| [Harvard Stat 110](https://stat110.hsites.harvard.edu/) | `Reference` |
| [MIT 18.600 Probability and Random Variables](https://ocw.mit.edu/courses/18-600-probability-and-random-variables-fall-2019/resources/lecture-notes/) | `Reference` |
| [Competitive Programmer's Handbook](https://usaco.guide/CPH.pdf) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Dice Probability](https://cses.fi/problemset/task/1725/) | `Practice` |
| [CSES Candy Lottery](https://cses.fi/problemset/task/1727/) | `Practice` |
| [CSES Moving Robots](https://cses.fi/problemset/task/1726/) | `Practice` |
| [CSES Inversion Probability](https://cses.fi/problemset/task/1728/) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Probability hot sheet](../../../notebook/probability-hot-sheet.md) | `quick reference` |
| [Dice Probability](../../../practice/ladders/math/probability/diceprobability.md) | `flagship note` |
| [Probability starter route](../../../template-library.md) | `starter route` |
| [Randomized Algorithms](../../../topics/advanced/randomized-algorithms/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Dice Probability](https://cses.fi/problemset/task/1725) | `CSES` | `Medium` | Distributions | Math; Dynamic Programming | Basic Probability; State DP | Probability-DP; Pmf; Dice | The cleanest first benchmark where an exact probability answer comes from propagating a bounded sum distribution over repeated random steps. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Moving Robots](https://cses.fi/problemset/task/1726) | `CSES` | `Hard` | Random Walks | Math; State Transitions | Probability DP; Independent Events | Transition-Probability; Independence; Expectation | A natural next step where one finite-state transition distribution is combined across many independent walkers. |

### Challenge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Inversion Probability](https://cses.fi/problemset/task/1728) | `CSES` | `Hard` | Expected Value | Math; Counting | Counting Basics | Linearity-Of-Expectation; Pairs; Expectation | A harder compare point where linearity of expectation beats any attempt to model the full joint distribution directly. |

### Bridge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Candy Lottery](https://cses.fi/problemset/task/1727) | `CSES` | `Medium` | Expected Value | Math; Observation | Basic Probability | Distribution-Of-Maximum; Independence | A strong compare point where the shortest solution derives a distribution first and only then takes expectation. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `DICEPROBABILITY` | Dice Probability | `primary` | `medium` | - | [Note](../../../practice/ladders/math/probability/diceprobability.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/probability/diceprobability.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
