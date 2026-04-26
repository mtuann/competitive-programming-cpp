# Huffman / Data Compression Hot Sheet

Use this page when the real question is "build one optimal binary prefix-code tree by repeatedly merging the two lightest subtrees."

## Do Not Use When

- the task is one scan with prefix feasibility or repair -> [Prefix Constraints](../topics/greedy/prefix-constraints/README.md)
- the point is a production compression format, bit packing, or container headers
- the task only needs a priority queue, not a proof of optimal merge structure

## Choose By Signal

- one optimal merge / prefix-code tree from positive frequencies -> `Huffman`
- one heap-backed feasibility repair over ordered input -> `Prefix Constraints`
- one plain priority-queue process without coding-tree semantics -> reopen [Heaps And Ordered Sets](../topics/data-structures/heaps-and-ordered-sets/README.md)

## Core Invariants

- the heap stores the current forest of subtree weights
- every merge increases total weighted path length by exactly `a + b`
- total optimum equals the sum of all merge costs
- one-symbol input needs an explicit empty-code convention

## Main Traps

- confusing code assignment tie policy with the actual optimality invariant
- trying to teach LZW / run-length / file-format details in the first Huffman lane
- forgetting that the objective is weighted depth, not lexicographic prettiness of the codewords

## Exact Starter Route

- exact starter -> [`huffman-coding.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/greedy/huffman-coding.cpp)
- flagship rep -> [Huffman Coding Benchmark](../practice/ladders/greedy/huffman-data-compression/huffmancoding.md)
- compare route -> [Greedy overview](../topics/greedy/README.md)
- compare route -> [Heaps And Ordered Sets](../topics/data-structures/heaps-and-ordered-sets/README.md)

## Reopen Paths

- full lesson -> [Huffman / Data Compression](../topics/greedy/huffman-data-compression/README.md)
- greedy family hub -> [Greedy](../topics/greedy/README.md)
- broader retrieval -> [Build Kit](../docs/build-kit.md)
