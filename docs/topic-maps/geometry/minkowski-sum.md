# Geometry -> Minkowski Sum

Sum two convex polygons in CCW order by normalizing the lowest vertex and merging edge directions, then reuse the result for repeated sums or point-in-convex queries.

- Topic slug: `geometry/minkowski-sum`
- Tutorial page: [Open tutorial](../../../topics/geometry/minkowski-sum/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/geometry/minkowski-sum/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `1`

## Microtopics

- minkowski-sum
- convex-polygons
- edge-merge
- lowest-vertex-normalization
- repeated-sum
- point-in-convex

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms Minkowski sum](https://cp-algorithms.com/geometry/minkowski.html) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Codeforces Mogohu-Rea Idol](https://codeforces.com/problemset/problem/87/E) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Minkowski Sum hot sheet](../../../notebook/minkowski-sum-hot-sheet.md) | `quick reference` |
| [Mogohu-Rea Idol (stretch anchor)](../../../practice/ladders/geometry/minkowski-sum/mogohureaidol.md) | `stretch note` |
| [Convex Hull](../../../topics/geometry/convex-hull/README.md) | `compare point` |
| [Geometry cheatsheet](../../../notebook/geometry-cheatsheet.md) | `chooser` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |

## Curated External Problems

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Mogohu-Rea Idol](https://codeforces.com/problemset/problem/87/E) | `Codeforces` | `Very Hard` | Point-In-Convex | Geometry; Modeling; Implementation | Convex Polygon Order; Cross Product; Point In Convex Polygon | Convex Polygon; Repeated Sum; Point Query; Center Of Mass | A stretch repeated-sum model where the basic two-polygon merge is already assumed and the real lesson is reusing it for three convex polygons plus scaled point-in-convex queries. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `MOGOHUREAIDOL` | Mogohu-Rea Idol | `primary` | `very-hard` | - | [Note](../../../practice/ladders/geometry/minkowski-sum/mogohureaidol.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/minkowski-sum/mogohureaidol.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
