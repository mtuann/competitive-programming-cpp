# Sum of Two Values

- Title: `Sum of Two Values`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1640](https://cses.fi/problemset/task/1640)
- Secondary topics: `Sort and scan`, `Original index recovery`, `Opposite-end pointers`
- Difficulty: `medium`
- Subtype: `Find two distinct positions whose values sum to a target`
- Status: `solved`
- Solution file: [sumoftwovalues.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/two-pointers/sumoftwovalues.cpp)

## Why Practice This

This is one of the cleanest first examples of the "sorted opposite-end pointers" pattern.

It teaches three useful habits together:

- sort the data to create monotonicity
- move only one pointer at a time based on what the sum tells you
- preserve original indices even after sorting

That makes it a great bridge between simple sorting tasks and full sliding-window reasoning.

## Key Idea

Store each number together with its original index, then sort by value.

Let:

- `l` start at the smallest value
- `r` start at the largest value

At every step, check:

```text
values[l] + values[r]
```

There are only three cases:

- if the sum is too small, move `l` right
- if the sum is too large, move `r` left
- if the sum matches the target, output the two original indices

Why is this valid after sorting?

Because increasing `l` can only increase the sum, and decreasing `r` can only decrease the sum. That monotone behavior is exactly what makes two pointers work here.

## Complexity

- sorting: `O(n log n)`
- two-pointer scan: `O(n)`
- total: `O(n log n)`

## Pitfalls / Judge Notes

- You must output the original positions, not the sorted positions.
- The two chosen elements must be distinct, so the loop should run while `l < r`.
- Use `long long` for the sum if you want one less thing to worry about when values get large.
- If no pair works, print `IMPOSSIBLE`.

## Reusable Pattern

- Topic page: [Two Pointers And Sliding Window](../../../../topics/foundations/patterns/two-pointers/README.md)
- Practice ladder: [Two Pointers ladder](README.md)
- Starter template: [sort-and-comparator.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/sort-and-comparator.cpp)
- Notebook refresher: [Foundations cheatsheet](../../../../notebook/foundations-cheatsheet.md)
- Carry forward: sorted order can create exactly the monotonicity two pointers needs.
- This note adds: the "sort values but keep original indices" version of the pattern.

## Solutions

- Code: [sumoftwovalues.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/two-pointers/sumoftwovalues.cpp)
