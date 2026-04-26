# De Bruijn Sequence

- Title: `De Bruijn Sequence`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1692](https://cses.fi/problemset/task/1692)
- Secondary topics: `Eulerian cycle`, `Graph modeling`, `Bitmask states`
- Difficulty: `hard`
- Subtype: `Binary de Bruijn graph construction`
- Status: `solved`
- Solution file: [debruijnsequence.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/de-bruijn-sequence/debruijnsequence.cpp)

## Why Practice This

This is the cleanest first in-repo flagship for `De Bruijn Sequence`.

The statement already gives:

- binary alphabet
- one target order `n`
- exactly the universal-window construction goal

So the hard part is exactly the algorithmic one:

- model overlap states
- make each length-`n` word one edge
- read one Eulerian cycle back into one output string

## Recognition Cue

Reach for this route when:

- every binary string of length `n` must appear exactly once
- adjacent windows overlap by `n - 1`
- the answer is one constructed string, not a minimum or maximum over paths

The strongest smell here is:

- "construct the shortest binary string containing all `n`-bit strings as substrings"

That is exactly this lane.

## Problem-Specific Route

This task does **not** want:

- KMP or suffix structures, because we are not searching inside a given text
- plain Eulerian feasibility on an explicit input graph, because the graph is hidden
- brute force over candidate strings

The clean route is:

1. let vertices be all `(n - 1)`-bit states
2. from each state, add two directed edges by appending `0` or `1`
3. run one Eulerian cycle from the all-zero state
4. prepend `n - 1` zeros and append the traversed edge labels in order

## Core Idea

Every length-`n` bitstring has:

- one prefix of length `n - 1`
- one suffix of length `n - 1`

So it naturally becomes one edge between overlap states.

If an Eulerian cycle uses every edge exactly once, then:

- every length-`n` bitstring appears exactly once
- consecutive edges already overlap correctly

That means the cycle itself is the answer, once linearized.

## Complexity

- graph size: `2^(n - 1)` states and `2^n` edges
- traversal: `O(2^n)`
- memory: `O(2^n)`

That is fully comfortable for the CSES limits.

## Pitfalls / Judge Notes

- Handle `n = 1` directly.
- The answer is usually printed as a linear string, not as a cycle object.
- The final string length must be `2^n + n - 1`.
- If you append edge labels on backtracking, reverse them before printing.

## Reusable Pattern

- Topic page: [De Bruijn Sequence](../../../../topics/graphs/de-bruijn-sequence/README.md)
- Practice ladder: [De Bruijn Sequence ladder](README.md)
- Starter template: [de-bruijn-sequence-binary.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/de-bruijn-sequence-binary.cpp)
- Notebook refresher: [De Bruijn Sequence hot sheet](../../../../notebook/de-bruijn-sequence-hot-sheet.md)
- Compare points:
  - [Eulerian Path / Cycle](../../../../topics/graphs/eulerian-path-cycle/README.md)
  - [Graph Modeling](../../../../topics/graphs/graph-modeling/README.md)
- This note adds: the clean binary first route before more irregular overlap-graph constructions

## Solutions

- Code: [debruijnsequence.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/de-bruijn-sequence/debruijnsequence.cpp)
