# Min-Cost Flow

Min-cost flow is what you use when sending flow is not enough:

- you must also optimize the total transportation cost
- or prove that among all flows of a required value, your chosen one is the cheapest

This page is still contest-facing, but it sits one layer above plain max flow. The core engine is no longer just “augment until no more flow fits.” The real invariant is:

- augment along a cheapest residual route
- and preserve a residual graph where that claim remains meaningful

## At A Glance

- Use this page when:
  - you must send exactly `k` units, or maximize flow and minimize cost among those maximum flows
  - each unit of flow pays a transportation, assignment, or routing cost
  - the statement sounds like `cheapest way to transport / assign / route under capacities`
  - plain max flow gets the amount right but loses the objective
- Prerequisites:
  - [Maximum Flow](../flow/README.md)
  - [Shortest Paths](../shortest-paths/README.md)
  - [Optimization And Duality](../../advanced/optimization-and-duality/README.md)
- Strongest cues:
  - the problem literally asks for `minimum total cost` under a flow or matching-style model
  - augmenting one more unit has a meaningful path cost
  - the editorial language says `potentials`, `reduced cost`, or `successive shortest augmenting path`
  - assignment / transportation / shipment modeling appears, but capacities still matter
- Strongest anti-cues:
  - only the amount of flow matters; then [Maximum Flow](../flow/README.md) is enough
  - the graph is tiny and brute-force DP over states is cleaner than building a residual network
  - the objective is really one shortest path, not repeated routing under capacities
  - you have negative costs but no clean plan for initial potentials or Bellman-Ford-style seeding
- Success after studying this page:
  - you can explain why reverse residual edges carry negative cost
  - you can explain what reduced costs are preserving
  - you know when the repo starter template is safe and when it is underpowered
  - you can distinguish `min-cost flow of value k` from `min-cost max-flow`

## Quick Route

```text
1. Do capacities matter?
   if no -> shortest paths / assignment / greedy may be enough

2. Does each routed unit pay a cost?
   if no -> plain max flow

3. Is the target "send exactly k" or "among max flows, choose cheapest"?
   if yes -> min-cost flow is a serious candidate

4. Are initial residual costs nonnegative?
   if yes on every initially usable residual edge -> Dijkstra + potentials starter is plausible
   if no -> seed initial potentials first, or use a more general shortest-path phase
```

## Problem Model And Notation

Take a directed network with:

- capacity `u(e) >= 0`
- per-unit cost `c(e)`
- source `s`
- sink `t`

For a flow `f`, the total cost is:

$$
\mathrm{cost}(f) = \sum_{e} c(e)\, f(e).
$$

Two common optimization targets appear in contests.

### Fixed-Value Min-Cost Flow

Find the cheapest flow of some required value `K`.

Contest phrasing:

- send exactly `K` units at minimum cost
- transport `K` items as cheaply as possible

### Min-Cost Max-Flow

First maximize the flow value, then among all maximum flows choose one of minimum total cost.

Contest phrasing:

- send as much as possible, but do it as cheaply as possible

These are related, but they are not the same question. Many contest tasks are fixed-value first, not full min-cost max-flow.

## From Plain Max Flow To The Right Residual View

Plain max flow says:

- augment any residual `s-t` path that still has capacity

That works because the only objective is value.

Once cost matters, not all residual augmentations are equal. A bad path can lock you into a more expensive flow even if the total amount sent is still feasible.

So the right question becomes:

- among all residual augmentations that increase the required flow, which one is cheapest right now?

This leads to the canonical contest algorithm:

- **successive shortest augmenting paths**

The residual graph must now track two things at once:

- remaining capacity
- how the objective changes if we push one more unit through an arc

That is why reverse arcs matter so much.

### Why Reverse Residual Arcs Need Negative Cost

If you send one unit through an edge of cost `c`, then undoing that unit should decrease the total cost by exactly `c`.

So the reverse residual edge must carry cost:

$$
-c.
$$

This is not an implementation trick. It is what makes the residual graph reflect the real “marginal change in objective” correctly.

## Core Invariant And Why It Works

There are three central invariants.

### Invariant 1: Optimality Is About Negative Residual Cycles

For fixed flow value, a feasible flow is optimal iff its residual graph has no negative-cost cycle.

Contest interpretation:

- if a negative residual cycle exists, you can circulate flow around it and strictly reduce total cost without changing the `s-t` flow value
- if no such cycle exists, there is no local residual improvement of that kind left

This is the right conceptual analogue of “no augmenting path” in plain max flow.

### Invariant 2: Reduced Costs Preserve Which Paths Are Cheapest

Given vertex potentials `\pi(v)`, define the reduced cost:

$$
c_{\pi}(u, v) = c(u, v) + \pi(u) - \pi(v).
$$

Three facts matter.

#### Fact A: Cycle Costs Do Not Change

On any directed cycle, the potential terms telescope:

$$
\sum ( \pi(u) - \pi(v) ) = 0.
$$

So the reduced cost of a cycle equals its original cost.

That means negative cycles stay negative and nonnegative cycles stay nonnegative.

#### Fact B: Path Costs Shift By An Endpoint Constant

For an `s-t` path `P`,

$$
c_{\pi}(P) = c(P) + \pi(s) - \pi(t).
$$

So among all `s-t` paths, the cheapest path in original costs is also the cheapest path in reduced costs.

This is why reweighting is safe.

#### Fact C: If Reduced Costs Are Nonnegative, Dijkstra Becomes Valid

If every residual edge satisfies:

$$
c_{\pi}(u, v) \ge 0,
$$

then shortest augmenting paths can be found with Dijkstra on the reweighted residual graph.

This is the whole point of potentials in contest implementations.

### Invariant 3: Potential Updates Keep Reduced Costs Nonnegative

After one shortest-path run in reduced costs, update:

$$
\pi'(v) = \pi(v) + d(v),
$$

for every vertex reached by that run, where `d(v)` is the reduced-cost distance from `s`.

Then for every residual edge `(u, v)` whose endpoints were both reached:

$$
c_{\pi'}(u, v) = c_{\pi}(u, v) + d(u) - d(v) \ge 0.
$$

Why?

- shortest-path distances satisfy `d(v) <= d(u) + c_{\pi}(u, v)`
- rearranging gives `c_{\pi}(u, v) + d(u) - d(v) >= 0`

For vertices not reached in the Dijkstra phase, the potential is left unchanged, so already-safe reduced costs stay safe there.

One more post-augmentation fact matters:

- if `(u, v)` lies on the chosen shortest path, then `d(v) = d(u) + c_{\pi}(u, v)`
- so that edge gets new reduced cost exactly `0`
- therefore the newly activated reverse edge also gets reduced cost exactly `0`

That is why augmentation does not suddenly create a negative reduced-cost reverse edge on the chosen path.

That is the invariant the code is really maintaining.

## Complexity And Tradeoffs

The standard contest engine is:

- successive shortest augmenting paths
- Dijkstra on reduced costs
- one augmentation per shortest residual route

Tradeoffs:

| Pattern | What you gain | Main risk |
| --- | --- | --- |
| Dijkstra + potentials | a clean and practical default for many contest instances | assuming it works before you have nonnegative reduced costs |
| fixed-value min-cost flow | exact control over shipped amount | forgetting that infeasibility must return `flow < need` cleanly |
| min-cost max-flow | strongest modeling power | heavier than most core flow tasks and easy to overuse |
| residual reconstruction on original edges | judge-ready transportation plan | reading the answer off residual edges instead of original arcs |

In this repo, the starter template is intentionally the practical contest version:

- Dijkstra + potentials
- no Bellman-Ford seeding built in
- therefore it assumes every initially usable residual edge already has nonnegative cost

Operational reading:

- the negative reverse edges do **not** break this at the start, because they begin with zero residual capacity
- what actually matters is that every forward edge with positive initial residual capacity has nonnegative cost

That is an important boundary, not a footnote.

## Variant Chooser

| Situation | Best first lens | Why it fits | Where it fails |
| --- | --- | --- | --- |
| only throughput matters | plain max flow | cost is irrelevant | weak if every unit has a meaningful objective cost |
| one unit or one path is all you need | shortest path | no repeated capacity-limited routing is needed | weak if multiple units interact through capacities |
| send exactly `K` units as cheaply as possible | fixed-value min-cost flow | the required value is explicit | weak if the graph cannot support all `K` units |
| send as much as possible, but cheapest among all max flows | min-cost max-flow | value and cost both matter at optimum | weak if the statement really fixed the amount already |
| costs may be negative initially | Bellman-Ford/SPFA seeding + potentials, or another more general MCF engine | you need valid initial reduced costs | weak if you assume the repo starter handles this automatically |

## Worked Examples

### Example 1: Why The Shortest Residual Path Is The Right Augmentation

Suppose you must send exactly `2` units from `s` to `t`.

Two residual `s-t` paths are currently available:

- one has path cost `3`
- one has path cost `9`

If you send one unit on the expensive path first when the cheap path was available, you already overpay by `6` unless the residual structure later compensates through reverse adjustments.

The residual graph does support correction through reverse negative-cost edges, but the whole successive-shortest-path idea is:

- choose the cheapest residual augmentation at each stage
- so you never create avoidable cost debt in the first place

This is the direct contest intuition for the algorithm.

### Example 2: Reduced Costs Make Dijkstra Honest Again

Suppose all residual reduced costs are nonnegative under current potentials.

If Dijkstra finds a shortest reduced-cost path `P`, then for any other `s-t` path `Q`:

$$
c_{\pi}(P) \le c_{\pi}(Q).
$$

But:

$$
c_{\pi}(P) = c(P) + \pi(s) - \pi(t),
\qquad
c_{\pi}(Q) = c(Q) + \pi(s) - \pi(t).
$$

So:

$$
c(P) \le c(Q).
$$

This is the whole safety proof in one line:

- reduced costs make Dijkstra legal
- the endpoint shift preserves which `s-t` path is actually cheapest

### Example 3: `MINCOST` Is Fixed-Value Min-Cost Flow Plus Reconstruction

Use [MINCOST](../../../practice/ladders/graphs/flow/mincost.md).

The internal core is standard:

- build the residual network
- run successive shortest augmenting paths until `K` units are sent or impossible

The extra work is judge-facing:

- roads are given as undirected transport channels
- after the optimal flow is found, recover the net direction on each original road

This is a good contest reminder:

- the hard part is often not only the engine
- it is the layer that maps the engine’s residual data back to the statement’s original objects

### Example 4: Tiny Statement-To-Network Modeling Trace

Suppose:

- worker `i` can do at most one job
- job `j` needs exactly one worker
- assigning worker `i` to job `j` costs `a_{ij}`

Build:

- `s -> worker_i` with capacity `1`, cost `0`
- `worker_i -> job_j` with capacity `1`, cost `a_{ij}` when that assignment is allowed
- `job_j -> t` with capacity `1`, cost `0`

Now:

- one unit of flow means one assignment
- sending `m` units means completing `m` jobs
- minimizing total flow cost means minimizing total assignment cost

This is the cleanest contest modeling smell:

- bipartite assignment under capacities, with explicit per-match cost

### Example 5: Potentials Are A Dual-Flavored Certificate, Not Just A Hack

As noted in [Optimization And Duality](../../advanced/optimization-and-duality/README.md), feasible potentials behave like a local certificate:

- they keep every residual reduced cost nonnegative
- that locally certifies that Dijkstra is valid on the current reweighted graph

This does **not** mean you need to derive the full LP dual every contest time.

It does mean:

- if you treat potentials as “magic numbers that somehow fix Dijkstra,” the page is not finished yet

The right contest understanding is:

- potentials are carrying the certificate that reweighting is safe

## Algorithm And Pseudocode

This is the standard fixed-value pattern.

```text
MIN_COST_FLOW(s, t, need):
    flow = 0
    cost = 0
    initialize residual graph with reverse edges of cost -c
    initialize potentials pi so reduced costs are nonnegative

    while flow < need:
        run shortest path from s to t on reduced costs
        if t is unreachable:
            break

        update potentials using the shortest-path distances

        add = bottleneck residual capacity on the chosen path
        add = min(add, need - flow)

        augment add units on that path
        flow += add
        cost += add * original_path_cost

    return (flow, cost)
```

The two contest branches afterward are:

- if `flow < need`, the fixed-value problem is infeasible
- otherwise, the accumulated `cost` is the optimum cost for that shipped value

How this maps onto the repo starter:

- for fixed-value min-cost flow, pass the exact required `need`
- for min-cost max-flow, either wrap the augmentations yourself or pass a safe upper bound on the maximum possible flow and accept the returned `(flow, cost)` when the routine stops early because no more augmenting path exists

## Implementation Notes

### 1. Reverse Costs Must Be Exact Negatives

If the forward edge has cost `c`, the reverse residual edge must have cost `-c`.

Anything else breaks the residual objective.

### 2. Keep Original Costs Separate In Your Mental Model

Dijkstra runs on:

- reduced costs

but the objective you report is:

- original total cost

The repo starter gets this right by accumulating `add * e.cost` on the actual chosen residual edges, while potentials are only for shortest-path legality.

### 3. `long long` Is The Default

Use `long long` for:

- capacities when they can stack
- distances
- total cost

Overflow here is easy and extremely expensive.

### 4. The Repo Starter Assumes Initial Nonnegative Residual Costs

The starter template:

- does **not** run Bellman-Ford or SPFA to seed initial potentials
- so it is safe only when every initially usable residual edge has nonnegative cost

If the statement can produce negative-cost residual arcs initially, you need:

- initial shortest-path potentials from Bellman-Ford / SPFA
- or a more general min-cost flow engine

### 5. Fixed-Value And Min-Cost Max-Flow Are Different Stop Conditions

For fixed-value flow:

- stop once `need` units are sent

For min-cost max-flow:

- continue while any augmenting path exists

Confusing these is a common modeling bug.

### 6. Reconstruction Belongs To The Original Graph

Residual edges are an optimization object.

If the problem asks for:

- assignments
- shipments
- directed use of original undirected roads

then reconstruct on the original edges or original bipartite pairs, not by dumping residual arcs directly.

`MINCOST` is the internal reminder for this.

Generic extraction rule:

- keep a handle to the original forward arc you care about
- after the algorithm finishes, read used flow as

$$
\text{original capacity} - \text{current residual forward capacity}
$$

on that original forward arc

## Practice Archetypes

- exact shipment or transportation with capacities and per-unit costs
- assignment-style models where both feasibility and total price matter
- fixed-value routing under capacities
- flow tasks whose real entry point is `cheapest feasible transport`, not `maximum throughput`
- problems where the code is standard but output reconstruction is statement-specific

## References And Repo Anchors

### Primary / Course

- MIT 6.854 Notes, [Min-Cost Flow](https://courses.csail.mit.edu/6.854/20/Notes/n09-mincostflow.html)
- MIT 6.854 Notes, [Prices and Reduced Costs](https://courses.csail.mit.edu/6.854/16/Notes/n10-mincostflow.html)
- CMU 15-451, [Min-Cost Flow lecture notes](https://www.cs.cmu.edu/~15451-f24/lectures/lecture13-min-cost-flow.pdf)
- Princeton COS 423, [Min-Cost Flows](https://www.cs.princeton.edu/courses/archive/spr11/cos423/Lectures/MinCostFlows.pdf)

### Reference

- [CP-Algorithms: Min-Cost Flow](https://cp-algorithms.com/graph/min_cost_flow.html)

### Repo Anchors

- nearby topic: [Maximum Flow](../flow/README.md)
- nearby topic: [Shortest Paths](../shortest-paths/README.md)
- duality bridge: [Optimization And Duality](../../advanced/optimization-and-duality/README.md)
- practice note: [MINCOST](../../../practice/ladders/graphs/flow/mincost.md)
- starter template: [min-cost-flow.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/min-cost-flow.cpp)
- notebook refresher: [Graph cheatsheet](../../../notebook/graph-cheatsheet.md)

## Related Topics

- [Maximum Flow](../flow/README.md)
- [Shortest Paths](../shortest-paths/README.md)
- [Matching](../matching/README.md)
- [Optimization And Duality](../../advanced/optimization-and-duality/README.md)
