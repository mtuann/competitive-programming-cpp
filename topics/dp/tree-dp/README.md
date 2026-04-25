# Tree DP

Tree DP is what happens when:

- the input is a tree
- the answer is not just one traversal aggregate
- and each child subtree can be summarized by a small state

This is why tree DP sits exactly between:

- graph structure
- and dynamic programming

The main skill is not "memorize a DFS template." It is:

> define the smallest subtree state that makes child subproblems independent

If you get that part right, the implementation is often just a postorder DFS.

## At A Glance

Reach for tree DP when:

- the input is a tree or can be rooted cleanly
- each node combines information from its children
- the answer asks for counts, best values, or feasibility over connected structure
- path uniqueness is the reason local subtree summaries become meaningful

Strong contest triggers:

- "for every subtree rooted at ..."
- choose / skip current node
- best value using descendants
- merge child contributions
- compute one answer for the whole rooted tree

Strong anti-cues:

- the problem only needs one aggregate like subtree size or sum
- the answer is really a path or ancestor query problem
- the graph is not a tree and cycles still matter
- you are about to define many states before checking whether a plain traversal invariant is enough

What success looks like after studying this page:

- you can define the subtree state precisely
- you know when child contributions are independent
- you can separate subtree-local answers from whole-tree answers
- you can tell when rerooting is the next step and when it is not needed
- you can spot when the hard part is the merge, not the DFS

## Prerequisites

- [DP Foundations](../foundations/README.md)
- [Trees](../../graphs/trees/README.md)
- [Graph Modeling](../../graphs/graph-modeling/README.md)

Helpful neighboring topics:

- [LCA](../../graphs/lca/README.md)
- [Tree Algorithms Ladder](../../../practice/ladders/graphs/trees/README.md)
- [DP Cheatsheet](../../../notebook/dp-cheatsheet.md)

## Problem Model And Notation

We root the tree at some node, usually `1` unless the problem suggests something else.

Then every node `u` has:

- one parent `p`
- zero or more children
- a subtree consisting of `u` and all descendants of `u`

The canonical tree-DP shape is:

$$
dp[u] = \text{answer for the subtree rooted at } u
$$

or, with local choices:

$$
dp[u][state] = \text{answer for the subtree rooted at } u \text{ under one boundary condition}
$$

The key modeling rule is:

- the state must contain exactly the information the parent needs from `u`'s subtree

## From Brute Force To The Right Idea

### Brute Force

The naive way to think about many tree problems is:

- try all choices in the whole tree
- check whether they conflict

That quickly explodes because choices at different branches interact globally.

### The Real Compression

Once the tree is rooted, every child subtree hangs off `u` through exactly one boundary edge.

That means if the state at `u` tells us what matters across that boundary, then:

- each child subtree becomes independent of the others

This is the real reason tree DP works.

### The First Question Is Not "What Is The Transition?"

The first question is:

> What must the parent know about this subtree, and nothing more?

Typical answers are:

- one number like subtree sum or best score
- a tiny choice state such as `take / skip`
- a bounded count of selected items

If the state is too small:

- the merge becomes invalid

If it is too large:

- complexity explodes

## Core Invariant And Why It Works

### 1. Child Subtrees Are Independent Once The Boundary State Is Fixed

In a rooted tree, the only way a child subtree communicates with the rest of the tree is through its parent edge.

So if the state already records what matters at that boundary, then:

- one child subtree does not need to inspect the full contents of another child subtree

This is the structural theorem behind almost every tree DP.

### 2. Postorder Is The Natural Evaluation Order

To compute `dp[u]`, you usually need all `dp[v]` for children `v` of `u`.

So the natural order is:

- DFS to children first
- compute parent after all children return

This is just dynamic programming on the rooted-tree partial order.

### 3. Take / Skip Is The Canonical First Nontrivial Pattern

Many tree-DP problems have a local conflict at a node:

- if you take `u`, the children must obey one rule
- if you skip `u`, the children may choose more freely

That produces the classic two-state shape:

$$
dp[u][0],\ dp[u][1]
$$

The deep point is not the notation. It is the boundary meaning:

- what does the parent need to know about whether `u` was used?

### 4. Rerooting Is A Different Layer

Basic subtree DP computes answers that are local to the chosen root.

Sometimes the problem asks for:

- the answer for every possible root
- or a whole-tree quantity seen from each node

That is the rerooting / all-roots layer:

- first compute subtree information
- then propagate outside-subtree information

It is still tree DP, but it is not the first mental model to reach for.

### 5. Heavy Child Merges Are The Real Cost Center

Some tree DPs are easy because each child contributes independently with a constant-size summary.

Others are harder because:

- the state includes a count or knapsack dimension
- children must be merged one by one

So one of the main complexity questions is:

- do I have a constant-size local state, or a child-merge DP?

## Complexity And Tradeoffs

Typical contest-level view:

| Pattern | Typical time | Main idea | Main danger |
| --- | --- | --- | --- |
| subtree aggregate | `O(n)` | one summary per node | calling it DP when a simple traversal invariant would do |
| take / skip states | `O(n)` | constant-size state per node | wrong state meaning at parent boundary |
| rerooting | `O(n)` or `O(n * state)` | two passes: down and up | mixing subtree and whole-tree answers |
| knapsack-style child merge | often `O(nk^2)` or similar | distribute budget across children | state blow-up and bad merge order |

Rule of thumb:

- if the state is constant-size, tree DP is often linear
- if the state tracks counts or budgets, the merge usually dominates

## Variant Chooser

| Situation | Best first model | Why it fits | Main danger |
| --- | --- | --- | --- |
| subtree sizes / sums / counts | subtree aggregation | children contribute one summary each | overcomplicating with fake states |
| choose or skip current node | two-state tree DP | local conflict is exactly at the parent-child boundary | forgetting what `take` actually forbids |
| whole-tree answer for every root | rerooting DP | subtree-only answers are insufficient | trying to solve it with one DFS |
| bounded number of selections in a subtree | tree knapsack | budget must be split across children | merge complexity explosion |
| tree problem with no real subtree independence | not tree DP | the tree alone does not guarantee DP is right | forcing a DP state where a greedy/traversal invariant fits better |

Two quick reject rules:

- if your state does not answer a rooted-subtree question, stop and redefine it
- if the parent would still need to inspect raw child subtree structure, the state is not sufficient yet

## Worked Examples

### Example 1: Subtree Size Is The Smallest Tree DP

Root the tree.

Then:

$$
sub[u] = 1 + \sum_{v \in child(u)} sub[v]
$$

This is the lightest possible tree DP:

- one scalar summary
- one postorder merge

It is useful because it shows the core rhythm without extra state design.

### Example 2: `Tree Matching` Is Canonical Two-State Tree DP

In [Tree Matching](../../../practice/ladders/dp/tree-dp/treematching.md), the global object is:

- a maximum matching on a tree

Once the tree is rooted, the right states are:

```text
skip[u] = best answer in u's subtree if u is matched to no child
take[u] = best answer in u's subtree if u is matched to exactly one child
```

Why this works:

- if `u` matches no child, each child subtree may choose its own best outcome independently
- if `u` matches one child `v`, then `v` must contribute its `skip` state, while other children stay independent

This is the cleanest first serious example because the merge logic is real, but the state is still tiny.

It also teaches a reusable merge trick:

- first compute a `base` answer where every child contributes its independent best value
- then "swap in" the one child that must obey a stricter rule

This `base-and-swap` pattern appears in many tree DPs beyond matching.

### Example 3: Why Children Become Independent

Suppose `u` has children `a`, `b`, and `c`.

If the state at `u` already decides whether `u` is available to connect to one child, then:

- the subtree of `a` only needs to know that boundary rule
- it does not need the internal structure of the subtree of `b`

This is the exact reason postorder merging is legal:

- the parent boundary state cuts the subproblems apart

### Example 4: Rerooting Is "Subtree DP Is Not Enough"

Suppose the problem asks:

- for every node `u`, what is the answer if the whole tree is considered from `u`?

Then `dp[u]` on the subtree of `u` is not enough, because it says nothing about the part of the tree above `u`.

That is where rerooting enters:

- one pass for downward subtree information
- another pass for information coming from the parent side

This is the right conceptual boundary:

- subtree DP solves one rooted view
- rerooting propagates "outside subtree" information

### Example 5: `VOSTRIP` Is A Good Boundary Example

[VOSTRIP](../../../practice/ladders/graphs/tree-dp/vostrip.md) lives on a tree, but its accepted solution is more about:

- local degree-based aggregation
- path endpoint counting

than about a textbook rooted-subtree DP table.

This is valuable because it teaches a healthy boundary:

- not every tree problem needs full tree DP
- sometimes the tree only guarantees a clean local counting argument

## Algorithm And Pseudocode

Repo starter templates:

- [tree-dp-subtree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/tree-dp-subtree.cpp)
- [tree-dp-rerooting.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/tree-dp-rerooting.cpp)

### Generic Postorder Tree DP

```text
dfs(u, parent):
    initialize dp[u] with the base value for u

    for each child v of u:
        if v == parent:
            continue
        dfs(v, u)
        merge dp[v] into dp[u]
```

### Two-State Pattern

```text
dfs(u, parent):
    compute all child states first

    dp[u][0] = merge when u is not used in the local special way
    dp[u][1] = merge when u is used in the local special way
```

The point is not the indices `0/1`.

The point is:

- each state must correspond to one precise boundary promise

### Rerooting Skeleton

```text
dfs_down(u, parent):
    compute subtree answers from children upward

dfs_up(u, parent):
    propagate parent-side contribution to children
```

This is a second pattern, not the default first one.

## Implementation Notes

### 1. Exclude The Parent

Every tree DFS must enforce:

- do not walk back into the parent

This is obvious, but forgetting it is still the fastest way to destroy both correctness and complexity.

### 2. State Meaning Must Be Written In English

Before coding, write something like:

- "`dp[u][1]` means ..."

If that sentence is blurry, the code will usually be blurry too.

### 3. Merge Logic Is Where Most Bugs Live

The DFS itself is rarely the hard part.

The real questions are:

- which child states are compatible?
- when one child is chosen specially, how do the others contribute?

This is why `Tree Matching` is such a strong study problem.

### 4. Subtree Answer And Whole-Tree Answer Are Different Objects

Do not silently reuse a subtree DP as if it already answered the whole-tree problem for every node.

Ask explicitly:

- is my answer local to the rooted subtree?
- or does it need information from above?

If the second one is true, think rerooting.

In many rerooting problems, the practical challenge is:

- how to give one child the contribution of "all siblings plus the parent side"

That is where prefix/suffix aggregates or best-two-child summaries often appear.

### 5. Constant-Size States First, Knapsack States Second

When learning tree DP, build confidence in:

- subtree aggregates
- `take / skip`
- small local states

before moving to:

- selecting `k` nodes
- budget splits
- prefix-child merge DPs

The underlying structure is the same, but the merge cost gets much heavier.

### 6. Recursive DFS May Need Care On Deep Trees

Conceptually, recursive DFS is the cleanest way to write tree DP.

But on judges with deep trees, you may prefer:

- iterative traversals
- or explicit stack enlargement if the environment allows it

### 7. Root Choice Usually Changes The View, Not The Final Optimum

Many tree-DP problems can be rooted anywhere convenient.

The chosen root changes:

- how you describe states
- which nodes are "children"

but not the underlying problem.

Pick the root that makes the state easiest to define.

When in doubt, pick the root that makes one of these simplest:

- parent exclusion
- child merge order
- the meaning of `take / skip`

## Beyond Basic Tree DP

This page is intentionally centered on the core contest layer:

- subtree aggregation
- two-state rooted DP
- rerooting boundary
- child-merge reasoning

Important next-layer directions include:

- rerooting / all-roots DP in full detail
- tree knapsack
- DP on [virtual trees](../../graphs/virtual-tree/README.md)
- combining tree DP with bitmask or other secondary state dimensions

The right study order is:

1. learn to define one rooted-subtree state
2. internalize child independence and merge order
3. then move to rerooting and heavier child-merge DPs

## Practice Archetypes

The most common tree-DP-shaped tasks are:

- **subtree aggregate with a nontrivial merge**
- **choose / skip current node**
- **maximum or minimum structure inside rooted subtrees**
- **whole-tree answer for every node after one rerooting pass**
- **budget distribution across child subtrees**

The strongest smell is:

- the graph is a tree
- and once rooted, each child subtree can be summarized independently

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Primary / course:

- [CMU 15-451 Lecture 5: Tree Dynamic Programming](https://www.cs.cmu.edu/~yangp/15-451/lecture5.pdf)

Reference:

- [USACO Guide: DP on Trees - Introduction](https://usaco.guide/gold/dp-trees)
- [USACO Guide: DP on Trees - Solving For All Roots](https://usaco.guide/gold/all-roots?lang=cpp)
- [OI Wiki: Tree DP](https://en.oi-wiki.org/dp/tree/)

Practice:

- [CSES Tree Algorithms](https://cses.fi/problemset/list/)

Repo anchors:

- practice ladder: [Tree DP ladder](../../../practice/ladders/dp/tree-dp/README.md)
- practice note: [Tree Matching](../../../practice/ladders/dp/tree-dp/treematching.md)
- practice note: [VOSTRIP](../../../practice/ladders/graphs/tree-dp/vostrip.md)
- starter template: [tree-dp-subtree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/tree-dp-subtree.cpp)
- starter template: [tree-dp-rerooting.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/tree-dp-rerooting.cpp)
- notebook refresher: [DP cheatsheet](../../../notebook/dp-cheatsheet.md)

## Related Topics

- [Trees](../../graphs/trees/README.md)
- [LCA](../../graphs/lca/README.md)
- [Bitmask DP](../bitmask-dp/README.md)
- [Interval DP](../interval-dp/README.md)
