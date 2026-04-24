# Z-Function

The Z-function is the cleanest exact linear-time string tool when the problem is naturally about:

- the whole prefix of the string
- matched against every other position

That is its core viewpoint:

- not "what border survives here?" like [KMP](../kmp/README.md)
- but "how much of the prefix matches starting here?"

If KMP feels like a fallback-chain algorithm, Z-function feels like a **prefix-match landscape** over the string.

This page aims to make three things automatic:

1. understand what `z[i]` means without ambiguity
2. trust the `[l, r)` Z-box reuse invariant
3. see immediately when Z is the cleaner lens than KMP

## At A Glance

Reach for Z-function when:

- you want prefix-match length at every position
- the statement is about borders, periods, or repeated prefixes
- concatenation `pattern + '#' + text` feels natural
- the problem is exact, not probabilistic, and the prefix viewpoint is the cleanest one

Strong contest triggers:

- "how much does the prefix match starting at each position?"
- "find all exact matches of one pattern in one text"
- "find all borders of a string"
- "list all valid periods"
- "detect repeated structure by checking if a suffix is fully covered by the prefix"

Strong anti-cues:

- many patterns against one text: [Aho-Corasick](../aho-corasick/README.md) is the right machine
- substring equality queries dominate: [String Hashing](../hashing/README.md) or suffix structures may be more natural
- the problem is really about fallback states or automaton transitions: [KMP](../kmp/README.md) may read more directly

What success looks like after studying this page:

- you can define `z[i]` in one sentence
- you can explain why the Z-box `[l, r)` is reusable
- you know why the algorithm is linear
- you can solve pattern matching via concatenation without hesitation
- you know the difference between "period with full tiling" and "period where the last block may be partial"

## Prerequisites

- [KMP](../kmp/README.md) for the neighboring exact-matching viewpoint
- [String Hashing](../hashing/README.md) for the deterministic-versus-probabilistic tradeoff

Helpful neighboring topics:

- [Aho-Corasick](../aho-corasick/README.md)
- [Suffix Array And LCP](../suffix-array-lcp/README.md)

## Problem Model And Notation

For a string `s` of length `n`, define:

$$
z[i] = \max \{ \ell \mid s[0..\ell-1] = s[i..i+\ell-1] \}.
$$

In words:

- `z[i]` is the longest prefix length that matches starting at position `i`

By convention, contest implementations usually set:

$$
z[0] = 0,
$$

even though the whole string matches itself. This keeps the array focused on proper shifts.

The central invariant uses a half-open interval:

$$
[l, r)
$$

such that:

$$
s[l..r) = s[0..r-l).
$$

This interval is called the **Z-box**.

It means:

- the substring starting at `l` and ending just before `r`
- is already known to match the prefix of the same length

## From Brute Force To The Right Idea

### Brute Force

The definition suggests a direct `O(n^2)` algorithm:

For each `i`:

1. compare `s[0]` with `s[i]`
2. compare `s[1]` with `s[i+1]`
3. keep going until the first mismatch

This is too slow on repetitive strings such as:

```text
aaaaaaa...
```

because each shift rechecks a lot of the same prefix characters.

### The Structural Observation

Suppose we already know a segment:

$$
s[l..r) = s[0..r-l).
$$

Now consider some `i` with:

$$
l \le i < r.
$$

Then part of the match at `i` is already implied by the known Z-box.

Why?

Because position `i` inside the box corresponds to position:

$$
k = i - l
$$

inside the prefix.

So information about `z[k]` can often be reused.

That is the central optimization:

- reuse what is already certified inside the current Z-box
- only do fresh comparisons when trying to extend beyond `r`

### Why Prefix Reuse Is The Whole Algorithm

There are only two situations:

1. `i >= r`
   - no current Z-box covers `i`
   - we must compare from scratch
2. `i < r`
   - `i` lies inside the current Z-box
   - we inherit a guaranteed starting value from the mirrored prefix position

So the whole Z algorithm is:

- maintain the best known prefix-match window `[l, r)`
- seed from it when possible
- extend only beyond the frontier `r`

## Core Invariant And Why It Works

### The Z-Box Invariant

At every step, we maintain a segment `[l, r)` satisfying:

$$
s[l..r) = s[0..r-l).
$$

Usually we keep one of the rightmost such segments discovered so far.

This means:

- everything inside that box is already certified as matching the prefix
- fresh work is needed only when we try to go beyond `r`

In particular, for every `i` with `l <= i < r`, we automatically know the lower bound:

$$
z[i] \ge \min(r - i, z[i - l]).
$$

That lower bound is the whole reuse mechanism of the algorithm.

### Case 1: `i >= r`

If the current index `i` lies outside the Z-box, then there is no reusable match information at `i`.

So we start from:

$$
z[i] = 0
$$

and compare characters directly until the match stops.

If this new match reaches farther than the old box, we update `[l, r)`.

### Case 2: `i < r`

Now `i` lies inside the current Z-box.

Let:

$$
k = i - l.
$$

Position `k` in the prefix mirrors position `i` inside the box.

There are two subcases:

#### Subcase A: `z[k] < r - i`

Then the whole mirrored match fits strictly inside the current box.

So:

$$
z[i] = z[k].
$$

Why is this exact?

Because the Z-box already guarantees that those `z[k]` characters match, and the first mismatch that stopped `z[k]` inside the prefix also transfers to position `i` before we reach `r`.

#### Subcase B: `z[k] >= r - i`

Then the mirrored match reaches the right boundary of the current box.

So we may safely initialize:

$$
z[i] = r - i,
$$

but we do **not** know whether the match continues beyond `r`.

That is the only place where fresh comparisons are needed.

So the standard initialization is:

$$
z[i] = \min(r - i, z[i - l]).
$$

and then we try to extend further by direct comparison.

### Why The Algorithm Is Linear

The easiest amortized view is:

- every time the `while` loop succeeds, the right endpoint `r` increases
- `r` never decreases
- `r` can increase at most `n` times overall

So the total number of successful extension comparisons is `O(n)`.

What about failed comparisons?

There is at most one final failed comparison per position after the inherited seed is exhausted, so those also total `O(n)`.

Therefore the whole algorithm runs in:

$$
O(n).
$$

### Why Z And KMP Feel Different

This is worth making explicit.

Z-function answers:

$$
\text{"how much of the prefix matches starting at each position?"}
$$

KMP / prefix-function answers:

$$
\text{"what is the longest border ending at each position?"}
$$

Both are linear. The difference is the reuse mechanism:

- Z reuses a prefix-match window
- KMP reuses a border fallback chain

That is why some applications feel far cleaner with one than the other.

## Complexity And Tradeoffs

- build Z array: `O(n)`
- memory: `O(n)` for the output array

Practical tradeoffs:

| Tool | Best when | Time | Main tradeoff |
| --- | --- | --- | --- |
| Z-function | prefix-match viewpoint is natural | `O(n)` | less direct for border-chain automaton thinking |
| KMP / prefix function | fallback links, borders, automaton states | `O(n)` | less visually direct for "prefix against every shift" |
| String hashing | substring equality queries or many comparisons | often very practical | probabilistic unless collision safeguards are used |
| suffix structures | richer substring order/statistics questions | often stronger abstraction | more machinery than needed for simple prefix-match problems |

Rule of thumb:

- if the statement keeps talking about the prefix appearing at other positions, Z is often the cleanest exact answer
- if the statement keeps talking about borders that survive mismatches, KMP is often the cleaner exact answer

## Variant Chooser

| Variant | Use it when | Main trick | Main pitfall |
| --- | --- | --- | --- |
| raw Z array | you need prefix-match lengths directly | maintain `[l, r)` | wrong mirrored index or wrong half-open interval |
| pattern matching via concatenation | one pattern against one text | build `p + '#' + t` | forgetting a delimiter outside the alphabet |
| borders from Z | suffix fully covered by prefix | check `i + z[i] = n` | confusing borders with full periods |
| periods with partial last block | suffix must equal prefix remainder | check `i + z[i] = n` | incorrectly adding `n % i = 0` |
| periods with full tiling only | exact block repetition | require both `i + z[i] = n` and `n % i = 0` | forgetting the stricter divisibility condition |

## Worked Examples

### Example 1: A Small Z-Box Trace

Take:

```text
s = aabcaabxaaaz
```

We process left to right.

At `i = 1`:

- compare prefix with suffix starting at `1`
- only the first `a` matches
- so `z[1] = 1`
- current Z-box becomes `[1, 2)`

At `i = 4`:

```text
s[4..] = aabxaaaz
prefix = aabcaabxaaaz
```

The match length is `3`, so:

$$
z[4] = 3
$$

and now the Z-box becomes:

$$
[4, 7).
$$

At `i = 5`, we are inside the box.

Mirrored position:

$$
k = 5 - 4 = 1.
$$

Since `z[1] = 1` and `r - i = 2`, we may inherit:

$$
z[5] = \min(2, 1) = 1.
$$

No fresh extension is needed.

This is the whole reuse idea in miniature.

### Example 2: Pattern Matching By Concatenation

Suppose:

```text
pattern = aba
text    = cababac
```

Build:

```text
aba#cababac
```

Now compute the Z array of this combined string.

At every position inside the text part:

- if `z[i] >= |pattern|`
- then the whole pattern matches starting there

So Z turns one-pattern exact matching into a single prefix-match array computation.

This is one of the cleanest applications in all of string algorithms.

The reason this works is that the delimiter prevents matches from leaking across the pattern/text boundary, so a prefix match of length `|pattern|` inside the text part must be a real occurrence of the pattern.

### Example 3: Borders

If:

$$
i + z[i] = n,
$$

then the suffix starting at `i` matches the prefix all the way to the end.

So the string has a border of length:

$$
n - i.
$$

That gives a very clean Z-based border test:

- a suffix is a border exactly when it is fully covered by the prefix

This is one reason [String Functions](../../../practice/ladders/strings/z-function/stringfunctions.md) is such a good bridge problem: it lets you compare the Z-view of borders with the prefix-function view on the same input.

### Example 4: Periods With Partial Last Block

This is the idea used in [Finding Periods](../../../practice/ladders/strings/z-function/findingperiods.md).

If we test period length `p`, then the suffix `s[p..n)` must match the prefix `s[0..n-p)`.

That condition is:

$$
p + z[p] = n.
$$

This is enough when the last block may be partial.

It is **not** the same as full tiling.

If the problem instead demands full repetition by complete blocks, then we also need:

$$
n \bmod p = 0.
$$

This distinction is easy to miss and causes many wrong answers.

## Algorithm And Pseudocode

The repo starter implementation is:

- [z-function.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/z-function.cpp)

### Standard Construction

```text
z_function(s):
    n = len(s)
    z = array of n zeros
    l = 0
    r = 0

    for i from 1 to n - 1:
        if i < r:
            z[i] = min(r - i, z[i - l])

        while i + z[i] < n and s[z[i]] == s[i + z[i]]:
            z[i]++

        if i + z[i] > r:
            l = i
            r = i + z[i]

    return z
```

### Pattern Matching Wrapper

```text
matches(pattern, text):
    combined = pattern + '#' + text
    z = z_function(combined)
    for each position i in text-part of combined:
        if z[i] >= len(pattern):
            report a match
```

### Border / Period Checks

```text
for i from 1 to n - 1:
    if i + z[i] == n:
        suffix starting at i is fully covered by prefix
```

That single test powers several periodicity and border problems.

## Implementation Notes

### 1. Keep `[l, r)` Half-Open

Use:

- `l` inclusive
- `r` exclusive

Then:

- box length is `r - l`
- mirrored reuse is `min(r - i, z[i - l])`

This convention makes the code and proof much cleaner.

### 2. `z[0]` Is Usually `0` By Convention

Some mathematical texts define `z[0] = n`.

In contest code, `z[0] = 0` is more common.

Be explicit about the convention when comparing with other references.

### 3. The Mirrored Index Is `i - l`

One of the most common bugs is to write the reuse line incorrectly.

Inside the current Z-box:

$$
k = i - l
$$

is the mirrored prefix position.

So the seeded value is:

$$
\min(r - i, z[i - l]).
$$

### 4. The Delimiter In Concatenation Must Be Safe

For `pattern + '#' + text`, the delimiter must not occur in either string.

Otherwise a false match can cross the boundary and corrupt the interpretation.

### 5. Border Versus Period Is A Logic Choice, Not A Z Choice

Z only tells you prefix coverage facts.

You still have to translate those facts into the exact problem condition:

- border?
- full tiling period?
- period with partial last block?
- occurrence count?

Do not smuggle in an extra divisibility condition unless the statement actually asks for it.

### 6. Concatenation Answers Matching, Not Just Existence

For `pattern + '#' + text`, the Z array does more than say whether a match exists:

- every position with `z[i] >= |pattern|` is an occurrence
- the exact Z value also tells how much of the pattern matches there before a mismatch

That makes Z especially nice for "diagnostic" string problems where near-matches or repeated prefix structure matter.

### 7. Z Is Often The Cleanest Way To Think About Prefix Occurrences

If the problem language is:

- "prefix appears here"
- "suffix matches prefix"
- "what is the longest prefix match at this shift?"

then Z is usually more natural than forcing a KMP explanation onto it.

### 8. KMP And Z Are Neighbors, Not Replacements

Many tasks can be solved by either.

Pick the one whose invariant matches the statement language:

- prefix-match window -> Z
- border fallback chain -> KMP

This is a judgment skill worth building deliberately.

## Practice Archetypes

The most common Z-function patterns are:

- **exact one-pattern matching** via concatenation
- **prefix diagnostics**: how strongly does the prefix appear at every shift?
- **borders** from suffixes fully covered by the prefix
- **period detection** with or without full tiling
- **string-structure debugging** alongside KMP / prefix function

The strongest contest smell is:

- "the prefix of this string matters at many other positions"

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Course:

- [UNSW COMP4128 string lecture notes](https://www.cse.unsw.edu.au/~cs4128/18s1/lectures/11-strings.pdf)
- [USACO Guide: String Searching](https://usaco.guide/adv/string-search?lang=cpp)

Reference:

- [CP-Algorithms: Z-Function](https://cp-algorithms.com/string/z-function.html)
- [OI Wiki: Z Function](https://en.oi-wiki.org/string/z-func/)

Practice:

- [CSES Problem Set](https://cses.fi/problemset/)

Repo anchors:

- practice ladder: [Z-Function ladder](../../../practice/ladders/strings/z-function/README.md)
- practice note: [String Functions](../../../practice/ladders/strings/z-function/stringfunctions.md)
- practice note: [Finding Periods](../../../practice/ladders/strings/z-function/findingperiods.md)
- starter template: [z-function.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/z-function.cpp)
- notebook refresher: [String cheatsheet](../../../notebook/string-cheatsheet.md)

## Related Topics

- [KMP](../kmp/README.md)
- [String Hashing](../hashing/README.md)
- [Aho-Corasick](../aho-corasick/README.md)
- [Suffix Array And LCP](../suffix-array-lcp/README.md)
