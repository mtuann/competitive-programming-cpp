# Binary Trie / XOR Queries Hot Sheet

Use this sheet when one evolving multiset of non-negative integers is queried by **best xor partner**, not by sorting, prefix sums, or subset-xor algebra.

## Do Not Use When

- the task wants xor against any subset instead of one stored element
- there is no dynamic set of integers at all, only strings -> [Trie](../topics/strings/trie/README.md)
- the statement really wants a counting inequality like `xor < K` and you have not reopened the full topic
- a simpler static trick already removes the need for dynamic insert / erase / query

## Choose By Signal

- insert / erase-one / maximum xor query over integers -> `binary trie`
- prefix xors are inserted one by one, each new prefix asks for best xor partner -> `binary trie`
- string prefixes or dictionary lookup dominate -> [String cheatsheet](string-cheatsheet.md)
- one current range with endpoint moves is the whole state -> [Mo's hot sheet](mos-hot-sheet.md)

## Core Invariants

- every node is one binary prefix under one fixed bit width
- `cnt` says how many live values still pass through that prefix
- maximum xor walks high bit to low bit, preferring the opposite bit when the preferred branch is alive
- `erase_one(x)` must remove exactly one occurrence, not all duplicates

## Main Traps

- mixing bit widths between inserts and queries
- forgetting to seed `0` when the empty prefix or guaranteed non-empty multiset matters
- querying an empty trie
- trying to physically delete nodes instead of trusting counts

## Exact Starter Route

- exact starter -> [binary-trie-xor.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/binary-trie-xor.cpp)
- flagship in-lane rep -> [Vasiliy's Multiset](../practice/ladders/data-structures/binary-trie-xor/vasiliysmultiset.md)
- compare points -> [Trie](../topics/strings/trie/README.md), [XOR Basis / Linear Basis](../topics/math/xor-basis/README.md), [Data structures cheatsheet](data-structures-cheatsheet.md)

## Reopen Paths

- full topic page -> [Binary Trie / XOR Queries](../topics/data-structures/binary-trie-xor/README.md)
- structural ancestor -> [Trie](../topics/strings/trie/README.md)
- reusable snippet map -> [Template Library](../template-library.md)
- retrieval router -> [Build Kit](../docs/build-kit.md)
