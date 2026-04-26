# Book Coverage Roadmap

- Purpose: source-driven roadmap for remaining algorithm and data-structure coverage after the core repo has already become broad
- Scope: gaps and under-covered neighbors surfaced by major books and PDFs, especially when they are not yet full lanes in the repo
- Doc type: planning
- Owner: repo maintainer
- Status: active
- Last reviewed: 2026-04-25
- Update triggers: after any broad book/PDF audit, after any major reprioritization, or when one of the listed source-driven waves ships
- Canonical companion docs: [Roadmap](roadmap.md), [Expansion Roadmap](expansion-roadmap.md), [Algorithm Gap Roadmap](algorithm-gap-roadmap.md), [Freshness Backbone](freshness-backbone.md), [Source Map](source-map.md)

This file exists so the repo can answer a different question than the normal expansion backlog:

- not just "what sounds cool next?"
- but "after checking the major CP books and algorithm texts, what is still missing, thin, or only present as a boundary note?"

The goal is breadth without drift:

- keep the repo aligned with the strongest contest-facing books
- notice textbook-breadth topics that are still worth having
- explicitly mark low-ROI topics so they do not keep resurfacing as accidental TODOs

Shipped since this audit was first drafted:

- [x] `Tree Isomorphism` on `2026-04-25`
- [x] `de Bruijn Sequence / de Bruijn Graph Modeling` on `2026-04-25`
- [x] `Bit-Parallelism / Bitset Optimization` on `2026-04-25`
- [x] `Hungarian / Assignment Problem` on `2026-04-25`
- [x] `Edmonds Blossom / General Matching` on `2026-04-25`
- [x] `Randomized / Global Min-Cut` on `2026-04-25`
- [x] `Burnside / Pólya / Group Actions` on `2026-04-25`
- [x] `Berlekamp-Massey / Kitamasa` on `2026-04-25`
- [x] `FWHT / XOR Convolution / Subset Convolution` on `2026-04-25`
- [x] `Interval Trees` on `2026-04-25`
- [x] `B-Trees` on `2026-04-25`
- [x] `Skip Lists` on `2026-04-25`
- [x] `X-Fast / Y-Fast Tries` on `2026-04-25`
- [x] `Regular Expressions / Finite Automata` on `2026-04-25`
- [x] `Huffman / Data Compression` on `2026-04-25`
- [x] `Online Algorithms` on `2026-04-25`
- [x] `Machine Learning Algorithms` on `2026-04-25`
- [x] `Gradient Descent` on `2026-04-25`
- [x] `Quantum Algorithms` on `2026-04-25`
- [x] `Parallel Algorithms` on `2026-04-25`

## Source Set Reviewed

This roadmap is based on the following public source pages and PDFs checked on `2026-04-25`.

| Source | Kind | Why it matters here |
| --- | --- | --- |
| [Competitive Programmer's Handbook](https://www.cses.fi/book/book.pdf) | free CP PDF | baseline CP canon and classic CSES-flavored topic mix |
| [Guide to Competitive Programming, 3rd ed. (2024)](https://link.springer.com/book/10.1007/978-3-031-61794-2) | current CP textbook | newer advanced-CP synthesis, including explicitly modern topics |
| [Competitive Programming 4 contents](https://cpbook.net/details?cp=4) | CP book companion site | rare-topic radar and practice-heavy classification |
| [Introduction to Algorithms, 4th ed.](https://mitpress.mit.edu/9780262046305/introduction-to-algorithms/) and its [table of contents PDF](https://mitp-content-server.mit.edu/books/content/sectbyfn/books_pres_0/11599/4e_toc.pdf) | flagship algorithms textbook | broad reference for classical algorithms and newer textbook additions |
| [Algorithms by Jeff Erickson](https://jeffe.cs.illinois.edu/teaching/algorithms/index.html) | free modern algorithms textbook + advanced notes | excellent signal for theory-heavy topics that still have practical algorithmic value |
| [Dasgupta, Papadimitriou, Vazirani](https://cseweb.ucsd.edu/~dasgupta/book/) and [TOC PDF](https://cseweb.ucsd.edu/~dasgupta/book/toc.pdf) | free algorithms textbook | compact core + theory-side neighboring topics |
| [Open Data Structures](https://opendatastructures.org/) | free data-structures textbook | best signal for textbook DS families not always hand-coded in CP |
| [Algorithms, 4th ed. by Sedgewick and Wayne](https://sedgewick.io/books/algorithms/) | practical algorithms text | strong breadth signal for data structures, strings, regex, compression, and B-trees |
| [The Algorithm Design Manual](https://link.springer.com/book/978-1-84800-069-8) | practical design text | reinforces design-technique breadth, search, DP, weighted graphs, hard problems |

## Current Repo Synthesis

The repo is already strong on most CP canon:

- tree and dynamic-tree routes like [HLD](../topics/graphs/hld/README.md), [Link-Cut Tree](../topics/graphs/link-cut-tree/README.md), [Euler Tour Tree](../topics/graphs/euler-tour-tree/README.md), [Centroid Decomposition](../topics/graphs/centroid-decomposition/README.md), and [Virtual Tree](../topics/graphs/virtual-tree/README.md)
- advanced DP like [Divide and Conquer DP](../topics/dp/divide-and-conquer-dp/README.md), [Knuth Optimization](../topics/dp/knuth-optimization/README.md), [CHT / Li Chao](../topics/dp/cht-li-chao/README.md), [Slope Trick](../topics/dp/slope-trick/README.md), and [Lagrangian Relaxation](../topics/dp/lagrangian-relaxation/README.md)
- advanced number theory and algebra like [CRT](../topics/math/chinese-remainder/README.md), [Lucas](../topics/math/lucas-theorem/README.md), [Mobius](../topics/math/mobius-multiplicative/README.md), [Dirichlet Prefix Sums](../topics/math/dirichlet-prefix-sums/README.md), [Min_25 / Du Jiao](../topics/math/min25-du-jiao/README.md), [Primitive Root](../topics/math/primitive-root/README.md), and [Pollard-Rho](../topics/math/pollard-rho/README.md)
- deep string coverage like [Suffix Automaton](../topics/strings/suffix-automaton/README.md), [Suffix Tree](../topics/strings/suffix-tree/README.md), [Eertree](../topics/strings/eertree/README.md), [Aho-Corasick](../topics/strings/aho-corasick/README.md), and [Palindromes / Manacher](../topics/strings/palindromes/README.md)
- harder data structures like [Segment Tree Beats](../topics/data-structures/segment-tree-beats/README.md), [Wavelet Tree](../topics/data-structures/wavelet-tree/README.md), [Persistent Treap](../topics/data-structures/persistent-treap/README.md), [DSU Rollback](../topics/data-structures/dsu-rollback/README.md), and [PBDS / Order Statistics Tree](../topics/data-structures/pbds-order-statistics/README.md)

So this roadmap is no longer about filling beginner gaps.

It is about:

- promoting boundary mentions into real lanes when the topic still matters
- adding textbook-breadth topics only when they justify their surface area
- keeping the queue explicit enough that no serious source-backed family is forgotten

## How To Read Priority

### `High`

- appears across multiple checked sources
- or is already a strong boundary inside the repo that now deserves a full lane
- or unlocks multiple neighboring topics

### `Medium`

- source-backed and worthwhile
- but may fit better as a micro-lane, refinement, or sibling under an existing family

### `Low`

- useful for breadth or theory
- but not strong enough to jump ahead of CP-first lanes

## Source-By-Source Gap Matrix

This is the anti-forgetting section: one pass per source family, with the remaining uncovered or thinly covered items called out directly.

### Competitive Programmer's Handbook

Status:

- most of the core handbook is already covered strongly
- the remaining under-covered neighbors are mostly advanced side roads rather than mainline canon

Still worth extracting more explicitly:

- `de Bruijn sequence / de Bruijn graph modeling`
  - status: now shipped as [De Bruijn Sequence](../topics/graphs/de-bruijn-sequence/README.md)
  - benchmark: [CSES - De Bruijn Sequence](https://cses.fi/problemset/task/1692)

### Guide to Competitive Programming (2024)

Status:

- the repo already matches a large fraction of the advanced CP-oriented coverage
- the clearest remaining gap from the book's newer advanced framing is not another tree/data-structure lane, but implementation-driven technique lanes

Still worth extracting more explicitly:

- `bit-parallelism / bitset optimization`
  - status: now shipped as [Bit-Parallelism / Bitset Optimization](../topics/dp/bit-parallelism/README.md)
- `push-relabel` as a refinement under the flow family
  - status: now shipped as an in-family refinement under [Maximum Flow](../topics/graphs/flow/README.md)

### Competitive Programming 4

Status:

- the repo has already shipped many topics CP4 treats as rare: HLD, Li Chao, Lucas, CRT, centroid, Mo, FFT, simplex, matroid intersection, game theory, and more
- CP4 is still the strongest signal for a few remaining contest-rare leaves

Still worth extracting more explicitly:

- `Hungarian / Kuhn-Munkres / assignment problem`
  - status: now shipped as [Hungarian / Assignment Problem](../topics/graphs/hungarian-assignment/README.md)
- `Edmonds blossom / general matching`
  - status: now shipped as [Edmonds Blossom / General Matching](../topics/graphs/general-matching/README.md)
- `Stable Marriage`
  - status: now shipped as [Stable Marriage](../topics/graphs/stable-marriage/README.md)
- `Tree Isomorphism`
  - status: now shipped as [Tree Isomorphism](../topics/graphs/tree-isomorphism/README.md)
- `de Bruijn sequence`
  - status: now shipped as [De Bruijn Sequence](../topics/graphs/de-bruijn-sequence/README.md)
- `Push-Relabel`
  - status: now shipped as an in-family refinement under [Maximum Flow](../topics/graphs/flow/README.md)
- `Gradient descent`
  - status: now shipped as [Gradient Descent](../topics/advanced/gradient-descent/README.md)
  - note: intentionally kept as a narrow breadth lane around fixed-step batch descent on one affine squared-loss benchmark

### CLRS 4th Edition

Status:

- the repo already covers much of the CP-relevant overlap: BSTs, red-black context, DSU, DP, flow, bipartite matching, FFT, number theory, suffix arrays, simplex, LP duality, approximation, and hardness
- the remaining CLRS-shaped gaps are classical but not all equally contest-relevant

Still worth extracting more explicitly:

- `Hungarian / assignment problem`
  - status: now shipped as [Hungarian / Assignment Problem](../topics/graphs/hungarian-assignment/README.md)
- `Stable Marriage`
  - status: now shipped as [Stable Marriage](../topics/graphs/stable-marriage/README.md)
- `Interval Trees`
  - status: now shipped as [Interval Trees](../topics/data-structures/interval-trees/README.md)
  - note: intentionally shipped as a narrow textbook-breadth lane, not as a first-line replacement for the repo's main ordered-set or segment-tree routes
- `B-Trees`
  - status: now shipped as [B-Trees](../topics/data-structures/b-trees/README.md)
  - note: intentionally shipped as a textbook-breadth lane, not as a contest-first ordered-set route
- `Online Algorithms`
  - status: now shipped as [Online Algorithms](../topics/advanced/online-algorithms/README.md)
  - note: intentionally kept as a narrow theory-breadth lane with deterministic ski rental as the exact first route
- `Machine Learning Algorithms`
  - status: now shipped as [Machine Learning Algorithms](../topics/advanced/machine-learning-algorithms/README.md)
  - note: intentionally kept as a narrow breadth lane around perceptron on linearly separable data, not a general ML curriculum

### Jeff Erickson

Status:

- the repo already covers several advanced-note families he highlights: min-cost flow, LP, simplex, matroids, randomized algorithms, suffix structures, DSU, treaps, scapegoat/splay context
- the clearest remaining signal is around min-cut and a few textbook-breadth side topics

Still worth extracting more explicitly:

- `Randomized minimum cut`
  - status: now shipped as the randomized sibling inside [Randomized / Global Min-Cut](../topics/graphs/global-min-cut/README.md)
- `Global min-cut`
  - status: now shipped as [Randomized / Global Min-Cut](../topics/graphs/global-min-cut/README.md)
- `Skip lists`
  - status: now shipped as [Skip Lists](../topics/data-structures/skip-lists/README.md)
  - note: still a breadth lane with lower CP ROI than treap / PBDS / splay

### Dasgupta, Papadimitriou, Vazirani

Status:

- the core divide-and-conquer, graph, greedy, DP, LP, and hardness layers are already well represented in the repo
- the meaningful remaining gap from this book is mostly not CP-first

Still worth tracking:

- `Quantum algorithms`
  - status: now shipped as [Quantum Algorithms](../topics/advanced/quantum-algorithms/README.md)
  - note: intentionally kept as a narrow theory-breadth lane around a classical simulator for the Deutsch-Jozsa promise problem

### Open Data Structures

Status:

- this source mostly reinforces that the repo already covers the CP-relevant BST and meldable-heap families well
- what remains here is mostly textbook data-structure breadth

Still worth extracting more explicitly:

- `Skip List`
  - status: now shipped as [Skip Lists](../topics/data-structures/skip-lists/README.md)
- `B-Tree`
  - status: now shipped as [B-Trees](../topics/data-structures/b-trees/README.md)
- `x-fast trie / y-fast trie`
  - status: now shipped as [X-Fast / Y-Fast Tries](../topics/data-structures/x-fast-y-fast-tries/README.md)

Recommended treatment:

- do not prioritize them ahead of stronger contest-facing gaps
- if opened at all, treat them as a `textbook breadth wave`, not a CP-core wave

### Sedgewick and Wayne

Status:

- many core families are already covered: graphs, strings, suffix arrays, searching, balanced BSTs, flow
- the clearest remaining signals are breadth topics rather than urgent CP gaps

Still worth extracting more explicitly:

- `B-Trees`

Recommended treatment:

- regex has now shipped as the focused micro-lane [Regular Expressions / Finite Automata](../topics/strings/regex-finite-automata/README.md)
- compression has now shipped as the focused micro-lane [Huffman / Data Compression](../topics/greedy/huffman-data-compression/README.md)
- B-trees remain low priority for a contest repo

### The Algorithm Design Manual

Status:

- this source mostly confirms that the repo is already strong on design paradigms, weighted graphs, combinatorial search, DP, and hardness
- it is more of a sanity check than a strong source of new lane obligations at this stage

Remaining value:

- use it to validate sequencing and representative problem choice
- do not open standalone lanes only because this book mentions them

## Full-Lane Candidates Still Worth Shipping

At the moment, this queue is empty.

The last remaining full-lane gap from the current book sweep has now shipped:

- `Randomized / Global Min-Cut`
  - status: now shipped as [Randomized / Global Min-Cut](../topics/graphs/global-min-cut/README.md)

## Micro-Lane Or In-Family Refinement Candidates

These are real topics, but they should usually ship as sibling pages or refinements inside an existing family.

| Topic | Best home | Why not a top-priority standalone wave |
| --- | --- | --- |
| `Push-Relabel` | under [Maximum Flow](../topics/graphs/flow/README.md) | refinement of a family the repo already teaches well |
| `Regular Expressions / finite automata` | now shipped as [Regular Expressions / Finite Automata](../topics/strings/regex-finite-automata/README.md) | breadth-motivated string micro-lane, not a contest-core replacement for literal matchers |
| `Huffman / Data Compression` | now shipped as [Huffman / Data Compression](../topics/greedy/huffman-data-compression/README.md) | breadth-motivated greedy micro-lane, not a contest-core replacement for mainstream string tooling |
| `Online Algorithms` | now shipped as [Online Algorithms](../topics/advanced/online-algorithms/README.md) | theory-breadth lane kept intentionally narrow around deterministic ski rental and competitive analysis |

## Compare-Note / Breadth-Only Candidates

These should stay behind the contest-facing queue unless the repo explicitly decides to broaden into textbook coverage for its own sake.

| Topic | Main supporting source | Recommended treatment |
| --- | --- | --- |
| `Skip List` | `ODS`, `Jeff Erickson` | now shipped as a narrow textbook-breadth lane |
| `x-fast trie / y-fast trie` | `ODS` | now shipped as a narrow textbook-breadth lane |
| `Machine Learning Algorithms` | `CLRS 4e` | now shipped as a narrow breadth lane [Machine Learning Algorithms](../topics/advanced/machine-learning-algorithms/README.md) |
| `Quantum Algorithms` | `Dasgupta et al.` | now shipped as a narrow breadth lane [Quantum Algorithms](../topics/advanced/quantum-algorithms/README.md) |
| `Parallel Algorithms` | `CLRS 4e` | now shipped as a narrow breadth lane [Parallel Algorithms](../topics/advanced/parallel-algorithms/README.md) |
| `Gradient Descent` | `CLRS 4e`, `CP4` mention | now shipped as a narrow breadth lane [Gradient Descent](../topics/advanced/gradient-descent/README.md) |

## Suggested Default Ship Order

This queue tries to maximize:

- contest relevance
- fit with existing repo boundaries
- source coverage breadth
- teaching coherence

### Wave A. Cut-Tree / Cut-Family Completion

- now closed: `Randomized / Global Min-Cut` has shipped as [Randomized / Global Min-Cut](../topics/graphs/global-min-cut/README.md)

### Wave B. Bitwise Algebra / Packed-State Techniques

- all currently identified book-backed gaps in this bucket are now shipped

### Wave C. Rare Modeling Leaves

- all currently identified rare modeling leaves are now shipped

### Wave D. Matching / Flow Refinement Extras

- now closed: `Push-Relabel` has shipped as an in-family refinement under [Maximum Flow](../topics/graphs/flow/README.md)

### Wave F. Textbook Breadth, Only If Wanted

- all currently identified textbook-breadth data-structure gaps in this bucket are now shipped

### Wave G. Theory-Breadth Extras

- now closed: `Online Algorithms` has shipped as [Online Algorithms](../topics/advanced/online-algorithms/README.md)

### Wave H. Out-Of-Scope Unless The Repo Intentionally Broadens

- none currently

## "Do Not Forget" Checklist

Use this checklist before declaring the post-core repo "book-broad enough."

### Must Still Decide Explicitly

- [x] `Hungarian / Assignment Problem`
- [x] `Edmonds Blossom / General Matching`
- [x] `Gomory-Hu Tree`
- [x] `Burnside / Pólya / Group Actions`
- [x] `Berlekamp-Massey / Kitamasa`
- [x] `FWHT / XOR Convolution / Subset Convolution`
- [x] `Bit-Parallelism / Bitset Optimization`

### Should Eventually Resolve One Way Or The Other

- [x] `Tree Isomorphism`
- [x] `de Bruijn Sequence`
- [x] `Stable Marriage`
- [x] `Randomized / Global Min-Cut`
- [x] `Push-Relabel`
- [x] `Interval Trees`

### Low-Priority But Should Not Reappear As "Forgotten"

- [x] `B-Trees`
- [x] `Skip Lists`
- [x] `x-fast / y-fast tries`
- [x] `Regular Expressions / finite automata`
- [x] `Huffman / Data Compression`
- [x] `Online Algorithms`
- [x] `Machine Learning Algorithms`
- [x] `Gradient Descent`
- [x] `Quantum Algorithms`
- [x] `Parallel Algorithms`

## Definition Of Done For One Book-Driven Gap

A topic in this file is not considered resolved just because it appears in an index or as one problem note.

It is resolved only when one of the following is true:

- it becomes a full lane with topic page, starter, hot sheet, ladder route, flagship note, and routing
- it becomes a consciously documented `micro-lane` or `compare-note` under the right parent family
- it is consciously marked `out of scope` with a brief reason in this file or the main roadmap

## Relationship To The Other Roadmaps

- [Algorithm Gap Roadmap](algorithm-gap-roadmap.md) is the main execution backlog
- this file is the `source-completeness audit companion`
- [Expansion Roadmap](expansion-roadmap.md) stays about phased repo growth

So the normal workflow should be:

1. audit large sources into this file
2. promote the best actionable items into [Algorithm Gap Roadmap](algorithm-gap-roadmap.md) or a new wave plan
3. ship them in small waves
4. return here after the next broad audit
