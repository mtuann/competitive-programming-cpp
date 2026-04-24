# Graph Modeling

Many contest problems do not announce themselves as graph problems.

They talk about:

- cities
- rooms
- transformations
- states
- prerequisites
- assignments
- legal moves
- or things that can influence each other

The real turning point is often not the algorithm. It is the moment you decide:

> What exactly is a vertex, and what exactly is an edge?

That is why graph modeling is not "preprocessing before the real work." Very often, graph modeling **is** the real work.

## At A Glance

Reach for graph modeling when:

- objects are connected, dependent, reachable, or transformable
- the same move or relation appears repeatedly
- the statement sounds local, but the answer is global
- once the structure is named correctly, a standard graph family becomes obvious

Strong contest triggers:

- "can move from A to B"
- "depends on"
- "reachable"
- "connected"
- "minimum steps"
- "choose compatible pairs"
- "remove a small blocking set"

Strong anti-cues:

- the whole problem is already just array / prefix / sorting logic
- there is no reusable notion of state or legal move
- you are building a graph only because the input looks like pairs, not because the graph actually preserves the problem

What success looks like after studying this page:

- you can say what one vertex means in one sentence
- you can justify whether edges are directed, undirected, weighted, or implicit
- you can choose between object graph, grid graph, state graph, dependency DAG, or bipartite model
- once the model is fixed, the algorithm family becomes much clearer
- you stop carrying story details that the algorithm never uses

## Prerequisites

- [Foundations](../../foundations/README.md)
- [BFS And DFS](../bfs-dfs/README.md)

Helpful neighboring topics:

- [Shortest Paths](../shortest-paths/README.md)
- [Matching](../matching/README.md)
- [Maximum Flow](../flow/README.md)

## Problem Model And Notation

At graph-modeling time, you should be able to answer these questions explicitly:

1. what is a vertex?
2. what does an edge mean?
3. is the edge directed or undirected?
4. is the edge weighted or unweighted?
5. do I need to store the graph explicitly, or can I generate neighbors on demand?

A graph model is valid when:

- every relevant object or state becomes a vertex
- every legal move / dependency / compatibility relation becomes an edge
- illegal moves are absent
- the quantity later optimized by the algorithm still means the same thing in the graph

That last point matters most.

For example:

- path length in the graph should match number of moves if you want BFS
- edge weights should match real costs if you want Dijkstra
- capacities should match real usage limits if you want max flow

## From Brute Force To The Right Idea

### Brute Force

The naive mistake is to stay inside the story:

- "a room is connected to a room"
- "a course depends on a course"
- "a token changes into another token"

but never write down the reusable structure.

Then every next step feels bespoke.

### The Real Compression

The right abstraction is:

- keep only the objects or states that matter
- connect them exactly when one legal move or relation exists

Once you do that, the statement often collapses into one of a few familiar graph families:

- connected components
- shortest paths
- DAG order / SCC compression
- matching
- flow

This is why modeling is often the true unlock.

### The First Question Is Not "Which Algorithm?"

The first question is:

> What is the smallest graph that still preserves the problem correctly?

That single sentence drives almost every good modeling decision:

- object graph or state graph?
- explicit or implicit?
- weighted or unweighted?
- directed or undirected?
- vertex capacity or edge capacity?

## Core Invariant And Why It Works

### 1. A Good Model Preserves Legal Objects And Legal Moves

If a graph path corresponds to something impossible in the original problem, the model is wrong.

If a legal move in the original problem is missing from the graph, the model is also wrong.

So the key invariant is:

- graph structure and problem structure must match in both directions

This is why graph modeling should be stated in plain language before code:

- "vertex means ..."
- "edge means ..."

### 2. Direction Is Semantic, Not Cosmetic

An edge should be directed if the relation is one-way:

- prerequisite
- implication
- allowed transition
- one-way road

It should be undirected only when the relation is symmetric:

- road usable both ways
- friendship
- same connected region relation

Choosing direction incorrectly often breaks the problem before the algorithm starts.

### 3. Weight Is Meaning

Weights should exist only when they represent real cost:

- distance
- time
- energy
- penalty

If every move costs the same, do **not** add fake weights just because weighted templates exist.

This is the modeling boundary between:

- BFS
- `0-1 BFS`
- Dijkstra
- Bellman-Ford

### 4. Explicit And Implicit Graphs Are Both First-Class Models

Sometimes the graph should be stored:

- given edges between cities
- task dependency list

Sometimes the graph should be generated on demand:

- grid neighbors
- number transformations
- bitmask transitions

An implicit graph is still a graph.

The only difference is:

- `Adj(u)` is computed instead of pre-stored

That is often the cleanest model when the total state space is large but only a fraction is explored.

### 5. State Graphs Are Usually The Hidden Hard Part

For many problems, the vertices are not physical objects from the statement.

They are states such as:

- a board position
- a string after one operation
- a pair `(position, mask)`
- a city plus whether a coupon was already used

This is the moment where many "not a graph problem" tasks become graph problems.

If one legal move transforms one state into another:

- states are vertices
- legal moves are edges

### 6. Modeling Often Chooses The Whole Algorithm Family

Once the graph is right, the next step is usually obvious:

- unweighted reachability -> BFS / DFS
- weighted path cost -> shortest paths
- dependencies -> toposort / SCC
- left/right compatibility -> matching
- capacities -> flow

That is why graph modeling is a spine topic, not an isolated trick.

## Complexity And Tradeoffs

Representation choices matter.

Typical tradeoffs:

| Representation | Best when | Main benefit | Main danger |
| --- | --- | --- | --- |
| adjacency list | sparse graph | near-linear traversals | forgetting hidden dense structure |
| adjacency matrix | tiny or dense graph | $O(1)$ edge lookup | wasting $O(n^2)$ memory |
| implicit neighbors | huge state space, local transitions | no need to materialize all edges | generating duplicate or invalid states |

Modeling tradeoffs:

- explicit graphs are easier to debug
- implicit graphs are often the only feasible option for grids or state spaces
- richer states make the graph correct, but can blow up the state count
- over-compressing the model can silently remove legal moves

## Variant Chooser

| Situation | Best first model | Why it fits | Main danger |
| --- | --- | --- | --- |
| cities and roads / friendships / components | real-object graph | the statement already gives the vertices and edges | choosing direction wrong |
| grid movement | implicit grid graph | local neighbors are generated cheaply | materializing unnecessary edges |
| number / string / board transformations | state graph | the real vertices are states, not story objects | missing state dimensions |
| prerequisites / dependencies | directed graph or DAG | "must happen before" is literally edge direction | forgetting cycle handling |
| two disjoint sides with compatibility | bipartite graph | left/right structure is the real model | mixing the two sides |
| capacities or usage limits | flow network | capacities belong on edges after reduction | using plain traversal on a throughput problem |

Two quick reject rules:

- if you cannot define a vertex and edge in one clean sentence, the model is not ready yet
- if your graph remembers story details that never affect legality or cost, it is probably too fat

## Worked Examples

### Example 1: `Counting Rooms` Is An Implicit Grid Graph

In [Counting Rooms](../../../practice/ladders/graphs/graph-modeling/countingrooms.md), the statement never gives you an explicit graph.

The correct model is:

- vertex: a floor cell
- edge: one legal step to a neighboring floor cell

This graph is:

- unweighted
- undirected in effect
- implicit

Once that is clear, the algorithm choice is immediate:

- count connected components with DFS/BFS

This is a perfect first reminder that:

- "the graph is not written down" does not mean "there is no graph"

### Example 2: `Building Roads` Is A Real-Object Graph

In [Building Roads](../../../practice/ladders/graphs/graph-modeling/buildingroads.md):

- vertex: city
- edge: existing road

The graph is:

- explicit
- undirected
- unweighted

The real task is then:

- find connected components
- connect one representative from each component

This is a clean example where the model is simple, and the constructive answer falls out of the structure.

### Example 3: Grid Shortest Path Means Model First, Then Cost Model

Suppose you move on a grid with four-directional steps.

If every move costs `1`, then:

- the graph is an implicit unweighted graph
- shortest path means BFS

If some cells have entry costs, then the model changes:

- weights now mean something real
- the next algorithm may become Dijkstra

So even on the same grid, the important modeling question is:

- what does one edge cost mean?

### Example 4: State Graphs Are Often The Hidden Solution

Suppose the problem asks for the minimum number of operations to transform one number into another.

The physical objects in the story are numbers, but the graph is:

- vertex: current number / current state
- edge: one legal operation

This is not a road graph or dependency graph.

It is a state graph.

That one shift in viewpoint is the difference between:

- inventing ad hoc recursion
- and running standard shortest-path or BFS logic

### Example 5: Bipartite Modeling Chooses Matching Before Code

Suppose the statement gives:

- workers
- jobs
- compatibility pairs

The correct first model is:

- left side = workers
- right side = jobs
- edge = compatibility

That is what makes matching natural later.

If capacities enter, the model may then grow into flow, but the left/right partition is still the key modeling move.

## Algorithm And Pseudocode

There is no single graph-modeling algorithm, but there is a reusable checklist.

### Minimal Modeling Checklist

```text
1. say what one vertex means
2. say what one edge means
3. decide directed or undirected
4. decide weighted or unweighted
5. decide explicit or implicit adjacency
6. check that every legal move exists
7. check that every graph path still means something legal in the problem
8. only then choose BFS / DFS / shortest paths / SCC / matching / flow
```

### Adjacency List Skeleton

Weighted:

```cpp
struct Edge {
    int to;
    int w;
};
vector<vector<Edge>> g(n);
```

Unweighted:

```cpp
vector<vector<int>> g(n);
```

Implicit neighbor generation:

```text
for each legal move from state u:
    generate next state v
```

This is still an adjacency function, just not a stored adjacency list.

## Implementation Notes

### 1. Name The Vertex Before You Touch Code

If you cannot say:

- "a vertex represents ..."

then you are still in the story, not in the model.

### 2. Do Not Smuggle Extra Story Detail Into The State

A good state stores exactly what future legality or cost depends on.

Too little state:

- loses correctness

Too much state:

- explodes complexity

### 3. Implicit Graphs Need Duplicate Control

When generating neighbors on demand:

- visited / distance maps become even more important

Otherwise the same logical state may be regenerated many times.

### 4. Direction Should Match Meaning

Ask:

- if I can go from `u` to `v`, can I always go back?

If not, the edge is directed.

This sounds obvious, but many graph bugs are really direction bugs.

### 5. Pick The Lightest Valid Graph Family

After the model is fixed, avoid overengineering:

- unweighted graph -> BFS, not Dijkstra
- plain bipartite compatibility -> matching, not flow first
- throughput with capacities -> flow, not ad hoc path search

### 6. State Graphs Often Need Pruning Bounds

A theoretically valid state graph can still be unusably large.

So after modeling, ask:

- which states are reachable?
- which states are useful?
- can some transitions be generated lazily?

Correctness comes first, but feasibility comes right after.

### 7. The Graph Can Change Level

Sometimes the right graph is not on original vertices at all.

Examples:

- SCC condensation DAG
- flow network after node splitting
- bipartite graph after left/right partition

This is still graph modeling, just one layer above the statement.

## Beyond The Core Topic

This page is intentionally centered on the modeling decisions that show up constantly in contest problems:

- object graph
- grid graph
- state graph
- dependency graph
- bipartite model
- capacity network

Important next-layer directions include:

- state compression for DP-heavy search spaces
- layered graphs for time / parity / coupon states
- implication graphs for 2-SAT
- reduced graphs such as SCC condensation or flow transformations

The right study order is:

1. learn to define vertices and edges cleanly
2. learn to choose direction and cost semantics correctly
3. then learn richer reductions built on top of that discipline

## Practice Archetypes

The most common graph-modeling-flavored tasks are:

- **connected components in a hidden graph**
- **shortest path after choosing the right move model**
- **state graph with legal transformations**
- **dependency graph with cycle / order logic**
- **bipartite compatibility**
- **capacity reduction**

The strongest smell is:

- the algorithm family becomes obvious only after you rename the story as vertices and edges

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Primary / course:

- [MIT 6.006 Lecture 11: Graph Search and Representations](https://courses.csail.mit.edu/6.006/fall09/lecture_notes/lecture11.pdf)
- [Stanford CS106B: Graph Algorithms](https://web.stanford.edu/class/archive/cs/cs106b/cs106b.1244/lectures/24-graphs/)
- [CMU 15-281: State Space Graphs and Search](https://www.cs.cmu.edu/~15281-f24/lectures/15281_F24_Lec2_Agents_and_Uninformed_Search_inked.pdf)

Reference:

- [Cornell CS3110: Graph Representations and Traversals](https://www.cs.cornell.edu/courses/cs3110/2014sp/lectures/24/graph-representations-and-traversals.html)

Practice:

- [ICPC Curriculum](https://curriculum.u.icpc.global/curriculum/)
- [CSES Graph Algorithms](https://cses.fi/problemset/)

Repo anchors:

- practice ladder: [Graph modeling ladder](../../../practice/ladders/graphs/graph-modeling/README.md)
- practice note: [Counting Rooms](../../../practice/ladders/graphs/graph-modeling/countingrooms.md)
- practice note: [Building Roads](../../../practice/ladders/graphs/graph-modeling/buildingroads.md)
- notebook refresher: [Graph cheatsheet](../../../notebook/graph-cheatsheet.md)

## Related Topics

- [BFS And DFS](../bfs-dfs/README.md)
- [Shortest Paths](../shortest-paths/README.md)
- [Matching](../matching/README.md)
- [Maximum Flow](../flow/README.md)
