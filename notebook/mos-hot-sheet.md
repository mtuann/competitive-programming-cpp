# Mo's Algorithm Hot Sheet

Use this page when one static array has many range queries, all queries are known first, and the answer-state is easy to update after moving one endpoint by one step.

## Do Not Use When

- one monotone sweep invariant already solves the task -> [Offline Tricks](offline-tricks-hot-sheet.md)
- updates happen between queries and you have not modeled the time dimension
- the statistic is still expensive even after moving one endpoint by one
- the problem is really a tree/path reduction first

## Choose By Signal

- right endpoint or threshold only moves forward -> [Offline Tricks hot sheet](offline-tricks-hot-sheet.md)
- one active range `[L, R]` is the whole state, and add/remove are cheap -> `Mo's algorithm`
- static array + heavy frequency-based score -> `Mo's algorithm` before forcing a segment tree
- add/remove edge timeline -> [DSU Rollback hot sheet](dsu-rollback-hot-sheet.md)

## Core Invariants

- the maintained structure must represent exactly the current active range
- `add(pos)` and `remove(pos)` must be true inverses on the maintained statistic
- every query still needs its original index because processing order is changed offline
- ordinary starter here assumes inclusive `[l, r]` ranges

## Main Traps

- picking Mo when a monotone sweep is cleaner and faster
- forgetting to undo the old contribution before changing frequency
- using `int` for frequency-weighted answers that need `long long`
- stretching the ordinary starter to updates or tree queries without the extra reduction

## Exact Starter Route

- exact starter -> [mos-algorithm.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/mos-algorithm.cpp)
- flagship repo note -> [Powerful Array](../practice/ladders/data-structures/mos-algorithm/powerfularray.md)
- family compare point -> [Offline Tricks hot sheet](offline-tricks-hot-sheet.md)
- lighter compare point -> [Distinct Values Queries](../practice/ladders/data-structures/offline-tricks/distinctvaluesqueries.md)

## Reopen Paths

- family boundary and chooser -> [Offline Tricks](../topics/data-structures/offline-tricks/README.md)
- full topic page -> [Mo's Algorithm](../topics/data-structures/mos-algorithm/README.md)
- broader routing -> [Data Structures cheatsheet](data-structures-cheatsheet.md)
- snippet map -> [Template Library](../template-library.md)
