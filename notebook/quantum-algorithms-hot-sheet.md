# Quantum Algorithms Hot Sheet

Use this page when the repo's exact quantum route is:

- one promise problem
- one Boolean oracle
- one Deutsch-Jozsa simulator
- one `constant vs balanced` classification

## Do Not Use When

- the task needs real quantum hardware modeling
- the real topic is Grover, Shor, phase estimation, or HHL
- the interest is classical randomness, not quantum superposition
- the goal is practical contest performance on explicit oracle tables

## Exact Route In This Repo

- read full truth table of `f : {0,1}^n -> {0,1}`
- map to phase signs `(-1)^{f(x)}`
- compute the `|0^n>` amplitude numerator:
  - `sum_x (-1)^{f(x)}`
- classify:
  - `±2^n` -> `CONSTANT`
  - `0` -> `BALANCED`

## Recognition Cues

- promise `constant or balanced`
- oracle / black-box framing
- Hadamard layers are the whole lesson
- this is a breadth benchmark, not a contest-core tool

## Core Invariants

- the Deutsch-Jozsa guarantee is promise-based
- the zero-state amplitude is the decisive signal on this route
- explicit truth-table input means this repo benchmark is simulator-first, not a quantum speedup claim

## Main Traps

- dropping the promise and pretending the same classifier still means the same thing
- overclaiming the explicit truth-table benchmark as a practical speedup
- confusing this lane with full quantum algorithm coverage

## Exact Starter In This Repo

- starter -> [`deutsch-jozsa-simulator.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/advanced/deutsch-jozsa-simulator.cpp)
- flagship rep -> [Deutsch-Jozsa Oracle Benchmark](../practice/ladders/advanced/quantum-algorithms/deutschjozsa.md)
- classical sibling -> [FWHT / XOR Convolution / Subset Convolution](../topics/dp/fwht-subset-convolution/README.md)

## Reopen Paths

- full tutorial -> [Quantum Algorithms](../topics/advanced/quantum-algorithms/README.md)
- parent router -> [Advanced overview](../topics/advanced/README.md)
- retrieve layer -> [Build Kit](../docs/build-kit.md) and [Template Library](../template-library.md)
