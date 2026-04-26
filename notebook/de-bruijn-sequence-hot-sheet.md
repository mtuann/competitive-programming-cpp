# De Bruijn Sequence Hot Sheet

Use this sheet when the statement is really about **covering every length-`n` window exactly once** and the clean route is to hide the string inside an Eulerian cycle.

## Do Not Use When

- the graph is already explicit and the only question is Eulerian feasibility -> [Eulerian hot sheet](eulerian-hot-sheet.md)
- the task is matching or searching inside a string, not constructing one
- labels, weights, or path values dominate more than overlap structure
- the answer object is not one overlap-driven sequence

## Choose By Signal

- every binary length-`n` block must appear once -> `De Bruijn Sequence`
- every next block overlaps the previous one by `n - 1` symbols -> same lane, model overlap states first
- explicit graph, use every edge once -> [Eulerian hot sheet](eulerian-hot-sheet.md)
- graph model still unclear -> [Graph cheatsheet](graph-cheatsheet.md)

## Core Invariants

- vertices are `(n - 1)`-symbol overlap states
- each length-`n` block is one directed edge
- each traversed edge appends exactly one new symbol to the answer
- binary order-`n` graph has `2^(n - 1)` states and `2^n` edges
- final linear answer is `start_state + edge_labels`, so its length is `2^n + n - 1`

## Main Traps

- modeling vertices as full length-`n` blocks instead of overlap states
- forgetting the special `n = 1` case
- forgetting to prefix the start state's `n - 1` symbols when linearizing the cycle
- checking only the graph walk and not the final string length
- reopening full string algorithms when the real bottleneck is graph modeling

## Exact Starter Route

- exact starter -> [de-bruijn-sequence-binary.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/de-bruijn-sequence-binary.cpp)
- flagship in-lane rep -> [De Bruijn Sequence](../practice/ladders/graphs/de-bruijn-sequence/debruijnsequence.md)
- graph-family compare point -> [Eulerian hot sheet](eulerian-hot-sheet.md)
- modeling compare point -> [Graph Modeling](../topics/graphs/graph-modeling/README.md)

## Reopen Paths

- full topic page -> [De Bruijn Sequence](../topics/graphs/de-bruijn-sequence/README.md)
- all-edge traversal details -> [Eulerian Path / Cycle](../topics/graphs/eulerian-path-cycle/README.md)
- broader graph chooser -> [Graph cheatsheet](graph-cheatsheet.md)
