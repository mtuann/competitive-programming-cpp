# Convex Hull Trick / Li Chao Tree

This topic is about the DP and optimization lane where a transition becomes:

$$
dp[i] = \text{base}[i] + \min_j (m_j x_i + b_j)
$$

or the analogous maximum form.

The important shift is:

- previous states stop looking like "states"
- they become **lines**
- the current state becomes one **query point**

That line-view is what people usually mean by `Convex Hull Trick` in contest discussion.

For this repo, the first exact starter in the family is a **Li Chao tree**:

- lines are added online
- queries arrive online
- the `x` domain is known and discrete
- no monotonicity assumptions are needed

## At A Glance

- **Use when:** the expensive part of the recurrence is a min/max over affine functions `m x + b`
- **Core worldview:** each previous candidate becomes one line; each current state is just "query at `x_i`"
- **Main tools:** monotone hull / deque CHT, static hull + binary search, Li Chao tree
- **Typical complexity:** `O(log C)` per insertion/query for Li Chao, where `C` is the size of the `x` domain
- **Main trap:** jumping straight to Li Chao before checking whether a lighter monotone-hull route already fits

Strong contest signals:

- `dp[i] = min_j (a_j * x_i + b_j)` or max variant
- each previous state contributes one line
- current state contributes one query `x`
- the statement looks like "choose previous checkpoint / machine / monster / break point" and the algebra turns affine

Strong anti-cues:

- the recurrence is not affine after expansion
- you still have a quadratic term that depends on both `i` and `j`
- the real optimization is divide-and-conquer DP, Knuth, or monotone queue rather than line containers
- one static scan with monotone slopes and monotone queries is enough, so a full Li Chao tree is overkill

## Prerequisites

- [DP Foundations](../foundations/README.md)
- [Reasoning, Invariants, And Proof Discipline](../../foundations/reasoning/README.md)
- [Binary Search](../../foundations/patterns/binary-search/README.md) helps, because many hull explanations are really about one crossing point

Helpful neighboring topics:

- [Algorithm Engineering](../../advanced/algorithm-engineering/README.md) once constant factors and exact starter choice matter
- [Line sweep / event ordering instincts](../../geometry/sweep-line/README.md) as a compare point for "one structure over an ordered domain"

## Problem Model And Notation

The canonical form is:

$$
dp[i] = c_i + \min_j (m_j x_i + b_j)
$$

or:

$$
dp[i] = c_i + \max_j (m_j x_i + b_j)
$$

where:

- `x_i` is the query point coming from the current state
- each previous state `j` contributes one line:

$$
y = m_j x + b_j
$$

The transformation step is usually:

1. start from a quadratic-looking or pairwise recurrence
2. expand and separate all `j`-only terms into slope/intercept
3. isolate the current-state parameter as the query `x_i`

Once that works, the recurrence is no longer "compare all previous states."

It becomes:

- insert lines
- query best line at `x_i`

## From Brute Force To The Right Idea

### Brute Force

If we directly evaluate:

$$
\min_{j < i} (m_j x_i + b_j)
$$

for every `i`, we spend:

$$
O(n^2)
$$

That is usually too slow once `n` reaches `2 \cdot 10^5`.

### Structural Observation

Each previous candidate is not arbitrary. It is an affine function:

$$
f_j(x) = m_j x + b_j
$$

So the set of candidates is really a set of lines.

For one fixed query `x_i`, we only want:

- the lowest line at `x_i`
- or the highest line at `x_i`

This means the optimization layer is geometric:

- maintain an envelope of lines
- answer best-value queries at points

### Why There Are Several Variants

Not every line-container problem needs the same machinery.

There are three common lanes:

1. **Monotone hull / deque CHT**
   - slopes inserted in monotone order
   - query `x` values are also monotone
   - often `O(1)` amortized per operation

2. **Static hull + binary search**
   - all lines are known first, or the offline order is manageable
   - queries can use crossing-order logic

3. **Li Chao tree**
   - online line insertion
   - online queries
   - no monotonicity assumptions
   - known query domain

For this repo, the first shipped starter is lane `3`, because it is the safest general exact route for many contest problems once the affine transformation is real.

## Core Invariant And Why It Works

## 1. Li Chao Node Meaning

Each node owns one interval:

$$
[L, R]
$$

on the `x` domain.

It stores one line with the invariant:

```text
the stored line is the best known line at the midpoint of this interval
```

That midpoint rule is the whole data structure.

## 2. Why One Midpoint Is Enough To Decide A Swap

Suppose the node already stores line `old`, and we insert line `nw`.

At midpoint `mid`, exactly one of them is better:

- if `nw(mid)` is better, we swap
- otherwise the old line stays

After that swap/no-swap, the node again satisfies:

```text
stored line wins at mid
```

So the node contract remains true.

## 3. Where Can The Losing Line Still Matter?

Two lines can cross at most once.

So if the losing line is worse at `mid`, it can still become better only on **one side**:

- left side
- or right side

That is why Li Chao recurses into only one child per insertion level.

The side is determined by comparing values at:

- `L`
- `mid`

or equivalently `mid` and `R`.

## 4. Why Query Works

For a query point `x`, we walk from root to the leaf interval containing `x`.

Every node on that path stores one line that is best at its midpoint, and some of those lines may still be the true winner at `x`.

So the answer is:

- minimum or maximum over all lines stored along that path

That gives:

$$
O(\log C)
$$

per query, where `C` is the number of integer points in the domain.

## 5. Why Complexity Stays Logarithmic

At each depth:

- one insertion recurses into at most one child
- one query descends into exactly one child

So both operations visit only one root-to-leaf path.

For an integer domain `[x_{min}, x_{max}]`, the depth is:

$$
O(\log (x_{max} - x_{min} + 1))
$$

That is the standard Li Chao complexity.

## Variant Chooser

### Use A Monotone Hull / Deque CHT When

- slopes are added in monotone order
- query `x` values are also monotone
- you want the lightest constant-factor route

This is the clean lane behind problems like `Monster Game I`.

### Use Li Chao Tree When

- lines are added online
- queries arrive online
- slope order is arbitrary
- query order is arbitrary
- the `x` domain is known

This is the starter shipped in this repo and the lane used by [Monster Game II](../../../practice/ladders/dp/cht-li-chao/monstergame2.md).

### Use Segment Li Chao When

- each line is active only on a subrange of `x`
- the full-domain line assumption is false

This is the next layer after the starter, not the starter itself.

### Do Not Use CHT / Li Chao When

- the recurrence has not truly become affine
- the optimization is over intervals or partitions rather than lines
- divide-and-conquer DP or Knuth is the real family

## Worked Examples

### Example 1: Monster Game II

The statement gives monsters with:

- strength `s_i`
- next skill factor `f_i`

If `dp[i]` is the minimum time after killing monster `i`, then every previous kill `j` offers:

$$
dp[j] + f_j \cdot s_i
$$

That is exactly a line:

$$
y = f_j x + dp[j]
$$

queried at:

$$
x = s_i
$$

The initial skill factor `x_0` becomes the first line:

$$
y = x_0 \cdot x + 0
$$

Because both strengths and next skill factors are arbitrary in `Monster Game II`, the safe exact starter is Li Chao.

### Example 2: Why Monster Game I Is Different

In `Monster Game I`:

- strengths are nondecreasing
- skill factors are nonincreasing

So:

- query `x` values are monotone
- inserted slopes are monotone

That means a deque hull is enough.

This is why the topic title is `CHT / Li Chao` rather than just `Li Chao`:

- same affine DP family
- different exact starter depending on order structure

### Example 3: Max Instead Of Min

If the problem asks for:

$$
\max_j (m_j x_i + b_j)
$$

then either:

- flip all comparisons in the Li Chao tree
- or negate lines and answers to reuse a min-structure

The repo starter keeps only the min version to stay small and explicit.

## Algorithm And Pseudocode

```text
insert_line(new):
    at node interval [L, R], let mid = (L + R) / 2
    keep at this node the line that is better at mid
    the losing line can still matter on at most one side
    recurse only into that side

query(x):
    walk root -> leaf containing x
    answer = best among all node-stored lines on that path
```

For DP:

```text
insert initial line
for each state i in order:
    dp[i] = query(x_i) + base_i
    insert the line generated by state i
```

## Implementation Notes

- The repo starter is:
  - `min` only
  - full-domain line insertion only
  - integer `x` domain `[x_low, x_high]`
- Use `__int128` inside line evaluation if `m * x + b` may approach `1e18`.
- Check whether the problem wants:
  - full-domain line insertion
  - segment-limited insertion
  - minimum or maximum
- Do not hardcode a Li Chao tree before checking whether monotone hull is simpler.
- Keep the initial line explicit; many bugs come from forgetting the base transition.

## Practice Archetypes

- affine DP with arbitrary line/query order
- online line insertion + point query
- "previous state becomes a line" optimizations
- bounded integer query domain with exact min/max

## References

- [CP-Algorithms: Convex Hull Trick and Li Chao Tree](https://cp-algorithms.com/geometry/convex_hull_trick.html)
- [CSES: Monster Game I](https://cses.fi/problemset/task/2084)
- [CSES: Monster Game II](https://cses.fi/problemset/task/2085)
- [Library Checker: Line Add Get Min](https://judge.yosupo.jp/problem/line_add_get_min)
- [Library Checker: Segment Add Get Min](https://judge.yosupo.jp/problem/segment_add_get_min)

## Repo Anchors

- DP routing: [DP overview](../README.md)
- Retrieval layer: [DP cheatsheet](../../../notebook/dp-cheatsheet.md)
- Exact hot sheet: [CHT / Li Chao hot sheet](../../../notebook/cht-hot-sheet.md)
- Exact starter: [li-chao-tree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/li-chao-tree.cpp)
- Flagship rep: [Monster Game II](../../../practice/ladders/dp/cht-li-chao/monstergame2.md)
- Compare point: [Lazy Segment Tree](../../data-structures/lazy-segment-tree/README.md) for "same tree shape, very different invariant"
