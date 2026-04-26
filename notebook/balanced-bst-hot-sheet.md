# Balanced BST Hot Sheet

Use this sheet when you feel the urge to hand-code a balanced BST and want to
check whether AVL, Red-Black, Scapegoat, SBT, or Splay is actually the right move.

## Do Not Use When

- GNU PBDS already solves the job -> [PBDS / Order Statistics Tree](../topics/data-structures/pbds-order-statistics/README.md)
- split/merge by key or by position is the real invariant -> [Treap / Implicit Treap](../topics/data-structures/treap-implicit/README.md)
- you are really in dynamic-tree territory -> [Link-Cut Tree](../topics/graphs/link-cut-tree/README.md)

## Choose By Signal

- one dynamic ordered set with rank / `k`-th and GNU extensions allowed -> `PBDS`
- self-hosted split/merge ordered set or sequence surgery -> `Treap`
- dynamic interval overlap queries over one live set -> `Interval Tree`
- deterministic rotation-based ordered set as an implementation exercise -> `AVL`
- library-style balancing / `std::set` / PBDS internals curiosity -> `Red-Black`
- rebuild-based deterministic balancing curiosity -> `Scapegoat`
- size-driven deterministic order-statistics balancing curiosity -> `SBT`
- self-adjusting ordered set and direct bridge into `LCT` -> `Splay`
- dynamic-tree path machinery itself -> `Link-Cut Tree`

## AVL Core Invariant

- BST order on keys
- `abs(height(left) - height(right)) <= 1` at every node
- if rank / `k`-th matters, subtree size must also be maintained through every rotation

## Red-Black Core Invariant

- BST order on keys
- each node is red or black
- no red node has a red child
- every root-to-null path has the same black-height
- if rank / `k`-th matters, subtree size must also survive recolor/rotate fix-ups

## Scapegoat Core Invariant

- BST order on keys
- subtree sizes stay accurate on the path you update
- when a balance threshold is violated, rebuild one offending subtree
- lazy deletion variants must keep live-size bookkeeping honest

## Size Balanced Tree Core Invariant

- BST order on keys
- subtree sizes are always accurate
- size inequalities between children / nephews decide whether rebalancing is needed
- rank / `k`-th support comes from the same `size` field used for balancing

## Main Traps

- delete balancing is the easiest place to get rotations wrong
- subtree size updates must happen after every rotate
- duplicates need an explicit `count`, not one blind extra node policy
- if you want split/merge, you probably wanted treap instead
- if your real reason is "this is probably what `std::set` uses", you probably wanted PBDS or plain `set`, not a hand-coded Red-Black tree
- if your real reason is "no rotations sounds easier", Scapegoat can still be more code than PBDS or treap once rebuild logic is included
- if your real reason is "rank support is built in", SBT can still be more contest work than PBDS for the same interface

## Practical Repo Rule

In this repo:

- AVL, Red-Black, Scapegoat, and SBT are **compare notes**
- Splay is a narrow enabling lane because it directly bridges into link-cut tree
- PBDS and treap are still the main first-line retrieval routes for ordinary ordered-set work

So if you are under contest pressure, default to:

- [PBDS / Order Statistics Tree](../topics/data-structures/pbds-order-statistics/README.md)
- [Treap / Implicit Treap](../topics/data-structures/treap-implicit/README.md)

and only reopen the balanced-BST compare note if you deliberately want the
deterministic textbook routes.

## Reopen Paths

- full compare page -> [Balanced BSTs For Contests](../topics/data-structures/balanced-bsts/README.md)
- augmented-BST overlap route -> [Interval Trees](../topics/data-structures/interval-trees/README.md)
- ordinary ordered sets -> [Heaps And Ordered Sets](../topics/data-structures/heaps-and-ordered-sets/README.md)
- GNU order-statistics route -> [Order Statistics Tree hot sheet](order-statistics-tree-hot-sheet.md)
- self-hosted split/merge route -> [Treap / Implicit Treap hot sheet](treap-hot-sheet.md)
- self-adjusting route -> [Splay Tree hot sheet](splay-tree-hot-sheet.md) + [Splay Tree](../topics/data-structures/splay-tree/README.md)
