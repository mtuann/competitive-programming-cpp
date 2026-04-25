# Geometry -> Half-Plane Intersection

Intersect directed half-planes by angle sorting and deque cleanup to recover one bounded convex feasible region or polygon kernel.

- Topic slug: `geometry/half-plane-intersection`
- Tutorial page: [Open tutorial](../../../topics/geometry/half-plane-intersection/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/geometry/half-plane-intersection/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `4`
- Curated external problems: `1`

## Microtopics

- directed-half-plane
- angle-sort
- parallel-tie-break
- deque-intersection
- polygon-kernel
- bounded-region

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms half-plane intersection](https://cp-algorithms.com/geometry/halfplane-intersection.html) | `Reference` |
| [Masaryk University half-plane intersection](https://is.muni.cz/do/sci/UMS/el/geometricke-alg/pages/05-intersection.html?lang=en) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Kattis Big Brother](https://open.kattis.com/problems/bigbrother) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Half-Plane Intersection hot sheet](../../../notebook/half-plane-intersection-hot-sheet.md) | `quick reference` |
| [Big Brother](../../../practice/ladders/geometry/half-plane-intersection/bigbrother.md) | `flagship note` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |
| [Convex Hull](../../../topics/geometry/convex-hull/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Big Brother](https://open.kattis.com/problems/bigbrother) | `Kattis` | `Medium` | Polygon-Kernel | Geometry; Implementation | Orientation; Polygon Area; Directed Line Sidedness | Directed Lines; Continuous Geometry; Deque | The cleanest polygon-kernel benchmark where every polygon edge turns into one inward half-plane and the intended route is exactly angle-sorted half-plane intersection. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `BIGBROTHER` | Big Brother | `primary` | `medium` | - | [Note](../../../practice/ladders/geometry/half-plane-intersection/bigbrother.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/half-plane-intersection/bigbrother.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
