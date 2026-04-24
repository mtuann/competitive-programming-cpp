# Distinct Values Queries

- Title: `Distinct Values Queries`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1734](https://cses.fi/problemset/task/1734)
- Secondary topics: `Offline sweep by right endpoint`, `Fenwick tree`, `Last occurrence`
- Difficulty: `hard`
- Subtype: `Count how many distinct values appear in many static subarrays`
- Status: `solved`
- Solution file: [distinctvaluesqueries.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/offline-tricks/distinctvaluesqueries.cpp)

## Why Practice This

This problem is great offline-trick training because the online-looking question:

```text
how many distinct values are inside [l, r]?
```

becomes much simpler once we notice that all queries are known in advance.

Then we can sort queries by `r` and sweep once from left to right.

## Key Idea

Process the array from left to right. At position `i`, imagine marking exactly one active occurrence for each value:

- the most recent occurrence seen so far gets mark `1`
- every older occurrence of the same value gets mark `0`

If we maintain that invariant, then for any query `[l, r]` answered when the sweep is at `r`, the number of distinct values inside the range is just:

```text
sum(l, r)
```

over those active marks.

How do we maintain it?

When value `a[i]` appears:

1. if it appeared before at `last[a[i]]`, remove that old active mark
2. add an active mark at `i`
3. update `last[a[i]] = i`

A Fenwick tree stores these active marks and supports:

- point updates
- range-sum queries

Queries are sorted by right endpoint. As soon as the sweep reaches a query’s `r`, all information that should affect that query is already present in the Fenwick tree.

## Complexity

- sorting queries: `O(q log q)`
- each array position causes at most two Fenwick updates: `O(n log n)`
- each query is one Fenwick range sum: `O(q log n)`
- total: `O((n + q) log n)`

## Pitfalls / Judge Notes

- Offline order is part of the algorithm. Always keep the original query index so answers can be restored.
- The Fenwick tree stores “is this the latest occurrence so far?”, not raw frequencies.
- Remove the previous active occurrence before activating the new one.
- Mo’s algorithm also solves this problem, but the right-endpoint sweep is cleaner for a first offline-tricks note.

## Reusable Pattern

- Topic page: [Offline Tricks](../../../../topics/data-structures/offline-tricks/README.md)
- Practice ladder: [Offline Tricks ladder](README.md)
- Starter template: [offline-query-skeleton.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/offline-query-skeleton.cpp)
- Notebook refresher: [Data structures cheatsheet](../../../../notebook/data-structures-cheatsheet.md)
- Carry forward: sort or sweep queries so the expensive state change happens once per event, not once per query.
- This note adds: the right event ordering and state invariant for this exact offline reduction.

## Solutions

- Code: [distinctvaluesqueries.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/offline-tricks/distinctvaluesqueries.cpp)
