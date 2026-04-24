# Range Update Queries

- Title: `Range Update Queries`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1651](https://cses.fi/problemset/task/1651)
- Secondary topics: `Dynamic difference array`, `Fenwick tree`, `Range-add point-query`
- Difficulty: `medium`
- Subtype: `Support range additions and point-value queries on an initial array`
- Status: `solved`
- Solution file: [rangeupdatequeries.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/difference-arrays/rangeupdatequeries.cpp)

## Why Practice This

This is a perfect bridge problem between the *idea* of a difference array and the *data structure* needed when updates and queries are interleaved.

Offline difference arrays say:

- add `x` to `[l, r]`
- mark `+x` at `l`
- mark `-x` at `r + 1`
- rebuild the final array with one prefix pass

This problem asks for point values in the middle of the process, so we need that same difference-array view, but maintained dynamically.

## Recognition Cue

Reach for this pattern when:

- updates affect whole ranges
- queries ask for one position or one prefix state
- the array starts with initial values, but updates and queries are interleaved
- the offline difference-array trick feels almost right except that you must answer before all updates finish

The key smell is:

- "range add, point query"

That is usually a hint to store updates at the boundaries and reconstruct one point by taking a prefix.

## Problem-Specific Transformation

The raw statement sounds dynamic, but the right rewrite is:

- stop thinking about the values `a[i]` directly
- maintain the difference array `diff`

One update on `[l, r]` becomes only:

- `diff[l] += u`
- `diff[r + 1] -= u`

Then a point query at `k` is just:

- prefix sum of `diff[1..k]`

So the problem is no longer "dynamic range updates on the array." It becomes:

- point updates on `diff`
- prefix queries on `diff`

That is exactly the Fenwick-friendly formulation.

## Core Idea

Let the original array be `a[1..n]`. Define the difference array:

```text
diff[1] = a[1]
diff[i] = a[i] - a[i - 1]   for i >= 2
```

Then one range update:

```text
add u on [l, r]
```

becomes only two point updates on `diff`:

```text
diff[l] += u
diff[r + 1] -= u   (if r + 1 <= n)
```

Why does that work?

Because after taking prefix sums, every position from `l` to `r` accumulates `+u`, and everything after `r` gets canceled by the `-u` boundary mark.

Now the value at index `k` is:

```text
a[k] = diff[1] + diff[2] + ... + diff[k]
```

So the whole problem becomes:

- point updates on `diff`
- prefix-sum queries on `diff`

That is exactly what a Fenwick tree does well.

## Complexity

- build initial difference array into Fenwick: `O(n log n)`
- each range update: `O(log n)`
- each point query: `O(log n)`

## Pitfalls / Judge Notes

- This is not a plain offline difference-array problem because queries appear between updates.
- The `r + 1` boundary update must be skipped when `r == n`.
- Querying position `k` means taking the prefix sum of the dynamic difference array up to `k`.
- The conceptual trick is difference arrays; the supporting structure is Fenwick.

## Reusable Pattern

- Topic page: [Difference Arrays](../../../../topics/foundations/patterns/difference-arrays/README.md)
- Practice ladder: [Difference Arrays ladder](README.md)
- Starter template: [difference-array.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/difference-array.cpp)
- Notebook refresher: [Foundations cheatsheet](../../../../notebook/foundations-cheatsheet.md)
- Carry forward: encode updates at boundaries first, then reconstruct the final values with one prefix pass.
- This note adds: the query model and indexing details for this specific update pattern.

## Solutions

- Code: [rangeupdatequeries.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/difference-arrays/rangeupdatequeries.cpp)
