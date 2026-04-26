# Graphs -> Edmonds Blossom / General Matching

Maximum-cardinality matching in a general undirected graph via Edmonds blossom shrinking, with odd-cycle contraction preserving augmenting-path search.

- Topic slug: `graphs/general-matching`
- Tutorial page: [Open tutorial](../../../topics/graphs/general-matching/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/graphs/general-matching/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `3`

## Microtopics

- general-graph-matching
- augmenting-paths
- alternating-forest
- blossom-shrinking
- base-array
- odd-cycle-contraction

## Learning Sources

| Source | Type |
| --- | --- |
| [OI Wiki general graph maximum matching](https://en.oi-wiki.org/graph/graph-matching/general-match/) | `Reference` |
| [KACTL PDF](https://pages.cs.wisc.edu/~dieter/ICPC/21-22/kactl.pdf) | `Reference` |
| [Edmonds blossom lecture notes](https://web.eecs.utk.edu/~jplank/plank/classes/cs494/494/notes/Edmonds/) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Library Checker Matching on General Graph](https://judge.yosupo.jp/problem/general_matching) | `Practice` |
| [Luogu P6113](https://www.luogu.com.cn/problem/P6113) | `Practice` |
| [VN SPOJ QBFLOWER](https://vn.spoj.com/problems/QBFLOWER/) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [General Matching hot sheet](../../../notebook/general-matching-hot-sheet.md) | `quick reference` |
| [General Matching starter route](../../../template-library.md) | `starter route` |
| [General Matching note](../../../practice/ladders/graphs/general-matching/generalmatching.md) | `anchor note` |
| [Matching tutorial](../../../topics/graphs/matching/README.md) | `compare point` |
| [QBFLOWER note](../../../practice/ladders/graphs/matching/qbflower.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Matching on General Graph](https://judge.yosupo.jp/problem/general_matching) | `Library Checker` | `Hard` | Blossom | Template Problem; Non-Bipartite Matching | Augmenting Paths; Alternating Forest; Matching Basics | Edmonds Blossom; Odd Cycle; Maximum Matching | The cleanest direct benchmark where the graph is explicitly general and the whole task is just blossom-based maximum matching. |

### Practice

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [P6113 [Template] General Graph Maximum Matching](https://www.luogu.com.cn/problem/P6113) | `Luogu` | `Hard` | Blossom | Template Drill; Non-Bipartite Matching | Augmenting Paths; Odd Cycle Contraction | Template; Maximum Matching | A straightforward second template benchmark once the Library Checker route feels stable. |

### Bridge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [QBFLOWER - Tặng hoa](https://vn.spoj.com/problems/QBFLOWER/) | `VN SPOJ` | `Medium` | Edge Cover | Modeling; Transformation | Maximum Matching; Edge Cover Formula | Minimum Edge Cover; Graph Transformation | A strong bridge problem where blossom is still the engine, but only after reducing the story to minimum edge cover on a general graph. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `GENERALMATCHING` | Matching on General Graph | `primary` | `hard` | - | [Note](../../../practice/ladders/graphs/general-matching/generalmatching.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/general-matching/generalmatching.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
