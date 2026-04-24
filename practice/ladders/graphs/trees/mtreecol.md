# MTREECOL

- Title: `MTREECOL - Color a tree`
- Judge / source: `VN SPOJ / VNOI`
- Original URL: [https://vn.spoj.com/problems/MTREECOL/](https://vn.spoj.com/problems/MTREECOL/)
- Mirror URL: [https://oj.vnoi.info/problem/mtreecol](https://oj.vnoi.info/problem/mtreecol)
- Source contest: `Peking 2004`
- Secondary topics: `Greedy scheduling`, `Precedence constraints`, `Tree contraction`
- Difficulty: `hard`
- Subtype: `Minimum weighted completion time on a rooted tree precedence order`
- Status: `solved`
- Solution file: [mtreecol.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/trees/mtreecol.cpp)

## Why Practice This

This is a very good example of a tree problem that looks like DP at first, but the winning idea is actually scheduling greedy.

The rooted tree only provides precedence constraints:

- a node can be colored only after its parent is colored
- every node takes exactly `1` unit of time
- coloring node `i` at completion time `F_i` costs `C_i * F_i`

So the real task is:

- find the best linear extension of a rooted tree
- minimize the weighted sum of completion times

## Recognition Cue

Reach for scheduling-on-a-tree reductions when:

- the tree only imposes ancestor-before-descendant precedence
- every node has a weight and one unit processing time
- the objective is a weighted completion-time sum

The strongest smell is:

- "color/process nodes only after their parent, minimize weighted finish times"

That usually means precedence scheduling, not classic subtree DP.

## Problem-Specific Transformation

The rooted-tree statement is rewritten as:

- each rooted component is a schedulable block
- choose which available block to process next

Then the main question becomes:

- which block should go earlier in the linear extension?

The pairwise-swap analysis answers that with one density:

- `W(X) / S(X)`

So the tree is only the source of precedence constraints; the real engine is greedy scheduling plus contractions.

## Core Idea

At any moment, think of several already-contracted components hanging under the root.

For one active component `X`, define:

```text
W(X) = total C_i inside X
S(X) = number of original nodes inside X
```

Suppose two available components `X` and `Y` can both be processed next. If we schedule:

```text
X before Y
```

instead of:

```text
Y before X
```

the pairwise-swap calculation says `X` should go first exactly when:

```text
W(X) / S(X) >= W(Y) / S(Y)
```

So available blocks should be ordered by decreasing density:

```text
density(X) = W(X) / S(X)
```

For a rooted tree, that leads to a clean greedy contraction:

1. every node starts as its own component
2. repeatedly choose the active non-root component with maximum density
3. merge it into its parent component
4. continue until only the root component remains

If component `X` is merged into parent `P`, then every node in `X` gets delayed by:

```text
S(P)
```

more time units, so the total extra cost added at that step is:

```text
W(X) * S(P)
```

Starting from:

```text
sum C_i
```

and adding these merge costs gives the optimum answer.

## Complexity

With the straightforward implementation:

- each merge scans all active components to find the best density
- each merge also scans all nodes to redirect children of the merged component

So the total complexity is:

```text
O(N^2)
```

which is easily fast enough for `N <= 1000`.

## Pitfalls / Judge Notes

- This is a multi-test problem ending with `0 0`.
- The input edges are already directed from parent to child.
- Do not compare densities with floating point. Use cross multiplication:

```text
W(a) * S(b) ? W(b) * S(a)
```

- The root is never chosen for merging; everything eventually merges into it.
- The answer fits in `32-bit` for the official constraints, but `long long` is the safer default.

## Reusable Pattern

- Topic page: [Trees](../../../../topics/graphs/trees/README.md)
- Practice ladder: [Trees ladder](README.md)
- Starter template: [Template library overview](../../../../template-library.md)
- Notebook refresher: [Graph cheatsheet](../../../../notebook/graph-cheatsheet.md)
- Carry forward: compute parent, depth, and subtree facts once so later tree logic has something stable to build on.
- This note adds: the tree-specific invariant or decomposition that goes beyond the plain rooted-tree setup.

## Solutions

- Code: [mtreecol.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/trees/mtreecol.cpp)
