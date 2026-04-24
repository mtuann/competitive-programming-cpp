# Graphs -> Matching

Augmenting-path techniques for bipartite matching and reductions to cover and assignment problems.

- Topic slug: `graphs/matching`
- Tutorial page: [Open tutorial](../../../topics/graphs/matching/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/graphs/matching/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `0`
- Curated external problems: `11`

## Microtopics

- bipartite
- augmenting-path
- kuhn
- hopcroft-karp
- konig
- assignment-reduction

## Learning Sources

| Source | Type |
| --- | --- |
| [OI Wiki max bipartite matching](https://en.oi-wiki.org/graph/graph-matching/bigraph-match/) | `trusted guide` |
| [cp-algorithms Kuhn](https://cp-algorithms.com/graph/kuhn_maximum_bipartite_matching.html) | `trusted guide` |
| [OI Wiki augmenting path](https://en.oi-wiki.org/graph/graph-matching/augment/) | `trusted guide` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Library Checker bipartite matching](https://judge.yosupo.jp/problem/bipartitematching) | `problem` |
| [CSES Problem Set](https://cses.fi/problemset/) | `problem set` |
| [USACO contest archive](https://usaco.org/index.php?page=contests) | `contest archive` |

## Curated External Problems

### Warm-Up

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Gopher II](https://onlinejudge.org/external/100/10080.pdf) | `UVa` | `Easy` | Bipartite Matching, Geometry-To-Graph | Distance-Threshold Graph; Max Matching | Bipartite Matching Basics; Distance Formula | Geometry; Reachability | The archetypal geometry-to-matching conversion. |
| [The dog task](https://onlinejudge.org/index.php?Itemid=8&option=com_onlinejudge&page=show_problem&problem=611) | `UVa` | `Easy` | Bipartite Matching | Small Bipartite Graph; Matching | Matching Basics | Animals; Assignment | A compact warm-up that drills matching construction. |

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Bipartite Matching](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A) | `AOJ` | `Easy` | - | - | - | Bipartite Graph; Augmenting Paths; Kuhn | Official bipartite matching baseline. |
| [Guardian of Decency](https://onlinejudge.org/external/120/12083.pdf) | `UVa` | `Medium` | Bipartite Matching, Independent Set | Compatibility Graph; Matching To Cover | Hall/Konig Intuition | Compatibility Graph | A classic compatibility graph that reduces to maximum matching. |
| [School Dance](https://cses.fi/problemset/task/1696) | `CSES` | `Medium` | Bipartite Matching | Augmenting Paths; Bipartite Matching | Bipartite Graph Modeling | Bipartite Graphs; Pairing; Construction | Matching plus explicit pair recovery. |
| [General Matching](https://judge.yosupo.jp/problem/general_matching) | `Library Checker` | `Hard` | - | - | - | Blossom; Non-Bipartite; Verify | Trusted general-graph matching verification task. |
| [Task Assignment](https://cses.fi/problemset/task/2129) | `CSES` | `Hard` | - | - | - | Assignment; Weighted Matching; Bipartite Graph | Weighted bipartite matching in assignment form. |

### Classics

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [A Plug for UNIX](https://onlinejudge.org/external/7/753.pdf) | `UVa` | `Medium` | Bipartite Matching, Adapter Graph | Reachability Closure; Max Matching | Graph Modeling | Conversion Graph | A very standard matching reduction with adapters and compatibility. |
| [Antenna Placement](https://onlinejudge.org/external/103/10349.pdf) | `UVa` | `Medium` | Minimum Vertex Cover | Grid Bipartization; Vertex Cover Extraction | Bipartite Graphs | Grid Graphs; Domination | Canonical grid-adjacency matching reduction. |
| [Machine Schedule](https://onlinejudge.org/index.php?Itemid=8&option=com_onlinejudge&page=show_problem&problem=3635) | `UVa` | `Medium` | Bipartite Matching, Job Assignment | Job-Machine Bipartite Graph; Minimum Cover Intuition | Minimum Vertex Cover Intuition | Scheduling | Another classic assignment problem with a matching core. |

### Advanced

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Sorting Slides](https://onlinejudge.org/external/6/663.pdf) | `UVa` | `Hard` | Unique Assignment | Forced-Edge Reasoning; Matching Plus Uniqueness | Bipartite Matching; Geometry To Graph | Geometry; Deduction | A harder matching problem because uniqueness of assignment matters. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `QBFLOWER` | Tặng hoa | `primary` | `medium` | minimum edge cover; general matching; graph transformation | [Note](../../../practice/ladders/graphs/matching/qbflower.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/matching/qbflower.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
