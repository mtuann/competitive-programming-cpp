# ODT / Chtholly

This lane is for problems where the live state is better described as an
**ordered partition of disjoint constant intervals** than as one point-by-point
array.

The repo keeps the first route deliberately narrow:

- one `std::set` keyed by interval left endpoint
- one `split(x)` primitive that isolates boundaries before every range touch
- one interval-collapsing `assign(l, r, v)` operation
- range walks like `add`, `kth`, or `pow-sum` only when the data is
  **random / soft** or repeated assigns keep the interval count under control

This page is about the contest family commonly called:

- `ODT`
- `Chtholly Tree`
- piecewise-constant interval partition with ordered-set splits

It is **not** a magic worst-case replacement for:

- [Lazy Segment Tree](../lazy-segment-tree/README.md)
- [Segment Tree Beats](../segment-tree-beats/README.md)

If the statement needs hard worst-case guarantees under adversarial updates,
stay with segment-tree families.

## At A Glance

- **Use when:** range assign is the operation that keeps collapsing equal-value
  runs, and the whole problem can be expressed as walking the current interval
  partition
- **Core worldview:** store disjoint constant segments in order and split only
  at the boundaries you are about to touch
- **Main tools:** `split`, `assign`, interval walk on `[l, r]`, and one honest
  complexity story about how many segments are touched
- **Typical route here:** `std::set` of nodes `[l, r, value]`
- **Main trap:** pretending this gives clean worst-case guarantees just because
  the code is short

Strong contest signals:

- "set every value in `[l, r]` to `x`"
- many values become equal on large ranges
- answers can be computed by iterating over the **current runs**
- the canonical statement is [896C - Willem, Chtholly and Seniorious](https://codeforces.com/problemset/problem/896/C?mobile=true)

Strong anti-cues:

- the range update/query family needs hard guarantees on adversarial input
- the real invariant is prefix sums or one monoid over all points
- there is no collapsing assignment operation to keep the run count healthy
- the task is already closed by [Lazy Segment Tree](../lazy-segment-tree/README.md)
  or [Segment Tree Beats](../segment-tree-beats/README.md)

## Prerequisites

- [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md) just enough to
  trust ordered-set iteration and iterator discipline
- [Lazy Segment Tree](../lazy-segment-tree/README.md) for the contrast between
  "hard guaranteed range structure" and "soft interval partition"

Helpful compare points:

- [Lazy Segment Tree](../lazy-segment-tree/README.md): use this when the range
  algebra is real and you need hard online guarantees
- [Segment Tree Beats](../segment-tree-beats/README.md): use this when the task
  is clamp-style range updates, not interval partitioning
- [Offline Tricks](../offline-tricks/README.md): use this first if all queries
  are reorderable and a heavy online structure is avoidable

## Problem Model And Notation

Think of the array as a partition of disjoint segments:

$$
[l_1, r_1], [l_2, r_2], \dots, [l_k, r_k]
$$

where every segment stores one constant value:

$$
v_1, v_2, \dots, v_k
$$

The invariant is:

```text
each node represents one interval on which the array is constant
```

The standard representation is:

```cpp
struct Node {
    int l, r;
    mutable long long v;
    bool operator<(const Node& other) const { return l < other.l; }
};
set<Node> odt;
```

The key primitive is:

```text
split(x)
```

which isolates the node that starts exactly at `x` by cutting the old segment
if needed.

Once both boundaries are isolated, every range operation becomes:

```text
split(r + 1), split(l), then erase / assign / walk [itl, itr)
```

## From Brute Force To The Right Idea

### Brute Force

Keep the whole array explicitly and apply every range operation point by point.

That is often:

- easy to reason about
- too slow once `n` and `m` are both large

### The First Shift

The statement is not really about every point independently.

It is often about the fact that large stretches of the array keep sharing the
same value.

So instead of storing:

```text
a[1], a[2], ..., a[n]
```

store only the current runs.

### The Second Shift

Once the state is one ordered partition, every range operation becomes:

1. isolate the touched boundaries
2. iterate only over the runs inside them
3. erase / mutate / aggregate those runs

That is the whole ODT worldview.

## Core Technique

### 1. `split(pos)`

`split(pos)` is the real primitive.

If there is already a node starting at `pos`, return it.

Otherwise find the node `[l, r]` containing `pos`, remove it, and replace it
with:

- `[l, pos - 1]`
- `[pos, r]`

with the same value.

### 2. `assign(l, r, value)`

This is the interval-collapsing operation that makes the route viable.

Do:

1. `itr = split(r + 1)`
2. `itl = split(l)`
3. erase all nodes in `[itl, itr)`
4. insert one node `[l, r, value]`

This is the cleanest route and the one the starter is built around.

### 3. Range Walks

For operations like:

- add a delta to all values in `[l, r]`
- collect all segments in `[l, r]` and find the `k`-th value
- compute $\sum value^{x} \cdot length \pmod{mod}$

you do the same boundary isolation and then walk the interval slice.

This part is where the route becomes **honestly heuristic**:

- if the touched slice has many nodes, the operation is expensive
- if range assigns or random data keep node counts small, it works well

## Complexity And Honesty

For one operation touching `k` current segments:

- boundary isolation costs `O(log S)` each, where `S` is the number of stored
  nodes
- the range walk costs `O(k)`
- `kth` adds sorting on the touched segments

So the true cost is not:

```text
always O(log n)
```

It is:

```text
O(log S + k)
```

or more, depending on the per-segment work.

That is why this lane must be used honestly:

- **good fit:** range assigns keep collapsing runs, or the statement is
  randomized / soft like CF896C
- **bad fit:** adversarial updates can keep fragmenting the partition forever

## Exact Starter Route In This Repo

- Topic: this page
- Hot sheet: [ODT / Chtholly hot sheet](../../../notebook/odt-chtholly-hot-sheet.md)
- Starter template: [`odt-interval-set.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/odt-interval-set.cpp)
- Flagship anchor: [Willem, Chtholly and Seniorious](../../../practice/ladders/data-structures/odt-chtholly/willemchthollyandseniorious.md)

The starter is intentionally honest:

- it is one `std::set` interval-partition route
- it exposes `split`, `assign`, `add`, `kth`, and power-sum over the current
  partition
- it does **not** promise good worst-case behavior on arbitrary updates
- it is the right first snippet only when the interval-count story is favorable

## Flagship Modeling: Willem, Chtholly and Seniorious

The cleanest canonical rep for this lane is:

- [Willem, Chtholly and Seniorious](../../../practice/ladders/data-structures/odt-chtholly/willemchthollyandseniorious.md)

Why it fits:

- the statement itself is the source of the name `Chtholly Tree`
- `assign(l, r, x)` is the interval-collapsing operation
- the other operations are exactly range walks over the current partition
- the data is generator-driven and intentionally soft enough for this route

One strong deterministic bridge after that is:

- [915E - Physical Education Lessons](https://codeforces.com/problemset/problem/915/E)

where interval assign plus counting is the real invariant, even without the
full CF896C random-data flavor.

## Main Pitfalls

- calling `split(l)` before `split(r + 1)` and invalidating the iterator story
- mutating the interval boundaries inside a `set` node
- treating ODT as a guaranteed replacement for segment trees
- forgetting that `kth` and power-sum are over the **current interval slice**,
  not over original positions one by one
- using this route when there is no interval-collapsing assignment to control
  fragmentation

## Practice

### First In Repo

- [Willem, Chtholly and Seniorious](../../../practice/ladders/data-structures/odt-chtholly/willemchthollyandseniorious.md)

### Strong Follow-Ups

- [915E - Physical Education Lessons](https://codeforces.com/problemset/problem/915/E)
- [CF896C - Willem, Chtholly and Seniorious](https://codeforces.com/problemset/problem/896/C?mobile=true)

## Retrieval Map

- quick recall -> [ODT / Chtholly hot sheet](../../../notebook/odt-chtholly-hot-sheet.md)
- reusable route -> [`odt-interval-set.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/odt-interval-set.cpp)
- broader chooser -> [Data structures cheatsheet](../../../notebook/data-structures-cheatsheet.md)
- routing layer -> [Template Library](../../../template-library.md), [Build Kit](../../../docs/build-kit.md)

## References And Repo Anchors

Reference / practice:

- [OI Wiki - ODT / Chtholly](https://oi-wiki.org/misc/odt/)
- [Codeforces Round #449 Editorial](https://codeforces.com/topic/56423/en2?mobile=false)
- [CF896C - Willem, Chtholly and Seniorious](https://codeforces.com/problemset/problem/896/C?mobile=true)
- [CF915E - Physical Education Lessons](https://codeforces.com/problemset/problem/915/E)

Repo anchors:

- [ODT / Chtholly hot sheet](../../../notebook/odt-chtholly-hot-sheet.md)
- [`odt-interval-set.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/odt-interval-set.cpp)
- [Willem, Chtholly and Seniorious](../../../practice/ladders/data-structures/odt-chtholly/willemchthollyandseniorious.md)
