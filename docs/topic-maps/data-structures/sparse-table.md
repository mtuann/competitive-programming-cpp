# Data Structures -> Sparse Table

Static range query structure for idempotent operations such as RMQ and LCA reductions.

- Topic slug: `data-structures/sparse-table`
- Tutorial page: [Open tutorial](../../../topics/data-structures/sparse-table/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/data-structures/sparse-table/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `0`
- Curated external problems: `3`

## Microtopics

- rmq
- idempotent
- immutable-array
- log-table
- overlapping-blocks
- lca-reduction

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms sparse table](https://cp-algorithms.com/data_structures/sparse-table.html) | `Reference` |
| [OI Wiki sparse table](https://en.oi-wiki.org/ds/sparse-table/) | `Reference` |
| [USACO Guide Euler Tour / Static RMQ](https://usaco.guide/gold/tree-euler/) | `Reference` |

## Practice And Follow-Up Sources

| Source | Type |
| --- | --- |
| [CSES Static Range Minimum Queries](https://cses.fi/problemset/task/1647/) | `Practice` |
| [SPOJ RMQSQ](https://www.spoj.com/problems/RMQSQ/) | `Practice` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Static Range Minimum Queries](https://cses.fi/problemset/task/1647) | `CSES` | `Easy` | - | Query-Heavy; Data-Structure-Heavy | Idempotent Operations; Range Queries; Preprocessing | Range-Min; Static-Queries; Idempotent | The textbook static RMQ problem that sparse tables are built for. |
| [Range GCD Query](https://judge.yosupo.jp/problem/range_gcd_query) | `Library Checker` | `Medium` | - | - | - | GCD; Idempotent | Same sparse-table idea with gcd aggregation. |

### Classics

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Static RMQ](https://judge.yosupo.jp/problem/staticrmq) | `Library Checker` | `Easy` | - | Query-Heavy | Sparse Table; Idempotent Queries; Preprocessing | Range-Min; Idempotent | A concise official benchmark for validating a sparse table implementation. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `STATICRANGEMINIMUMQUERIES` | Static Range Minimum Queries | `primary` | `easy` | sparse table rmq; idempotent overlap query; log table preprocessing | [Note](../../../practice/ladders/data-structures/sparse-table/staticrangeminimumqueries.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/sparse-table/staticrangeminimumqueries.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
