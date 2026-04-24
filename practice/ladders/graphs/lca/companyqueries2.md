# COMPANYQUERIES2

- Title: `COMPANYQUERIES2 - Company Queries II`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1688](https://cses.fi/problemset/task/1688)
- Secondary topics: `Binary lifting`, `Depth equalization`, `Tree path queries`
- Difficulty: `medium`
- Subtype: `Lowest common ancestor queries on a rooted tree`
- Status: `solved`
- Solution file: [companyqueries2.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/lca/companyqueries2.cpp)

## Why Practice This

This is the cleanest "real" LCA problem in the CSES tree section.

You are given a rooted company hierarchy and many queries asking for the lowest common boss of two employees. Nothing extra is hiding in the statement, so the whole point is to make binary lifting feel natural:

- preprocess the ancestor table once
- answer each query by jumping upward in powers of two
- recognize that equalizing depths is what makes the rest of the query simple

If binary lifting still feels like a memorized trick, this is the problem that usually turns it into a reusable tool.

## Recognition Cue

Reach for LCA when:

- the graph is a rooted tree
- many queries ask for the meeting point of two nodes in that rooted hierarchy
- path or ancestor formulas become easy once the common ancestor is known
- preprocessing once is clearly allowed and reused by many queries

The strongest wording smell is:

- "lowest common boss", "lowest common ancestor", or "meeting node in a rooted tree"

## Problem-Specific Transformation

The company story is just a rooted tree:

- employee `1` is the root
- every other employee has one direct boss

So the whole task becomes:

- preprocess powers-of-two ancestors
- equalize depths
- lift both nodes together until they almost meet

That reframes the problem from hierarchy language into the standard binary-lifting query template.

## Core Idea

Root the tree at employee `1`.

For every node `v`, store:

- `depth[v]`: distance from the root
- `up[k][v]`: the `2^k`-th ancestor of `v`

The meaning of `up[k][v]` is the whole trick.

Instead of remembering how to move up by every possible distance, we only remember powers of two:

- `up[0][v]` = direct boss
- `up[1][v]` = 2 bosses up
- `up[2][v]` = 4 bosses up
- ...

Then any upward move can be decomposed by bits.

For example, moving up `13` levels means:

```text
13 = 8 + 4 + 1
```

so we jump with:

```text
up[3] -> up[2] -> up[0]
```

## How An LCA Query Works

To answer `lca(a, b)`:

1. If one node is deeper, lift it until both nodes are at the same depth.
2. If they already match, that node is the answer.
3. Otherwise try powers from large to small. Whenever `up[k][a] != up[k][b]`, lift both nodes by `2^k`.
4. After that loop, `a` and `b` are children of the LCA, so the answer is `up[0][a]`.

Why this is correct:

- Step 1 removes the easy mismatch: different depths.
- In step 3 we only take jumps that keep the nodes **below** the LCA.
- The first point where they would stop differing is exactly one edge below the answer.

## Implementation Plan

Because the input already gives the parent of every employee, we can build a `children` list directly.

Then:

1. Traverse from root `1` to fill `depth`.
2. For each child `v` of `u`, set:

```text
up[0][v] = u
up[k][v] = up[k-1][ up[k-1][v] ]
```

3. Each query uses:
   - one `lift()` call to equalize depths
   - one downward loop over powers of two

The solution here uses an iterative traversal, which is a safe default for CSES because the tree can be very deep.

## Complexity

- preprocessing: `O(n log n)`
- each query: `O(log n)`
- memory: `O(n log n)`

With `n, q <= 2 * 10^5`, this is exactly the intended complexity.

## Pitfalls / Judge Notes

- The tree is rooted at `1`, so set every ancestor of the root to `1` itself.
- Return early after depth equalization if one node becomes the other.
- Use enough levels in the jump table: while `(1 << LOG) <= n`, keep increasing `LOG`.
- An iterative DFS/BFS avoids recursion-depth issues on a long chain.

## Reusable Pattern

- Topic page: [LCA](../../../../topics/graphs/lca/README.md)
- Practice ladder: [LCA ladder](README.md)
- Starter template: [lca-binary-lifting.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/lca-binary-lifting.cpp)
- Notebook refresher: [Graph cheatsheet](../../../../notebook/graph-cheatsheet.md)
- Carry forward: equalize depths first, then lift both nodes together from large jumps downward.
- This note adds: the query formula or tree-specific interpretation that sits on top of plain LCA.

## Solutions

- Code: [companyqueries2.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/lca/companyqueries2.cpp)
