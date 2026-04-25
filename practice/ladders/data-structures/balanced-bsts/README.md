# Balanced BSTs For Contests Ladder

This is a **compare-note ladder**, not a primary retrieval lane.

Use it when you deliberately want to understand where AVL sits relative to the
repo's main BST routes, and where Red-Black / Scapegoat / SBT fit in the same
family map.

## Who This Is For

Use this ladder if:

- you want to practice one textbook balanced BST on purpose
- you keep wondering "why PBDS / treap first, not AVL or Red-Black or Scapegoat or SBT?"
- you want one implementation challenge before deciding whether AVL is worth
  carrying in your personal toolbox

## Warm-Up

- explain the difference between:
  - plain ordered set
  - order-statistics tree
  - split/merge tree
  - dynamic-tree splay machinery
- say when the repo prefers PBDS and when it prefers treap

## Core

- read [Balanced BSTs For Contests](../../../../topics/data-structures/balanced-bsts/README.md)
- focus on the AVL, Red-Black, Scapegoat, and SBT sections
- practice one deterministic rotation-based ordered-set implementation

## Implementation Challenge

- [Luogu P3369 - 普通平衡树](https://www.luogu.com.cn/problem/P3369)

This is the cleanest "if you really want to implement AVL yourself" rep.

It also works as a Red-Black compare rep if your goal is to feel how much
bookkeeping the library-style balancing route really buys you.

It also works as a Scapegoat compare rep if your goal is to contrast
rotation-heavy balancing with rebuild-heavy balancing on the same interface.

It also works as an SBT compare rep if your goal is to contrast size-driven
balancing against the other textbook balancing signals.

## Compare Practice

- [ORDERSET - Order Statistic Set](https://www.spoj.com/problems/ORDERSET/)
  Compare your AVL route against the repo's [PBDS lane](../pbds-order-statistics/README.md).
- [Salary Queries](https://cses.fi/problemset/task/1144)
  Compare an AVL multiset-with-counts route against the repo's
  [key-based treap bridge](../treap-implicit/README.md).

## Exit Criteria

You are ready to leave this compare track when:

- you can explain AVL's invariant and four rotation cases
- you can explain the Red-Black color / black-height story at a high level
- you can explain the Scapegoat rebuild story at a high level
- you can explain the SBT size-balance story at a high level
- you can say clearly why PBDS or treap is still usually the better contest route
- you no longer confuse "textbook balanced BST" with "best retrieval choice"

## Main Routes Back

- [Balanced BST hot sheet](../../../../notebook/balanced-bst-hot-sheet.md)
- [PBDS / Order Statistics Tree ladder](../pbds-order-statistics/README.md)
- [Treap / Implicit Treap ladder](../treap-implicit/README.md)
- [Link-Cut Tree ladder](../../graphs/link-cut-tree/README.md)
