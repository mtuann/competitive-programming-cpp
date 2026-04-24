# Finding Borders

- Title: `Finding Borders`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1732](https://cses.fi/problemset/task/1732)
- Secondary topics: `Prefix-suffix equality`, `Proper borders`, `Collision awareness`
- Difficulty: `easy`
- Subtype: `List every proper border of one string`
- Status: `solved`
- Solution file: [findingborders.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/hashing/findingborders.cpp)

## Why Practice This

This is a clean first hashing exercise because the whole problem reduces to one primitive:

- compare one prefix against one suffix quickly

There is no DP or automaton wrapped around it. If your `get(l, r)` function is correct, the rest is just looping over candidate border lengths.

## Recognition Cue

Reach for this hashing pattern when:

- you need to compare many prefix/suffix or substring pairs quickly
- equality checks dominate the task
- the whole problem becomes easy once `get(l, r)` is trustworthy

The strongest smell is:

- "for every length `len`, is the prefix of length `len` equal to the suffix of length `len`?"

That is a textbook fit for prefix hashes.

## Problem-Specific Transformation

The border story collapses to one substring-equality loop:

- prefix = `s[0..len)`
- suffix = `s[n-len..n)`

So the reusable rewrite is:

- preprocess rolling hashes once
- compare these two substrings for every candidate `len`

That turns the problem from string-structure language into a clean equality-filtering task.

## Core Idea

A border is a **proper** prefix that is also a suffix.

So for every `len` from `1` to `n - 1`, we only need to check whether:

```text
s[0..len) == s[n-len..n)
```

Rolling hash turns that comparison into `O(1)` after preprocessing.

Precompute:

```text
pref[i] = hash of s[0..i)
pow[i] = BASE^i
```

Then extract any substring hash with:

```text
get(l, r) = pref[r] - pref[l] * pow[r - l]
```

Now every candidate border length becomes one constant-time comparison:

```text
get(0, len) == get(n - len, n)
```

If true, print `len`.

This is not the only way to solve the task. Prefix-function or Z-function gives an exact linear solution too. This note is valuable because it drills the hashing workflow directly:

- build prefix hashes
- normalize substring fingerprints
- compare many substring pairs cheaply

## Complexity

- preprocessing hashes and powers: `O(n)`
- checking all border lengths: `O(n)`
- total: `O(n)`

## Pitfalls / Judge Notes

- Borders are proper, so do **not** print `n`.
- Keep substring endpoints half-open: `[l, r)`.
- Equal hashes are a strong fingerprint, not a proof. In contest practice, a robust 64-bit rolling hash is usually accepted here.
- This problem is simple enough that off-by-one mistakes matter more than asymptotic mistakes.

## Reusable Pattern

- Topic page: [Hashing](../../../../topics/strings/hashing/README.md)
- Practice ladder: [Hashing ladder](README.md)
- Starter template: [rolling-hash.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/rolling-hash.cpp)
- Notebook refresher: [String cheatsheet](../../../../notebook/string-cheatsheet.md)
- Carry forward: treat hashing as a fast equality filter, then be explicit about what substring comparison is being asked.
- This note adds: the exact prefix / suffix / substring relation checked in this note.

## Solutions

- Code: [findingborders.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/hashing/findingborders.cpp)
