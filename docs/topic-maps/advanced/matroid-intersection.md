# Advanced -> Matroid Intersection

Maximum-cardinality common independent set on one explicit ground set using exchange-graph augmentation and structure-aware matroid modeling.

- Topic slug: `advanced/matroid-intersection`
- Tutorial page: [Open tutorial](../../../topics/advanced/matroid-intersection/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/advanced/matroid-intersection/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `1`

## Microtopics

- matroid-intersection
- exchange-graph
- augmenting-paths
- partition-matroid
- linear-matroid
- independence-oracles

## Learning Sources

| Source | Type |
| --- | --- |
| [Extremal Combinatorics notes: Matroid Intersection](https://extremalcombinatorics.com/optimization/notes/sec_matroidIntersection.html) | `Reference` |
| [Codeforces Gym 102156 D - Pick Your Own Nim](https://codeforces.com/gym/102156/problem/D) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Matroid Intersection hot sheet](../../../notebook/matroid-intersection-hot-sheet.md) | `quick reference` |
| [Pick Your Own Nim note](../../../practice/ladders/advanced/matroid-intersection/pickyourownnim.md) | `flagship note` |
| [Optimization And Duality tutorial](../../../topics/advanced/optimization-and-duality/README.md) | `compare point` |
| [XOR Basis tutorial](../../../topics/math/xor-basis/README.md) | `compare point` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Pick Your Own Nim](https://codeforces.com/gym/102156/problem/D) | `Codeforces Gym` | `Very Hard` | Optimization | Modeling; Augmenting Path; Theory-Heavy | XOR Basis; Matching; Optimization And Duality | Partition Matroid; Linear Matroid; XOR Basis | A clean contest anchor where one choice per box forms a partition matroid and the xor-independence condition forms a linear matroid relative to Alice's fixed heaps. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `PICKYOUROWNNIM` | Pick Your Own Nim | `primary` | `very-hard` | - | [Note](../../../practice/ladders/advanced/matroid-intersection/pickyourownnim.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/matroid-intersection/pickyourownnim.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
