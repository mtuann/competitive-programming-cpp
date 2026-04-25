# Reactor Cooling

- Title: `Reactor Cooling`
- Judge / source: `Codeforces acmsguru`
- Original URL: [https://codeforces.com/problemsets/acmsguru/problem/99999/194](https://codeforces.com/problemsets/acmsguru/problem/99999/194)
- Secondary topics: `Feasible circulation`, `Lower bounds`, `Flow reconstruction`
- Difficulty: `hard`
- Subtype: `Lower/upper bounded circulation with witness output`
- Status: `solved`
- Solution file: [reactorcooling.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/flow/reactorcooling.cpp)

## Why Practice This

This is the cleanest first in-repo flagship for `Flow With Lower Bounds`.

The statement is almost pure theory-to-code transfer:

- every pipe is directed
- every pipe has a lower bound and an upper bound
- every node must end balanced
- you must print one feasible assignment in input order

So the hard part is not another max-flow theorem. It is recognizing the exact reduction:

- subtract lowers
- build balances
- add super source / super sink
- check for one saturating auxiliary max flow

## Recognition Cue

Reach for the lower-bounds lane when:

- each edge says `l <= f <= r`
- every node must conserve flow
- the statement asks for any witness, not an optimum

The strongest smell here is:

- "every pipe must carry at least `l_ij` and at most `c_ij`, and every node must balance"

That is exactly the `feasible circulation with lower bounds` problem.

## Problem-Specific Transformation

For each pipe `u -> v` with lower/upper bounds `[l, c]`:

1. pre-send the mandatory `l`
2. replace the free capacity by `c - l`
3. update balances:
   - `balance[u] -= l`
   - `balance[v] += l`

Then create the auxiliary network:

- `SS -> v` with capacity `balance[v]` if `balance[v] > 0`
- `v -> TT` with capacity `-balance[v]` if `balance[v] < 0`

Now the original instance is feasible iff the max flow from `SS` to `TT` saturates all edges leaving `SS`.

Finally, reconstruct each original pipe flow as:

$$
\text{answer}_k = l_k + \text{extra}_k.
$$

## Core Idea

The lower bounds are treated as fixed baseline flow, not part of the search.

So the search only decides the extra flow above that baseline.

If the baseline lower bounds leave some vertex short of inflow, the auxiliary max flow repairs that shortage.
If all shortages can be repaired simultaneously, the circulation exists.

This gives the exact contest pattern:

1. build residual capacities `upper - lower`
2. compute the balance array
3. attach `SS` and `TT`
4. run Dinic once
5. recover original edge flows in input order

## Complexity

- one Dinic run on `n + 2` vertices and `m + O(n)` edges

That is easily fast enough for the judge limits here.

## Pitfalls / Judge Notes

- The sign convention matters: use one consistent `balance[u] -= lower`, `balance[v] += lower`.
- The printed answer is on the **original pipes**, not on the auxiliary edges.
- Reconstruct as `lower + extra`, not just the transformed-edge flow.
- This task is already a circulation, so no extra `t -> s` edge is needed.

## Reusable Pattern

- Topic page: [Flow With Lower Bounds](../../../../topics/graphs/flow-lower-bounds/README.md)
- Practice ladder: [Flow ladder](README.md)
- Starter template: [flow-lower-bounds.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/flow-lower-bounds.cpp)
- Notebook refresher: [Flow With Lower Bounds hot sheet](../../../../notebook/flow-lower-bounds-hot-sheet.md)
- Compare points:
  - [Maximum Flow](../../../../topics/graphs/flow/README.md)
  - [Min-Cost Flow](../../../../topics/graphs/min-cost-flow/README.md)
- This note adds: the pure feasible-circulation flagship where the whole answer is one witness flow vector.

## Solutions

- Code: [reactorcooling.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/flow/reactorcooling.cpp)
