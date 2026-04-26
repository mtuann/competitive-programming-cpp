# Global Min-Cut Hot Sheet

Use this sheet when the graph is **undirected**, there is **no designated source/sink**, and the statement wants the cheapest cut that disconnects the graph in any nontrivial way.

## Do Not Use When

- one explicit `s-t` cut or throughput question matters -> [Flow hot sheet](flow-hot-sheet.md)
- many pairwise min-cuts on the same graph matter -> [Gomory-Hu hot sheet](gomory-hu-hot-sheet.md)
- the graph is directed
- costs or lower bounds dominate more than the cut family itself

## Choose By Signal

- one undirected weighted graph, no source/sink, minimum disconnect cost -> `Randomized / Global Min-Cut`
- one designated `s-t` cut / throughput / cut certificate -> [Flow hot sheet](flow-hot-sheet.md)
- many pairwise undirected min-cuts compressed into one tree -> [Gomory-Hu hot sheet](gomory-hu-hot-sheet.md)
- you specifically want the randomized contraction worldview after the deterministic route is already clear -> reopen the topic page and jump to the `Karger / Karger-Stein` compare section

## Core Invariants

- each Stoer-Wagner phase grows a set by **maximum adjacency**
- the last vertex of the phase gives one minimum `s-t` cut in the current contracted graph
- after merging the last two phase vertices, any better global cut must still survive in the contracted graph
- the answer is the minimum phase cut seen across all contractions

## Main Traps

- guessing one pair `(s, t)` and pretending that is enough
- forgetting the graph must be undirected
- overwriting parallel edges instead of accumulating them
- assuming the witness side is unique

## Exact Starter Route

- exact starter -> [stoer-wagner-global-mincut.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/stoer-wagner-global-mincut.cpp)
- flagship in-lane rep -> [Minimum Cut](../practice/ladders/graphs/global-min-cut/globalmincut.md)
- compare points -> [Maximum Flow](../topics/graphs/flow/README.md), [Gomory-Hu Tree](../topics/graphs/gomory-hu/README.md)

## Reopen Paths

- full topic page -> [Randomized / Global Min-Cut](../topics/graphs/global-min-cut/README.md)
- broader graph-family chooser -> [Graph cheatsheet](graph-cheatsheet.md)
- reusable snippet map -> [Template Library](../template-library.md)
- retrieval router -> [Build Kit](../docs/build-kit.md)
