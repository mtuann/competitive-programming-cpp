# De Bruijn Sequence

This lane is for the moment the statement is not really about:

- shortest paths
- substring matching
- one explicit graph given in the input

but about one modeling question:

- how do I build one short sequence so every length-`n` block appears exactly once?

The repo's exact first route for this family is:

- starter -> [de-bruijn-sequence-binary.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/de-bruijn-sequence-binary.cpp)
- flagship note -> [De Bruijn Sequence](../../../practice/ladders/graphs/de-bruijn-sequence/debruijnsequence.md)
- compare point -> [Eulerian Path / Cycle](../eulerian-path-cycle/README.md)
- stretch compare point -> `k`-ary alphabets or overlap-graph reconstruction with a less regular state set

This lane intentionally teaches the **binary order-`n` route first**:

- vertices are `(n - 1)`-bit states
- each length-`n` bitstring becomes one directed edge
- one Eulerian cycle encodes the whole answer

It does not start from the fully general overlap-graph setting or from arbitrary alphabets.

## At A Glance

- **Use when:** the answer is one binary string and every length-`n` bitstring must appear exactly once as a substring, or a near-identical overlap-modeling task hides that same structure
- **Core worldview:** model each `(n - 1)`-bit suffix state as a vertex, each length-`n` bitstring as one edge, then let one Eulerian cycle list every required block exactly once
- **Main tools:** implicit graph modeling, bitmask states, iterative or recursive `Hierholzer`, and linearization by prefixing the start state's bits
- **Typical complexity:** `O(2^n)` for the binary first route
- **Main trap:** forgetting that the Eulerian cycle is cyclic, while the judge usually wants a linear string of length `2^n + n - 1`

Strong contest signals:

- "every binary string of length `n` must appear exactly once"
- "construct the shortest binary string containing all `n`-bit patterns"
- "adjacent windows overlap by `n - 1`"
- "the graph is not given, but a state graph is hiding in the windows"

Strong anti-cues:

- the graph is already explicit and the whole problem is just Eulerian feasibility -> [Eulerian Path / Cycle](../eulerian-path-cycle/README.md)
- the task is ordinary substring search rather than sequence construction
- labels, costs, or path values dominate instead of overlap structure
- the alphabet or overlap constraints are irregular enough that the binary implicit graph no longer fits directly

## Prerequisites

- [Graph Modeling](../graph-modeling/README.md)
- [Eulerian Path / Cycle](../eulerian-path-cycle/README.md)

Helpful compare points:

- [Eulerian Path / Cycle](../eulerian-path-cycle/README.md): use this first when the graph is already explicit and the hard part is just feasibility plus `Hierholzer`
- [Strings overview](../../strings/README.md): use that when matching, suffix structure, or automata dominate more than construction

## Problem Model And Notation

For binary order `n`:

- every binary string of length `n` is one required block
- every binary string of length `n - 1` is one state

Build a directed graph where:

- vertex `u` is one `(n - 1)`-bit state
- an edge labeled `b in {0, 1}` goes from state `u` to the state formed by dropping the leftmost bit and appending `b`

Equivalently:

- each edge is one length-`n` bitstring
- its tail is the prefix of length `n - 1`
- its head is the suffix of length `n - 1`

Then:

- every state has outdegree `2`
- every state has indegree `2`

so the graph is Eulerian.

If an Eulerian cycle lists edge labels in order, then each length-`n` block appears exactly once.

## From Brute Force To The Right Model

### What Brute Force Tries

The naive instinct is:

- grow the answer bit by bit
- track which length-`n` windows already appeared
- backtrack when you repeat or miss a block

That explodes because the sequence choices branch too much.

### The Structural Shift

Do not think in terms of the whole output string first.

Think in terms of:

- states = the last `n - 1` bits
- transitions = append one bit

Now the problem becomes:

```text
use every transition exactly once
```

That is an Eulerian-cycle problem on an implicit graph.

## Core Invariants And Why They Matter

### 1. One Edge Represents One Required Window

Each length-`n` bitstring must appear exactly once.

So each such bitstring should be represented by:

- exactly one directed edge

That makes the problem "cover all edges once", not "cover all vertices once".

### 2. Vertices Are Overlap States Of Length `n - 1`

Two consecutive windows in the final answer overlap by `n - 1` bits.

That overlap is exactly what vertices store.

So the transition structure becomes local and deterministic.

### 3. The Graph Is Balanced

For each `(n - 1)`-bit state:

- append `0`
- append `1`

so:

- outdegree = `2`
- indegree = `2`

This is why the binary state graph is Eulerian without any extra repair step.

### 4. The Eulerian Cycle Is Cyclic, The Judge Output Is Usually Linear

The cycle itself is circular.

To print one linear witness, the standard route is:

1. pick a start state, usually all zeros
2. output that state's `n - 1` bits first
3. then append the edge labels of the Eulerian cycle in order

That gives length:

$$
2^n + n - 1
$$

which is the expected linear witness size.

### 5. Edge Labels Are The New Bits

When traversing one edge:

- the label of that edge is exactly the next bit appended to the output

This is the clean invariant that turns one Eulerian cycle back into one string.

## Complexity And Tradeoffs

For the binary first route:

- number of vertices: `2^(n - 1)`
- number of edges: `2^n`
- traversal: `O(2^n)`
- memory: `O(2^n)`

Rule of thumb:

- explicit graph already given -> reopen [Eulerian Path / Cycle](../eulerian-path-cycle/README.md)
- binary all-windows construction -> this lane
- larger alphabet or irregular overlap rules -> same modeling idea, but the graph representation may need more care

## Worked Examples

### Example 1: CSES De Bruijn Sequence

The repo's flagship note:

- [De Bruijn Sequence](../../../practice/ladders/graphs/de-bruijn-sequence/debruijnsequence.md)

This is the cleanest first benchmark because:

- the alphabet is binary
- the target is exactly "every length-`n` bitstring once"
- the graph is completely implicit

So the whole route is:

1. build `(n - 1)`-bit states
2. run one Eulerian cycle
3. linearize it into one output string

### Example 2: Same Family, Less Regular Modeling

Sometimes the statement is still about overlap windows, but:

- the alphabet is larger than binary
- not every possible block exists
- the edges come from given fragments rather than all bitstrings

Then the same worldview still applies:

- windows become edges
- overlaps become vertices

but you are no longer in the exact first-route starter.

## Practice Archetypes

- binary universal circular / linear string -> [De Bruijn Sequence](../../../practice/ladders/graphs/de-bruijn-sequence/debruijnsequence.md)
- overlap graph reconstruction where each block should be used once -> same family, but reopen [Graph Modeling](../graph-modeling/README.md) first
- explicit all-edge traversal with no hidden string model -> [Eulerian Path / Cycle](../eulerian-path-cycle/README.md)

## References

- [CSES - De Bruijn Sequence](https://cses.fi/problemset/task/1692)
- [Competitive Programmer's Handbook PDF](https://www.cses.fi/book/book.pdf)
- [CP-Algorithms: Finding the Eulerian path in O(M)](https://cp-algorithms.com/graph/euler_path.html)

## Repo Anchors

- [De Bruijn Sequence ladder](../../../practice/ladders/graphs/de-bruijn-sequence/README.md)
- [De Bruijn Sequence hot sheet](../../../notebook/de-bruijn-sequence-hot-sheet.md)
- [Exact starter template](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/de-bruijn-sequence-binary.cpp)
- [De Bruijn Sequence note](../../../practice/ladders/graphs/de-bruijn-sequence/debruijnsequence.md)
- Compare points:
  - [Eulerian Path / Cycle](../eulerian-path-cycle/README.md)
  - [Graph Modeling](../graph-modeling/README.md)
