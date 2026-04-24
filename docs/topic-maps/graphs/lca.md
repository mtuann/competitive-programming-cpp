# Graphs -> LCA

Lowest common ancestor as a reusable primitive for ancestor checks and path queries on rooted trees.

- Topic slug: `graphs/lca`
- Tutorial page: [Open tutorial](../../../topics/graphs/lca/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/graphs/lca/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `0`
- Curated external problems: `6`

## Microtopics

- binary-lifting
- euler-tour
- rmq-reduction
- tin-tout
- ancestor-query
- path-query

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms binary lifting](https://cp-algorithms.com/graph/lca_binary_lifting.html) | `trusted guide` |
| [OI Wiki LCA](https://en.oi-wiki.org/graph/lca/) | `trusted guide` |
| [USACO Guide Euler tour technique](https://usaco.guide/gold/tree-euler/) | `trusted guide` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Library Checker LCA](https://judge.yosupo.jp/problem/lca) | `problem` |
| [CSES Problem Set](https://cses.fi/problemset/) | `problem set` |
| [USACO contest archive](https://usaco.org/index.php?page=contests) | `contest archive` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Company Queries I](https://cses.fi/problemset/task/1687) | `CSES` | `Easy` | - | - | - | Binary Lifting; Kth Ancestor; Jump Pointers | Ancestor lifting in its purest form. |

### Binary Lifting

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Company Queries II](https://cses.fi/problemset/task/1688) | `CSES` | `Medium` | Binary Lifting | Jump Pointers; Depth Equalization; Ancestor Climbing | Tree Depth; Ancestor Tables | Lowest Common Ancestor; Boss Queries; Ancestor Table; Boss Hierarchy | Classic LCA queries over a rooted tree hierarchy. |

### LCA Application

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [閉路](https://atcoder.jp/contests/abc014/tasks/abc014_4) | `AtCoder` | `Medium` | Distances | Distance Via LCA; Path Length Formula; Query Preprocessing | LCA; Depth Arrays; Tree Distances | Cycle Length; Tree Path; Query Answer | A classic LCA application where each query becomes a path-length computation. |

### LCA Basics

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [LCA: Lowest Common Ancestor](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C) | `AOJ` | `Medium` | - | Binary Lifting; Euler Tour; Ancestor Checks | Trees; DFS Order; Ancestor Climbing | Rooted Tree; Binary Lifting; Ancestor Queries | The official baseline LCA problem from AOJ. |
| [Lowest Common Ancestor](https://judge.yosupo.jp/problem/lca) | `Library Checker` | `Medium` | - | Binary Lifting; HLD-Style Interface; Query Batching | Rooted Tree; Ancestor Tables; LCA Concept | Implementation Check; Rooted Tree; Verify; Binary Lifting | A compact verification judge for a production-grade LCA routine. |

### LCA Distance Formula

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Distance Queries](https://cses.fi/problemset/task/1135) | `CSES` | `Medium` | Distances | Depth Plus LCA; Distance Formula; Binary Lifting | LCA; Tree Depth; Ancestor Jumps | Tree Distance; Path Length; Distance; Rooted Tree | Uses LCA as the backbone for tree distance answers. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `COMPANYQUERIES2` | Company Queries II | `primary` | `medium` | binary lifting; depth equalization; lowest common ancestor | [Note](../../../practice/ladders/graphs/lca/companyqueries2.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/lca/companyqueries2.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
