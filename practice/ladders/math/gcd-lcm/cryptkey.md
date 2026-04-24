# CRYPTKEY

- Title: `Chìa khóa mã số`
- Judge / source: `VN SPOJ`
- Original URL: [https://vn.spoj.com/problems/CRYPTKEY/](https://vn.spoj.com/problems/CRYPTKEY/)
- Mirror URL: [https://oj.vnoi.info/problem/cryptkey](https://oj.vnoi.info/problem/cryptkey)
- Secondary topics: `Prime factorization`, `Closure under operations`, `Necessary and sufficient condition`
- Difficulty: `hard`
- Subtype: `Membership in a gcd/lcm-generated set`
- Source contest: `VOI 2015 Day 1`
- Status: `solved`
- Solution file: [cryptkey.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/gcd-lcm/cryptkey.cpp)

## Why Practice This

This is a strong number-theory problem because the closure under `gcd` and `lcm` looks abstract at first, but the right viewpoint turns it into a tiny check over the prime powers of `k`.

## Recognition Cue

This is a `closure under gcd/lcm -> prime-power feasibility` signal:

- the set is defined by repeated `gcd` and `lcm`
- the query asks whether one target number can be generated
- trying to simulate all closures is impossible
- the target number `k` is small enough to factor, and prime exponents matter more than raw values

When a number-theory closure problem asks about one target, factor the target first and ask what each prime power would need locally.

## Problem-Specific Transformation

The statement is rewritten prime-by-prime:

- factor `k`
- for each prime power `p^e` dividing `k`, collect all input numbers divisible by `p^e`
- take the gcd of that eligible set and test whether it contains exactly the right amount of `p` and no forbidden extra baggage

If one witness gcd exists for every prime power of `k`, then taking the lcm of those witnesses reconstructs `k`. So the global closure question becomes a small family of local prime-power tests.

## Core Idea

Let `S` be the smallest set containing the input numbers and closed under:

- `gcd`
- `lcm`

We want to know whether `k` belongs to `S`.

Write:

`k = p1^e1 * p2^e2 * ... * pm^em`

For one fixed prime power `pj^ej`, look at **all** input numbers divisible by `pj^ej`, and take their gcd:

`gj = gcd(all ai such that pj^ej | ai)`

Then:

- if no input number is divisible by `pj^ej`, we can never create that prime power in `k`
- if `gj` still contains a prime factor that should not divide `k`, or an exponent that stays too large for another prime of `k`, then every gcd built while preserving `pj^ej` still keeps that unwanted divisibility
- if `v_pj(gj) > ej`, then we also cannot reduce that exponent without losing `pj^ej`

So the condition for prime `pj` is:

1. there exists at least one `ai` divisible by `pj^ej`
2. `gj` divides `k`
3. the exponent of `pj` in `gj` is exactly `ej`

If this holds for every prime factor of `k`, then each `gj` is itself constructible by repeated gcd, and:

`lcm(g1, g2, ..., gm) = k`

so `k` belongs to `S`.

Special case:

- if `k = 1`, then the answer is `YES` iff `gcd(a1, a2, ..., an) = 1`

### Why GCD Of All Eligible Numbers Is Decisive

For one target prime power `p^e`, every constructible witness that still keeps `p^e` must be the gcd of some subset of eligible numbers. Taking the gcd of **all** eligible numbers gives the smallest object you can hope for while preserving that divisibility requirement.

So if even this all-eligible gcd still contains a forbidden extra prime or too much of some exponent, no smaller subset-gcd can repair the issue in the right direction. That is why the global closure test reduces to one gcd check per target prime power.

Mini-example: if `k` needs `2^3` and the eligible numbers are `24 = 2^3 * 3` and `40 = 2^3 * 5`, then their gcd is `8`, which is perfect. But if every eligible number were also divisible by `3`, then every possible gcd witness would still be divisible by `3`, so no closure process could isolate the exact factor wanted for `k`.

## Complexity

- factorize `k`: `O(sqrt(k))`
- scan all numbers for every distinct prime factor of `k`

Since `k <= 10^12`, the number of distinct prime factors is very small, so the full solution is easily fast enough for `n <= 50000`.

## Pitfalls / Judge Notes

- The closure is not “all divisors of all lcms” in a naive sense; the useful objects are gcds of carefully chosen groups.
- For each prime power of `k`, it is enough to gcd **all** eligible numbers. If even that gcd is too large or has extra primes, no subset can fix it.
- Handle `k = 1` separately.
- Use `long long`; all values are within `10^12`.

## Reusable Pattern

- Topic page: [GCD And LCM](../../../../topics/math/number-theory-basics/README.md)
- Practice ladder: [GCD And LCM ladder](README.md)
- Starter template: [number-theory-basics.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/number-theory-basics.cpp)
- Notebook refresher: [Number theory cheatsheet](../../../../notebook/number-theory-cheatsheet.md)
- Carry forward: factor or normalize the arithmetic condition before you start casework.
- This note adds: the prime-power reasoning and feasibility test specific to this key construction.

## Solutions

- Code: [cryptkey.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/gcd-lcm/cryptkey.cpp)
