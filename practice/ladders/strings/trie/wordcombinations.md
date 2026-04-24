# Word Combinations

- Title: `Word Combinations`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1731](https://cses.fi/problemset/task/1731)
- Main topic: `Strings -> Trie`
- Secondary topics: `DP on suffixes`, `Dictionary segmentation`, `Duplicate words`
- Difficulty: `medium`
- Subtype: `Count how many dictionary segmentations form the target string`
- Status: `solved`
- Solution file: [wordcombinations.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/trie/wordcombinations.cpp)

## Why Practice This

This is a strong trie problem because the trie is not the whole answer by itself. The real structure is:

- DP decides what state to count
- the trie makes each DP transition cheap enough to enumerate

That split is exactly why this problem is worth learning.

## Key Idea

Let `dp[i]` be the number of ways to split the suffix `s[i..n-1]` into dictionary words.

Then:

- `dp[n] = 1` because the empty suffix has one valid completion
- for each position `i`, we try every dictionary word that starts at `i`

Naively, that means checking all words against `s[i..]`, which is too wasteful.

Instead, insert all dictionary words into a trie. Then for a fixed start `i`, walk forward through the text:

```text
s[i], s[i + 1], s[i + 2], ...
```

and move through the trie at the same time.

Whenever the current trie node is terminal, we found one dictionary word ending at `j`, so it contributes:

```text
dp[j + 1]
```

to `dp[i]`.

If the next text character has no trie edge, we stop immediately. So each DP state only explores prefixes that are actually present in the dictionary.

The solution computes `dp` from right to left so every `dp[j + 1]` is already known when needed.

## Complexity

- building the trie: `O(total dictionary length)`
- DP transitions: `O(total successful trie walks from all start positions)`
- worst-case bound: `O(n * longest_word_length + total dictionary length)`

This is fast enough for the intended constraints when implemented iteratively.

## Pitfalls / Judge Notes

- The answer is modulo `10^9 + 7`.
- A trie node should track terminal multiplicity, not just a boolean, if duplicate words are allowed in the input.
- Compute `dp` from right to left so transitions point to already-computed states.
- Stop the forward scan immediately when the trie has no next edge for the current character.

## Reusable Pattern

- Topic page: [Trie](../../../../topics/strings/trie/README.md)
- Practice ladder: [Trie ladder](README.md)
- Starter template: [trie-basic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/trie-basic.cpp)
- Notebook refresher: [String cheatsheet](../../../../notebook/string-cheatsheet.md)
- Carry forward: use the trie only for the shared-prefix part; keep the extra DP or query logic separate.
- This note adds: the state transition or counting rule built on top of the trie.

## Solutions

- Code: [wordcombinations.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/trie/wordcombinations.cpp)
