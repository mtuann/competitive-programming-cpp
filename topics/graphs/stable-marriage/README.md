# Stable Marriage

This lane is for the moment pairing stops being about:

- how many compatible edges you can take
- or the minimum total cost of a perfect assignment

and becomes about:

- two equal-sized sides
- strict preference lists on both sides
- and finding a matching with **no blocking pair**

The repo's exact first route for this family is:

- starter -> [gale-shapley-stable-marriage.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/gale-shapley-stable-marriage.cpp)
- flagship note -> [Stable Marriage](../../../practice/ladders/graphs/stable-marriage/stablemarriage.md)
- compare point -> [Matching](../matching/README.md)
- compare point -> [Hungarian / Assignment Problem](../hungarian-assignment/README.md)

This lane intentionally teaches the **equal-size, complete, strict-preference Gale-Shapley route first**. It does not start from hospital-residents quotas, ties, incomplete lists, or stable roommates.

## At A Glance

- **Use when:** there are two sides of equal size, every participant ranks every participant on the other side, and the goal is any stable perfect matching
- **Core worldview:** keep one current proposal frontier per proposer and let each accepter keep only the best proposal seen so far
- **Main tools:** preference lists, inverse ranking tables, one queue of free proposers, and permanent rejections
- **Typical complexity:** `O(n^2)` for `n` proposers and `n` accepters
- **Main trap:** forcing this onto assignment or cardinality-matching tasks where the real objective is size or cost, not stability

Strong contest signals:

- "everyone ranks all candidates on the other side"
- "find a stable matching"
- "no unmatched pair should prefer each other over their assigned partners"
- "any stable pairing is accepted"
- "which side proposes matters"

Strong anti-cues:

- the objective is maximum number of pairs -> [Matching](../matching/README.md)
- the objective is minimum total additive cost -> [Hungarian / Assignment Problem](../hungarian-assignment/README.md)
- capacities, quotas, or transport structure dominate -> [Min-Cost Flow](../min-cost-flow/README.md)
- preference lists have ties, missing entries, or many-to-one quotas -> this exact lane is too narrow

## Prerequisites

- [Matching](../matching/README.md), because two-sided pairing language should already feel natural
- [Graph Modeling](../graph-modeling/README.md), at the level of being comfortable turning a story into two sides and one relation

Helpful compare points:

- [Matching](../matching/README.md): use this when the objective is still cardinality in a bipartite graph
- [Hungarian / Assignment Problem](../hungarian-assignment/README.md): use this when the statement is a square cost matrix and total cost is the true objective
- [Min-Cost Flow](../min-cost-flow/README.md): use this when quotas or richer capacity constraints matter more than stable preferences

## Problem Model And Notation

Let:

- `P = {0, 1, ..., n - 1}` be the proposers
- `A = {0, 1, ..., n - 1}` be the accepters

Every proposer `p` has a strict total order over all accepters.
Every accepter `a` has a strict total order over all proposers.

A matching `M` is **stable** if there is no blocking pair `(p, a)` such that:

- `p` prefers `a` over `M(p)`
- and `a` prefers `p` over `M(a)`

The stable-marriage task is:

- match every proposer to one accepter
- match every accepter to one proposer
- and avoid all blocking pairs

## From Brute Force To The Right Idea

### Brute Force

Enumerate all bijections from proposers to accepters.

That is:

$$
O(n!)
$$

before stability checking.

Impossible at contest sizes.

### The Right Compression

This problem is not asking for:

- the biggest matching
- or the cheapest perfect matching

It asks for a matching that survives every **local deviation test**.

So the useful state is:

- who each free proposer should try next
- which proposal each accepter is currently holding
- and whether a rejection is already permanent

That is exactly what deferred acceptance tracks.

### The Gale-Shapley Insight

If proposers make offers in order:

- every proposer only moves forward through the list
- every accepter keeps the best proposer seen so far
- weaker held proposals get discarded forever

That monotone process is enough to guarantee:

- termination
- stability
- and proposer-optimality among all stable matchings

## Core Invariants And Why They Matter

The repo starter keeps four contest-facing invariants.

### 1. Every Proposer Advances Monotonically

Each proposer has one pointer `next_choice[p]`.

Whenever proposer `p` gets rejected:

- `next_choice[p]` increases
- and `p` never proposes to the same accepter again

So the total number of proposals is at most `n^2`.

### 2. Every Accepter Keeps The Best Proposal Seen So Far

If accepter `a` currently holds proposer `p`, then among everyone who has proposed to `a` so far:

- `a` prefers `p` to all others

That is why the tentative partner of one accepter can only improve over time.

### 3. Rejections Are Permanent

If accepter `a` rejects proposer `p`, it means `a` is already holding or later receives someone preferred over `p`.

So in the proposer-driven algorithm:

- `a` can never be the final partner of `p`

This is the monotone fact that stops the search from looping.

### 4. When The Process Stops, No Blocking Pair Exists

Suppose the final matching had a blocking pair `(p, a)`.

Then proposer `p` must have proposed to `a` before settling for a worse final partner.
At that moment, `a` either:

- accepted `p` temporarily
- or rejected `p` immediately

In either case, by the permanent-rejection invariant, `a` ends with someone at least as preferred as `p`.

So `(p, a)` cannot block the final matching.

That is the whole stability proof.

## Complexity And Tradeoffs

The standard Gale-Shapley implementation here runs in:

$$
O(n^2).
$$

Rule of thumb:

- full strict preference tables, equal sizes, stability objective -> this lane
- additive cost objective on a dense matrix -> [Hungarian / Assignment Problem](../hungarian-assignment/README.md)
- compatibility graph with maximum-cardinality objective -> [Matching](../matching/README.md)

## Worked Examples

### Example 1: Repo Canonical Benchmark

This repo's flagship note:

- [Stable Marriage](../../../practice/ladders/graphs/stable-marriage/stablemarriage.md)

The benchmark is intentionally stripped down to the exact lane:

- `n` proposers
- `n` accepters
- each side gives one full strict preference list
- print any stable matching

That keeps the whole focus on Gale-Shapley itself.

### Example 2: Why This Is Not Assignment

If a task says:

- "every row and every column must be used exactly once"
- and "minimize the total dissatisfaction / cost / penalty"

then the right model is not stable marriage first.
That is a weighted assignment problem:

- [Hungarian / Assignment Problem](../hungarian-assignment/README.md)

Stable marriage cares about **blocking pairs**, not the sum of ranks.

## Repo Starter Contract

The starter:

- assumes complete strict preference lists on both sides
- expects all ids to be `0`-based inside the structure
- returns both `proposer_to_accepter` and `accepter_to_proposer`

That contract is enough for:

- direct stable-matching output
- custom stability verification
- flipping proposer/accepter roles to compare the opposite optimal bias

## Main Traps

- confusing "stable" with "minimum total dissatisfaction"
- forgetting that the proposing side gets its best stable outcome under this route
- feeding ties or incomplete lists into a starter that assumes strict full rankings
- rebuilding preference comparisons on the fly instead of precomputing inverse ranks

## Reopen Paths

- exact starter -> [gale-shapley-stable-marriage.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/gale-shapley-stable-marriage.cpp)
- hot sheet -> [Stable Marriage hot sheet](../../../notebook/stable-marriage-hot-sheet.md)
- practice lane -> [Stable Marriage ladder](../../../practice/ladders/graphs/stable-marriage/README.md)
- compare point -> [Matching](../matching/README.md)
- compare point -> [Hungarian / Assignment Problem](../hungarian-assignment/README.md)
- broader chooser -> [Graph cheatsheet](../../../notebook/graph-cheatsheet.md)
