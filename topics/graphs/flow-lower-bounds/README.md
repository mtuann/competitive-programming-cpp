# Flow With Lower Bounds

This lane starts when plain max flow stops being expressive enough.

The statement is no longer only:

- "how much can pass?"

It becomes:

- "every edge must carry **at least** some amount"
- "every edge may carry **at most** some amount"
- "find one feasible circulation / routing that respects both"

That is the canonical `lower / upper bounds on edges` family.

The main contest trick is not a brand-new flow engine. It is a reduction:

- subtract every lower bound first
- track the imbalance that creates at each vertex
- then ask one ordinary max-flow engine to saturate the correction edges

## At A Glance

Use this page when:

- each directed edge has a mandatory minimum flow `l(e)` and a maximum flow `r(e)`
- the statement asks for one feasible circulation, scheduling, or routing under both lower and upper bounds
- every vertex must still satisfy flow conservation after those lower bounds are honored
- you need to decide feasibility first, then reconstruct one witness flow

Strong contest signals:

- "`l_i <= f_i <= r_i` on every pipe / road / assignment edge"
- "find **any** feasible circulation"
- "mandatory minimum shipment / throughput on some edges"
- "close the network into a circulation, then check feasibility"

Strong anti-cues:

- only an upper capacity exists; then [Maximum Flow](../flow/README.md) is enough
- edge costs matter and the task is already cost-aware; then [Min-Cost Flow](../min-cost-flow/README.md) may be the real engine
- the graph changes online
- the problem is pure matching with no lower bounds

What success looks like after this page:

- you can derive the node-balance array without sign mistakes
- you know why one saturating max-flow check is enough for feasible circulation
- you can convert a lower-bounded `s-t` flow into circulation by adding `t -> s`
- you can reconstruct original edge flows as `lower + used(extra capacity)`

## Prerequisites

- [Maximum Flow](../flow/README.md)
- [Graph Modeling](../graph-modeling/README.md)

Helpful neighboring topics:

- [Min-Cost Flow](../min-cost-flow/README.md)
- [Matching](../matching/README.md) when the reduction is still bipartite and lower bounds do not really appear

## Quick Route

```text
1. Does every edge have only an upper capacity?
   if yes -> plain max flow

2. Does each edge also have a required minimum?
   if yes -> subtract lowers and build balances

3. Is this already a circulation?
   if yes -> super source / super sink reduction
   if no, but it is an s-t flow -> add t -> s and solve as circulation

4. Does cost matter too?
   if yes -> lower-bounds reduction may still be part of the model,
            but the engine may become min-cost flow instead
```

## Problem Model And Notation

Each directed edge `e = (u, v)` has:

- lower bound `l(e)`
- upper bound `r(e)`

and a valid flow must satisfy:

$$
l(e) \le f(e) \le r(e).
$$

For pure circulation, every vertex `v` must satisfy:

$$
\sum_{(u, v)} f(u, v) = \sum_{(v, w)} f(v, w).
$$

The main family split is:

### Feasible Circulation

There is no distinguished source or sink.

The whole question is:

- does some flow assignment satisfy every edge bound and every conservation equation?

### Lower-Bounded `s-t` Flow

There is still a source `s` and sink `t`, but some edges also have lower bounds.

The standard contest move is:

- add one extra edge `t -> s`
- then solve the resulting circulation instance

If you want at least `F` units from `s` to `t`, make that extra edge carry lower bound `F`.

## From Brute Force To The Right Reduction

### Brute Force

The naive instinct is:

- force every edge to carry its lower bound
- then try to locally repair the resulting imbalance

That is not reliable, because once lower bounds are placed, the remaining feasibility is global.

One vertex may now need extra inflow.
Another may need extra outflow.
The question is no longer "pick one path," but:

- can all imbalances be paired simultaneously through residual capacity?

### The Right Compression

For every edge `(u, v)` with bounds `[l, r]`:

1. pre-send `l` units through it
2. only the extra capacity `r - l` remains free

This changes vertex balances.

If we define:

- `balance[v] += l` for incoming lower bounds
- `balance[v] -= l` for outgoing lower bounds

then:

- `balance[v] > 0` means vertex `v` still needs that much extra inflow
- `balance[v] < 0` means vertex `v` must send that much extra outflow

So the whole problem becomes:

- can the residual capacities route enough extra flow to satisfy every positive balance?

That is exactly one max-flow feasibility test.

## Core Invariant And Why It Works

### 1. Lower Bounds Are A Fixed Baseline, Not Part Of The Search

After replacing each edge capacity by:

$$
r(e) - l(e),
$$

the search space only decides the **extra** flow above the mandatory baseline.

The original flow is always recovered as:

$$
f(e) = l(e) + g(e),
$$

where `g(e)` is the flow found in the reduced network.

### 2. Balance Array Encodes Exactly What The Lower Bounds Broke

Subtracting lower bounds does not destroy conservation randomly.

It creates a precise imbalance:

- outgoing lower bounds decrease local surplus
- incoming lower bounds increase local surplus

So if `balance[v] = +x`, vertex `v` needs `x` more incoming units in the reduced network.
If `balance[v] = -x`, it must send `x` more outgoing units.

This is why the super-node construction is correct:

- super source `SS -> v` with capacity `balance[v]` when `balance[v] > 0`
- `v -> TT` with capacity `-balance[v]` when `balance[v] < 0`

### 3. Saturating Every `SS` Edge Is The Whole Feasibility Condition

Let:

$$
D = \sum_{balance[v] > 0} balance[v].
$$

If the max flow from `SS` to `TT` equals `D`, then every positive-balance vertex received exactly the extra inflow it needed.

Because total positive balance equals total negative balance, that also means:

- every deficit and surplus is reconciled
- every original lower bound is still honored
- every vertex is now balanced in the original circulation again

If any `SS` edge remains unsaturated, some required imbalance could not be repaired, so the original instance is impossible.

This is the key invariant:

```text
feasible circulation  <=>  one saturating max flow in the auxiliary network
```

### 4. Why The `t -> s` Edge Fixes Lower-Bounded `s-t` Flow

Ordinary `s-t` flow violates circulation-style conservation:

- source sends more than it receives
- sink receives more than it sends

Adding one extra edge `t -> s` closes the loop.

Then any feasible `s-t` flow corresponds to one circulation in the augmented graph, and vice versa.

This is the standard way to reuse the same lower-bounds machinery for:

- feasible `s-t` flow
- required minimum value `F`
- some max-flow-with-lower-bounds extensions

## Complexity And Tradeoffs

The reduction adds:

- two extra vertices `SS`, `TT`
- up to one extra edge per original-vertex balance
- optionally one extra `t -> s` edge

So the auxiliary graph is still close to the original graph size.

In contests, the default engine is:

- `Dinic` on the reduced graph

Typical tradeoff table:

| Situation | Good first engine | Why | Main trap |
| --- | --- | --- | --- |
| feasible circulation with lower/upper bounds | max flow after reduction | only feasibility matters | wrong balance signs |
| lower-bounded `s-t` flow | same reduction plus `t -> s` | reuses one circulation engine | forgetting the closure edge |
| lower bounds plus costs | reduction may still be needed | lower bounds remain real | assuming plain max-flow starter solves costs |

## Variant Chooser

### Use Pure Feasible Circulation When

- every node must end balanced
- there is no distinguished source or sink
- you just need one witness assignment

Flagship in this repo:

- [Reactor Cooling](../../../practice/ladders/graphs/flow/reactorcooling.md)

### Use Lower-Bounded `s-t` Flow When

- the statement still has a source and sink
- some edges must carry at least a minimum amount

Standard reduction:

- add `t -> s`
- solve circulation with lower bounds

### Use Min-Cost Flow Instead When

- every shipped unit also has a meaningful objective cost
- feasibility is not enough; you must optimize

Compare point:

- [Min-Cost Flow](../min-cost-flow/README.md)

### Use Matching Instead When

- the statement is still fundamentally bipartite pairing
- lower bounds do not actually appear on edges

Compare point:

- [Matching](../matching/README.md)

## Worked Examples

### Example 1: Pure Feasible Circulation

Suppose we have:

- `1 -> 2` with `[1, 3]`
- `2 -> 3` with `[1, 4]`
- `3 -> 1` with `[1, 5]`

Subtract lower bounds:

- every edge now has residual capacity at least `0`
- every vertex gets one incoming lower and one outgoing lower

So every balance is still `0`.

That means:

- no super-source repair is even needed
- the all-lower assignment is already feasible

Recovered flow:

- `1, 1, 1`

This is the easiest reminder that sometimes lower bounds already balance themselves.

### Example 2: One Imbalanced Vertex Must Be Repaired

Edges:

- `1 -> 2` with `[2, 5]`
- `2 -> 3` with `[0, 4]`
- `3 -> 1` with `[0, 4]`

Lower-bound baseline sends `2` units only through `1 -> 2`.

Balances:

- node `1`: `-2`
- node `2`: `+2`
- node `3`: `0`

So the reduced graph must route two extra units from `2` back toward `1` using the remaining capacities.

If the residual capacities support that repair, the instance is feasible.
If not, it is impossible.

This is the main viewpoint to internalize:

- lower bounds create vertex imbalances
- the auxiliary max flow only exists to repair them

### Example 3: Lower-Bounded `s-t` Flow

Suppose the original task is:

- source `s = 1`
- sink `t = 4`
- some edges have lower bounds

This is not a circulation yet because:

- `s` is allowed to have net outflow
- `t` is allowed to have net inflow

Add:

- one edge `4 -> 1` with `[0, INF]`

Now the whole instance becomes a circulation problem.

If you instead require at least `F` units from `1` to `4`, use:

- `4 -> 1` with lower bound `F`

That is the cleanest way to translate a lower-bounded `s-t` flow request into the same starter pattern.

## Algorithm And Pseudocode

Repo starter template:

- [flow-lower-bounds.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/flow-lower-bounds.cpp)

### Feasible Circulation Skeleton

```text
for each edge (u, v, lower, upper):
    add residual-capacity edge (u, v, upper - lower)
    balance[u] -= lower
    balance[v] += lower

need = 0
for each vertex v:
    if balance[v] > 0:
        add edge SS -> v with capacity balance[v]
        need += balance[v]
    else if balance[v] < 0:
        add edge v -> TT with capacity -balance[v]

if maxflow(SS, TT) != need:
    impossible
else:
    original flow on edge e = lower[e] + residual-used-on-transformed-edge
```

### Lower-Bounded `s-t` Flow Skeleton

```text
add original lower/upper-bounded edges
add one extra edge (t, s, 0, INF)   // or (t, s, F, INF) for required minimum F
run feasible_circulation()
```

## Implementation Notes

### 1. The Sign Convention Must Stay Fixed

This repo uses:

- `balance[u] -= lower`
- `balance[v] += lower`

and then:

- positive balance means "needs more inflow"
- negative balance means "must send more outflow"

Do not flip one side and keep the same super-node wiring.

### 2. Reconstruct On Original Edge IDs

The answer you print is not the auxiliary-graph flow.

For each original edge:

$$
\text{answer} = lower + \text{flow on transformed edge}.
$$

That is why the starter stores one handle for each original edge.

### 3. `t -> s` Is A Modeling Edge, Not A Residual Reverse Edge

This is one of the easiest confusions in this lane.

- residual reverse edges come from the max-flow implementation automatically
- the extra `t -> s` edge is a real modeling edge you add by hand

Those are different objects.

### 4. Feasibility First, Optimization Later

The starter in this repo is for:

- feasible circulation / witness reconstruction

not for:

- min-cost lower-bounded flow
- general b-flow with costs

If costs matter, use this reduction only as the first modeling layer and then switch engines.

### 5. Integer Inputs Still Give Integer Witnesses

Because the reduced network uses ordinary integral capacities and the repo engine is max flow, the recovered witness stays integral.

That is why contest tasks in this family naturally want integer pipe / shipment outputs.

## Practice Archetypes

The strongest lower-bounds-shaped tasks are:

- feasible circulation in a pipe network
- routing where every edge must carry at least a minimum amount
- lower-bounded `s-t` transport after adding `t -> s`
- costed b-flow / supply-demand problems as a harder follow-up

The strongest smell is:

- "every edge has both a minimum and a maximum allowed flow"

Once that sentence appears, plain Dinic is usually only the **engine after reduction**, not the modeling idea itself.

## References And Repo Anchors

Research sweep refreshed on `2026-04-25`.

Course / reference:

- [CP-Algorithms: Flows with demands](https://cp-algorithms.com/graph/flow_with_demands.html)
- [USACO Guide: Flow with Lower Bounds](https://usaco.guide/adv/flow-lb)
- [Illinois CS473: More Network Flow Applications](https://courses.grainger.illinois.edu/cs473/sp2014/lec/19_lec.pdf)

Practice:

- [Codeforces acmsguru 194 - Reactor Cooling](https://codeforces.com/problemsets/acmsguru/problem/99999/194)

Repo anchors:

- practice ladder: [Flow ladder](../../../practice/ladders/graphs/flow/README.md)
- flagship note: [Reactor Cooling](../../../practice/ladders/graphs/flow/reactorcooling.md)
- starter template: [flow-lower-bounds.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/flow-lower-bounds.cpp)
- quick retrieval: [Flow With Lower Bounds hot sheet](../../../notebook/flow-lower-bounds-hot-sheet.md)
- compare point: [Maximum Flow](../flow/README.md)
- compare point: [Min-Cost Flow](../min-cost-flow/README.md)

## Related Topics

- [Maximum Flow](../flow/README.md)
- [Min-Cost Flow](../min-cost-flow/README.md)
- [Matching](../matching/README.md)
- [Graph Modeling](../graph-modeling/README.md)
