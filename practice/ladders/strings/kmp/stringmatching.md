# String Matching

- Title: `String Matching`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1753](https://cses.fi/problemset/task/1753)
- Secondary topics: `Prefix function`, `Border fallback`, `Overlapping matches`
- Difficulty: `easy`
- Subtype: `Count all exact occurrences of one pattern in a text`
- Status: `solved`
- Solution file: [stringmatching.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/kmp/stringmatching.cpp)

## Why Practice This

This is the cleanest first KMP problem because the task is exactly what the algorithm was built for: scan one long text, count every occurrence of one pattern, and do it without ever moving the text pointer backward.

## Recognition Cue

This is one of the clearest `KMP` triggers:

- one pattern and one long text
- count all exact occurrences
- overlapping matches matter
- rescanning the text from the left would be too expensive

If the statement is really about "keep scanning forward without undoing text work," the prefix-function fallback machine is usually the right model.

## Problem-Specific Transformation

The statement talks about counting matches, but the reusable reformulation is:

- preprocess the pattern into a border-fallback table `pi`
- scan the text with one state `j = matched_prefix_length`
- on mismatch, shorten `j` through `pi[j - 1]`
- on full match, increment the answer and continue from `pi[m - 1]`

So the problem is not "search from every text position." It is "maintain the longest matched prefix while the text pointer only moves right."

## Core Idea

Let `pi[i]` be the length of the longest proper prefix of the pattern that is also a suffix ending at position `i`.

That one array answers the key mismatch question:

```text
we matched j characters, then pattern[j] != current_text_char
```

Where should we continue?

We do **not** restart from zero immediately. The prefix of length `pi[j - 1]` is already known to match the suffix of what we just matched, so it is the longest valid fallback state. Therefore:

```text
j = pi[j - 1]
```

and we try the same text character again from that shorter border.

While scanning the text:

- if characters match, extend `j`
- if they mismatch, follow border links through `pi`
- if `j == m`, we found one full occurrence

After a full match, set:

```text
j = pi[m - 1]
```

instead of zero, because matches are allowed to overlap.

## Complexity

- prefix-function build: `O(m)`
- text scan: `O(n)`
- total: `O(n + m)`

Each character participates in only a constant number of pointer movements across the whole run.

## Pitfalls / Judge Notes

- Count overlapping matches, so do not reset `j` to zero after a full occurrence unless `pi[m - 1]` is zero anyway.
- The fallback on mismatch is `pi[j - 1]`, not `pi[j]`.
- Handle the pattern and text as plain strings; no separator trick is required here.
- With input sizes up to about `10^6`, use iterative logic and fast I/O.

## Reusable Pattern

- Topic page: [KMP](../../../../topics/strings/kmp/README.md)
- Practice ladder: [KMP ladder](README.md)
- Starter template: [kmp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/kmp.cpp)
- Notebook refresher: [String cheatsheet](../../../../notebook/string-cheatsheet.md)
- Carry forward: the prefix function is a fallback table, not just a preprocessing artifact.
- This note adds: the occurrence-counting or overlap logic added on top of the base matcher.

## Solutions

- Code: [stringmatching.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/kmp/stringmatching.cpp)
