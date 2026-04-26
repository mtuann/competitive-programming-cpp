# Task Assignment

- Title: `Task Assignment`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/2129](https://cses.fi/problemset/task/2129)
- Secondary topics: `Weighted bipartite matching`, `Assignment matrix`, `Perfect matching output`
- Difficulty: `hard`
- Subtype: `Square minimum-cost assignment with witness output`
- Status: `solved`
- Solution file: [taskassignment.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/hungarian-assignment/taskassignment.cpp)

## Why Practice This

This is the cleanest first in-repo flagship for `Hungarian / Assignment Problem`.

The statement is almost the textbook assignment problem with no distracting side story:

- `n` employees
- `n` tasks
- full `n x n` cost matrix
- each employee gets exactly one task
- each task gets exactly one employee
- print both the minimum cost and one valid assignment

So the hard part is not graph modeling anymore. The hard part is recognizing that this has moved past plain matching and into weighted one-to-one assignment.

## Recognition Cue

Reach for the Hungarian lane when:

- the input is already a square cost matrix
- every row and every column must be used exactly once
- the objective is the minimum total cost

The strongest smell here is:

- "pick one entry from every row and every column so the total sum is minimum"

That is exactly the assignment problem.

## Problem-Specific Route

This task does **not** need a capacity-rich flow network first.

The clean route is:

1. treat employees as rows and tasks as columns
2. run Hungarian on the matrix
3. recover the chosen column for each row
4. print the total cost and the row/column pairs in `1`-based indexing

The repo starter already exposes:

- minimum cost
- and `assignment[row] = column`

which is exactly the output contract here.

## Core Idea

Hungarian keeps dual potentials `u` and `v` such that:

$$
u[i] + v[j] \le a[i][j].
$$

Edges with equality are the current tight edges. The algorithm repeatedly:

- grows one alternating structure from the next unmatched row
- tracks the smallest uncovered reduced slack
- shifts potentials so at least one new edge becomes tight
- augments once a free column is reached

That gives a perfect assignment in:

$$
O(n^3).
$$

For `n <= 200`, this is very comfortable.

## Complexity

- Hungarian on an `n x n` matrix: `O(n^3)`
- memory: `O(n^2)` for the input matrix and `O(n)` for the solver state

## Pitfalls / Judge Notes

- The answer must print the **minimum total cost first**.
- After that, any optimal employee-task pairing is accepted.
- Keep everything in `long long` in the template path even though this task's raw bounds are small.
- The template returns zero-based columns, so convert to `1`-based when printing.

## Reusable Pattern

- Topic page: [Hungarian / Assignment Problem](../../../../topics/graphs/hungarian-assignment/README.md)
- Practice ladder: [Hungarian ladder](README.md)
- Starter template: [hungarian-assignment.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hungarian-assignment.cpp)
- Notebook refresher: [Hungarian hot sheet](../../../../notebook/hungarian-hot-sheet.md)
- Compare points:
  - [Matching](../../../../topics/graphs/matching/README.md)
  - [Min-Cost Flow](../../../../topics/graphs/min-cost-flow/README.md)
- This note adds: the clean matrix-first flagship where Hungarian is the natural first route, not only a side note under matching or min-cost flow.

## Solutions

- Code: [taskassignment.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/hungarian-assignment/taskassignment.cpp)
