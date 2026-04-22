# QBFLOWER

- Title: `Tặng hoa`
- Judge: `VN SPOJ`
- Original URL: [https://vn.spoj.com/problems/QBFLOWER/](https://vn.spoj.com/problems/QBFLOWER/)
- Main topic: `Graphs -> Matching`
- Likely subtype: `General graph matching`
- Status: `solved`
- Solution file: [qbflower.cpp](/Users/mitu/Desktop/work/cp-cpp/solutions/graphs/matching/qbflower.cpp)

## Why This Folder

This problem is placed under `practice/ladders/graphs/matching/` because the repo is organized by learning topic first.

The exact problem page on `vn.spoj.com` was not publicly fetchable from my side, but the public VNOJ problem listing classifies `qbflower` under general graph matching, which makes this the right home for now.

## Key Idea

Treat each girl as a vertex and each boy as an undirected edge connecting the two girls on his list.

We need the smallest number of chosen edges so that every vertex is incident to at least one chosen edge. That is exactly the `minimum edge cover` problem on a general graph.

For any graph without isolated vertices:

`minimum edge cover size = number of vertices - maximum matching size`

So the task becomes:

1. compute a maximum matching in the general graph
2. print `N - matching_size`

Because the graph is not guaranteed to be bipartite, the solution uses Edmonds' blossom algorithm.

## Theory Version vs Judge Version

There are two slightly different ways to talk about this problem.

### 1. Strict graph-theory version

In graph theory, an edge cover of all vertices exists only if there is no isolated vertex.

So if some girl never appears in any pair at all, then the instance is infeasible.

Under that version of the problem, if the output spec explicitly said what to do when impossible, then printing `-1` would be a reasonable choice.

### 2. Judge-facing version on `vn.spoj`

The official statement only says to print the minimum number of boys to choose. It does not define any special output for an impossible instance.

The accepted submission for this repository follows the judge-facing formula directly:

`answer = N - maximum_matching`

That is the version kept in [qbflower.cpp](/Users/mitu/Desktop/work/cp-cpp/solutions/graphs/matching/qbflower.cpp).

## Why The Formula Works

If we already have a maximum matching:

- every matched edge covers two different girls efficiently
- every girl left unmatched needs one more chosen edge to cover her

So the optimal count becomes:

`matched_edges + unmatched_vertices = maximum_matching + (N - 2 * maximum_matching) = N - maximum_matching`

## Implementation Notes

- The graph is a general graph, not a bipartite graph.
- So we cannot use Hopcroft-Karp here.
- The implementation uses Edmonds' blossom algorithm for maximum matching.

## Repo Format

For this repository, this problem is recorded in two pieces:

- practice note: [qbflower.md](/Users/mitu/Desktop/work/cp-cpp/practice/ladders/graphs/matching/qbflower.md)
- code submission: [qbflower.cpp](/Users/mitu/Desktop/work/cp-cpp/solutions/graphs/matching/qbflower.cpp)

The note format I used for this problem is:

1. metadata: title, judge, URL, topic, status
2. placement note: why it belongs in this folder
3. graph model: how to transform the statement into a graph problem
4. theorem: the formula or main result
5. judge note: any mismatch between clean theory and actual judge behavior
6. implementation note: what algorithm the code uses
