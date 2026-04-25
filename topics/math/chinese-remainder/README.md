# Chinese Remainder / Linear Congruences

This lane starts when a problem stops being "do modular arithmetic carefully" and becomes:

```text
several residue conditions must all hold at once
```

The first useful shift is to stop treating each congruence separately.

Instead:

- one congruence is one residue class
- two congruences can be merged into one equivalent residue class or declared inconsistent
- a whole system is solved by repeating that merge

For contest work, this is the clean exact route for:

- `x ≡ a_i (mod m_i)` systems
- non-coprime modulus merges with gcd consistency checks
- linear congruences like `a x ≡ b (mod m)` after one extended-Euclid reduction

## At A Glance

- **Use when:** one or many congruences must hold simultaneously, or a congruence system must be collapsed into one residue modulo lcm
- **Core worldview:** merge two congruences into one equivalent congruence and repeat
- **Main tools:** normalization modulo `m`, `gcd` consistency, extended Euclid, Bézout coefficients
- **Typical complexity:** `O(k log M)` to merge `k` congruences when arithmetic fits in `long long`
- **Main trap:** assuming CRT only works for pairwise-coprime moduli, then missing the general gcd-consistency merge

Strong contest signals:

- the statement literally gives several conditions like `x ≡ a (mod n)`
- one answer must satisfy two calendars, clocks, cycles, or repeating schedules at once
- the modulus is composite, so prime-mod inverse shortcuts are not enough
- a linear congruence like `a x ≡ b (mod m)` needs to be solved before anything else can continue

Strong anti-cues:

- the whole task is only repeated `powmod` or inverse under one prime modulus
- the main work is counting, not solving a congruence system
- the moduli are huge enough that `lcm` or exact reconstruction no longer fits the intended arithmetic model

## Prerequisites

- [Modular Arithmetic](../modular-arithmetic/README.md)
- [Number Theory Basics](../number-theory-basics/README.md)

Helpful nearby anchors:

- [Euclid Problem](../../../practice/ladders/math/gcd-lcm/euclidproblem.md) for Bézout coefficients
- [Modular Arithmetic hot sheet](../../../notebook/modular-arithmetic-hot-sheet.md)

## Problem Model And Notation

One congruence

$$
x \equiv a \pmod m
$$

means:

$$
x = a + t m
$$

for some integer `t`.

So every congruence describes one residue class.

The system

$$
\begin{cases}
x \equiv a_1 \pmod {m_1} \\
x \equiv a_2 \pmod {m_2} \\
\dots
\end{cases}
$$

asks whether those residue classes intersect, and if they do, to rewrite that intersection as:

$$
x \equiv a \pmod M
$$

for one larger modulus `M`.

That is the right mental model for both CRT and the general non-coprime merge.

## From Brute Force To The Right Idea

### Brute Force

For two congruences

$$
x \equiv a_1 \pmod {m_1}, \quad x \equiv a_2 \pmod {m_2}
$$

the naive route is:

- enumerate numbers in one residue class
- check when one also lands in the other class

That is acceptable only when the moduli are tiny.

### Structural Observation

Any common solution must satisfy:

$$
x = a_1 + k m_1
$$

for some integer `k`.

Plugging into the second congruence gives:

$$
a_1 + k m_1 \equiv a_2 \pmod {m_2}
$$

so:

$$
m_1 k \equiv a_2 - a_1 \pmod {m_2}
$$

Now the problem is no longer "search for x."

It becomes:

- solve one linear congruence for `k`
- reconstruct the merged residue class for `x`

That is why extended Euclid sits at the heart of the general merge.

## Core Invariant And Why It Works

## 1. Merge Invariant

After processing some prefix of the system, keep exactly one invariant:

```text
current pair (a, m) means:
x ≡ a (mod m)
is equivalent to all congruences processed so far
```

If the next congruence is compatible, we update `(a, m)` to a new merged pair.

If it is incompatible, the whole system has no solution.

## 2. Coprime Textbook CRT

If `gcd(m1, m2) = 1`, the classical CRT says the two congruences have a unique solution modulo:

$$
m_1 m_2
$$

So in the coprime case, the merge always succeeds.

That is the clean theorem version many people remember first.

## 3. General Non-Coprime Merge

For the general case, let:

$$
g = \gcd(m_1, m_2)
$$

The system

$$
x \equiv a_1 \pmod {m_1}, \quad x \equiv a_2 \pmod {m_2}
$$

has a solution **iff**

$$
a_2 - a_1 \equiv 0 \pmod g
$$

This is the real consistency test.

Why?

Because any common solution forces:

$$
x - a_1
$$

to be divisible by `m1` and:

$$
x - a_2
$$

to be divisible by `m2`.

Subtracting gives:

$$
a_2 - a_1
$$

must be divisible by any common divisor of `m1` and `m2`, in particular by `g`.

If the difference passes that test, divide the equation by `g` and solve:

$$
\frac{m_1}{g} k \equiv \frac{a_2 - a_1}{g} \pmod {\frac{m_2}{g}}
$$

Now:

$$
\gcd\!\left(\frac{m_1}{g}, \frac{m_2}{g}\right)=1
$$

so the inverse exists modulo `m2 / g`, and one valid shift `k` can be recovered from extended Euclid.

The merged modulus becomes:

$$
\mathrm{lcm}(m_1, m_2)=\frac{m_1}{g} m_2
$$

## 4. Linear Congruence As A Doorway

The congruence

$$
a x \equiv b \pmod m
$$

is equivalent to:

$$
a x + m y = b
$$

for some integer `y`.

So it is a linear Diophantine equation.

That means:

- if `gcd(a, m)` does not divide `b`, there is no solution
- otherwise, divide by the gcd and solve using extended Euclid

This is why `extended-gcd-diophantine.cpp` is the natural compare point for this lane.

## Variant Chooser

### Use Plain Modular Arithmetic When

- you only need `powmod`, inverse, or factorial tables under one fixed prime modulus
- there is no congruence system to merge

That is the lane of:

- [Modular Arithmetic](../modular-arithmetic/README.md)

### Use Extended Euclid Alone When

- you only need one Bézout witness
- you only need one inverse under a composite modulus
- you only need to solve one equation `a x + b y = c`

That is the lane of:

- [Euclid Problem](../../../practice/ladders/math/gcd-lcm/euclidproblem.md)

### Use Chinese Remainder / Congruence Merging When

- two or more residue conditions must hold together
- pairwise-coprime CRT is enough, or
- the moduli are not coprime but gcd consistency may still allow a solution

This is the lane of:

- [General Chinese Remainder](../../../practice/ladders/math/chinese-remainder/generalchineseremainder.md)

### Mention Garner Only As A Compare Point

Garner is useful when:

- many pairwise-coprime moduli are already available
- you want reconstruction in mixed-radix form

That is **not** the first route this repo should teach for standard contest CRT.

## Worked Examples

### Example 1. Coprime Merge

Solve:

$$
x \equiv 2 \pmod 3,\quad x \equiv 3 \pmod 5
$$

Write:

$$
x = 2 + 3k
$$

Plug into the second congruence:

$$
2 + 3k \equiv 3 \pmod 5
$$

so:

$$
3k \equiv 1 \pmod 5
$$

The inverse of `3 mod 5` is `2`, so:

$$
k \equiv 2 \pmod 5
$$

Take `k = 2`:

$$
x = 2 + 3 \cdot 2 = 8
$$

Therefore:

$$
x \equiv 8 \pmod {15}
$$

### Example 2. Inconsistent Non-Coprime System

Solve:

$$
x \equiv 1 \pmod 4,\quad x \equiv 2 \pmod 6
$$

Here:

$$
g = \gcd(4,6)=2
$$

but:

$$
a_2-a_1 = 1
$$

is not divisible by `2`.

So there is **no solution**.

This is the standard trap people miss if they only memorize coprime CRT.

### Example 3. Kattis General Chinese Remainder

For one test case:

```text
x ≡ a (mod n)
x ≡ b (mod m)
```

the route is:

1. normalize to `(a, n)` and `(b, m)`
2. compute `g = gcd(n, m)`
3. if `(b - a) % g != 0`, print `no solution`
4. otherwise merge into:
   - one residue `x`
   - one modulus `lcm(n, m)`

That is exactly why the note is a clean flagship problem for this lane.

## Pseudocode

```text
merge(a1, m1, a2, m2):
    normalize a1 into [0, m1)
    normalize a2 into [0, m2)
    g, x, y = ext_gcd(m1, m2)
    diff = a2 - a1
    if diff % g != 0:
        return no solution
    mod = m2 / g
    t = ((diff / g) * x) mod mod
    lcm = (m1 / g) * m2
    ans = a1 + m1 * t
    ans = ans mod lcm
    return (ans, lcm)

crt_system(list):
    cur = (0, 1)
    for (a, m) in list:
        cur = merge(cur, (a, m))
        if cur is impossible:
            return impossible
    return cur
```

## Implementation Notes

- Normalize residues immediately into `[0, m)` before merging.
- Use `__int128` for products like `m1 * t` and `(m1 / g) * m2`.
- Keep the public result normalized to:
  - smallest nonnegative residue
  - modulus equal to the merged lcm
- Distinguish clearly between:
  - one inverse under composite modulus
  - one full congruence-system merge
- If the problem asks for many congruences, merge left to right and stop at the first inconsistency.

## Worked Compare Points In This Repo

- [Euclid Problem](../../../practice/ladders/math/gcd-lcm/euclidproblem.md): one Bézout witness, not a full system merge
- [General Chinese Remainder](../../../practice/ladders/math/chinese-remainder/generalchineseremainder.md): exact non-coprime merge route
- [Modular Arithmetic](../modular-arithmetic/README.md): the prime-mod toolbox this lane grows out of

## In This Repo

- [Chinese Remainder / Linear Congruences ladder](../../../practice/ladders/math/chinese-remainder/README.md)
- [Chinese Remainder hot sheet](../../../notebook/chinese-remainder-hot-sheet.md)
- [General Chinese Remainder note](../../../practice/ladders/math/chinese-remainder/generalchineseremainder.md)
- [starter template](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/chinese-remainder.cpp)
- compare points:
  - [Modular Arithmetic](../modular-arithmetic/README.md)
  - [Euclid Problem](../../../practice/ladders/math/gcd-lcm/euclidproblem.md)

## References

- Reference: [cp-algorithms - Chinese Remainder Theorem](https://cp-algorithms.com/algebra/chinese-remainder-theorem.html)
- Reference: [cp-algorithms - Linear Congruence Equation](https://cp-algorithms.com/algebra/linear_congruence_equation.html)
- Practice: [Kattis - General Chinese Remainder](https://open.kattis.com/problems/generalchineseremainder)
- Practice: [Library Checker - System of Linear Congruence](https://judge.yosupo.jp/problem/system_of_linear_congruence)
