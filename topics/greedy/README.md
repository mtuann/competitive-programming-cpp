# Greedy

<div class="badge-row" markdown>
  <span class="route-badge route-badge--bridge">Bridge</span>
</div>

Greedy is where you stop asking "can I search all possibilities?" and start asking "what choice can I commit to now without breaking the future?"

## Use This Area When

- every prefix or partial solution must stay feasible
- one local choice looks promising, but only if you can justify it
- the hard part is the invariant or exchange argument, not the implementation itself

## Start With One Route

| If your bottleneck is... | Open first | Then |
| --- | --- | --- |
| feasibility by prefixes | [Prefix Constraints](prefix-constraints/README.md) | the corresponding ladder and one repair-with-heap style note |
| merge-cost or weighted-depth objectives | [Huffman / Data Compression](huffman-data-compression/README.md) | compare against other heap-driven greedy routes |

## Core Progression

1. `Core first`
- sort by the quantity that makes feasibility easiest to state
- write the prefix invariant before writing the loop

2. `Then add`
- repair a broken prefix with a heap or ordered set
- reconstruct a witness, not just the objective value

3. `Later`
- optimal merge trees and weighted-depth objectives
- proof-heavy greedy theory and matroid-flavored extensions

## Good First Repo Anchors

- [Lemonade Line](../../practice/ladders/greedy/prefix-constraints/lemonadeline.md)
- [Prefix Sum Addicts](../../practice/ladders/greedy/prefix-constraints/prefixsumaddicts.md)
- [VODIVIDE](../../practice/ladders/greedy/prefix-constraints/vodivide.md)
- [Huffman Coding Benchmark](../../practice/ladders/greedy/huffman-data-compression/huffmancoding.md)

## Browse All Subtopics

- [Prefix Constraints](prefix-constraints/README.md)
- [Huffman / Data Compression](huffman-data-compression/README.md)

## Go Deeper

- Reference: [OI Wiki - Greedy](https://en.oi-wiki.org/basic/greedy/)
- Reference: [Competitive Programmer's Handbook](https://usaco.guide/CPH.pdf)
- Practice: [Greedy ladders](../../practice/ladders/greedy/README.md)
