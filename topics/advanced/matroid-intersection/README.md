# Matroid Intersection

This lane is for the rare contest situation where the hidden combinatorial object really is:

- one explicit ground set
- two matroids on that same ground set
- and the thing you want is a largest common independent set

The repo's exact first route is intentionally narrow:

- **unweighted**
- **maximum-cardinality**
- **explicit ground set**
- **independence-oracle based**

This is not a general matroid textbook, and it is not the weighted version.

It sits next to:

- [Optimization And Duality](../optimization-and-duality/README.md) for the theorem / certificate lens
- [Matching](../../graphs/matching/README.md) when the hidden model is already a specialized matching problem
- [XOR Basis / Linear Basis](../../math/xor-basis/README.md) when only one linear-independence family matters
- [Simplex](../simplex/README.md) when the real model is continuous LP rather than combinatorial exchange

## At A Glance

- **Use when:**
  - the ground set is explicit and not huge
  - you can write two independence tests cleanly
  - the objective is cardinality, not weight
  - one choice must satisfy two different "independence" stories at once
- **Prerequisites:**
  - [Optimization And Duality](../optimization-and-duality/README.md)
  - [Reasoning](../../foundations/reasoning/README.md)
- **Boundary with nearby pages:**
  - use [Matching](../../graphs/matching/README.md) when the whole story is already a graph matching and the specialized solver is cleaner
  - use [XOR Basis / Linear Basis](../../math/xor-basis/README.md) when the only real constraint is xor-span independence
  - use this page when the cleanest model is "two matroids on one ground set"
- **Strongest cues:**
  - "pick one object from each group while preserving another independence rule"
  - the editorial talks about `partition matroid`, `linear matroid`, or `exchange graph`
  - bipartite matching appears as a comparison point, not as the exact final model
  - the hidden obstruction is not one graph cut or one DP state, but one failed exchange argument
- **Strongest anti-cues:**
  - weights matter -> this exact starter does not do weighted matroid intersection
  - the ground set is huge or only implicit
  - the real route is already ordinary matching / max flow / xor basis
  - you only need one theorem statement, not one contest-time implementation
- **Success after studying this page:**
  - you can state `Z1`, `Z2`, and the exchange graph correctly
  - you can augment one common independent set by a shortest exchange path
  - you know when to keep the generic oracle route and when to exploit structure

## Problem Model And Notation

The exact starter in this repo solves:

- ground set `X = {0, 1, ..., n-1}`
- two matroids `M1 = (X, I1)` and `M2 = (X, I2)`
- task: find one largest set `Y` such that `Y in I1` and `Y in I2`

The exact contract is:

- `n` is explicit
- you can test `S in I1` and `S in I2` for subsets `S`
- the objective is cardinality only

The exact non-promises matter just as much:

- no weighted matroid intersection
- no claim that the starter is the right solver for huge oracle-heavy instances
- no promise that every contest problem exposing one matroid should be forced through this lane

## Why This Exists Next To Optimization And Duality

[Optimization And Duality](../optimization-and-duality/README.md) gives the theorem-level lens:

- weak duality from ranks on a partition `A sqcup B`
- Edmonds' min-max theorem
- why augmenting paths are certifying optimality

This page teaches the narrower contest move:

- keep one common independent set `Y`
- build the exchange digraph `H(M1, M2, Y)`
- augment along a shortest path from `Z1` to `Z2`

So the division of labor is:

- **duality page:** why the theorem is true and what the certificate means
- **this page:** how to run the augmentation algorithm as contest code

## Core Route In This Repo

The exact starter route is:

- unweighted matroid intersection
- explicit ground set
- independence oracles
- exchange digraph augmentation

For a current common independent set `Y`:

- `Z1` = outside elements directly addable in `M1`
- `Z2` = outside elements directly addable in `M2`
- arcs `y -> z` for `y in Y`, `z notin Y` if swapping `y` out for `z` preserves `M1`
- arcs `z -> y` for `z notin Y`, `y in Y` if swapping `y` out for `z` preserves `M2`

Then:

- a shortest directed path from `Z1` to `Z2` gives one augmentation
- no such path means the current set is maximum

## Core Invariants

### 1. The Current Set Must Stay Common Independent

Every augmentation starts from one set `Y` that is already independent in both matroids.

If that invariant is not true, the exchange graph means nothing.

### 2. Arcs Are One-Sided Promises

An arc does **not** mean "the whole swap is valid in both matroids."

It only means:

- `y -> z`: the swap is valid for `M1`
- `z -> y`: the swap is valid for `M2`

The alternating path is what stitches those one-sided promises into one global augmentation.

### 3. The Shortest `Z1 -> Z2` Path Is The Safe Augmentation

The algorithm is not:

- pick any swappable element greedily

It is:

- use the exchange graph
- find a shortest path from `Z1` to `Z2`
- toggle along that alternating path

That is the contest-time form of the theorem.

## Worked Example: Pick Your Own Nim

Use [Pick Your Own Nim](../../../practice/ladders/advanced/matroid-intersection/pickyourownnim.md).

Bob must choose exactly one heap from each box so that, after combining his picks with Alice's fixed heaps, **every nonempty subset** has nonzero xor.

That is equivalent to saying:

- all chosen heap sizes must be linearly independent over `GF(2)`

So the two matroids are:

- **partition matroid**: at most one chosen heap from each box
- **linear matroid**: Bob's chosen heaps stay linearly independent together with Alice's fixed heaps

This is exactly why the flagship sits here:

- one side is "one per box"
- the other side is "stay independent in one vector space"
- the clean algorithm is an augmenting-path matroid-intersection route

## Variant Chooser

| Situation | Best first move | Why it fits | Where it fails |
| --- | --- | --- | --- |
| explicit ground set, two clean independence oracles, cardinality objective | use matroid intersection | the exchange-graph algorithm matches the model exactly | weak if the ground set is too large for generic oracle calls |
| hidden model is already bipartite or general matching | use [Matching](../../graphs/matching/README.md) | the specialized graph algorithm is simpler and faster | weak if the real second constraint is not graph matching |
| only linear independence in `GF(2)` matters | use [XOR Basis / Linear Basis](../../math/xor-basis/README.md) | one matroid is enough; no need for a second independence system | weak if one-per-group or one-per-color constraints also matter |
| continuous optimization with real-valued variables | use [Simplex](../simplex/README.md) | the object is LP, not combinatorial exchange | weak if the variables are discrete chosen elements |

## Complexity And Tradeoffs

The relevant contest tradeoff is:

- beautiful generality
versus
- expensive oracle traffic

Practical notes:

- the generic starter is for small / medium explicit ground sets
- the right flagship move is often to exploit structure in one or both matroids
- linear + partition is much friendlier than arbitrary black-box oracles

That is why this lane belongs in `advanced`:

- the theorem is elegant
- the generic route is powerful
- but the reusable contest implementation is still niche

## Main Traps

- forcing ordinary matching through generic matroid intersection when matching is already the cleaner route
- forgetting that the starter is **unweighted**
- writing oracles that are already too slow before the augmenting loop even starts
- treating "swap valid in one matroid" as if it meant "swap valid globally"
- overclaiming that every linear-matroid problem belongs here instead of in [XOR Basis / Linear Basis](../../math/xor-basis/README.md)

## Reopen Path

- Topic page: [Matroid Intersection](README.md)
- Practice ladder: [Matroid Intersection ladder](../../../practice/ladders/advanced/matroid-intersection/README.md)
- Starter template: [matroid-intersection-oracle.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/advanced/matroid-intersection-oracle.cpp)
- Notebook refresher: [Matroid Intersection hot sheet](../../../notebook/matroid-intersection-hot-sheet.md)
- Compare points:
  - [Optimization And Duality](../optimization-and-duality/README.md)
  - [Matching](../../graphs/matching/README.md)
  - [XOR Basis / Linear Basis](../../math/xor-basis/README.md)
  - [Pick Your Own Nim](../../../practice/ladders/advanced/matroid-intersection/pickyourownnim.md)

## References And Practice

- [Extremal Combinatorics notes: Matroid Intersection](https://extremalcombinatorics.com/optimization/notes/sec_matroidIntersection.html)
- [Codeforces Gym 102156 D - Pick Your Own Nim](https://codeforces.com/gym/102156/problem/D)
