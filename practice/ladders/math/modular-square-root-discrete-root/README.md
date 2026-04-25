# Modular Square Root / Discrete Root Ladder

## Who This Is For

Use this lane when modular arithmetic basics feel comfortable, but extracting a root inside one prime modulus still feels like a black box.

## Warm-Up

- fast power under modulo
- modular inverse versus ordinary division
- why "prime modulus" changes what algebra is legal
- the idea of quadratic residues

## Core

- test whether `a` is a quadratic residue modulo `p`
- split `p - 1 = q * 2^s` with `q` odd
- run Tonelli-Shanks to recover one root
- flagship verifier-style rep: [Sqrt Mod](sqrtmod.md)

## Stretch

- explain why the exact first route is square root, not general `k`-th root
- compare Tonelli-Shanks with the primitive-root + discrete-log route used for discrete roots
- say when composite-mod square roots are a different lane entirely

## Retrieval Layer

- exact starter -> [mod-sqrt-tonelli-shanks.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/mod-sqrt-tonelli-shanks.cpp)
- quick reminder sheet -> [Modular Square Root hot sheet](../../../../notebook/modular-square-root-hot-sheet.md)
- compare points -> [Primitive Root](../../../../topics/math/primitive-root/README.md), [BSGS / Discrete Log](../../../../topics/math/bsgs-discrete-log/README.md)

## Repo Anchors

- [Sqrt Mod](sqrtmod.md)

## Exit Criteria

You are ready to move on when you can:

- say exactly when Euler's criterion rules out a root
- explain the `p - 1 = q * 2^s` split without looking it up
- distinguish square-root extraction from exponent recovery
- explain why discrete root needs primitive-root / BSGS machinery as a follow-up lane

## External Practice

- [Library Checker - Sqrt Mod](https://judge.yosupo.jp/problem/sqrt_mod)
- [Library Checker - K-th Root Mod](https://judge.yosupo.jp/problem/kth_root_mod)
- [CP-Algorithms - Discrete Root](https://cp-algorithms.com/algebra/discrete-root.html)

## Tutorial Link

- [Modular Square Root / Discrete Root](../../../../topics/math/modular-square-root-discrete-root/README.md)
