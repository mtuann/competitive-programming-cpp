# Math -> Linear Recurrence And Matrix Exponentiation

Fixed-width linear recurrences and repeated small linear transitions, turned into companion matrices and powered quickly by repeated squaring.

- Topic slug: `math/linear-recurrence`
- Tutorial page: [Open tutorial](../../../topics/math/linear-recurrence/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/math/linear-recurrence/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `3`
- Curated external problems: `3`

## Microtopics

- companion-matrix
- state-vector
- matrix-power
- linear-transition
- recurrence-jump
- fast-doubling-compare

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms Fibonacci numbers](https://cp-algorithms.com/algebra/fibonacci-numbers.html) | `Reference` |
| [Competitive Programmer's Handbook](https://usaco.guide/CPH.pdf) | `Reference` |
| [Principles of Algorithmic Problem Solving](https://usaco.guide/PAPS.pdf) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Throwing Dice](https://cses.fi/problemset/task/1096/) | `Practice` |
| [CSES Fibonacci Numbers](https://cses.fi/problemset/task/1722/) | `Practice` |
| [CSES Graph Paths I](https://cses.fi/problemset/task/1723/) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Linear Recurrence hot sheet](../../../notebook/linear-recurrence-hot-sheet.md) | `quick reference` |
| [Throwing Dice](../../../practice/ladders/math/linear-recurrence/throwingdice.md) | `flagship note` |
| [Templates overview](../../../template-library.md) | `template guide` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Fibonacci Numbers](https://cses.fi/problemset/task/1722) | `CSES` | `Medium` | Matrix/Recurrence | Math; Implementation | Binary Exponentiation; Modular Arithmetic | Matrix Exponentiation; Fibonacci; Fast Doubling Compare | The smallest exact recurrence-lifting example and the cleanest compare point against fast doubling. |
| [Throwing Dice](https://cses.fi/problemset/task/1096) | `CSES` | `Medium` | DP/Recurrences | Dynamic Programming; Math | Basic DP; Modular Arithmetic | Matrix Exponentiation; Companion Matrix; Mod Arithmetic | A fixed-width order-6 recurrence where huge n turns an ordinary DP into a companion-matrix route. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Graph Paths I](https://cses.fi/problemset/task/1723) | `CSES` | `Hard` | Graphs/Walk Counting | Graphs; Math | Matrix Exponentiation; Graph Modeling | Matrix Exponentiation; Adjacency Matrix; Walk Counting | Shows the same repeated-linear-transition worldview outside one-dimensional recurrences. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `THROWINGDICE` | Throwing Dice | `primary` | `medium` | linear recurrence; companion matrix; matrix exponentiation | [Note](../../../practice/ladders/math/linear-recurrence/throwingdice.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/linear-recurrence/throwingdice.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
