# Range Update Queries

- Title: `Range Update Queries`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1651](https://cses.fi/problemset/task/1651)
- Main topic: `Foundations -> Difference Arrays`
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

## Key Idea

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
