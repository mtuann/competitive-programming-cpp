# Modular Arithmetic

Modular arithmetic is the standard contest language for "the exact integer is huge, but its residue is enough." It looks elementary at first, but most real bugs in this topic come from forgetting that some familiar operations survive modulo `m` and some do not.

This page aims to make three things feel automatic:

1. reduce early and often for `+`, `-`, and `*`
2. only divide when an inverse actually exists
3. only reduce exponents when a theorem really permits it

If [Number Theory Basics](../number-theory-basics/README.md) is about divisibility structure, modular arithmetic is about computing safely inside one residue system.

## At A Glance

Reach for modular arithmetic when:

- the statement literally asks for the answer modulo `MOD`
- counts, powers, or products become too large to store exactly
- you need repeated exponentiation, inverses, or binomial coefficients
- a DP counts ways and only the residue matters
- polynomial or matrix operations are performed under a fixed modulus

Strong contest triggers:

- `print the answer modulo 1e9+7`
- `a^b mod MOD`
- `nCk mod MOD`
- `divide by x modulo MOD`
- `a^(b^c) mod MOD`
- `many queries under one fixed prime modulus`

Strong anti-cues:

- the modulus changes per query and the real issue is factorization or CRT
- the task is about exact rational values, not residues
- the modulus is composite and you were about to apply Fermat blindly
- the main problem is number-theoretic structure rather than residue computation

What success looks like after studying this page:

- you know exactly which algebraic moves are always legal mod `m`
- you can explain why modular division requires `gcd(a, m) = 1`
- you can choose between Fermat inverse and extended Euclid
- you can tell when exponent reduction is valid and when it is a trap
- you can precompute factorial and inverse-factorial tables without guessing

## Prerequisites

- [C++ Language For Contests](../../foundations/cpp-language/README.md)
- [Number Theory Basics](../number-theory-basics/README.md) for gcd and coprimality language

## Problem Model And Notation

We write:

$$
a \equiv b \pmod m
$$

to mean that `a` and `b` leave the same remainder modulo `m`, or equivalently:

$$
m \mid (a - b).
$$

The residue system modulo `m` contains the classes:

$$
0, 1, 2, \dots, m-1.
$$

In contest code, `normalize(x)` usually means:

```text
x %= MOD
if x < 0: x += MOD
```

The most important operations are:

- addition
- subtraction
- multiplication
- exponentiation
- inversion when it exists

The first three are always compatible with congruence. Division is not.

Quick legality table:

| Operation | Always safe mod `m`? | What you need to check |
| --- | --- | --- |
| `a + b` | yes | nothing extra |
| `a - b` | yes | normalize the result in code |
| `a * b` | yes | avoid overflow before `%` |
| `a^e` | yes for the base | reduce the base first; reducing the exponent needs a theorem |
| `a / b` | no | inverse of `b` must exist |

## From Brute Force To The Right Idea

### Why We Reduce At All

Suppose a DP counts paths, subsets, or strings. The exact answer might have hundreds of thousands of digits, but the judge only asks for the value modulo `MOD`.

The naive instinct is:

1. compute the true integer answer
2. take `% MOD` at the end

This is usually impossible because intermediate values overflow long before the computation finishes.

### The Structural Observation

Congruence is stable under:

- addition
- subtraction
- multiplication

So we can replace large intermediate values by their residues immediately without changing the final answer modulo `m`.

That turns modular arithmetic from "last-step formatting" into "the arithmetic system we work in from the beginning."

The most common contest manifestation is a counting DP transition such as:

```text
dp[v] = (dp[v] + dp[u]) % MOD
```

That line is sound because addition respects congruence, so the entire DP can live inside the residue system.

### The First Big Trap: Division Is Different

In ordinary arithmetic, if:

$$
ac = bc,
$$

and `c != 0`, we cancel `c`.

Modulo `m`, this is not always sound.

For example, modulo `6`:

$$
2 \cdot 3 \equiv 4 \cdot 3 \pmod 6
$$

but:

$$
2 \not\equiv 4 \pmod 6.
$$

So modular arithmetic is not just "do the same thing, then `% MOD`". You must know which operations remain legal.

## Core Invariant And Why It Works

### Congruence Respects `+`, `-`, `*`

If:

$$
a \equiv b \pmod m,
$$

then for any `c`:

$$
a + c \equiv b + c \pmod m
$$

$$
a - c \equiv b - c \pmod m
$$

$$
ac \equiv bc \pmod m.
$$

This follows directly from the definition `m | (a - b)`.

That is why we may reduce after every addition or multiplication in DP, combinatorics, and matrix transitions.

### Exponentiation Respects Congruence In The Base

If:

$$
x \equiv y \pmod m,
$$

then for any integer `k >= 1`:

$$
x^k \equiv y^k \pmod m.
$$

So base reduction is always safe:

$$
a^e \bmod m = (a \bmod m)^e \bmod m.
$$

This is why `powmod` starts by reducing the base.

### Why Inverses Exist Exactly When `gcd(a, m) = 1`

We say `a` has a multiplicative inverse modulo `m` if there exists `x` such that:

$$
ax \equiv 1 \pmod m.
$$

This is equivalent to:

$$
ax + my = 1
$$

for some integer `y`, which is exactly a Bézout identity. Such an identity exists if and only if:

$$
\gcd(a, m) = 1.
$$

So the rule is:

- inverse exists iff `a` and `m` are coprime

This one theorem explains both:

- why modular division is sometimes legal
- why it sometimes fails completely

### Fermat's Little Theorem And Why Prime Moduli Feel Easy

If `p` is prime and `a` is not divisible by `p`, then:

$$
a^{p-1} \equiv 1 \pmod p.
$$

Multiply both sides by `a^{-1}` and we get:

$$
a^{p-2} \equiv a^{-1} \pmod p.
$$

That is the standard contest formula for inverses under a prime modulus:

$$
a^{-1} \equiv a^{p-2} \pmod p.
$$

This is the main reason prime moduli like `1_000_000_007` and `998244353` are so friendly:

- every nonzero residue has an inverse
- fast exponentiation gives that inverse in `O(log p)`

### Why Exponent Reduction Needs A Theorem

This is the second big trap.

You may always reduce the **base** modulo `m`, but you may not always reduce the **exponent** modulo `m`.

MIT's notes make this warning explicit. For example:

$$
1 \equiv 6 \pmod 5
$$

but:

$$
2^1 \not\equiv 2^6 \pmod 5.
$$

Exponent reduction only becomes valid when a theorem gives a cycle length.

For prime `p` and `a \not\equiv 0 \pmod p`:

$$
a^k \equiv a^{\,k \bmod (p-1)} \pmod p.
$$

More generally, if `gcd(a, m) = 1`, Euler's theorem gives:

$$
a^{\varphi(m)} \equiv 1 \pmod m,
$$

so exponents can be reduced modulo `\varphi(m)`.

If `a` is not coprime with the modulus, you must handle edge cases separately rather than applying exponent reduction blindly.

## Complexity And Tradeoffs

- `powmod(a, e, m)`: `O(log e)`
- one inverse by extended Euclid: `O(log m)`
- one inverse by Fermat under prime modulus: `O(log m)`
- factorial / inverse-factorial precompute up to `N`: `O(N)`
- one `nCk` query after precompute: `O(1)`

Practical tradeoffs:

| Situation | Best tool | Why |
| --- | --- | --- |
| fixed prime modulus, one inverse | Fermat + `powmod` | easy and contest-standard |
| composite modulus or inverse existence unclear | extended Euclid | directly checks `gcd(a, m) = 1` |
| many `nCk mod p` queries with one prime modulus | factorial + inverse-factorial tables | one build, then `O(1)` queries |
| exponent tower under prime modulus | exponent reduction modulo `p - 1` plus edge cases | reuse Fermat cycle |
| arbitrary modulus with factorial factors sharing primes | more advanced number theory / CRT | naive inverse-factorial formula may break |

Rule of thumb:

- prime modulus -> the workflow is much simpler
- composite modulus -> always ask whether the needed inverse exists
- when you see `% MOD`, ask whether the task is merely arithmetic, or whether gcd / factorization structure is secretly driving the legality

## Variant Chooser

| Variant | What changes | When to choose it | Where it gets awkward |
| --- | --- | --- | --- |
| prime-mod helper set | `powmod`, `inv`, `nCk` by factorials | fixed prime modulus, standard DP/combinatorics | wrong if modulus is composite or `n >= mod` assumptions break |
| composite-mod inverse | use extended Euclid | modulus is not prime or inverse existence must be checked | no inverse when `gcd(a, m) != 1` |
| factorial / inverse-factorial tables | precompute once | many `nCk` queries under one prime modulus | invalid if denominator contains noninvertible factors mod composite `m` |
| exponent reduction | shrink exponent mod cycle length | exponent towers, repeated powering | dangerous when coprimality or zero-base edge cases are ignored |
| CRT / prime-power handling | combine several local mod systems | arbitrary modulus with richer combinatorics | outside the basic toolkit of this page |

## Worked Examples

### Example 1: Binary Exponentiation

Suppose we need:

$$
3^{13} \bmod 17.
$$

Binary exponentiation maintains:

$$
\text{answer} \cdot \text{base}^{\text{remaining exponent}} \equiv 3^{13} \pmod{17}.
$$

Start with:

- `answer = 1`
- `base = 3`
- `exp = 13`

Binary form of `13` is `1101`, so we repeatedly:

- multiply by the current base when the low bit is `1`
- square the base
- shift the exponent right

One possible trace:

1. `exp = 13` odd -> `answer = 1 * 3 = 3`, `base = 9`
2. `exp = 6` even -> `answer = 3`, `base = 13`
3. `exp = 3` odd -> `answer = 3 * 13 = 39 ≡ 5`, `base = 16`
4. `exp = 1` odd -> `answer = 5 * 16 = 80 ≡ 12`

So:

$$
3^{13} \equiv 12 \pmod{17}.
$$

The point is not the arithmetic itself, but the invariant: every loop preserves the value of the original power modulo `m`.

### Example 2: Inverse Exists Or Does Not Exist

Consider `3^{-1} mod 11`.

Since:

$$
\gcd(3, 11) = 1,
$$

the inverse exists. In fact:

$$
3 \cdot 4 = 12 \equiv 1 \pmod{11},
$$

so the inverse is `4`.

Now consider `2^{-1} mod 6`.

Here:

$$
\gcd(2, 6) = 2 \neq 1,
$$

so no inverse exists.

This is the cleanest example of why modular division is conditional, not a built-in operation.

### Example 3: `nCk` Mod A Prime

If `MOD` is prime and we need many binomial queries, use:

$$
\binom{n}{k} \equiv \frac{n!}{k!(n-k)!} \pmod{MOD}
$$

and rewrite division as multiplication by inverses:

$$
\binom{n}{k} \equiv n! \cdot (k!)^{-1} \cdot ((n-k)!)^{-1} \pmod{MOD}.
$$

After precomputing:

- `fact[i] = i! mod MOD`
- `inv_fact[i] = (fact[i])^{-1} mod MOD`

one query becomes:

```text
fact[n] * inv_fact[k] * inv_fact[n-k] mod MOD
```

This is the standard contest pattern when many combinatorics queries share one prime modulus.

### Example 4: Exponentiation II And Exponent Reduction

Suppose we want:

$$
a^{(b^c)} \bmod p
$$

for a prime `p`.

If `a \not\equiv 0 \pmod p`, Fermat gives the cycle length `p - 1`, so:

$$
a^{(b^c)} \equiv a^{\,\left(b^c \bmod (p-1)\right)} \pmod p.
$$

So the computation becomes:

1. compute `e = b^c mod (p - 1)`
2. compute `a^e mod p`

But if `a \equiv 0 \pmod p`, you must separate:

- exponent `0` -> answer often treated as `1` by contest convention
- exponent `> 0` -> answer `0`

This is why exponent reduction is a theorem-driven optimization, not an unconditional `% (p-1)` trick.

## Algorithm And Pseudocode

This repo's canonical helpers are:

- [modular-arithmetic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/modular-arithmetic.cpp)
- [factorial-binomial-mod.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/factorial-binomial-mod.cpp)
- [extended-gcd-diophantine.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/extended-gcd-diophantine.cpp)

### Normalize

```text
normalize(x, MOD):
    x = x % MOD
    if x < 0:
        x += MOD
    return x
```

### Binary Exponentiation

```text
powmod(a, e, MOD):
    a = normalize(a, MOD)
    result = 1 % MOD
    while e > 0:
        if e is odd:
            result = (result * a) % MOD
        a = (a * a) % MOD
        e >>= 1
    return result
```

### Inverse By Fermat (Prime Modulus Only)

```text
inv_prime(a, MOD):
    return powmod(a, MOD - 2, MOD)
```

### Inverse By Extended Euclid

```text
inv_general(a, MOD):
    find x, y such that ax + MOD*y = gcd(a, MOD)
    if gcd(a, MOD) != 1:
        inverse does not exist
    return normalize(x, MOD)
```

### Many `nCk` Queries Under One Prime Modulus

```text
build_comb(N, MOD):
    fact[0] = 1
    for i from 1 to N:
        fact[i] = fact[i-1] * i mod MOD
    inv_fact[N] = powmod(fact[N], MOD - 2, MOD)
    for i from N down to 1:
        inv_fact[i-1] = inv_fact[i] * i mod MOD

binom(n, k):
    if k < 0 or k > n:
        return 0
    return fact[n] * inv_fact[k] * inv_fact[n-k] mod MOD
```

## Implementation Notes

### 1. Normalize After Subtraction

In C++:

```text
(-1) % MOD
```

is negative. So write:

```text
(a - b + MOD) % MOD
```

or use a `normalize` helper.

### 2. Cast Before Multiplying

If `a` and `b` are `int`, then:

```text
a * b
```

may overflow before `% MOD` is applied. Promote to `long long` first.

### 3. Modular Division Is Multiplication By An Inverse

Never write ordinary division under the modulus unless you have already proved the denominator is invertible.

The real question is always:

$$
\gcd(a, MOD) = 1\ ?
$$

### 4. Prime-Mod Factorial Formulas Have Hidden Assumptions

The usual factorial formula for `nCk mod MOD` assumes you can invert the denominator factors.

That is immediate for a prime modulus when those factors are nonzero modulo `MOD`, but it becomes delicate for composite moduli or prime powers.

There is also a very practical contest assumption hiding here:

- if `MOD` is prime and `0 <= n < MOD`, then `1, 2, ..., n` are all nonzero modulo `MOD`
- if `n >= MOD`, then `n!` is already divisible by `MOD`, so the naive factorial / inverse-factorial story needs more care

Tiny anti-example:

- modulo `5`, the value `C(5, 1)` is perfectly meaningful and equals `0`
- but `fact[5] \equiv 0 \pmod 5`, so the naive table formula using `inv_fact[5]` is not even well-formed

That is the point where Lucas-style reasoning or prime-power handling starts to matter.

### 5. Exponent Reduction Is Not Base Reduction

You may always reduce:

```text
a -> a % MOD
```

You may **not** always reduce:

```text
e -> e % MOD
```

without a theorem like Fermat or Euler, plus the right coprimality conditions.

### 6. Prime Modulus And Composite Modulus Are Different Worlds

Under a prime modulus:

- every nonzero value is invertible
- Fermat inverse is available
- combinatorics formulas are cleaner

Under a composite modulus:

- some nonzero residues have no inverse
- cancellation may fail
- factorial-based formulas may need prime-factor bookkeeping or CRT

### 7. The Topic Often Splits Into Two Contest Workflows

When you see modular arithmetic, ask which workflow this really is:

- `computation workflow`: `powmod`, inverse, factorials, direct residue operations
- `legality workflow`: does inverse exist, can I reduce exponents, is prime-vs-composite the real issue

Many wrong solutions fail not because the arithmetic loop is hard, but because the legality check was skipped.

### 8. Judge Conventions Still Matter

Contest problems sometimes define edge cases explicitly, for example:

- `0^0 = 1`

So even when the modular algebra is clean, still read the statement for any convention that overrides your mathematical instinct on boundary cases.

## Practice Archetypes

Use modular arithmetic when the problem feels like one of these:

- `mod power`: repeated exponentiation under one modulus
- `prime-mod inverse`: divide by a value modulo a prime
- `prime-mod combinatorics`: many `nCk` or counting queries under one fixed prime
- `exponent tower`: outer power is easy, inner exponent must be reduced
- `composite-mod warning`: the statement tempts you to divide, but invertibility is the real question

Good internal practice anchors:

- [Exponentiation](../../../practice/ladders/math/modular-arithmetic/exponentiation.md): first warm-up for `powmod`
- [Exponentiation II](../../../practice/ladders/math/modular-arithmetic/exponentiation2.md): exponent reduction under a prime modulus

Suggested progression:

1. master `powmod`
2. understand inverse existence via gcd
3. use Fermat inverse under prime mod
4. precompute factorial / inverse-factorial tables
5. only then trust exponent reduction tricks automatically

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Course:

- [MIT 6.1200J / 18.062J Lecture 09: Modular Arithmetic](https://ocw.mit.edu/courses/6-1200j-mathematics-for-computer-science-spring-2024/mit6_1200j_s24_lec09.pdf)
- [MIT Mathematics for Computer Science lecture notes](https://web.mit.edu/broder/Public/6.042-lecture-notes/lecture-notes.pdf)

Reference:

- [CP-Algorithms: Modular Inverse](https://cp-algorithms.web.app/algebra/module-inverse.html)
- [CP-Algorithms: Binary Exponentiation](https://cp-algorithms.com/algebra/binary-exp.html)
- [CP-Algorithms: Binomial Coefficients](https://cp-algorithms.com/combinatorics/binomial-coefficients.html)

Practice:

- [CSES Problem Set](https://cses.fi/problemset/)

Repo anchors:

- [Modular arithmetic ladder](../../../practice/ladders/math/modular-arithmetic/README.md)
- [Exponentiation](../../../practice/ladders/math/modular-arithmetic/exponentiation.md)
- [Exponentiation II](../../../practice/ladders/math/modular-arithmetic/exponentiation2.md)
- [modular-arithmetic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/modular-arithmetic.cpp)
- [factorial-binomial-mod.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/factorial-binomial-mod.cpp)
- [extended-gcd-diophantine.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/extended-gcd-diophantine.cpp)
- [Number theory cheatsheet](../../../notebook/number-theory-cheatsheet.md)

## Related Topics

- [Number Theory Basics](../number-theory-basics/README.md)
- [FFT / NTT](../fft-ntt/README.md)
- [Combinatorics](../../combinatorics/README.md)
