# Burnside / Pólya / Group Actions

This topic starts when plain counting is no longer enough because several representations describe the same object.

The first exact route in this repo is intentionally narrow:

- colorings of positions on a cycle
- equivalence under rotation only
- Burnside's lemma to average fixed colorings

Then the family widens to:

- dihedral symmetries with reflections
- grid colorings under quarter-turn rotations
- full Pólya inventory / cycle-index counting when colors are not just anonymous `k` choices

## At A Glance

- **Use when:** the statement says two configurations are the same up to rotation or another explicit symmetry
- **Core worldview:** count orbits, not raw representations
- **Main tools:** Burnside's lemma, cycle decomposition of one permutation, modular exponentiation
- **Typical complexity:** often `O(|G| * cost(fixed-count))`, or better after grouping equal cycle structures
- **Main trap:** counting all representations correctly but forgetting to quotient by symmetry in the right way

## Prerequisites

- [Counting Basics](../counting-basics/README.md)
- [Modular Arithmetic](../../math/modular-arithmetic/README.md)

Helpful but light background:

- `gcd(n, r)` as the number of cycles created by a rotation of length `r`
- the idea that one permutation decomposes positions into independent cycles

## Problem Model And Notation

Let:

- `X` be the set of raw representations
- `G` be a finite group of symmetries acting on `X`

Examples:

- strings of length `n`, with cyclic shifts acting on positions
- `n x n` black/white grids, with quarter-turn rotations acting on cells

The real objects we want to count are the **orbits** of this action.

Burnside's lemma says:

$$
|X / G| = \frac{1}{|G|} \sum_{g \in G} \mathrm{fix}(g),
$$

where `fix(g)` is the number of representations unchanged by symmetry `g`.

For contest use, the whole game becomes:

1. identify the symmetry group
2. count fixed colorings for each group element
3. average

## First Exact Route In This Repo

The starter contract is:

- positions are the `n` pearls of a necklace
- each position has `m` possible colors
- two colorings are equivalent if one is a cyclic rotation of the other
- answer is required modulo one fixed prime

This is the `C_n` action on length-`n` strings.

The repo starter intentionally stops here:

- **yes:** rotations on one cycle
- **not yet:** reflections, bracelets, arbitrary finite groups, full inventory polynomials

## From Brute Force To The Right Idea

### Brute Force Fails Immediately

There are `m^n` raw strings.

You could try:

- generate every coloring
- compute its canonical rotation
- deduplicate

That is conceptually fine but useless at contest sizes.

### Burnside Replaces Deduplication With Fixed Counts

Instead of asking:

- "how many distinct representatives survive after deduplication?"

ask:

- "for each rotation, how many colorings stay unchanged?"

That is much easier.

### Why One Rotation Is Easy

Fix a rotation by `r`.

Position `i` moves to `i + r mod n`. Repeating that movement partitions the `n` positions into cycles.

The number of cycles is:

$$
\gcd(n, r).
$$

Why this matters:

- every position in one cycle must share the same color if the coloring is fixed
- different cycles can choose colors independently

So the number of fixed colorings under rotation `r` is:

$$
m^{\gcd(n, r)}.
$$

### The Necklace Formula

Burnside now gives:

$$
\text{necklaces}(n, m)
=
\frac{1}{n}
\sum_{r=0}^{n-1} m^{\gcd(n, r)}.
$$

This is the first exact route the repo teaches.

Equivalent grouped form:

$$
\text{necklaces}(n, m)
=
\frac{1}{n}
\sum_{d \mid n} \varphi(d)\, m^{n/d}.
$$

That grouped divisor form is useful later, but the starter is written around the direct Burnside rotation scan because it keeps the logic visible.

## Core Invariants And Why It Works

### 1. Orbit Counting, Not Representation Counting

The answer is not `m^n`.

It is the number of equivalence classes after quotienting by symmetry.

If you are still counting strings directly, you are one abstraction layer too low.

### 2. A Fixed Coloring Must Be Constant On Each Permutation Cycle

This is the contest-level invariant that turns abstract group action into code.

For a permutation `g` acting on positions:

- each cycle of `g` must receive one uniform color
- each cycle chooses independently

So if `g` has `c(g)` cycles, then:

$$
\mathrm{fix}(g) = m^{c(g)}.
$$

This is exactly the special-case bridge from Burnside to the contest-friendly `k^{#cycles}` viewpoint often attributed to Pólya.

### 3. The Repo Starter Assumes Modular Division Is Legal

The starter uses one fixed prime modulus and divides by `|G|` using an inverse.

That means:

- you should already trust the [Modular Arithmetic](../../math/modular-arithmetic/README.md) route
- the exact starter contract is "fixed prime modulus, group size invertible modulo `MOD`"

For `CSES - Counting Necklaces`, this is safe because `n <= 10^6 < 10^9 + 7`.

## Recognition Cues

Reach for this topic when:

- the statement says two configurations are identical after rotation
- you are counting colorings or labelings up to symmetry
- the group is small and explicit, even if the representation set is huge
- direct deduplication would be easy to describe but impossible to run

Strong contest smells:

- necklace / bracelet / ring
- grid or polygon colorings up to rotation
- "consider two objects equal if one can be rotated into the other"

## Anti-Cues

Do **not** open this lane first when:

- there is no quotient by symmetry at all
- the only real task is modular exponentiation or inverse work
- the object is labeled and all rotations remain distinct by statement
- the main bottleneck is DP or graph modeling, not orbit counting

In those cases, reopen:

- [Counting Basics](../counting-basics/README.md)
- [Modular Arithmetic](../../math/modular-arithmetic/README.md)

## Common Pitfalls

- averaging the raw number of colorings instead of the fixed-coloring counts
- forgetting that the group is rotations only, not rotations plus reflections
- computing the right Burnside sum but dividing illegally modulo a composite
- using the starter when the real task needs a cycle index with weighted colors or exact multiplicities

## Stretch Routes After The First Lane

After `Counting Necklaces`, the natural next openings are:

- **quarter-turn grid rotations**
  - example: [Counting Grids](https://cses.fi/problemset/task/2210)
  - same Burnside worldview, different cycle counts for `0`, `90`, `180`, and `270` degrees
- **bracelets / dihedral symmetry**
  - add reflections and separate the odd/even `n` cases carefully
- **full Pólya inventory**
  - use cycle index when colors have structured weights or bounded inventories

## Solved Example In This Repo

- [Counting Necklaces](../../../practice/ladders/combinatorics/burnside-polya/countingnecklaces.md): first exact Burnside route on cyclic rotations, with `m^{gcd(n,r)}` fixed-count logic visible in full

## Related Topics

- [Counting Basics](../counting-basics/README.md)
- [Inclusion-Exclusion](../inclusion-exclusion/README.md)
- [Modular Arithmetic](../../math/modular-arithmetic/README.md)

## Go Deeper

- Reference: [cp-algorithms - Burnside's lemma / Pólya enumeration theorem](https://cp-algorithms.com/combinatorics/burnside.html)
- Reference: [Competitive Programmer's Handbook](https://www.cses.fi/book/book.pdf)
- Practice: [CSES - Counting Necklaces](https://cses.fi/problemset/task/2209)
- Practice: [CSES - Counting Grids](https://cses.fi/problemset/task/2210)
