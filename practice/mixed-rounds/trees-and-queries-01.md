# Trees And Queries 01

This pack is for `rooted-tree retrieval`: ancestor jumps, subtree states, rerooting, and path queries in one sitting.

## Who This Is For

Use this pack if:

- tree problems still split in your head into too many separate tricks
- `LCA`, `tree DP`, and `HLD` each make sense alone but switching between them still feels slow
- the hard part is deciding what the tree is being used for this time: hierarchy, DP container, or path-query skeleton

## Entry Gate

Try this pack only if these already feel like review:

- [Company Queries II](../ladders/graphs/lca/companyqueries2.md)
- [Tree Matching](../ladders/dp/tree-dp/treematching.md)
- [Tree Distances II](../ladders/dp/tree-dp/treedistances2.md)
- [Path Queries II](../ladders/graphs/hld/pathqueries2.md)
- [MTREECOL](../ladders/graphs/trees/mtreecol.md) if you want the full five-slot pack
- otherwise at least the [Trees ladder](../ladders/graphs/trees/README.md), and treat slot `5` as optional bonus rather than core

## Pack Shape

- Type: `rooted-tree switching drill`
- Topic mix: `LCA + tree DP + rerooting + HLD + tree-as-structure reduction`
- Problems: `5`
- Suggested time: `3-4 hours`

## Topics Under Test

- deciding whether the tree is mainly an ancestor hierarchy, a DP container, or a path-query structure
- keeping parent/depth/subtree language stable across different solution families
- switching from one-root answers to all-roots answers
- knowing when a tree problem is not “just more DP”

## Suggested Order

| Slot | Problem | Topic | Why it is here |
| --- | --- | --- | --- |
| 1 | [Company Queries II](../ladders/graphs/lca/companyqueries2.md) | `LCA` | Opens with the cleanest rooted-hierarchy query and anchors depth/ancestor language. |
| 2 | [Tree Matching](../ladders/dp/tree-dp/treematching.md) | `Tree DP` | Switches the tree from a query object into a rooted-subtree DP container. |
| 3 | [Tree Distances II](../ladders/dp/tree-dp/treedistances2.md) | `Rerooting` | Keeps the rooted-tree vocabulary but changes the main task into all-roots transfer. |
| 4 | [Path Queries II](../ladders/graphs/hld/pathqueries2.md) | `HLD` | Reframes the tree again as a path-query reduction over a base array. |
| 5 | [MTREECOL](../ladders/graphs/trees/mtreecol.md) | `Tree as precedence structure` | Optional stretch slot: ends with one tree reduction where the tree is mostly a constraint graph, not a normal DP/query family. |

## How To Run It

- solve in order so the pack keeps changing what “the tree” means
- before coding each slot, write one short line: `hierarchy`, `subtree DP`, `all-roots DP`, `path query`, or `precedence structure`
- if recognition is still fuzzy after about `12-15 minutes`, allow one refresher page and restart once
- if one slot still feels dead after about `30 minutes`, log the wrong tree model and continue

## Allowed Refreshers

- [Graph cheatsheet](../../notebook/graph-cheatsheet.md)
- [DP cheatsheet](../../notebook/dp-cheatsheet.md)
- [HLD hot sheet](../../notebook/hld-hot-sheet.md)
- [Trees](../../topics/graphs/trees/README.md)
- [Tree DP](../../topics/dp/tree-dp/README.md)
- [LCA](../../topics/graphs/lca/README.md)

## Debrief

After the pack, write down:

1. Which slot made you choose the wrong tree model first.
2. Whether you lost more time to `state design`, `ancestor bookkeeping`, or `path reduction`.
3. Which rooted-tree invariant now feels reusable across several families instead of isolated to one topic.

## Go Back Next

- if slot `1` was weak, revisit [LCA](../ladders/graphs/lca/README.md)
- if slots `2-3` were weak, revisit [Tree DP](../ladders/dp/tree-dp/README.md)
- if slot `4` was weak, revisit [Heavy-Light Decomposition](../ladders/graphs/hld/README.md)
- if optional slot `5` was weak, revisit [Trees](../ladders/graphs/trees/README.md) and compare it with [Tree DP](../ladders/dp/tree-dp/README.md)
- if the whole pack felt manageable, return to [Contest Core Switching 01](contest-core-switching-01.md) or a track playbook
