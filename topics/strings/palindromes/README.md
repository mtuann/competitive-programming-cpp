# Palindromes / Manacher

This topic is about the first string tool that treats:

- **every center**
- **every maximal odd/even palindrome around that center**

as the main object.

That viewpoint is different from the existing string lanes in this repo:

- [KMP](../kmp/README.md) is about borders and exact one-pattern matching
- [Z-Function](../z-function/README.md) is about prefix matches starting at each index
- [String Hashing](../hashing/README.md) is about substring fingerprints and comparison
- `Manacher` is about **palindromic radii around centers**

For contest work, this matters because many palindrome tasks are really asking for one of:

- the longest palindromic substring
- all maximal odd/even radii
- a direct count or scan over palindromic centers

When the string is static, `Manacher` is the clean exact linear-time baseline.

## At A Glance

- **Use when:** the string is static, and the question is about longest palindromic substring or all palindrome radii around centers
- **Core worldview:** every palindrome has one center, so compute the maximal radius at every center once and reuse it
- **Main tools:** odd-radius array `d1`, even-radius array `d2`, current best palindrome interval `[l, r]`
- **Typical complexity:** `O(n)`
- **Main trap:** mixing up the meanings of `d1` and `d2`, or losing track of how radii map back to substring bounds

Strong contest signals:

- "longest palindromic substring"
- "for each center / position, how far can the palindrome extend?"
- "all palindromes" in one static string
- the brute force is `O(n^2)` by expanding around every center

Strong anti-cues:

- the string changes online, so static preprocessing is no longer enough
- the real task is many arbitrary substring-palindrome queries, where [String Hashing](../hashing/README.md) may be the better primitive
- the problem needs a full palindromic-substring dictionary or online insertion structure rather than one static scan

## Prerequisites

- [Strings overview](../README.md)

Helpful neighboring topics:

- [Z-Function](../z-function/README.md) as one useful compare point, because the reuse invariant feels similar
- [String Hashing](../hashing/README.md)
- [Suffix Array And LCP](../suffix-array-lcp/README.md) for longest repeated substring and other static-substring structure questions

## Problem Model And Notation

Let:

$$
s = s_0 s_1 \dots s_{n-1}
$$

be one static string.

We use two standard arrays:

- `d1[i]`: number of matching layers for the **odd** palindrome centered at `i`
- `d2[i]`: number of matching layers for the **even** palindrome centered between `i-1` and `i`

With the repo convention:

- odd palindrome length at center `i` is:

$$
2 \cdot d1[i] - 1
$$

- even palindrome length at split `i` is:

$$
2 \cdot d2[i]
$$

Examples:

- if `d1[i] = 1`, the palindrome is just `s[i]`
- if `d1[i] = 3`, the longest odd palindrome there has length `5`
- if `d2[i] = 2`, the longest even palindrome there has length `4`

This odd/even split is the cleanest contest form of Manacher.

## From Brute Force To The Right Idea

### Brute Force: Expand Around Every Center

The direct idea is:

- try every odd center
- try every even center
- expand outward while characters match

This is correct, but in the worst case:

```text
aaaaaa...aaaa
```

almost every center expands a long way, so the total work becomes:

$$
O(n^2)
$$

### The Structural Observation

Suppose we already know one palindrome interval:

$$
[l, r]
$$

that is currently the rightmost palindrome found so far.

Now consider a new center `i` inside that interval.

Its mirror center across the middle of `[l, r]` has already been processed.

So part of the palindrome information at `i` is **already known by symmetry**.

This is the same key mental move as in KMP and Z:

- do not rescan the part that one previous structure already certifies

### Why Odd And Even Need Separate Arrays

Odd palindromes have one character center.

Even palindromes have one split center.

Trying to force both into one contest interface usually creates more off-by-one bugs than it saves.

So the standard safe route is:

- one pass for odd centers
- one pass for even centers

Each pass has the same invariant shape.

### The Reuse Boundary

When center `i` lies inside the current rightmost palindrome `[l, r]`, the mirrored center tells us a **minimum guaranteed radius** at `i`.

But it may still extend farther beyond `r`, so after the mirrored bootstrap we still do an ordinary expansion loop.

That is the whole algorithm:

- reuse what symmetry certifies
- expand only beyond the known boundary

## Core Invariant And Why It Works

### 1. Maintain The Rightmost Known Palindrome

For each pass, keep one current interval:

$$
[l, r]
$$

meaning:

- this is the rightmost palindrome found so far in that parity pass

The exact parity-specific interpretation changes slightly, but the contest role is the same:

- anything strictly outside `[l, r]` is unknown
- anything inside can borrow information from its mirror

### 2. Mirror Reuse Inside The Interval

If center `i` lies inside the current interval, let `j` be its mirrored center.

Then the palindrome radius at `i` is at least:

- the mirrored radius at `j`
- clipped by the current right boundary

This clipped mirrored value becomes the starting radius.

That is the linear-time speedup:

- large parts of the scan do not restart from radius `0`

### 3. Expansion Only Beyond The Known Boundary

After copying the mirrored lower bound, try to extend farther:

- compare the next left character
- compare the next right character
- increase the radius while they match

If no extension is possible, the borrowed radius was already exact.

If extension works, then we discovered a strictly farther-reaching palindrome and can move `[l, r]` rightward.

### 4. Why The Total Work Is Linear

The important amortized fact is:

- the brute-force inner loop only does new comparison work when it pushes the right boundary farther

Every successful extension that passes the old boundary increases that right boundary.

Since the right boundary can move right only `O(n)` times, the total amount of "new" expansion work over the whole pass is linear.

So:

- odd pass is `O(n)`
- even pass is `O(n)`

and the whole algorithm is:

$$
O(n)
$$

### 5. Odd And Even Bounds

With the repo convention:

- odd palindrome centered at `i` with radius `d1[i]` occupies:

$$
[i - d1[i] + 1,\; i + d1[i] - 1]
$$

- even palindrome centered at split `i` with radius `d2[i]` occupies:

$$
[i - d2[i],\; i + d2[i] - 1]
$$

These formulas are the exact bridge from radii back to substring answers.

## Variant Chooser

### Use Manacher When

- the string is static
- you need longest palindromic substring or all center radii
- the answer naturally comes from odd/even center expansion

This is the main lane of this page.

### Use String Hashing When

- you need many arbitrary substring palindrome checks
- dynamic updates or many independent queries matter more than one full linear scan

Hashing plus reverse-string preprocessing is often the better compare point there.

### Use DP Only When n Is Small

The classic palindrome DP:

```text
is_pal[l][r]
```

is still valid, but it is usually only for:

- small constraints
- teaching
- or problems where DP state is already the real structure

For large static strings, `Manacher` is the exact linear-time primitive.

### Do Not Use This Lane When

- you need suffix-order / repetition structure, not palindromic structure
- the problem is really about one pattern against one text
- the statement needs an online palindromic structure beyond static radii

## Worked Examples

### Example 1: Longest Palindrome In `abacaba`

At center `i = 3` (`c`), the odd expansion reaches:

```text
abacaba
```

So:

$$
d1[3] = 4
$$

because the odd palindrome length is:

$$
2 \cdot 4 - 1 = 7.
$$

This is the cleanest mental model for `d1`:

- it is a radius count including the center layer

### Example 2: Even Palindrome In `abba`

The longest palindrome is even, centered between the two `b` characters.

If the split center is `i = 2`, then:

$$
d2[2] = 2
$$

and the palindrome length is:

$$
2 \cdot 2 = 4.
$$

So `d2` is not "half-length rounded somehow."

It is exactly the number of matched layers around that split.

### Example 3: Why The Mirror Only Gives A Lower Bound

Suppose current rightmost palindrome is:

```text
... x [ a b a b a ] y ...
```

and a center `i` lies inside it.

Its mirror center may certify that radius `k` is already safe.

But if the characters just outside the old right edge also match, the palindrome at `i` may extend farther than the mirrored one.

That is why the algorithm is:

- bootstrap from mirror
- then still expand

### Example 4: Longest Palindrome Output

In [Longest Palindrome](https://cses.fi/problemset/task/1111/), once all `d1` and `d2` values are known, the answer is just:

- the best odd interval from `d1`
- or the best even interval from `d2`

No heavier string structure is needed.

## Algorithm And Pseudocode

### Odd Pass

```text
l = 0, r = -1
for i in [0..n-1]:
    k = 1
    if i <= r:
        mirror = l + r - i
        k = min(d1[mirror], r - i + 1)
    while i - k >= 0 and i + k < n and s[i-k] == s[i+k]:
        k++
    d1[i] = k
    if i + k - 1 > r:
        l = i - k + 1
        r = i + k - 1
```

### Even Pass

```text
l = 0, r = -1
for i in [0..n-1]:
    k = 0
    if i <= r:
        mirror = l + r - i + 1
        k = min(d2[mirror], r - i + 1)
    while i - k - 1 >= 0 and i + k < n and s[i-k-1] == s[i+k]:
        k++
    d2[i] = k
    if i + k - 1 > r:
        l = i - k
        r = i + k - 1
```

### Recover Longest Palindromic Substring

```text
best_len = 1
best_l = 0

for each i:
    odd_len = 2 * d1[i] - 1
    update best with [i - d1[i] + 1, i + d1[i] - 1]

    even_len = 2 * d2[i]
    update best with [i - d2[i], i + d2[i] - 1]
```

Then print:

```text
s.substr(best_l, best_len)
```

## Implementation Notes

### 1. Keep Odd And Even Separate

Do not try to compress `d1` and `d2` into one contest interface unless you already trust a transformed-string formulation.

Two explicit arrays are easier to debug.

### 2. Be Explicit About Bounds

Write down the exact interval formula for:

- odd radius
- even radius

before extracting substrings.

Most wrong answers here are not complexity bugs. They are boundary bugs.

### 3. Static String Only

`Manacher` is a one-shot preprocessing tool on one immutable string.

If the statement has updates, reopen [String Hashing](../hashing/README.md) or a data-structure lane instead of forcing this primitive.

### 4. The Repo Starter Exposes Radii, Not Just One Longest Answer

That is deliberate.

The reusable primitive is:

- all odd radii
- all even radii

The longest palindrome is then just one thin consumer on top.

## Practice Archetypes

The most common problems in this lane are:

- **longest palindromic substring**
- **enumerate or summarize palindrome radii**
- **odd/even center scans**
- **palindrome-heavy static-string preprocessing**

Strong contest smells include:

- "expand around every center" is the obvious brute force
- the string is static
- exact palindrome structure matters more than general substring equality

## References

- [CP-Algorithms: Manacher's Algorithm - Finding all sub-palindromes in O(N)](https://cp-algorithms.com/string/manacher.html)
- [CSES: Longest Palindrome](https://cses.fi/problemset/task/1111/)
- [CSES: All Palindromes](https://cses.fi/problemset/task/3138)
- [Library Checker: Enumerate Palindromes](https://judge.yosupo.jp/problem/enumerate_palindromes)

## Repo Anchors

- [Palindromes ladder](../../../practice/ladders/strings/palindromes/README.md)
- [Palindromes hot sheet](../../../notebook/palindromes-hot-sheet.md)
- [Longest Palindrome note](../../../practice/ladders/strings/palindromes/longestpalindrome.md)
- [starter template](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/manacher.cpp)
- [String Hashing](../hashing/README.md)
- [Z-Function](../z-function/README.md)
