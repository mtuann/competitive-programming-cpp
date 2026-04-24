# Geometry -> Sweep Line

Sort events and maintain an active structure while a conceptual line moves across the plane.

- Topic slug: `geometry/sweep-line`
- Tutorial page: [Open tutorial](../../../topics/geometry/sweep-line/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/geometry/sweep-line/README.md)
- Repo problems currently tagged here: `3`
- Repo companion pages: `0`
- Curated external problems: `6`

## Microtopics

- event-sorting
- active-set
- closest-pair
- interval-union
- segment-intersections
- range-counting

## Learning Sources

| Source | Type |
| --- | --- |
| [Topcoder line sweep algorithms](https://www.topcoder.com/thrive/articles/Line%20Sweep%20Algorithms) | `Essay / Blog` |
| [USACO Guide sweep line](https://usaco.guide/plat/sweep-line?lang=cpp) | `Reference` |
| [Competitive Programmer's Handbook](https://usaco.guide/CPH.pdf) | `Reference` |

## Practice And Follow-Up Sources

| Source | Type |
| --- | --- |
| [CSES Intersection Points](https://cses.fi/problemset/task/1740) | `Practice` |
| [CSES Minimum Euclidean Distance](https://cses.fi/problemset/task/2194/) | `Practice` |
| [CSES Area of Rectangles](https://cses.fi/problemset/task/1741) | `Practice` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Line Segments Trace I](https://cses.fi/problemset/task/3427) | `CSES` | `Medium` | Envelope | - | - | Scan; Max-Query; Segments | Scan-line style reasoning over many segments. |
| [Line Segments Trace II](https://cses.fi/problemset/task/3428) | `CSES` | `Hard` | Envelope | - | - | Scan; Events; Segments | A more intricate sweep-line companion problem. |

### Challenge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Area of Rectangles](https://cses.fi/problemset/task/1741) | `CSES` | `Hard` | Area-Union | Coordinate Compression | Event Sweep; Interval Coverage | Rectangle Union; Events; Coordinate-Compression; Rectangles | The classic rectangle-union sweep benchmark. |
| [Intersection Points](https://cses.fi/problemset/task/1740) | `CSES` | `Hard` | Intersection-Counting | Event Sorting | Ordered Events; Fenwick Tree / Balanced Bst | Orthogonal Segments; Intersections; Events; Active-Set | A textbook sweep-line intersection counter. |
| [Lines and Queries I](https://cses.fi/problemset/task/3429) | `CSES` | `Hard` | - | Online; Data-Structure-Heavy | Convex Hull Trick Basics; Line Evaluation | Line Containers; Optimization | Not a pure sweep line, but a great event-driven geometry/data-structure hybrid. |
| [Minimum Euclidean Distance](https://cses.fi/problemset/task/2194) | `CSES` | `Hard` | - | Divide-And-Conquer; Sweep-Line | Sorting; Plane Sweep Intuition | Closest Pair | The closest-pair sweep is a classic geometry engineering benchmark. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `KINGDOMS` | KINGDOMS | `primary` | `hard` | laminar regions; sweep events; containment tree | [Note](../../../practice/ladders/geometry/sweep-line/kingdoms.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/sweep-line/kingdoms.cpp) |
| `MINIMUMEUCLIDEANDISTANCE` | Minimum Euclidean Distance | `secondary` | `hard` | closest pair sweep line; active strip by x distance; ordered set by y | [Note](../../../practice/ladders/advanced/algorithm-engineering/minimumeuclideandistance.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/algorithm-engineering/minimumeuclideandistance.cpp) |
| `VOTELPH` | Bà Nà | `primary` | `hard` | piecewise maximum; endpoint preprocessing; parabola envelopes | [Note](../../../practice/ladders/geometry/sweep-line/votelph.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/sweep-line/votelph.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
