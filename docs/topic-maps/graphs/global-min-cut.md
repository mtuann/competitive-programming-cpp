# Graphs -> Randomized / Global Min-Cut

One undirected weighted graph, no designated source/sink, and the cheapest global cut found first through deterministic Stoer-Wagner phases.

- Topic slug: `graphs/global-min-cut`
- Tutorial page: [Open tutorial](../../../topics/graphs/global-min-cut/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/graphs/global-min-cut/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `3`

## Microtopics

- global-min-cut
- stoer-wagner
- cut-contraction
- maximum-adjacency-order
- undirected-cuts
- karger-compare

## Learning Sources

| Source | Type |
| --- | --- |
| [Princeton GlobalMincut](https://algs4.cs.princeton.edu/code/javadoc/edu/princeton/cs/algs4/GlobalMincut.html) | `Course` |
| [MIT randomized algorithms minimum cut notes](https://ocw.mit.edu/courses/6-856j-randomized-algorithms-fall-2002/resources/n16_min_cut/) | `Course` |

## Practice Sources

| Source | Type |
| --- | --- |
| [POJ 2914 - Minimum Cut](http://poj.org/problem?id=2914) | `Practice` |
| [UVa 10480 - Sabotage](https://onlinejudge.org/external/104/10480.pdf) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Global Min-Cut hot sheet](../../../notebook/global-min-cut-hot-sheet.md) | `quick reference` |
| [Global Min-Cut starter route](../../../template-library.md) | `starter route` |
| [Minimum Cut note](../../../practice/ladders/graphs/global-min-cut/globalmincut.md) | `anchor note` |
| [Maximum Flow tutorial](../../../topics/graphs/flow/README.md) | `compare point` |
| [Gomory-Hu tutorial](../../../topics/graphs/gomory-hu/README.md) | `compare point` |

## Curated External Problems

### Warm-Up

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Police Chase](https://cses.fi/problemset/task/1695) | `CSES` | `Medium` | Min Cut, Edge Cut, Flow | S-T Min Cut; Edge Extraction | Max Flow; Cut Extraction | Roads; Certificate | Another clean compare point: extract one cut certificate first, then move to the global family where no designated pair remains. |

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Minimum Cut](http://poj.org/problem?id=2914) | `POJ` | `Hard` | Undirected Cuts | Stoer-Wagner; Dense Cut Phases | Max Flow Min Cut Intuition; Undirected Weighted Graphs | Stoer-Wagner; Cut Contraction | Canonical global min-cut benchmark: no designated source/sink, parallel edges allowed, and the whole task is exactly the cut-family route. |

### Classics

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Sabotage](https://onlinejudge.org/external/104/10480.pdf) | `UVa` | `Medium` | Min Cut, Flow | S-T Min Cut; Cut Extraction | Max Flow; Minimum Cut | Graph Partition | Warm-up compare point: still one cut-extraction task, useful before the no-source/sink global min-cut lane. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `GLOBALMINCUT` | Minimum Cut | `primary` | `hard` | - | [Note](../../../practice/ladders/graphs/global-min-cut/globalmincut.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/global-min-cut/globalmincut.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
