# X-Fast / Y-Fast Tries Ladder

This lane is for the first time one ordered-set lesson is really about
**bounded integer universe + predecessor / successor via prefix hashing** instead of one ordinary `O(log n)` tree.

## Who This Is For

Use this lane if:

- you already understand what one ordered set does
- [Binary Trie / XOR Queries](../../../../topics/data-structures/binary-trie-xor/README.md) already feels separate from ordinary ordered sets
- you now want the classical x-fast / y-fast breadth story itself

This lane is intentionally narrow:

- one exact starter
- one flagship note built around a canonical predecessor / successor benchmark
- one compare route against [PBDS / Order Statistics Tree](../../../../topics/data-structures/pbds-order-statistics/README.md)
- one compare route against [Skip Lists](../../../../topics/data-structures/skip-lists/README.md)

## Warm-Up

- explain why the universe bound `U = 2^w` is the real parameter
- explain why storing every prefix lets you binary-search depth
- explain why leaf links are still needed after the prefix search stops

Target skill:

- recognize when the real lesson is "bounded-integer predecessor structure," not "which ordinary ordered set should I use?"

## Core

- per-depth prefix hashing
- deepest-existing-prefix binary search
- leaf linked order
- jump pointers on one-child internal nodes
- exact flagship rep: [X-Fast Dictionary](xfastdictionary.md)

Target skill:

- trust the x-fast predecessor / successor route and understand why leaf order finishes the job after prefix search

## Stretch

- reopen how y-fast keeps only sampled representatives in the x-fast layer
- compare against [Binary Trie / XOR Queries](../../../../topics/data-structures/binary-trie-xor/README.md) to keep xor semantics separate
- compare against [PBDS / Order Statistics Tree](../../../../topics/data-structures/pbds-order-statistics/README.md) so the "breadth lane vs contest-first route" boundary stays honest

Target skill:

- separate x-fast mechanics from the y-fast refinement that fixes x-fast's space and update cost

## Retrieval Layer

- exact quick sheet -> [X-Fast / Y-Fast hot sheet](../../../../notebook/x-fast-y-fast-hot-sheet.md)
- exact starter -> [x-fast-trie.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/x-fast-trie.cpp)
- compare route -> [Binary Trie / XOR Queries](../../../../topics/data-structures/binary-trie-xor/README.md)
- compare route -> [PBDS / Order Statistics Tree](../../../../topics/data-structures/pbds-order-statistics/README.md)
- broader chooser -> [Data structures cheatsheet](../../../../notebook/data-structures-cheatsheet.md)

## Repo Anchors And Compare Points

- topic page -> [X-Fast / Y-Fast Tries](../../../../topics/data-structures/x-fast-y-fast-tries/README.md)
- flagship note -> [X-Fast Dictionary](xfastdictionary.md)
- compare point -> [Binary Trie / XOR Queries](../../../../topics/data-structures/binary-trie-xor/README.md)
- compare point -> [PBDS / Order Statistics Tree](../../../../topics/data-structures/pbds-order-statistics/README.md)
- compare point -> [Skip Lists](../../../../topics/data-structures/skip-lists/README.md)
- broader routing -> [Data Structures ladder](../README.md)

The cleanest in-repo loop here is:

1. reopen [Binary Trie / XOR Queries](../../../../topics/data-structures/binary-trie-xor/README.md) just enough to keep xor objectives separate from predecessor objectives
2. learn the bounded-universe route in [X-Fast / Y-Fast Tries](../../../../topics/data-structures/x-fast-y-fast-tries/README.md)
3. solve [X-Fast Dictionary](xfastdictionary.md)
4. compare back against [PBDS / Order Statistics Tree](../../../../topics/data-structures/pbds-order-statistics/README.md) so the "textbook breadth vs contest-first route" boundary stays sharp

## Exit Criteria

You are ready to move on when:

- you can explain why x-fast needs the leaf list even after hashing all prefixes
- you know the difference between x-fast and y-fast in one sentence
- you know why this family is rarely the first contest retrieval route in the repo

## External Practice

- [Open Data Structures - Data Structures for Integers](https://opendatastructures.org/newhtml/ods/latex/integers.html)

## Tutorial Link

- [X-Fast / Y-Fast Tries](../../../../topics/data-structures/x-fast-y-fast-tries/README.md)
