# Flow With Lower Bounds Hot Sheet

Use this page when every directed edge has both a required minimum and a maximum allowed flow, and you want the shortest route back to the `subtract lowers -> fix balances -> one saturating max flow` pattern.

## Do Not Use When

- edges only have upper capacities, so plain max flow is enough
- costs already dominate the objective and feasibility alone is not the whole task
- the statement is really matching or ordinary transport without lower bounds
- the graph changes online

## Choose By Signal

- every edge says `lower <= flow <= upper` and all vertices must balance -> [`flow-lower-bounds.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/flow-lower-bounds.cpp)
- there is an `s-t` flow with lower bounds -> add a real modeling edge `t -> s`, then reuse [`flow-lower-bounds.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/flow-lower-bounds.cpp)
- capacities plus costs matter too -> reopen [Min-Cost Flow](../topics/graphs/min-cost-flow/README.md) after the lower-bounds reduction
- only throughput matters and no lower bound exists -> go back to [Flow hot sheet](flow-hot-sheet.md)

## Core Invariants

- replace each edge capacity by `upper - lower`
- accumulate `balance[u] -= lower`, `balance[v] += lower`
- positive balance means "needs more inflow"; negative balance means "must send more outflow"
- add `SS -> v` for positive balance, `v -> TT` for negative balance
- feasible circulation exists iff every `SS` edge can be saturated
- recover original edge flow as `lower + flow_on_transformed_edge`

## Main Traps

- flipping the balance sign convention halfway through the reduction
- forgetting that `t -> s` is a real modeling edge, not a residual reverse edge
- printing transformed-edge flow instead of original `lower + extra`
- assuming the plain max-flow starter already knows about lower bounds

## Exact Starters In This Repo

- exact starter for feasible circulation / lower-bounded `s-t` reductions -> [`flow-lower-bounds.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/flow-lower-bounds.cpp)
- flagship in-repo rep -> [Reactor Cooling](../practice/ladders/graphs/flow/reactorcooling.md)
- compare plain throughput first -> [Flow hot sheet](flow-hot-sheet.md)
- compare cost-aware transport -> [Min-Cost Flow hot sheet](min-cost-flow-hot-sheet.md)

## Reopen Paths

- full reduction and `t -> s` reasoning -> [Flow With Lower Bounds](../topics/graphs/flow-lower-bounds/README.md)
- if the statement still only smells like max flow -> [Maximum Flow](../topics/graphs/flow/README.md)
- if costs are present too -> [Min-Cost Flow](../topics/graphs/min-cost-flow/README.md)
- practice lane -> [Flow ladder](../practice/ladders/graphs/flow/README.md)
