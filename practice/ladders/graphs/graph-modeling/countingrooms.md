# Counting Rooms

- Title: `Counting Rooms`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1192](https://cses.fi/problemset/task/1192)
- Secondary topics: `Grid graph`, `Flood fill`, `Connected components`
- Difficulty: `easy`
- Subtype: `Count connected components of floor cells in a blocked grid`
- Status: `solved`
- Solution file: [countingrooms.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/graph-modeling/countingrooms.cpp)

## Why Practice This

This is one of the cleanest first graph-modeling problems because the statement never gives you an explicit graph.

You have to decide that:

- each floor cell is a vertex
- each 4-direction move between neighboring floor cells is an edge

Once that model is fixed, the rest is just counting connected components with a standard flood fill.

## Key Idea

Treat the grid as an implicit unweighted graph:

- vertex: a cell `(r, c)` with `grid[r][c] == '.'`
- edge: one step up, down, left, or right to another floor cell

Then each room is exactly one connected component of this graph.

So the algorithm is:

1. Scan every cell.
2. When an unvisited floor cell appears, start one flood fill from it.
3. Mark every reachable floor cell in that component.
4. Increase the room count once for that fill.

The modeling step matters more than the traversal brand. DFS or BFS both work because the graph is unweighted and we only need component counting.

## Complexity

- every cell is processed at most once
- each grid edge is checked a constant number of times
- total: `O(nm)`

This is optimal for the given grid size.

## Pitfalls / Judge Notes

- The graph is implicit, so do not try to build an adjacency list for all cells first.
- Use an iterative flood fill; recursive DFS can overflow the call stack on a `1000 x 1000` grid.
- Only the `.` cells belong to the graph. Walls are absent vertices, not blocked visits to mark later.
- Be consistent about 4-direction movement. Diagonals are not edges here.

## Reusable Pattern

- Topic page: [Graph Modeling](../../../../topics/graphs/graph-modeling/README.md)
- Practice ladder: [Graph Modeling ladder](README.md)
- Starter template: [dfs-iterative.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dfs-iterative.cpp)
- Notebook refresher: [Graph cheatsheet](../../../../notebook/graph-cheatsheet.md)
- Carry forward: if a grid cell behaves like a state you can stand on, model it as a vertex first and let traversal come second.
- This note adds: counting components when the graph exists only implicitly through local moves.

## Solutions

- Code: [countingrooms.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/graph-modeling/countingrooms.cpp)
