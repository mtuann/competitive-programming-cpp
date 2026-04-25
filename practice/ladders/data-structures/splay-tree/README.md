# Splay Tree Ladder

This ladder is for the moment when you explicitly want the self-adjusting BST
route and the direct bridge into link-cut tree.

## Who This Is For

Use this ladder if:

- you want one hand-coded ordered set with `rotate / splay / parent`
- PBDS feels too black-box for the machinery you want to learn
- link-cut tree looks close, but auxiliary splay trees still feel mysterious

## Warm-Up

- explain why amortized `O(log n)` is the right guarantee here
- say the difference between:
  - PBDS order statistics
  - treap split/merge
  - splay self-adjustment
  - link-cut auxiliary splay trees

## Core

- read [Splay Tree](../../../../topics/data-structures/splay-tree/README.md)
- focus on `rotate`, `splay`, subtree sizes, and duplicates via `cnt`
- trust the first route as one ordered multiset, not a full sequence or dynamic-tree lane

## Flagship Rep

- [Ordinary Balanced Tree](ordinarybalancedtree.md)

This is the exact first benchmark where the structure itself is the problem.

## Compare Practice

- [ORDERSET - Order Statistic Set](https://www.spoj.com/problems/ORDERSET/)
  Compare the same interface against the repo's
  [PBDS lane](../pbds-order-statistics/README.md).
- [Luogu P3391 - 文艺平衡树](https://www.luogu.com.cn/problem/P3391)
  Stretch route once you want to see how splay can move from ordered sets into
  sequence reversals.

## Exit Criteria

You are ready to leave this lane when:

- you can explain `zig`, `zig-zig`, and `zig-zag`
- you can maintain subtree size and duplicates safely
- you can say clearly why PBDS or treap is still often simpler
- you can reopen [Link-Cut Tree](../../graphs/link-cut-tree/README.md) without treating splay as magic

## Main Routes Back

- [Splay Tree hot sheet](../../../../notebook/splay-tree-hot-sheet.md)
- [PBDS / Order Statistics Tree ladder](../pbds-order-statistics/README.md)
- [Treap / Implicit Treap ladder](../treap-implicit/README.md)
- [Link-Cut Tree ladder](../../graphs/link-cut-tree/README.md)
