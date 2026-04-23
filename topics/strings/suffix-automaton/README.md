# Suffix Automaton

Suffix automaton is the compact state-machine view of all substrings of a string. It is deeper than suffix array, but extremely powerful once the state meaning clicks.

## Prerequisites

- [Suffix Array And LCP](../suffix-array-lcp/README.md)
- [Trie](../trie/README.md)

## When To Suspect It

- substring queries over one growing string
- distinct substring counting or longest common substring variants
- you want the automaton of all substrings rather than all prefixes
- the string is built online and you want to update structure one character at a time

## Core Idea

Each state represents an equivalence class of substrings sharing the same set of end positions.

The automaton grows online one character at a time, with suffix links handling fallback.

For each state `v`, the key meaning is:

```text
all substrings represented by v have lengths in (len(link[v]), len[v]]
```

That one interval is the mental model you need most.

## Theory / Proof Sketch

When a new character is appended:

- create a new state for all suffixes ending at that character
- follow suffix links to add missing transitions
- if an existing transition would break the length invariant, clone the state

Clones are what preserve correctness while keeping the automaton compact. They split one old equivalence class into two:

- one for shorter-context behavior
- one for the new longer-context behavior

This is why suffix automaton stays linear in size despite representing all substrings.

## Complexity And Tradeoffs

- build: `O(n)` amortized
- many queries become linear or near-linear in the query size
- number of states: at most `2n - 1`

Tradeoffs:

- very powerful
- much harder to learn and debug than KMP, Z, or suffix array
- best once you already understand suffix links and state meaning clearly

## Canonical Pattern

Start with:

- state `0` as the initial state
- `last = 0`
- extend one character at a time
- use suffix links and clones

Typical follow-up tasks:

- count distinct substrings from state lengths
- propagate occurrence counts by topological order of state length
- walk another string through the automaton for longest common substring

## Worked Examples

Example 1: count distinct substrings

Each state contributes:

```text
len[v] - len(link[v])
```

new substrings.

Example 2: longest common substring with another string

Scan the second string through the automaton while maintaining current matched length. On failure, follow suffix links.

Example 3: frequency or occurrence aggregation on states

After marking end positions from insertions, propagate counts from longer states to their suffix links.

## Recognition Cues

- "all substrings of one string"
- online extension by appending characters
- distinct substring counting, longest common substring, or occurrence aggregation
- suffix array feels too static or too rank-focused for the task

## Common Mistakes

- not understanding what a state means before coding
- forgetting clone behavior or assigning clone links incorrectly
- confusing transitions of the new state and the clone
- propagating occurrence counts in the wrong order
- using suffix automaton for tasks where suffix array or hashing is easier

## Standard Variants

- online build
- distinct-substring counting
- occurrence-count propagation
- longest common substring with another string
- DP over automaton states

## Practice Ladder

- [Suffix automaton ladder](../../../practice/ladders/strings/suffix-automaton/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Suffix Automaton](https://cp-algorithms.com/string/suffix-automaton.html)
- Reference: [OI Wiki - Suffix Automaton](https://en.oi-wiki.org/string/sam/)
- Blog/reference: [USACO Guide - Suffix Automaton](https://usaco.guide/adv/string-suffix?lang=cpp)
- Notes: [Stanford string processing notes](https://web.stanford.edu/class/archive/cs/cs166/)

## Related Topics

- [Suffix Array And LCP](../suffix-array-lcp/README.md)
- [Aho-Corasick](../aho-corasick/README.md)
