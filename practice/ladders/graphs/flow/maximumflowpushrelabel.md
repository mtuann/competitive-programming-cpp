# Maximum Flow

- Title: `Maximum Flow`
- Judge / source: `AOJ`
- Original URL: [https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A)
- Secondary topics: `Push-Relabel`, `Highest-label`, `Gap heuristic`
- Difficulty: `medium`
- Subtype: `Plain s-t max flow with a non-augmenting-path engine`
- Status: `solved`
- Solution file: [maximumflowpushrelabel.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/flow/maximumflowpushrelabel.cpp)

## Why Practice This

This is the cleanest repo rep for the moment when the model is already just ordinary directed max flow, but the algorithm you want to reopen is **not** Dinic.

Nothing in the statement asks for:

- lower bounds
- costs
- matching structure
- or repeated pairwise cuts

So the whole exercise is about learning a second reliable engine inside the same family: `preflow + heights + admissible pushes + gap heuristic`.

## Recognition Cue

Reach for this route when:

- the graph is still a plain directed `s-t` flow network
- you want a non-augmenting-path engine
- the interesting implementation ideas are excess, relabeling, and active vertices

The strongest smell is:

- "I already trust the max-flow model; I specifically want a push-relabel benchmark, not a new reduction."

## Problem-Specific Transformation

There is almost no extra modeling:

- vertices are already `0 ... V-1`
- source is `0`
- sink is `V - 1`
- each directed edge already carries its capacity

So the problem stays exactly one standard max-flow instance.

## Core Idea

Instead of searching for augmenting paths, push-relabel works with a **preflow**:

- source pushes out flow immediately
- internal vertices may temporarily hold positive excess
- only later do pushes and relabels move that excess toward the sink or trap it on the source side of the minimum cut

The implementation keeps:

- residual forward and reverse capacities
- a `height` label on each vertex
- an `excess` value for active internal vertices

An edge `u -> v` is admissible only when:

```text
height[u] = height[v] + 1
```

Then:

- `push` sends as much as possible on one admissible residual edge
- `relabel` raises a blocked vertex to one plus the minimum residual neighbor height
- the **gap heuristic** kills a whole layer once one height level becomes empty

For this judge size, highest-label push-relabel with gap is a clean sibling to Dinic and easy to trust once the invariants click.

## Complexity

- safe coarse bound: `O(V^2 E)` for this variant
- with `|V| <= 100`, `|E| <= 1000`, it is easily fast enough

## Pitfalls / Judge Notes

- This is a **directed** flow network; do not mirror capacities unless the statement says so.
- Preflow is allowed to violate conservation at internal nodes during the run.
- Reverse residual capacity must still be updated on every push.
- Source is `0`, sink is `V - 1`.
- `c_i` may be `0`; those edges can be added directly and simply never push flow.

## Reusable Pattern

- Topic page: [Maximum Flow](../../../../topics/graphs/flow/README.md)
- Practice ladder: [Flow ladder](README.md)
- Starter template: [push-relabel-max-flow.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/push-relabel-max-flow.cpp)
- Default engine compare point: [dinic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dinic.cpp)
- Notebook refresher: [Push-Relabel hot sheet](../../../../notebook/push-relabel-hot-sheet.md)
- Carry forward: the model is unchanged; only the engine worldview shifts from blocking flows to excess-driven preflow.
- This note adds: the cleanest repo rep for `plain max flow, but solved with push-relabel`.

## Solutions

- Code: [maximumflowpushrelabel.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/flow/maximumflowpushrelabel.cpp)
