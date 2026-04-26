# Huffman Coding Benchmark

- Title: `Huffman Coding Benchmark`
- Judge / source: `Canonical greedy prefix-code benchmark`
- Original URL: [https://algs4.cs.princeton.edu/code/javadoc/edu/princeton/cs/algs4/Huffman.html](https://algs4.cs.princeton.edu/code/javadoc/edu/princeton/cs/algs4/Huffman.html)
- Secondary topics: `Optimal merge`, `Prefix codes`, `Weighted path length`
- Difficulty: `medium`
- Subtype: `Binary Huffman coding with deterministic tie-breaks`
- Status: `solved`
- Solution file: [huffmancoding.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/greedy/huffman-data-compression/huffmancoding.cpp)

## Why Practice This

This is the cleanest first in-repo flagship for `Huffman / Data Compression`.

The benchmark is intentionally narrow:

- one list of positive frequencies
- one optimal weighted path length
- one deterministic valid code assignment

So the hard part is exactly the lane itself:

- priority-queue merge discipline
- weighted merge-cost invariant
- leaf-depth to codeword reconstruction

## Recognition Cue

Reach for the Huffman worldview when:

- the statement is really about one optimal binary prefix code
- or one repeated "merge two smallest weights" structure
- or expected code length / weighted depth is the objective

The strongest smell is:

- "this is an optimal merge tree"

That is exactly this lane.

## Problem-Specific Route

This benchmark does **not** want:

- prefix-feasibility scan reasoning from [Prefix Constraints](../../../../topics/greedy/prefix-constraints/README.md)
- one industrial compression API
- or one mere min-heap demo without the greedy proof

The clean route is:

1. create one leaf per symbol
2. keep the forest in a min-heap ordered by `(weight, minimum original symbol index)`
3. repeatedly merge the two smallest trees
4. accumulate weighted path length through merge sums
5. DFS the final tree to recover one deterministic code per symbol

That is exactly the first Huffman route.

## Core Idea

The key monotone fact is:

- every merge of subtrees with weights `a` and `b` increases the final answer by exactly `a + b`

So the entire optimum can be tracked as:

```text
sum of all merge weights
```

That lets you reason about the objective without carrying all leaf depths by hand at every step.

## Complexity

With `n` symbols:

- build: `O(n log n)`
- recover codes: `O(n)`
- memory: `O(n)`

The point of this benchmark is not to mimic a file compressor.
The point is:

- optimal merge greedy
- deterministic code assignment under ties
- one visible prefix-code tree

## Input / Output Contract For This Repo

This repo's canonical benchmark uses:

- one integer `n`
- one line with `n` positive frequencies

The solution prints:

- first line: minimum weighted path length
- next `n` lines: the code for symbol `i`

Tie policy in this repo:

- heap key is `(subtree weight, minimum original symbol index in the subtree)`
- earlier popped subtree becomes the left child
- if `n = 1`, the printed code is `-` to denote the empty codeword

## Pitfalls / Judge Notes

- The real invariant is the minimum weighted cost, not the prettiness of one code assignment.
- Different valid tie policies can produce different optimal codes.
- This repo fixes one deterministic tie-break so outputs stay stable.
- The lane is about the coding tree, not about bitstream serialization or decompression headers.

## Reusable Pattern

- Topic page: [Huffman / Data Compression](../../../../topics/greedy/huffman-data-compression/README.md)
- Practice ladder: [Huffman / Data Compression ladder](README.md)
- Starter template: [huffman-coding.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/greedy/huffman-coding.cpp)
- Notebook refresher: [Huffman / Data Compression hot sheet](../../../../notebook/huffman-hot-sheet.md)
- Compare points:
  - [Heaps And Ordered Sets](../../../../topics/data-structures/heaps-and-ordered-sets/README.md)
  - [Prefix Constraints](../../../../topics/greedy/prefix-constraints/README.md)

## Solutions

- Code: [huffmancoding.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/greedy/huffman-data-compression/huffmancoding.cpp)
