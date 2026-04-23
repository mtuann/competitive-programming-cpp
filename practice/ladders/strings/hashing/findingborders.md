# Finding Borders

- Title: `Finding Borders`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1732](https://cses.fi/problemset/task/1732)
- Main topic: `Strings -> Hashing`
- Secondary topics: `Prefix-suffix equality`, `Proper borders`, `Collision awareness`
- Difficulty: `easy`
- Subtype: `List every proper border of one string`
- Status: `solved`
- Solution file: [findingborders.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/hashing/findingborders.cpp)

## Why Practice This

This is a clean first hashing exercise because the whole problem reduces to one primitive:

- compare one prefix against one suffix quickly

There is no DP or automaton wrapped around it. If your `get(l, r)` function is correct, the rest is just looping over candidate border lengths.

## Key Idea

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

## Solutions

- Code: [findingborders.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/hashing/findingborders.cpp)
