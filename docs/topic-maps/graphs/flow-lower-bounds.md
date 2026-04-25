# Graphs -> Flow With Lower Bounds

Feasible circulation and lower/upper edge bounds reduced to one saturating max-flow check with super source and super sink.

- Topic slug: `graphs/flow-lower-bounds`
- Tutorial page: [Open tutorial](../../../topics/graphs/flow-lower-bounds/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/graphs/flow/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `2`

## Microtopics

- feasible-circulation
- lower-bounds
- balance-array
- super-source-sink
- t-to-s-reduction
- flow-reconstruction

## Learning Sources

| Source | Type |
| --- | --- |
| [CP-Algorithms flows with demands](https://cp-algorithms.com/graph/flow_with_demands.html) | `Reference` |
| [USACO Guide flow with lower bounds](https://usaco.guide/adv/flow-lb) | `Reference` |
| [Illinois CS473 flow extensions](https://courses.grainger.illinois.edu/cs473/sp2014/lec/19_lec.pdf) | `Course` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Codeforces acmsguru Reactor Cooling](https://codeforces.com/problemsets/acmsguru/problem/99999/194) | `Practice` |
| [Library Checker min_cost_b_flow](https://judge.yosupo.jp/problem/min_cost_b_flow) | `Practice` |
| [Codeforces problemset](https://codeforces.com/problemset) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Flow With Lower Bounds hot sheet](../../../notebook/flow-lower-bounds-hot-sheet.md) | `quick reference` |
| [Reactor Cooling note](../../../practice/ladders/graphs/flow/reactorcooling.md) | `anchor note` |
| [Flow starter route](../../../template-library.md) | `starter route` |
| [Maximum Flow tutorial](../../../topics/graphs/flow/README.md) | `adjacent tutorial` |
| [Min-Cost Flow tutorial](../../../topics/graphs/min-cost-flow/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Reactor Cooling](https://codeforces.com/problemsets/acmsguru/problem/99999/194) | `Codeforces acmsguru` | `Hard` | Lower Bounds | Reduction; Witness Output | Maximum Flow; Residual Graph; Super Source / Super Sink | Feasible Circulation; Balance Array; Witness Output | The canonical first lower-bounds circulation problem: every edge has mandatory minimum and maximum flow, and you must print one witness in input order. |

### Advanced

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Minimum Cost b-Flow](https://judge.yosupo.jp/problem/min_cost_b_flow) | `Library Checker` | `Hard` | Lower Bounds, Cost | Verification; Cross-Topic | Flow With Lower Bounds; Min-Cost Flow; Supply / Demand Modeling | Node Supply/Demand; Costed Flow | A strong official compare point showing how lower bounds and node balances grow into the costed b-flow family. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `REACTORCOOLING` | Reactor Cooling | `secondary` | `hard` | feasible circulation; lower bounds; flow reconstruction | [Note](../../../practice/ladders/graphs/flow/reactorcooling.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/flow/reactorcooling.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
