# Graphs -> De Bruijn Sequence

Overlap-state modeling where length-n windows become directed edges, and one Eulerian cycle linearizes into a universal sequence.

- Topic slug: `graphs/de-bruijn-sequence`
- Tutorial page: [Open tutorial](../../../topics/graphs/de-bruijn-sequence/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/graphs/de-bruijn-sequence/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `1`

## Microtopics

- de-bruijn-graph
- overlap-states
- binary-order-n
- eulerian-construction
- implicit-state-graph
- window-cover-construction

## Learning Sources

| Source | Type |
| --- | --- |
| [Competitive Programmer's Handbook PDF](https://www.cses.fi/book/book.pdf) | `Reference` |
| [CSES De Bruijn Sequence](https://cses.fi/problemset/task/1692) | `Practice` |
| [CP-Algorithms Eulerian Path](https://cp-algorithms.com/graph/euler_path.html) | `Reference` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [De Bruijn Sequence hot sheet](../../../notebook/de-bruijn-sequence-hot-sheet.md) | `quick reference` |
| [De Bruijn Sequence note](../../../practice/ladders/graphs/de-bruijn-sequence/debruijnsequence.md) | `flagship note` |
| [Eulerian Path / Cycle tutorial](../../../topics/graphs/eulerian-path-cycle/README.md) | `compare point` |
| [Graph Modeling tutorial](../../../topics/graphs/graph-modeling/README.md) | `compare point` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [De Bruijn Sequence](https://cses.fi/problemset/task/1692) | `CSES` | `Hard` | Graph Modeling, Construction | State Graph Modeling; Eulerian Construction; String Reconstruction | Eulerian Cycle; Bitmask States | De Bruijn Graph; Eulerian Cycle; Bitmask States | The clean binary flagship where overlap-state modeling is the whole trick, and an Eulerian cycle is only the execution engine after the graph is revealed. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `DEBRUIJNSEQUENCE` | De Bruijn Sequence | `primary` | `hard` | - | [Note](../../../practice/ladders/graphs/de-bruijn-sequence/debruijnsequence.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/de-bruijn-sequence/debruijnsequence.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
