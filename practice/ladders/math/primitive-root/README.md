# Primitive Root Ladder

## Who This Is For

Use this lane when modular arithmetic basics feel comfortable, but "find a generator modulo `p`" still feels like abstract group theory instead of one reusable contest test.

## Warm-Up

- fast power under modulo
- factorization of `p - 1`
- order of an element modulo one prime
- why the nonzero residues modulo `p` form one cyclic group

## Core

- prime-mod generator finding through order tests
- factor `p - 1` into its distinct prime divisors
- reject a candidate `g` if one power:

$$
g^{(p-1)/q}
$$

collapses to `1`
- flagship verifier-style rep: [Primitive Root](primitiveroot.md)

## Stretch

- explain why this lane is about generators, not exponent recovery
- compare primitive-root finding with [BSGS / Discrete Log](../../../../topics/math/bsgs-discrete-log/README.md)
- compare the primitive-root doorway with the Tonelli-Shanks starter lane in [Modular Square Root / Discrete Root](../../../../topics/math/modular-square-root-discrete-root/README.md)
- say when factorization of `p - 1` becomes the real bottleneck instead of the generator test

## Retrieval Layer

- exact starter -> [primitive-root-prime.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/primitive-root-prime.cpp)
- quick reminder sheet -> [Primitive Root hot sheet](../../../../notebook/primitive-root-hot-sheet.md)
- compare points -> [BSGS / Discrete Log](../../../../topics/math/bsgs-discrete-log/README.md), [Modular Square Root / Discrete Root](../../../../topics/math/modular-square-root-discrete-root/README.md)

## Repo Anchors

- [Primitive Root](primitiveroot.md)

## Exit Criteria

You are ready to move on when you can:

- state the exact prime-divisor test for one candidate generator
- explain why checking the distinct prime divisors of `p - 1` is enough
- distinguish generator finding from discrete log and modular square-root extraction
- say when the factorization layer, not the order test, becomes the limiting step

## External Practice

- [Library Checker - Primitive Root](https://judge.yosupo.jp/problem/primitive_root)
- [Library Checker - K-th Root Mod](https://judge.yosupo.jp/problem/kth_root_mod)
- [OI Wiki - Primitive Root](https://en.oi-wiki.org/math/primitive-root/)

## Tutorial Link

- [Primitive Root](../../../../topics/math/primitive-root/README.md)
