# Persistent Treap Ladder

This lane is for the first time split/merge treap and persistence have to be true at the same time.

## Who This Is For

Use this lane if:

- old versions of a list or sequence stay alive
- new operations branch from those old versions
- concatenation and prefix/suffix extraction are the real edits
- persistent segment tree feels too rigid because the structure itself must be cut or glued

## Warm-Up

- [Range Queries and Copies](../persistent-data-structures/rangequeriesandcopies.md)
- [Cut and Paste](../treap-implicit/cutandpaste.md)

Target skill:

- say clearly why fixed-array path copying is not enough and why one current implicit treap is not enough either

## Core

- version roots as immutable list handles
- persistent `merge`
- persistent `split_prefix`
- subtree sum as the first carried aggregate
- flagship rep: [Persistent List](persistentlist.md)

Target skill:

- explain why "merge old lists into a new list" and "split one old list into two new lists" are exactly the persistent split/merge treap story

## Stretch

- persistent ordered-set-by-key treap as a sibling variant, not the first route
- richer sequence aggregates or lazy tags once plain list-sum persistence is trusted
- compare when a functional queue/stack or a persistent segment tree is still the lighter tool

## Retrieval Layer

- exact starter -> [persistent-treap-list-sum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/persistent-treap-list-sum.cpp)
- quick reminder sheet -> [Persistent Treap hot sheet](../../../../notebook/persistent-treap-hot-sheet.md)
- compare points -> [Persistent Data Structures](../../../../topics/data-structures/persistent-data-structures/README.md), [Treap / Implicit Treap](../../../../topics/data-structures/treap-implicit/README.md)

## Repo Anchors

- [Persistent List](persistentlist.md)

## Exit Criteria

You are ready to move on when you can:

- represent every version by one root handle
- explain why `merge` and `split` must clone touched nodes
- distinguish persistent split/merge sequence work from persistent fixed-array work
- tell when this lane is still enough and when richer lazy-tag or key-based variants are the real follow-up

## External Practice

- [E-olymp 2957 - Persistent list](https://eolymp.com/en/problems/2957)
- [HSE persistence sheet (Persistent List / Forward!)](https://cdkrot.me/teaching/2020s-algo2/statements/200417_hse.pdf)

## Tutorial Link

- [Persistent Treap](../../../../topics/data-structures/persistent-treap/README.md)
