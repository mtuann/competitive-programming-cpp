# Interval Trees Ladder

This lane is for the first time one dynamic interval set becomes the real data
structure instead of only a side effect of sorting or range processing.

## Who This Is For

Use this lane if:

- [Heaps And Ordered Sets](../../../../topics/data-structures/heaps-and-ordered-sets/README.md) already feels comfortable
- you can explain half-open interval overlap cleanly
- you now need online insert / erase / overlap checks against one live interval set

This lane is intentionally narrow:

- one exact starter
- one flagship note built around a gentle overlap benchmark
- one compare route against [Balanced BSTs For Contests](../../../../topics/data-structures/balanced-bsts/README.md)
- one compare route against [ODT / Chtholly](../../../../topics/data-structures/odt-chtholly/README.md)

## Warm-Up

- define overlap for half-open intervals `[l, r)`
- explain why `max(l1, l2) < min(r1, r2)` is the right predicate
- explain why subtree `max_r` is enough to prune the overlap search

Target skill:

- recognize when the real state is "one explicit live set of intervals," not one line array or one offline sorted list

## Core

- lexicographic BST order on `(l, r)`
- subtree `max_r`
- any-overlap query
- exact flagship rep: [Reservation System](reservationsystem.md)

Target skill:

- trust the augmented-BST route and know when it is slightly overkill but still pedagogically exact

## Stretch

- attach ids if exact duplicate intervals matter
- compare the same benchmark against a simpler predecessor/successor ordered-set solution
- branch to [ODT / Chtholly](../../../../topics/data-structures/odt-chtholly/README.md) if the real state is piecewise-constant runs under assign
- branch to [Segment Tree](../../../../topics/data-structures/segment-tree/README.md) if the real query is aggregate coverage on a fixed universe

Target skill:

- separate "dynamic interval overlap set" from both interval partitions and coordinate-aggregated range structures

## Retrieval Layer

- exact quick sheet -> [Interval Tree hot sheet](../../../../notebook/interval-tree-hot-sheet.md)
- exact starter -> [interval-tree-overlap-treap.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/interval-tree-overlap-treap.cpp)
- compare route -> [Balanced BSTs For Contests](../../../../topics/data-structures/balanced-bsts/README.md)
- compare route -> [Heaps And Ordered Sets](../../../../topics/data-structures/heaps-and-ordered-sets/README.md)
- compare route -> [ODT / Chtholly](../../../../topics/data-structures/odt-chtholly/README.md)
- broader chooser -> [Data structures cheatsheet](../../../../notebook/data-structures-cheatsheet.md)

## Repo Anchors And Compare Points

- topic page -> [Interval Trees](../../../../topics/data-structures/interval-trees/README.md)
- flagship note -> [Reservation System](reservationsystem.md)
- compare point -> [Balanced BSTs For Contests](../../../../topics/data-structures/balanced-bsts/README.md)
- compare point -> [Heaps And Ordered Sets](../../../../topics/data-structures/heaps-and-ordered-sets/README.md)
- compare point -> [ODT / Chtholly](../../../../topics/data-structures/odt-chtholly/README.md)
- broader routing -> [Data Structures ladder](../README.md)

The cleanest in-repo loop here is:

1. reopen [Heaps And Ordered Sets](../../../../topics/data-structures/heaps-and-ordered-sets/README.md) just enough to keep ordered-set neighbor logic straight
2. learn the augmented overlap route in [Interval Trees](../../../../topics/data-structures/interval-trees/README.md)
3. solve [Reservation System](reservationsystem.md)
4. compare the same benchmark against lighter neighbor-check logic so the "interval tree vs simpler ordered set" boundary stays honest

## Exit Criteria

You are ready to move on when:

- you can explain why `max_r` is the only extra subtree summary needed for this exact overlap search
- you know when interval trees are the right abstraction and when they are only a textbook detour
- you can state the half-open overlap predicate without hesitation

## External Practice

- [AOJ 0360 - Reservation System](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0360)

## Tutorial Link

- [Interval Trees](../../../../topics/data-structures/interval-trees/README.md)
