# Advanced -> Quantum Algorithms

Theory-breadth quantum coverage taught first through a classical simulator for the Deutsch-Jozsa promise problem and its Hadamard-layer amplitude invariant.

- Topic slug: `advanced/quantum-algorithms`
- Tutorial page: [Open tutorial](../../../topics/advanced/quantum-algorithms/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/advanced/quantum-algorithms/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `4`
- Curated external problems: `2`

## Microtopics

- deutsch-jozsa
- promise-problem
- phase-oracle
- hadamard-layer
- constant-vs-balanced
- quantum-simulator
- classical-transform-compare

## Learning Sources

| Source | Type |
| --- | --- |
| [MIT OCW 6.845 lecture note on Deutsch-Jozsa](https://ocw.mit.edu/courses/6-845-quantum-complexity-theory-fall-2010/resources/mit6_845f10_lec05/) | `Course` |
| [MIT 8.370x Quantum Information Science I](https://www.ocw.mit.edu/courses/8-370x-quantum-information-science-i-spring-2018/) | `Course` |
| [Watrous quantum computation notes](https://cs.uwaterloo.ca/~watrous/QC-notes/) | `Reference` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Quantum Algorithms hot sheet](../../../notebook/quantum-algorithms-hot-sheet.md) | `quick reference` |
| [Deutsch-Jozsa Oracle Benchmark](../../../practice/ladders/advanced/quantum-algorithms/deutschjozsa.md) | `flagship note` |
| [FWHT / XOR Convolution / Subset Convolution tutorial](../../../topics/dp/fwht-subset-convolution/README.md) | `compare point` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Deutsch-Jozsa Oracle Benchmark](https://ocw.mit.edu/courses/6-845-quantum-complexity-theory-fall-2010/resources/mit6_845f10_lec05/) | `MIT OCW 6.845` | `Theory` | Promise Problems | Theory Benchmark; Simulator | Boolean Cube; Signs | Deutsch-Jozsa; Phase Oracle; Hadamard; Constant Vs Balanced | The canonical first quantum benchmark for this repo because one clean amplitude invariant separates the promised constant and balanced oracle families. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Quantum computation notes](https://cs.uwaterloo.ca/~watrous/QC-notes/) | `Waterloo` | `Theory` | Further Theory | Lecture Notes; Theory Breadth | Deutsch-Jozsa; Hadamard Layers | Grover; Shor; Quantum States; Amplitudes | A strong follow-up once Deutsch-Jozsa is clear and you want broader theory without pretending the repo lane already covers full quantum implementation work. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `DEUTSCHJOZSA` | Deutsch-Jozsa Oracle Benchmark | `primary` | `medium` | - | [Note](../../../practice/ladders/advanced/quantum-algorithms/deutschjozsa.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/quantum-algorithms/deutschjozsa.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
