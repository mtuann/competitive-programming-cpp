# DP -> Bit-Parallelism / Bitset Optimization

Pack one large boolean DP row into machine words so shift-OR reachability updates run wordwise instead of scalar O(nW) loops.

- Topic slug: `dp/bit-parallelism`
- Tutorial page: [Open tutorial](../../../topics/dp/bit-parallelism/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/dp/bit-parallelism/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `2`

## Microtopics

- bitset-dp
- word-packing
- shift-or-reachability
- subset-sum-bitset
- component-size-knapsack
- packed-boolean-state

## Learning Sources

| Source | Type |
| --- | --- |
| [Competitive Programmer's Handbook](https://www.cses.fi/book/book.pdf) | `Reference` |
| [Guide to Competitive Programming](https://link.springer.com/book/10.1007/978-3-031-61794-2) | `Reference` |
| [CSES School Excursion](https://cses.fi/problemset/task/1706/) | `Practice` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Money Sums](https://cses.fi/problemset/task/1745/) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Bit-Parallelism / Bitset Optimization hot sheet](../../../notebook/bit-parallelism-hot-sheet.md) | `quick reference` |
| [School Excursion note](../../../practice/ladders/dp/bit-parallelism/schoolexcursion.md) | `flagship note` |
| [Knapsack Family tutorial](../../../topics/dp/knapsack-family/README.md) | `compare point` |
| [FWHT / XOR Convolution / Subset Convolution tutorial](../../../topics/dp/fwht-subset-convolution/README.md) | `compare point` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [School Excursion](https://cses.fi/problemset/task/1706/) | `CSES` | `Hard` | Bitset DP | Dynamic Programming; Implementation; Graph Modeling | DSU; Boolean DP; Shift-Or Reachability | Bitset; Reachability; Component Sizes; Subset Sum | The clean flagship where a light DSU reduction produces one subset-sum reachability row and the intended implementation win is packed bitset shift-OR. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Money Sums](https://cses.fi/problemset/task/1745/) | `CSES` | `Easy` | Subset Sum | Dynamic Programming; Implementation | Boolean DP; Shift-Or Reachability | Bitset; Reachable Sums; Boolean DP | A smaller warm-up where the same packed reachability update is already clean even if ordinary scalar DP still exists. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `SCHOOLEXCURSION` | School Excursion | `primary` | `hard` | - | [Note](../../../practice/ladders/dp/bit-parallelism/schoolexcursion.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/bit-parallelism/schoolexcursion.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
