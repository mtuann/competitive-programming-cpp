# Quantum Algorithms

This lane exists as a **textbook-breadth advanced lane**, not as a claim that competitive programming now needs a working quantum-computing stack.

The repo's exact first route is intentionally narrow:

- one promise problem
- one Boolean oracle `f : {0,1}^n -> {0,1}`
- promise: `f` is either constant or balanced
- one Deutsch-Jozsa circuit idea
- one classical simulator that preserves the algorithmic structure

That means this page is **not**:

- a quantum-physics course
- a hardware page
- a general quantum-circuit toolkit
- a full lane for Grover, Shor, or phase estimation

It is the first clean algorithmic route for:

- phase kickback
- Hadamard layers
- the Deutsch-Jozsa promise problem
- one tiny quantum-algorithm benchmark that can still live honestly inside a classical repo

with [Deutsch-Jozsa Oracle Benchmark](../../../practice/ladders/advanced/quantum-algorithms/deutschjozsa.md) as the flagship benchmark.

This page sits next to:

- [Randomized Algorithms](../randomized-algorithms/README.md) because both lanes broaden the usual deterministic classical worldview
- [FWHT / XOR Convolution / Subset Convolution](../../dp/fwht-subset-convolution/README.md) because the Hadamard layer has a strong classical transform sibling
- [Complexity And Hardness](../complexity-and-hardness/README.md) when the real goal is complexity-separation language rather than one concrete simulator

## At A Glance

- **Use when:**
  - you want one algorithmic quantum-breadth lane without pretending the repo is a quantum-computing curriculum
  - the benchmark is the Deutsch-Jozsa promise problem
  - you want the first route where Hadamard layers and phase signs are the whole lesson
  - you are comfortable with this being a simulator / teaching benchmark, not a contest-core tool
- **Prerequisites:**
  - [Reasoning](../../foundations/reasoning/README.md)
  - [FWHT / XOR Convolution / Subset Convolution](../../dp/fwht-subset-convolution/README.md) is a helpful sibling, not a strict prereq
- **Boundary with nearby pages:**
  - use this page when the exact lesson is one classical simulation of the Deutsch-Jozsa route
  - use [Randomized Algorithms](../randomized-algorithms/README.md) when the real topic is probability-backed classical design
  - use [Complexity And Hardness](../complexity-and-hardness/README.md) when the lesson is complexity classes and reductions, not one circuit idea
- **Strongest cues:**
  - oracle / black-box viewpoint
  - promise `constant or balanced`
  - Hadamard transform / phase oracle language
  - interest in the first iconic quantum speedup toy problem
- **Strongest anti-cues:**
  - the task needs realistic quantum hardware modeling
  - the real algorithm is Grover / Shor / phase estimation
  - the benchmark expects a practical classical speedup from the explicit truth-table I/O
  - the repo user actually wants a full quantum-information course
- **Success after studying this page:**
  - you can explain what the Deutsch-Jozsa promise problem is
  - you can state why the `|0^n>` amplitude distinguishes `constant` from `balanced`
  - you know why this lane is breadth and simulator-first, not contest-core

## Problem Model And Notation

The exact starter route in this repo uses:

- one integer `n`
- one oracle truth table `f(x)` for all `x in {0,1}^n`
- the promise that `f` is either:
  - `constant`
  - or `balanced` with exactly half `0` and half `1`

The Deutsch-Jozsa quantum route applies:

1. Hadamard on the `n` input qubits
2. phase oracle `(-1)^{f(x)}`
3. Hadamard again
4. measure the input register

On this exact route, the amplitude of `|0^n>` after the final Hadamard layer is:

$$
\frac{1}{2^n}\sum_{x \in \{0,1\}^n} (-1)^{f(x)}.
$$

So:

- if `f` is constant, the numerator is `+2^n` or `-2^n`
- if `f` is balanced, the numerator is `0`

The repo's classical simulator works directly with that invariant.

This is deliberate.

Why:

- it keeps the lane algorithmic instead of hardware-heavy
- it preserves the real Deutsch-Jozsa logic
- it avoids pretending explicit truth-table input is where quantum speedup would live in practice

## Why This Exists Next To FWHT

[FWHT / XOR Convolution / Subset Convolution](../../dp/fwht-subset-convolution/README.md) teaches a classical transform family built from the same Hadamard-pattern matrix.

This page teaches a different lens:

- not convolution
- not subset algebra
- but one quantum-circuit benchmark whose acceptance signal is driven by the Hadamard basis

So the division of labor is:

- **FWHT page:** classical transform technique on the Boolean cube
- **quantum-algorithms page:** first promise-problem simulator using the same transform shape

## Core Route In This Repo

The exact route is:

1. read the full oracle truth table
2. build the phase-sign vector `(-1)^{f(x)}`
3. compute the zero-state amplitude numerator
4. classify:
   - nonzero full-magnitude numerator -> `CONSTANT`
   - zero numerator -> `BALANCED`

The exact starter contract is intentionally narrow:

- one promise problem only
- one classical simulator only
- one full-truth-table oracle representation
- one yes/no style classification

The exact non-promises matter:

- no universal quantum-circuit simulator
- no noisy gates or measurement models
- no Shor / Grover / Simon coverage
- no claim that this route is practically useful for ordinary CP tasks

## Core Invariants

### 1. This Is A Promise Problem

The route assumes the oracle is either:

- constant
- or balanced

If you drop that promise, the original Deutsch-Jozsa guarantee is no longer the same problem.

### 2. The Key Signal Is The `|0^n>` Amplitude

The benchmark does not need the whole final state.

For this exact promise problem, the only decisive quantity is:

$$
\sum_x (-1)^{f(x)}.
$$

That is the compact invariant the repo starter exposes.

### 3. The Repo Route Is A Classical Simulator, Not A Speedup Claim

Given the whole truth table explicitly, a classical counter can also detect `constant` vs `balanced`.

This lane must say that out loud.

The point here is:

- preserve the algorithmic structure of the quantum route
- keep the breadth topic from staying vague
- not claim a practical advantage on this repo-native I/O

## Worked Example: Deutsch-Jozsa Oracle Benchmark

Use [Deutsch-Jozsa Oracle Benchmark](../../../practice/ladders/advanced/quantum-algorithms/deutschjozsa.md).

For `n = 3`, there are `8` inputs.

If the oracle is:

- all zeroes, then `f` is constant
- `0 0 0 0 1 1 1 1`, then `f` is balanced

The phase-sign sum is:

- `+8` in the constant-zero case
- `0` in the balanced case

So the benchmark prints:

- `CONSTANT`
- or `BALANCED`

That is the first route the lane wants you to reopen quickly.

## Variant Chooser

| Situation | Best first move | Why it fits | Where it fails |
| --- | --- | --- | --- |
| one tiny promise-problem simulator for the first iconic quantum algorithm | use this lane | the Deutsch-Jozsa structure is exactly the lesson | weak if the real interest is fuller quantum algorithm families |
| the shared object is really the Hadamard transform on the Boolean cube | use [FWHT / XOR Convolution / Subset Convolution](../../dp/fwht-subset-convolution/README.md) | that page is the real classical transform route | weak if the point is the quantum promise problem itself |
| the lesson is probabilistic classical design, not quantum states | use [Randomized Algorithms](../randomized-algorithms/README.md) | randomness is the actual tool there | weak if you really want the Deutsch-Jozsa circuit idea |
| the goal is complexity / class language instead of a concrete simulator | use [Complexity And Hardness](../complexity-and-hardness/README.md) | that page owns the broader theory framing | weak if the missing piece is still the basic benchmark |

## Complexity And Tradeoffs

With oracle size `N = 2^n`, the exact repo route is:

- `O(N)` time
- `O(1)` extra memory beyond the read buffer if streamed

The point is not asymptotic wow-factor on this explicit input model.

The real tradeoff is:

- very honest breadth coverage
versus
- zero pretense that this is a standard contest weapon

That is why the lane belongs in `advanced` and `breadth`.

## Main Traps

- forgetting that Deutsch-Jozsa is a promise problem
- claiming practical speedup on the explicit truth-table benchmark
- drifting into full quantum-course material that the repo does not support
- confusing Hadamard-transform structure with ordinary FFT/NTT use cases
- pretending this first route already covers Grover or Shor

## Reopen Path

- Topic page: [Quantum Algorithms](README.md)
- Practice ladder: [Quantum Algorithms ladder](../../../practice/ladders/advanced/quantum-algorithms/README.md)
- Starter template: [deutsch-jozsa-simulator.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/advanced/deutsch-jozsa-simulator.cpp)
- Notebook refresher: [Quantum Algorithms hot sheet](../../../notebook/quantum-algorithms-hot-sheet.md)
- Compare points:
  - [FWHT / XOR Convolution / Subset Convolution](../../dp/fwht-subset-convolution/README.md)
  - [Randomized Algorithms](../randomized-algorithms/README.md)
  - [Deutsch-Jozsa Oracle Benchmark](../../../practice/ladders/advanced/quantum-algorithms/deutschjozsa.md)

## References And Practice

- [MIT OpenCourseWare 6.845 lecture note on Deutsch-Jozsa](https://ocw.mit.edu/courses/6-845-quantum-complexity-theory-fall-2010/resources/mit6_845f10_lec05/)
- [MIT 8.370x Quantum Information Science I and II](https://www.ocw.mit.edu/courses/8-370x-quantum-information-science-i-spring-2018/)
- [Watrous quantum computation notes](https://cs.uwaterloo.ca/~watrous/QC-notes/)
