# General Chinese Remainder

- Title: `Chinese Remainder Theorem (non-relatively prime moduli)`
- Judge / source: `Kattis`
- Original URL: [https://open.kattis.com/problems/generalchineseremainder](https://open.kattis.com/problems/generalchineseremainder)
- Secondary topics: `Chinese remainder theorem`, `Extended Euclid`, `Congruence merge`
- Difficulty: `medium`
- Subtype: `Merge two congruences with non-coprime moduli`
- Status: `solved`
- Solution file: [generalchineseremainder.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/chinese-remainder/generalchineseremainder.cpp)

## Why Practice This

This is the cleanest in-repo anchor for the first exact `Chinese Remainder / Linear Congruences` lane.

The statement gives exactly two residue conditions:

```text
x ≡ a (mod n)
x ≡ b (mod m)
```

but the important twist is:

- the moduli are **not** guaranteed to be coprime

So the lesson is not only textbook CRT.

It is:

- detect inconsistency with `gcd(n, m)`
- if the system is consistent, merge it into one residue modulo `lcm(n, m)`

## Recognition Cue

Reach for CRT merging when:

- the answer must satisfy several periodic conditions simultaneously
- the statement wants one merged residue class
- the moduli may share factors, so coprime-only CRT is too weak

The strongest smell here is:

- "output the combined solution, or say no solution"

That means you need an exact merge, not just modular arithmetic facts in isolation.

## Problem-Specific Transformation

Write the first congruence as:

$$
x = a + k n
$$

Substitute into the second:

$$
a + k n \equiv b \pmod m
$$

so:

$$
n k \equiv b - a \pmod m
$$

Now the problem is:

- solve one linear congruence for `k`
- reconstruct `x`

Let:

$$
g = \gcd(n, m)
$$

Then:

- if `(b - a) % g != 0`, there is no solution
- otherwise divide through by `g`, solve the reduced congruence, and output one residue modulo:

$$
\mathrm{lcm}(n,m)=\frac{n}{g} m
$$

## Core Idea

Use one general merge routine for two congruences.

1. normalize the residues
2. compute `g = gcd(n, m)` together with Bézout coefficients from extended Euclid
3. reject immediately if the residue difference is not divisible by `g`
4. otherwise solve the reduced shift modulo `m / g`
5. rebuild the merged answer and normalize it into `[0, lcm)`

The invariant is:

```text
the returned pair (x, K) means:
all original solutions are exactly x mod K
```

That is why the output format matches the math object so cleanly.

## Complexity

- `O(log(min(n, m)))` per test case

The heavy lifting is only one gcd / extended-gcd merge.

## Pitfalls / Judge Notes

- The moduli are not guaranteed coprime.
- Output `no solution` exactly when the gcd-consistency test fails.
- Normalize the final answer into `0 <= x < K`.
- Use `long long` plus `__int128` for products like `n * step` and `lcm`.
- Do not print the first matching number you stumble onto; print the canonical residue modulo `K`.

## Reusable Pattern

- Topic page: [Chinese Remainder / Linear Congruences](../../../../topics/math/chinese-remainder/README.md)
- Practice ladder: [Chinese Remainder / Linear Congruences ladder](README.md)
- Starter template: [chinese-remainder.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/chinese-remainder.cpp)
- Notebook refresher: [Chinese Remainder hot sheet](../../../../notebook/chinese-remainder-hot-sheet.md)
- Compare points:
  - [Euclid Problem](../../../../practice/ladders/math/gcd-lcm/euclidproblem.md)
  - [Modular Arithmetic hot sheet](../../../../notebook/modular-arithmetic-hot-sheet.md)
- This note adds: the first exact non-coprime congruence merge route in the repo.

## Solutions

- Code: [generalchineseremainder.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/chinese-remainder/generalchineseremainder.cpp)
