# Geometry -> Nearest Pair of Points

Find the global closest Euclidean pair in one static planar point set through an x-sorted sweep and a y-ordered active strip.

- Topic slug: `geometry/nearest-pair`
- Tutorial page: [Open tutorial](../../../topics/geometry/nearest-pair/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/geometry/nearest-pair/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `4`
- Curated external problems: `2`

## Microtopics

- closest-pair
- active-strip
- x-sweep
- y-ordered-set
- packing-bound
- squared-distance

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms closest pair](https://cp-algorithms.com/geometry/nearest_points.html) | `Reference` |
| [AOJ Closest Pair](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A) | `Practice` |
| [CSES Minimum Euclidean Distance](https://cses.fi/problemset/task/2194/) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Nearest Pair hot sheet](../../../notebook/nearest-pair-hot-sheet.md) | `quick reference` |
| [Closest Pair](../../../practice/ladders/geometry/nearest-pair/closestpair.md) | `flagship note` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |
| [Minimum Euclidean Distance note](../../../practice/ladders/advanced/algorithm-engineering/minimumeuclideandistance.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Closest Pair](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A) | `AOJ` | `Medium` | Sweep-Line | Geometry; Implementation | Sorting Points; Ordered Set By Y; Squared Distance Bookkeeping | Closest Pair; Active Strip; Euclidean Distance; Ordered Set | The cleanest official nearest-pair benchmark where the intended route is exactly the standard x-sorted sweep with a y-ordered active strip. |

### Challenge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Minimum Euclidean Distance](https://cses.fi/problemset/task/2194) | `CSES` | `Hard` | - | Implementation; Sweep-Line | Sorting Points; Active Strip; Integer Distance Arithmetic | Closest Pair; Sweep Line; Squared Distance; Plane Geometry | A harder verifier-style sibling where the same nearest-pair sweep must be implemented carefully enough for contest-sized integer input. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `CLOSESTPAIR` | Closest Pair | `primary` | `medium` | - | [Note](../../../practice/ladders/geometry/nearest-pair/closestpair.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/nearest-pair/closestpair.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
