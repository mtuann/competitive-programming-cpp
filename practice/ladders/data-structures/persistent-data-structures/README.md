# Persistent Data Structures Ladder

Use this ladder when:

- you trust ordinary segment trees
- "copy / snapshot / old version" is now the real modeling cue
- you want one exact first route for persistence before touching fancier order-statistics variants

## Warm-Up Goal

Before leaving this lane, you should be able to:

- explain why copying the whole array is wasteful
- say why one point update only changes one root-to-leaf path
- keep a `roots` array where each version is one handle
- distinguish `persistent versions` from `rollback`

## Core Retrieval Route

- exact quick sheet -> [Persistent Data Structures hot sheet](../../../../notebook/persistent-data-structures-hot-sheet.md)
- exact starter -> [`persistent-segment-tree-point-set-sum.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/persistent-segment-tree-point-set-sum.cpp)
- exact flagship rep -> [Range Queries and Copies](rangequeriesandcopies.md)

## What This Lane Teaches First

- persistent segment tree by path copying
- version roots as the real state
- point assignment + range sum over many alive versions
- why a copy operation is usually just one new root handle

## Compare Points

- one current version only -> [Segment Tree ladder](../segment-tree/README.md)
- undo while traversing time / DFS -> [DSU Rollback ladder](../dsu-rollback/README.md)
- range updates on one active array -> [Lazy Segment Tree ladder](../lazy-segment-tree/README.md)

## Suggested Loop

1. reread the version/root invariant from [Persistent Data Structures](../../../../topics/data-structures/persistent-data-structures/README.md)
2. trust one exact implementation through [Range Queries and Copies](rangequeriesandcopies.md)
3. compare that route back against [Dynamic Range Sum Queries](../segment-tree/dynamicrangesumqueries.md) so "new version" vs "mutate current tree" feels crisp
4. only then stretch toward richer persistent variants

## Exit Criteria

You are ready to leave the lane when:

- you can explain why one update adds only `O(log n)` new nodes
- you no longer confuse "copy version" with "deep copy the whole array"
- you can say clearly when rollback is the better worldview than persistence

## External Follow-Up

- [CSES - Range Queries and Copies](https://cses.fi/problemset/task/1737)
- [SPOJ - MKTHNUM](https://www.spoj.com/problems/MKTHNUM/)
- [Library Checker - Persistent Union Find](https://judge.yosupo.jp/problem/persistent_unionfind)
