# Missing Number

- Title: `Missing Number`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1083](https://cses.fi/problemset/task/1083)
- Secondary topics: `Running total`, `long long discipline`, `Input fluency`
- Difficulty: `easy`
- Subtype: `Recover one missing value from the range 1..n`
- Status: `solved`
- Solution file: [missingnumber.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/cpp-language/missingnumber.cpp)

## Why Practice This

This is a strong first note for the repo because almost nothing here is algorithmically hard.

That is exactly the point.

It lets you practice the beginner loop cleanly:

- read input without friction
- choose a safe integer type
- write one tiny invariant
- compile and run without fighting syntax

If this problem still feels noisy, it usually means the local C++ workflow needs a little more repetition before harder topics.

## Key Idea

The numbers should be exactly:

```text
1 + 2 + ... + n
```

but one value is missing from the input.

So:

1. compute the expected total of `1..n`
2. subtract every value that actually appears
3. the remaining value is the answer

The standard arithmetic-sum formula is:

```text
n * (n + 1) / 2
```

That total should be stored in `long long`, not `int`, because the intermediate multiplication can exceed 32-bit range.

This is a great beginner habit:

- the code is tiny
- the variable meanings are simple
- type discipline still matters

## Complexity

- one pass over the input: `O(n)`
- memory: `O(1)`

## Pitfalls / Judge Notes

- Use `long long` for the running total and the expected sum.
- The missing value is from `1..n`, while the input contains only `n - 1` numbers.
- This is a perfect warm-up for the compile/run loop. Do not overengineer it with extra containers if you do not need them.

## Reusable Pattern

- Topic page: [C++ Language For Contests](../../../../topics/foundations/cpp-language/README.md)
- Practice ladder: [C++ Language ladder](README.md)
- Starter template: [contest-main.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/contest-main.cpp)
- Notebook refresher: [Foundations cheatsheet](../../../../notebook/foundations-cheatsheet.md)
- Carry forward: use tiny problems to stabilize I/O, types, and compile discipline before chasing harder patterns.
- This note adds: the simplest possible example where `long long` still matters.

## Solutions

- Code: [missingnumber.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/cpp-language/missingnumber.cpp)
