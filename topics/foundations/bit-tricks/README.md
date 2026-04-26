# Bit Tricks

Bit tricks are the bridge between ordinary integer programming and the moment a
problem starts treating one integer as a packed set of boolean states.

This page is not about one single theorem.

It is the "learn to read bits as structure" bridge before you branch into:

- bitmask DP
- xor basis
- SOS / FWHT
- binary tries
- bitset-packed reachability

## At A Glance

- **Use when:** parity, powers of two, bitmasks, subset iteration, xor, or one bounded boolean universe is the real state
- **Core worldview:** an integer can act as a compact vector of boolean flags, not just as an arithmetic value
- **Main tools:** shifts, masks, `&`, `|`, `^`, `~`, `__builtin_popcount`, `lowbit`, subset iteration
- **Typical complexity:** `O(1)` per primitive operation, or `O(2^k)` / `O(k 2^k)` when the real state is one `k`-bit mask
- **Main trap:** treating bit operations as syntax trivia instead of defining what each bit actually means

Strong contest signals:

- the state is "which elements are chosen?"
- `n` is small enough that a subset mask is viable
- the statement asks about xor, parity, powers of two, or subset relations
- you need to encode many yes/no flags inside one compact state

Strong anti-cues:

- the real bottleneck is still arrays, sorting, or prefix sums
- the mask would need hundreds of bits and there is no bitset packing trick to save it
- the statement only mentions binary representation, but the clean invariant is not bitwise at all

## Prerequisites

- [C++ Language For Contests](../cpp-language/README.md)
- [Reasoning And Implementation Discipline](../reasoning/README.md)

Helpful neighboring topics:

- [Bitmask DP](../../dp/bitmask-dp/README.md)
- [Bit-Parallelism / Bitset Optimization](../../dp/bit-parallelism/README.md)
- [SOS DP](../../dp/sos-dp/README.md)
- [FWHT / XOR Convolution / Subset Convolution](../../dp/fwht-subset-convolution/README.md)
- [Binary Trie / XOR Queries](../../data-structures/binary-trie-xor/README.md)
- [XOR Basis / Linear Basis](../../math/xor-basis/README.md)

## Problem Model And Notation

The default mental model is:

- bit `i` of mask `m` tells you whether feature `i` is present
- the whole integer is one compact state

Common meanings:

- subset mask over `k` items
- parity or on/off flags
- set of visited small states
- xor value or binary trie path

If bit `i` is set, we write:

```text
m >> i & 1 = 1
```

and if we want to turn it on:

```text
m |= 1 << i
```

The important part is not the syntax.

It is deciding what each bit means before you start mutating the mask.

## From Brute Force To The Right Idea

### Brute Force: Track Booleans Separately

A beginner often stores:

- one boolean array
- one vector of chosen indices
- one set for membership

even when the whole state has only `k <= 20` binary decisions.

That can be fine for readability, but once:

- you need hashing or memoization
- you need to compare many states quickly
- or the transition is "toggle / add / remove one element"

the packed-mask model becomes the clean representation.

### The First Shift: State Compression

If the only information that matters is a collection of yes/no decisions, a
mask gives you:

- one integer state
- `O(1)` bit tests and updates
- cheap copying and hashing

That is why so many subset problems start with:

```text
dp[mask]
```

instead of a more verbose state object.

### The Second Shift: Arithmetic And Set Logic Split Apart

Once bits encode membership, different operations mean different combinatorial
things:

- `mask | other` means union of flags
- `mask & other` means intersection of flags
- `mask ^ other` means symmetric difference / xor logic
- `mask & -mask` isolates the least-significant set bit

This is the point where bit tricks stop being "micro-optimizations" and become
state algebra.

## Core Invariants And Why They Work

### 1. Each Bit Needs A Stable Meaning

The most important invariant is:

- bit `i` always means the same feature everywhere in the solution

If the mapping from bit position to semantic feature drifts, the code becomes
impossible to reason about.

### 2. Lowbit Is A Structural Tool

For a nonzero integer `x`,

```text
x & -x
```

isolates the least-significant set bit.

That is useful because:

- it extracts one chosen element
- it supports Fenwick intuition
- it lets you peel bits one by one

### 3. Subset Iteration Has Its Own Standard Loop

To iterate over all submasks `sub` of `mask`:

```text
for (int sub = mask; ; sub = (sub - 1) & mask) { ... }
```

This works because subtracting `1` flips the suffix in binary, and `& mask`
forces the result back inside the subset lattice.

That loop is a contest primitive, not an optional trick.

### 4. Packed Bits Are Still About Complexity

Using bits does not magically save an exponential algorithm.

It only helps when the true state width is already small enough, or when
machine-word packing gives you real constant-factor wins.

That is why this bridge page naturally hands off either to:

- [Bitmask DP](../../dp/bitmask-dp/README.md) for exact subset-state search
- [Bit-Parallelism / Bitset Optimization](../../dp/bit-parallelism/README.md) for machine-word packing

## Variant Chooser

### Stay On This Page When

- the main need is bit vocabulary, subset iteration, parity, xor, or powers of two

### Use Bitmask DP When

- the whole algorithm is really `dp[mask]` or `dp[pos][mask]`

### Use Bit-Parallelism When

- the state width is large, but the operations are shift/OR/AND style over many bits at once

### Use SOS / FWHT When

- the boolean-cube indexing law itself is the hard part

### Use XOR Basis Or Binary Trie When

- the object is not a subset-state DP, but xor structure over values in one live set

## Repo Anchors And Compare Points

- [School Excursion](../../../practice/ladders/dp/bit-parallelism/schoolexcursion.md)
- [Compatible Numbers](../../../practice/ladders/dp/sos-dp/compatiblenumbers.md)
- [Bitwise XOR Convolution](../../../practice/ladders/dp/fwht-subset-convolution/bitwisexorconvolution.md)
- [Vasiliy's Multiset](../../../practice/ladders/data-structures/binary-trie-xor/vasiliysmultiset.md)
- [XMAX](../../../practice/ladders/math/xor-basis/xmax.md)
- [Bit Tricks ladder](../../../practice/ladders/foundations/bit-tricks/README.md)

## Sources

- Reference: [CP-Algorithms - Bit manipulation](https://cp-algorithms.com/algebra/bit-manipulation.html)
- Reference: [Competitive Programmer's Handbook](https://www.cses.fi/book/book.pdf)
- Practice: [CSES Problem Set](https://cses.fi/problemset/)
