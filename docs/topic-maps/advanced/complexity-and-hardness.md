# Advanced -> Complexity And Hardness

Reductions, hardness classes, and the language for understanding when exact efficient algorithms are unlikely.

- Topic slug: `advanced/complexity-and-hardness`
- Tutorial page: [Open tutorial](../../../topics/advanced/complexity-and-hardness/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/advanced/complexity-and-hardness/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `2`
- Curated external problems: `5`

## Microtopics

- reductions
- NP-completeness
- hardness-vs-completeness
- lower-bounds
- P-NP-EXP-BPP
- decision-vs-optimization
- approximation-barriers

## Learning Sources

| Source | Type |
| --- | --- |
| [MIT 18.404J Theory of Computation](https://ocw.mit.edu/courses/18-404j-theory-of-computation-fall-2020/) | `Course` |
| [Computational Complexity: A Modern Approach](https://theory.cs.princeton.edu/complexity/) | `Reference` |
| [MIT 6.006 Lecture 19 Complexity](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/resources/lecture-19-complexity/) | `Course` |

## Follow-Up Reading

| Source | Type |
| --- | --- |
| [MIT 6.045J](https://ocw.mit.edu/courses/6-045j-automata-computability-and-complexity-spring-2011/) | `Course` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Book Shop note](../../../practice/ladders/dp/knapsack-family/bookshop.md) | `repo case study` |
| [Approximation tutorial](../../../topics/advanced/approximation-and-relaxation/README.md) | `related tutorial` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Problem Set 0](https://people.seas.harvard.edu/~salil/cs221/spring10/PS0.pdf) | `Harvard CS221` | `Theory` | - | - | - | Search Vs Decision; Reductions; Complexity Classes | A clean course-quality entry point for formal complexity reasoning. |
| [Problem Set 1](https://people.seas.harvard.edu/~salil/cs221/spring10/PS1.pdf) | `Harvard CS221` | `Theory` | - | - | - | P-Completeness; Circuit Complexity; Factoring | Covers several central reductions and class-separation themes in one place. |
| [Problem Set 3](https://people.seas.harvard.edu/~salil/cs221/spring10/PS3.pdf) | `Harvard CS221` | `Theory` | - | - | - | PSPACE; Branching Programs; Circuit Lower Bounds | Very good practice for moving between models of computation. |
| [Problem Set 4](https://people.seas.harvard.edu/~salil/cs221/spring10/PS4.pdf) | `Harvard CS221` | `Theory` | - | - | - | Promise Problems; #P; Approximation Hardness | Bridges exact complexity language with counting and approximation hardness. |
| [Problem Set 6](https://people.seas.harvard.edu/~salil/cs221/spring10/PS6.pdf) | `Harvard CS221` | `Theory` | - | - | - | PCP; Property Testing; Hardness Of Approximation | A strong advanced capstone on implications, PCPs, and testing/hardness themes. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `BOOKSHOP` | Book Shop | `secondary` | `easy` | 0 1 knapsack; downward capacity loop; budget value maximization | [Note](../../../practice/ladders/dp/knapsack-family/bookshop.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/knapsack-family/bookshop.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
