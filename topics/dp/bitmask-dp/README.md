# Bitmask DP

Bitmask DP is the standard exact technique when the real state is:

- which items are already used
- which vertices are already visited
- which colors / groups / jobs are already covered

and the number of such items is small enough that

$$
2^n
$$

states are still feasible.

This is one of the most important contest patterns for "small `n`, huge search tree" problems. The brute force is usually `n!` or "all partitions / all permutations", but once you realize that many histories share the same remaining future, those histories collapse into the same subset state.

## At A Glance

- **Use when:** `n` is small, typically around `15` to `22`, and the state naturally is a subset
- **Most common states:** `dp[mask]`, `dp[mask][last]`
- **Canonical examples:** assignment DP, TSP / Hamiltonian DP, partition/subset-cover DP
- **Typical complexity:** `O(2^n)`, `O(n 2^n)`, or `O(n^2 2^n)`
- **Main trap:** storing more history than the future actually needs
- **Do not use when:** `n` is large enough that `2^n` is already dead on arrival, or the state really wants a graph/BFS/modeling view instead

## Problem Model And Notation

Assume the items are indexed

$$
0, 1, \dots, n-1.
$$

A mask is an integer whose binary expansion says which items are currently in the chosen set:

- bit `i` is `1` if item `i` is present
- bit `i` is `0` otherwise

So:

$$
\text{mask} \in [0, 2^n).
$$

The full set is usually written as

$$
full\_mask = (1 \ll n) - 1.
$$

Common operations:

$$
\text{contains}(mask, i) \iff (mask \,\&\, (1 \ll i)) \ne 0
$$

$$
\text{add}(mask, i) = mask \,|\, (1 \ll i)
$$

$$
\text{remove}(mask, i) = mask \,\hat{}\, (1 \ll i)
\quad \text{if } i \text{ is known to be present}
$$

The three most common meanings of a mask are:

1. **used / assigned items**
2. **visited vertices**
3. **already covered categories / colors / constraints**

The whole topic is about choosing the smallest state that still tells the future everything it needs.

## From Brute Force To The Right Idea

### Brute Force: Enumerate All Orders Or All Assignments

A typical subset-style problem begins with a search space like:

- all permutations of `n` items
- all ways to assign jobs to workers
- all ways to visit all vertices
- all ways to split items into groups

That often means:

$$
n!
$$

or some comparably explosive search tree.

For example, in TSP:

- brute force tries every visiting order
- complexity is factorial

That is far too large even for `n = 15`.

### Why Many Histories Are Equivalent

Suppose two partial solutions:

- have visited the same subset of cities
- and currently end at the same city

Then for every future continuation, the only thing that matters is:

- which cities are already done
- where you are now

The exact internal order that got you there is no longer relevant, except through the DP value you already computed.

That is the dynamic-programming collapse:

- many exponential histories
- one compact state

### The Two Canonical State Shapes

#### `dp[mask]`

Use this when the subset alone already determines what happens next.

Typical signal:

- the next step depends only on which items are already used
- not on the order they were chosen
- and not on a current endpoint or position

Examples:

- assignment by "how many jobs are already taken"
- set-cover style DP
- some partition DPs

#### `dp[mask][last]`

Use this when the future depends on:

- the chosen subset
- plus one distinguished last / current item

Typical signal:

- path or ordering structure matters
- transition cost depends on where you currently stand

Examples:

- TSP / Hamiltonian path
- shortest path visiting all special nodes
- sequence-building with adjacency costs

This is the most important fork to recognize quickly.

## Core Invariant And Why It Works

### The DP Principle

Bitmask DP works only if the state remembers exactly what the future needs.

That means:

- if two histories produce the same state
- then every legal future continuation from those histories has the same set of options and the same future scoring rule

When that is true, keeping only the best value for each state is safe.

### Why `dp[mask][last]` Is Enough For TSP-Style Problems

Let:

$$
dp[mask][v]
$$

be the minimum cost of visiting exactly the vertices in `mask` and ending at vertex `v`.

Why is this enough?

Because once you know:

- which vertices remain unvisited
- and the current endpoint `v`

every future extension cost depends only on those two pieces of information.

The earlier internal route matters only through its optimal total cost, which `dp[mask][v]` already stores.

That gives the standard recurrence:

$$
dp[mask][v]
=
\min_{u \in mask \setminus \{v\}}
\bigl(dp[mask \setminus \{v\}][u] + cost(u, v)\bigr).
$$

This is the classical Bellman / Held–Karp viewpoint.

### Why `dp[mask]` Is Enough For Assignment DP

In assignment DP, suppose:

- there are `n` workers
- there are `n` jobs
- the first `k = popcount(mask)` workers have already been assigned
- `mask` says which jobs are taken

Then the next worker index is determined automatically by `k`.

So you do not need to store it as a separate dimension:

- the mask already implies where you are in the process

That is the signal that `dp[mask]` is enough.

### State Minimality Matters

The most common conceptual bug is:

- storing extra data "just in case"

For example, if `mask` already determines the step number, then storing both:

- `mask`
- `used_count`

is redundant.

Redundant state often turns:

$$
O(n 2^n)
$$

into:

$$
O(n^2 2^n)
$$

for no gain.

## Complexity And Feasibility

This topic lives and dies by constraint reading.

### Common Sizes

- `2^20 ≈ 10^6`
- `20 * 2^20 ≈ 2 * 10^7`
- `20^2 * 2^20 ≈ 4 * 10^8`

These rough numbers are the mental calculator you need in contest.

### Typical Regimes

- `O(2^n)` is comfortable for `n <= 22` or so
- `O(n 2^n)` is often comfortable for `n <= 20`
- `O(n^2 2^n)` is usually for `n <= 18..20`, depending on constants and number of test cases

So the strongest signal is not just "subset exists." It is:

- subset exists
- and the constraints scream that only exponential-in-`n` with small `n` can fit

### Time-Memory Tradeoff

A table of size

$$
2^n \times n
$$

can already be large.

That means you should think early about:

- whether to store `int`, `long long`, or `bool`
- whether rolling arrays are possible
- whether the state graph can be traversed in another way

## Variant Chooser

### Choose `dp[mask]` When

- the subset alone determines the progress
- the next position is implicit from `popcount(mask)`
- or the answer is "best way to cover / assign exactly this set"

Canonical examples:

- assignment DP
- minimum cost to cover colors
- some partition DPs over submasks

### Choose `dp[mask][last]` When

- there is a current endpoint or current item
- transition cost depends on where you are
- order matters, but only through the last position

Canonical examples:

- TSP
- Hamiltonian path counting / optimization
- visit-all-special-nodes path problems

### Think About BFS-On-Subsets Instead When

- the objective is minimum number of steps / moves
- each transition has uniform cost
- and the state graph is naturally unweighted

Then the right tool may be:

- BFS over `(mask, node)`

instead of DP.

### Think About Meet-In-The-Middle Instead When

- the subset state is the real structure
- but `2^n` for the full `n` is too large

This often happens around:

- `n ≈ 35..45`

Then splitting into two halves may be much better than a full subset DP.

### Think About SOS / Subset Transforms Only After Basic Bitmask DP

Some heavier techniques iterate over:

- all submasks of every mask
- zeta / mobius transforms
- SOS DP

Those belong to the next layer. First master:

- `dp[mask]`
- `dp[mask][last]`
- ordinary submask iteration

## Worked Examples

### Example 1: Assignment DP With `dp[mask]`

Suppose worker `k` must be assigned one unused job.

Let:

$$
dp[mask] = \text{minimum cost after assigning the first } popcount(mask) \text{ workers to the jobs in } mask.
$$

Then:

- if `mask` already contains `j`, job `j` is unavailable
- otherwise assign the next worker to job `j`

So the transition is:

$$
dp[mask \cup \{j\}]
=
\min\bigl(dp[mask \cup \{j\}], dp[mask] + cost[k][j]\bigr),
$$

where

$$
k = popcount(mask).
$$

This is the key bitmask-DP lesson:

- the step number is not stored explicitly
- it is recovered from the subset size

### Example 2: TSP / Held–Karp With `dp[mask][last]`

Let:

$$
dp[mask][v]
$$

be the minimum cost of starting from a fixed source, visiting exactly the set `mask`, and ending at `v`.

Then the final edge into `v` must come from some `u` in

$$
mask \setminus \{v\}.
$$

So:

$$
dp[mask][v]
=
\min_{u \in mask \setminus \{v\}}
\bigl(dp[mask \setminus \{v\}][u] + dist[u][v]\bigr).
$$

This is the classical subset-DP recurrence. It replaces factorial search over visiting orders by one DP state per `(subset, endpoint)`.

The important modeling lesson is:

- if you remove `last`, the future transition cost is no longer determined
- so `dp[mask]` alone is too weak here

### Example 3: Cover-Colors Or Keeper-State DP

In problems like [VMMARBLE](../../../practice/ladders/dp/bitmask-dp/vmmarble.md), the mask means:

- which colors already have at least one keeper

That is not a path problem. There is no meaningful `last`.

So the correct state is a pure coverage DP:

$$
dp[mask].
$$

This is a good reminder that bitmask DP is a family of subset-state designs, not only TSP.

### Example 4: Submask Partition DP

Sometimes you want to split a mask into:

- one chosen submask
- the rest

Then the canonical loop is:

```text
for (sub = mask; sub; sub = (sub - 1) & mask)
```

This enumerates all nonempty submasks of `mask`.

It is powerful, but dangerous:

- inside an outer loop over all masks, it may cost `O(3^n)` overall

So use it deliberately, not automatically.

## Algorithm And Pseudocode

Repo starter template:

- [bitmask-subset-iterate.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/bitmask-subset-iterate.cpp)

### Generic Forward `dp[mask]`

```text
dp[*] = INF
dp[0] = base

for mask from 0 to (1 << n) - 1:
    if dp[mask] is unreachable:
        continue

    determine what the next choice means for this mask

    for each item bit not in mask:
        next_mask = mask | (1 << bit)
        relax dp[next_mask] from dp[mask]
```

This increasing-mask order is valid in many forward subset DPs because every transition adds bits, so dependencies always come from smaller masks.

### Generic Held–Karp Style `dp[mask][last]`

```text
dp[*][*] = INF
dp[1 << start][start] = 0

for mask from 0 to (1 << n) - 1:
    for last from 0 to n - 1:
        if last not in mask:
            continue
        if dp[mask][last] is unreachable:
            continue

        for nxt from 0 to n - 1:
            if nxt already in mask:
                continue
            next_mask = mask | (1 << nxt)
            relax dp[next_mask][nxt]
```

For Hamiltonian **path** problems, the answer is usually:

$$
\min_v dp[full\_mask][v].
$$

For Hamiltonian **cycle / tour** problems such as classical TSP, you still need to close the loop:

$$
\min_v \bigl(dp[full\_mask][v] + dist[v][start]\bigr).
$$

### Enumerating Submasks

```text
sub = mask
while sub > 0:
    use sub
    sub = (sub - 1) & mask
```

This visits every nonzero submask exactly once.

## Implementation Notes

### 1. `1 << n` Needs Type Discipline

If `n` can approach `31`, then `1 << n` on signed `int` is a trap.

Contest-safe habits:

- use `1 << n` only when `n` is small and clearly safe
- otherwise use `1LL << n`

For typical bitmask DP limits around `n <= 20`, `int` masks are usually fine, but it is still worth being explicit.

Also remember the semantic distinction:

- `1 << bit` means the singleton subset containing `bit`
- `(1 << n) - 1` means the full subset of all `n` items

### 2. `mask` Meaning Must Be A Full Sentence

Before writing code, you should be able to say:

- "`mask` means these jobs are already assigned"
- "`mask` means these cities are already visited"
- "`mask` means these colors are already covered"

If you cannot say that cleanly, your transition logic will drift.

### 3. Decide Whether You Add A Bit Or Remove A Bit

Both directions are valid:

- grow from smaller masks to larger masks
- or define a recurrence from `mask \setminus {bit}` into `mask`

The important thing is consistency.

Forward transitions are usually easier to debug in contest.

### 4. `popcount(mask)` Is Often A Hidden State Variable

In assignment-style DP, the next row / worker / position is:

$$
k = popcount(mask).
$$

That is one of the most valuable bitmask-DP recognitions:

- the subset size may already encode the stage of the process

This is one reason increasing-mask iteration is so common:

- every transition goes from a state with `k` chosen items to one with `k + 1`
- so no future state is read before it is written

### 5. Watch Total Complexity, Not Just State Count

Many people estimate only the number of states:

$$
2^n.
$$

But the real cost is often:

$$
n 2^n
\quad \text{or} \quad
n^2 2^n.
$$

This is why `n = 22` may be fine for one pattern and dead for another.

The same warning applies to submask enumeration:

- one loop over all submasks of one fixed mask costs `O(2^{popcount(mask)})`
- doing that inside a loop over all masks often costs `O(3^n)` overall

### 6. Memory Compression Sometimes Works

If transitions only go from:

- smaller masks to larger masks

and you only need the previous layer by popcount, layer compression may be possible.

But do not force it too early. Clarity is usually worth more than shaving memory unless the constraints demand it.

### 7. Bitmask DP Versus Subset Sum Bitsets

Do not confuse these:

- **bitmask DP**: state is a subset of items
- **bitset DP**: state is usually a reachable value/set of sums packed into machine words

They both use bits, but they solve different shapes of problems.

### 8. Dense State Graphs May Want Another View

Sometimes `(mask, node)` is better understood as a graph state than as a table state.

If transitions are:

- unweighted
- uniform cost
- naturally graph-like

then BFS or shortest-path thinking may be the right wrapper around the same subset state.

### 9. Reverse Recurrences Still Need A Safe Fill Order

If your recurrence removes a bit, such as

$$
dp[mask][v]
\leftarrow
dp[mask \setminus \{v\}][u],
$$

then a plain increasing loop over `mask` is still often valid, because every proper submask is numerically smaller than `mask`.

That is a useful implementation fact, but do not rely on it blindly. Always ask:

- are all dependencies strict submasks?
- or does my recurrence also depend on another dimension whose order I still need to manage?

## Beyond Basic Bitmask DP

The core contest layer is:

- `dp[mask]`
- `dp[mask][last]`
- adding one bit
- iterating submasks

Important next-layer directions include:

- SOS DP / subset transforms
- profile DP on grids
- meet-in-the-middle
- bitmask DP combined with shortest paths or BFS on state graphs

The right study order is:

1. learn to define the mask in plain language
2. choose between `dp[mask]` and `dp[mask][last]`
3. internalize the feasibility of `n 2^n` and `n^2 2^n`
4. only then move to heavier subset transforms

## Practice Archetypes

The most common bitmask-DP-shaped tasks are:

- **assignment / matching by used set**
- **visit-all-nodes path or tour**
- **cover all colors / categories / features**
- **partition a small set into valid groups**
- **small-state exponential search where many orders collapse to the same subset**

The strongest contest smell is:

- `n` is tiny
- brute force over orders or subsets is almost feasible
- and the future depends only on a chosen subset plus maybe one small extra parameter

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Primary / classical landmark:

- Bellman–Held–Karp style subset DP for TSP, referenced in [Held–Karp algorithm](https://en.wikipedia.org/wiki/Held%E2%80%93Karp_algorithm)

Course:

- [Stanford CS97SI: Dynamic Programming](https://web.stanford.edu/class/cs97si/04-dynamic-programming.pdf)
- [UCF Programming Team Lecture: DP Algorithm for Traveling Salesman Problem](https://www.cs.ucf.edu/~dmarino/progcontests/modules/dptsp/DP-TSP-Notes.pdf)
- [Illinois CS491 CAP: Travelling Salesperson](https://courses.grainger.illinois.edu/cs491cap/fa2019/lectures/tsp/)

Reference:

- [USACO Guide: Bitmask DP](https://usaco.guide/gold/dp-bitmasks)
- [CP-Algorithms: Enumerating Submasks of a Bitmask](https://cp-algorithms.com/algebra/all-submasks.html)

Essay / notes:

- [TJHSST Programming Lecture: Bitmask DP](https://activities.tjhsst.edu/sct/lectures/1920/2020_3_6_Bitmask_DP.pdf)

Practice:

- [AtCoder Educational DP Contest](https://atcoder.jp/contests/dp)

Repo anchors:

- practice ladder: [Bitmask DP ladder](../../../practice/ladders/dp/bitmask-dp/README.md)
- practice note: [VMMARBLE](../../../practice/ladders/dp/bitmask-dp/vmmarble.md)
- starter template: [bitmask-subset-iterate.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/bitmask-subset-iterate.cpp)
- notebook refresher: [DP cheatsheet](../../../notebook/dp-cheatsheet.md)

## Related Topics

- [DP Foundations](../foundations/README.md)
- [Knapsack Family](../knapsack-family/README.md)
- [Tree DP](../tree-dp/README.md)
- [Graph Modeling](../../graphs/graph-modeling/README.md)
