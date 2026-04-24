# Exponentiation

- Title: `Exponentiation`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1095](https://cses.fi/problemset/task/1095)
- Secondary topics: `Binary exponentiation`, `Modulo arithmetic`, `Fast power`
- Difficulty: `easy`
- Subtype: `Answer many a^b mod 1e9+7 queries quickly`
- Status: `solved`
- Solution file: [exponentiation.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/modular-arithmetic/exponentiation.cpp)

## Why Practice This

This is the cleanest first modular-arithmetic problem in the repo:

- one idea
- one standard loop
- one important edge case: `0^0 = 1` in this judge

It is the best first anchor for the topic because it turns “power modulo `MOD`” into a trusted tool you will reuse everywhere else.

## Key Idea

Use binary exponentiation.

Write the exponent in binary and repeatedly square the base:

- if the current bit of `b` is `1`, multiply the answer by the current base
- square the base each step
- shift the exponent right

Because we take `% MOD` after every multiplication, all values stay bounded.

The invariant is:

```text
answer * base^remaining_exponent == original_a^original_b  (mod MOD)
```

When the exponent becomes zero, `answer` is the desired value.

## Complexity

- one query: `O(log b)`
- all queries: `O(n log b)`

This is exactly what the constraints want.

## Pitfalls / Judge Notes

- The statement explicitly says `0^0 = 1`, and the standard binary-exponentiation loop already gives that result if `answer` starts at `1`.
- Always reduce after multiplication.
- Do not try to call a floating-point `pow`; this is integer modular arithmetic.

## Reusable Pattern

- Topic page: [Modular Arithmetic](../../../../topics/math/modular-arithmetic/README.md)
- Practice ladder: [Modular Arithmetic ladder](README.md)
- Starter template: [modular-arithmetic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/modular-arithmetic.cpp)
- Notebook refresher: [Number theory cheatsheet](../../../../notebook/number-theory-cheatsheet.md)
- Carry forward: when the exponent is large and the modulus is fixed, think repeated squaring immediately.
- This note adds: the multi-query contest wrapper and the judge's `0^0` convention.

## Solutions

- Code: [exponentiation.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/modular-arithmetic/exponentiation.cpp)
