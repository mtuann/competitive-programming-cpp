# Geometry -> Counting Geometry

Count intersections, lattice points, or union areas by mixing geometry primitives with combinatorics and data structures.

- Topic slug: `geometry/counting-geometry`
- Tutorial page: [Open tutorial](../../../topics/geometry/counting-geometry/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/geometry/counting-geometry/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `0`
- Curated external problems: `6`

## Microtopics

- Pick-theorem
- lattice-points
- intersection-counting
- union-area
- coordinate-compression
- fenwick-or-segtree

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms Pick's theorem](https://cp-algorithms.com/geometry/picks-theorem.html) | `trusted guide` |
| [cp-algorithms lattice points](https://cp-algorithms.com/geometry/lattice-points.html) | `trusted guide` |
| [USACO Guide range queries with sweep line](https://usaco.guide/plat/range-sweep) | `trusted guide` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Polygon Lattice Points](https://cses.fi/problemset/task/2193/) | `problem` |
| [CSES Intersection Points](https://cses.fi/problemset/task/1740) | `problem` |
| [CSES Area of Rectangles](https://cses.fi/problemset/task/1741) | `problem` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Polygon Lattice Points](https://cses.fi/problemset/task/2193) | `CSES` | `Medium` | - | Counting | GCD; Shoelace Formula | Lattice Points; Pick's Theorem | A perfect counting-geometry problem on polygons. |
| [Right Triangles](https://codeforces.com/problemset/problem/52/B) | `Codeforces` | `Medium` | - | Combinatorics | Row/Column Counting | Grid Geometry; Right Triangles | A grid-counting geometry problem with a simple but elegant formula. |
| [Satyam and Counting](https://codeforces.com/problemset/problem/2009/D) | `Codeforces` | `Hard` | Triangles | - | - | Points; Right-Triangles; Combinatorics | A modern CF counting-geometry task with triangle counting flavor. |
| [Triangles 3000](https://codeforces.com/problemset/problem/528/E) | `Codeforces` | `Very Hard` | Lines | - | - | Intersections; Triangle-Counting; Arrangements | A high-end geometric counting problem on line arrangements. |

### Challenge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Area of Rectangles](https://cses.fi/problemset/task/1741) | `CSES` | `Hard` | Union-Area | Coordinate Compression | Interval Counting | Area Union; Sweep Line; Measure; Events; Rectangle-Union | Area accumulation from geometric event processing. |
| [Intersection Points](https://cses.fi/problemset/task/1740) | `CSES` | `Hard` | Sweep-Line | Event Counting | - | Intersection Counting; Orthogonal-Segments; Events; Counts | Counts geometric events rather than constructing explicit shapes. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `PRAVO` | Tam giác vuông | `secondary` | `medium` | count right triangles; normalized directions; perpendicular pairing | [Note](../../../practice/ladders/geometry/right-triangles/pravo.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/right-triangles/pravo.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
