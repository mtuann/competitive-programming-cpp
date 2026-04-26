# Deutsch-Jozsa Oracle Benchmark

- Title: `Deutsch-Jozsa Oracle Benchmark`
- Judge / source: `Canonical quantum promise-problem benchmark`
- Original URL: [https://ocw.mit.edu/courses/6-845-quantum-complexity-theory-fall-2010/resources/mit6_845f10_lec05/](https://ocw.mit.edu/courses/6-845-quantum-complexity-theory-fall-2010/resources/mit6_845f10_lec05/)
- Secondary topics: `Deutsch-Jozsa`, `Phase oracle`, `Hadamard transform`
- Difficulty: `medium`
- Subtype: `Promise problem simulator for constant-vs-balanced Boolean oracles`
- Status: `solved`
- Solution file: [deutschjozsa.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/quantum-algorithms/deutschjozsa.cpp)

## Why Practice This

This is the cleanest first in-repo anchor for `Quantum Algorithms`.

The benchmark is intentionally narrow:

- one Boolean oracle
- one promise problem
- one simulator-friendly invariant
- one yes/no classification

So the whole lesson is exactly the lane itself:

- what the promise is
- why the phase-sign sum matters
- how the final Hadamard layer exposes `constant` vs `balanced`

## Recognition Cue

Reach for this route when:

- the benchmark explicitly invokes Deutsch-Jozsa
- the oracle promise is `constant or balanced`
- the whole job is to preserve the structure of one tiny quantum algorithm in a classical simulator

The strongest smell is:

```text
I want one honest quantum-algorithm breadth benchmark, not a full quantum toolkit.
```

That is exactly this note.

## Problem-Specific Route

This repo's benchmark uses:

- one integer `n`
- one list of `2^n` bits giving `f(x)` in lexicographic order
- the promise that `f` is constant or balanced

The route is:

1. convert `f(x)` into phase signs `(-1)^{f(x)}`
2. sum those signs
3. classify:
   - absolute sum `2^n` -> `CONSTANT`
   - sum `0` -> `BALANCED`

This is exactly the `|0^n>` amplitude test in simulator form.

## Core Idea

The first route does not need the entire quantum state.

It only needs the one decisive scalar:

$$
\sum_x (-1)^{f(x)}.
$$

### 1. Constant Oracle

If all outputs are the same, then every phase sign matches.

So the sum is:

- `+2^n` if all outputs are `0`
- `-2^n` if all outputs are `1`

### 2. Balanced Oracle

If exactly half the outputs are `0` and half are `1`, then half the signs are `+1` and half are `-1`.

So the sum is:

- `0`

### 3. Why The Repo Uses A Simulator

With the whole truth table already explicit, a classical counter can also solve the promise problem.

This repo lane must say that directly.

The purpose is not classical advantage.
The purpose is preserving the algorithmic shape of the Deutsch-Jozsa benchmark.

## Complexity

With `N = 2^n` oracle entries:

- time = `O(N)`
- extra memory = `O(1)` if streamed

The benchmark is breadth-first, not performance-first.

## Input / Output Contract For This Repo

This repo's benchmark uses:

- one integer `n`
- one line with `2^n` bits `f(0), f(1), ..., f(2^n - 1)`

The solution prints exactly one line:

- `CONSTANT`
- or `BALANCED`

This is a repo-native benchmark, not one standard online judge task.

## Pitfalls / Judge Notes

- The route assumes the Deutsch-Jozsa promise; without it, the same output labels are not the same problem.
- This benchmark is simulator-first and does not claim practical quantum advantage on explicit truth-table input.
- The key invariant is the zero-state amplitude numerator, not generic counting language alone.
- This note does not stand in for Grover, Shor, or full circuit simulation.

## Reusable Pattern

- Topic page: [Quantum Algorithms](../../../../topics/advanced/quantum-algorithms/README.md)
- Practice ladder: [Quantum Algorithms ladder](README.md)
- Starter template: [deutsch-jozsa-simulator.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/advanced/deutsch-jozsa-simulator.cpp)
- Notebook refresher: [Quantum Algorithms hot sheet](../../../../notebook/quantum-algorithms-hot-sheet.md)
- Compare points:
  - [FWHT / XOR Convolution / Subset Convolution](../../../../topics/dp/fwht-subset-convolution/README.md)
  - [Randomized Algorithms](../../../../topics/advanced/randomized-algorithms/README.md)

## Solutions

- Code: [deutschjozsa.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/quantum-algorithms/deutschjozsa.cpp)
