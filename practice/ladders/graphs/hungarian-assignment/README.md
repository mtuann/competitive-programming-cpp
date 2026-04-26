# Hungarian / Assignment Problem Ladder

This lane is for the first time bipartite pairing becomes **weighted one-to-one assignment**, not just maximum cardinality matching.

## Who This Is For

Use this lane if:

- [Matching](../../../../topics/graphs/matching/README.md) already feels comfortable
- you can explain why "each endpoint at most once" creates a bipartite matching model
- you now need minimum total cost across a perfect assignment

This lane is intentionally narrow:

- one exact starter
- one flagship note that is almost pure assignment matrix
- one compare route against [Min-Cost Flow](../../../../topics/graphs/min-cost-flow/README.md)
- one reminder that blossom is a different boundary

## Warm-Up

- explain why a plain cardinality matcher cannot optimize total cost
- explain why [Min-Cost Flow](../../../../topics/graphs/min-cost-flow/README.md) still works here but is often heavier
- hand-check the best permutation on a `3 x 3` cost matrix

Target skill:

- recognize when the statement is exactly weighted bipartite assignment in matrix form

## Core

- one row per column
- one column per row
- minimum total cost
- exact flagship rep: [Task Assignment](taskassignment.md)

Target skill:

- map the problem directly to a cost matrix and trust the `O(n^3)` Hungarian route

## Stretch

- revisit the same family under "maximize total profit" by negating weights
- compare one assignment-matrix problem against one [Min-Cost Flow](../flow/README.md) problem and explain why the models differ
- try one extra external assignment benchmark after the flagship

Target skill:

- distinguish dense square assignment from richer transport-style flow tasks

## Retrieval Layer

- exact quick sheet -> [Hungarian hot sheet](../../../../notebook/hungarian-hot-sheet.md)
- exact starter -> [hungarian-assignment.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hungarian-assignment.cpp)
- compare route -> [Matching](../../../../topics/graphs/matching/README.md)
- compare route -> [Min-Cost Flow](../../../../topics/graphs/min-cost-flow/README.md)
- broader chooser -> [Graph cheatsheet](../../../../notebook/graph-cheatsheet.md)

## Repo Anchors And Compare Points

- topic page -> [Hungarian / Assignment Problem](../../../../topics/graphs/hungarian-assignment/README.md)
- flagship note -> [Task Assignment](taskassignment.md)
- compare point -> [Matching](../../../../topics/graphs/matching/README.md)
- compare point -> [Min-Cost Flow](../../../../topics/graphs/min-cost-flow/README.md)
- broader routing -> [Graphs ladder](../README.md)

The cleanest in-repo loop here is:

1. reopen [Matching](../../../../topics/graphs/matching/README.md) just enough to remember the one-to-one pairing structure
2. learn the weighted dense-matrix route in [Hungarian / Assignment Problem](../../../../topics/graphs/hungarian-assignment/README.md)
3. solve [Task Assignment](taskassignment.md)
4. compare that exact matrix route against [MINCOST](../flow/mincost.md) to keep the family boundary sharp

## Exit Criteria

You are ready to move on when:

- you can say exactly why this task is assignment, not plain matching
- you know why Hungarian is a cleaner first route than min-cost flow on a dense square matrix
- you can recover the assignment itself, not only the minimum cost

## External Practice

- [CSES - Task Assignment](https://cses.fi/problemset/task/2129)
- [SPOJ - ASSIGN4](https://www.spoj.com/problems/ASSIGN4/)
- [The Great Wall Game](https://www.cs.cmu.edu/~eugene/teach/acm06a/hard/05.pdf)

## Tutorial Link

- [Hungarian / Assignment Problem](../../../../topics/graphs/hungarian-assignment/README.md)
