# CRYPTKEY

- Title: `Chìa khóa mã số`
- Judge / source: `VN SPOJ`
- Original URL: [https://vn.spoj.com/problems/CRYPTKEY/](https://vn.spoj.com/problems/CRYPTKEY/)
- Mirror URL: [https://oj.vnoi.info/problem/cryptkey](https://oj.vnoi.info/problem/cryptkey)
- Main topic: `Math -> GCD / LCM`
- Secondary topics: `Prime factorization`, `Closure under operations`, `Necessary and sufficient condition`
- Difficulty: `hard`
- Subtype: `Membership in a gcd/lcm-generated set`
- Source contest: `VOI 2015 Day 1`
- Status: `solved`
- Solution file: [cryptkey.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/gcd-lcm/cryptkey.cpp)

## Why Practice This

This is a strong number-theory problem because the closure under `gcd` and `lcm` looks abstract at first, but the right viewpoint turns it into a tiny check over the prime powers of `k`.

## Key Idea

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
- if `gj` still contains some extra prime factor not in `k`, or a too-large exponent for another prime of `k`, then every gcd built while preserving `pj^ej` keeps that extra baggage
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

## Complexity

- factorize `k`: `O(sqrt(k))`
- scan all numbers for every distinct prime factor of `k`

Since `k <= 10^12`, the number of distinct prime factors is very small, so the full solution is easily fast enough for `n <= 50000`.

## Pitfalls / Judge Notes

- The closure is not “all divisors of all lcms” in a naive sense; the useful objects are gcds of carefully chosen groups.
- For each prime power of `k`, it is enough to gcd **all** eligible numbers. If even that gcd is too large or has extra primes, no subset can fix it.
- Handle `k = 1` separately.
- Use `long long`; all values are within `10^12`.

## Solutions

- Code: [cryptkey.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/gcd-lcm/cryptkey.cpp)
