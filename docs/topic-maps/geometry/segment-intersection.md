# Geometry -> Segment Intersection

Robust orientation tests, on-segment handling, and degenerate cases for line and segment intersection.

- Topic slug: `geometry/segment-intersection`
- Tutorial page: [Open tutorial](../../../topics/geometry/segment-intersection/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/geometry/segment-intersection/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `0`
- Curated external problems: `5`

## Microtopics

- orientation-test
- on-segment
- collinear-overlap
- degeneracies
- integer-robustness
- line-vs-segment

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms segment intersection](https://cp-algorithms.com/geometry/check-segments-intersection.html) | `trusted guide` |
| [Topcoder geometry concepts part 2](https://www.topcoder.com/community/competitive-programming/tutorials/geometry-concepts-line-intersection-and-its-applications/) | `trusted tutorial` |
| [Princeton geometric primitives](https://www.cs.princeton.edu/courses/archive/fall10/cos226/lectures/99GeometricPrimitives-2x2.pdf) | `course` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Line Segment Intersection](https://cses.fi/problemset/task/2190) | `problem` |
| [CSES Point in Polygon](https://cses.fi/problemset/task/2192) | `problem` |
| [CSES Point Location Test](https://cses.fi/problemset/task/2189/) | `problem` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Line Segment Intersection](https://cses.fi/problemset/task/2190) | `CSES` | `Medium` | Orientation | Case Analysis | Orientation Tests; Segment Bounding Boxes | Robust Geometry; Ccw; Overlap; Touching | The canonical segment-intersection decision problem. |
| [Line Segments Trace I](https://cses.fi/problemset/task/3427) | `CSES` | `Medium` | Sweep-Line | - | - | Envelope; Max-Point; Scan | A line-segment scan problem where sweep-style reasoning is natural. |
| [Line Segments Trace II](https://cses.fi/problemset/task/3428) | `CSES` | `Hard` | Sweep-Line | - | - | Envelope; Comparisons; Scan | The harder companion to Trace I with similar line-sweep flavor. |

### Challenge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Area of Rectangles](https://cses.fi/problemset/task/1741) | `CSES` | `Hard` | - | Sweep-Line; Coordinate Compression | Segment Events; Range Coverage | Sweep Line; Interval Coverage; Rectangles | The canonical rectangle-union sweep-line problem. |
| [Intersection Points](https://cses.fi/problemset/task/1740) | `CSES` | `Hard` | Sweep-Line, Intersection-Counting | Sweep-Line | Event Sorting; Balanced Tree / Fenwick | Orthogonal Segments; Horizontal-Vertical; Events; Count | Counts many segment intersections with a line-sweep approach. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `LINESEGMENTINTERSECTION` | Line Segment Intersection | `primary` | `easy` | orientation test; on segment inclusion; collinear overlap handling | [Note](../../../practice/ladders/geometry/segment-intersection/linesegmentintersection.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/segment-intersection/linesegmentintersection.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
