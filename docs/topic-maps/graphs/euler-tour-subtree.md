# Graphs -> Euler Tour / Subtree Queries

Flatten one rooted subtree into one contiguous interval so subtree-only queries become array range queries.

- Topic slug: `graphs/euler-tour-subtree`
- Tutorial page: [Open tutorial](../../../topics/graphs/euler-tour-subtree/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/graphs/euler-tour-subtree/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `4`
- Curated external problems: `4`

## Microtopics

- tin-tout
- single-entry-tour
- subtree-interval
- flatten-tree
- fenwick-on-tour
- subtree-sum
- point-update

## Learning Sources

| Source | Type |
| --- | --- |
| [USACO Guide Euler Tour Technique](https://usaco.guide/gold/tree-euler/) | `Reference` |
| [OI Wiki tree basics](https://en.oi-wiki.org/graph/tree-basic/) | `Reference` |
| [CSES Subtree Queries](https://cses.fi/problemset/task/1137/) | `Practice` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Problem Set](https://cses.fi/problemset/) | `Practice` |
| [USACO contest archive](https://usaco.org/index.php?page=contests) | `Practice` |
| [AtCoder problems archive](https://atcoder.jp/contests/archive) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Subtree Queries hot sheet](../../../notebook/subtree-queries-hot-sheet.md) | `quick reference` |
| [Euler Tour subtree starter route](../../../template-library.md) | `starter route` |
| [Subtree Queries note](../../../practice/ladders/graphs/euler-tour-subtree/subtreequeries.md) | `anchor note` |
| [Trees tutorial](../../../topics/graphs/trees/README.md) | `adjacent tutorial` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Subtree Queries](https://cses.fi/problemset/task/1137) | `CSES` | `Medium` | Trees, Euler Tour | Flatten Tree; Fenwick Tree; Range Sum Queries | Rooted Tree; Fenwick Tree | Subtree Sum; Updates; Fenwick | The canonical subtree-interval problem where flattening a rooted tree turns each subtree into one range query. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Count Descendants](https://atcoder.jp/contests/abc202/tasks/abc202_e) | `AtCoder` | `Medium` | Trees, Euler Tour | Flatten Tree; Offline Counting; Binary Search | Subtree Intervals; Binary Search | Subtree Interval; Depth Buckets; Offline | A clean next step where subtree intervals stay the same but you intersect them with depth-grouped positions. |
| [Distinct Colors](https://cses.fi/problemset/task/1139) | `CSES` | `Hard` | Trees | Flatten Tree; Offline Queries; Subtree Aggregation | Euler Tour; Subtree Intervals; Offline Reasoning | Distinct Values; Subtree Aggregation; Offline | A stretch problem showing that the same subtree interval view can feed a different offline engine once sum/count is no longer enough. |

### Bridge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Path Queries](https://cses.fi/problemset/task/1138) | `CSES` | `Medium` | Trees, Euler Tour | Euler Tour; Fenwick Tree; Prefix On Tree | Tree Flattening; Fenwick Tree; Rooted Tree | Root Path Sum; Updates; Tree Flattening | A strong compare point once subtree intervals are trusted and you want to see how similar flattening ideas answer a different rooted-tree query. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `SUBTREEQUERIES` | Subtree Queries | `primary` | `medium` | euler tour flattening; subtree interval; fenwick point set range sum | [Note](../../../practice/ladders/graphs/euler-tour-subtree/subtreequeries.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/euler-tour-subtree/subtreequeries.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
