# String Hashing

String hashing is the contest-friendly way to turn substring comparison into arithmetic.

It is the right tool when you want:

- many arbitrary substring equality checks
- binary search on the first mismatch or longest common prefix
- a lightweight alternative to heavier exact structures

Among the standard string tools:

- [KMP](../kmp/README.md) and [Z-Function](../z-function/README.md) are exact and linear for narrower tasks
- [Suffix Array And LCP](../suffix-array-lcp/README.md) is exact and structural for static order questions
- string hashing is the flexible "fast fingerprint" layer for many substring comparisons

This page teaches the contest route that matters most:

1. model a string as a polynomial-like hash
2. precompute prefix hashes and powers
3. extract any substring hash in `O(1)`
4. keep the collision story honest

## At A Glance

Reach for string hashing when:

- the same string is queried many times
- arbitrary substring equality matters
- binary search on answer length needs a fast equality primitive
- exact linear tools exist, but the comparison pattern is more flexible than one-pattern matching

Strong contest triggers:

- "compare these two substrings many times"
- "longest common prefix of many suffix pairs"
- "binary search the longest repeated/common substring"
- "prefix equals suffix?" or "border equality" over many candidate lengths
- "palindrome queries" with forward + reverse preprocessing

Strong anti-cues:

- one exact pattern against one text: KMP or Z is cleaner
- the problem truly needs exact suffix order or adjacent LCP structure: suffix array is more natural
- the judge is strongly adversarial and the solution has no clean verification fallback
- the range of comparisons is tiny enough that direct character checks are already cheap

What success looks like after studying this page:

- you can derive the standard `get(l, r)` formula instead of memorizing it
- you know why substring extraction needs base powers
- you understand that equal hashes mean "probably equal," not "proved equal"
- you can choose between one-mod, double hash, and unsigned-64 overflow style
- you can decide when hashing is the right flexible tool and when an exact algorithm is better

## Prerequisites

- [Prefix Sums](../../foundations/patterns/prefix-sums/README.md)
- [Modular Arithmetic](../../math/modular-arithmetic/README.md)

Helpful neighboring topics:

- [KMP](../kmp/README.md)
- [Z-Function](../z-function/README.md)
- [Suffix Array And LCP](../suffix-array-lcp/README.md)

## Problem Model And Notation

Let:

- `s` be a string of length `n`
- `val(c)` be the numeric value assigned to character `c`
- `B` be a fixed base

The classic polynomial-style prefix hash is:

$$
H[i] = \sum_{t=0}^{i-1} val(s_t)\, B^t
$$

or, in the equivalent rolling-prefix style used by many contest templates:

$$
pref[i+1] = pref[i] \cdot B + val(s_i).
$$

The repo template uses the second form with unsigned 64-bit overflow:

- [rolling-hash.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/rolling-hash.cpp)

and stores:

- `pref[i]`: hash of `s[0..i)`
- `power[i] = B^i`

The core primitive is:

$$
get(l, r) = \text{hash of } s[l..r).
$$

Everything else in substring hashing is built on top of that one operation.

## From Brute Force To The Right Idea

### Brute Force

Suppose you need to compare many substrings:

```text
s[l1..r1) ?= s[l2..r2)
```

The naive method compares characters one by one:

- `O(length)` per query

That is too slow once substring comparison becomes the inner primitive of:

- many queries
- binary search on answer length
- or enumeration over many candidates

### The Prefix-Sum Analogy

Hashing is to strings what prefix sums are to arrays.

With prefix sums:

- range sum = difference of two prefix sums

With polynomial hashing:

- substring hash = difference of two prefix hashes, after accounting for the shifted powers

So the right mental model is not "random magic numbers." It is:

- precompute cumulative structure once
- subtract away the unwanted prefix carefully

### Why Base Powers Appear

If `pref[r]` contains contributions from:

$$
s_0, s_1, \dots, s_{r-1},
$$

then subtracting `pref[l]` alone is not enough, because the prefix part is sitting at the wrong power positions.

You must shift it to match the suffix-aligned contribution:

$$
pref[l] \cdot B^{r-l}.
$$

That is the entire reason power tables are part of the standard template.

One quiet but crucial boundary:

- raw hash equality is the intended primitive only for substrings of the **same length**

If the lengths differ, you are not asking a meaningful equality question about the same polynomial shape.

## Core Invariant And Why It Works

### 1. Prefix Hashes Store Weighted Prefixes

In the rolling-prefix formulation:

$$
pref[i+1] = pref[i] \cdot B + val(s_i),
$$

the value `pref[i]` is exactly the hash of the prefix `s[0..i)`.

So one more character extends the old polynomial by one base multiplication and one added coefficient.

### 2. Why `get(l, r)` Works

For the rolling-prefix convention, the substring extraction formula is:

$$
get(l, r) = pref[r] - pref[l] \cdot B^{r-l}.
$$

Why?

Because `pref[r]` contains:

- the prefix `s[0..l)` shifted up by `r-l` powers
- plus the exact contribution of `s[l..r)`

Subtracting:

$$
pref[l] \cdot B^{r-l}
$$

removes the first part and leaves exactly the substring fingerprint.

That is the whole correctness proof.

### 3. Equal Strings Imply Equal Hashes

If two substrings are characterwise equal, then they produce the same polynomial expression, so their hashes match.

So:

$$
\text{equal strings} \Rightarrow \text{equal hashes}.
$$

This direction is deterministic.

### 4. Equal Hashes Do **Not** Necessarily Imply Equal Strings

The reverse implication is only probabilistic:

$$
\text{equal hashes} \centernot\Rightarrow \text{proved equal strings}.
$$

Different strings can collide under the same fingerprint.

That is the central honesty rule of hashing:

- hashing is a very strong equality filter
- not an absolute proof, unless the problem or modulus setup gives a special guarantee

So the right mental model is:

- unequal hashes => definitely different
- equal hashes => extremely plausible match, but still a fingerprint event

### 5. Collision Management Is The Real Design Choice

Contest solutions usually control collision risk by using one of these routes:

- two independent modular hashes
- unsigned 64-bit overflow hash
- hash + direct verification when the candidate count is small enough

The repo starter uses unsigned `unsigned long long` overflow hashing because it is:

- simple
- fast
- and often strong enough for normal contest use

### 6. Monte Carlo Versus Las Vegas Mindset

If your algorithm trusts hash equality directly, it is typically Monte Carlo:

- very likely correct
- but not logically impossible to fail

If a hash match triggers a later exact character check, the final answer can become Las Vegas:

- maybe a few extra verifications
- but no false equality in the final result

That distinction matters most in pattern matching and binary-search-on-answer problems.

## Complexity And Tradeoffs

With one preprocessed string of length `n`:

- preprocess `pref` and `power`: `O(n)`
- one substring hash query: `O(1)`
- one LCP query via binary search + hashing: `O(log n)`

Practical tradeoffs:

| Tool | Best when | Time | Main tradeoff |
| --- | --- | --- | --- |
| string hashing | many arbitrary substring comparisons | `O(1)` per hash query after preprocess | probabilistic |
| KMP / Z | one exact matching / border-style task | linear and exact | much narrower |
| suffix array + LCP | static structural string queries | exact, preprocess-heavy | heavier to build and explain |
| direct character comparison | few or tiny queries | simplest possible | too slow when nested inside many checks |

Rule of thumb:

- if the primitive is "compare two substrings quickly," hashing is a natural fit
- if the primitive is "solve one exact string problem end to end," an exact linear algorithm may be cleaner

A practical chooser many contestants use is:

- `u64` overflow hash for speed and minimal code
- double hash when the task or judge feels collision-sensitive
- hash + direct verification when the candidate set is already small after filtering

## Variant Chooser

| Variant | Use it when | Main idea | Main pitfall |
| --- | --- | --- | --- |
| one modular hash | constraints are moderate and collision risk is acceptable | one prefix table, one modulus | treating collisions as impossible |
| double hash | correctness confidence should be much stronger | two independent fingerprints | bookkeeping gets noisier |
| unsigned 64-bit overflow hash | speed and simplicity matter most | arithmetic modulo `2^64` by overflow | still probabilistic, no theorem of exactness |
| forward + reverse hashes | palindrome / mirror checks | preprocess both directions | index mapping mistakes |
| hash + binary search | longest equal prefix / longest repeated length | use hashes as equality oracle | off-by-one in search bounds |

## Worked Examples

### Example 1: Deriving `get(l, r)`

Suppose:

```text
s = abcd
```

and use the rolling-prefix recurrence:

$$
pref[i+1] = pref[i] \cdot B + val(s_i).
$$

Then:

$$
pref[4] = (((val(a)\cdot B + val(b))\cdot B + val(c))\cdot B + val(d)).
$$

The substring `s[1..3)` is `"bc"`.

To isolate it, remove the contribution of `"a"` shifted by two places:

$$
get(1, 3) = pref[3] - pref[1] \cdot B^2.
$$

That leaves exactly the polynomial for `"bc"`.

Once this identity feels natural, the whole hashing template becomes much easier to trust.

Notice that this extracted value is tied to length `2`. So it should be compared directly only with another substring hash of length `2`.

### Example 2: Borders By Prefix/Suffix Equality

In [Finding Borders](../../../practice/ladders/strings/hashing/findingborders.md), for every candidate border length `len`, we check:

$$
s[0..len) \stackrel{?}{=} s[n-len..n).
$$

Hashing turns that into:

$$
get(0, len) \stackrel{?}{=} get(n-len, n).
$$

So the whole problem reduces to:

- preprocess once
- compare many prefix/suffix pairs in `O(1)`

This is the cleanest first hashing problem in the repo.

And because both compared pieces have the same candidate length `len`, the raw hash equality check is the right primitive here.

### Example 3: Longest Common Prefix By Binary Search

Suppose we want:

$$
\mathrm{LCP}(i, j)
$$

between suffixes starting at `i` and `j`.

Binary search the largest `len` such that:

$$
get(i, i+len) = get(j, j+len).
$$

This is the classic "hash + binary search" pattern:

- hashing gives the equality test
- binary search turns it into a maximal length query

This is one of the main reasons hashing stays so useful even when exact tools like suffix arrays exist.

### Example 4: Palindrome Query With Forward + Reverse Hash

To test whether:

$$
s[l..r)
$$

is a palindrome:

1. compare its forward hash
2. compare the corresponding reversed interval hash

The important part is not the formula itself, but the idea that reverse preprocessing gives another `get(l, r)` oracle over the mirrored string.

So palindrome checks become "compare the substring against its reverse" in `O(1)`.

## Algorithm And Pseudocode

The repo starter implementation is:

- [rolling-hash.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/rolling-hash.cpp)

### Build Prefix Hashes

```text
build_hash(s):
    pref[0] = 0
    power[0] = 1

    for i from 0 to n - 1:
        pref[i + 1] = pref[i] * BASE + value(s[i])
        power[i + 1] = power[i] * BASE
```

### Extract Substring Hash

```text
get(l, r):
    return pref[r] - pref[l] * power[r - l]
```

### Binary Search LCP

```text
lcp(i, j):
    low = 0
    high = n - max(i, j)

    while low < high:
        mid = (low + high + 1) / 2
        if get(i, i + mid) == get(j, j + mid):
            low = mid
        else:
            high = mid - 1

    return low
```

## Implementation Notes

### 1. Keep Endpoints Half-Open

Use one interval convention everywhere:

```text
[l, r)
```

This makes:

- substring length = `r - l`
- prefix hash arrays cleaner
- binary search bounds less error-prone

### 2. The Repo Template Uses Unsigned 64-Bit Overflow

The current repo starter chooses:

- one fixed 64-bit base
- natural overflow modulo `2^64`

This is a very common contest choice because it is tiny and fast.

But it is still a fingerprinting scheme, not an exact proof system.

### 3. Base Choice Is Part Of The Collision Story

A bad or predictable base can make collisions easier to engineer.

Typical contest routes:

- fixed strong-looking base for convenience
- randomized base at runtime for harder adversarial attacks
- double hashing if the problem is especially collision-sensitive

### 4. Normalize Only In The Right Model

With the repo's rolling-prefix formula, `get(l, r)` already returns a normalized substring fingerprint for that exact interval length.

So equal-length substring comparison is direct:

$$
get(l_1, r_1) = get(l_2, r_2).
$$

Do not add extra modular inverses or shifting unless your hash convention actually requires them.

### 5. Hashing Is A Filter, Not A License To Forget Exact Algorithms

If the problem is really:

- exact one-pattern matching
- exact border computation
- exact prefix structure

then KMP or Z may be the cleaner endorsed tool.

Hashing wins when flexibility matters more than determinism.

### 6. Adversarial Judges Change The Recommendation

If a problem is notorious for anti-hash tests, strengthen your policy:

- double hash
- randomize base
- or add exact verification at the final candidate stage

The tool itself does not change. The collision-management discipline does.

### 7. Hashing Versus Suffix Array

This is the most useful high-level judgment:

- hashing is lighter and easier when you only need a fast substring equality primitive
- suffix array is stronger and exact when you need global order or LCP structure

If the problem can be solved by:

- "compare substrings many times"

then hashing is often the fastest path to code.

If the problem is about:

- "what is the sorted structure of all suffixes?"

then hashing is usually a helper, not the main structure.

## Practice Archetypes

The most common hashing-flavored tasks are:

- **prefix / suffix equality**
- **border checks**
- **substring equality queries**
- **binary search on longest equal length**
- **palindrome queries with forward + reverse hashes**

The strongest contest smell is:

- many equality checks
- flexible substring positions
- exact linear algorithms exist, but the problem shape wants a reusable comparison oracle

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Primary / background:

- [Karp and Rabin: Efficient Randomized Pattern-Matching Algorithms (bibliographic pointer)](https://cir.nii.ac.jp/crid/1361137044594504832)

Course:

- [Princeton COS226: Substring Search / Rabin-Karp lecture slides](https://www.cs.princeton.edu/courses/archive/spring12/cos226/lectures/53SubstringSearch.pdf)
- [CMU 15-451: Karp-Rabin lecture notes](https://www.cs.cmu.edu/afs/cs/academic/class/15451-f14/www/lectures/lec6/karp-rabin-09-15-14.pdf)

Reference:

- [CP-Algorithms: String Hashing](https://cp-algorithms.com/string/string-hashing.html)
- [USACO Guide: Hashing](https://usaco.guide/gold/hashing)

Practice:

- [CSES Problem Set](https://cses.fi/problemset/)

Repo anchors:

- practice ladder: [Hashing ladder](../../../practice/ladders/strings/hashing/README.md)
- practice note: [Finding Borders](../../../practice/ladders/strings/hashing/findingborders.md)
- starter template: [rolling-hash.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/rolling-hash.cpp)
- notebook refresher: [String cheatsheet](../../../notebook/string-cheatsheet.md)

## Related Topics

- [KMP](../kmp/README.md)
- [Z-Function](../z-function/README.md)
- [Suffix Array And LCP](../suffix-array-lcp/README.md)
- [Suffix Automaton](../suffix-automaton/README.md)
