# Inclusion-Exclusion

Inclusion-exclusion is the correction rule for counting a union when the easy counts overlap.

This topic starts where [Counting Basics](../counting-basics/README.md) stops:

- direct constructive counting is almost right
- but the counted cases overlap
- and the only missing ingredient is to correct the overcount systematically

In contest problems, the most common shape is:

- there are `m` bad properties or `m` divisibility conditions
- `m` is small enough to iterate subsets
- the intersection of any chosen subset is much easier to count than the final answer directly

## At A Glance

- **Use when:** you can count intersections of chosen conditions more easily than the final union/complement
- **Core worldview:** alternate signs over subset intersections so every object ends with the correct net contribution
- **Main tools:** union formula, complement formula, subset iteration, parity sign, intersection-size computation
- **Typical complexity:** often `O(2^m * cost(intersection))`
- **Main trap:** getting the sign logic right but counting the wrong subset intersection, or using PIE when a direct count is simpler

## Problem Model And Notation

Let:

$$
A_1, A_2, \dots, A_m
$$

be sets representing bad properties, required properties, or divisibility conditions.

The classical goal is to count:

$$
\left| A_1 \cup A_2 \cup \cdots \cup A_m \right|.
$$

The inclusion-exclusion formula is:

$$
\left| \bigcup_{i=1}^{m} A_i \right|
=
\sum_i |A_i|
- \sum_{i<j} |A_i \cap A_j|
+ \sum_{i<j<k} |A_i \cap A_j \cap A_k|
- \cdots
+ (-1)^{m+1} |A_1 \cap \cdots \cap A_m|.
$$

Equivalently, over all non-empty subsets `S` of `{1,2,\dots,m}`:

$$
\left| \bigcup_{i=1}^{m} A_i \right|
=
\sum_{\varnothing \ne S \subseteq [m]}
(-1)^{|S|+1}
\left| \bigcap_{i \in S} A_i \right|.
$$

This is the form most contest implementations use.

## From Brute Force To The Right Idea

### Brute Force: Count The Good Objects Directly

Suppose you want:

- strings avoiding forbidden letters
- numbers divisible by at least one of several values
- assignments satisfying at least one of several conditions

Direct counting often fails because:

- one object can satisfy several conditions at once
- naive addition counts that object multiple times

This is the central failure mode that inclusion-exclusion repairs.

### The First Shift: Count The Union Or Count Its Complement

Many problems can be phrased either as:

- count objects satisfying at least one property

or:

- count all objects, then subtract those satisfying none

The first modeling decision is:

- is the union easier to describe?
- or is the complement easier to describe?

Inclusion-exclusion works in both directions, but you must decide what your accumulator means.

### The Second Shift: Subset Intersections Are Often Easier Than The Final Answer

This is the real reason PIE works in contests.

A typical pattern:

- the final union is messy
- but once you fix a subset of conditions, the intersection count becomes simple

Examples:

- divisible by all numbers in a subset -> count with `\lfloor n / \mathrm{lcm} \rfloor`
- missing all letters in a subset -> count by reducing alphabet size
- satisfy all chosen forbidden equalities -> collapse to one easier configuration

### The Third Shift: Think "Net Contribution Of One Object"

The deepest intuition is not the formula itself.

It is:

- if an object lies in exactly `k` chosen bad sets, what total coefficient does it receive?

An object in exactly `k` bad sets contributes:

$$
\binom{k}{1}
- \binom{k}{2}
+ \binom{k}{3}
- \cdots
+ (-1)^{k+1}\binom{k}{k}
= 1.
$$

for the union formula.

Objects outside all bad sets contribute `0`.

That is why inclusion-exclusion is a correction mechanism:

- overcount first
- then subtract the overcorrections
- then add back the over-overcorrections

## Core Invariants And Why It Works

### 1. Union Formula

For two sets:

$$
|A \cup B| = |A| + |B| - |A \cap B|.
$$

This is already inclusion-exclusion:

- add both sets
- subtract the overlap counted twice

For three sets:

$$
|A \cup B \cup C|
= |A| + |B| + |C|
- |A \cap B| - |A \cap C| - |B \cap C|
+ |A \cap B \cap C|.
$$

The triple intersection must be added back because it was:

- counted three times in the singles
- subtracted three times in the pairs

So it was currently counted `0` times, but should be counted once.

The general formula is the exact same correction pattern over all subset sizes.

### 2. Contribution Proof

Suppose one object belongs to exactly `k` of the sets.

In the union formula, it appears:

- once for every chosen singleton containing it
- once for every chosen pair containing it
- once for every chosen triple containing it
- and so on

So its total coefficient is:

$$
\sum_{t=1}^{k} (-1)^{t+1} \binom{k}{t}.
$$

Using:

$$
\sum_{t=0}^{k} (-1)^t \binom{k}{t} = (1-1)^k = 0,
$$

we get:

$$
\sum_{t=1}^{k} (-1)^{t+1} \binom{k}{t} = 1.
$$

This proves that every object in the union is counted exactly once.

### 3. Complement Form

Sometimes the desired answer is:

- objects satisfying none of the bad properties

If `U` is the full universe, then:

$$
|\text{good}| = |U| - \left| \bigcup_{i=1}^{m} A_i \right|.
$$

In practice, this often leads to cleaner code:

```text
answer = total
for each non-empty subset S:
    contribution = size(intersection of conditions in S)
    if |S| is odd: answer -= contribution
    else: answer += contribution
```

This is the most common contest template.

### 4. Intersection Size Is The Real Problem

PIE is useful only if:

$$
\left| \bigcap_{i \in S} A_i \right|
$$

is easy enough to compute for every relevant subset `S`.

That is the main chooser question.

The sign pattern is never the hard part once you are disciplined.

The real hard part is:

- what exactly does one subset mean?
- and how do I count that intersection?

## Variant Chooser

### Use Inclusion-Exclusion When

- the number of conditions is small enough to iterate subsets
- the subset intersection is clean
- direct counting overlaps badly

Canonical smells:

- "at least one"
- "avoid all forbidden properties"
- "divisible by one of these values"
- "missing some letters / colors / symbols"

### Use Complementary Counting First When

- total objects are easy to count
- the "bad" union is what has overlapping structure

This is often cleaner than trying to count good objects directly.

### Use LCM/Product-Based PIE When

- conditions are divisibility conditions
- one subset means "divisible by all chosen values"

Then intersections often become:

$$
\left\lfloor \frac{n}{\mathrm{lcm}(S)} \right\rfloor.
$$

If the chosen numbers are distinct primes, that lcm simplifies to their product.

### Use Alphabet/Feature-Removal PIE When

- each bad property means "missing feature `i`"
- choosing a subset means those features are all simultaneously absent

Then the intersection often becomes:

- count with a reduced alphabet
- count with fewer available labels
- count after forcing some coordinates equal or forbidden

If the intersection size depends only on `|S|`, not on the actual identity of `S`, the formula often compresses nicely by grouping subsets of the same size.

### Move To Möbius / Sieve / DP When

- `m` is too large for subset iteration
- the conditions have arithmetic divisor structure better handled by Möbius inversion
- the intersection function itself requires substantial state DP

PIE is not the answer to every overlapping-count problem. It is the right answer when the subset space is still small enough.

## Worked Examples

### Example 1: Prime Multiples

Let:

$$
S_i = \{x \in [1,n] : a_i \mid x\}.
$$

We want:

$$
\left| S_1 \cup S_2 \cup \cdots \cup S_k \right|.
$$

For one subset `T`, the intersection means:

- `x` is divisible by every `a_i` in `T`

So:

$$
\left| \bigcap_{i \in T} S_i \right|
=
\left\lfloor \frac{n}{\mathrm{lcm}(a_i : i \in T)} \right\rfloor.
$$

In [Prime Multiples](../../../practice/ladders/combinatorics/inclusion-exclusion/primemultiples.md), the inputs are distinct primes, so:

$$
\mathrm{lcm}(a_i : i \in T) = \prod_{i \in T} a_i.
$$

That makes the whole topic feel very clean:

- subset
- product
- parity sign

### Example 2: Strings Missing Some Letters

Suppose you count strings of length `n` over an alphabet of size `m` that use every letter at least once.

Let `A_i` be:

- strings missing letter `i`

Then for a subset `S` of letters forced missing:

$$
\left| \bigcap_{i \in S} A_i \right| = (m-|S|)^n.
$$

So the answer is:

$$
\sum_{s=0}^{m} (-1)^s \binom{m}{s}(m-s)^n.
$$

This is a textbook example of "subset chooses which features are absent".

### Example 3: Why PIE Can Be Overkill

Suppose a counting problem can already be solved by:

- choose positions of the special elements

with no overlap ambiguity.

Then PIE is unnecessary.

This is the important boundary with [Counting Basics](../counting-basics/README.md):

- do not introduce alternating signs if one direct bijection already counts everything exactly once

### Example 4: Overflow In LCM-Based PIE

Suppose you enumerate subsets and compute:

$$
\mathrm{lcm}(a_1,\dots,a_t)
$$

incrementally.

If that lcm exceeds `n`, then:

$$
\left\lfloor \frac{n}{\mathrm{lcm}} \right\rfloor = 0,
$$

so the subset contributes nothing.

In code, stop early once the running lcm or running product exceeds the useful threshold.

This is one of the most important implementation patterns in divisibility PIE.

## Algorithms And Pseudocode

### Count A Union By Subset Iteration

```text
answer = 0
for each non-empty subset S:
    inter = size_of_intersection(S)
    if popcount(S) is odd:
        answer += inter
    else:
        answer -= inter
```

### Count A Complement By Subtracting The Union

```text
answer = total_objects
for each non-empty subset S:
    inter = size_of_intersection(S)
    if popcount(S) is odd:
        answer -= inter
    else:
        answer += inter
```

### LCM/Product Guard Pattern

```text
value = 1
valid = true
for each chosen number x:
    if value would exceed limit after combining with x:
        valid = false
        break
    value = combine(value, x)   // often lcm or product

if valid:
    use floor(limit / value)
else:
    contribution = 0
```

The structure is simple, but the correctness depends on defining `size_of_intersection(S)` exactly.

## Implementation Notes

### 1. Decide What The Accumulator Means

Before coding, say one sentence out loud:

- "my accumulator is counting the union"
- or
- "my accumulator is counting good objects by subtracting bad unions from total"

This prevents sign drift halfway through implementation.

### 2. A Subset Must Have A Clear Semantic Meaning

Never iterate subsets mechanically.

For each subset `S`, you should be able to finish the sentence:

- "`S` means all these properties happen simultaneously"

If that sentence is unclear, the intersection count is probably unclear too.

### 3. `popcount(S)` Controls The Sign, Not The Story

The sign rule comes only from subset size parity.

Do not invent custom sign rules based on the statement wording. Keep the math invariant fixed.

### 4. Stop LCM/Product Growth Early

In number-theory PIE, it is common that:

- the real contribution becomes `0` once the running lcm exceeds `n`

Stopping early is both faster and safer.

### 5. PIE Is Often A Modeling Layer, Not The Whole Solution

Sometimes PIE wraps another primitive:

- modular exponentiation
- binomial coefficients
- number-theory preprocessing
- subset DP

That is normal. PIE answers the overlap question, not necessarily the whole implementation question.

### 6. Small Brute Force Is Extremely Valuable Here

PIE formulas are easy to sign-flip or misinterpret.

So for tiny parameters, brute-force enumeration is one of the best sanity checks you can run before trusting the alternating-sign code.

### 7. "At Least One" And "Exactly One" Are Different Targets

PIE most directly gives:

- union size
- or complement of a union

If the problem asks for:

- exactly one property
- exactly `t` satisfied properties

then you usually need one extra translation step after the basic PIE viewpoint. Do not assume the standard union formula answers that target without modification.

## Practice Archetypes

The most common inclusion-exclusion-shaped tasks are:

- **count numbers divisible by at least one chosen divisor**
- **count objects avoiding one or more forbidden features**
- **count surjections / all-features-used objects**
- **count complements where direct good-counting overlaps**
- **subset-sign formulas where each subset collapses to one easy intersection**

Strong contest smells include:

- the words "at least one", "none of", "avoid all", "use every"
- a small number of conditions, often `m <= 20`
- one subset intersection is easy, but the full union is not
- direct constructive counting almost works but overlaps

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Primary / course:

- [MIT OCW: Inclusion-Exclusion (Principles of Discrete Applied Mathematics)](https://ocw.mit.edu/courses/18-200-principles-of-discrete-applied-mathematics-spring-2024/resources/18200-lecture-3-version-2_mp4/)
- [MIT Combinatorics: The Fine Art of Counting, lecture notes index](https://mitocw.ups.edu.ec/high-school/mathematics/combinatorics-the-fine-art-of-counting/lecture-notes/)
- [Stanford CS109 lecture notes: Combinatorics](https://web.stanford.edu/class/archive/cs/cs109/cs109.1248/lectures/2-Combinatorics/2-Combinatorics.pdf)

Course / notes:

- [Exploring Combinatorics: Inclusion-Exclusion notes](https://borisbukh.org/CombinatoricsSpring13/notes_inclusion_exclusion.pdf)

Reference:

- [CP-Algorithms: Inclusion-Exclusion Principle](https://cp-algorithms.com/combinatorics/inclusion-exclusion.html)
- [OI Wiki: Inclusion-Exclusion Principle](https://en.oi-wiki.org/math/combinatorics/inclusion-exclusion/)
- [USACO Guide: PIE](https://usaco.guide/plat/PIE?lang=cpp)

Practice:

- [Prime Multiples](../../../practice/ladders/combinatorics/inclusion-exclusion/primemultiples.md)

Repo anchors:

- ladder: [Inclusion-Exclusion ladder](../../../practice/ladders/combinatorics/inclusion-exclusion/README.md)
- notebook refresher: [Combinatorics Cheatsheet](../../../notebook/combinatorics-cheatsheet.md)
- adjacent topic: [Counting Basics](../counting-basics/README.md)
- adjacent topic: [Number Theory Basics](../../math/number-theory-basics/README.md)

## Related Topics

- [Counting Basics](../counting-basics/README.md)
- [Bounded Compositions](../bounded-compositions/README.md)
- [Number Theory Basics](../../math/number-theory-basics/README.md)
- [Bitmask DP](../../dp/bitmask-dp/README.md)
