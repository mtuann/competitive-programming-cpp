# Data Structures -> Persistent Data Structures

Path-copying data structures where updates create new version roots and old snapshots remain queryable.

- Topic slug: `data-structures/persistent-data-structures`
- Tutorial page: [Open tutorial](../../../topics/data-structures/persistent-data-structures/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/data-structures/persistent-data-structures/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `3`

## Microtopics

- path-copying
- version-roots
- persistent-segment-tree
- copy-on-write
- snapshot-query
- branching-versions

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms segment tree persistent section](https://cp-algorithms.com/data_structures/segment_tree.html) | `Reference` |
| [USACO Guide persistent data structures](https://usaco.guide/adv/persistent?lang=java) | `Reference` |
| [CSES Range Queries and Copies](https://cses.fi/problemset/task/1737) | `Practice` |

## Practice Sources

| Source | Type |
| --- | --- |
| [SPOJ MKTHNUM](https://www.spoj.com/problems/MKTHNUM/) | `Practice` |
| [Library Checker Persistent Union Find](https://judge.yosupo.jp/problem/persistent_unionfind) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Persistent Data Structures hot sheet](../../../notebook/persistent-data-structures-hot-sheet.md) | `quick reference` |
| [Range Queries and Copies note](../../../practice/ladders/data-structures/persistent-data-structures/rangequeriesandcopies.md) | `anchor note` |
| [Persistent starter route](../../../template-library.md) | `starter route` |
| [Segment Tree tutorial](../../../topics/data-structures/segment-tree/README.md) | `adjacent tutorial` |
| [DSU Rollback tutorial](../../../topics/data-structures/dsu-rollback/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Range Queries and Copies](https://cses.fi/problemset/task/1737) | `CSES` | `Hard` | Persistent Segment Tree | Data-Structure-Heavy; Versioned Queries | Segment Tree; Point Update; Path Copying | Path-Copying; Version-Roots; Range-Sum | The cleanest first exact benchmark where each point update creates a new segment-tree root and old versions stay queryable. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [K-th Number](https://www.spoj.com/problems/MKTHNUM/) | `SPOJ` | `Hard` | Order Statistics, Persistent Segment Tree | Data-Structure-Heavy; Value Compression | Coordinate Compression; Prefix Version Difference | Prefix-Versions | The classic stretch problem once path copying is trusted and the persistent tree stores frequencies instead of plain sums. |

### Challenge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Persistent Union Find](https://judge.yosupo.jp/problem/persistent_unionfind) | `Library Checker` | `Hard` | Persistent Union Find | Verification; Versioned Queries | Persistence Worldview; Version Handles; DSU Basics | Persistence; Versioned Connectivity | A family-broadening verifier showing that the persistent worldview is larger than segment-tree snapshots alone. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `RANGEQUERIESANDCOPIES` | Range Queries and Copies | `primary` | `hard` | persistent segment tree; path copying; versioned range sum | [Note](../../../practice/ladders/data-structures/persistent-data-structures/rangequeriesandcopies.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/persistent-data-structures/rangequeriesandcopies.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
