# Graphs And DP Switching 01

This pack is for `crossing the boundary between graph structure and state design` in one sitting.

## Who This Is For

Use this pack if:

- graph traversal basics already feel familiar
- classic DP notes are no longer brand-new
- the hard part is resetting your mental model quickly when the problem family changes

## Entry Gate

Try this pack only if these already feel like review:

- [Counting Rooms](../ladders/graphs/graph-modeling/countingrooms.md)
- [Course Schedule](../ladders/graphs/scc-toposort/courseschedule.md)
- [Book Shop](../ladders/dp/knapsack-family/bookshop.md)
- [Tree Matching](../ladders/dp/tree-dp/treematching.md)
- [Counting Numbers](../ladders/dp/digit-dp/countingnumbers.md)

## Pack Shape

- Type: `switching drill`
- Topic mix: `Graph modeling + DAG reasoning + knapsack + tree DP + digit DP`
- Problems: `5`
- Suggested time: `3-4 hours`

## Topics Under Test

- turning raw input into the right graph first
- recognizing when indegree structure is the whole problem
- keeping one-dimensional DP updates disciplined
- building minimal subtree states
- introducing a small extra state without overcomplicating the DP

## Suggested Order

| Slot | Problem | Topic | Why it is here |
| --- | --- | --- | --- |
| 1 | [Counting Rooms](../ladders/graphs/graph-modeling/countingrooms.md) | `Graph modeling` | Opens with the simplest graph-state translation and flood-fill discipline. |
| 2 | [Course Schedule](../ladders/graphs/scc-toposort/courseschedule.md) | `Toposort` | Keeps you in graphs but changes the invariant from reachability to dependency order. |
| 3 | [Book Shop](../ladders/dp/knapsack-family/bookshop.md) | `0/1 knapsack` | Forces a clean switch from graph structure to state transitions and loop direction. |
| 4 | [Tree Matching](../ladders/dp/tree-dp/treematching.md) | `Tree DP` | Moves back to graph-shaped input but keeps DP as the main engine. |
| 5 | [Counting Numbers](../ladders/dp/digit-dp/countingnumbers.md) | `Digit DP` | Ends with a more symbolic state design task where the transition logic matters more than implementation volume. |

## How To Run It

- treat slots `1-2` as your graph half and slots `3-5` as your DP half
- do one honest attempt before opening any refresher
- if a slot still feels unrecognizable after about `15 minutes`, allow one refresher page and restart once
- if you are still blocked after about `30 minutes`, log the missing recognition cue and continue

## Allowed Refreshers

- [Graph cheatsheet](../../notebook/graph-cheatsheet.md)
- [DP cheatsheet](../../notebook/dp-cheatsheet.md)
- [Graph Modeling](../../topics/graphs/graph-modeling/README.md)
- [Digit DP](../../topics/dp/digit-dp/README.md)

## Debrief

After the pack, write down:

1. Which slot made you lose the most time to modeling rather than coding.
2. Whether slot `2` or slot `4` felt more natural, and why.
3. Which DP state was easiest to explain out loud, and which one still felt memorized instead of understood.

## Go Back Next

- if slots `1-2` were the main issue, revisit [Graph Modeling](../ladders/graphs/graph-modeling/README.md) or [Topological Sort And SCC](../ladders/graphs/scc-toposort/README.md)
- if slot `3` or `4` was the main issue, revisit [Knapsack Family](../ladders/dp/knapsack-family/README.md) or [Tree DP](../ladders/dp/tree-dp/README.md)
- if slot `5` was the main issue, revisit [Digit DP](../ladders/dp/digit-dp/README.md)
- if the whole pack felt manageable, go back to [Contest Core Switching 01](contest-core-switching-01.md) or move on to a real contest set
