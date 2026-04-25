# Binary Trie / XOR Queries

Binary trie is the right answer when:

- the maintained set is a set or multiset of **non-negative integers**
- every value is read bit by bit under one fixed width
- the query asks for the best stored number under an xor objective
- brute-forcing all stored numbers per query is too slow

This lane is best learned as a **data-structure lane**, not hidden inside plain [Trie](../../strings/trie/README.md).

The repo's exact first route for this family is:

- starter -> [binary-trie-xor.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/binary-trie-xor.cpp)
- flagship note -> [Vasiliy's Multiset](../../../practice/ladders/data-structures/binary-trie-xor/vasiliysmultiset.md)
- compare point -> [Trie](../../strings/trie/README.md)

## At A Glance

- **Use when:** insert / erase / query all happen against one evolving multiset of integers and the score is built greedily bit by bit
- **Core worldview:** every node represents one binary prefix of the stored numbers
- **Main tools:** fixed bit width, subtree counts, greedy opposite-bit walk for maximum xor
- **Typical complexity:** `O(B)` per insert, erase, or query where `B` is the chosen bit width
- **Main trap:** forgetting that deletion needs counts, not just pointers

Strong contest signals:

- "insert / erase / max xor query"
- "find one stored number that maximizes `x xor y`"
- "prefix xor values are inserted one by one, then each new prefix asks for best xor partner"
- "the values are integers, but the natural traversal is by bits"

Strong anti-cues:

- the task is about xor against **any subset** rather than against one stored element -> binary trie is the wrong family
- only one offline batch of values matters and one linear scan or sort trick already works
- the real task is still string-prefix lookup or dictionary matching -> [Trie](../../strings/trie/README.md)
- the statement needs counts like "how many prefixes have xor < K" and you have not checked whether the starter's exact API still fits

## Prerequisites

- [C++ Language For Contests](../../foundations/cpp-language/README.md) only at the level of reading and writing bits consistently
- [Trie](../../strings/trie/README.md) as the structural ancestor
- [Prefix Sums](../../foundations/patterns/prefix-sums/README.md) for the maximum-xor-subarray compare route

Helpful compare points:

- [Trie](../../strings/trie/README.md): same prefix-tree idea, but over characters rather than bits
- [Fenwick Tree](../fenwick-tree/README.md): not a fit when the target is "best xor partner" instead of one mergeable prefix aggregate
- [Offline Tricks](../offline-tricks/README.md): reordering queries does not remove the need for the xor data structure itself

## Problem Model And Notation

Let `S` be a multiset of non-negative integers.

Choose one fixed bit width:

$$
B + 1
$$

and represent every value using bits:

$$
b_B b_{B-1} \dots b_0
$$

A binary-trie node corresponds to one binary prefix. Its children are:

- `0` child
- `1` child

The key metadata is:

- `cnt[v]`: how many stored numbers pass through node `v`

That turns the trie from a static reachability structure into a dynamic multiset structure.

The hidden contract is:

```text
every inserted value and every query must use the same bit width
```

Without that, the tree shape itself becomes inconsistent.

## From Brute Force To The Right Idea

### Brute Force

For a query value `x`, scan all `y in S` and compute:

$$
x \oplus y
$$

Then take the maximum.

This is fine for tiny sets, but if there are `q` insert / erase / query operations, the cost becomes:

$$
O(q \cdot |S|)
$$

or worse.

### The Bitwise Pivot

For maximum xor, the most significant differing bit dominates all lower bits.

So if we inspect bits from high to low:

- at bit `b`, if `x` has bit `0`, we prefer a stored number with bit `1`
- if `x` has bit `1`, we prefer a stored number with bit `0`

That is a greedy choice, but it is safe because winning a higher bit is always better than anything lower bits can compensate for.

So instead of treating numbers as indivisible keys, we walk them by binary prefixes.

That is exactly what a trie gives us.

## Core Invariant And Why It Works

For every node representing one binary prefix `p`:

```text
cnt[p] = number of stored values whose fixed-width binary representation begins with p
```

This single invariant explains everything.

### 1. Why Insert Works

When inserting one number `x`:

1. start at the root
2. read bits from most significant to least significant
3. create missing children as needed
4. increment `cnt` on every visited node

After that, every prefix on the path correctly records that one more number passes through it.

### 2. Why Erase-One Works

Erasing one occurrence of `x` means:

1. traverse the exact bit path of `x`
2. decrement `cnt` on every visited node

The children can stay allocated even if `cnt` becomes zero.

That is why deletion in the first starter is about **counts**, not physical node removal.

### 3. Why Maximum-Xor Query Works

Suppose we query value `x`.

At bit `b`:

- let `bit = (x >> b) & 1`
- the preferred child is `bit ^ 1`

If that preferred child exists and its count is positive, taking it makes the xor bit at position `b` equal to `1`.

If not, we must take the same-bit child and accept xor bit `0`.

This greedy rule is correct because:

- a `1` at a more significant xor bit is always better than any pattern of lower bits
- subtree counts tell us whether the preferred branch actually contains a live stored number

So the trie turns "best xor partner" into a sequence of locally forced prefix choices.

## Worked Examples

### Example 1: Dynamic Multiset Maximum Xor

This repo's flagship note:

- [Vasiliy's Multiset](../../../practice/ladders/data-structures/binary-trie-xor/vasiliysmultiset.md)

Operations:

- `+ x`: insert one occurrence
- `- x`: erase one occurrence
- `? x`: return the maximum value of `x xor y` over stored `y`

This is the cleanest first benchmark because:

- the multiset is truly dynamic
- duplicates matter
- maximum xor is the whole query target

### Example 2: Maximum Xor Subarray

Let prefix xors be:

$$
pref_i = a_0 \oplus a_1 \oplus \dots \oplus a_i
$$

Then xor of subarray `(l..r)` is:

$$
pref_r \oplus pref_{l-1}
$$

So when scanning prefixes left to right:

- insert all previous prefix xors into the binary trie
- for the current prefix xor, ask for its best xor partner already seen

This is the bridge from "dynamic multiset query" to "bitwise array problem."

### Example 3: Why Plain Trie Is Only The Ancestor

In [Trie](../../strings/trie/README.md), the natural questions are:

- does this word exist?
- how many words share this prefix?

In binary trie, the natural questions are:

- can I choose a stored branch that optimizes the xor bit here?

So the structure is inherited from trie, but the contest objective is different:

- dictionary logic -> membership / prefix counting
- binary-trie logic -> numeric optimization under a fixed bit width

## Complexity And Tradeoffs

If the chosen width is `B + 1`, then:

- insert: `O(B)`
- erase-one: `O(B)`
- max xor query: `O(B)`
- memory: `O(number of created trie nodes)`

For the ordinary `0 <= x <= 10^9` contest lane, `B = 30` is common.

Tradeoffs:

- great for "one stored element maximizing xor"
- not the right tool for xor against arbitrary subsets
- heavier than a simple sorted container when the statement never asks for bitwise optimization

## Starter Fit

The starter in this repo is intentionally narrow:

- dynamic multiset of non-negative integers
- fixed bit width chosen once
- `insert`
- `erase_one`
- `count_value`
- `max_xor_value`

That is enough for:

- `Vasiliy's Multiset`
- maximum-xor-prefix style scans after a light wrapper

It is **not** sold as:

- a counting-trie for inequalities like `xor < K`
- a signed-integer xor structure
- a compressed bitwise Patricia trie

## Pseudocode

```text
insert(x):
    v = root
    cnt[v]++
    for b from MAX_BIT down to 0:
        bit = (x >> b) & 1
        if child[v][bit] missing:
            create it
        v = child[v][bit]
        cnt[v]++

max_xor_value(x):
    if trie empty:
        fail
    v = root
    ans = 0
    for b from MAX_BIT down to 0:
        bit = (x >> b) & 1
        want = bit ^ 1
        if child[v][want] exists and cnt[child[v][want]] > 0:
            ans |= (1 << b)
            v = child[v][want]
        else:
            v = child[v][bit]
    return ans
```

## Implementation Notes

- Fix the bit width once at construction time.
- Seed the trie with `0` if the problem guarantees queries before any real insertion or if prefix-xor logic wants the empty prefix alive.
- Deletion should only decrement counts; do not rely on node destruction.
- If duplicates are allowed, `erase_one(x)` must remove exactly one occurrence.
- If the statement value range is larger than `2^31`, widen both the stored type and the shift logic consistently.

## References And Repo Anchors

Research sweep refreshed on `2026-04-25`.

Course / reference:

- [OI Wiki: Trie](https://en.oi-wiki.org/string/trie/)
- [USACO Guide: Trie](https://usaco.guide/gold/trie)
- [Competitive Programmer's Handbook](https://cses.fi/book/book.pdf)

Practice:

- [Codeforces 706D - Vasiliy's Multiset](https://codeforces.com/problemset/problem/706/D)
- [CSES - Maximum Xor Subarray](https://cses.fi/problemset/task/1655)
- [SPOJ - SUBXOR](https://www.spoj.com/problems/SUBXOR/)

Repo anchors:

- practice ladder: [Binary Trie / XOR Queries ladder](../../../practice/ladders/data-structures/binary-trie-xor/README.md)
- practice note: [Vasiliy's Multiset](../../../practice/ladders/data-structures/binary-trie-xor/vasiliysmultiset.md)
- starter template: [binary-trie-xor.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/binary-trie-xor.cpp)
- notebook refresher: [Binary Trie hot sheet](../../../notebook/binary-trie-hot-sheet.md)
- compare point: [Trie](../../strings/trie/README.md)
