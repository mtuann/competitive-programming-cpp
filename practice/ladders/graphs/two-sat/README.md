# Two-SAT Ladder

This ladder should make `2-SAT` feel like a clean implication-graph reduction instead of a bag of logic tricks.

## Who This Is For

Use this lane if:

- binary-choice feasibility problems still feel magical instead of structural
- you know SCCs, but do not yet see when to turn clauses into implications
- you can check satisfiability in theory, but assignment extraction still feels slippery

This is currently a thin lane on purpose:

- one flagship in-lane rep
- one exact starter
- strong compare points back into `Graph Modeling` and `SCC`

## Warm-Up

- clause to implication rewrite
- literal / complement encoding

Target skill:

- restate a binary logical condition as one or more `2`-literal clauses

## Core

- [Giant Pizza](giantpizza.md)
- implication graph
- SCC contradiction test
- assignment extraction

Target skill:

- move from statement text to one satisfiable assignment cleanly

## Stretch

- compare against [Graph Modeling](../graph-modeling/README.md)
- compare against [Topological Sort And SCC](../scc-toposort/README.md)
- use [The Door Problem](https://codeforces.com/problemset/problem/776/D) as the first external modeling stretch

Target skill:

- recognize when the hard part is clause modeling, not SCC code

## Retrieval Layer

- quickest in-repo reminder -> [Two-SAT hot sheet](../../../../notebook/two-sat-hot-sheet.md)
- exact starter -> [two-sat.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/two-sat.cpp)
- flagship in-lane rep -> [Giant Pizza](giantpizza.md)
- simpler directed-graph compare point -> [Course Schedule](../scc-toposort/courseschedule.md)
- SCC reopening path -> [Topological Sort And SCC](../../../../topics/graphs/scc-toposort/README.md)

## Repo Anchors And Compare Points

- topic page -> [2-SAT](../../../../topics/graphs/two-sat/README.md)
- SCC foundation -> [Topological Sort And SCC](../../../../topics/graphs/scc-toposort/README.md)
- modeling compare point -> [Graph Modeling](../../../../topics/graphs/graph-modeling/README.md)
- broader graph routing -> [Graphs ladder](../README.md)

The strongest in-repo loop here is:

1. learn the implication-graph model from the [2-SAT topic](../../../../topics/graphs/two-sat/README.md)
2. solve or revisit [Giant Pizza](giantpizza.md) as the clean assignment-extraction rep
3. compare the same problem family against the broader [Graph Modeling](../../../../topics/graphs/graph-modeling/README.md) and [SCC](../../../../topics/graphs/scc-toposort/README.md) pages
4. only then jump to harder external models like `Wedding` or `The Door Problem`

## Exit Criteria

You are ready to move on when:

- you can encode `a or b`, `a -> b`, `not both`, and `exactly one` without notes
- you can explain why `x` and `not x` in one SCC is impossible
- you can recover one assignment, not just answer `YES/NO`

## External Practice

- [CP-Algorithms - 2-SAT](https://cp-algorithms.com/graph/2SAT.html)
- [CSES - Giant Pizza](https://cses.fi/problemset/task/1684)
- [Codeforces - The Door Problem](https://codeforces.com/problemset/problem/776/D)

## Tutorial Link

- [2-SAT](../../../../topics/graphs/two-sat/README.md)
