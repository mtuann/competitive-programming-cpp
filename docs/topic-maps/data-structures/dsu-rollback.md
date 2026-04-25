# Data Structures -> DSU Rollback / Offline Dynamic Connectivity

Rollback-friendly union-find plus segment tree over time for offline add/remove connectivity timelines.

- Topic slug: `data-structures/dsu-rollback`
- Tutorial page: [Open tutorial](../../../topics/data-structures/dsu-rollback/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/data-structures/dsu-rollback/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `2`

## Microtopics

- rollback-dsu
- snapshot
- rollback
- segment-tree-over-time
- edge-active-interval
- offline-dynamic-connectivity

## Learning Sources

| Source | Type |
| --- | --- |
| [CP-Algorithms deleting from a data structure in O(T(n) log n)](https://cp-algorithms.com/data_structures/deleting_in_log_n.html) | `Reference` |
| [USACO Guide offline deletion](https://usaco.guide/adv/offline-del) | `Reference` |
| [CSES Dynamic Connectivity](https://cses.fi/problemset/task/2133/) | `Practice` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Problem Set](https://cses.fi/problemset/) | `Practice` |
| [Library Checker](https://judge.yosupo.jp/) | `Practice` |
| [Codeforces problemset](https://codeforces.com/problemset) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [DSU Rollback hot sheet](../../../notebook/dsu-rollback-hot-sheet.md) | `quick reference` |
| [Dynamic Connectivity note](../../../practice/ladders/data-structures/dsu-rollback/dynamicconnectivity.md) | `anchor note` |
| [DSU rollback starter route](../../../template-library.md) | `starter route` |
| [DSU tutorial](../../../topics/data-structures/dsu/README.md) | `adjacent tutorial` |
| [Offline Tricks tutorial](../../../topics/data-structures/offline-tricks/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Dynamic Connectivity](https://cses.fi/problemset/task/2133) | `CSES` | `Hard` | Advanced Techniques, Dynamic Connectivity | Offline; Data-Structure-Heavy; Timeline Modeling | DSU; Offline Reasoning; Half-Open Intervals | Rollback-DSU; Segment-Tree-Over-Time; Component-Count | The cleanest first exact benchmark for edge-lifetime intervals, rollback DSU, and component answers at every time state. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Dynamic Graph Vertex Add Component Sum](https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum) | `Library Checker` | `Hard` | Dynamic Connectivity | Offline; Verification; Data-Structure-Heavy | Rollback DSU; Component Metadata; Offline Dynamic Connectivity | Rollback-DSU; Segment-Tree-Over-Time; Component Metadata | A strong next-step verifier once rollback connectivity itself is trusted and component-value aggregation becomes the new difficulty. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `DYNAMICCONNECTIVITY` | Dynamic Connectivity | `primary` | `hard` | dsu rollback; segment tree over time; offline dynamic connectivity | [Note](../../../practice/ladders/data-structures/dsu-rollback/dynamicconnectivity.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/dsu-rollback/dynamicconnectivity.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
