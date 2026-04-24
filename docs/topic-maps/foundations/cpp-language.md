# Foundations -> C++ Language

Core C++ contest toolkit: fast I/O, references and value semantics, STL primitives, and the subset of the language that matters most under time pressure.

- Topic slug: `foundations/cpp-language`
- Tutorial page: [Open tutorial](../../../topics/foundations/cpp-language/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/foundations/cpp-language/README.md)
- Repo problems currently tagged here: `2`
- Repo companion pages: `3`
- Curated external problems: `6`

## Microtopics

- fast-io
- value-vs-reference
- const-correctness
- vector-and-pair
- sort-and-lower_bound
- maps-and-sets
- priority_queue
- overflow-discipline

## Learning Sources

| Source | Type |
| --- | --- |
| [cppreference language](https://en.cppreference.com/w/cpp/language) | `official docs` |
| [cppreference containers](https://en.cppreference.com/w/cpp/container) | `official docs` |
| [cppreference algorithms](https://en.cppreference.com/w/cpp/algorithm) | `official docs` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Problem Set](https://cses.fi/problemset) | `problem set` |
| [Codeforces sortings tag](https://codeforces.com/problemset?tags=sortings) | `problem set` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Foundations cheatsheet](../../../notebook/foundations-cheatsheet.md) | `quick reference` |
| [Templates overview](../../../template-library.md) | `template guide` |
| [STL basics ladder](../../../practice/ladders/foundations/stl/README.md) | `adjacent ladder` |

## Curated External Problems

### Warm-Up

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Missing Number](https://cses.fi/problemset/task/1083) | `CSES` | `Easy` | - | Implementation-Heavy | Basic Arithmetic; Arrays; Input/Output | Arrays; Math; Accumulation; Scan | Good practice for reading values, tracking a simple invariant, and avoiding off-by-one mistakes. |
| [Repetitions](https://cses.fi/problemset/task/1069) | `CSES` | `Easy` | - | Implementation-Heavy | Strings; Loops; Basic Comparisons | Scanning; Runs; Run-Length; Scan | Reinforces careful string scanning and run-length style logic without extra data structures. |
| [Weird Algorithm](https://cses.fi/problemset/task/1068) | `CSES` | `Easy` | - | Implementation-Heavy | Basic Loops; Branching; Input/Output | Simulation; Loops; I/O; Branching | A clean first task for writing a loop, handling parity, and printing a sequence correctly. |

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Coin Piles](https://cses.fi/problemset/task/1754) | `CSES` | `Easy` | - | - | - | Parity; Cases; Math | Great first problem for branch logic and case analysis. |
| [Permutations](https://cses.fi/problemset/task/1070) | `CSES` | `Easy` | - | Implementation-Heavy | Loops; Arrays; Simple Constructive Ideas | Construction; Parity; Output-Formatting | A nice starter for constructing outputs with a simple parity-based pattern. |

### Theory / Course

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Increasing Array](https://cses.fi/problemset/task/1094) | `CSES` | `Easy` | - | Proof-Heavy; Implementation-Heavy | Arrays; Greedy Reasoning; Prefix Invariants | Arrays; Invariants | A compact proof-by-invariant problem where the implementation is simple but the invariant matters. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `DISTINCTNUMBERS` | Distinct Numbers | `secondary` | `easy` | sort unique; container deduplication; stl algorithms | [Note](../../../practice/ladders/foundations/stl/distinctnumbers.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/stl/distinctnumbers.cpp) |
| `MISSINGNUMBER` | Missing Number | `primary` | `easy` | running total subtraction; arithmetic series sum; type safe warm-up | [Note](../../../practice/ladders/foundations/cpp-language/missingnumber.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/cpp-language/missingnumber.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
