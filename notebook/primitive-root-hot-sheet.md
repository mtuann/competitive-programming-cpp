# Primitive Root Hot Sheet

Use this page when the task is:

```text
given prime p, output one primitive root modulo p
```

and you want the shortest safe route back to the generator test.

## Do Not Use When

- the unknown is in the exponent rather than the base
- the exact task is only `x^2 ≡ a (mod p)`
- the modulus is composite and you have not separated that case
- factoring `p - 1` is the real bottleneck and this starter contract is too narrow

## Choose By Signal

- find one generator modulo one prime -> [`primitive-root-prime.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/primitive-root-prime.cpp)
- recover `x` from `a^x ≡ b (mod m)` -> [Discrete Log hot sheet](discrete-log-hot-sheet.md)
- recover one square root from `x^2 ≡ a (mod p)` -> [Modular Square Root hot sheet](modular-square-root-hot-sheet.md)
- merge residue classes or solve `a x ≡ b (mod m)` -> [Chinese Remainder / Linear Congruences](../topics/math/chinese-remainder/README.md)
- only need powers / inverses / binomials -> [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md)

## Core Invariants

- for prime `p`, the nonzero residues form a cyclic group of size `p - 1`
- candidate `g` is primitive iff:

$$
g^{(p-1)/q} \not\equiv 1 \pmod p
$$

for every distinct prime divisor `q` of `p - 1`

- `p = 2` is the trivial edge case with answer `1`
- the first route is only as good as your access to the distinct prime divisors of `p - 1`

## Main Traps

- forgetting to deduplicate prime divisors of `p - 1`
- testing the prime-mod criterion unchanged under composite moduli
- forgetting the `p = 2` edge case
- using trial division when the true bottleneck is 64-bit factorization of `p - 1`

## Exact Starters In This Repo

- exact starter -> [`primitive-root-prime.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/primitive-root-prime.cpp)
- flagship in-lane rep -> [Primitive Root](../practice/ladders/math/primitive-root/primitiveroot.md)
- compare points -> [BSGS / Discrete Log](../topics/math/bsgs-discrete-log/README.md), [Modular Square Root / Discrete Root](../topics/math/modular-square-root-discrete-root/README.md)
- nearby foundation -> [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md)

## Reopen Paths

- full lesson -> [Primitive Root](../topics/math/primitive-root/README.md)
- broader chooser -> [Number Theory cheatsheet](number-theory-cheatsheet.md)
- template chooser -> [Template Library](../template-library.md)
