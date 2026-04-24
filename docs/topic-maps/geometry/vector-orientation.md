# Geometry -> Vector And Orientation

Dot, cross, orientation, signed area, and exact integer geometry as the basis of most planar algorithms.

- Topic slug: `geometry/vector-orientation`
- Tutorial page: [Open tutorial](../../../topics/geometry/vector-orientation/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/geometry/vector-orientation/README.md)
- Repo problems currently tagged here: `3`
- Curated external problems: `5`

## Microtopics

- dot-product
- cross-product
- ccw
- signed-area
- collinearity
- integer-geometry

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms basic geometry](https://cp-algorithms.com/geometry/basic-geometry.html) | `trusted guide` |
| [cp-algorithms oriented area](https://cp-algorithms.com/geometry/oriented-triangle-area.html) | `trusted guide` |
| [Princeton geometric primitives](https://www.cs.princeton.edu/courses/archive/fall10/cos226/lectures/99GeometricPrimitives-2x2.pdf) | `course` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Point Location Test](https://cses.fi/problemset/task/2189/) | `problem` |
| [CSES Polygon Area](https://cses.fi/problemset/task/2191/) | `problem` |
| [CSES Line Segment Intersection](https://cses.fi/problemset/task/2190) | `problem` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Point Location Test](https://cses.fi/problemset/task/2189) | `CSES` | `Easy` | - | Implementation | Cross Product Sign | Cross Product; Half-Plane; Left-Right; Point-In-Sector | Simple orientation logic with a direct geometric interpretation. |
| [Polygon Area](https://cses.fi/problemset/task/2191) | `CSES` | `Easy` | Shoelace | Formula Derivation | Cross Product | Shoelace Formula; Area; Signed-Area; Cross-Product; Polygon | Shoelace is just accumulated oriented area. |
| [Triangle](https://codeforces.com/problemset/problem/18/A) | `Codeforces` | `Easy` | Triangle-Classification | - | - | Right-Angle; Integer-Coordinates; Bruteforce | A compact geometry check built entirely around distances and angle tests. |
| [Line Segment Intersection](https://cses.fi/problemset/task/2190) | `CSES` | `Medium` | Segment-Geometry | Case Analysis | Orientation Test; Bounding Boxes | Segment Intersection; Cross Product; Ccw; Intersection | The standard cross-product intersection test in its cleanest form. |
| [Triangle](https://codeforces.com/contest/407/problem/A) | `Codeforces` | `Medium` | Construction | - | - | Integer-Points; Right-Triangle; Existence | A direct construction problem for a right triangle on the integer grid. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `LINESEGMENTINTERSECTION` | Line Segment Intersection | `secondary` | `easy` | orientation test; on segment inclusion; collinear overlap handling | [Note](../../../practice/ladders/geometry/segment-intersection/linesegmentintersection.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/segment-intersection/linesegmentintersection.cpp) |
| `PRAVO` | Tam giác vuông | `secondary` | `medium` | count right triangles; normalized directions; perpendicular pairing | [Note](../../../practice/ladders/geometry/right-triangles/pravo.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/right-triangles/pravo.cpp) |
| `VMCOINS` | Trò chơi với những đồng xu | `secondary` | `hard` | promise-driven constructive; translation matching; small residual search | [Note](../../../practice/ladders/advanced/constructive/vmcoins.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/constructive/vmcoins.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
