# Distinct Numbers

- Title: `Distinct Numbers`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1621](https://cses.fi/problemset/task/1621)
- Secondary topics: `sort`, `unique`, `Container choice`
- Difficulty: `easy`
- Subtype: `Count how many different values appear in one array`
- Status: `solved`
- Solution file: [distinctnumbers.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/stl/distinctnumbers.cpp)

## Why Practice This

This is a great first STL note because the whole problem is smaller than the toolbox choice:

- do we use `set`?
- do we sort and call `unique`?
- do we reach for hashing?

That is exactly the kind of decision basic STL fluency should make feel natural.

## Key Idea

One clean solution is:

1. read the numbers into a `vector`
2. `sort` the vector
3. call `unique`
4. count how many values remain

After sorting, equal values become consecutive. `unique` then compacts the vector so only one representative of each equal block stays in the prefix.

So the number of distinct values is:

```text
unique_end - values.begin()
```

This is a nice STL-basics exercise because the real work is done by standard algorithms rather than custom logic.

A `set` or `unordered_set` would also work, but `sort + unique` is especially educational here because it teaches two very common contest tools at once.

## Complexity

- sorting: `O(n log n)`
- `unique`: `O(n)`
- total: `O(n log n)`

## Pitfalls / Judge Notes

- `unique` does not erase elements by itself; it returns the new logical end iterator.
- Always sort before using `unique` if you want to remove all duplicates by value.
- This problem only asks for the count, so you do not need to preserve original order.

## Reusable Pattern

- Topic page: [STL Basics](../../../../topics/foundations/cpp-language/README.md)
- Practice ladder: [STL Basics ladder](README.md)
- Starter template: [sort-and-comparator.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/sort-and-comparator.cpp)
- Notebook refresher: [Foundations cheatsheet](../../../../notebook/foundations-cheatsheet.md)
- Carry forward: pick the STL tool by the operation you need most often, not by habit.
- This note adds: the container or algorithm choice that best matches this statement.

## Solutions

- Code: [distinctnumbers.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/stl/distinctnumbers.cpp)
