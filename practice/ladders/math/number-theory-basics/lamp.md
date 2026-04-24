# LAMP

- Title: `LAMP - Dàn đèn màu`
- Judge / source: `VN SPOJ / VNOI`
- Original URL: [https://vn.spoj.com/problems/LAMP/](https://vn.spoj.com/problems/LAMP/)
- Mirror URL: [https://oj.vnoi.info/problem/lamp](https://oj.vnoi.info/problem/lamp)
- Main topic: `Math -> Number Theory Basics`
- Secondary topics: `Asymptotic density`, `Pairwise coprime numbers`, `Exact big fractions`
- Difficulty: `hard`
- Subtype: `Final color density after many overwrite operations on multiples`
- Status: `solved`
- Solution file: [lamp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/number-theory-basics/lamp.cpp)

## Why Practice This

This is a good example of turning an infinite-process story into an exact density formula. The update rule looks dynamic, but the final color of lamp `x` depends only on the last button whose number divides `x`.

## Core Idea

Let `p_i` be the number on button `i`, pressed in order.

A lamp ends with color `i` exactly when:

- it is divisible by `p_i`
- it is not divisible by any later `p_j` with `j > i`

So the density is:

```text
C_i = 1/p_i * product_{j>i}(1 - 1/p_j)
```

The pairwise-coprime condition is what makes this exact: divisibility by different `p_j` behaves independently modulo the product.

## Exact Fraction Handling

The formula is simple, but the exact reduced fraction can be huge. The useful trick is:

- maintain the suffix product

```text
S_i = product_{j>i}(p_j - 1) / p_j
```

as one reduced fraction `num / den`

- to output `C_i = num / (den * p_i)`, only `gcd(num, p_i)` matters
- to update `S_{i-1} = S_i * (p_i - 1) / p_i`, only these two gcds matter:

```text
g1 = gcd(num, p_i)
g2 = gcd(den, p_i - 1)
```

That means we never need `gcd` between two huge integers. We only need `gcd(bigint, small_int)`.

Because the time limit is very tight, a lightweight custom bigint is safer than a heavier general-purpose multiprecision type. We only need:

- multiply by `<= 10^9`
- divide by `<= 10^9`
- modulo `<= 10^9`

## Complexity

- `O(n * cost_of_big_integer_arithmetic)`
- `n <= 1000`, so this is easily fine with `cpp_int`

## Pitfalls / Judge Notes

- Lamp `0` is divisible by every `p_i`, but it has density `0`, so it does not affect the limit.
- `p_i` may be `1`. Then button `i` colors every lamp, and every earlier color gets density `0`.
- The denominator can be enormous, so fixed-width integers are not enough.
- Do not try to simulate by period unless only for brute-force testing.

## Reusable Pattern

- Topic page: [Number Theory Basics](../../../../topics/math/number-theory-basics/README.md)
- Practice ladder: [Number Theory Basics ladder](README.md)
- Starter template: [number-theory-basics.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/number-theory-basics.cpp)
- Notebook refresher: [Number theory cheatsheet](../../../../notebook/number-theory-cheatsheet.md)
- Carry forward: reduce the statement to divisibility, gcd, lcm, or factorization facts before coding.
- This note adds: the inclusion-exclusion style density formula and exact arithmetic for this note.

## Solutions

- Code: [lamp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/number-theory-basics/lamp.cpp)
