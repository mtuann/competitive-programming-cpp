# BSGS / Discrete Log Ladder

## Who This Is For

Use this lane when modular arithmetic basics feel comfortable, but problems where the exponent itself becomes the unknown still feel like a wall.

## Warm-Up

- fast power under modulo
- modular inverse through extended Euclid
- why `gcd(a, m)` changes the shape of:

$$
a^x \equiv b \pmod m
$$

## Core

- one coprime BSGS route with baby steps and giant steps
- the general contest route: `gcd` reduction first, BSGS second
- flagship verifier-style rep: [Discrete Logarithm Mod](discretelogarithmmod.md)

## Stretch

- explain why this route is about `O(sqrt(m))` memory, not "fancy modular arithmetic"
- compare plain discrete log with future primitive-root / discrete-root extensions
- compare exponent recovery with ordinary congruence solving

## Retrieval Layer

- exact starter -> [discrete-log-bsgs.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/discrete-log-bsgs.cpp)
- quick reminder sheet -> [Discrete Log hot sheet](../../../../notebook/discrete-log-hot-sheet.md)
- compare-point doorway -> [Chinese Remainder / Linear Congruences](../../../../topics/math/chinese-remainder/README.md)
- follow-up doorways -> [Primitive Root](../../../../topics/math/primitive-root/README.md), [Modular Square Root / Discrete Root](../../../../topics/math/modular-square-root-discrete-root/README.md)

## Repo Anchors

- [Discrete Logarithm Mod](discretelogarithmmod.md)

## Exit Criteria

You are ready to move on when you can:

- explain why BSGS is meet-in-the-middle, not brute force with a hash map
- justify the `gcd`-reduction stage before the coprime BSGS stage
- say exactly when `O(sqrt(m))` memory makes the route infeasible
- distinguish discrete log from linear congruence solving

## External Practice

- [Library Checker - Discrete Logarithm Mod](https://judge.yosupo.jp/problem/discrete_logarithm_mod)
- [LibreOJ #6542 - BSGS](https://loj.ac/p/6542)
- [OI Wiki - BSGS](https://en.oi-wiki.org/math/bsgs/)

## Tutorial Link

- [BSGS / Discrete Log](../../../../topics/math/bsgs-discrete-log/README.md)
