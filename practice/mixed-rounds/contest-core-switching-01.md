# Contest Core Switching 01

This pack is for `breadth and gear-switching` once the main contest-core families already feel familiar.

## Who This Is For

Use this pack if:

- you have already solved several focused ladder problems
- switching between data structures, graphs, DP, strings, and math still feels slow
- you want a light contest-style drill without committing to a full contest set

## Entry Gate

Try this pack only if at least most of these already feel like review, not first exposure:

- [Dynamic Range Sum Queries](../ladders/data-structures/segment-tree/dynamicrangesumqueries.md)
- [Course Schedule](../ladders/graphs/scc-toposort/courseschedule.md)
- [Book Shop](../ladders/dp/knapsack-family/bookshop.md)
- [Finding Periods](../ladders/strings/z-function/findingperiods.md)
- [Exponentiation II](../ladders/math/modular-arithmetic/exponentiation2.md)

## Pack Shape

- Type: `contest-style drill`
- Topic mix: `Data structures + graphs + DP + strings + math`
- Problems: `5`
- Suggested time: `2.5-3.5 hours`

## Topics Under Test

- update/query invariant recall
- directed dependency modeling
- state-transition reset speed
- string-pattern recognition
- modular-identity recall under pressure

## Suggested Order

| Slot | Problem | Topic | Why it is here |
| --- | --- | --- | --- |
| 1 | [Dynamic Range Sum Queries](../ladders/data-structures/segment-tree/dynamicrangesumqueries.md) | `Segment tree` | Starts with a clean update/query data-structure loop. |
| 2 | [Course Schedule](../ladders/graphs/scc-toposort/courseschedule.md) | `Toposort` | Changes the mental model from range maintenance to dependency structure. |
| 3 | [Book Shop](../ladders/dp/knapsack-family/bookshop.md) | `Knapsack DP` | Forces a state-transition reset and disciplined iteration order. |
| 4 | [Finding Periods](../ladders/strings/z-function/findingperiods.md) | `Strings / Z-function` | Injects a pattern-recognition problem instead of raw simulation. |
| 5 | [Exponentiation II](../ladders/math/modular-arithmetic/exponentiation2.md) | `Modular arithmetic` | Finishes with a formula-heavy task where the key is using the right identity quickly. |

## How To Run It

- treat this as one sitting if possible
- only open topic refreshers between problems, not during implementation
- keep a short scratch log of the first wrong instinct for each slot
- if recognition is still missing after about `15 minutes`, allow one refresher page and restart once
- if one slot still goes nowhere after about `30 minutes`, log it and move on instead of letting the whole session collapse

## Allowed Refreshers

- [Data structures cheatsheet](../../notebook/data-structures-cheatsheet.md)
- [Graph cheatsheet](../../notebook/graph-cheatsheet.md)
- [DP cheatsheet](../../notebook/dp-cheatsheet.md)
- [String cheatsheet](../../notebook/string-cheatsheet.md)
- [Number theory cheatsheet](../../notebook/number-theory-cheatsheet.md)

## Debrief

This pack is doing its job if you can answer these after the round:

- which problem took the longest to recognize, not to code?
- where did you lose time to syntax vs to modeling?
- which topic still needs one more focused ladder pass before more mixed practice?

## Go Back Next

- back to [Ladders](../ladders/README.md) if one topic clearly felt weak
- into [Graphs And DP Switching 01](graphs-dp-switching-01.md) if the graph/DP slots were the real bottleneck
- into [Strings, Math, And Counting 01](strings-math-counting-01.md) if the symbolic topics were the real bottleneck
- or into [Contest Playbooks](../contest-playbooks/README.md) if the switching itself felt manageable
