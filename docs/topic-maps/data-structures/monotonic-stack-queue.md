# Data Structures -> Monotonic Stack / Queue

One linear scan, one domination rule: use monotonic stacks for boundaries and deques for fixed-width extrema.

- Topic slug: `data-structures/monotonic-stack-queue`
- Tutorial page: [Open tutorial](../../../topics/data-structures/monotonic-stack-queue/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/data-structures/monotonic-stack-queue/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `3`
- Curated external problems: `3`

## Microtopics

- previous-smaller
- next-smaller
- monotonic-stack
- monotonic-deque
- sliding-window-minmax
- histogram-boundaries

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms minimum stack / minimum queue](https://cp-algorithms.com/data_structures/stack_queue_modification.html) | `Reference` |
| [Competitive Programmer's Handbook](https://www.cses.fi/book/book.pdf) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Nearest Smaller Values](https://cses.fi/problemset/task/1645) | `Practice` |
| [CSES Sliding Window Minimum](https://cses.fi/problemset/task/3221) | `Practice` |
| [CSES Advertisement](https://cses.fi/problemset/task/1142) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Monotonic Stack / Queue hot sheet](../../../notebook/monotonic-stack-queue-hot-sheet.md) | `quick reference` |
| [Nearest Smaller Values note](../../../practice/ladders/data-structures/monotonic-stack-queue/nearestsmallervalues.md) | `anchor note` |
| [Data structures cheatsheet](../../../notebook/data-structures-cheatsheet.md) | `broader chooser` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Nearest Smaller Values](https://cses.fi/problemset/task/1645) | `CSES` | `Medium` | Monotonic Stack | Implementation; Amortized | Stacks; Indices; Strict Comparators | Previous-Smaller; Boundary | The canonical first boundary-scan problem for the monotonic-stack side of the family. |
| [Sliding Window Minimum](https://cses.fi/problemset/task/3221) | `CSES` | `Medium` | Monotonic Deque | Implementation; Streaming | Deque; Window Expiry; Amortized Reasoning | Window-Minimum; Stream | The queue-side canonical benchmark where domination pops and window expiry are both visible. |

### Classics

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Advertisement](https://cses.fi/problemset/task/1142) | `CSES` | `Medium` | Monotonic Stack | Implementation; Geometry-On-Array | Boundary Indices | Histogram; Nearest-Smaller; Rectangle Area | A strong follow-up where nearest-smaller boundaries turn directly into widths. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `NEARESTSMALLERVALUES` | Nearest Smaller Values | `primary` | `medium` | - | [Note](../../../practice/ladders/data-structures/monotonic-stack-queue/nearestsmallervalues.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/monotonic-stack-queue/nearestsmallervalues.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
