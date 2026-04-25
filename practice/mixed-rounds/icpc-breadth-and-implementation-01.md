# ICPC Breadth And Implementation 01

This pack is for `ICPC-style breadth plus implementation stability`: banker-first ordering, one-machine realism, and a late slot that still punishes sloppy code.

## Who This Is For

Use this pack if:

- standard contest-core families already feel familiar in isolation
- you want one session that tests opening order, switching, and code reliability together
- your main misses are no longer “I have never seen this,” but “I mis-prioritized it” or “the implementation leaked”

## Entry Gate

Try this pack only if these already feel like review:

- [Message Route](../ladders/graphs/bfs-dfs/messageroute.md)
- [String Matching](../ladders/strings/kmp/stringmatching.md)
- [Dynamic Range Sum Queries](../ladders/data-structures/segment-tree/dynamicrangesumqueries.md)
- [Road Reparation](../ladders/graphs/mst/roadreparation.md)
- [Book Shop](../ladders/dp/knapsack-family/bookshop.md)

If slot `5` still feels shaky, treat it as the late implementation slot rather than the first target.

## Pack Shape

- Type: `ICPC breadth + implementation drill`
- Topic mix: `Graphs + strings + DP + data structures`
- Problems: `5`
- Suggested time: `3-4 hours`

## Topics Under Test

- recognizing the safest banker quickly
- switching from compact banker solves into medium graph and DP slots without losing machine tempo
- keeping machine time on the cleanest current solve
- protecting accepted checkpoints before reviving the late implementation slot

## Suggested Order

| Slot | Problem | Topic | Why it is here |
| --- | --- | --- | --- |
| 1 | [Message Route](../ladders/graphs/bfs-dfs/messageroute.md) | `BFS + reconstruction` | First banker: low setup cost, quick graph read, and one clean path-certification loop. |
| 2 | [String Matching](../ladders/strings/kmp/stringmatching.md) | `KMP` | Second banker: compact linear implementation and a very different modeling surface from slot `1`. |
| 3 | [Road Reparation](../ladders/graphs/mst/roadreparation.md) | `MST / DSU` | Medium graph slot where the key is not mistaking MST for shortest-path thinking. |
| 4 | [Book Shop](../ladders/dp/knapsack-family/bookshop.md) | `Knapsack DP` | Forces a mental reset into state/iteration discipline after two graph-facing slots. |
| 5 | [Dynamic Range Sum Queries](../ladders/data-structures/segment-tree/dynamicrangesumqueries.md) | `Segment tree` | Late implementation slot: simple idea, but one indexing or interval mistake can still sink the session. |

## How To Run It

1. spend `15-20 minutes` on a real opening triage before writing code
2. fill one short board with:
   - banker / medium / investment
   - owner
   - machine priority
   - bailout minute
3. solve in the suggested order unless the triage board gives a concrete reason to swap two adjacent slots
4. after each slot, decide `bank / hand off / park`, not just “keep poking it”
5. if one slot stalls for about `20-25 minutes` with no localized bug or invariant, park it and move

## Allowed Refreshers

- [Contest Checklist](../../notebook/contest-checklist.md)
- [Graph cheatsheet](../../notebook/graph-cheatsheet.md)
- [Data structures cheatsheet](../../notebook/data-structures-cheatsheet.md)
- [DP cheatsheet](../../notebook/dp-cheatsheet.md)
- [String cheatsheet](../../notebook/string-cheatsheet.md)
- [Build Kit](../../docs/build-kit.md)

## Debrief

After the pack, log:

1. first triage mistake
2. first machine-usage mistake
3. first implementation leak that cost real time
4. whether slot `5` died from fatigue, weak retrieval, or interval/index discipline
5. the slot that should become your next focused ladder revisit

## Go Back Next

- if slot `1` was weak, revisit [BFS / DFS ladder](../ladders/graphs/bfs-dfs/README.md)
- if slot `2` was weak, revisit [KMP ladder](../ladders/strings/kmp/README.md)
- if slot `3` was weak, revisit [MST ladder](../ladders/graphs/mst/README.md)
- if slot `4` was weak, revisit [Knapsack Family ladder](../ladders/dp/knapsack-family/README.md)
- if slot `5` was weak, revisit [Segment Tree ladder](../ladders/data-structures/segment-tree/README.md)
- if the whole pack felt structurally bad, reopen [ICPC Playbook](../contest-playbooks/icpc.md)
