# Algorithm Gap Roadmap

- Purpose: durable TODO list for algorithm and data-structure gaps that are still worth adding after the core content waves
- Scope: new algorithm families, data-structure families, and closely related retrieval/practice follow-ups
- Doc type: planning
- Owner: repo maintainer
- Status: active
- Last reviewed: 2026-04-25
- Update triggers: after any broad coverage audit, after any major reprioritization, or when one of the listed waves ships
- Canonical companion docs: [Roadmap](roadmap.md), [Expansion Roadmap](expansion-roadmap.md), [Freshness Backbone](freshness-backbone.md), [Source Map](source-map.md)

This file exists so the repo can keep expanding deliberately without losing the distinction between:

- high-ROI missing canon
- useful second-wave refinements
- low-ROI prestige coverage

## How To Use This File

- use this as the algorithm-specific backlog after the earlier expansion phases have largely shipped
- treat the top section as the default next-wave queue
- only move to lower sections when the higher section has either shipped or been consciously deferred
- do not open more than `2` new deep-topic lanes in one wave
- do not open a wave here unless the repo can support the usual full lane:
  - topic page
  - starter template
  - hot sheet or strong parent-cheatsheet route
  - ladder placement
  - at least one flagship note plus solution
  - route into `Build Kit` and `Template Library`

## Selection Rules

### Prefer These First

- reusable families that still appear across `VNOI Wiki`, `USACO Guide Advanced`, `CP-Algorithms`, or `OI Wiki`
- topics that close a real route gap in the current repo
- topics that unlock or justify later topics

### Push These Later

- topics that mostly duplicate an existing route with a different implementation flavor
- prestige-heavy topics with low contest frequency
- textbook data structures that are rarely hand-coded in modern CP

## BST Policy

The repo should not try to add every balanced BST variant as a full lane.

### Full-Lane BST Topics Worth Having

- `PBDS / Order Statistics Tree`
- `Key-Based Treap`
- `Implicit Treap` (already shipped)
- `Link-Cut Tree`
- `Euler Tour Tree`
- `Persistent Treap`

### BST Topics Usually Better As Compare Notes

- `AVL`
- `Red-Black Tree`
- `Scapegoat Tree`
- `Size Balanced Tree`

### Splay Policy

- do not add a standalone `Splay Tree` lane unless it directly enables:
  - `Link-Cut Tree`
  - a clear ordered-set / sequence route the repo actually intends to teach
- [x] `Splay Tree` enabling lane for one self-adjusting ordered-set route and the direct bridge into `Link-Cut Tree`

## Should Do Soon

These are the highest-ROI gaps that still look worth shipping.

### Wave 1. Contest BST Refinement

- [x] `PBDS / Order Statistics Tree`
- [x] `Key-Based Treap` exact starter and route polish for the existing treap family

### Wave 2. Dynamic Tree Core

- [x] `Link-Cut Tree`

### Wave 3. DP Optimization Core

- [x] `Divide and Conquer DP`
- [x] `Knuth Optimization`

### Wave 4. Tree Query Refinements

- [x] `DSU on Tree / Small-to-Large`
- [x] `Virtual Tree`

### Wave 5. Algebra / Linear Algebra Core

- [x] `BSGS / Discrete Log`
- [x] `Gaussian Elimination / Linear Algebra`

### Wave 6. Suffix Structure Completion

- [x] `Suffix Tree`

## Good Next

These should come after the `Should Do Soon` block unless a later audit changes the order.

### Wave 7. Advanced DP Variants

- [x] `Broken Profile / Plug DP`
- [x] `SOS DP`

### Wave 8. Dynamic Tree Follow-Up

- [x] `Euler Tour Tree`

### Wave 9. Number-Theory Prefix-Sum Family

- [x] `Dirichlet Convolution / Prefix Sums of Number-Theoretic Functions`
- [x] `Min_25 / Du Jiao` after the Dirichlet lane exists

### Wave 10. Number-Theory Follow-Up

- [x] `Modular Square Root / Discrete Root`

### Wave 11. Geometry Canon Extensions

- [x] `Half-Plane Intersection`
- [x] `Nearest Pair of Points`

### Wave 12. BST / Treap Follow-Up

- [x] `Persistent Treap`

### Wave 13. CHT Family Refinement

- [x] `LineContainer` exact route as a sibling / refinement under the current `CHT / Li Chao` family

## Long-Tail Later

These are legitimate topics, but they should not jump ahead of the groups above without a strong audit reason.

### Advanced Optimization / Algebra

- [x] `Slope Trick`
- [x] `Lagrangian Relaxation / Aliens Trick`
- [x] `Polynomial / Formal Power Series`
- [x] `Simplex`

### Advanced Math

- [x] `Primitive Root`
- [x] `Pollard-Rho`

### Advanced Structures / Geometry

- [x] `Matroid Intersection`
- [x] `Minkowski Sum`
- [x] `Pairing Heap / Leftist Heap`
- [x] `ODT / Chtholly`

### BST Textbook Coverage

- [x] `AVL` compare note after opening a balancing-overview page
- [x] `Red-Black Tree` compare note under the balancing-overview page for `PBDS` / library-style ordered-container framing
- [x] `Scapegoat Tree` compare note under the balancing-overview page for rebuild-based balanced-BST framing
- [x] `Size Balanced Tree` compare note under the balancing-overview page for size-driven balanced-BST framing

## Suggested Default Ship Order

If no fresher audit finding overrides it, the default next-wave queue is:

1. `Freshness / backlog reprioritization pass`
2. open a new lane only if an audit produces a stronger gap than the remaining compare-note backlog

## Definition Of Done For One Gap Wave

A gap is only considered shipped when:

- the lane exists in `topics/`
- the lane has a reusable starter route
- the lane has at least one retrieval surface
- the lane has at least one flagship note plus solution
- the lane is reachable from a hub or route page
- the lane has gone through a review sweep
- the usual build/check suite passes

## Source Backbone For This File

This backlog should be kept honest against:

- [VNOI Wiki](https://wiki.vnoi.info/)
- [USACO Guide Advanced](https://usaco.guide/adv)
- [CP-Algorithms](https://cp-algorithms.com/)
- [OI Wiki](https://en.oi-wiki.org/)

Those sources are not "the repo's law", but they are the main coverage radar used to decide whether a missing family still deserves a full lane.
