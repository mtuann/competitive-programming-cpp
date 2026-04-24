# KMP

Knuth-Morris-Pratt is the standard deterministic linear-time answer for "find one pattern inside one text" when you want a proof-backed exact matcher, not a probabilistic hash and not a heavier suffix structure. More importantly, it teaches one of the most reusable ideas in strings:

1. a mismatch does not destroy all previous work
2. the part that survives is exactly a border
3. borders themselves form a fallback chain

If `Z-function` feels like the "prefix matches everywhere" view, KMP is the "what is the longest prefix that still survives here?" view.

## At A Glance

Reach for KMP when:

- one pattern must be matched exactly inside one text
- overlaps matter
- you want deterministic worst-case `O(n + m)`
- the pattern's own border structure is useful beyond matching
- the problem talks about borders, prefix-suffix overlaps, periods, or fallback states

Strong contest triggers:

- "count all exact occurrences of `p` in `t`"
- "find all borders of a string"
- "after a mismatch, keep the longest usable overlap"
- "build an automaton on prefix states"
- "reuse the overlap between suffix of what matched and prefix of the pattern"

Strong anti-cues:

- many patterns against one text: [Aho-Corasick](../aho-corasick/README.md) is the right multi-pattern machine
- the problem is more naturally "how much does the whole prefix match at every position?": [Z-Function](../z-function/README.md) may read more cleanly
- substring equality queries dominate: [String Hashing](../hashing/README.md) or suffix structures may be the real tool
- approximate matching is needed: plain KMP is exact only

What success looks like after studying this page:

- you can define `pi[i]` without ambiguity
- you can explain why only borders matter after a mismatch
- you can derive both prefix-function construction and text matching from the same invariant
- you know when to write the classic stateful matcher and when the `pattern + '#' + text` trick is simpler

## Prerequisites

- [Z-Function](../z-function/README.md) for the neighboring exact-match perspective
- [String Hashing](../hashing/README.md) for the deterministic-vs-probabilistic tradeoff

## Problem Model And Notation

Let:

- `P` be the pattern, length `m`
- `T` be the text, length `n`

We use zero-based indexing.

A **border** of a string is a proper prefix that is also a suffix.

For a string `S`, define the prefix function:

$$
\pi[i] = \text{length of the longest proper prefix of } S[0..i] \text{ that is also a suffix of } S[0..i].
$$

So `pi[i]` is a length, not an index.

Example: if `S = "ababaca"`, then:

$$
\pi = [0, 0, 1, 2, 3, 0, 1].
$$

The KMP matching state is:

$$
j = \text{current matched prefix length of } P.
$$

During matching, after reading some prefix of the text, `j` means:

- the last `j` text characters match `P[0..j-1]`
- no longer prefix of `P` has that property

That is the main invariant of the algorithm.

## From Brute Force To The Right Idea

### Brute Force

The naive exact matcher tries every shift:

- align `P` at every start position in `T`
- compare characters left to right
- after a mismatch, move the pattern by one

Worst-case time is `O(nm)`.

The failure mode is easy to see on repetitive strings:

- `T = aaaaaaaaa...`
- `P = aaaaab`

You keep rechecking almost the same prefix of `P` over and over.

### What Actually Survives After A Mismatch

Suppose we matched `j` characters:

$$
P[0..j-1] = T[i-j..i-1]
$$

and then `P[j] != T[i]`.

What shift is still possible?

The already matched text suffix can only remain useful if it is also a prefix of the pattern. So after a mismatch, the next candidate state must be a border of `P[0..j-1]`.

This is the crucial observation:

- after a mismatch, the only survivors are borders
- among those borders, the best first retry is the longest one

That is exactly what `pi[j-1]` stores.

### Why Prefix Function Is The Right Cache

If we knew, for every prefix `P[0..i]`, the length of its longest border, then on mismatch from state `j` we could jump to:

$$
j \leftarrow \pi[j-1]
$$

instead of restarting from zero.

If that shorter border also fails against the current text character, we jump again:

$$
j \leftarrow \pi[\pi[j-1]-1],
$$

and so on.

So the whole algorithm becomes:

1. preprocess the pattern into its border fallback table `pi`
2. scan the text left to right
3. on mismatch, follow border links instead of moving the text pointer backward

This is why KMP is linear: the text pointer never rewinds, and the pattern state only moves along a precomputed border chain.

## Core Invariant And Why It Works

### Invariant For Prefix-Function Construction

When building `pi` for a string `S`, suppose we are computing `pi[i]`.

Let:

$$
j = \pi[i-1].
$$

Then before comparing `S[i]`, `j` is the length of the longest border of `S[0..i-1]`.

If `S[i] == S[j]`, that border extends by one, so:

$$
\pi[i] = j + 1.
$$

If `S[i] != S[j]`, the current border cannot extend. The only smaller candidates worth trying are borders of that border, so we set:

$$
j \leftarrow \pi[j-1]
$$

and try again.

This works because every suffix of `S[0..i-1]` that is also a prefix must itself be a border of the current longest border chain.

### Invariant For Text Matching

While scanning text position `i`, let `j` be the current matched prefix length.

The invariant is:

$$
P[0..j-1] = T[i-j..i-1]
$$

and `j` is maximal with that property.

Now compare `T[i]` with `P[j]`.

- If they match, we extend the invariant to `j + 1`.
- If they mismatch, the only possible surviving states are borders of `P[0..j-1]`, so we repeatedly replace `j` by `pi[j-1]`.

This never misses a match, because any valid next shift must preserve a suffix of the already matched text that is also a prefix of `P`.

### Why The Algorithm Is Linear

There are two standard proofs worth remembering.

#### 1. Prefix-function construction

In the build loop:

- `i` increases from left to right exactly once
- `j` only moves backward through `pi`

Every backward jump strictly decreases `j`, and every successful character comparison increases it by one. Since `j` never becomes negative, the total number of decreases across the whole run is `O(m)`. Therefore the total build time is `O(m)`.

#### 2. Text matching

During matching:

- the text index only moves right
- every failure jump strictly decreases `j`
- every match increases `j`

So the total number of character comparisons is linear in `n + m`. A convenient way to phrase it, also emphasized in course notes, is:

- each step either advances in the text
- or strictly shortens the current matched prefix

neither can happen too many times overall.

### Failure Links And Prefix Function Are The Same Spine

Older expositions often describe KMP with a failure-link automaton. Contest code usually stores `pi`.

These are the same idea in two surface forms:

- failure link from state `j` tells where to go after mismatch
- `pi[j-1]` is exactly that fallback length

So when contest notes say:

```text
j = pi[j - 1]
```

they are following one failure edge in the KMP automaton.

## Complexity And Tradeoffs

- prefix-function build: `O(m)`
- matching one pattern against one text: `O(n + m)`
- memory: `O(m)` for `pi`

Practical tradeoffs:

| Tool | Best when | Time | Main limitation |
| --- | --- | --- | --- |
| naive scan | tiny inputs or one-off scripting | `O(nm)` worst-case | rescans too much |
| [String Hashing](../hashing/README.md) | many substring comparisons, equality queries, or when probabilistic checks are acceptable | often `O(n + m)` or better per query pattern | collisions unless deterministic safeguards are added |
| [Z-Function](../z-function/README.md) | prefix-match style tasks, concatenation tricks | `O(n + m)` | border chaining and fallback-state thinking are less direct |
| KMP | deterministic exact one-pattern matching, borders, fallback states | `O(n + m)` | specialized to exact matching and prefix-border structure |
| [Aho-Corasick](../aho-corasick/README.md) | many patterns in one text | `O(total text + total patterns + matches)` | heavier preprocessing and automaton |

Rule of thumb:

- one exact pattern, one text, deterministic worst-case guarantee -> KMP
- one exact pattern, but the statement talks in "prefix match at each shift" language -> Z-function may be the cleaner first lens
- many patterns -> Aho-Corasick
- repeated substring equality or binary search on answers -> hashing often plays a different role

## Variant Chooser

| Variant | What changes | When to choose it | Where it gets awkward |
| --- | --- | --- | --- |
| classic stateful matcher | keep `j` while scanning `T` | direct text scan, streaming, overlaps | slightly harder to explain on first read |
| `pattern + '#' + text` prefix-function trick | compute `pi` on one combined string | contest implementation is short and uniform | needs a separator not in the alphabet |
| border chaining | repeatedly follow `pi[x-1]` | all borders, period checks, prefix occurrence counts | not itself a matcher |
| prefix automaton | precompute transitions from `pi` states | DP on generated strings, recursive texts, automaton tasks | heavier than plain KMP for simple matching |

The important lesson is that KMP is bigger than "one matcher":

- `pi` is a border table
- border table gives failure links
- failure links give a small deterministic automaton

## Worked Examples

### Example 1: Mechanical Trace On `ababaca`

Let:

$$
S = \text{"ababaca"}.
$$

We compute `pi` left to right.

Known final answer:

$$
\pi = [0, 0, 1, 2, 3, 0, 1].
$$

The instructive step is `i = 5`, where `S[i] = 'c'`.

Before processing `i = 5`, we have:

- prefix `S[0..4] = "ababa"`
- `j = pi[4] = 3`

So the current best border is `"aba"`.

Try to extend it:

- compare `S[5] = 'c'` with `S[3] = 'b'` -> mismatch

The longest border fails, so fall back to the next border of `"ababa"`:

$$
j \leftarrow \pi[2] = 1
$$

Now try border `"a"`:

- compare `S[5] = 'c'` with `S[1] = 'b'` -> mismatch

Fall back again:

$$
j \leftarrow \pi[0] = 0
$$

Now there is no nonempty border left. Since `S[5] != S[0]`, we conclude:

$$
\pi[5] = 0.
$$

This is the whole algorithm in miniature:

- start from the longest border
- if it fails, only try borders of that border
- never retry arbitrary lengths

### Example 2: Contest-Style Matching With Overlaps

Let:

- `P = "aba"`
- `T = "ababa"`

The prefix function of `P` is:

$$
\pi = [0, 0, 1].
$$

Now scan the text with state `j`.

1. Read `a`: `j = 1`
2. Read `b`: `j = 2`
3. Read `a`: `j = 3` -> full match ends here

So we found one occurrence ending at this position. But because overlaps are allowed, we do **not** reset to zero. We continue from the longest proper border of the whole pattern:

$$
j \leftarrow \pi[2] = 1.
$$

Continue scanning:

4. Read `b`: `j = 2`
5. Read `a`: `j = 3` -> second full match

So the matches start at positions `0` and `2`.

This is exactly why full-match fallback matters: if you reset to zero blindly, you lose overlapping matches.

## Algorithm And Pseudocode

This repo's starter template is:

- [kmp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/kmp.cpp)

It uses the combined-string trick, but the classic stateful matcher is the right conceptual core.

### Prefix Function

```text
prefix_function(S):
    pi[0] = 0
    for i from 1 to |S|-1:
        j = pi[i-1]
        while j > 0 and S[i] != S[j]:
            j = pi[j-1]
        if S[i] == S[j]:
            j = j + 1
        pi[i] = j
    return pi
```

### Classic KMP Matcher

```text
match(T, P):
    pi = prefix_function(P)
    j = 0
    for i from 0 to |T|-1:
        while j > 0 and T[i] != P[j]:
            j = pi[j-1]
        if T[i] == P[j]:
            j = j + 1
        if j == |P|:
            report match ending at i
            j = pi[j-1]
```

### Combined-String Contest Variant

Build:

$$
S = P + \# + T
$$

where `#` is a separator not appearing in either string.

Then every position in `S` with:

$$
\pi[i] = |P|
$$

corresponds to one occurrence of `P` in `T`.

Why this works:

- every prefix of `S` of length `|P|` is exactly the pattern `P`
- the separator prevents any longer match from leaking across the boundary
- so when a suffix ending in the text part has prefix-function value `|P|`, it means that suffix ends with one exact copy of `P`

This is often the shortest contest implementation if you already trust your prefix-function builder.

## Implementation Notes

### 1. `pi[i]` Is A Length, Not An Index

This is the easiest off-by-one trap.

If `j = pi[i-1]`, then the next character to compare is `S[j]`, not `S[j-1]`.

### 2. After A Full Match, Fall Back To `pi[m-1]`

If overlaps are possible, do not reset `j` to zero after one full occurrence.

The correct transition is:

```text
j = pi[m - 1]
```

### 3. Combined-String KMP Needs A Safe Separator

For:

```text
P + '#' + T
```

the separator must not appear in either string. In competitive programming this is often easy because the alphabet is lowercase English letters and `#` is safe.

If the alphabet is arbitrary bytes or unrestricted Unicode, the classic matcher is the safer presentation.

### 4. Empty Pattern Is Usually Excluded By Problem Statements

Most contest problems guarantee `m >= 1`. If you ever write a reusable library outside contest assumptions, decide explicitly what an empty pattern means before coding.

### 5. KMP And Z Solve Some Of The Same Tasks

Both can do:

- exact one-pattern matching
- borders / periods
- concatenation tricks

But their mental models differ:

- KMP is best when fallback states or border chains are the story
- Z is best when "how strongly does the whole prefix match here?" is the story

### 6. Prefix Automaton Is The Next Step, Not The First

For plain matching, do not overbuild.

The automaton form matters when:

- the text is generated recursively
- you want DP over states
- you process one stream character at a time with precomputed transitions

For ordinary `String Matching`, the plain matcher or combined-string trick is enough.

### 7. `pi` Can Solve More Than Matching

Once `pi` is computed, you can often answer:

- all border lengths
- whether a string has a full period
- how often prefixes occur
- automaton transitions for generated texts

So the main contest habit is:

- do not think of `pi` as "only the preprocessing for KMP"
- think of it as "the border structure of the string"

To enumerate all borders of a string `S`, start from:

```text
x = pi[n - 1]
```

and repeatedly jump:

```text
x = pi[x - 1]
```

until `x = 0`.

## Practice Archetypes

KMP is the right first tool when the problem feels like one of these:

- `single exact pattern`: all matches, count matches, or first match
- `border chain`: list all borders or follow prefix-suffix links
- `period / overlap`: reuse the longest suffix-prefix overlap
- `prefix automaton`: transitions over prefix states instead of raw text rescans

Good internal practice anchors:

- [String Matching](../../../practice/ladders/strings/kmp/stringmatching.md): clean first KMP problem, especially for overlaps
- [Finding Borders](../../../practice/ladders/strings/hashing/findingborders.md): same border language, but here KMP gives a deterministic route too
- [Finding Periods](../../../practice/ladders/strings/z-function/findingperiods.md): useful comparison point for `pi` vs `z`

Suggested progression:

1. build `pi` from memory on short strings
2. solve exact one-pattern matching
3. enumerate borders by chaining `pi`
4. only then move to prefix automata or generated-text DP

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Primary:

- [Knuth, Morris, Pratt: Fast Pattern Matching in Strings (1977)](https://cs.brown.edu/courses/csci1810/fall-2023/resources/ch2_readings/kmp_strings.pdf)

Course:

- [Cornell CS312 lecture notes on string matching](https://www.cs.cornell.edu/courses/cs312/2002sp/lectures/lec25.htm)
- [Concordia notes: The Knuth-Morris-Pratt string-matching algorithm](https://users.encs.concordia.ca/~chvatal/notes/kmp.html)
- [COMP 526 string matching slides](https://www.wild-inter.net/teaching/comp526/notes-04-string-matching.pdf)

Reference:

- [CP-Algorithms: Prefix function / Knuth-Morris-Pratt](https://cp-algorithms.com/string/prefix-function.html)

Practice:

- [CSES Problem Set](https://cses.fi/problemset/)

Repo anchors:

- [KMP ladder](../../../practice/ladders/strings/kmp/README.md)
- [String Matching note](../../../practice/ladders/strings/kmp/stringmatching.md)
- [kmp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/kmp.cpp)
- [String cheatsheet](../../../notebook/string-cheatsheet.md)

## Related Topics

- [Z-Function](../z-function/README.md)
- [String Hashing](../hashing/README.md)
- [Aho-Corasick](../aho-corasick/README.md)
- [Suffix Automaton](../suffix-automaton/README.md)
