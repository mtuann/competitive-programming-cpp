# Pollard-Rho Hot Sheet

Use this page when the task is:

```text
factor one 64-bit integer into prime factors
```

and you want the shortest safe route back to the `Miller-Rabin -> Pollard-Rho -> recurse` stack.

## Do Not Use When

- trial division or SPF sieve is already enough
- the real task is primitive-root testing, not factorization itself
- the integer domain is outside the normal 64-bit contest setting
- you only need one gcd / modular inverse / small-prime fact

## Choose By Signal

- factor one 64-bit integer into sorted prime factors -> [`pollard-rho-factorize.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/pollard-rho-factorize.cpp)
- find one primitive root modulo one prime once factorization is already under control -> [Primitive Root hot sheet](primitive-root-hot-sheet.md)
- recover `x` from `a^x ≡ b (mod m)` -> [Discrete Log hot sheet](discrete-log-hot-sheet.md)
- plain sieve / divisors / totients -> [Number Theory Basics](../topics/math/number-theory-basics/README.md)

## Core Invariants

- always run a 64-bit primality test before trying to split
- Pollard-Rho only succeeds when it returns a proper factor `1 < d < n`
- recurse on both parts until every leaf is prime
- sort the final prime multiset before trusting verifier-style output

## Main Traps

- skipping the primality gate and recursing forever on primes
- treating `d = n` as success instead of "restart with another seed / constant"
- forgetting multiplicity when merging recursive results
- using signed overflow instead of `__int128` / safe modular multiplication

## Exact Starters In This Repo

- exact starter -> [`pollard-rho-factorize.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/pollard-rho-factorize.cpp)
- flagship in-lane rep -> [Factorize](../practice/ladders/math/pollard-rho/factorize.md)
- compare point -> [Primitive Root](../topics/math/primitive-root/README.md)
- nearby foundation -> [Number Theory cheatsheet](number-theory-cheatsheet.md)

## Reopen Paths

- full lesson -> [Pollard-Rho](../topics/math/pollard-rho/README.md)
- broader chooser -> [Number Theory cheatsheet](number-theory-cheatsheet.md)
- template chooser -> [Template Library](../template-library.md)
