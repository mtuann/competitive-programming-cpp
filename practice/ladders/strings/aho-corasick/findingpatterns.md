# Finding Patterns

- Title: `Finding Patterns`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/2102](https://cses.fi/problemset/task/2102)
- Secondary topics: `Trie automaton`, `Failure links`, `Failure-tree propagation`
- Difficulty: `medium`
- Subtype: `Answer whether each pattern appears at least once in one text`
- Status: `solved`
- Solution file: [findingpatterns.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/aho-corasick/findingpatterns.cpp)

## Why Practice This

This is the textbook first Aho-Corasick problem:

- one text
- many patterns
- only exact matching
- one yes/no answer per pattern

That makes it perfect for learning the automaton itself before moving on to heavier variants like occurrence counting or automaton DP.

## Recognition Cue

Reach for Aho-Corasick when:

- there is one long text
- there are many patterns
- matching each pattern independently would repeat the same text scan too much

The strongest smell is:

- "for each pattern, does it appear in the text at least once?"

That is exactly the many-patterns-against-one-text use case of the automaton.

## Problem-Specific Transformation

The statement is rewritten as:

- trie over all patterns
- failure links for suffix fallback
- one text scan that visits automaton states

Then the per-pattern yes/no answers are no longer independent scans. They come from:

- how often each automaton state is visited
- propagated upward through failure links

## Core Idea

Insert all patterns into a trie and remember the terminal node of each pattern.

Then build failure links with BFS. Each failure link says:

```text
if this trie edge fails, what is the longest proper suffix state we can continue from?
```

After the trie becomes an automaton, scan the text once:

- follow automaton transitions character by character
- each visited state means "some pattern suffixes may end here"

Instead of walking the whole output chain for every text position, we use a cleaner offline trick:

1. Count how many times each automaton state is visited while scanning the text.
2. Process states in reverse BFS order.
3. Add each state's count into its failure link parent.

Why does that work?

Because if state `v` is visited, then every pattern represented by a suffix state on the failure chain also matched at that text position. Reverse propagation along failure links accumulates exactly those suffix matches.

So for every pattern, we only check whether its terminal node received a positive count.

## Complexity

- building the trie: `O(total pattern length)`
- building failure links: `O(alphabet * states)`
- scanning the text: `O(text length)`
- propagating counts on failure links: `O(states)`

For lowercase English strings, this is comfortably fast for the CSES limits.

## Pitfalls / Judge Notes

- Duplicate patterns can end at the same trie node; storing each pattern's terminal state handles that naturally.
- Failure links are not just for mismatches during the scan. They also carry suffix-match information.
- If you walk the whole output chain at every text position, you risk unnecessary overhead. Reverse failure-tree propagation is cleaner here.
- Root transitions should be completed during BFS so the scan loop stays simple.

## Reusable Pattern

- Topic page: [Aho-Corasick](../../../../topics/strings/aho-corasick/README.md)
- Practice ladder: [Aho-Corasick ladder](README.md)
- Starter template: [aho-corasick.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/aho-corasick.cpp)
- Notebook refresher: [String cheatsheet](../../../../notebook/string-cheatsheet.md)
- Carry forward: build failure links once, then treat the automaton walk as the real scan.
- This note adds: the output aggregation or query logic used on top of the automaton.

## Solutions

- Code: [findingpatterns.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/strings/aho-corasick/findingpatterns.cpp)
