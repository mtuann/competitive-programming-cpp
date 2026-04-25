# Offline Tricks Hot Sheet

Use this page when all queries are known in advance and the main question is which batching or sweep invariant makes the online structure disappear.

## Do Not Use When

- answers depend on previous answers in a way that blocks reordering
- the problem is truly online and the statement order is binding
- one static array trick already solves the task without any reordering

## Choose By Signal

- sort events and queries by one monotone key, then sweep once -> [`offline-query-skeleton.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/offline-query-skeleton.cpp)
- queries share one right endpoint or threshold dimension -> offline sweep before reaching for a heavier online tree
- add/remove one interval while moving a window -> Mo's algorithm family
- answer is monotone in one hidden parameter -> parallel binary search
- deletions are the hard part -> rollback or time-segmentation route

## Core Invariants

- offline legality comes first: reordering must preserve what each query is asking
- one-key sweep problems maintain one monotone pointer or eligibility frontier
- every reordered query needs its original id so answers return to statement order
- the repo starter only covers the narrow sorted-sweep branch, not Mo or rollback machinery

## Main Traps

- treating “all queries are known first” as sufficient without proving reordering safety
- forgetting original indices and then printing answers in sorted order
- overclaiming the starter as a generic offline engine when it is only a one-key sweep scaffold
- forcing offline processing onto tasks whose state changes are not monotone

## Exact Starters In This Repo

- one-key monotone sweep -> [`offline-query-skeleton.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/offline-query-skeleton.cpp)
- current-range maintenance with symmetric endpoint moves -> [Mo's hot sheet](mos-hot-sheet.md)
- flagship repo note -> [Distinct Values Queries](../practice/ladders/data-structures/offline-tricks/distinctvaluesqueries.md)
- exact current-range route -> [Powerful Array](../practice/ladders/data-structures/mos-algorithm/powerfularray.md)
- deletion / rollback lane -> [DSU Rollback hot sheet](dsu-rollback-hot-sheet.md) + [Dynamic Connectivity](../practice/ladders/data-structures/dsu-rollback/dynamicconnectivity.md)
- compare against online range structures -> [Data structures cheatsheet](data-structures-cheatsheet.md)

## Reopen Paths

- family chooser, Mo, PBS, and rollback boundaries -> [Offline Tricks](../topics/data-structures/offline-tricks/README.md)
- exact Mo lane -> [Mo's Algorithm](../topics/data-structures/mos-algorithm/README.md)
- exact rollback-over-time route -> [DSU Rollback / Offline Dynamic Connectivity](../topics/data-structures/dsu-rollback/README.md)
- lighter structure alternatives -> [Data structures cheatsheet](data-structures-cheatsheet.md)
- snippet map -> [Template Library](../template-library.md)
