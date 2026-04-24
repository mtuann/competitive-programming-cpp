# Advanced -> Randomized Algorithms

Monte Carlo and Las Vegas design, amplification, randomized rounding, and probability-backed correctness guarantees.

- Topic slug: `advanced/randomized-algorithms`
- Tutorial page: [Open tutorial](../../../topics/advanced/randomized-algorithms/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/advanced/randomized-algorithms/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `2`
- Curated external problems: `9`

## Microtopics

- Las-Vegas
- Monte-Carlo
- amplification
- concentration-bounds
- universal-hashing
- min-cut
- randomized-rounding
- Yao-minimax

## Learning Sources

| Source | Type |
| --- | --- |
| [MIT 6.856 Randomized Algorithms](https://courses.csail.mit.edu/6.856/current/) | `course` |
| [MIT OCW 6.856J](https://ocw.mit.edu/courses/6-856j-randomized-algorithms-fall-2002/) | `course` |
| [CMU 15-756 Randomized Algorithms](https://csd.cs.cmu.edu/course/15756/f24) | `course` |

## Practice Sources

| Source | Type |
| --- | --- |
| [MIT 6.856 notes and problem sets](https://courses.csail.mit.edu/6.856/current/) | `course exercises` |
| [MIT OCW 6.856J lecture notes](https://www.ocw.mit.edu/courses/6-856j-randomized-algorithms-fall-2002/resources/lecture-notes/) | `course exercises` |
| [CMU 15-359 Probability and Computing](https://www.csd.cmu.edu/course/15359/f24) | `course exercises` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Hashing tutorial](../../../topics/strings/hashing/README.md) | `repo case study` |
| [Hashing ladder](../../../practice/ladders/strings/hashing/README.md) | `adjacent ladder` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Problem Set 1](https://www.cs.utexas.edu/~ecprice/courses/randomized/fa19/psets/randomized-ps1.pdf) | `UT Austin CS388R` | `Theory` | - | - | - | Min-Cut; Sampling; Expected Complexity | A strong theory-first warmup on randomized design and analysis from an algorithms course. |

### Challenge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Problem with Random Tests](https://codeforces.com/problemset/problem/1743/D) | `Codeforces` | `Hard` | - | Probabilistic Reasoning | Expected Value; Randomized Thinking | Probability; Adversarial Tests | A direct fit for understanding how random testing interacts with algorithm design. |
| [Wizards and Huge Prize](https://codeforces.com/problemset/problem/105/B) | `Codeforces` | `Hard` | - | Probabilistic Model | Probability Basics | Probability; Randomization; Expected Value | A classic probability-heavy contest problem. |
| [Gosha is hunting](https://codeforces.com/problemset/problem/739/E) | `Codeforces` | `Very Hard` | - | Stochastic Analysis | Probability; DP | Probability; Randomization; Expected Value | A high-end probabilistic problem that rewards careful randomized analysis. |
| [Isaac's Queries](https://codeforces.com/problemset/problem/2157/G) | `Codeforces` | `Very Hard` | - | Interactive Reasoning | Probability; Interactive Protocols | Probability; Interactive | A modern hard problem where randomness and interaction both matter. |

### Cross-Topic

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Journey](https://codeforces.com/problemset/problem/839/C) | `Codeforces` | `Medium` | Tree Expectation, Expected Value | DFS Expectation | Tree DFS; Basic Probability | Tree DFS; Probability | A friendly bridge from tree DFS into expectation, best framed here as cross-topic probability practice. |
| [Control of Randomness](https://codeforces.com/problemset/problem/2040/E) | `Codeforces` | `Hard` | Probability On Trees, Tree DP | Tree DP; Case Analysis | Basic Probability | Probability; Expected Process | Better treated as a cross-topic probability-on-trees exercise than as a pure randomized-design core problem. |
| [I Love Balls](https://codeforces.com/problemset/problem/1983/E) | `Codeforces` | `Hard` | Probability DP, Expected Value | State Expectation | Basic Probability; DP States | Game Process | A strong cross-topic expectation/DP problem that supports randomized-thinking practice without being a randomized-design essential. |
| [Expected Value Again](https://codeforces.com/problemset/problem/1205/E) | `Codeforces` | `Very Hard` | Combinatorial Expectation, Expected Value | Counting; Expectation Analysis | Basic Probability; Combinatorics | Combinatorics | A very hard cross-topic expectation/combinatorics exercise rather than a primary randomized-algorithms core item. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `FINDINGBORDERS` | Finding Borders | `secondary` | `easy` | rolling hash; prefix-suffix equality; proper borders enumeration | [Note](../../../practice/ladders/strings/hashing/findingborders.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/hashing/findingborders.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
