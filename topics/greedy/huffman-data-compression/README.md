# Huffman / Data Compression

This lane is for the point where a greedy problem stops being:

- "keep every prefix feasible"
- or "repair the worst current choice"

and becomes:

- **merge the two lightest pieces**
- build one optimal binary prefix-code tree
- and reason about weighted depth, not about one scan invariant

The repo's exact first route for this family is:

- starter -> [huffman-coding.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/greedy/huffman-coding.cpp)
- flagship note -> [Huffman Coding Benchmark](../../../practice/ladders/greedy/huffman-data-compression/huffmancoding.md)
- compare point -> [Heaps And Ordered Sets](../../data-structures/heaps-and-ordered-sets/README.md)
- compare point -> [Prefix Constraints](../prefix-constraints/README.md)

This lane intentionally teaches the **binary Huffman route first**:

- positive symbol frequencies
- min-heap over current subtree weights
- repeated merge of the two smallest trees
- weighted external path length and one deterministic code assignment

It does **not** start from:

- full file compressors
- bitstream serialization
- arithmetic coding
- LZW or run-length coding
- entropy proofs beyond the contest-facing greedy story

## At A Glance

- **Use when:** the objective is one optimal binary prefix code or one optimal merge tree from symbol frequencies
- **Core worldview:** every merge pays its combined weight once more, so the total optimum is exactly the sum of merge costs
- **Main tools:** min-heap, merge tree, leaf depths, deterministic tie-break policy
- **Typical complexity:** `O(n log n)` for `n` symbols
- **Main trap:** confusing "build one optimal prefix-code tree" with "implement a production compressor"

Strong study signals:

- "repeatedly take the two smallest weights"
- "optimal prefix code"
- "weighted path length / expected code length"
- "classic Huffman coding from the data-compression chapter"

Strong anti-cues:

- the task is really one range or prefix feasibility scan -> [Prefix Constraints](../prefix-constraints/README.md)
- the point is actual byte-level compression format details
- the alphabet changes online and merge history is not the right object

## Prerequisites

- [Greedy overview](../README.md), because you should already be comfortable with exchange-style greedy thinking
- [Heaps And Ordered Sets](../../data-structures/heaps-and-ordered-sets/README.md), because the implementation route is one disciplined min-heap process
- [Sorting](../../foundations/patterns/sorting/README.md) helps as a lighter compare point, because many merge problems begin by asking what order matters

Helpful compare points:

- [Heaps And Ordered Sets](../../data-structures/heaps-and-ordered-sets/README.md): use this when the main question is only priority-queue mechanics, not greedy optimality
- [Prefix Constraints](../prefix-constraints/README.md): use that family when feasibility lives in one scan over ordered input, not one merge forest
- [Minimum Spanning Tree](../../graphs/mst/README.md): another greedy tree-building family, but the proof lens is cut safety rather than weighted depth

## Problem Model

The canonical task in this lane is:

- you have `n` symbols
- symbol `i` has frequency `f[i] > 0`
- build one binary prefix code minimizing:

```text
sum(f[i] * code_length[i])
```

Equivalently:

- build one full binary tree whose leaves are the symbols
- minimize weighted leaf depth

That is the exact first model this repo teaches.

## The Greedy Pivot

The central greedy fact is:

- in some optimal tree, the two lightest symbols can be made siblings at maximum depth

So if you merge those two symbols into one combined weight:

```text
w = x + y
```

the remaining problem is the same problem on one smaller instance.

That is why the algorithm becomes:

1. keep all current trees in a min-heap by weight
2. remove the two lightest
3. merge them
4. push their parent back
5. repeat until one tree remains

This is the exact greedy backbone of Huffman coding.

## Core Invariants

The repo starter keeps four contest-facing invariants.

### 1. The Heap Stores The Current Forest

Every heap item means:

- one subtree
- one total frequency
- one deterministic tie-break key for reproducible output

So the heap is not just "numbers"; it is the current reduced instance.

### 2. Every Merge Adds Its Weight Once To The Final Objective

If two subtrees of weights `a` and `b` are merged, then all leaves inside them go one level deeper.

So that merge increases the final weighted path length by exactly:

```text
a + b
```

This is the fastest sanity check in the whole lane.

### 3. The Final Cost Equals The Sum Of All Merge Costs

You can compute the optimum either by:

- DFS on final leaf depths
- or summing every internal merge weight

Those two numbers must agree.

### 4. One-Symbol Input Needs A Convention

If `n = 1`, the mathematically clean codeword is the empty string.

This repo prints:

- weighted cost `0`
- code `-`

so the output stays visible and unambiguous.

## Complexity And Tradeoffs

With `n` symbols:

- heap-based build: `O(n log n)`
- DFS to assign codes: `O(n)`
- memory: `O(n)`

Rule of thumb:

- one optimal merge / prefix-code tree -> this lane
- one scan with prefix feasibility -> [Prefix Constraints](../prefix-constraints/README.md)
- one PQ process without a proof obligation -> reopen [Heaps And Ordered Sets](../../data-structures/heaps-and-ordered-sets/README.md)

## Worked Example

Classic frequencies:

```text
45 13 12 16 9 5
```

The deterministic repo starter builds one valid optimal code such as:

```text
0
101
100
111
1101
1100
```

with weighted cost:

```text
224
```

The exact codes depend on the tie policy, but the minimum cost is the real invariant.

## Common Pitfalls

- proving only that the smallest pair "looks good" instead of using the sibling-at-maximum-depth reduction
- forgetting that multiple optimal code assignments can exist under ties
- trying to teach file headers, byte packing, or decompression formats in the first lane
- mishandling the one-symbol case

## Exit Criteria

After this section, you should be able to:

- explain why the two smallest weights are merged first
- compute weighted path length both from merge sums and from final depths
- implement one deterministic binary Huffman builder with a min-heap
- know why this lane is about greedy optimal merge, not about industrial compression tooling

## Go Deeper

- Reference: [Algorithms 4/e - Huffman](https://algs4.cs.princeton.edu/code/javadoc/edu/princeton/cs/algs4/Huffman.html)
- Reference: [Algorithms 4/e - Data Compression slides](https://algs4.cs.princeton.edu/lectures/keynote/55DataCompression.pdf)
- Reference: [Cornell CS312 - Priority Queues, Heaps, Huffman Coding](https://www.cs.cornell.edu/courses/cs312/2002sp/lectures/lec19.asp)
- Practice: [Greedy ladders](../../../practice/ladders/greedy/README.md)
