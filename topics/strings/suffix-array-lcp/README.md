# Suffix Array And LCP

Suffix array is the contest-friendly exact structure for:

- suffix order
- lexicographic substring logic
- repeated-substring reasoning
- and many "one static string, many structural questions" problems

It is heavier than [String Hashing](../hashing/README.md), but much lighter conceptually than a suffix tree and often easier to explain and debug than [Suffix Automaton](../suffix-automaton/README.md) for static-string tasks.

This page teaches the classic contest route:

1. build suffix array by **doubling**
2. build LCP by **Kasai**
3. reuse `sa`, `rank`, and `lcp` for common exact-string tasks

## At A Glance

Reach for suffix array when:

- suffixes need to be sorted exactly
- repeated-substring structure matters
- lexicographic order of suffixes or substrings is the main object
- the string is static and preprocessing-heavy queries are acceptable

Strong contest triggers:

- "longest repeated substring"
- "number of distinct substrings"
- "sort suffixes or rank suffixes"
- "exact substring comparisons after preprocessing"
- "one static string with many lexicographic or LCP-style queries"

Strong anti-cues:

- you only need one narrow exact-matching task: [KMP](../kmp/README.md) or [Z-Function](../z-function/README.md) may be cleaner
- substring equality alone is enough and probabilistic methods are acceptable: hashing may be simpler
- the task is online / dynamic over the string
- suffix order is overkill for the actual question

What success looks like after studying this page:

- you can explain what `sa`, `rank`, and `lcp` each mean
- you understand why doubling by equivalence classes works
- you know why many explanations append a sentinel, and why this repo template instead uses virtual `-1` ranks for the missing second half
- you can explain Kasai's `k--` reuse intuition
- you can derive distinct-substring and longest-repeated-substring formulas from `lcp`

## Prerequisites

- [String Hashing](../hashing/README.md)
- [Sorting](../../foundations/patterns/sorting/README.md)

Helpful neighboring topics:

- [Suffix Automaton](../suffix-automaton/README.md)
- [KMP](../kmp/README.md)
- [Z-Function](../z-function/README.md)

## Problem Model And Notation

Let `s` be a string of length `n`.

The suffix starting at position `i` is:

$$
s[i..n-1].
$$

The **suffix array** `sa` is the list of starting indices of all suffixes in lexicographic order.

So:

$$
sa[k] = \text{the starting position of the } k\text{-th smallest suffix.}
$$

The inverse array is usually called `rank`:

$$
rank[i] = \text{the position of suffix } s[i..] \text{ inside } sa.
$$

The **LCP array** stores longest common prefixes of adjacent suffixes in suffix-array order:

$$
lcp[k] = \text{LCP}(s[sa[k]..], s[sa[k+1]..]).
$$

This array has length `n - 1` if no sentinel row is kept in the final structure.

## From Brute Force To The Right Idea

### Brute Force

The naive way to build a suffix array is:

1. generate all suffix strings
2. sort them directly

Sorting needs `O(n log n)` comparisons, but each comparison may take `O(n)` time, so the total can reach:

$$
O(n^2 \log n).
$$

This is too slow at contest sizes.

### The Structural Observation

We do not need to compare whole suffixes from scratch at every sort step.

Instead, we can sort suffixes by:

- first `1` character
- then first `2` characters
- then first `4` characters
- then first `8` characters
- and so on

This gives the doubling approach.

### Why Equivalence Classes Are The Right Summary

Suppose we already know the equivalence class of every suffix by its first `2^k` characters.

Then to compare suffixes by their first `2^{k+1}` characters, it is enough to compare the pair:

$$
(c_k[i],\ c_k[i + 2^k]),
$$

where `c_k[i]` is the class of the first half and `c_k[i + 2^k]` is the class of the second half.

So a longer comparison is reduced to a pair of shorter comparisons already summarized by class ids.

That is the entire reason the doubling algorithm works.

### Why A Sentinel Helps

The cleanest contest implementation appends a sentinel character:

- smaller than every real character
- occurring only once at the end

This does two things:

- every suffix becomes comparable without running off the end
- sorting cyclic shifts of `s + '$'` becomes equivalent to sorting suffixes of `s`

That is why many textbook and CP-Algorithms explanations start with an explicit sentinel.

The repo starter template takes a slightly different but equivalent route: it does **not** append a sentinel to the stored string, and instead treats the missing second half rank as `-1` during doubling. The teaching picture is still the same:

- a shorter suffix should compare smaller once one side runs out of characters
- you need one consistent rule for "nothing is here anymore"

So the sentinel model is the cleanest way to think, while the virtual-`-1` model is the concrete policy used in this repo snippet.

## Core Invariant And Why It Works

### Doubling Invariant

After iteration `k`, we maintain:

- `sa`: suffixes sorted by their first `2^k` characters
- `c_k[i]`: the equivalence class of suffix `i` under comparison of the first `2^k` characters

This means:

$$
c_k[i] = c_k[j]
$$

if and only if the length-`2^k` prefixes of suffixes `i` and `j` are equal.

So `c_k[i]` is not "some helper label". It is exactly the rank of suffix `i` under the truncated key of length `2^k`.

### Why The Next Iteration Uses Rank Pairs

To compare suffixes `i` and `j` by `2^{k+1}` characters, split each prefix into two halves of length `2^k`.

Then:

$$
s[i..i+2^{k+1}-1]
$$

is determined by:

$$
(c_k[i],\ c_k[i+2^k]).
$$

So sorting suffixes by those rank pairs gives the correct order for the next doubling level. In other words:

- `c_k[i]` summarizes the first half
- `c_k[i + 2^k]` summarizes the second half
- the ordered pair is a complete signature for the first `2^{k+1}` characters

This is the real induction step:

1. assume `c_k` correctly ranks length-`2^k` prefixes
2. sort by pairs of those ranks
3. compress equal pairs into new classes `c_{k+1}`

That is the induction step of the construction.

### When Doubling Stops

Once:

$$
2^k \ge n,
$$

the compared prefix length already covers every suffix completely, so the suffix order is final.

At that point all suffixes have unique relative positions.

### Kasai's Invariant

After building `sa`, we want `lcp`.

Kasai uses the inverse array `rank`, and scans suffixes in original index order.

Suppose the current suffix `s[i..]` has LCP length `k` with its next suffix in suffix-array order.

If we delete the first character from both matched suffixes, we immediately get a common prefix of length `k - 1` between `s[i+1..]` and the shifted comparison partner. The actual neighbor of `s[i+1..]` in suffix-array order might be different, but it cannot force the best possible LCP below that already-known `k - 1` floor before we start extending again.

So when we move from suffix `i` to suffix `i+1`, the reusable part of the previous answer can only drop by `1`.

That is the reason for the standard reuse line:

```text
if k > 0: k--
```

before extending again.

### Why Kasai Is Linear

Every successful character comparison increases `k`.

Across the whole algorithm:

- `k` can only increase up to `n`
- and it decreases by at most `1` per outer iteration

So the total number of comparisons is `O(n)`.

This is the LCP analogue of the usual amortized trick in linear string algorithms:

- reuse most of the previous work
- only pay for frontier expansion

## Complexity And Tradeoffs

For the classic doubling route:

- suffix array: `O(n \log n)`
- Kasai LCP: `O(n)`
- memory: usually `O(n)` to `O(n \log n)` depending on whether intermediate class tables are stored

Practical tradeoffs:

| Tool | Best when | Time | Main tradeoff |
| --- | --- | --- | --- |
| suffix array + LCP | exact static-string order / repeated structure | preprocess `O(n \log n)` | heavier than hashing for narrow tasks |
| string hashing | equality / quick comparisons with acceptable collision risk | light and practical | probabilistic unless carefully hardened |
| suffix automaton | substring-state counting / endpos-style reasoning | powerful and linear | more abstract and harder to debug for many learners |
| KMP / Z | narrow exact-match or prefix-structure tasks | linear and simpler | too specialized for full suffix ordering |

Rule of thumb:

- if the task is about suffix order or repeated-substring structure, suffix array is a strong exact static-string choice
- if you only need one small exact-matching primitive, it is often overkill

## Variant Chooser

| Variant | Use it when | Main idea | Main pitfall |
| --- | --- | --- | --- |
| doubling suffix array | standard contest baseline | ranks of length `1, 2, 4, 8, ...` | sentinel / pair-comparison mistakes |
| suffix array + Kasai | you also need adjacent LCP information | reuse `k - 1` when shifting suffix start | mixing `sa` with `rank` |
| suffix array + RMQ on `lcp` | many arbitrary suffix-LCP queries | RMQ over adjacent LCPs | forgetting that arbitrary suffix LCP becomes a range minimum |
| cyclic-shift variant | minimal rotation / cyclic order tasks | sort cyclic shifts | mixing true suffix order with cyclic order |

## Worked Examples

### Example 1: A Tiny Suffix Array

Take:

```text
s = banana
```

The suffixes are:

```text
0 banana
1 anana
2 nana
3 ana
4 na
5 a
```

Sorted:

```text
5 a
3 ana
1 anana
0 banana
4 na
2 nana
```

So:

$$
sa = [5, 3, 1, 0, 4, 2].
$$

This single example is worth memorizing because it makes the meanings of `sa` and `rank` concrete immediately.

### Example 2: Distinct Substrings

Every suffix contributes all of its prefixes as candidate substrings.

Suffix `sa[i]` has:

$$
n - sa[i]
$$

prefixes in total.

But among those, exactly `lcp[i-1]` are duplicates of prefixes already seen from the previous suffix in sorted order.

So the number of new substrings contributed by suffix `sa[i]` is:

$$
(n - sa[i]) - lcp[i-1]
$$

with `lcp[-1]` treated as `0`.

Equivalently:

$$
\text{distinct substrings} = \frac{n(n+1)}{2} - \sum lcp[i].
$$

This is one of the cleanest suffix-array applications.

### Example 3: Longest Repeated Substring

If a substring appears at least twice, then there are at least two suffixes sharing it as a prefix.

In suffix-array order, all suffixes sharing a common prefix form a contiguous block.

So some adjacent pair in that block has at least that common-prefix length.

Therefore:

$$
\text{longest repeated substring length} = \max lcp[i].
$$

This is exactly the logic behind [Repeating Substring](../../../practice/ladders/strings/suffix-array-lcp/repeatingsubstring.md).

### Example 4: Arbitrary Suffix LCP From Adjacent LCP

Suppose suffixes `i` and `j` appear at positions `rank[i] < rank[j]` in the suffix array.

Then:

$$
\text{LCP}(i, j) = \min(lcp[rank[i]],\ lcp[rank[i]+1],\ \dots,\ lcp[rank[j]-1]).
$$

So arbitrary suffix-LCP queries reduce to RMQ on the `lcp` array.

This is one of the most important conceptual bridges:

- adjacent LCP information
- plus RMQ
- gives general suffix-LCP queries

## Algorithm And Pseudocode

The repo starter implementation is:

- [suffix-array.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/suffix-array.cpp)

### Doubling Construction

```text
build_suffix_array(s):
    append sentinel if needed
    initialize classes by first character

    for k = 0, 1, 2, ... while 2^k < n:
        sort suffixes by pair:
            (class[i], class[i + 2^k])
        rebuild new classes

    remove sentinel row if your final API wants suffixes of the original string only
    return sa
```

### Kasai LCP

```text
build_lcp(s, sa):
    rank[sa[i]] = i for all i
    k = 0

    for i from 0 to n - 1:
        if rank[i] is the last suffix:
            k = 0
            continue

        j = sa[rank[i] + 1]
        while s[i + k] == s[j + k]:
            k++
        lcp[rank[i]] = k
        if k > 0:
            k--
```

### Distinct Substrings

```text
answer = n * (n + 1) / 2
for each value x in lcp:
    answer -= x
```

### Longest Repeated Substring

```text
best = max(lcp)
take one suffix position where lcp is best
print that many characters from the corresponding suffix
```

## Implementation Notes

### 1. Decide Sentinel Policy Early

The cleanest doubling implementations append a sentinel like `$` that is smaller than all real characters.

Be consistent about:

- whether the sentinel suffix stays in the final `sa`
- whether `lcp` is computed on the original string or the sentinel-extended one

The repo starter template currently uses the other common policy:

- keep the original string unchanged
- and use second-half rank `-1` when `i + 2^k` goes out of range

Both conventions are fine. Many off-by-one bugs come from starting with one convention and mentally switching to the other halfway through.

### 2. `sa` And `rank` Are Inverses, Not Alternatives

Keep this mental picture:

- `sa[pos]` -> where is the suffix starting index at sorted position `pos`?
- `rank[i]` -> what is the sorted position of suffix `i`?

Confusing these two arrays is one of the most common implementation mistakes.

### 3. Doubling Stores Class Information, Not Literal Prefix Strings

At level `k`, do not think:

- "I stored the first `2^k` characters"

Think:

- "I stored a compact id for the equivalence class of the first `2^k` characters"

That is why the algorithm is efficient.

### 4. Kasai Uses Original Index Order For A Reason

Kasai scans suffixes by starting index, not by suffix-array order, because moving from `i` to `i+1` lets us reuse `k - 1`.

That reuse is the entire linear-time trick.

### 5. Suffix Array Is Exact But Heavy

Before reaching for it, ask:

- do I really need suffix order?
- or do I only need exact matching, borders, or equality checks?

If the narrower problem can be solved by:

- KMP
- Z-function
- hashing

then suffix array may be unnecessary overhead.

### 6. Suffix Array Versus Suffix Automaton

This is a useful judgment call:

- suffix array is excellent for static lexicographic order, repeated-substring structure, and LCP reasoning
- suffix automaton is excellent for substring-state counting, end-position structure, and state-DP style reasoning

If the task reads like "sort suffixes" or "use adjacent suffix common prefixes", suffix array is often the more natural tool.

## Practice Archetypes

The most common suffix-array-flavored tasks are:

- **distinct substrings**
- **longest repeated substring**
- **lexicographic suffix order**
- **arbitrary suffix-LCP with RMQ**
- **static string with many exact order queries**

The strongest contest smell is:

- one static string
- many questions about sorted suffix structure or repeated substrings

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Course:

- [USACO Guide: Suffix Array](https://usaco.guide/adv/suffix-array?lang=cpp)
- [Stanford CS166: Suffix and LCP Arrays](https://web.stanford.edu/class/archive/cs/cs166/cs166.1256/lectures/16/)

Reference:

- [CP-Algorithms: Suffix Array](https://cp-algorithms.com/string/suffix-array.html)

Primary reading pointers:

- [Manber and Myers: Suffix Arrays: A New Method for On-Line String Searches](https://web.stanford.edu/class/archive/cs/cs166/cs166.1256/readings/10.pdf)
- [Kasai et al.: Linear-Time Longest-Common-Prefix Computation in Suffix Arrays and Its Applications](https://web.stanford.edu/class/archive/cs/cs166/cs166.1256/readings/11.pdf)

Practice:

- [CSES Problem Set](https://cses.fi/problemset/)

Repo anchors:

- practice ladder: [Suffix Array And LCP ladder](../../../practice/ladders/strings/suffix-array-lcp/README.md)
- practice note: [Repeating Substring](../../../practice/ladders/strings/suffix-array-lcp/repeatingsubstring.md)
- starter template: [suffix-array.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/suffix-array.cpp)
- notebook refresher: [String cheatsheet](../../../notebook/string-cheatsheet.md)

## Related Topics

- [Suffix Automaton](../suffix-automaton/README.md)
- [String Hashing](../hashing/README.md)
- [KMP](../kmp/README.md)
- [Z-Function](../z-function/README.md)
