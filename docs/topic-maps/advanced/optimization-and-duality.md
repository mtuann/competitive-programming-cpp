# Advanced -> Optimization And Duality

LP duality, convex relaxation, and the optimization language that later feeds into flow, DP tricks, and aliens-style reasoning.

- Topic slug: `advanced/optimization-and-duality`
- Tutorial page: [Open tutorial](../../../topics/advanced/optimization-and-duality/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/advanced/optimization-and-duality/README.md)
- Repo problems currently tagged here: `2`
- Repo companion pages: `2`
- Curated external problems: `6`

## Microtopics

- LP-duality
- complementary-slackness
- convex-relaxation
- Lagrangian-relaxation
- KKT-conditions
- subgradient-methods
- primal-dual-schema
- aliens-trick

## Learning Sources

| Source | Type |
| --- | --- |
| [Stanford EE364a](https://web.stanford.edu/class/ee364a/) | `Course` |
| [Boyd-Vandenberghe Convex Optimization](https://stanford.edu/~boyd/cvxbook/) | `Reference` |
| [Stanford CS261](https://theory.stanford.edu/~tim/cs261/cs261.html) | `Course` |

## Practice And Follow-Up Sources

| Source | Type |
| --- | --- |
| [EE364a duality notes](https://web.stanford.edu/class/ee364a/lectures/duality.pdf) | `Course` |
| [EE364b](https://web.stanford.edu/class/ee364b) | `Course` |
| [MS&E 310 Conic Linear Optimization](https://web.stanford.edu/class/msande310/course.shtml) | `Course` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Police Chase note](../../../practice/ladders/graphs/flow/policechase.md) | `bridge note` |
| [Maximum Flow tutorial](../../../topics/graphs/flow/README.md) | `adjacent tutorial` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Giant Pizza](https://cses.fi/problemset/task/1684) | `CSES` | `Medium` | - | Logical Modeling | 2-SAT; Implication Graphs | 2-SAT; Constraint Satisfaction | A good example of optimizing by encoding constraints into a solvable dual structure. |
| [Police Chase](https://cses.fi/problemset/task/1695) | `CSES` | `Medium` | - | - | - | Minimum Cut; Certificate; Flow Dual | Makes the cut side of flow duality explicit. |
| [School Dance](https://cses.fi/problemset/task/1696) | `CSES` | `Medium` | - | Augmenting Paths | Bipartite Matching | Matching; Bipartite Graphs; Flow; Bipartite Graph | A very approachable gateway into max-flow / matching duality. |
| [Distinct Routes](https://cses.fi/problemset/task/1711) | `CSES` | `Hard` | - | - | - | Edge-Disjoint Paths; Flow Decomposition; Packing | A strong path-packing formulation that broadens optimization modeling. |

### Challenge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Download Speed](https://cses.fi/problemset/task/1694) | `CSES` | `Hard` | - | Flow Modeling | Max Flow; Min Cut | Max Flow; Min Cut; Network Optimization; Duality Intuition | Max-flow/min-cut duality is the core lesson of this problem. |
| [Task Assignment](https://cses.fi/problemset/task/2129) | `CSES` | `Hard` | - | Exact Optimization | Matching; Cost Matrices | Assignment; Min-Cost Optimization; Min-Cost Flow; Bipartite Optimization | A textbook assignment problem with a natural dual interpretation. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `C11XU` | Bộ sưu tập đồng xu | `secondary` | `hard` | xor-independence; forest selection; augmenting exchange | [Note](../../../practice/ladders/data-structures/dsu/c11xu.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/dsu/c11xu.cpp) |
| `POLICECHASE` | Police Chase | `secondary` | `medium` | unit capacity max flow; residual reachable cut; minimum edge cut certificate | [Note](../../../practice/ladders/graphs/flow/policechase.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/flow/policechase.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
