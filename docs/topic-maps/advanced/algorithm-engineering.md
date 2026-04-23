# Advanced -> Algorithm Engineering

Performance work beyond asymptotics: benchmarks, cache behavior, memory layout, and reproducible measurements.

- Topic slug: `advanced/algorithm-engineering`
- Tutorial page: [Open tutorial](../../../topics/advanced/algorithm-engineering/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/advanced/algorithm-engineering/README.md)
- Repo problems currently tagged here: `0`
- Curated external problems: `8`

## Microtopics

- benchmarking
- profiling
- cache-locality
- SIMD
- memory-hierarchy
- external-memory
- parallelism
- reproducibility

## Learning Sources

| Source | Type |
| --- | --- |
| [MIT 6.506 Algorithm Engineering](https://people.csail.mit.edu/jshun/6506-s23/) | `course` |
| [MIT OCW 6.5060](https://ocw.mit.edu/courses/6-5060-algorithm-engineering-spring-2023/) | `course` |
| [TU/e Algorithms Engineering](https://research.tue.nl/en/courses/algorithms-engineering/) | `course` |

## Practice Sources

| Source | Type |
| --- | --- |
| [PBBS benchmark suite](https://www.cs.cmu.edu/~pbbs/) | `benchmark suite` |
| [Sort Benchmark](https://sortbenchmark.org/) | `benchmark suite` |
| [AtCoder Introduction to Heuristics](https://atcoder.jp/contests/intro-heuristics/tasks/intro_heuristics_a) | `practice` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Robot Path](https://cses.fi/problemset/task/1742) | `CSES` | `Medium` | - | Implementation | Hash Set; Coordinate Simulation | Hashing; Simulation; Sets | A small but instructive exercise in robust simulation and state tracking. |
| [Dynamic Values And Maximum Sum](https://codeforces.com/problemset/problem/2209/F) | `Codeforces` | `Very Hard` | - | - | - | Tree Process; State Transitions | Performance-sensitive tree optimization with many moving parts, ideal for engineering-heavy practice. |
| [Juan's Colorful Tree](https://codeforces.com/problemset/problem/2155/F) | `Codeforces` | `Very Hard` | - | - | - | Tree Queries; Set Intersections; Hybrid Techniques | Shows how serious contest solutions often combine several techniques to meet practical limits. |
| [Minimum Difference](https://codeforces.com/problemset/problem/1476/G) | `Codeforces` | `Very Hard` | - | - | - | Data Structures; Query Optimization; Implementation Detail | A good benchmark for fast query processing where constants and representation choices matter. |
| [Query Jungle](https://codeforces.com/problemset/problem/2152/G) | `Codeforces` | `Very Hard` | - | - | - | Tree Queries; Toggle Updates; Global State Maintenance | Strong example of designing around query/update bottlenecks rather than just the high-level idea. |

### Challenge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Area of Rectangles](https://cses.fi/problemset/task/1741) | `CSES` | `Hard` | - | Engineering; Event Processing | Compression; Segment Tree Or Fenwick | Coordinate Compression; Sweep Line; Interval Coverage | Great for practicing fast, memory-conscious sweep-line implementation. |
| [Lines and Queries I](https://cses.fi/problemset/task/3429) | `CSES` | `Hard` | - | Online; Optimized Query Processing | Line Evaluation; Convex Hull Trick | Convex Hull Trick; Data Structures | Rewards clean data-structure engineering and careful constant-factor control. |
| [Minimum Euclidean Distance](https://cses.fi/problemset/task/2194) | `CSES` | `Hard` | - | Performance Tuning; Geometric Data Structures | Sorting; Balanced Search | Implementation; Sweep Line; Closest Pair | A classic example where asymptotics are simple but implementation details matter. |

## Repo Problems

_No repo note has been tagged to this topic yet._

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
