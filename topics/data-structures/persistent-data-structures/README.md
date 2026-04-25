# Persistent Data Structures

Persistent data structures are the first serious answer when:

- updates create **new versions** instead of destroying the old one
- queries can ask about **past snapshots**
- copies of a structure can later **branch independently**

For contest work, the first exact starter is usually a **persistent segment tree** built by path copying.

The right mental shift is:

1. one version is not "the array right now"
2. one version is one **root handle**
3. an update does not mutate the old structure
4. it returns a **new root** that shares most of its nodes with the old one

That sharing is the whole point of persistence.

## At A Glance

- **Use when:** old versions stay queryable, or the statement literally talks about copies / snapshots / branching histories
- **Core worldview:** every version is just one root; updates copy only the nodes on the changed path and share everything else
- **Main tools:** path copying, version root array, persistent segment tree, immutable query logic
- **Typical complexity:** `O(log n)` new nodes per point update and `O(log n)` per range query for the first segment-tree route
- **Main trap:** accidentally mutating a shared node and corrupting older versions

Strong contest signals:

- "copy array `k`, then modify the copy"
- "query version `v` after several later updates already happened"
- "past snapshots remain alive, not just undoable"
- "each update changes one position, but many versions coexist"

Strong anti-cues:

- only the **current** state matters, and you just need point/range queries
- you only need to undo along one DFS or time walk -> [DSU Rollback / Offline Dynamic Connectivity](../dsu-rollback/README.md) is closer
- updates are heavy range updates with lazy tags
- the task is really an offline order-statistics lane, not versioned array snapshots

## Prerequisites

- [Segment Tree](../segment-tree/README.md)
- [Reasoning, Invariants, And Proof Discipline](../../foundations/reasoning/README.md)

Helpful neighboring topics:

- [Lazy Segment Tree](../lazy-segment-tree/README.md) as a compare point for "update one current tree" vs "create a new tree version"
- [DSU Rollback / Offline Dynamic Connectivity](../dsu-rollback/README.md) for the contrast `undo one active state` vs `query many historical states`

## Problem Model And Notation

Let:

$$
a^{(0)} = [a_0, a_1, \dots, a_{n-1}]
$$

be the initial array.

After each update, we want a new version:

$$
a^{(1)}, a^{(2)}, \dots
$$

Queries can refer to any version:

$$
\mathrm{sum}(v, l, r)
$$

meaning:

```text
query version v on interval [l, r)
```

The first shipped route in this repo supports:

- point assignment
- range sum
- arbitrary queries on any stored version
- branching from an older version by updating it again

That is the exact shape of [Range Queries and Copies](../../../practice/ladders/data-structures/persistent-data-structures/rangequeriesandcopies.md).

## From Brute Force To The Right Idea

### Brute Force

If each update creates a new full array copy, then one point update costs:

$$
O(n)
$$

because we duplicate the whole array.

With many updates, this becomes too expensive in both:

- time
- memory

### Structural Observation

Suppose we already store a segment tree for one version.

If one update changes only one array position, then in that segment tree:

- only one root-to-leaf path changes
- every node off that path stays exactly the same

So copying the whole tree is wasteful.

We only need to:

- create new nodes on the changed path
- reuse old child pointers for untouched subtrees

This is **path copying**.

### Why Path Copying Is Enough

For a point update:

- the leaf for that index changes
- each ancestor of that leaf needs a repaired aggregate
- no other node needs any modification

So one update needs only:

$$
O(\log n)
$$

new nodes.

That is the core persistence saving.

## Core Invariant And Why It Works

## 1. Version Meaning

Each version is represented by one root:

```text
root[v] = the root node of version v
```

The root is enough because the whole tree below it determines all array values for that version.

## 2. Node Meaning

For every node representing segment `[L, R)`:

```text
sum[node] is the true sum of that segment for exactly one version tree path
```

The meaning is the same as an ordinary segment tree.

Persistence changes **how nodes are created**, not what a node summary means.

## 3. Update Rule

When updating one position `pos`:

- create a new root
- recurse toward the affected leaf
- create a new node at every segment on that path
- reuse the untouched child from the previous version

So the new version shares all subtrees that do not intersect the update path.

## 4. Why Old Versions Stay Correct

Older versions never lose correctness because we never mutate their nodes.

We only:

- read old nodes
- allocate new copies where needed
- connect those copies into a new root

So once a root is created, that version is immutable.

## 5. Why Query Works

A query on version `v` is just an ordinary segment-tree query starting from `root[v]`.

Because every node in that version tree already stores the correct segment sum for that version, the usual range-query logic still applies unchanged.

So persistence does **not** make querying conceptually harder.

It only changes the update construction.

## 6. Why Complexity Stays Logarithmic

For a balanced segment tree:

- one point update touches `O(log n)` segments
- one range query visits `O(log n)` nodes in the standard way

Therefore:

- update: `O(log n)` new nodes
- query: `O(log n)`
- memory after `q` updates: `O(n + q \log n)` nodes

## Variant Chooser

### Use The First Persistent Segment Tree Route When

- updates are point assignments or point adds
- queries ask sums or another standard segment-tree aggregate
- many versions stay alive
- one old version may be copied and then modified independently

This is the exact route for `Range Queries and Copies`.

### Prefer Rollback When

- only one active state exists at a time
- you move forward and backward through one recursion or one time traversal
- old snapshots do not need arbitrary future queries

Rollback is about:

- undoing

Persistence is about:

- preserving many roots at once

### Reopen The Topic Before Reusing The Starter When

- you need range updates, not point updates
- the value stored per node is more complex than a simple sum
- the task is persistent order-statistics (`k`-th smallest, prefix-frequency roots, etc.)
- persistence is on a structure that is not segment-tree-shaped

## Worked Example 1: Range Queries And Copies

Start with:

$$
[1, 2, 3, 4]
$$

Call its root `r0`.

Now update position `1` to `10`, producing version `r1`.

Only the nodes on the path to that leaf are copied.

Conceptually:

```text
r0: [1,2,3,4]
r1: [1,10,3,4]
```

The right half `[3,4]` is unchanged, so the new tree can literally reuse that whole subtree from `r0`.

Then:

- query on `r0` over `[0,4)` gives `10`
- query on `r1` over `[0,4)` gives `18`

Both versions coexist.

## Worked Example 2: Why Copy Is Just Another Root Handle

Suppose the statement says:

- copy version `2`
- the new copy becomes version `5`

There is no structural work yet.

We can simply do:

```text
root[5] = root[2]
```

because both names currently point at the same immutable version tree.

Only when version `5` later gets updated do we allocate fresh path-copied nodes from that root.

That is why copy operations are so cheap in persistent problems.

## Pseudocode

```text
build(a, l, r):
    node = new node
    if r - l == 1:
        node.sum = a[l]
        return node
    m = (l + r) / 2
    node.left = build(a, l, m)
    node.right = build(a, m, r)
    node.sum = node.left.sum + node.right.sum
    return node

point_set(node, l, r, pos, value):
    new_node = copy(node)
    if r - l == 1:
        new_node.sum = value
        return new_node
    m = (l + r) / 2
    if pos < m:
        new_node.left = point_set(node.left, l, m, pos, value)
    else:
        new_node.right = point_set(node.right, m, r, pos, value)
    new_node.sum = new_node.left.sum + new_node.right.sum
    return new_node

range_sum(node, l, r, ql, qr):
    if qr <= l or r <= ql:
        return 0
    if ql <= l and r <= qr:
        return node.sum
    m = (l + r) / 2
    return range_sum(node.left, l, m, ql, qr)
         + range_sum(node.right, m, r, ql, qr)
```

## Implementation Notes

- Keep an arena `vector<Node>` and store child indices instead of raw pointers if you want simpler contest memory management.
- Copying a node means:
  - append one new node
  - initialize it from the old node
  - mutate only the fields on the new copy
- Internal intervals should stay zero-based half-open `[l, r)`, even if the judge statement is one-based inclusive.
- A "copy version" query usually just pushes an existing root index into the version array.
- Estimate memory before coding. A safe first bound is roughly:

$$
\text{initial tree size} + (\text{updates}) \cdot O(\log n)
$$

- The first starter here is intentionally narrow:
  - point assignment
  - range sum
  - persistent segment tree

Do not over-read it as a generic persistent library for all variants.

## References

- [cp-algorithms: Segment Tree, persistent section](https://cp-algorithms.com/data_structures/segment_tree.html)
- [USACO Guide: Persistent Data Structures](https://usaco.guide/adv/persistent?lang=java)
- [CSES: Range Queries and Copies](https://cses.fi/problemset/task/1737)
- [SPOJ: MKTHNUM](https://www.spoj.com/problems/MKTHNUM/)
- [Library Checker: Persistent Union Find](https://judge.yosupo.jp/problem/persistent_unionfind)

## In This Repo

- [Persistent Data Structures ladder](../../../practice/ladders/data-structures/persistent-data-structures/README.md)
- [Persistent Data Structures hot sheet](../../../notebook/persistent-data-structures-hot-sheet.md)
- [Range Queries and Copies note](../../../practice/ladders/data-structures/persistent-data-structures/rangequeriesandcopies.md)
- [starter template](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/persistent-segment-tree-point-set-sum.cpp)
- compare points:
  - [Segment Tree](../segment-tree/README.md)
  - [DSU Rollback / Offline Dynamic Connectivity](../dsu-rollback/README.md)
