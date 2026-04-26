# Graphs -> Eulerian Path / Cycle

Degree conditions, Hierholzer traversal, and use-every-edge-once constructions in directed and undirected graphs.

- Topic slug: `graphs/eulerian-path-cycle`
- Tutorial page: [Open tutorial](../../../topics/graphs/eulerian-path-cycle/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/graphs/eulerian-path-cycle/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `3`

## Microtopics

- hierholzer
- eulerian-trail
- eulerian-cycle
- degree-parity
- indegree-outdegree-balance
- de-bruijn-reduction

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms Eulerian Path](https://cp-algorithms.com/graph/euler_path.html) | `Reference` |
| [OI Wiki Euler graph](https://en.oi-wiki.org/graph/euler/) | `Reference` |
| [CSES Mail Delivery](https://cses.fi/problemset/task/1691/) | `Practice` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Problem Set](https://cses.fi/problemset/) | `Practice` |
| [CSES Teleporters Path](https://cses.fi/problemset/task/1693/) | `Practice` |
| [Codeforces problemset](https://codeforces.com/problemset) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Eulerian hot sheet](../../../notebook/eulerian-hot-sheet.md) | `quick reference` |
| [Eulerian starter route](../../../template-library.md) | `starter route` |
| [Mail Delivery note](../../../practice/ladders/graphs/eulerian-path-cycle/maildelivery.md) | `anchor note` |
| [Graph cheatsheet](../../../notebook/graph-cheatsheet.md) | `quick reference` |
| [Euler Tour / Subtree Queries tutorial](../../../topics/graphs/euler-tour-subtree/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Mail Delivery](https://cses.fi/problemset/task/1691) | `CSES` | `Medium` | Undirected | Hierholzer Traversal; Degree Check; Witness Output | Undirected Graphs; Degree Parity; DFS-Style Traversal | Eulerian Cycle; Hierholzer; Degree Parity; Undirected Graphs | The cleanest first contest problem for undirected Eulerian cycles: parity, connected support, and one Hierholzer walk. |
| [Teleporters Path](https://cses.fi/problemset/task/1693) | `CSES` | `Hard` | Directed | Directed Hierholzer; Balance Check; Start-End Enforcement | Directed Graphs; Indegree And Outdegree; Eulerian Trail Conditions | Eulerian Path; Directed Graphs; In-Out Balance; Hierholzer | The canonical directed-path benchmark where start and end are fixed and in/out balance matters more than parity. |

### Classics

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Play on Words](https://onlinejudge.org/external/1/10129.pdf) | `UVa` | `Medium` | Classic | Modeling; Balance Check; Connected Support | Directed Graphs; Eulerian Path Conditions; Graph Modeling | String To Graph; Directed Eulerian Path | A classic Eulerian-reduction problem where statement parsing and graph support checks matter as much as the traversal itself. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `MAILDELIVERY` | Mail Delivery | `primary` | `medium` | - | [Note](../../../practice/ladders/graphs/eulerian-path-cycle/maildelivery.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/eulerian-path-cycle/maildelivery.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
