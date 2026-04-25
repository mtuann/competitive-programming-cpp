# Distinct Palindromic Substrings

- Title: `Distinct Palindromic Substrings`
- Judge / source: `Timus`
- Original URL: [https://acm.timus.ru/problem.aspx?num=1960&space=1](https://acm.timus.ru/problem.aspx?num=1960&space=1)
- Secondary topics: `Eertree`, `Distinct palindromes`, `Append-only string`
- Difficulty: `medium`
- Subtype: `After each appended character, report how many distinct palindromic substrings the current prefix contains`
- Status: `solved`
- Solution file: [distinctpalindromicsubstrings.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/eertree/distinctpalindromicsubstrings.cpp)

## Why Practice This

This is the cleanest first exact benchmark for the `Eertree` lane.

The statement says almost everything we need:

- one string grows left to right
- after each append, report the number of **different** palindromic substrings of the current prefix

So the real lesson is not longest-palindrome extraction.

It is:

- new palindromes must end at the new last position
- one append creates at most one new distinct palindrome
- the answer after each step is just the number of ordinary Eertree nodes so far

## Recognition Cue

Reach for `Eertree` when:

- the string grows one character at a time
- the task wants **distinct** palindromes, not just one longest palindrome
- per-prefix answers matter
- brute force would keep re-enumerating palindromic suffixes and deduplicating them

The strongest smell here is:

- "after each appended character, how many different palindromic substrings exist now?"

That is the textbook first `Eertree` problem.

## Problem-Specific Transformation

Maintain one Eertree over the current prefix.

For each appended character:

1. walk suffix links from `last` until extension is possible
2. if the transition already exists, just move `last`
3. otherwise create exactly one new node
4. output:

```text
current ordinary node count = tree.size() - 2
```

So the statement becomes:

- maintain the distinct-palindrome dictionary online
- exploit the fact that each append creates at most one new node
- report the ordinary node count after each step

## Core Idea

The live pointer `last` always stores:

- the longest palindromic suffix of the processed prefix

That is the right update frontier because every new palindrome must end at the current last character.

The suffix-link chain of `last` lists candidate suffix palindromes in decreasing length order.

So each append does:

- fallback by suffix links until the new character can wrap one candidate palindrome
- reuse an existing transition if that wrapped palindrome was already known
- otherwise create one new node for the unique new longest palindromic suffix

Then the per-prefix answer is immediate:

- ordinary nodes correspond one-to-one with distinct nonempty palindromes

## Complexity

For a string of length `n`:

- total build: `O(n)`
- total nodes: `O(n)`
- output: `O(n)`

This fits comfortably for `n <= 10^5`.

## Pitfalls / Judge Notes

- The answer is about **different** palindromes, not total palindrome occurrences.
- Do not confuse `last` with "the newest node"; if the transition already exists, no new node is created.
- Keep both roots: odd root `-1` and even root `0`.
- The alphabet is lowercase English letters, so the exact starter route can use a fixed `26`-way transition table safely.

## Reusable Pattern

- Topic page: [Eertree / Palindromic Tree](../../../../topics/strings/eertree/README.md)
- Practice ladder: [Eertree / Palindromic Tree ladder](README.md)
- Starter template: [eertree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/eertree.cpp)
- Notebook refresher: [Eertree hot sheet](../../../../notebook/eertree-hot-sheet.md)
- Compare points:
  - [Palindromes / Manacher](../../../../topics/strings/palindromes/README.md)
  - [Suffix Automaton](../../../../topics/strings/suffix-automaton/README.md)
- Carry forward: when one growing string needs the dictionary of distinct palindromes, turn every append into a suffix-link walk plus at most one node creation.
- This note adds: the per-prefix counting viewpoint where `tree.size() - 2` is already the whole answer.

## Solutions

- Code: [distinctpalindromicsubstrings.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/eertree/distinctpalindromicsubstrings.cpp)
