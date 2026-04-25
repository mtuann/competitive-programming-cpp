# Petrozavodsk / OpenCup Hard Mixed 01

This pack is a repo-native stand-in for `camp-style hard mixed practice`: advanced switching, hard implementation, and no guarantee that the first visible route is the cleanest one.

## Who This Is For

Use this pack if:

- several advanced topics already feel like review
- your main misses now come from switching between very different hard models
- you want a camp-style sitting without pretending the repo is a full Petrozavodsk archive mirror

## Entry Gate

Try this pack only if these already feel stable:

- [Centroid Decomposition](../../topics/graphs/centroid-decomposition/README.md)
- [Persistent Data Structures](../../topics/data-structures/persistent-data-structures/README.md)
- [DSU Rollback / Offline Dynamic Connectivity](../../topics/data-structures/dsu-rollback/README.md)
- [Convex Hull Trick / Li Chao Tree](../../topics/dp/cht-li-chao/README.md)

At minimum, these should no longer feel like first exposure:

- [Ciel the Commander](../ladders/graphs/centroid-decomposition/cielthecommander.md)
- [Range Queries and Copies](../ladders/data-structures/persistent-data-structures/rangequeriesandcopies.md)
- [Dynamic Connectivity](../ladders/data-structures/dsu-rollback/dynamicconnectivity.md)

## Pack Shape

- Type: `camp-style advanced hard mixed drill`
- Topic mix: `tree decomposition + versioning + offline dynamic connectivity + affine DP optimization`
- Problems: `4`
- Suggested time: `4.5-6 hours`

## Topics Under Test

- whether you can keep advanced models compact under fatigue
- whether you know when to park one investment slot instead of contaminating the whole session
- whether your retrieval layer is good enough for advanced implementation, not only core CP

## Suggested Order

| Slot | Problem | Topic | Why it is here |
| --- | --- | --- | --- |
| 1 | [Ciel the Commander](../ladders/graphs/centroid-decomposition/cielthecommander.md) | `centroid decomposition` | Structural first slot: the idea is advanced, but the implementation surface is still contained enough to start the pack cleanly. |
| 2 | [Range Queries and Copies](../ladders/data-structures/persistent-data-structures/rangequeriesandcopies.md) | `persistent segment tree` | Versioned data structure slot: harder implementation discipline without the full timeline complexity of rollback. |
| 3 | [Dynamic Connectivity](../ladders/data-structures/dsu-rollback/dynamicconnectivity.md) | `DSU rollback + offline segmentation` | Camp-style mid-to-late slot where modeling drift and implementation drift interact. |
| 4 | [Monster Game II](../ladders/dp/cht-li-chao/monstergame2.md) | `Li Chao tree` | Optional late investment: sharp signal, but the best play is often to open it only after the earlier structure-heavy slots are stable. |

## How To Run It

1. spend `12-15 minutes` reading all `4` slots and tag each as:
   - `shippable with work`
   - `investment but real`
   - `park for now`
2. solve in the suggested order unless slot `2` feels dramatically cleaner than slot `1`
3. do **not** open slot `4` if slot `3` still lacks a compact model
4. after each finished or parked slot, log:
   - first model leak
   - first implementation leak
   - whether the slot should have been parked earlier
5. allow at most one short hot-sheet refresh between slots

## Allowed Refreshers

- [Centroid Decomposition hot sheet](../../notebook/centroid-hot-sheet.md)
- [Persistent Data Structures hot sheet](../../notebook/persistent-data-structures-hot-sheet.md)
- [DSU Rollback hot sheet](../../notebook/dsu-rollback-hot-sheet.md)
- [CHT / Li Chao hot sheet](../../notebook/cht-hot-sheet.md)
- [Build Kit](../../docs/build-kit.md)

## Debrief

Write down:

1. the first slot whose model was wrong, not just incomplete
2. the first slot whose implementation burden was underestimated
3. the first slot that should have been parked earlier
4. one exact recovery route for the next session

## Go Back Next

- centroid structure still fuzzy -> [Centroid Decomposition ladder](../ladders/graphs/centroid-decomposition/README.md)
- versioned updates still noisy -> [Persistent Data Structures ladder](../ladders/data-structures/persistent-data-structures/README.md)
- timeline segmentation / rollback still fuzzy -> [DSU Rollback ladder](../ladders/data-structures/dsu-rollback/README.md)
- affine DP signal still weak -> [CHT / Li Chao ladder](../ladders/dp/cht-li-chao/README.md)
- the whole pack felt strategically wrong -> [Contest Engineering](../../topics/advanced/contest-engineering/README.md)
