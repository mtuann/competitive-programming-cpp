# Aho-Corasick

Aho-Corasick is the multi-pattern extension of trie matching. Use it when many patterns are matched against one text.

## Prerequisites

- [Trie](../trie/README.md)
- [BFS And DFS](../../graphs/bfs-dfs/README.md)

## When To Suspect It

- many patterns, one long text
- you need all occurrences of many keywords
- pattern matching with shared prefixes should be reused
- one-pattern tools like KMP would be too repetitive across a large pattern set

## Core Idea

Build a trie of the patterns, then add failure links that point to the next best suffix state after a mismatch.

This turns the trie into an automaton.

At scan time:

- follow trie edges when possible
- follow failure links when not
- collect outputs from the current state and its output/failure chain

## Theory / Proof Sketch

Failure links play the same role as KMP fallback, but on trie states instead of a single string. BFS over the trie builds those links in increasing depth order, which ensures each state's fallback is already known.

That gives an automaton where each processed character updates the current state in near-constant amortized time.

## Complexity And Tradeoffs

- build: `O(total pattern length * alphabet handling)`
- scan text: `O(text length + matches)`

Tradeoffs:

- perfect for multi-pattern exact matching
- heavier than KMP or Z for one pattern
- memory cost can become significant with huge alphabets or many states

## Canonical Pattern

Template in this repo:

- [aho-corasick.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/aho-corasick.cpp)

Standard workflow:

1. insert all patterns into a trie
2. BFS to build failure links
3. propagate terminal/output information through those links
4. scan the text or run DP on automaton states

## Worked Examples

Example 1: count keyword occurrences in a document

Every time the scan reaches a state, add that state's terminal count.

Example 2: forbidden substring DP using automaton states

DP over:

```text
position, automaton_state
```

and ban transitions that land in forbidden-output states.

Example 3: output all matches of many patterns

Store pattern ids in terminal states and report them while scanning.

## Recognition Cues

- one huge text and many query patterns
- banned keywords inside DP-generated strings
- dictionary matching with shared prefixes
- you want to preprocess the pattern set once and reuse it

## Common Mistakes

- forgetting to propagate output links or terminal counts through failure links
- using a dense alphabet table when the alphabet is large and sparse
- overusing Aho-Corasick when the pattern count is tiny
- building failure links correctly but not using them in the scan loop
- forgetting that automaton-DP states may need pruning on terminal nodes

## Standard Variants

- count matches
- report pattern ids
- automaton DP over generated strings
- sparse-edge implementation for larger alphabets
- exit-link or output-link optimizations

## Practice Ladder

- [Aho-Corasick ladder](../../../practice/ladders/strings/aho-corasick/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Aho-Corasick](https://cp-algorithms.com/string/aho_corasick.html)
- Reference: [OI Wiki - AC Automaton](https://en.oi-wiki.org/string/ac-automaton/)
- Blog/reference: [Stanford CS166 string matching notes](https://web.stanford.edu/class/archive/cs/cs166/)
- Paper/notes: [Aho-Corasick original algorithm background](https://en.wikipedia.org/wiki/Aho%E2%80%93Corasick_algorithm)

## Related Topics

- [Trie](../trie/README.md)
- [Digit DP](../../dp/digit-dp/README.md)
