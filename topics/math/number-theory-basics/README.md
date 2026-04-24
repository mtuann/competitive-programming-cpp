# Number Theory Basics

Number theory basics is the layer where arithmetic stops being about decimal values and starts being about divisibility structure.

This topic is the entry point for:

- `gcd` / `lcm`
- prime factorization
- divisor counting
- sieve-style preprocessing
- the prime-exponent worldview behind many contest math problems

It is a family page, not one single trick. The goal is to know which primitive to reach for, why it works, and when a problem is really about divisibility rather than raw numeric simulation.

## At A Glance

- **Use when:** the statement smells like divisibility, gcd/lcm, factors, or repeated factorization
- **Core worldview:** represent integers by their prime exponents whenever possible
- **Main tools:** Euclid, trial division, sieve of Eratosthenes, SPF sieve, linear sieve
- **Typical complexity:** `gcd` in `O(log n)`, one factorization by trial division in `O(\sqrt{n})`, SPF preprocessing in near-linear time
- **Main trap:** solving a divisibility problem at the value level when the clean argument lives per prime

## Problem Model And Notation

We work over positive integers unless stated otherwise.

Standard notation:

- `d | n` means "`d` divides `n`"
- `gcd(a, b)` is the greatest common divisor
- `lcm(a, b)` is the least common multiple

If

$$
n = \prod_{i=1}^{k} p_i^{e_i}
$$

is the prime factorization of `n`, then the exponents `e_i` are the real structural information.

Two especially important arithmetic functions are:

$$
\tau(n) = \text{number of positive divisors of } n
$$

and

$$
\sigma(n) = \text{sum of positive divisors of } n.
$$

This page focuses on the contest layer built on:

- divisibility facts
- Euclid's algorithm
- prime factorization
- divisor formulas
- sieve preprocessing

## From Brute Force To The Right Idea

### Brute Force: Treat The Number As A Black Box

A beginner approach to number-theory-flavored tasks is often:

- test every possible divisor
- recompute `gcd` from scratch everywhere
- factor every number independently with trial division
- reason directly with values instead of structure

That works for tiny inputs, but it scales badly once:

- there are many queries
- the same arithmetic structure repeats
- the real answer depends on which primes divide a number, not on the number's decimal form

### The First Shift: Think In Divisibility, Not Values

When a problem asks:

- whether something divides something else
- whether two numbers are coprime
- what the gcd/lcm is
- how many divisors a number has

the correct mental object is usually not the number itself.

It is:

- its prime support
- or the exponent of each prime

This is why the same problem often becomes much simpler after factorization.

### The Second Shift: Prime Exponents Decouple The Problem

If

$$
a = \prod p^{\alpha_p},
\qquad
b = \prod p^{\beta_p},
$$

then:

$$
\gcd(a, b) = \prod p^{\min(\alpha_p, \beta_p)}
$$

and

$$
\mathrm{lcm}(a, b) = \prod p^{\max(\alpha_p, \beta_p)}.
$$

This is the deepest "basic" idea in this topic.

Once you internalize it, many problems stop looking mysterious:

- gcd/lcm constructions
- divisibility feasibility
- closure under repeated gcd/lcm
- divisor counting
- "best divisor" or "best gcd" scans over many values

### The Third Shift: Precompute Structure When Many Numbers Are Involved

For one moderate-size number, trial division is often enough.

For many numbers up to one bound `MAX`, recomputing from scratch is wasteful.

That is when sieve preprocessing becomes the right abstraction:

- list all primes up to `MAX`
- or store `spf[x] = smallest prime factor of x`

Then factorization becomes repeated table lookups instead of repeated searching.

## Core Invariants And Why They Work

### 1. Euclid's Algorithm

The key identity is:

$$
\gcd(a, b) = \gcd(b, a \bmod b).
$$

Why is this true?

If `a = qb + r`, then a number divides both `a` and `b` exactly when it divides both `b` and `r`.

So the common divisors of `(a, b)` and `(b, r)` are the same, which means their greatest common divisor is the same.

This gives the standard recurrence:

```text
gcd(a, b):
    while b != 0:
        (a, b) = (b, a mod b)
    return a
```

This is why Euclid is so fast:

- each step strictly decreases the second argument
- the values collapse quickly enough to give logarithmic complexity

Two boundary facts matter constantly in contest code:

$$
\gcd(a, 0) = |a|
$$

and

$$
\gcd(0, 0)
$$

is usually treated as undefined mathematically, but many code paths avoid needing it.

### 2. Prime-Factorization View Of GCD And LCM

Suppose

$$
a = \prod p^{\alpha_p},
\qquad
b = \prod p^{\beta_p}.
$$

For a divisor `d` to divide both `a` and `b`, its exponent on each prime `p` can be at most both `\alpha_p` and `\beta_p`.

So the largest such common divisor uses:

$$
\min(\alpha_p, \beta_p)
$$

for every prime.

Similarly, a common multiple must contain enough of each prime to cover both inputs, so the smallest one uses:

$$
\max(\alpha_p, \beta_p).
$$

That immediately yields the standard identity:

$$
\gcd(a, b) \cdot \mathrm{lcm}(a, b) = a \cdot b
$$

for positive integers `a, b`.

In code, the safer form for `lcm` is:

$$
\mathrm{lcm}(a, b) = \frac{a}{\gcd(a, b)} \cdot b
$$

because dividing first reduces overflow risk.

### 3. Divisor Counting Formula

If

$$
n = \prod_{i=1}^{k} p_i^{e_i},
$$

then every positive divisor of `n` has the form:

$$
d = \prod_{i=1}^{k} p_i^{f_i}
\qquad \text{where } 0 \le f_i \le e_i.
$$

For each prime `p_i`, there are exactly `e_i + 1` legal choices for `f_i`.

So:

$$
\tau(n) = \prod_{i=1}^{k} (e_i + 1).
$$

The same decoupling gives the divisor-sum formula:

$$
\sigma(n) = \prod_{i=1}^{k} (1 + p_i + p_i^2 + \cdots + p_i^{e_i}).
$$

These formulas are not "special tricks". They are the direct consequence of the fact that divisors are chosen independently prime by prime.

### 4. Trial Division

For one number `n`, the simplest factorization idea is:

- try candidate divisors from `2` upward
- whenever one divides `n`, peel off its full exponent

The stopping rule is:

- once `d * d > n`, any remaining `n > 1` must itself be prime

Why?

Because if a composite number had no factor at most its square root, then both factors would be larger than the square root, and their product would already exceed the number.

That is the basic proof behind the `O(\sqrt{n})` trial-division bound.

### 5. Sieve Of Eratosthenes

The Sieve of Eratosthenes finds all primes up to `N` by repeatedly crossing off multiples of each prime.

The key invariant is:

- when you reach an unmarked number `p`, it is prime
- every composite number has a smallest prime factor, so it will eventually be crossed off by that factor

The sieve is the right tool when you need:

- all primes up to one bound
- or many factorizations, if you want to bootstrap a better table from it

### 6. SPF Sieve

Instead of only marking "composite", you can store:

$$
\mathrm{spf}[x] = \text{smallest prime factor of } x.
$$

Then factorization becomes:

```text
while x > 1:
    p = spf[x]
    count how many times p divides x
    divide x by p repeatedly
```

The invariant is simple:

- every composite `x` has at least one prime factor
- storing the smallest one gives a guaranteed valid next peel step
- repeated peeling terminates after exactly the total exponent count of the factorization

This is one of the most useful contest preprocessings in the whole repo.

## Variant Chooser

### Use Euclid When

- you just need `gcd`
- you need prefix/suffix gcd
- you need to simplify `lcm`
- the problem is really about divisibility over arrays, not about full factorization

Canonical smells:

- "remove one element and maximize gcd"
- "is this replacement enough to preserve divisibility?"
- "collapse many numbers by gcd"

### Use Trial Division When

- you only factor one number or a few numbers
- the values are moderate enough that `O(\sqrt{n})` is fine
- preprocessing a large table would be overkill

### Use Sieve Of Eratosthenes When

- you need all primes up to `N`
- or you need primality information for many values in one range

### Use SPF Sieve When

- you will factor many values up to one bound
- factorization itself is part of the hot loop
- you need divisor/counting logic on many inputs

### Use Linear Sieve When

- you want primes plus smallest-prime-factor-style structure in one pass
- or you want multiplicative functions in bulk

This is the natural next layer after the basic sieve/SPF viewpoint. It is worth knowing, but many contest tasks are already solved by a standard SPF table.

### Move To Modular Arithmetic When

- the real problem is about inverses, powers, or combinations modulo `MOD`
- divisibility over integers is no longer the main invariant

That boundary is important:

- number theory basics = integer divisibility structure
- modular arithmetic = arithmetic inside one residue system

## Worked Examples

### Example 1: GCD And LCM Through Prime Exponents

Take:

$$
360 = 2^3 \cdot 3^2 \cdot 5
$$

and

$$
840 = 2^3 \cdot 3 \cdot 5 \cdot 7.
$$

Then:

$$
\gcd(360, 840) = 2^3 \cdot 3^1 \cdot 5^1 = 120
$$

because we take the smaller exponent of each prime, and:

$$
\mathrm{lcm}(360, 840) = 2^3 \cdot 3^2 \cdot 5^1 \cdot 7^1 = 2520
$$

because we take the larger exponent.

This is the mental model to keep even when you call `std::gcd` in code.

### Example 2: Counting Divisors

Let

$$
n = 2^3 \cdot 3^2 \cdot 5^1.
$$

Any divisor has the form:

$$
2^a 3^b 5^c
\qquad
0 \le a \le 3,\; 0 \le b \le 2,\; 0 \le c \le 1.
$$

So:

- `a` has `4` choices
- `b` has `3` choices
- `c` has `2` choices

Therefore:

$$
\tau(n) = 4 \cdot 3 \cdot 2 = 24.
$$

This is exactly the logic behind [Counting Divisors](../../../practice/ladders/math/number-theory-basics/countingdivisors.md).

### Example 3: Many Factorizations Need SPF, Not Repeated Trial Division

Suppose the input contains up to `2 * 10^5` numbers, each at most `10^6`, and you must factor all of them.

Trial division per number repeats the same small-prime work over and over.

The better workflow is:

1. build `spf` once for all values up to `10^6`
2. factor each number by repeatedly peeling `spf[x]`

That is the structural reason SPF pays off:

- one global preprocessing
- many cheap local factorizations

### Example 4: The Best GCD May Be Found By Scanning Multiples

Some gcd problems are not solved by calling `gcd` many times.

[Common Divisors](../../../practice/ladders/math/gcd-lcm/commondivisors.md) is a good example:

- instead of checking every pair
- scan each candidate divisor `d`
- count how many numbers are multiples of `d`

This is still a number-theory-basics move, because it comes from divisibility structure:

- "`d` is a feasible gcd" means "at least two numbers are divisible by `d`"

## Algorithms And Pseudocode

### Euclid

```text
gcd(a, b):
    while b != 0:
        r = a mod b
        a = b
        b = r
    return abs(a)
```

### Trial Division

```text
factorize(n):
    factors = []
    d = 2
    while d * d <= n:
        if n % d == 0:
            cnt = 0
            while n % d == 0:
                n /= d
                cnt += 1
            factors.push((d, cnt))
        d += 1
    if n > 1:
        factors.push((n, 1))
    return factors
```

### SPF Build

```text
build_spf(MAX):
    spf[0..MAX] = 0
    for i in 2..MAX:
        if spf[i] == 0:
            spf[i] = i
            if i * i <= MAX:
                for j in i * i, i * i + i, ...:
                    if spf[j] == 0:
                        spf[j] = i
```

### Factorization Using SPF

```text
factorize_with_spf(x, spf):
    factors = []
    while x > 1:
        p = spf[x]
        cnt = 0
        while x % p == 0:
            x /= p
            cnt += 1
        factors.push((p, cnt))
    return factors
```

The repo starter for this layer is:

- [number-theory-basics.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/number-theory-basics.cpp)

## Implementation Notes

### 1. Compute `lcm` In The Safe Order

Prefer:

```cpp
a / gcd(a, b) * b
```

over:

```cpp
a * b / gcd(a, b)
```

The first version still can overflow for huge values, but it is strictly safer.

### 2. Peel Full Exponents At Once

When factoring, do not just record that `p` divides `n`.

Peel the whole exponent:

- cleaner reasoning
- direct compatibility with divisor formulas
- easier bridge to gcd/lcm constructions

### 3. Trial Division Needs The Leftover Prime Case

After the loop, if `n > 1`, that leftover is prime and must be emitted.

Forgetting this is one of the most common factorization bugs.

### 4. SPF Only Helps Inside Its Precomputed Bound

If you built `spf` up to `MAX`, then:

- `spf[x]` is valid only for `x <= MAX`

This sounds obvious, but it is a frequent source of contest-time mistakes when inputs and derived values are mixed carelessly.

### 5. `gcd(0, x) = x` Makes Prefix/Suffix Patterns Clean

This is why array-gcd code can use boundary zeros so naturally.

You see this directly in:

- [GCD on Blackboard](../../../practice/ladders/math/gcd-lcm/gcdonblackboard.md)

### 6. Linear Sieve Is A Next-Step Optimizer, Not A Mandatory Default

If the task only needs:

- primes up to `N`
- or SPF-style factorization up to `N`

a standard sieve/SPF solution is often already enough.

Use linear sieve when its extra structure actually pays for itself.

## Practice Archetypes

The most common number-theory-basics-shaped tasks are:

- **direct gcd/lcm identity problems**
- **factor one number and derive a formula**
- **factor many numbers under one max bound**
- **count divisors / sum divisors**
- **scan divisors or multiples instead of scanning pairs**
- **reduce a closure or feasibility statement to prime exponents**

Strong contest smells include:

- the statement keeps saying `divides`, `coprime`, `prime`, `factor`, `divisor`
- the brute force is over pairs or all divisors
- the clean solution seems to separate by prime
- repeated factorization suggests one preprocessing table

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Primary / course:

- [MIT 6.042J: Facts About Divisibility](https://web.mit.edu/neboat/Public/6.042/numbertheory1.pdf)
- [MIT 6.042J: Computing GCDs](https://courses.csail.mit.edu/6.042/spring18/gcd-euclid.pdf)
- [Illinois CS173: Divisibility](https://courses.grainger.illinois.edu/cs173/fa2019/Lectures/Divisibility.pdf)

Course / notes:

- [UCF Prime Sieve Notes](https://www.cs.ucf.edu/~dmarino/progcontests/modules/sieve/PrimeSieveNotes.pdf)
- [Cornell Technical Report: A Linear Sieve Algorithm for Finding Prime Numbers](https://ecommons.cornell.edu/items/cd97309d-59ea-4be4-b7f0-4fe15984760f)

Reference:

- [CP-Algorithms: Euclidean Algorithm](https://cp-algorithms.com/algebra/euclid-algorithm.html)
- [CP-Algorithms: Sieve of Eratosthenes](https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html)
- [CP-Algorithms: Linear Sieve](https://cp-algorithms.com/algebra/prime-sieve-linear.html)
- [USACO Guide: Divisibility](https://usaco.guide/gold/divisibility?lang=cpp)

Practice:

- [Counting Divisors](../../../practice/ladders/math/number-theory-basics/countingdivisors.md)
- [Common Divisors](../../../practice/ladders/math/gcd-lcm/commondivisors.md)
- [GCD on Blackboard](../../../practice/ladders/math/gcd-lcm/gcdonblackboard.md)
- [CRYPTKEY](../../../practice/ladders/math/gcd-lcm/cryptkey.md)
- [LAMP](../../../practice/ladders/math/number-theory-basics/lamp.md)

Repo anchors:

- starter template: [number-theory-basics.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/number-theory-basics.cpp)
- extended-Euclid bridge: [extended-gcd-diophantine.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/extended-gcd-diophantine.cpp)
- notebook refresher: [Number Theory Cheatsheet](../../../notebook/number-theory-cheatsheet.md)
- adjacent topic: [Modular Arithmetic](../modular-arithmetic/README.md)

## Related Topics

- [Modular Arithmetic](../modular-arithmetic/README.md)
- [FFT / NTT](../fft-ntt/README.md)
- [Sparse Table](../../data-structures/sparse-table/README.md)
