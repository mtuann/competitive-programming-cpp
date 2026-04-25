# Vasiliy's Multiset

- Title: `Vasiliy's Multiset`
- Judge / source: `Codeforces`
- Original URL: [https://codeforces.com/problemset/problem/706/D](https://codeforces.com/problemset/problem/706/D)
- Secondary topics: `Binary trie`, `Maximum xor query`, `Dynamic multiset`
- Difficulty: `medium`
- Subtype: `Insert / erase-one / maximum xor value in a live integer multiset`
- Status: `solved`
- Solution file: [vasiliysmultiset.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/binary-trie-xor/vasiliysmultiset.cpp)

## Why Practice This

This is the cleanest first exact benchmark for the binary-trie lane.

The statement already gives the whole contest signal:

- the multiset changes over time
- duplicates matter
- every query asks for the best xor partner among currently alive values

So the real lesson is not an isolated bit trick.

It is:

- one binary prefix tree can represent the whole live multiset
- counts keep deletion safe
- maximum xor is just one greedy walk through that live tree

## Recognition Cue

Reach for a binary trie when:

- insertions and deletions happen online
- the values are integers, but the natural query still walks one bit at a time
- the objective is "choose one stored value maximizing xor"
- scanning every stored value is too slow

The strongest smell here is:

- "dynamic multiset + best xor against one current query value"

That is the canonical first binary-trie problem.

## Problem-Specific Transformation

Maintain one binary trie over all currently alive values in the multiset.

The statement gives three operations:

- `+ x` -> `insert(x)`
- `- x` -> `erase_one(x)`
- `? x` -> `max_xor_value(x)`

The multiset initially contains `0`, so seed the trie with `0` before processing queries.

Now the original problem is no longer "store many integers and compare each query against all of them."

It becomes:

- store one live bit-prefix structure
- keep counts on every prefix
- answer each `? x` by greedily taking the preferred alive branch from high bit to low bit

## Core Idea

At one bit position:

- if `x` has bit `0`, we prefer stored bit `1`
- if `x` has bit `1`, we prefer stored bit `0`

That makes the xor bit at this position equal to `1`.

This greedy step is safe because higher xor bits dominate all lower bits.

The trie needs counts because of deletion:

- a branch that exists physically may still be dead logically if its count is zero

So the query rule is:

1. try the opposite-bit child
2. only take it if its count is positive
3. otherwise take the same-bit child

That gives the maximum xor value in `O(B)` time.

## Complexity

For fixed bit width `B + 1`:

- insert: `O(B)`
- erase-one: `O(B)`
- query: `O(B)`
- memory: `O(number of created trie nodes)`

For this problem, `B = 30` is enough.

## Pitfalls / Judge Notes

- Seed the trie with `0` before processing any query.
- This is a **multiset**, so `erase_one(x)` removes only one occurrence.
- Keep one fixed bit width for all operations.
- Do not trust node existence alone; always check subtree counts.
- The required answer is the xor value, not the chosen partner itself.

## Reusable Pattern

- Topic page: [Binary Trie / XOR Queries](../../../../topics/data-structures/binary-trie-xor/README.md)
- Practice ladder: [Binary Trie / XOR Queries ladder](README.md)
- Starter template: [binary-trie-xor.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/binary-trie-xor.cpp)
- Notebook refresher: [Binary Trie hot sheet](../../../../notebook/binary-trie-hot-sheet.md)
- Compare points:
  - [Trie](../../../../topics/strings/trie/README.md)
  - [Data Structures cheatsheet](../../../../notebook/data-structures-cheatsheet.md)
- Carry forward: when the best answer is "one stored element maximizing xor," turn the set into a fixed-width bit-prefix tree.
- This note adds: the exact multiset deletion policy and the mandatory `0` seed pattern.

## Solutions

- Code: [vasiliysmultiset.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/binary-trie-xor/vasiliysmultiset.cpp)
