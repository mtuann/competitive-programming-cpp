# XMAX - XOR Maximization

- Title: `XMAX - XOR Maximization`
- Judge / source: `SPOJ`
- Original URL: [https://www.spoj.com/problems/XMAX/](https://www.spoj.com/problems/XMAX/)
- Secondary topics: `XOR basis`, `Linear independence over GF(2)`, `Maximum subset xor`
- Difficulty: `medium`
- Subtype: `Maximum xor obtainable from any subset of the given numbers`
- Status: `solved`
- Solution file: [xmax.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/xor-basis/xmax.cpp)

## Why Practice This

This is the cleanest in-repo anchor for the first exact `XOR Basis / Linear Basis` lane.

The statement asks for exactly one thing:

- maximum xor over all subsets of the given numbers

So the real lesson is not online updates or one best partner query.

It is:

- compress the set into one maximal linearly independent xor basis
- preserve the xor span exactly
- greedily recover the maximum possible value from that basis

## Recognition Cue

Reach for xor basis when:

- the task says "choose any subset"
- brute force is `2^n`
- representability or maximum xor over the whole subset space is the real question
- the natural structure is "independent xor generators", not one search tree over stored values

The strongest smell here is:

- "maximum xor obtainable from any subset"

That is the textbook first xor-basis problem.

## Problem-Specific Transformation

Build one xor basis from all input values.

Each insertion:

- either creates a new pivot vector
- or collapses to `0`, meaning the new number was already representable

Once the basis is built, the original problem is no longer:

- choose among exponentially many subsets

It becomes:

- greedily combine independent pivot vectors from high bit to low bit to maximize the answer

## Core Idea

Maintain at most one basis vector per highest set bit.

For each input value `x`:

1. scan bits from high to low
2. if the current highest set bit already has a pivot vector, xor it away
3. otherwise store `x` there and stop

This is Gaussian elimination over `GF(2)` in bitmask form.

After all insertions, the stored basis spans exactly the set of all subset xor values.

To get the maximum value:

1. start with `ans = 0`
2. scan pivot bits from high to low
3. if `ans xor basis[bit]` is larger, take it

That greedy choice is safe because higher bits dominate all lower bits.

## Complexity

If the bit width is `B + 1`:

- build: `O(nB)`
- maximum query: `O(B)`
- memory: `O(B)`

For `a_i <= 10^18`, `B = 60` is enough.

## Pitfalls / Judge Notes

- This is about xor of **any subset**, not xor with one chosen stored element.
- Dependent numbers may add nothing to the basis.
- Scan bits from high to low in both insertion and greedy maximum construction.
- Use `long long` carefully since values can reach `10^18`.

## Reusable Pattern

- Topic page: [XOR Basis / Linear Basis](../../../../topics/math/xor-basis/README.md)
- Practice ladder: [XOR Basis / Linear Basis ladder](README.md)
- Starter template: [xor-basis.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/xor-basis.cpp)
- Notebook refresher: [XOR Basis hot sheet](../../../../notebook/xor-basis-hot-sheet.md)
- Compare points:
  - [Binary Trie / XOR Queries](../../../../topics/data-structures/binary-trie-xor/README.md)
  - [Number theory cheatsheet](../../../../notebook/number-theory-cheatsheet.md)
- This note adds: the cleanest first maximum-subset-xor route, where the basis itself is the whole solution object.

## Solutions

- Code: [xmax.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/xor-basis/xmax.cpp)
