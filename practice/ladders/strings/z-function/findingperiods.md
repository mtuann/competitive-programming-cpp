# Finding Periods

- Title: `Finding Periods`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1733](https://cses.fi/problemset/task/1733)
- Main topic: `Strings -> Z-Function`
- Secondary topics: `String periodicity`, `Prefix alignment`, `Suffix covered by prefix`
- Difficulty: `easy`
- Subtype: `List every period length of one string`
- Status: `solved`
- Solution file: [findingperiods.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/z-function/findingperiods.cpp)

## Why Practice This

This is one of the cleanest Z-function applications in the whole topic.

The problem looks like it is about repeated blocks, but the real question is simpler:

- for each shift `p`, does the suffix `s[p..n)` match the prefix `s[0..n-p)`?

That is exactly what `z[p]` measures.

It is also a good trap to learn from: the last repetition may be partial, so this is **not** the usual "minimal period divides `n`" test.

## Key Idea

The statement says that a period is a prefix that can generate the whole string by repetition, and the **last repetition may be partial**.

So if we try a period length `p`, then:

- positions `0..p-1` are the prefix itself
- every later character should agree with the character `p` steps earlier
- equivalently, the whole suffix `s[p..n)` must equal the prefix `s[0..n-p)`

That condition is exactly:

```text
z[p] = n - p
```

because `z[p]` is the longest prefix match starting at position `p`.

So the algorithm is:

- build the Z array in `O(n)`
- for every `p` from `1` to `n - 1`, print `p` if `p + z[p] == n`
- always print `n`, because the whole string is always a period of itself

Example: `abcabca`

- `p = 3`: suffix `abca` matches prefix `abca`, so `3` is a valid period
- `p = 6`: suffix `a` matches prefix `a`, so `6` is also valid
- `p = 7`: always valid

That gives `3 6 7`.

## Complexity

- build Z array: `O(n)`
- scan all candidate lengths: `O(n)`
- total: `O(n)`

## Pitfalls / Judge Notes

- Do **not** require `n % p == 0`. That would solve a stricter problem than this one.
- `n` must be printed.
- Using the half-open Z-box `[l, r)` keeps the implementation cleaner.
- The input size goes up to `10^6`, so an `O(n^2)` character-by-character retry will time out.

## Reusable Pattern

- Topic page: [Z-Function](../../../../topics/strings/z-function/README.md)
- Practice ladder: [Z-Function ladder](README.md)
- Starter template: [z-function.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/z-function.cpp)
- Notebook refresher: [String cheatsheet](../../../../notebook/string-cheatsheet.md)
- Carry forward: if a problem asks whether a suffix is fully covered by the prefix, check whether `i + z[i] == n`.
- This note adds: the exact "period with partial last block" interpretation, which removes the divisibility requirement.

## Solutions

- Code: [findingperiods.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/z-function/findingperiods.cpp)
