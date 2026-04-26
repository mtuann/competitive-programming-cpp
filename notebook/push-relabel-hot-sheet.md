# Push-Relabel Hot Sheet

Use this page when the model is still plain static `s-t` maximum flow, but you want a non-augmenting-path engine instead of reopening Dinic first.

## Do Not Use When

- lower / upper edge bounds change the model first -> [Flow With Lower Bounds hot sheet](flow-lower-bounds-hot-sheet.md)
- edge costs matter -> [Min-Cost Flow hot sheet](min-cost-flow-hot-sheet.md)
- there is no designated `s-t` pair -> [Global Min-Cut hot sheet](global-min-cut-hot-sheet.md)
- the task is really matching or assignment, not generic transport -> [Matching hot sheet](matching-hot-sheet.md)

## Choose By Signal

- plain max flow / min cut, moderate network, default augmenting-path route -> [`dinic.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dinic.cpp)
- plain max flow / min cut, but you want a height/excess preflow engine or a denser hard-benchmark fallback -> [`push-relabel-max-flow.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/push-relabel-max-flow.cpp)
- one cut certificate after the flow finishes -> solve max flow first, then reopen [Flow hot sheet](flow-hot-sheet.md)

## Core Invariants

- a **preflow** may violate conservation at internal nodes; only `s` and `t` are exempt from the final conservation story
- an admissible push uses a residual edge with `height[u] = height[v] + 1`
- relabel only happens when no admissible residual edge remains
- if one height layer disappears, the gap heuristic can kill every higher active layer on the source side

## Main Traps

- expecting internal conservation to hold during intermediate states
- forgetting that reverse residual capacity must still be updated on every push
- pushing source or sink back into the active structure
- mixing this engine with lower-bounded or costed flow models as if the same starter already handled them

## Exact Starter Route

- default engine sibling -> [`dinic.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dinic.cpp)
- preflow / height-label sibling -> [`push-relabel-max-flow.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/push-relabel-max-flow.cpp)
- in-family benchmark rep -> [Maximum Flow (Push-Relabel route)](../practice/ladders/graphs/flow/maximumflowpushrelabel.md)

## Reopen Paths

- family chooser first -> [Flow hot sheet](flow-hot-sheet.md)
- full topic boundary and modeling -> [Maximum Flow](../topics/graphs/flow/README.md)
- broader graph-family chooser -> [Graph cheatsheet](graph-cheatsheet.md)
- snippet map -> [Template Library](../template-library.md)
