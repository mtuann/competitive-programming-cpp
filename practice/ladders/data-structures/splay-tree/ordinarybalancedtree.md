# Ordinary Balanced Tree

- Title: `普通平衡树`
- Judge / source: `Luogu`
- Original URL: [https://www.luogu.com.cn/problem/P3369](https://www.luogu.com.cn/problem/P3369)
- Secondary topics: `Splay tree`, `Ordered multiset`, `Rank`, `k-th`
- Difficulty: `hard`
- Subtype: `Self-adjusting ordered set with duplicates`
- Status: `solved`
- Solution file: [ordinarybalancedtree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/splay-tree/ordinarybalancedtree.cpp)

## Why Practice This

This is the cleanest first exact benchmark for the splay lane.

The statement is almost the structure definition:

- insert one value
- erase one value
- query rank
- query `k`-th
- predecessor
- successor

So the lesson is not hidden in modeling.

It is:

- maintain one ordered multiset
- keep subtree sizes and duplicate counts correct
- splay touched nodes to the root

## Recognition Cue

Reach for the exact starter route when:

- one changing ordered set is the whole state
- rank and `k`-th matter online
- you explicitly want the self-adjusting BST route, not PBDS or treap first

The strongest smell here is:

- "ordinary balanced tree interface, but I want to learn splaying itself"

## Problem-Specific Transformation

Maintain one dynamic multiset `S`.

Operations become:

- `1 x` -> insert `x`
- `2 x` -> erase one copy of `x`
- `3 x` -> print `count_less(x) + 1`
- `4 k` -> print the one-based `k`-th smallest
- `5 x` -> predecessor of `x`
- `6 x` -> successor of `x`

The whole problem is the ordered-set route itself.

## Core Idea

The structure keeps:

- BST order on distinct keys
- `cnt` for multiplicity
- `size` for subtree total size
- parent pointers for `rotate` and `splay`

Every important operation ends by splaying one touched node to the root.

That gives:

- rank through subtree-size accumulation on a BST descent
- `k`-th through left-size comparisons
- predecessor / successor through the usual ordered-set search logic

The new ingredient is not the ordered-set API.

It is:

- every access actively changes the root
- the tree shape follows recent access history

## Complexity

- insert: amortized `O(log n)`
- erase one: amortized `O(log n)`
- rank: amortized `O(log n)`
- `k`-th: amortized `O(log n)`
- predecessor / successor: amortized `O(log n)`
- memory: `O(n)`

## Pitfalls / Judge Notes

- multiplicity belongs in `cnt`, not duplicate physical nodes by default
- subtree `size` must include `cnt`
- after every rotation, update parents and sizes in the correct order
- this is amortized, not worst-case per single query
- if you only wanted the interface, PBDS is still shorter when GNU is allowed

## Reusable Pattern

- Topic page: [Splay Tree](../../../../topics/data-structures/splay-tree/README.md)
- Practice ladder: [Splay Tree ladder](README.md)
- Starter template: [splay-tree-ordered-set.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/splay-tree-ordered-set.cpp)
- Notebook refresher: [Splay Tree hot sheet](../../../../notebook/splay-tree-hot-sheet.md)
- Carry forward: once `rotate / splay / parent` no longer feels strange, reopen [Link-Cut Tree](../../../../topics/graphs/link-cut-tree/README.md)

## Solutions

- Code: [ordinarybalancedtree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/splay-tree/ordinarybalancedtree.cpp)
