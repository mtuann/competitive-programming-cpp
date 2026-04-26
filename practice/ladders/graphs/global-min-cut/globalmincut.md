# Minimum Cut

- Title: `Minimum Cut`
- Judge / source: `POJ 2914`
- Original URL: [http://poj.org/problem?id=2914](http://poj.org/problem?id=2914)
- Secondary topics: `Stoer-Wagner`, `Global min-cut`, `Undirected weighted graph`
- Difficulty: `hard`
- Subtype: `Single global minimum cut with parallel edges`
- Status: `solved`
- Solution file: [globalmincut.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/global-min-cut/globalmincut.cpp)

## Why Practice This

This is the cleanest first in-repo flagship for `Randomized / Global Min-Cut`.

The benchmark is intentionally narrow:

- one undirected weighted graph
- no designated source and sink
- parallel edges allowed
- output only the global min-cut value

So the hard part is exactly the lane itself:

- recognize that this is not one `s-t` cut
- trust Stoer-Wagner contraction
- keep the family boundary sharp against plain flow and Gomory-Hu

## Recognition Cue

Reach for this route when:

- the statement asks for the minimum total edge weight whose removal disconnects the graph
- the graph is undirected
- there is no singled-out pair `(s, t)`
- one answer for the whole graph is enough

The strongest smell here is:

- "global minimum cut of an undirected weighted graph"

That is exactly this lane.

## Problem-Specific Route

This benchmark does **not** want:

- Dinic on one guessed pair, because the cut is not tied to one fixed source/sink
- Gomory-Hu, because there is no pairwise query layer after the cut family
- Karger as the first route, because the repo's first contract here is exact deterministic Stoer-Wagner

The clean route is:

1. accumulate parallel edges into one symmetric weight matrix
2. run Stoer-Wagner phases on the current contracted graph
3. treat the last phase vertex as one candidate cut
4. contract the last two phase vertices
5. keep the minimum phase cut over all rounds

## Core Idea

Each phase grows one set `A` by repeatedly adding the vertex with largest total adjacency weight into `A`.

If `t` is the last added vertex and `s` is the previous one, then:

- the final tightness on `t` equals one minimum `s-t` cut in the current graph

That means each phase produces one valid candidate for the global minimum cut.

After that:

- merge `s` and `t`
- keep going

Any better global cut must either:

- already be the phase cut just found
- or survive in the contracted graph

So the minimum phase cut over all rounds is the global answer.

## Complexity

- Stoer-Wagner with dense adjacency matrix: `O(n^3)`
- memory: `O(n^2)`

That is the right shape for this classical benchmark.

## Input / Output Contract For This Repo

This flagship follows the classical POJ 2914 contract:

- input is a sequence of test cases until EOF
- each test case begins with `n m`
- then `m` lines follow, each with `u v w`
- vertices are `0`-based
- multiple edges between the same pair must be summed

The solution prints:

- one line per test case
- the value of the global minimum cut

## Pitfalls / Judge Notes

- This is **not** a directed cut problem.
- Sum parallel edges instead of overwriting them.
- A disconnected graph has global min-cut `0`; the implementation handles that naturally.
- The starter can recover one witness side, but this benchmark only needs the cut value.

## Reusable Pattern

- Topic page: [Randomized / Global Min-Cut](../../../../topics/graphs/global-min-cut/README.md)
- Practice ladder: [Randomized / Global Min-Cut ladder](README.md)
- Starter template: [stoer-wagner-global-mincut.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/stoer-wagner-global-mincut.cpp)
- Notebook refresher: [Global Min-Cut hot sheet](../../../../notebook/global-min-cut-hot-sheet.md)
- Compare points:
  - [Maximum Flow](../../../../topics/graphs/flow/README.md)
  - [Gomory-Hu Tree](../../../../topics/graphs/gomory-hu/README.md)
- This note adds: the clean benchmark where the cut family is still global and singular, not yet pairwise or query-heavy.

## Solutions

- Code: [globalmincut.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/global-min-cut/globalmincut.cpp)
