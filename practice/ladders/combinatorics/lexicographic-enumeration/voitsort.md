# VOITSORT

- Title: `Cây hoán vị`
- Judge / source: `VN SPOJ`
- Original URL: [https://vn.spoj.com/problems/VOITSORT/](https://vn.spoj.com/problems/VOITSORT/)
- Secondary topics: `Cartesian tree`, `Stack-sortable permutations`, `Next permutation`
- Difficulty: `hard`
- Subtype: `Count stack-sortable permutations in a short lexicographic interval`
- Source contest: `VOI 2015 Day 2`
- Status: `solved`
- Solution file: [voitsort.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/combinatorics/lexicographic-enumeration/voitsort.cpp)

## Why Practice This

This is a strong permutation problem because the tree definition looks specialized, but the real key is recognizing a known permutation operator. After that, the second trick is to exploit the small bound `k <= 10^6 < 10!`.

## Key Idea

The binary tree `T(pi)` is the max-Cartesian tree of the permutation `pi`, and the required listing order is its postorder traversal.

A standard fact is:

- postorder of the max-Cartesian tree of `pi`
- equals the result of passing `pi` through one stack

So the `TSort` property means exactly:

- `pi` is sortable by one stack into `(1, 2, ..., n)`

That is much easier to test. Simulate the usual stack-sorting process:

1. read the permutation from left to right
2. push each value
3. while the stack top equals the next needed output, pop it

The permutation is `TSort` iff the whole process outputs `1, 2, ..., n`.

Now for the counting part:

- `k <= 10^6 < 10!`
- therefore, among `k` consecutive permutations in lexicographic order, only the last `10` positions can vary freely
- the interval crosses at most one boundary between blocks with fixed first `n - 10` positions

So:

1. split the interval into at most two blocks
2. in each block, keep the prefix fixed
3. enumerate only the suffix permutations of the last `d = min(n, 10)` positions
4. test each full permutation by:
   - simulating the fixed prefix once
   - finishing the stack simulation on the small suffix

That gives `O(n + k * d)` with `d <= 10`.

## Complexity

- block setup: `O(n)`
- testing each candidate suffix: `O(d)`
- total: `O(n + k * d)` with `d <= 10`

This is fast enough for `n <= 1000`, `k <= 10^6`.

## Pitfalls / Judge Notes

- The tree formulation is a disguise. The main equivalence is to one-stack sorting.
- Do not iterate `k` times with full `next_permutation` on all `n` elements. That would be too slow.
- The `10!` observation is the whole optimization: only the suffix block changes significantly.
- When the interval crosses the end of a suffix block, rebuild the next block once, then continue.

## Reusable Pattern

- Topic page: [Lexicographic Enumeration](../../../../topics/combinatorics/lexicographic-enumeration/README.md)
- Practice ladder: [Lexicographic Enumeration ladder](README.md)
- Starter template: [Template library overview](../../../../template-library.md)
- Notebook refresher: [Combinatorics cheatsheet](../../../../notebook/combinatorics-cheatsheet.md)
- Carry forward: make the order relation precise before you try to rank, unrank, or enumerate.
- This note adds: the ordering rule and state transitions that are unique to this enumeration problem.

## Solutions

- Code: [voitsort.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/combinatorics/lexicographic-enumeration/voitsort.cpp)
