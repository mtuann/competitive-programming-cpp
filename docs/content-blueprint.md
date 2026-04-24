# Content Blueprint

This repository should grow in layers, not as a random pile of solutions.

## What Every Mature Topic Should Ship

Each finished topic should eventually include:

1. a layered, self-contained tutorial page in `topics/`
2. one or more reusable implementations in `templates/` or `solutions/`
3. a small practice ladder in `practice/ladders/`
4. a `go deeper` block with:
   - one `course` link
   - one `reference` link
   - one `practice` link
   - one optional `paper / lecture notes / blog` link

## Writing Rule

Each mature topic page should open with a fast-scanning core path, but the full page should still be complete enough that a serious reader can learn the topic without hunting for another primary explanation.

At minimum, the page should answer:

1. `When do I use this?`
2. `What is the brute-force baseline, and why does it fail?`
3. `Why does the optimized algorithm work?`
4. `What are the important variants and tradeoffs?`
5. `What is the clean implementation pattern?`
6. `What should I solve next?`

Anchor topics should also include:

- one real proof or correctness invariant
- two worked examples
- pseudocode plus implementation notes
- a variant chooser
- practice archetypes with recognition comments

Not every page has the same role:

- `technique leaf`: full deep tutorial for one concrete algorithm or data structure
- `family / chooser page`: a decision map across multiple related algorithms
- `theory-led page`: concept, theorem, or modeling page where code is secondary

The full deep template is the default for `technique leaf` pages. Family and theory-led pages may compress or rearrange sections, but they should still preserve the same teaching promises.

## Build Order

Use `stages` as the progression language across the repo. This file is the maintainer-facing build plan, not a second public taxonomy.

### Stage 0: Foundations

Build first:

- C++ setup and STL patterns
- asymptotic analysis
- proof tools: induction, invariants, exchange arguments
- sorting, binary search, prefix sums, two pointers

Deep links:

- [MIT 6.1210 / 6.1220](https://student.mit.edu/catalog/archive/fall/m6a.html)
- [Stanford CS161](https://cs161-stanford.github.io)
- [CP-Algorithms](https://cp-algorithms.com/)
- [CSES Problem Set](https://cses.fi/)

### Stage 1: Data Structures

Build next:

- DSU
- Fenwick tree
- segment tree
- sparse table
- heaps and ordered sets

Deep links:

- [Princeton COS 226](https://www.cs.princeton.edu/~cos226)
- [MIT 6.1210 / 6.1220](https://student.mit.edu/catalog/archive/fall/m6a.html)
- [USACO Guide](https://usaco.guide/)
- [KACTL](https://github.com/kth-competitive-programming/kactl)

### Stage 2: Graphs

Build next:

- BFS / DFS
- shortest paths
- MST + DSU
- SCC + topological sort
- trees, LCA, rerooting basics
- flow and matching

Deep links:

- [Stanford CS161](https://cs161-stanford.github.io)
- [Cornell CS 4820](https://www.cs.cornell.edu/courses/cs4820/2025sp/syllabus/)
- [ICPC Curriculum](https://curriculum.u.icpc.global/curriculum/)
- [CP-Algorithms](https://cp-algorithms.com/)

### Stage 3: Dynamic Programming and Math

Build next:

- classic state design
- knapsack family
- bitmask DP
- tree DP
- digit DP
- modular arithmetic
- combinatorics
- number theory core

Deep links:

- [Stanford CS161](https://cs161-stanford.github.io)
- [Cornell CS 4820](https://www.cs.cornell.edu/courses/cs4820/2025sp/syllabus/)
- [AtCoder](https://atcoder.jp/)
- [OI Wiki](https://en.oi-wiki.org/)

### Stage 4: Strings and Geometry

Build next:

- hashing
- KMP, Z-function
- trie, Aho-Corasick
- suffix array / automaton
- vectors, orientation, convex hull
- line sweep and intersection basics

Deep links:

- [CP-Algorithms](https://cp-algorithms.com/)
- [OI Wiki](https://en.oi-wiki.org/)
- [ICPC Problem Archive](https://foundation.icpc.global/archive/)
- [KACTL](https://github.com/kth-competitive-programming/kactl)

### Stage 5: Advanced Theory

Build after the core is stable:

- randomized algorithms
- approximation
- LP duality
- spectral / convex ideas
- complexity and hardness
- algorithm engineering

Deep links:

- [MIT Randomized Algorithms](https://courses.csail.mit.edu/6.856/current/)
- [Princeton COS 521](https://www.cs.princeton.edu/~hy2/teaching/fall25-cos521/index.html)
- [Cornell CS 6820](https://www.cs.cornell.edu/courses/cs6820/2025fa/syllabus.html)
- [Berkeley CS174](https://people.eecs.berkeley.edu/~sinclair/cs174/s25.html)

### Stage 6: Contest Engineering

Build continuously:

- notebook standards
- stress testing
- generators
- debugging checklist
- upsolving workflow
- team contest playbook
- contest-track roadmaps

Deep links:

- [ICPC Curriculum](https://curriculum.u.icpc.global/about/)
- [ICPC U](https://u.icpc.global/)
- [USACO Official Training](https://usaco.org/index.php?page=training)
- [KACTL](https://github.com/kth-competitive-programming/kactl)

## Deliverable Shape By Folder

- `topics/`: layered teaching pages with a scannable core path and a deeper tutorial layer
- `templates/`: reusable contest-ready code
- `practice/ladders/`: topic-first problem ladders
- `practice/mixed-rounds/`: review packs that mix topics
- `practice/contest-playbooks/`: contest-specific prep guides
- `notebook/`: curated snippets and team-reference material

## Minimum Viable Standard

Before calling a topic "done", make sure it has:

- one main explanation page
- one clean implementation
- three to ten practice problems
- one `go deeper` block with source links
