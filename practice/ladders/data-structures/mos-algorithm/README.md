# Mo's Algorithm Ladder

This lane is for the first time you trust that `reorder queries` is not just an offline trick, but a full answer strategy for static range queries.

## Who This Is For

Use this lane if:

- [Offline Tricks](../offline-tricks/README.md) already feels real
- you can explain one monotone offline sweep, but it is still unclear when that model fails
- you can imagine a current active range `[L, R]` and cheap add/remove updates

This is a thin lane on purpose:

- one exact starter
- one strong flagship rep
- strong compare points back into `offline tricks`

## Warm-Up

- say why [Distinct Values Queries](../offline-tricks/distinctvaluesqueries.md) is **not** the best first Mo problem even though Mo can solve it
- explain one maintained statistic where the right model is "current range", not "all events up to key `K`"
- derive the four boundary moves for one query transition by hand

Target skill:

- recognize the difference between `monotone sweep` and `local window maintenance`

Warm-up compare points:

- [Offline Tricks ladder](../offline-tricks/README.md)
- [Offline Tricks topic](../../../../topics/data-structures/offline-tricks/README.md)

## Core

- ordinary array-only Mo ordering
- block sort by `l`, snake order by `r`
- symmetric `add/remove`
- exact flagship rep: [Powerful Array](powerfularray.md)

Target skill:

- say clearly what the maintained state means and why add/remove are true inverses

## Stretch

- compare against [Static Range Count Distinct](https://judge.yosupo.jp/problem/static_range_count_distinct)
- revisit [Distinct Values Queries](../offline-tricks/distinctvaluesqueries.md) and explain why the monotone sweep is cleaner there
- tree or update variants should be treated as later reductions, not as "ordinary Mo but harder"

Target skill:

- distinguish "ordinary Mo is enough" from "this has escaped into tree/time variants"

## Retrieval Layer

- exact quick sheet -> [Mo's hot sheet](../../../../notebook/mos-hot-sheet.md)
- exact starter -> [mos-algorithm.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/mos-algorithm.cpp)
- family compare point -> [Offline Tricks hot sheet](../../../../notebook/offline-tricks-hot-sheet.md)
- broader chooser -> [Data Structures cheatsheet](../../../../notebook/data-structures-cheatsheet.md)

## Repo Anchors And Compare Points

- topic page -> [Mo's Algorithm](../../../../topics/data-structures/mos-algorithm/README.md)
- family compare point -> [Offline Tricks](../../../../topics/data-structures/offline-tricks/README.md)
- lighter compare point -> [Distinct Values Queries](../offline-tricks/distinctvaluesqueries.md)
- broader routing -> [Data Structures ladder](../README.md)

The cleanest in-repo loop here is:

1. trust the family boundary in [Offline Tricks](../../../../topics/data-structures/offline-tricks/README.md)
2. learn the exact current-range invariant in [Mo's Algorithm](../../../../topics/data-structures/mos-algorithm/README.md)
3. solve or revisit [Powerful Array](powerfularray.md)
4. compare back against [Distinct Values Queries](../offline-tricks/distinctvaluesqueries.md) so the difference between `locality` and `monotone sweep` becomes crisp

## Exit Criteria

You are ready to move on when:

- you can explain why the maintained structure is exactly the answer-state for the current range
- you know when Mo is only a fallback because a cleaner sweep is missing
- you can spot when updates/tree paths have escaped the ordinary starter

## External Practice

- [Codeforces - Powerful Array](https://codeforces.com/problemset/problem/86/D)
- [Library Checker - Static Range Count Distinct](https://judge.yosupo.jp/problem/static_range_count_distinct)
- [SPOJ - D-query](https://www.spoj.com/problems/DQUERY/)

## Tutorial Link

- [Mo's Algorithm](../../../../topics/data-structures/mos-algorithm/README.md)
