# Geometry -> Polygon Area And Point Location

Shoelace formula, point-in-polygon logic, and careful boundary handling in planar geometry.

- Topic slug: `geometry/polygon-area-point-location`
- Tutorial page: [Open tutorial](../../../topics/geometry/polygon-area-point-location/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/geometry/polygon-area-point-location/README.md)
- Repo problems currently tagged here: `5`
- Repo companion pages: `2`
- Curated external problems: `4`

## Microtopics

- shoelace
- ray-casting
- winding-number
- boundary-handling
- planar-point-location
- simple-polygon

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms area of simple polygon](https://cp-algorithms.com/geometry/area-of-simple-polygon.html) | `trusted guide` |
| [Princeton geometric primitives](https://www.cs.princeton.edu/courses/archive/fall10/cos226/lectures/99GeometricPrimitives-2x2.pdf) | `course` |
| [cp-algorithms point location](https://cp-algorithms.com/geometry/point-location.html) | `trusted guide` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Polygon Area](https://cses.fi/problemset/task/2191/) | `problem` |
| [CSES Point in Polygon](https://cses.fi/problemset/task/2192) | `problem` |
| [CSES Point Location Test](https://cses.fi/problemset/task/2189/) | `problem` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Geometry cheatsheet](../../../notebook/geometry-cheatsheet.md) | `quick reference` |
| [Templates overview](../../../template-library.md) | `template guide` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Point Location Test](https://cses.fi/problemset/task/2189) | `CSES` | `Easy` | Point-Location, Orientation | Implementation | Cross Product Sign | Cross-Product; Relative-Position | A very lightweight point-location primitive useful in polygon code. |
| [Polygon Area](https://cses.fi/problemset/task/2191) | `CSES` | `Easy` | Polygon-Area, Shoelace | Formula Derivation | Cross Product | Shoelace Formula; Signed-Area; Cross-Product; Simple-Polygon | A standard polygon-area starter problem. |
| [Point in Polygon](https://cses.fi/problemset/task/2192) | `CSES` | `Medium` | Point-Location | Parity Counting | Orientation Test; Segment Intersection | Ray Casting; Orientation; Inside-Outside | Directly trains point-in-polygon logic and boundary handling. |
| [Polygon Lattice Points](https://cses.fi/problemset/task/2193) | `CSES` | `Medium` | Polygon-Area, Lattice-Points | Counting | Shoelace Formula; GCD On Edges | Pick's Theorem; Pick-Theorem; Boundary; Interior | A classic Pick's theorem application. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `KINGDOMS` | KINGDOMS | `secondary` | `hard` | laminar regions; sweep events; containment tree | [Note](../../../practice/ladders/geometry/sweep-line/kingdoms.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/sweep-line/kingdoms.cpp) |
| `POINTINPOLYGON` | Point in Polygon | `primary` | `medium` | ray casting parity; boundary classification; on segment test | [Note](../../../practice/ladders/geometry/polygon-area-point-location/pointinpolygon.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/polygon-area-point-location/pointinpolygon.cpp) |
| `POLYGONAREA` | Polygon Area | `primary` | `easy` | shoelace formula; signed area accumulation; integer polygon area | [Note](../../../practice/ladders/geometry/polygon-area-point-location/polygonarea.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/polygon-area-point-location/polygonarea.cpp) |
| `TFIELD` | Ruộng bậc thang | `secondary` | `hard` | nested polygons; weighted sliding window; shoelace preprocessing | [Note](../../../practice/ladders/dp/sliding-window/tfield.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/sliding-window/tfield.cpp) |
| `VOTELPH` | Bà Nà | `secondary` | `hard` | piecewise maximum; endpoint preprocessing; parabola envelopes | [Note](../../../practice/ladders/geometry/sweep-line/votelph.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/sweep-line/votelph.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
