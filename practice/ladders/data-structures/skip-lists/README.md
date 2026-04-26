# Skip Lists Ladder

This lane is for the first time one ordered-dictionary lesson is really about
**probabilistic balancing with forward-pointer towers** instead of one tree.

## Who This Is For

Use this lane if:

- you already understand ordinary ordered-set operations
- [PBDS / Order Statistics Tree](../../../../topics/data-structures/pbds-order-statistics/README.md) feels like the contest-first route
- you now want the classical skiplist mechanics themselves

This lane is intentionally narrow:

- one exact starter
- one flagship note built around a canonical ordered-dictionary benchmark
- one compare route against [PBDS / Order Statistics Tree](../../../../topics/data-structures/pbds-order-statistics/README.md)
- one compare route against [Treap / Implicit Treap](../../../../topics/data-structures/treap-implicit/README.md)

## Warm-Up

- explain how the right/down search path works
- explain why a node with height `h` appears on all lower levels
- explain what `update[]` stores during insert or erase

Target skill:

- recognize when the real lesson is probabilistic ordered-dictionary structure, not one contest retrieval shortcut

## Core

- search path on multiple levels
- random node height
- insert with `update[]`
- erase-one with `update[]`
- exact flagship rep: [Skiplist Dictionary](skiplistdictionary.md)

Target skill:

- trust the expected `O(log n)` route and understand why no rotations are needed

## Stretch

- add indexable skiplist / random-access list only after ordered-set search/insert/erase feels stable
- compare against [PBDS / Order Statistics Tree](../../../../topics/data-structures/pbds-order-statistics/README.md) to keep contest ROI boundaries honest
- compare against [B-Trees](../../../../topics/data-structures/b-trees/README.md) so probabilistic balancing does not blur into high-fanout node splitting

Target skill:

- separate textbook randomized ordered dictionaries from both tree rotations and contest-first library routes

## Retrieval Layer

- exact quick sheet -> [Skiplist hot sheet](../../../../notebook/skiplist-hot-sheet.md)
- exact starter -> [skiplist-ordered-set.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/skiplist-ordered-set.cpp)
- compare route -> [PBDS / Order Statistics Tree](../../../../topics/data-structures/pbds-order-statistics/README.md)
- compare route -> [Treap / Implicit Treap](../../../../topics/data-structures/treap-implicit/README.md)
- compare route -> [B-Trees](../../../../topics/data-structures/b-trees/README.md)
- broader chooser -> [Data structures cheatsheet](../../../../notebook/data-structures-cheatsheet.md)

## Repo Anchors And Compare Points

- topic page -> [Skip Lists](../../../../topics/data-structures/skip-lists/README.md)
- flagship note -> [Skiplist Dictionary](skiplistdictionary.md)
- compare point -> [PBDS / Order Statistics Tree](../../../../topics/data-structures/pbds-order-statistics/README.md)
- compare point -> [Treap / Implicit Treap](../../../../topics/data-structures/treap-implicit/README.md)
- compare point -> [B-Trees](../../../../topics/data-structures/b-trees/README.md)
- broader routing -> [Data Structures ladder](../README.md)

The cleanest in-repo loop here is:

1. reopen [PBDS / Order Statistics Tree](../../../../topics/data-structures/pbds-order-statistics/README.md) just enough to keep the contest-first route straight
2. learn the tower-based route in [Skip Lists](../../../../topics/data-structures/skip-lists/README.md)
3. solve [Skiplist Dictionary](skiplistdictionary.md)
4. compare back against [Treap / Implicit Treap](../../../../topics/data-structures/treap-implicit/README.md) and [B-Trees](../../../../topics/data-structures/b-trees/README.md)

## Exit Criteria

You are ready to move on when:

- you can describe `update[]` and random heights without hesitation
- you know why skip lists are expected-time rather than deterministic worst-case balancing
- you know why the repo still prefers PBDS or treap for most actual contest retrieval

## External Practice

- [Open Data Structures - 4. Skiplists](https://opendatastructures.org/ods-cpp/4_Skiplists.html)

## Tutorial Link

- [Skip Lists](../../../../topics/data-structures/skip-lists/README.md)
