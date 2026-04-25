# Lazy Segment Tree

Lazy segment tree is the first real answer when:

- updates hit whole intervals, not single points
- queries still ask for interval aggregates online
- the update effect can be summarized at a node without touching every leaf immediately

It is best learned as an extension of the ordinary [Segment Tree](../segment-tree/README.md), not as a separate black box.

The mindset is:

1. keep the same segment-tree interval invariant
2. add one `pending update tag` per node
3. postpone pushing that tag to children until a later operation actually needs them

## At A Glance

- **Use when:** range updates and range queries are interleaved online, and a whole covered segment can absorb the update through a closed-form node adjustment
- **Core worldview:** a node can stay correct for its whole segment even if its children are temporarily stale, as long as the pending update tag records what they still owe
- **Main tools:** segment sums or other mergeable summaries, lazy tags, `apply`, `push`, `pull`
- **Typical complexity:** `O(log n)` per update/query
- **Main trap:** forgetting that “lazy” means `node correct, children deferred`, not “skip correctness until later”

Strong contest signals:

- "add `x` to every element in `[l, r]`, then answer sums online"
- "many long interval updates plus many interval queries"
- "point-update segment tree would touch too many leaves"
- "difference arrays would work only if all queries came after all updates"

Strong anti-cues:

- all updates are known first and you only need the final array -> [Difference Arrays](../../foundations/patterns/difference-arrays/README.md)
- updates are range add but queries are only point queries -> difference-array / Fenwick routes are lighter
- the statement needs both `range assign` and `range add`, but you only have a simple additive tag skeleton
- the statement now asks for `range chmin` / `range chmax`, so the update family is no longer one simple lazy-tag algebra -> compare [Segment Tree Beats](../segment-tree-beats/README.md)
- the real structure is a tree, so you first need Euler flattening or HLD before any array lazy tree matters

## Prerequisites

- [Segment Tree](../segment-tree/README.md)
- [Difference Arrays](../../foundations/patterns/difference-arrays/README.md)
- [Fenwick Tree](../fenwick-tree/README.md) for the lighter neighboring range-update lanes

Helpful neighboring topics:

- [Heavy-Light Decomposition](../../graphs/hld/README.md) when the lazy tree lives on decomposed paths
- [Trees](../../graphs/trees/README.md) once subtree flattening becomes the real reduction

## Problem Model And Notation

Assume an array:

$$
a_0, a_1, \dots, a_{n-1}
$$

We want to support:

- `range_add(l, r, delta)` on a half-open interval `[l, r)`
- `range_sum(l, r)` on the same interval convention

The ordinary segment-tree invariant is still:

$$
\text{sum}[v] = \sum_{i=L}^{R-1} a_i
$$

for the interval `[L, R)` owned by node `v`.

The new ingredient is a lazy tag:

$$
\text{lazy}[v]
$$

meaning:

```text
every element in this segment still owes +lazy[v] before the children are individually up to date
```

The key point is that the node itself can already be correct even while the children are deferred.

That is the lazy-propagation contract.

## From Brute Force To The Right Idea

### Brute Force

Suppose each update says:

- add `delta` to every index in `[l, r)`

and each query asks:

- sum of `[l, r)`

The naive approach does:

- range update: `O(r - l)`
- range query: `O(r - l)`

This is too slow once both happen many times.

### Why A Basic Segment Tree Is Still Too Eager

An ordinary point-update segment tree helps only if each update changes one leaf.

If you try to implement `range_add(l, r, delta)` by descending to every affected leaf, the cost becomes:

$$
O((r-l)\log n)
$$

which defeats the whole purpose.

So the real question is:

```text
can one fully covered node be updated in O(1) without touching its children yet?
```

For range add + range sum, yes.

If a node covers `[L, R)` and we add `delta` to every element in that segment, then:

$$
\text{sum}[v] \leftarrow \text{sum}[v] + \delta \cdot (R-L)
$$

So one node can absorb the whole update immediately.

### Why Difference Arrays Are Not Enough

Difference arrays also compress range adds, but only in the offline sense:

- you accumulate updates
- then reconstruct later

They break as soon as queries are interleaved with updates.

Lazy segment tree is the online version of the same compression instinct:

- compress the update at the largest fully covered segments
- defer detail work until a later query/update actually needs the children

## Core Invariant And Why It Works

## 1. Node Meaning

For every node `v` owning interval `[L, R)`:

```text
sum[v] is the true sum of the whole interval [L, R) after all updates already applied to that node
```

This must stay correct at all times.

The children are allowed to lag behind if the lazy tag explains that lag.

## 2. Lazy Tag Meaning

The lazy tag `lazy[v] = x` means:

```text
every leaf in the segment of v still needs +x before the children become individually up to date
```

Equivalently:

- the parent summary already includes this effect
- the children summaries may not
- pushing the tag later will repair that mismatch

So “lazy” never means “temporarily wrong node value.”

It means:

- parent correct
- descendants deferred

## 3. Full-Cover Update

If the update interval fully covers node `v` on `[L, R)`, then we do **not** recurse.

Instead:

$$
\text{sum}[v] \leftarrow \text{sum}[v] + \delta \cdot (R-L)
$$

and:

$$
\text{lazy}[v] \leftarrow \text{lazy}[v] + \delta
$$

Why is that enough?

Because every element of the segment got the same delta, so the aggregate can be updated in closed form, and the children can wait.

This is the entire reason lazy propagation exists.

## 4. Push

When an operation partially overlaps node `v`, we cannot keep the children stale anymore.

So before descending, we `push(v)`:

- apply the pending tag to the left child
- apply the pending tag to the right child
- clear the parent's tag

After the push:

- both children become correct for their full segments
- the parent tag becomes neutral again

Then recursion can safely continue.

## 5. Pull

After partial recursion returns, recompute:

$$
\text{sum}[v] = \text{sum}[left] + \text{sum}[right]
$$

This is exactly the same pull step as an ordinary segment tree.

So lazy propagation adds one extra discipline:

- `apply`
- `push`

but does **not** replace the ordinary merge invariant.

## 6. Why Query Still Works

Range query uses the same three-way overlap split:

- no overlap -> return identity
- full cover -> use `sum[v]` directly
- partial overlap -> `push`, recurse, merge

This is sound because whenever we use `sum[v]` directly, it is already the true answer for the whole segment.

Whenever we need finer granularity, `push` makes the children truthful before we inspect them.

## 7. Why Complexity Stays Logarithmic

Each operation only visits nodes on `O(log n)` root-to-boundary paths plus a logarithmic number of fully covered segments.

At each visited node, the extra lazy work is `O(1)`:

- maybe one push
- maybe one pull

So:

- range add: `O(log n)`
- range sum: `O(log n)`

The point of laziness is not asymptotically faster than a basic segment tree on point updates.

The point is that range updates stop exploding into leaf-by-leaf work.

## Variant Chooser

| If the statement asks... | Tag type | First route |
| --- | --- | --- |
| add one delta to every value in a range, then ask sums | additive tag | this page + range-add/sum starter |
| assign every value in a range to `x`, then ask sums | overwrite tag with precedence | topic first, then custom assign-capable lazy tree |
| both range add and range assign exist | layered tag semantics | do **not** drop in the add-only starter unchanged |
| affine transforms on a range | function composition tag | ACL `lazy_segtree` lens, then a specialized implementation |
| subtree/path updates on a tree | lazy tag on a flattened/decomposed array | Euler/HLD first, then lazy tree |

The repo starter for this lane is intentionally narrow:

- `range add`
- `range sum`

That is the cleanest first lazy tree.

## Worked Examples

### Example 1: Why A Fully Covered Node Can Stop Early

Suppose a node covers `[2, 6)` and currently stores:

$$
3 + 1 + 4 + 2 = 10
$$

If the update is:

$$
[2, 6) += 5
$$

then the new sum is:

$$
10 + 5 \cdot 4 = 30
$$

So the node can be fixed immediately in `O(1)`.

There is no need to touch each child yet.

That is the first mental checkpoint for lazy propagation:

```text
full cover means “repair here and defer below”
```

### Example 2: HORRIBLE

In [HORRIBLE - Horrible Queries](../../../practice/ladders/data-structures/lazy-segment-tree/horriblequeries.md), the operations are exactly:

- add `v` to every index in `[p, q]`
- ask the sum on `[p, q]`

The statement is one-based inclusive, but internally the reusable form is:

- update `[p - 1, q)`
- query `[p - 1, q)`

This is the cleanest flagship note for this lane because:

- the update type matches the starter exactly
- there is no extra assignment tag
- the only real new idea is lazy propagation itself

### Example 3: Why `Range Updates and Sums` Is Already A Next Variant

In [Range Updates and Sums](https://cses.fi/problemset/task/1735), one update adds while another assigns.

That changes the tag logic completely:

- `assign x` must override any earlier pending add
- `add d` after `assign x` becomes `assign (x + d)` at the same node

So this problem is not just “more tests for the same starter.”

It is the first strong proof that lazy trees are about **tag semantics**, not only about recursion boilerplate.

## Complexity And Tradeoffs

For the repo starter `range add + range sum`:

- build: `O(n)`
- range add: `O(log n)`
- range sum: `O(log n)`
- memory: `O(n)` or `O(4n)` depending on layout

Practical tradeoffs:

| Structure | Best when | Update | Query | Main limitation |
| --- | --- | --- | --- | --- |
| [Difference Arrays](../../foundations/patterns/difference-arrays/README.md) | all range adds known first | `O(1)` per offline mark | reconstruct later | cannot answer online interval queries |
| [Fenwick Tree](../fenwick-tree/README.md) | additive prefix/range patterns with lighter formulas | `O(log n)` | `O(log n)` | much narrower update/query family |
| [Segment Tree](../segment-tree/README.md) | point updates + general range queries | `O(log n)` | `O(log n)` | range updates still need leaf work |
| Lazy Segment Tree | online range updates + range queries | `O(log n)` | `O(log n)` | heavier implementation and tag semantics matter |

## Pseudocode

```text
apply(v, seg_len, delta):
    sum[v] += delta * seg_len
    lazy[v] += delta

push(v, left_len, right_len):
    if lazy[v] == 0:
        return
    apply(left child of v, left_len, lazy[v])
    apply(right child of v, right_len, lazy[v])
    lazy[v] = 0

range_add(v, L, R, ql, qr, delta):
    if qr <= L or R <= ql:
        return
    if ql <= L and R <= qr:
        apply(v, R - L, delta)
        return
    push(v, mid - L, R - mid)
    recurse on children
    sum[v] = sum[left] + sum[right]

range_sum(v, L, R, ql, qr):
    if qr <= L or R <= ql:
        return 0
    if ql <= L and R <= qr:
        return sum[v]
    push(v, mid - L, R - mid)
    return range_sum(left child) + range_sum(right child)
```

## Implementation Notes

- Keep one internal interval convention. The repo starter uses zero-based half-open `[l, r)`.
- `apply` should be the only place that changes both `sum` and `lazy` together.
- `push` should happen only before partial descent, not blindly on every visit.
- Use `long long`; a range add can multiply by segment length.
- For multiple test cases, fully reset both `sum` and `lazy`.
- If the statement later adds `range assign`, do not bolt it onto an additive tag casually. Redesign the tag semantics first.

## Practice Archetypes

- direct `range add + range sum` online tasks
- subtree add / subtree sum after Euler flattening
- HLD path updates with a lazy base structure
- advanced variants where the real challenge is composing tags correctly

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Primary / official:

- [AtCoder ACL lazy_segtree](https://atcoder.github.io/ac-library/production/document_en/lazysegtree.html)
- [AtCoder ACL appendix on Segtree / LazySegtree](https://atcoder.github.io/ac-library/production/document_en/appendix.html)

Reference:

- [cp-algorithms segment tree](https://cp-algorithms.com/data_structures/segment_tree.html)
- [OI Wiki segment tree](https://en.oi-wiki.org/ds/seg/)

Repo anchors:

- [Segment Tree](../segment-tree/README.md)
- [Lazy Segment Tree hot sheet](../../../notebook/lazy-segment-tree-hot-sheet.md)
- [Lazy Segment Tree ladder](../../../practice/ladders/data-structures/lazy-segment-tree/README.md)
- [HORRIBLE - Horrible Queries](../../../practice/ladders/data-structures/lazy-segment-tree/horriblequeries.md)
