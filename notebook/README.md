# Notebook

This folder is the short-reference layer of the repo.

Use it for:

- notebook-ready snippets
- formulas
- checklist pages
- contest-time reminders

It should stay denser and shorter than `topics/`.

## Quick Split

- `Notebook` = recall the main invariant, signal, or trap fast
- `Template Library` = retrieve the smallest reusable snippet fast
- `Build Kit` = route between notebook, templates, and workflow pages

## Contract

This layer answers one question:

```text
I already mostly know the area. What is the shortest route back to the right invariant, trap, and reusable snippet?
```

Every mature cheatsheet should bias toward:

- `Use when`
- `Do not use when`
- `Choose by signal`
- one or two core invariants
- one or two main traps
- direct jumps to topic pages, templates, and repo notes

It should not try to reteach the full topic. If you need proofs or slower walkthroughs, jump back to `topics/`.

## Use This Layer When

- the area is mostly known, but retrieval feels slow
- you want the lightest viable template family quickly
- you need the main invariant or failure mode under contest pressure
- you want one nearby repo note to reopen, not a long tutorial

## Do Not Use This Layer When

- you are learning the topic for the first time
- you still do not know the brute-force baseline
- you cannot yet explain why the main technique works
- the problem needs a slower decision page more than a compact reminder

## Fast Retrieval Loop

When you are mid-problem and want the shortest route back to something reusable:

1. open the relevant cheatsheet for the family
2. pick a template or invariant from there
3. jump back into the topic page only if you need proof, pitfalls, or a slower explanation

This is meant to be the layer you skim during implementation, not the layer you study first.

## Sheet Contract In Practice

The shortest useful scan order is:

1. `Use when`
2. `Do not use when`
3. `Choose by signal`
4. `Invariant / trap`
5. one template or repo anchor

## Representative Anchors

- Data structures -> [CVP00001](../practice/ladders/data-structures/fenwick-tree/cvp00001.md)
- Graphs -> [QOS](../practice/ladders/graphs/shortest-paths/qos.md), [MINCOST](../practice/ladders/graphs/flow/mincost.md)
- DP -> [TFIELD](../practice/ladders/dp/sliding-window/tfield.md)
- Number theory -> [CRYPTKEY](../practice/ladders/math/gcd-lcm/cryptkey.md)
- Geometry -> [KINGDOMS](../practice/ladders/geometry/sweep-line/kingdoms.md), [PRAVO](../practice/ladders/geometry/right-triangles/pravo.md)

## Current Sheets

- [Foundations cheatsheet](foundations-cheatsheet.md)
- [Data structures cheatsheet](data-structures-cheatsheet.md)
- [Fenwick hot sheet](fenwick-hot-sheet.md)
- [DSU hot sheet](dsu-hot-sheet.md)
- [DSU Rollback hot sheet](dsu-rollback-hot-sheet.md)
- [Segment Tree hot sheet](segment-tree-hot-sheet.md)
- [Lazy Segment Tree hot sheet](lazy-segment-tree-hot-sheet.md)
- [Persistent Data Structures hot sheet](persistent-data-structures-hot-sheet.md)
- [Sparse Table hot sheet](sparse-table-hot-sheet.md)
- [Offline Tricks hot sheet](offline-tricks-hot-sheet.md)
- [Graph cheatsheet](graph-cheatsheet.md)
- [Low-Link hot sheet](lowlink-hot-sheet.md)
- [Two-SAT hot sheet](two-sat-hot-sheet.md)
- [Subtree Queries hot sheet](subtree-queries-hot-sheet.md)
- [HLD hot sheet](hld-hot-sheet.md)
- [Centroid Decomposition hot sheet](centroid-hot-sheet.md)
- [Shortest Paths hot sheet](shortest-paths-hot-sheet.md)
- [Flow hot sheet](flow-hot-sheet.md)
- [Min-Cost Flow hot sheet](min-cost-flow-hot-sheet.md)
- [Matching hot sheet](matching-hot-sheet.md)
- [DP cheatsheet](dp-cheatsheet.md)
- [CHT / Li Chao hot sheet](cht-hot-sheet.md)
- [Digit DP hot sheet](digit-dp-hot-sheet.md)
- [Combinatorics cheatsheet](combinatorics-cheatsheet.md)
- [Linear Recurrence hot sheet](linear-recurrence-hot-sheet.md)
- [Number theory cheatsheet](number-theory-cheatsheet.md)
- [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md)
- [Chinese Remainder hot sheet](chinese-remainder-hot-sheet.md)
- [String cheatsheet](string-cheatsheet.md)
- [Palindromes hot sheet](palindromes-hot-sheet.md)
- [String Hashing hot sheet](string-hashing-hot-sheet.md)
- [Aho-Corasick hot sheet](aho-corasick-hot-sheet.md)
- [Suffix Array / LCP hot sheet](suffix-array-lcp-hot-sheet.md)
- [Geometry cheatsheet](geometry-cheatsheet.md)
- [Contest checklist](contest-checklist.md)
- [Anti-Hack Workflow](anti-hack-workflow.md)
- [Stress testing workflow](stress-testing-workflow.md)
- [Local judge workflow](local-judge-workflow.md)

## Good Pairings

- Fenwick / dynamic prefix counts -> [Fenwick hot sheet](fenwick-hot-sheet.md) + [Data structures cheatsheet](data-structures-cheatsheet.md)
- merge-only components -> [DSU hot sheet](dsu-hot-sheet.md) + [Data structures cheatsheet](data-structures-cheatsheet.md)
- offline add/remove connectivity -> [DSU Rollback hot sheet](dsu-rollback-hot-sheet.md) + [Offline Tricks hot sheet](offline-tricks-hot-sheet.md)
- segment tree under pressure -> [Segment Tree hot sheet](segment-tree-hot-sheet.md) + [Data structures cheatsheet](data-structures-cheatsheet.md)
- online range add + range sum -> [Lazy Segment Tree hot sheet](lazy-segment-tree-hot-sheet.md) + [Segment Tree hot sheet](segment-tree-hot-sheet.md)
- versioned array queries -> [Persistent Data Structures hot sheet](persistent-data-structures-hot-sheet.md) + [Segment Tree hot sheet](segment-tree-hot-sheet.md)
- static idempotent range queries -> [Sparse Table hot sheet](sparse-table-hot-sheet.md) + [Data structures cheatsheet](data-structures-cheatsheet.md)
- reorderable query batches -> [Offline Tricks hot sheet](offline-tricks-hot-sheet.md) + [Data structures cheatsheet](data-structures-cheatsheet.md)
- tree path queries -> [HLD hot sheet](hld-hot-sheet.md) + [Graph cheatsheet](graph-cheatsheet.md)
- shortest paths -> [Shortest Paths hot sheet](shortest-paths-hot-sheet.md) + [Graph cheatsheet](graph-cheatsheet.md)
- low-link critical structure -> [Low-Link hot sheet](lowlink-hot-sheet.md) + [Graph cheatsheet](graph-cheatsheet.md)
- binary clause feasibility -> [Two-SAT hot sheet](two-sat-hot-sheet.md) + [Graph cheatsheet](graph-cheatsheet.md)
- subtree-only tree aggregation -> [Subtree Queries hot sheet](subtree-queries-hot-sheet.md) + [Graph cheatsheet](graph-cheatsheet.md)
- tree problems that want balanced recursive splits -> [Centroid Decomposition hot sheet](centroid-hot-sheet.md) + [Graph cheatsheet](graph-cheatsheet.md)
- flow / cuts / transport -> [Flow hot sheet](flow-hot-sheet.md) + [Graph cheatsheet](graph-cheatsheet.md)
- costed transport under capacities -> [Min-Cost Flow hot sheet](min-cost-flow-hot-sheet.md) + [Flow hot sheet](flow-hot-sheet.md)
- bipartite pairing -> [Matching hot sheet](matching-hot-sheet.md) + [Flow hot sheet](flow-hot-sheet.md) when the reduction is ambiguous
- digit-counting on large ranges -> [Digit DP hot sheet](digit-dp-hot-sheet.md) + [DP cheatsheet](dp-cheatsheet.md)
- affine DP / online line minimum -> [CHT / Li Chao hot sheet](cht-hot-sheet.md) + [DP cheatsheet](dp-cheatsheet.md)
- linear recurrence under one modulus -> [Linear Recurrence hot sheet](linear-recurrence-hot-sheet.md) + [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md)
- ordered sets / sliding windows -> [Data structures cheatsheet](data-structures-cheatsheet.md)
- modular arithmetic / `nCk` -> [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md) + [Number theory cheatsheet](number-theory-cheatsheet.md)
- congruence systems or one inverse under composite modulus -> [Chinese Remainder hot sheet](chinese-remainder-hot-sheet.md) + [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md)
- one static palindrome scan -> [Palindromes hot sheet](palindromes-hot-sheet.md) + [String cheatsheet](string-cheatsheet.md)
- substring fingerprints -> [String Hashing hot sheet](string-hashing-hot-sheet.md) + [String cheatsheet](string-cheatsheet.md)
- many patterns in one text -> [Aho-Corasick hot sheet](aho-corasick-hot-sheet.md) + [String cheatsheet](string-cheatsheet.md)
- exact static suffix structure -> [Suffix Array / LCP hot sheet](suffix-array-lcp-hot-sheet.md) + [String cheatsheet](string-cheatsheet.md)
- polygon and segment geometry -> [Geometry cheatsheet](geometry-cheatsheet.md)
- debugging a suspicious implementation -> [Stress testing workflow](stress-testing-workflow.md)
- hack-sensitive constructive or open-hack fragility -> [Anti-Hack Workflow](anti-hack-workflow.md)
- interactive or validator-heavy tasks -> [Local judge workflow](local-judge-workflow.md)

## Learn -> Practice -> Retrieve

Use this layer as the `Retrieve` step, not the first step:

| If you need... | Open first | Then |
| --- | --- | --- |
| proof or slower explanation | [Topics](../topics/README.md) | come back here after the idea is trusted |
| a concrete next problem | [Problem Finder](../docs/problem-finder.md) | then reopen the relevant sheet |
| a pasteable snippet | [Build Kit](../docs/build-kit.md) | then the relevant template |

## Reopen Rules

- if you need proofs, go to `topics/`
- if you need a pasteable skeleton, go to [Template library](../template-library.md)
- if you need the exact next problem or next short set, go to [Problem Finder](../docs/problem-finder.md)
