# X-Fast / Y-Fast Hot Sheet

Use this page when the real lesson is bounded-universe predecessor / successor through prefix hashing, not one ordinary ordered set and not xor greediness.

## Do Not Use When

- the task is max-xor against one stored value -> [Binary Trie hot sheet](binary-trie-hot-sheet.md)
- online rank / `k`-th is the actual invariant -> [Order Statistics Tree hot sheet](order-statistics-tree-hot-sheet.md)
- one ordinary contest ordered set is enough -> `set` or [PBDS / Order Statistics Tree](../topics/data-structures/pbds-order-statistics/README.md)

## Choose By Signal

- fixed-width bounded integer universe + predecessor / successor -> `X-Fast Trie`
- same job, but you now care about fixing x-fast's space / update cost -> `Y-Fast Trie`
- fixed-width integer universe + xor-max objective -> `Binary Trie`

## Core Invariants

- every existing prefix is stored in exactly one hash table for its depth
- leaves stay linked in sorted order
- one-child internal nodes carry a jump to the nearest surviving leaf on that side
- all keys use one fixed bit width

## Main Traps

- forgetting that x-fast is `O(nw)` space, not one magical contest default
- mixing predecessor / successor logic with xor-greedy trie walks
- claiming y-fast when only x-fast machinery is implemented

## Exact Starter Route

- exact starter -> [`x-fast-trie.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/x-fast-trie.cpp)
- flagship rep -> [X-Fast Dictionary](../practice/ladders/data-structures/x-fast-y-fast-tries/xfastdictionary.md)
- compare route -> [Binary Trie / XOR Queries](../topics/data-structures/binary-trie-xor/README.md)
- compare route -> [Skip Lists](../topics/data-structures/skip-lists/README.md)

## Reopen Paths

- full lesson -> [X-Fast / Y-Fast Tries](../topics/data-structures/x-fast-y-fast-tries/README.md)
- xor-bit route -> [Binary Trie hot sheet](binary-trie-hot-sheet.md)
- ordered-set fallback -> [Order Statistics Tree hot sheet](order-statistics-tree-hot-sheet.md)
- textbook breadth sibling -> [Skiplist hot sheet](skiplist-hot-sheet.md)
