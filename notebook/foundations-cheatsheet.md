# Foundations Cheatsheet

Use this page as the short-reference layer for the beginner stack: compile/run, a few modern C++ shortcuts, and the first correctness checks worth doing before submission.

## Local Compile And Run

Default local loop:

```bash
c++ -std=c++20 -O2 -Wall -Wextra -pedantic main.cpp && ./a.out < input.txt
```

Same loop with a named binary:

```bash
c++ -std=c++20 -O2 -Wall -Wextra -pedantic main.cpp -o main && ./main < input.txt
```

What the flags are doing:

- `-std=c++20`: use the language level assumed by this repo
- `-O2`: optimize roughly like a normal judge build
- `-Wall -Wextra`: surface common mistakes early
- `-pedantic`: warn when code drifts toward non-standard behavior

## First Templates To Know

- `contest-main.cpp`
- `fast-io.cpp`
- `sort-and-comparator.cpp`
- `binary-search-first-true.cpp`
- `prefix-sum-1d.cpp`

You do not need to memorize every template. Learn a very small set until they feel predictable, and browse them through the [Template Library](../template-library.md).

## Modern C++ Short Wins

Structured bindings:

```cpp
pair<int, int> seg{l, r};
auto [left, right] = seg;
```

Range-for loops:

```cpp
long long sum = 0;
for (int x : values) sum += x;
```

Local lambda comparator:

```cpp
sort(a.begin(), a.end(), [](const Item &x, const Item &y) {
    return x.key < y.key;
});
```

`auto` for iterators or obvious long types:

```cpp
auto it = lower_bound(a.begin(), a.end(), target);
```

`emplace_back` when constructing in place:

```cpp
edges.emplace_back(u, v);
```

## Type Discipline

- use `int` for indices and small counters
- use `long long` for sums, products, weights, and most answers
- cast before multiplying when overflow is possible:

```cpp
long long area2 = 1LL * x1 * y2 - 1LL * y1 * x2;
```

## First Correctness Checklist

- What does each important variable mean right now?
- What is the indexing convention: `0..n-1`, `1..n`, or half-open `[l, r)`?
- Is the answer type large enough?
- If using prefix sums, did you define `pref[0] = 0`?
- If using binary search, do `l` and `r` have fixed meanings?
- If using two pointers, is the condition monotone enough?
- If using difference arrays, did you handle `r + 1` safely?

## Tiny Test Routine

Before submission, try:

1. smallest legal input
2. all equal values
3. strictly increasing or decreasing values
4. one edge case that attacks your invariant directly

## Good Next Reads

- [Foundations overview](../topics/foundations/README.md)
- [C++ Language For Contests](../topics/foundations/cpp-language/README.md)
- [Reasoning And Implementation Discipline](../topics/foundations/reasoning/README.md)
- [Foundations ladders](../practice/ladders/foundations/README.md)
