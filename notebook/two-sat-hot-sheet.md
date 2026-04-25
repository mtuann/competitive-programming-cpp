# Two-SAT Hot Sheet

Use this page when the statement is a binary-feasibility problem with pairwise logical clauses and you want the fastest route back to implication-graph modeling.

## Do Not Use When

- clauses regularly involve `3` or more literals
- variables are not really boolean yet
- the problem is optimization-heavy and feasibility is only one subpart
- you need to count assignments, not just find one or prove none exist

## Choose By Signal

- every object has two modes and each constraint touches at most two literals -> [`two-sat.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/two-sat.cpp)
- the modeling is still fuzzy but SCC/implication language seems close -> reopen [2-SAT](../topics/graphs/two-sat/README.md)
- the clause model is really a graph-reduction question first -> compare with [Graph Modeling](../topics/graphs/graph-modeling/README.md)
- the real issue is SCC compression on a generic directed graph, not boolean clauses -> reopen [Topological Sort And SCC](../topics/graphs/scc-toposort/README.md)

## Core Invariants

- `(a or b)` becomes `not a -> b` and `not b -> a`
- if a literal and its complement land in the same SCC, the instance is impossible
- a satisfying assignment can be read from SCC order by choosing the later component over its complement

## Main Traps

- choosing the wrong boolean meaning before you even build the graph
- mixing up literal encoding and complement encoding
- forgetting that `exactly one` is two clauses, not one
- comparing SCC ids with the wrong convention for the starter you copied

## Exact Starters In This Repo

- binary clauses with assignment extraction -> [`two-sat.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/two-sat.cpp)
- flagship in-lane rep -> [Giant Pizza](../practice/ladders/graphs/two-sat/giantpizza.md)
- simpler directed-graph compare point -> [Course Schedule](../practice/ladders/graphs/scc-toposort/courseschedule.md)
- SCC-first reopening path -> [Topological Sort And SCC](../topics/graphs/scc-toposort/README.md)

## Reopen Paths

- implication-graph proof and assignment extraction -> [2-SAT](../topics/graphs/two-sat/README.md)
- SCC backbone -> [Topological Sort And SCC](../topics/graphs/scc-toposort/README.md)
- graph-family chooser -> [Graph cheatsheet](graph-cheatsheet.md)
- practice lane -> [Two-SAT ladder](../practice/ladders/graphs/two-sat/README.md)
