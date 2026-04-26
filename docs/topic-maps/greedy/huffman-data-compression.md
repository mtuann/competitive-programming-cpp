# Greedy -> Huffman / Data Compression

Binary Huffman coding as an optimal-merge greedy lane: repeatedly merge the two lightest trees, track weighted path length by merge sums, and recover deterministic prefix codes.

- Topic slug: `greedy/huffman-data-compression`
- Tutorial page: [Open tutorial](../../../topics/greedy/huffman-data-compression/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/greedy/huffman-data-compression/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `1`

## Microtopics

- optimal-merge
- prefix-codes
- weighted-path-length
- min-heap-greedy
- deterministic-tie-break
- codeword-reconstruction

## Learning Sources

| Source | Type |
| --- | --- |
| [Algorithms 4/e Huffman](https://algs4.cs.princeton.edu/code/javadoc/edu/princeton/cs/algs4/Huffman.html) | `Course` |
| [Algorithms 4/e data compression slides](https://algs4.cs.princeton.edu/lectures/keynote/55DataCompression.pdf) | `Course` |
| [Cornell CS312 heaps and Huffman coding](https://www.cs.cornell.edu/courses/cs312/2002sp/lectures/lec19.asp) | `Course` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Huffman / Data Compression hot sheet](../../../notebook/huffman-hot-sheet.md) | `quick reference` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |
| [Huffman Coding Benchmark note](../../../practice/ladders/greedy/huffman-data-compression/huffmancoding.md) | `anchor note` |
| [Greedy overview](../../../topics/greedy/README.md) | `family hub` |
| [Heaps And Ordered Sets](../../../topics/data-structures/heaps-and-ordered-sets/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Huffman Coding Benchmark](https://algs4.cs.princeton.edu/code/javadoc/edu/princeton/cs/algs4/Huffman.html) | `Algorithms 4/e` | `Medium` | Data-Compression, Prefix-Codes | Heap Greedy; Tree Construction | Priority Queue; Weighted Merge Cost; Prefix Code | Optimal Merge; Min-Heap; Weighted Path Length | Canonical textbook benchmark where the whole lesson is the two-smallest merge greedy, not a production compression container. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `HUFFMANCODING` | Huffman Coding Benchmark | `primary` | `medium` | - | [Note](../../../practice/ladders/greedy/huffman-data-compression/huffmancoding.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/greedy/huffman-data-compression/huffmancoding.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
