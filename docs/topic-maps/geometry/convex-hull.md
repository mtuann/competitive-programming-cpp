# Geometry -> Convex Hull

Build hulls with monotone chain or Graham scan, then exploit hull order for rotating-calipers style tasks.

- Topic slug: `geometry/convex-hull`
- Tutorial page: [Open tutorial](../../../topics/geometry/convex-hull/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/geometry/convex-hull/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `0`
- Curated external problems: `6`

## Microtopics

- graham-scan
- monotone-chain
- sorting-by-angle
- collinear-points
- upper-lower-hull
- rotating-calipers

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms convex hull](https://cp-algorithms.com/geometry/convex-hull.html) | `Reference` |
| [USACO Guide convex hull](https://usaco.guide/plat/convex-hull) | `Reference` |
| [Topcoder geometry concepts part 2](https://www.topcoder.com/community/competitive-programming/tutorials/geometry-concepts-line-intersection-and-its-applications/) | `Essay / Blog` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Convex Hull](https://cses.fi/problemset/task/2195) | `Practice` |
| [CSES Polygon Area](https://cses.fi/problemset/task/2191/) | `Practice` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Convex Hull](https://cses.fi/problemset/task/2195) | `CSES` | `Medium` | Sorting | Sorting; Stack/Scan | Orientation Test; Sorting Points | Orientation; Monotone-Chain; Boundary | The canonical Andrew monotone-chain convex hull problem. |
| [Convex Hull Extension](https://codeforces.com/gym/104757/problem/C) | `Codeforces Gym` | `Hard` | Extension | - | - | Hull-Expansion; Distance; Construction | Official contest problem centered on manipulating an existing hull. |
| [Polygons](https://codeforces.com/problemset/problem/166/B) | `Codeforces` | `Hard` | Containment | - | - | Strictly-Convex; Inside-Test; Polygon | Strong convex-polygon containment practice with hull-style reasoning. |
| [U2](https://codeforces.com/problemset/problem/1143/F) | `Codeforces` | `Hard` | - | - | - | Parabolas; Upper-Hull; Counting | A more advanced geometry task often grouped with convex-hull thinking. |

### Challenge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Maximum Manhattan Distances](https://cses.fi/problemset/task/3410) | `CSES` | `Hard` | - | Extreme-Point Reasoning | Coordinate Transforms; Extreme Value Tracking | Manhattan Distance; Transformations | Manhattan extremes are often solved by hull-like geometric transforms. |
| [Minimum Euclidean Distance](https://cses.fi/problemset/task/2194) | `CSES` | `Hard` | - | Divide-And-Conquer; Sweep-Line | Sorting Points; Balanced Search By Y | Closest Pair; Sweep Line; Plane Geometry | A standard advanced geometry problem closely tied to hull-style point geometry. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `CONVEXHULL` | Convex Hull | `primary` | `medium` | andrew monotone chain; strict turn pop; boundary collinear points | [Note](../../../practice/ladders/geometry/convex-hull/convexhull.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/convex-hull/convexhull.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
