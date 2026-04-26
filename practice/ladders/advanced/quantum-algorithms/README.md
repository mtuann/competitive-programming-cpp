# Quantum Algorithms Ladder

## Who This Is For

Use this ladder only when you intentionally want one breadth-first quantum benchmark inside an algorithms repo, not because you expect ordinary contest ROI.

## Warm-Up

- state the Deutsch-Jozsa promise exactly
- explain why `constant` and `balanced` are the only allowed oracle types
- explain what the zero-state amplitude is measuring

## Core

- phase-sign view `(-1)^{f(x)}`
- Hadamard-layer intuition
- `CONSTANT` vs `BALANCED` through the `|0^n>` amplitude

## Repo Anchors

- [Deutsch-Jozsa Oracle Benchmark](deutschjozsa.md)
- [FWHT / XOR Convolution / Subset Convolution](../../dp/fwht-subset-convolution/README.md)
- [Randomized Algorithms](../randomized-algorithms/README.md)

## Stretch

- read one note on Simon or Grover and explain why this repo lane still intentionally stops earlier
- compare Hadamard-circuit thinking with the ordinary classical Walsh-Hadamard transform

## Compare Points

- first quantum breadth benchmark -> [Deutsch-Jozsa Oracle Benchmark](deutschjozsa.md)
- same transform shape in a classical lane -> [FWHT / XOR Convolution / Subset Convolution](../../dp/fwht-subset-convolution/README.md)
- broader non-classical worldview without quantum states -> [Randomized Algorithms](../randomized-algorithms/README.md)

This ladder is intentionally tiny.

The point is not to transform the repo into a quantum-computing course.
The point is to keep one source-backed breadth topic explicit and honest.

## Exit Criteria

You are ready to move on when you can:

- explain the Deutsch-Jozsa promise problem cleanly
- derive the decisive amplitude test for `|0^n>`
- say clearly why this repo route is simulator-first and breadth-only

## External Practice

- [MIT OpenCourseWare 6.845 lecture note on Deutsch-Jozsa](https://ocw.mit.edu/courses/6-845-quantum-complexity-theory-fall-2010/resources/mit6_845f10_lec05/)
- [Watrous quantum computation notes](https://cs.uwaterloo.ca/~watrous/QC-notes/)

## Tutorial Link

- [Quantum Algorithms](../../../../topics/advanced/quantum-algorithms/README.md)
