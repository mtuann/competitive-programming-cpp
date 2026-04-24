# Distinct Substrings

- Title: `Distinct Substrings`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/2105](https://cses.fi/problemset/task/2105)
- Secondary topics: `State length intervals`, `Suffix links`, `Online construction`
- Difficulty: `medium`
- Subtype: `Count the number of distinct substrings of one string`
- Status: `solved`
- Solution file: [distinctsubstrings.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/suffix-automaton/distinctsubstrings.cpp)

## Why Practice This

This is the cleanest first counting problem for suffix automaton.

The problem asks for a global substring count, but the answer falls directly out of the core SAM invariant:

- state `v` represents substring lengths in `(len(link[v]), len[v]]`

So instead of enumerating substrings, we only need to understand what each state contributes. That makes this task a great checkpoint for whether the automaton's state meaning really feels solid.

## Key Idea

Build the suffix automaton online while scanning the string from left to right.

For every non-root state `v`, all substrings represented by `v` have the same end-position behavior, and their possible lengths form one interval:

```text
len(link[v]) + 1, len(link[v]) + 2, ..., len[v]
```

That interval contains exactly:

```text
len[v] - len(link[v])
```

different substring lengths, so state `v` contributes that many distinct substrings.

Why does summing over states work?

- every distinct substring ends at exactly one SAM state
- inside one state, different lengths correspond to different substrings
- suffix links split the represented lengths into disjoint intervals

Therefore the answer is:

```text
sum over all non-root states of (len[v] - len(link[v]))
```

The only implementation detail that needs care is the standard clone case:

- extend one character at a time
- walk suffix links to add missing transitions
- if an old transition would break the length invariant, clone that state and redirect links

Once the automaton is correct, the final count is just one linear pass over the states.

## Complexity

- build automaton: `O(n)`
- sum contributions: `O(n)`
- states: at most `2n - 1`
- total memory: `O(n)`

## Pitfalls / Judge Notes

- The answer can be as large as `n(n+1)/2`, so use `long long`.
- Do not count the root state.
- In the clone case, copy transitions and suffix link first, then shorten only the clone's `len`.
- The CSES statement uses characters `a-z`, so a fixed `26`-transition array is both safe and fast here.

## Reusable Pattern

- Topic page: [Suffix Automaton](../../../../topics/strings/suffix-automaton/README.md)
- Practice ladder: [Suffix Automaton ladder](README.md)
- Starter template: [Template library overview](../../../../template-library.md)
- Notebook refresher: [String cheatsheet](../../../../notebook/string-cheatsheet.md)
- Carry forward: track what each automaton state summarizes before relying on clone logic.
- This note adds: the counting or aggregation performed on top of the suffix-automaton states.

## Solutions

- Code: [distinctsubstrings.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/suffix-automaton/distinctsubstrings.cpp)
