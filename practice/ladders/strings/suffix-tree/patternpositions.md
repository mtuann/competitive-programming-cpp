# Pattern Positions

- Title: `Pattern Positions`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/2104](https://cses.fi/problemset/task/2104)
- Secondary topics: `Compressed suffix trie`, `Edge-interval matching`, `Subtree minimum`
- Difficulty: `hard`
- Subtype: `Many patterns against one static text, earliest occurrence for each`
- Status: `solved`
- Solution file: [patternpositions.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/suffix-tree/patternpositions.cpp)

## Why Practice This

This is the cleanest first verifier for the repo's suffix-tree route.

The statement is not about suffix order or all-substring counting. It is about using one fixed text as a reusable exact index:

- build once
- walk each pattern through compressed edges
- answer with the minimum suffix start in the matched subtree

That makes it a much better first suffix-tree checkpoint than reusing `Distinct Substrings`, which the repo already uses to teach [Suffix Automaton](../../../../topics/strings/suffix-automaton/README.md).

## Recognition Cue

Reach for suffix tree here when:

- one text is fixed
- many patterns are queried against that text
- exact matching is required
- the answer is the first occurrence, not just existence

The strongest smell is:

- "build one exact substring index for one static text"

## Problem-Specific Transformation

Rewrite the task as:

- build the suffix tree of the text with a unique terminator
- store `min_start` for every subtree
- for each pattern, walk it across compressed edges
- if the walk fails, answer `-1`
- if the walk succeeds, answer `min_start + 1`

The `+1` is only for the judge's indexing.

## Core Idea

Every leaf corresponds to one suffix start of the text.

If a pattern `p` is fully matched from the root, then every leaf under that final matched subtree represents a suffix whose prefix starts with `p`.

So we only need one aggregate:

```text
min_start[v] = earliest suffix start among leaves in subtree(v)
```

Then each pattern query becomes:

1. choose the next edge by the next unmatched character
2. consume characters directly along that edge interval
3. if a mismatch happens, answer `-1`
4. if the pattern finishes anywhere along the matched edge, return the child subtree's `min_start`

The subtle point is that the pattern does **not** need to end at an explicit node. Finishing in the middle of an edge is still a complete match, because all leaves below that child continue with the same already-matched prefix.

## Complexity

- build suffix tree once: `O(n * alphabet)` with fixed-array transitions
- each query of length `m`: `O(m)`
- total over all queries: linear in the total pattern length

## Pitfalls / Judge Notes

- The text and patterns are lowercase `a-z`, so a fixed transition array is safe here.
- Append a unique terminator internally; do not let it leak into queries.
- Earliest occurrence is `1`-indexed in the statement, but suffix starts are stored `0`-indexed in the tree.
- The matched pattern may finish in the middle of a compressed edge. Do not force the walk to land on an explicit node.

## Reusable Pattern

- Topic page: [Suffix Tree](../../../../topics/strings/suffix-tree/README.md)
- Practice ladder: [Suffix Tree ladder](README.md)
- Starter template: [suffix-tree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/suffix-tree.cpp)
- Notebook refresher: [Suffix Tree hot sheet](../../../../notebook/suffix-tree-hot-sheet.md)
- Compare point: [Finding Patterns](../aho-corasick/findingpatterns.md) when many patterns are known first and a pattern trie is the simpler direction
- Compare point: [Repeating Substring](../suffix-array-lcp/repeatingsubstring.md) when suffix order, not substring indexing, is the real object

## Solutions

- Code: [patternpositions.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/suffix-tree/patternpositions.cpp)
