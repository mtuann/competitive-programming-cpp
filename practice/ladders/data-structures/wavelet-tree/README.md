# Wavelet Tree Ladder

This lane is for the first moment when a static array needs **order statistics or value counting inside subarrays**, not just one mergeable aggregate.

## Who This Is For

Use this lane if:

- the array is static
- many queries ask about value order inside `a[l:r)`
- persistent segment tree feels like a plausible compare point, but versions are not the real story
- you want the clean first route before reopening wavelet matrix variants

## Warm-Up

- [Static Range Minimum Queries](../sparse-table/staticrangeminimumqueries.md)
- [Range Queries and Copies](../persistent-data-structures/rangequeriesandcopies.md)

Target skill:

- say clearly why static RMQ is easier than static order statistics, and why persistent segment tree is a compare point rather than the only route

## Core

- node = one value interval plus one order-preserving subsequence
- `pref[i]` = how many of the first `i` subsequence elements go left
- `k-th smallest` works by translating `[l, r)` into child-local intervals
- one exact flagship rep: [MKTHNUM - K-th Number](mkthnum.md)

Target skill:

- explain the child-range rewrite without appealing to "magic compression"

## Stretch

- compare against [KQUERY](https://www.spoj.com/problems/KQUERY/) for threshold-count queries
- verify the same lane on [Library Checker - Range K-th Smallest](https://judge.yosupo.jp/problem/range_kth_smallest)
- reopen wavelet matrix or rectangle / 2D variants only after the classical recursive route feels routine

Target skill:

- know when the repo starter fits exactly and when the problem has drifted into packed-bitvector or 2D variants

## Retrieval Layer

- exact quick sheet -> [Wavelet Tree hot sheet](../../../../notebook/wavelet-tree-hot-sheet.md)
- exact starter -> [wavelet-tree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/wavelet-tree.cpp)
- best compare point -> [Persistent Data Structures hot sheet](../../../../notebook/persistent-data-structures-hot-sheet.md)
- parent chooser -> [Data structures cheatsheet](../../../../notebook/data-structures-cheatsheet.md)

## Exit Criteria

You are ready to move on when:

- you can define `pref[i]` exactly
- you can translate `[l, r)` into both child intervals without hesitation
- you can explain when wavelet tree is lighter than persistent segment tree and when it is not

## External Practice

- [SPOJ - MKTHNUM](https://www.spoj.com/problems/MKTHNUM/)
- [SPOJ - KQUERY](https://www.spoj.com/problems/KQUERY/)
- [Library Checker - Range K-th Smallest](https://judge.yosupo.jp/problem/range_kth_smallest)

## Tutorial Link

- [Wavelet Tree](../../../../topics/data-structures/wavelet-tree/README.md)
