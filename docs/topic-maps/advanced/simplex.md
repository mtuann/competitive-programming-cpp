# Advanced -> Simplex

Contest-time linear programming in the narrow max-form route maximize c^T x subject to Ax <= b and x >= 0.

- Topic slug: `advanced/simplex`
- Tutorial page: [Open tutorial](../../../topics/advanced/simplex/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/advanced/simplex/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `4`
- Curated external problems: `2`

## Microtopics

- linear-programming
- simplex-method
- phase-1-phase-2
- continuous-optimization
- resource-allocation-lp
- tableau-pivoting

## Learning Sources

| Source | Type |
| --- | --- |
| [KACTL Simplex header](https://raw.githubusercontent.com/kth-competitive-programming/kactl/main/content/numerical/Simplex.h) | `Reference` |
| [ICPC World Finals 2016 Problem I](https://icpc.global/worldfinals/problems/2016-ICPC-World-Finals/icpc2016.pdf) | `Practice` |
| [KTH Finals 2016 Solutions Overview](https://www.csc.kth.se/~austrin/icpc/finals2016solutions.pdf) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Kattis Cheese, If You Please](https://open.kattis.com/problems/cheeseifyouplease) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Simplex hot sheet](../../../notebook/simplex-hot-sheet.md) | `quick reference` |
| [Cheese, If You Please note](../../../practice/ladders/advanced/simplex/cheeseifyouplease.md) | `flagship note` |
| [Optimization And Duality tutorial](../../../topics/advanced/optimization-and-duality/README.md) | `compare point` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Cheese, If You Please](https://open.kattis.com/problems/cheeseifyouplease) | `Kattis` | `Medium-Hard` | Optimization, Linear Programming | Modeling; Floating Point | Linear Constraints; Continuous Variables | Continuous Optimization; Resource Allocation; Blending | The cleanest first simplex rep in the repo because the story is already one continuous blend-planning LP with one variable per product. |

### Challenge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Road Times](https://icpc.global/worldfinals/problems/2016-ICPC-World-Finals/icpc2016.pdf) | `ICPC World Finals` | `Very Hard` | Optimization, Linear Programming | Modeling; Theory-Heavy | Simplex; Shortest Paths; Optimization And Duality | LP Modeling; Shortest Paths; Challenge | A famous stretch problem where the LP layer is real contest substance, not just background theory. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `CHEESEIFYOUPLEASE` | Cheese, If You Please | `primary` | `hard` | - | [Note](../../../practice/ladders/advanced/simplex/cheeseifyouplease.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/simplex/cheeseifyouplease.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
