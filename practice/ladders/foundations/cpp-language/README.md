# C++ Language Ladder

This ladder is about implementation fluency, not hard algorithms.

## Who This Is For

Use this ladder if:

- coding feels slower than thinking
- STL still feels fragmented
- you want fewer syntax and container-choice bugs

## Before You Start

Open these once before touching the problems:

- deep page -> [C++ Language For Contests](../../../../topics/foundations/cpp-language/README.md)
- quick recall -> [Foundations cheatsheet](../../../../notebook/foundations-cheatsheet.md)
- when stdin/stdout is not enough -> [Local judge workflow](../../../../notebook/local-judge-workflow.md)
- when samples pass but trust is low -> [Stress testing workflow](../../../../notebook/stress-testing-workflow.md)

## First Local Loop

Use one reliable local command until it becomes muscle memory:

```bash
c++ -std=c++20 -O2 -Wall -Wextra -pedantic main.cpp -o main
./main < input.txt
```

This is the default compile/run loop to pair with the templates and notes in this repo.

If your compiler command is `g++` instead of `c++`, keep the same flags and only swap the executable name.

The first extension after this should be:

```bash
c++ -std=c++20 -O0 -g -Wall -Wextra -Wshadow -fsanitize=address,undefined -DLOCAL main.cpp -o main_dbg
./main_dbg < input.txt
```

That is the beginner-safe debug loop for “the code runs, but something feels wrong.”

If you want one optional local-only switch for `cerr` logs, keep them under `#ifdef LOCAL` and only use `-DLOCAL` on the debug build.

This ladder assumes you keep exactly those two loops until they feel boring.

## Warm-Up

- simple input / output tasks
- vector and string manipulation
- pairs, structs, and record sorting
- compile, run, and slightly edit one tiny program without searching for the flags again
- compare one `output.txt` against an `expected.txt`

## Three Input Patterns You Must Recognize

- one case: read once, solve once
- `t` cases: loop over `solve()`
- EOF-driven input: `while (cin >> x)`

If a problem still feels syntactically noisy, classify the input pattern before doing anything clever.

Target skill:

- write clean short programs without pausing on syntax

## Core

- frequency counting with `vector`, `map`, and `unordered_map`
- stack / queue / deque exercises
- comparator-based sorting
- choosing between `pair` and `struct`
- switching between release build and debug build without hesitation

Target skill:

- choose types and containers from required operations, not guesswork

## Retrieval Layer

- quick syntax + flags -> [Foundations cheatsheet](../../../../notebook/foundations-cheatsheet.md)
- contest-ready snippet inventory -> [Template Library](../../../../template-library.md)
- local debugging loops -> [Stress testing workflow](../../../../notebook/stress-testing-workflow.md)
- first container-choice note -> [Distinct Numbers](../stl/distinctnumbers.md)

## Repo Anchors

- [Weird Algorithm](weirdalgorithm.md)
- [Missing Number](missingnumber.md)
- [Distinct Numbers](../stl/distinctnumbers.md)
- [Increasing Array](../complexity-and-invariants/increasingarray.md)

## Stretch

- write the same solution twice: once quickly, once cleanly
- refactor one accepted messy solution into named helpers and clear state
- compare `vector`, `set`, `map`, and `priority_queue` on similar tasks

Target skill:

- build code that is both fast to write and easy to trust

## Exit Criteria

You are ready to move on when:

- you can build a clean contest skeleton from memory
- the compile command and stdin redirection feel automatic
- the debug / sanitizer build feels ordinary, not scary
- you can add and then remove one `#ifdef LOCAL` debug print without breaking the output
- you rarely make accidental-copy or overflow mistakes
- you can explain why a container choice fits the needed operations

## External Practice

- [CSES Problem Set](https://cses.fi/problemset/)
- [USACO Guide](https://usaco.guide/)
- [CPPReference](https://en.cppreference.com/w/)

## Tutorial Link

- [C++ Language For Contests](../../../../topics/foundations/cpp-language/README.md)
