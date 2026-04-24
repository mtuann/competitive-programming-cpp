# C++ Language Ladder

This ladder is about implementation fluency, not hard algorithms.

## Who This Is For

Use this ladder if:

- coding feels slower than thinking
- STL still feels fragmented
- you want fewer syntax and container-choice bugs

## First Local Loop

Use one reliable local command until it becomes muscle memory:

```bash
c++ -std=c++20 -O2 -Wall -Wextra -pedantic main.cpp && ./a.out < input.txt
```

This is the default compile/run loop to pair with the templates and notes in this repo.

If your compiler command is `g++` instead of `c++`, keep the same flags and only swap the executable name.

## Warm-Up

- simple input / output tasks
- vector and string manipulation
- pairs, structs, and record sorting
- compile, run, and slightly edit one tiny program without searching for the flags again

Target skill:

- write clean short programs without pausing on syntax

## Core

- frequency counting with `vector`, `map`, and `unordered_map`
- stack / queue / deque exercises
- comparator-based sorting
- choosing between `pair` and `struct`

Target skill:

- choose types and containers from required operations, not guesswork

## Retrieval Layer

- quick syntax + flags -> [Foundations cheatsheet](../../../../notebook/foundations-cheatsheet.md)
- contest-ready snippet inventory -> [Template Library](../../../../template-library.md)
- first container-choice note -> [Distinct Numbers](../stl/distinctnumbers.md)

## Repo Anchors

- [Missing Number](missingnumber.md)
- [Distinct Numbers](../stl/distinctnumbers.md)

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
- you rarely make accidental-copy or overflow mistakes
- you can explain why a container choice fits the needed operations

## External Practice

- [CSES Problem Set](https://cses.fi/problemset/)
- [USACO Guide](https://usaco.guide/)
- [CPPReference](https://en.cppreference.com/w/)

## Tutorial Link

- [C++ Language For Contests](../../../../topics/foundations/cpp-language/README.md)
