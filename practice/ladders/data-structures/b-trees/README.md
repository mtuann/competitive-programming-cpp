# B-Trees Ladder

This lane is for the first time one search-tree lesson is really about
**high-fanout multiway nodes** instead of one binary balancing scheme.

## Who This Is For

Use this lane if:

- you already understand what one ordered dictionary does
- [Balanced BSTs For Contests](../../../../topics/data-structures/balanced-bsts/README.md) already feels comfortable as a compare note
- you now want the classical B-tree story itself

This lane is intentionally narrow:

- one exact starter
- one flagship note built around a canonical insert/search benchmark
- one compare route against [PBDS / Order Statistics Tree](../../../../topics/data-structures/pbds-order-statistics/README.md)
- one compare route against [Treap / Implicit Treap](../../../../topics/data-structures/treap-implicit/README.md)

## Warm-Up

- explain what minimum degree `t` means
- explain why all leaves must stay at the same depth
- explain why splitting full children before descent keeps insert clean

Target skill:

- recognize when the real lesson is "multiway search tree with node capacity," not "which binary balanced tree should I use in contest code?"

## Core

- search inside one node
- child selection by separator keys
- root split
- split-full-child
- exact flagship rep: [B-Tree Dictionary](btreedictionary.md)

Target skill:

- trust the top-down insert route and understand how B-trees trade binary rotations for high fanout and splits

## Stretch

- add deletion only after the search/insert route already feels automatic
- compare against [PBDS / Order Statistics Tree](../../../../topics/data-structures/pbds-order-statistics/README.md) to keep contest ROI boundaries honest
- branch to B+ trees, disk pages, or bulk loading only after the first route is stable

Target skill:

- separate textbook breadth from the repo's first-line contest retrieval routes

## Retrieval Layer

- exact quick sheet -> [B-Tree hot sheet](../../../../notebook/b-tree-hot-sheet.md)
- exact starter -> [b-tree-insert-search.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/b-tree-insert-search.cpp)
- compare route -> [Balanced BSTs For Contests](../../../../topics/data-structures/balanced-bsts/README.md)
- compare route -> [PBDS / Order Statistics Tree](../../../../topics/data-structures/pbds-order-statistics/README.md)
- compare route -> [Treap / Implicit Treap](../../../../topics/data-structures/treap-implicit/README.md)
- broader chooser -> [Data structures cheatsheet](../../../../notebook/data-structures-cheatsheet.md)

## Repo Anchors And Compare Points

- topic page -> [B-Trees](../../../../topics/data-structures/b-trees/README.md)
- flagship note -> [B-Tree Dictionary](btreedictionary.md)
- compare point -> [Balanced BSTs For Contests](../../../../topics/data-structures/balanced-bsts/README.md)
- compare point -> [PBDS / Order Statistics Tree](../../../../topics/data-structures/pbds-order-statistics/README.md)
- compare point -> [Treap / Implicit Treap](../../../../topics/data-structures/treap-implicit/README.md)
- broader routing -> [Data Structures ladder](../README.md)

The cleanest in-repo loop here is:

1. reopen [Balanced BSTs For Contests](../../../../topics/data-structures/balanced-bsts/README.md) just enough to keep the binary-tree alternatives straight
2. learn the high-fanout route in [B-Trees](../../../../topics/data-structures/b-trees/README.md)
3. solve [B-Tree Dictionary](btreedictionary.md)
4. compare back against [PBDS / Order Statistics Tree](../../../../topics/data-structures/pbds-order-statistics/README.md) so the "breadth lane vs contest-first route" boundary stays sharp

## Exit Criteria

You are ready to move on when:

- you can describe `split-full-child` without hesitation
- you know why B-trees are not the repo's first retrieval route for ordinary CP ordered-set work
- you can explain how high fanout reduces height

## External Practice

- [Open Data Structures - 14.2 B-Trees](https://opendatastructures.org/ods-cpp/14_2_B_Trees.html)

## Tutorial Link

- [B-Trees](../../../../topics/data-structures/b-trees/README.md)
