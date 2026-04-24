# Weird Algorithm

- Title: `Weird Algorithm`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1068](https://cses.fi/problemset/task/1068)
- Secondary topics: `Basic loops`, `Parity branching`, `Output discipline`
- Difficulty: `easy`
- Subtype: `Simulate one recurrence and print the full path`
- Status: `solved`
- Solution file: [weirdalgorithm.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/cpp-language/weirdalgorithm.cpp)

## Why Practice This

This is one of the best first judged problems in the whole repo.

Almost all of the value is in the local workflow:

- read one integer cleanly
- write one loop without getting lost in syntax
- branch on parity without overthinking
- print a sequence with correct spacing and a final newline

That makes it a better first anchor than a harder problem with interesting algorithms but too much implementation noise.

## Key Idea

Start from `n` and keep applying the Collatz rule:

- if `n` is even, replace it with `n / 2`
- if `n` is odd, replace it with `3n + 1`

Print every visited value until the sequence reaches `1`.

The code is tiny, but one beginner habit still matters:

- store the current value in `long long`, not `int`

Even though the input starts inside the normal CSES range, the intermediate values can grow before they come back down.

## Complexity

- one iteration per printed value
- memory: `O(1)` beyond the output stream

## Pitfalls / Judge Notes

- Use `long long` for the current value.
- Print spaces between numbers, then end with one newline.
- Do not accidentally stop before printing the final `1`.
- If the loop seems endless locally, add one temporary `cerr` under `#ifdef LOCAL` before changing the logic blindly.

## Reusable Pattern

- Topic page: [C++ Language For Contests](../../../../topics/foundations/cpp-language/README.md)
- Practice ladder: [C++ Language ladder](README.md)
- Starter template: [contest-main.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/contest-main.cpp)
- Notebook refresher: [Foundations cheatsheet](../../../../notebook/foundations-cheatsheet.md)
- Carry forward: use tiny simulation tasks to stabilize compile, run, print, and inspect habits before moving to heavier data structures.
- This note adds: the cleanest first example of a while-loop + branch + output stream that still benefits from `long long`.

## Solutions

- Code: [weirdalgorithm.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/cpp-language/weirdalgorithm.cpp)
