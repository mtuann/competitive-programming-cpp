# Mobius And Multiplicative Counting

This lane starts when a gcd-counting problem stops being:

```text
try every pair, compute gcd, and count the good ones
```

and becomes:

```text
the right inclusion-exclusion lives on divisors, not on explicit pairs
```

The key shift is:

- stop iterating over pairs
- count how many values are divisible by each `d`
- use Mobius cancellation to isolate the exact gcd condition you want

For contest work, this is the clean exact route for:

- counting unordered pairs with `gcd = 1`
- turning divisor-sum information into exact gcd information
- arithmetic inclusion-exclusion where "all divisors up to MAX" matter
- multiplicative-counting tasks that want one linear sieve plus one multiples loop

## At A Glance

- **Use when:** the statement is really about gcd/divisibility counts over many values, and the clean answer is a sum over divisors
- **Core worldview:** Mobius gives the cancellation identity that turns "gcd is divisible by d" counts into "gcd is exactly 1" counts
- **Main tools:** Mobius function `mu`, linear sieve, divisor-frequency arrays, sums over multiples
- **Typical complexity:** `O(MAX)` for `mu` with a linear sieve, plus `O(MAX log MAX)` style multiples loops
- **Main trap:** deriving the Mobius formula correctly, then still counting ordered pairs or forgetting the `C(cnt[d], 2)` combinatorial factor

Strong contest signals:

- you need the number of pairs whose gcd is `1`
- the values are bounded, often by `10^6` or similar
- the statement is about divisibility structure across the whole array, not one query value
- ordinary prime-set inclusion-exclusion would have to range over too many divisors

Strong anti-cues:

- the problem gives one small explicit set of primes, so ordinary inclusion-exclusion is enough
- you only need the largest divisor with frequency at least `2`
- the main work is modular arithmetic or congruence solving, not divisor counting
- the value bound is too large for a multiples loop over all `d <= MAX`

## Prerequisites

- [Number Theory Basics](../number-theory-basics/README.md)
- [Inclusion-Exclusion](../../combinatorics/inclusion-exclusion/README.md)

Helpful nearby anchors:

- [Common Divisors](../../../practice/ladders/math/gcd-lcm/commondivisors.md)
- [Prime Multiples](../../../practice/ladders/combinatorics/inclusion-exclusion/primemultiples.md)
- [Number theory cheatsheet](../../../notebook/number-theory-cheatsheet.md)

## Problem Model And Notation

The Mobius function is:

$$
\mu(1)=1
$$

$$
\mu(n)=0 \text{ if } n \text{ is divisible by a square}
$$

$$
\mu(n)=(-1)^k \text{ if } n \text{ is square-free with } k \text{ distinct prime factors}
$$

The cancellation identity to remember is:

$$
\sum_{d \mid n} \mu(d) =
\begin{cases}
1 & n = 1 \\
0 & n > 1
\end{cases}
$$

This is the exact arithmetic version of inclusion-exclusion over prime divisors.

For array problems, a standard helper is:

$$
\text{cnt}[d] = \#\{a_i : d \mid a_i\}
$$

That is:

- `cnt[d]` counts values divisible by `d`
- `C(cnt[d], 2)` counts unordered pairs whose gcd is divisible by `d`

Then Mobius cancellation can isolate the exact gcd event you want.

## From Brute Force To The Right Idea

### Brute Force

For a task like "count coprime pairs in an array", the most direct route is:

- iterate over all unordered pairs
- compute `gcd(a[i], a[j])`
- count the ones equal to `1`

That is `O(n^2 log A)`, which dies immediately once `n` reaches `10^5`.

### First Structural Observation

Pair problems about gcd are often easier if you count by divisor:

- how many values are divisible by `1`
- how many by `2`
- how many by `3`
- ...

Once you know `cnt[d]`, you also know how many unordered pairs have gcd divisible by `d`:

$$
\binom{\text{cnt}[d]}{2}
$$

So the problem is no longer pairwise gcd checking.

It becomes one divisor-frequency precompute.

### Second Structural Observation

The event

```text
gcd(x, y) = 1
```

is equivalent to:

```text
the gcd has no prime divisor
```

That is an inclusion-exclusion statement.

But the clean contest version is not:

- enumerate prime subsets for every pair

It is:

- sum over divisors with Mobius weights

This is exactly where Mobius function earns its keep.

## Core Invariant And Why It Works

## 1. Mobius Is Divisor-Side Inclusion-Exclusion

For a positive integer `g`,

$$
\sum_{d \mid g} \mu(d)
$$

acts like an indicator:

- it is `1` when `g = 1`
- it is `0` otherwise

So for any pair `(x, y)`:

$$
[ \gcd(x, y) = 1 ] = \sum_{d \mid \gcd(x, y)} \mu(d)
$$

That one line is the core invariant of this whole lane.

## 2. Exchange The Order Of Counting

Summing over all unordered pairs:

$$
\sum_{i<j} [\gcd(a_i, a_j)=1]
=
\sum_{i<j} \sum_{d \mid \gcd(a_i, a_j)} \mu(d)
$$

Swap the summations:

$$
=
\sum_{d \ge 1} \mu(d)\cdot
\#\{(i,j): i<j,\ d \mid a_i,\ d \mid a_j\}
$$

But the inner count is exactly:

$$
\binom{\text{cnt}[d]}{2}
$$

So:

$$
\text{coprime pairs}
=
\sum_{d \ge 1} \mu(d)\binom{\text{cnt}[d]}{2}
$$

That is the flagship formula for this lane.

## 3. Why The Multiples Loop Works

If `freq[x]` is the count of occurrences of value `x`, then:

$$
\text{cnt}[d] = \sum_{k \ge 1} \text{freq}[k d]
$$

So you can compute every `cnt[d]` by iterating over multiples:

```text
for d in 1..MAX:
    for multiple in d, 2d, 3d, ...:
        cnt[d] += freq[multiple]
```

This is why the full lane remains contest-usable once `MAX` is only around `10^6`.

## 4. Mobius Inversion View

More generally, if:

$$
g(n) = \sum_{d \mid n} f(d)
$$

then Mobius inversion says:

$$
f(n) = \sum_{d \mid n} \mu(d)\, g(n/d)
$$

For contest work, the important lesson is not the algebraic slogan.

It is the route split:

- if the statement gives "sum over divisors" data, inversion may recover the exact function
- if the statement gives "pairs divisible by d" data, Mobius may recover the exact gcd layer

## Variant Chooser

### Use Direct Divisor-Frequency Counting When

- you only need a monotone condition like "at least two numbers share divisor `d`"
- the answer is something like the largest feasible gcd
- no exact cancellation by Mobius is needed

That is the route in:

- [Common Divisors](../../../practice/ladders/math/gcd-lcm/commondivisors.md)

### Use Ordinary Inclusion-Exclusion When

- the prime set is explicit and small
- the natural universe is subsets of primes, not all divisors up to `MAX`

That is the route in:

- [Prime Multiples](../../../practice/ladders/combinatorics/inclusion-exclusion/primemultiples.md)

### Use This Lane When

- all divisors up to `MAX` matter
- divisor frequencies are easy to aggregate
- exact gcd conditions like `gcd = 1` or exact divisor-side cancellation are the real bottleneck

### Do Not Overreach To Heavier Number-Theory Machinery

For the first ship of this lane, stay inside:

- one linear sieve
- one multiples loop
- one Mobius-weighted sum

Do not jump straight to:

- Dirichlet convolution as a separate topic
- Min_25 sieve
- large-`n` prefix sums of multiplicative functions

unless the statement truly needs them.

## Worked Examples

### Example 1. Small Coprime-Pairs Array

Take:

```text
[2, 3, 4, 9]
```

The unordered pairs are:

- `(2, 3)` coprime
- `(2, 4)` not coprime
- `(2, 9)` coprime
- `(3, 4)` coprime
- `(3, 9)` not coprime
- `(4, 9)` coprime

So the true answer is `4`.

Now compute by divisors:

- `cnt[1] = 4`
- `cnt[2] = 2`
- `cnt[3] = 2`
- `cnt[4] = 1`
- `cnt[9] = 1`

Relevant Mobius values:

- `mu[1] = 1`
- `mu[2] = -1`
- `mu[3] = -1`
- `mu[4] = 0`
- `mu[6] = 1`, but `cnt[6] = 0`

So:

$$
\sum_d \mu(d)\binom{\text{cnt}[d]}{2}
=
1\cdot \binom{4}{2}
-1\cdot \binom{2}{2}
-1\cdot \binom{2}{2}
= 6 - 1 - 1 = 4
$$

The Mobius sum exactly cancels every pair whose gcd is greater than `1`.

### Example 2. CSES Counting Coprime Pairs

For:

```text
5 4 20 1 16 17 5 15
```

the key observation is:

- `1` is divisible by every `d = 1` only, but it is coprime with every other value
- values like `20`, `16`, and `15` create many overlaps under divisors `2`, `4`, `5`
- the correct route is still the same:
  - frequency array
  - `cnt[d]` via multiples
  - Mobius-weighted pair sum

That yields the sample answer:

```text
19
```

The implementation lesson is that once the formula is correct, the problem becomes routine arithmetic precompute.

### Example 3. Exact GCD Layers

Sometimes you want:

```text
how many unordered pairs have gcd exactly g?
```

Then the same worldview still works.

Let:

$$
\text{cnt}_g[d] = \#\{a_i : gd \mid a_i\}
$$

and apply Mobius to the scaled divisor structure:

$$
\text{pairs with gcd exactly } g
=
\sum_{k \ge 1} \mu(k)\binom{\text{cnt}[gk]}{2}
$$

This is a good mental extension, even if the first flagship note only needs the `g = 1` case.

## Pseudocode

```text
read values
MAX = max(values)

mu = mobius_linear_sieve(MAX)
freq[x] = occurrence count of x

for d in 1..MAX:
    cnt[d] = 0
    for multiple in d, 2d, 3d, ...:
        cnt[d] += freq[multiple]

ans = 0
for d in 1..MAX:
    pairs = cnt[d] * (cnt[d] - 1) / 2
    ans += mu[d] * pairs

print ans
```

## Implementation Notes

- `mu[d] = 0` means "ignore this divisor completely" in the final sum.
- For unordered pairs, always use:

$$
\binom{cnt}{2} = \frac{cnt(cnt-1)}{2}
$$

not `cnt * cnt`.

- `cnt[d]` is usually built from a frequency array, not by factoring each input value separately.
- Use `long long` for the final answer and pair counts.
- If `MAX` is the maximum array value, the `for (multiple += d)` loops are the real complexity driver.

## References

- Reference: [OI Wiki - Mobius Inversion Formula](https://en.oi-wiki.org/math/mobius/)
- Reference: [cp-algorithms - Linear Sieve](https://cp-algorithms.com/algebra/prime-sieve-linear.html)
- Reference: [cp-algorithms - Inclusion-Exclusion Principle](https://cp-algorithms.com/combinatorics/inclusion-exclusion.html)
- Reference: [Competitive Programmer's Handbook](https://usaco.guide/CPH.pdf)
- Practice: [CSES - Counting Coprime Pairs](https://cses.fi/problemset/task/2417)

## Repo Anchors

- [Mobius And Multiplicative Counting ladder](../../../practice/ladders/math/mobius-multiplicative/README.md)
- [Exact starter template](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/mobius-linear-sieve.cpp)
- [Mobius hot sheet](../../../notebook/mobius-hot-sheet.md)
- [Counting Coprime Pairs note](../../../practice/ladders/math/mobius-multiplicative/countingcoprimepairs.md)
- Compare points:
  - [Number Theory Basics](../number-theory-basics/README.md)
  - [Inclusion-Exclusion](../../combinatorics/inclusion-exclusion/README.md)
  - [Common Divisors](../../../practice/ladders/math/gcd-lcm/commondivisors.md)
  - [Prime Multiples](../../../practice/ladders/combinatorics/inclusion-exclusion/primemultiples.md)
