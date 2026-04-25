# Dynamic Connectivity

- Title: `Dynamic Connectivity`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/2133](https://cses.fi/problemset/task/2133)
- Secondary topics: `DSU rollback`, `Segment tree over time`, `Offline dynamic connectivity`
- Difficulty: `hard`
- Subtype: `Count components after each add/remove edge event`
- Status: `solved`
- Solution file: [dynamicconnectivity.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/dsu-rollback/dynamicconnectivity.cpp)

## Why Practice This

This is the cleanest in-repo anchor for the full rollback-DSU lane.

The statement does not hide the real issue:

- edges are created
- edges are removed
- after every event, you need the current number of connected components

So the whole lesson is exactly:

- why plain DSU is no longer enough
- how to convert edge lifetimes into time intervals
- how rollback DSU plus a segment tree over time restores a clean near-logarithmic solution

## Recognition Cue

Reach for `DSU Rollback / Offline Dynamic Connectivity` when:

- the graph question is still about connectivity or component counts
- edges can both appear and disappear
- all events are given in advance
- the online dynamic-connectivity version feels much stronger than the intended difficulty

The strong smell here is:

- "report the number of components after every event" under add/remove edge operations

That is the canonical rollback-over-time setup.

## Problem-Specific Transformation

Index graph states by:

$$
t = 0, 1, \dots, k
$$

where state `t` means:

- the graph after the first `t` events

Then every undirected edge has one active lifetime interval:

$$
[l, r)
$$

meaning it is present in exactly those graph states.

For this problem:

- every initial edge starts at `0`
- an edge created by event `i` starts at `i`
- an edge removed by event `i` ends at `i`
- any edge still alive at the end ends at `k + 1`

Now the statement becomes:

- add each edge interval to a segment tree over time
- DFS that tree
- use rollback DSU to maintain the component structure for the current recursion segment
- answer `components` at each leaf state

## Core Idea

The hard part is not connectivity itself.

It is the deletions.

So instead of maintaining the graph online, do this offline:

1. extract each edge's active interval `[l, r)`
2. place that interval on `O(log k)` nodes of a segment tree over time
3. DFS the time tree
4. at each node, unite all edges active for that whole time segment
5. rollback those unions when leaving the node

At a leaf `t`, the DSU represents exactly the graph after `t` events, so:

```text
answer[t] = dsu.components
```

The rollback DSU uses:

- union by size
- no ordinary path compression
- one stack of reversible changes

That is the safe contest contract for this lane.

## Complexity

- lifetime extraction: `O((m + k) log(m + k))` or similar map cost
- each edge interval is placed on `O(log k)` time-tree nodes
- each rollback-DSU `find / unite` in the safe starter is `O(log n)`

So the total is:

$$
O((m + k)\log k \log n)
$$

which is fast enough for the CSES limits.

## Pitfalls / Judge Notes

- The output has `k + 1` answers because it includes the initial graph before any event.
- Model graph states, not just events. This is what makes the interval endpoints clean.
- Normalize every undirected edge as `(min(u, v), max(u, v))`.
- Do not use ordinary path compression in the rollback DSU.
- Snapshot once per DFS node, not once per individual union.

## Reusable Pattern

- Topic page: [DSU Rollback / Offline Dynamic Connectivity](../../../../topics/data-structures/dsu-rollback/README.md)
- Practice ladder: [DSU Rollback / Offline Dynamic Connectivity ladder](README.md)
- Starter template: [dsu-rollback-dynamic-connectivity.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/dsu-rollback-dynamic-connectivity.cpp)
- Notebook refresher: [DSU Rollback hot sheet](../../../../notebook/dsu-rollback-hot-sheet.md)
- Compare points: [DSU](../../../../topics/data-structures/dsu/README.md), [Offline Tricks](../../../../topics/data-structures/offline-tricks/README.md), [Distinct Values Queries](../offline-tricks/distinctvaluesqueries.md)
- This note adds: the exact `segment tree over time + rollback DSU` route for component counts under add/remove events.

## Solutions

- Code: [dynamicconnectivity.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/dsu-rollback/dynamicconnectivity.cpp)
