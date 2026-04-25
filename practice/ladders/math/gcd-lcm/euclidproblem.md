# Euclid Problem

- Title: `Euclid Problem`
- Judge / source: `UVa`
- Original URL: [https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1045](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1045)
- Mirror URL: [https://onlinejudge.org/external/101/10104.pdf](https://onlinejudge.org/external/101/10104.pdf)
- Secondary topics: `Extended Euclid`, `Bezout coefficients`, `Diophantine witness`
- Difficulty: `medium`
- Subtype: `Return one Bézout witness for gcd`
- Status: `solved`
- Solution file: [euclidproblem.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/gcd-lcm/euclidproblem.cpp)

## Why Practice This

This is the cleanest exact anchor for the `extended-gcd-diophantine` template.

The statement asks for:

- integers `x, y`
- and `d = gcd(a, b)`

such that:

```text
ax + by = d
```

That is exactly Bézout's identity in contest form.

## Recognition Cue

Reach for extended Euclid when:

- the statement literally asks for coefficients `x, y` with `ax + by = gcd(a, b)`
- you need one modular inverse under a composite modulus
- the real task is to find one witness for `ax + by = c`

The strongest smell is:

- "find integers x and y such that ax + by = ..."

That usually means the Euclidean algorithm is not just a gcd primitive anymore; it must also return the coefficients.

## Problem-Specific Transformation

The problem is already almost in reusable form.

The only rewrite is:

- solve the Bézout equation for `d = gcd(a, b)` directly
- print the returned coefficients and gcd

So unlike many number-theory problems, the reusable primitive is the whole solution shape here.

## Core Idea

Extended Euclid returns integers `x, y` such that:

```text
ax + by = gcd(a, b)
```

The recursion works because if:

```text
bx1 + (a mod b)y1 = gcd(a, b)
```

then substituting:

```text
a mod b = a - floor(a / b) * b
```

gives a valid pair for `(a, b)`:

```text
x = y1
y = x1 - floor(a / b) * y1
```

For this UVa problem, the judge wants the witness with minimal `|x| + |y|`, and if there is still a tie, the one with `x <= y`.

This is a tighter contract than “any Bézout witness works.” For this task, the usual recursive extended-Euclid reconstruction is still the accepted route.

## Complexity

- `O(log(min(a, b)))` per test case

## Pitfalls / Judge Notes

- Input has many test cases until EOF.
- The judge does not accept an arbitrary Bézout pair; it asks for the witness with minimal `|x| + |y|`, and then `x <= y` on ties.
- For this exact UVa task, the standard recursive extended-Euclid reconstruction is the accepted route.
- Do not confuse this task with solving `ax + by = c`; here `c` is specifically `gcd(a, b)`.
- Keep the coefficients in `long long` even though the formula is tiny.

## Reusable Pattern

- Topic page: [Modular Arithmetic](../../../../topics/math/modular-arithmetic/README.md)
- Practice ladder: [GCD / LCM ladder](README.md)
- Starter template: [extended-gcd-diophantine.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/extended-gcd-diophantine.cpp)
- Notebook refresher: [Modular Arithmetic hot sheet](../../../../notebook/modular-arithmetic-hot-sheet.md)
- Carry forward: once the statement asks for coefficients, reopen Bézout instead of stopping at `gcd(a, b)`.
- This note adds: the exact EOF loop and output shape for a plain Bézout-witness task.

## Solutions

- Code: [euclidproblem.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/gcd-lcm/euclidproblem.cpp)
