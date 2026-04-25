# Advanced -> Algorithm Engineering

Performance work beyond asymptotics: benchmarks, cache behavior, memory layout, and reproducible measurements.

- Topic slug: `advanced/algorithm-engineering`
- Tutorial page: [Open tutorial](../../../topics/advanced/algorithm-engineering/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/advanced/algorithm-engineering/README.md)
- Repo problems currently tagged here: `3`
- Repo companion pages: `5`
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
| [MIT 6.506 Algorithm Engineering](https://people.csail.mit.edu/jshun/6506-s23/) | `Course` |
| [MIT OCW 6.5060](https://ocw.mit.edu/courses/6-5060-algorithm-engineering-spring-2023/) | `Course` |
| [TU/e Algorithms Engineering](https://research.tue.nl/en/courses/algorithms-engineering/) | `Course` |

## Practice Sources

| Source | Type |
| --- | --- |
| [PBBS benchmark suite](https://www.cs.cmu.edu/~pbbs/) | `Practice` |
| [Sort Benchmark](https://sortbenchmark.org/) | `Practice` |
| [AtCoder Introduction to Heuristics](https://atcoder.jp/contests/intro-heuristics/tasks/intro_heuristics_a) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Contest checklist](../../../notebook/contest-checklist.md) | `checklist` |
| [Stress testing workflow](../../../notebook/stress-testing-workflow.md) | `verification guide` |
| [Contest playbooks](../../../practice/contest-playbooks/README.md) | `process guide` |
| [Minimum Euclidean Distance note](../../../practice/ladders/advanced/algorithm-engineering/minimumeuclideandistance.md) | `anchor note` |
| [Templates overview](../../../template-library.md) | `template guide` |

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

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `FFLOW` | Fast Maximum Flow | `secondary` | `medium` | maximum flow; undirected capacities; capacity scaling | [Note](../../../practice/ladders/graphs/flow/fflow.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/flow/fflow.cpp) |
| `MINIMUMEUCLIDEANDISTANCE` | Minimum Euclidean Distance | `primary` | `hard` | closest pair sweep line; active strip by x distance; ordered set by y | [Note](../../../practice/ladders/advanced/algorithm-engineering/minimumeuclideandistance.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/algorithm-engineering/minimumeuclideandistance.cpp) |
| `PRAVO` | Tam giác vuông | `secondary` | `medium` | count right triangles; normalized directions; perpendicular pairing | [Note](../../../practice/ladders/geometry/right-triangles/pravo.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/right-triangles/pravo.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
