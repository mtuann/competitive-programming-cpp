# Huffman / Data Compression Ladder

This lane is for the first time a greedy problem is really about
**optimal merge trees and weighted code depth**, not about a left-to-right feasibility scan.

## Who This Is For

Use this lane if:

- [Greedy overview](../../../../topics/greedy/README.md) already feels familiar
- heaps do not scare you anymore
- you want the classical Huffman route itself, not one industrial compression format

This lane is intentionally narrow:

- one exact starter
- one flagship note built around a deterministic repo benchmark
- one compare route against [Heaps And Ordered Sets](../../../../topics/data-structures/heaps-and-ordered-sets/README.md)
- one compare route against [Prefix Constraints](../../../../topics/greedy/prefix-constraints/README.md)

## Warm-Up

- explain why every merge increases weighted path length by the merged weight
- explain why the two smallest weights can be merged first in some optimal tree
- explain why multiple code assignments may exist under ties even when the optimal cost is fixed

Target skill:

- recognize when the real lesson is `optimal merge / prefix code`, not `just use a priority queue`

## Core

- min-heap over current subtree weights
- deterministic tie-break for reproducible code assignment
- merge-sum view of the objective
- leaf-depth DFS for explicit codewords
- exact flagship rep: [Huffman Coding Benchmark](huffmancoding.md)

Target skill:

- trust the heap-based Huffman route and know exactly what it does and does not try to cover

## Stretch

- compare against [Prefix Constraints](../../../../topics/greedy/prefix-constraints/README.md) so merge-greedy and scan-greedy stay separate
- compare against [Heaps And Ordered Sets](../../../../topics/data-structures/heaps-and-ordered-sets/README.md) so PQ mechanics and optimality proof do not blur together
- reopen full data-compression context only after the coding tree itself feels automatic

Target skill:

- separate `optimal prefix code construction` from the rest of the repo's greedy family

## Retrieval Layer

- exact quick sheet -> [Huffman / Data Compression hot sheet](../../../../notebook/huffman-hot-sheet.md)
- exact starter -> [huffman-coding.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/greedy/huffman-coding.cpp)
- broader chooser -> [Build Kit](../../../../docs/build-kit.md)
- broader family hub -> [Greedy](../../../../topics/greedy/README.md)

## Repo Anchors And Compare Points

- topic page -> [Huffman / Data Compression](../../../../topics/greedy/huffman-data-compression/README.md)
- flagship note -> [Huffman Coding Benchmark](huffmancoding.md)
- compare point -> [Heaps And Ordered Sets](../../../../topics/data-structures/heaps-and-ordered-sets/README.md)
- compare point -> [Prefix Constraints](../../../../topics/greedy/prefix-constraints/README.md)
- broader routing -> [Greedy ladders](../README.md)

## Exit Criteria

You are ready to move on when:

- you can justify the two-smallest merge step
- you can compute the answer both as merge sums and as weighted leaf depths
- you know why this lane is not a production compression-engine lane

## External Practice

- [Algorithms 4/e - Huffman](https://algs4.cs.princeton.edu/code/javadoc/edu/princeton/cs/algs4/Huffman.html)

## Tutorial Link

- [Huffman / Data Compression](../../../../topics/greedy/huffman-data-compression/README.md)
