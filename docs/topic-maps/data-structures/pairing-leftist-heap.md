# Data Structures -> Pairing Heap / Leftist Heap

Use a meldable heap when many singleton heaps keep unioning and the real primitive is merge rather than push.

- Topic slug: `data-structures/pairing-leftist-heap`
- Tutorial page: [Open tutorial](../../../topics/data-structures/pairing-leftist-heap/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/data-structures/pairing-leftist-heap/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `4`
- Curated external problems: `2`

## Microtopics

- meldable-heap
- leftist-heap
- pairing-heap
- merge
- delete-min
- owner-tracking

## Learning Sources

| Source | Type |
| --- | --- |
| [OI Wiki leftist tree](https://en.oi-wiki.org/ds/leftist-tree/) | `Reference` |
| [OI Wiki pairing heap](https://en.oi-wiki.org/ds/pairing-heap/) | `Reference` |
| [Luogu P3377](https://www.luogu.com.cn/problem/P3377) | `Practice` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Luogu P1456](https://www.luogu.com.cn/problem/P1456) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Pairing / Leftist Heap hot sheet](../../../notebook/pairing-leftist-heap-hot-sheet.md) | `quick reference` |
| [Mergeable Heap 1](../../../practice/ladders/data-structures/pairing-leftist-heap/mergeableheap1.md) | `flagship note` |
| [Heaps And Ordered Sets](../../../topics/data-structures/heaps-and-ordered-sets/README.md) | `compare point` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [P3377 [Template] Mergeable Heap 1](https://www.luogu.com.cn/problem/P3377) | `Luogu` | `Medium` | Meldable-Heap, Leftist-Heap | Data-Structure-Heavy; Implementation | Priority Queues; Heap Merge; Owner Tracking | Delete Min; DSU; Simulation | The cleanest verifier-style first rep where every item starts in its own heap, heaps meld online, and delete-min is asked by naming one item's current heap. |

### Challenge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [P1456 Monkey King](https://www.luogu.com.cn/problem/P1456) | `Luogu` | `Hard` | Meldable-Heap | Data-Structure-Heavy; Implementation | Heap Merge; Delete Min; Owner Tracking | Leftist Heap; Heap Merge | A classic follow-up where the same meldable-heap route survives after each duel mutates the current roots before the heaps merge again. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `MERGEABLEHEAP1` | P3377 [Template] Mergeable Heap 1 | `primary` | `medium` | - | [Note](../../../practice/ladders/data-structures/pairing-leftist-heap/mergeableheap1.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/pairing-leftist-heap/mergeableheap1.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
