# Geometry -> Right Triangles

A focused counting-geometry subtopic around perpendicular vectors, normalized slopes, and pivot-based counting.

- Topic slug: `geometry/right-triangles`
- Tutorial page: [Open tutorial](../../../topics/geometry/counting-geometry/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/geometry/right-triangles/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `0`
- Curated external problems: `5`

## Microtopics

- right-angle detection
- normalized-slope
- perpendicular-vectors
- pivot-counting
- integer-geometry
- direction-bucketing

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms basic geometry](https://cp-algorithms.com/geometry/basic-geometry.html) | `Reference` |
| [cp-algorithms oriented area](https://cp-algorithms.com/geometry/oriented-triangle-area.html) | `Reference` |
| [Princeton geometric primitives](https://www.cs.princeton.edu/courses/archive/fall10/cos226/lectures/99GeometricPrimitives-2x2.pdf) | `Course` |

## Practice And Follow-Up Sources

| Source | Type |
| --- | --- |
| [CSES Point Location Test](https://cses.fi/problemset/task/2189/) | `Practice` |
| [CSES Polygon Area](https://cses.fi/problemset/task/2191/) | `Practice` |
| [USACO contest archive](https://usaco.org/index.php?page=contests) | `Practice` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Triangle](https://codeforces.com/problemset/problem/18/A) | `Codeforces` | `Easy` | Classification | - | - | Distance-Checks; Integer-Grid; Right-Angle | A small but useful right-triangle recognition/classification task. |
| [Pythagorean Triples](https://codeforces.com/problemset/problem/707/C) | `Codeforces` | `Medium` | Number Theory | - | - | Integer-Sides; Construction; Pythagorean | Directly about right triangles and integer side lengths. |
| [Right Triangles](https://codeforces.com/problemset/problem/52/B) | `Codeforces` | `Medium` | Grid-Counting | Counting | Row/Column Counts | Combinatorics; Orthogonal; Stars-Grid | The standard orthogonal grid right-triangle counting problem. |
| [Triangle](https://codeforces.com/contest/407/problem/A) | `Codeforces` | `Medium` | Construction | - | - | Integer-Coordinates; Existence; Coordinate-Geometry | Constructing a right triangle with integer coordinates is core practice. |

### Challenge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Lovely Perfect Right Triangles](https://codeforces.com/gym/106215/problem/L) | `Codeforces Gym` | `Hard` | - | Enumeration; Number Theoretic Filtering | Pythagorean Triples; GCD | Number Theory; Counting | A harder right-triangle counting task with strong arithmetic structure. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `PRAVO` | Tam giác vuông | `primary` | `medium` | count right triangles; normalized directions; perpendicular pairing | [Note](../../../practice/ladders/geometry/right-triangles/pravo.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/right-triangles/pravo.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
