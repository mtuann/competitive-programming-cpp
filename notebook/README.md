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
- Geometry -> [Big Brother](../practice/ladders/geometry/half-plane-intersection/bigbrother.md), [Closest Pair](../practice/ladders/geometry/nearest-pair/closestpair.md), [KINGDOMS](../practice/ladders/geometry/sweep-line/kingdoms.md), [PRAVO](../practice/ladders/geometry/right-triangles/pravo.md)

## Current Sheets

- [Foundations cheatsheet](foundations-cheatsheet.md)
- [Data structures cheatsheet](data-structures-cheatsheet.md)
- [Fenwick hot sheet](fenwick-hot-sheet.md)
- [DSU hot sheet](dsu-hot-sheet.md)
- [DSU Rollback hot sheet](dsu-rollback-hot-sheet.md)
- [DSU On Tree hot sheet](dsu-on-tree-hot-sheet.md)
- [Segment Tree hot sheet](segment-tree-hot-sheet.md)
- [Lazy Segment Tree hot sheet](lazy-segment-tree-hot-sheet.md)
- [Segment Tree Beats hot sheet](segment-tree-beats-hot-sheet.md)
- [Persistent Data Structures hot sheet](persistent-data-structures-hot-sheet.md)
- [Persistent Treap hot sheet](persistent-treap-hot-sheet.md)
- [Pairing / Leftist Heap hot sheet](pairing-leftist-heap-hot-sheet.md)
- [Balanced BST hot sheet](balanced-bst-hot-sheet.md)
- [B-Tree hot sheet](b-tree-hot-sheet.md)
- [Skiplist hot sheet](skiplist-hot-sheet.md)
- [X-Fast / Y-Fast hot sheet](x-fast-y-fast-hot-sheet.md)
- [Interval Tree hot sheet](interval-tree-hot-sheet.md)
- [ODT / Chtholly hot sheet](odt-chtholly-hot-sheet.md)
- [Treap / Implicit Treap hot sheet](treap-hot-sheet.md)
- [Wavelet Tree hot sheet](wavelet-tree-hot-sheet.md)
- [Sparse Table hot sheet](sparse-table-hot-sheet.md)
- [Offline Tricks hot sheet](offline-tricks-hot-sheet.md)
- [Mo's hot sheet](mos-hot-sheet.md)
- [Binary Trie hot sheet](binary-trie-hot-sheet.md)
- [Order Statistics Tree hot sheet](order-statistics-tree-hot-sheet.md)
- [Monotonic Stack / Queue hot sheet](monotonic-stack-queue-hot-sheet.md)
- [Splay Tree hot sheet](splay-tree-hot-sheet.md)
- [Graph cheatsheet](graph-cheatsheet.md)
- [Low-Link hot sheet](lowlink-hot-sheet.md)
- [Eulerian hot sheet](eulerian-hot-sheet.md)
- [De Bruijn Sequence hot sheet](de-bruijn-sequence-hot-sheet.md)
- [Two-SAT hot sheet](two-sat-hot-sheet.md)
- [Tree Isomorphism hot sheet](tree-isomorphism-hot-sheet.md)
- [Subtree Queries hot sheet](subtree-queries-hot-sheet.md)
- [Virtual Tree hot sheet](virtual-tree-hot-sheet.md)
- [HLD hot sheet](hld-hot-sheet.md)
- [Centroid Decomposition hot sheet](centroid-hot-sheet.md)
- [Link-Cut Tree hot sheet](link-cut-tree-hot-sheet.md)
- [Euler Tour Tree hot sheet](euler-tour-tree-hot-sheet.md)
- [Shortest Paths hot sheet](shortest-paths-hot-sheet.md)
- [Flow hot sheet](flow-hot-sheet.md)
- [Push-Relabel hot sheet](push-relabel-hot-sheet.md)
- [Global Min-Cut hot sheet](global-min-cut-hot-sheet.md)
- [Gomory-Hu hot sheet](gomory-hu-hot-sheet.md)
- [Flow With Lower Bounds hot sheet](flow-lower-bounds-hot-sheet.md)
- [Min-Cost Flow hot sheet](min-cost-flow-hot-sheet.md)
- [Matching hot sheet](matching-hot-sheet.md)
- [Stable Marriage hot sheet](stable-marriage-hot-sheet.md)
- [Hungarian hot sheet](hungarian-hot-sheet.md)
- [General Matching hot sheet](general-matching-hot-sheet.md)
- [Huffman / Data Compression hot sheet](huffman-hot-sheet.md)
- [Meet-In-The-Middle hot sheet](meet-in-the-middle-hot-sheet.md)
- [DP cheatsheet](dp-cheatsheet.md)
- [SOS DP hot sheet](sos-dp-hot-sheet.md)
- [FWHT / XOR Convolution / Subset Convolution hot sheet](fwht-subset-convolution-hot-sheet.md)
- [Bit-Parallelism / Bitset Optimization hot sheet](bit-parallelism-hot-sheet.md)
- [Broken Profile hot sheet](broken-profile-hot-sheet.md)
- [Divide and Conquer DP hot sheet](divide-and-conquer-dp-hot-sheet.md)
- [Knuth Optimization hot sheet](knuth-optimization-hot-sheet.md)
- [CHT / Li Chao hot sheet](cht-hot-sheet.md)
- [Slope Trick hot sheet](slope-trick-hot-sheet.md)
- [Aliens Trick hot sheet](aliens-trick-hot-sheet.md)
- [Simplex hot sheet](simplex-hot-sheet.md)
- [Matroid Intersection hot sheet](matroid-intersection-hot-sheet.md)
- [Online Algorithms hot sheet](online-algorithms-hot-sheet.md)
- [Machine Learning hot sheet](machine-learning-hot-sheet.md)
- [Gradient Descent hot sheet](gradient-descent-hot-sheet.md)
- [Quantum Algorithms hot sheet](quantum-algorithms-hot-sheet.md)
- [Parallel Algorithms hot sheet](parallel-algorithms-hot-sheet.md)
- [Digit DP hot sheet](digit-dp-hot-sheet.md)
- [Combinatorics cheatsheet](combinatorics-cheatsheet.md)
- [Burnside / Pólya hot sheet](burnside-polya-hot-sheet.md)
- [Linear Recurrence hot sheet](linear-recurrence-hot-sheet.md)
- [Berlekamp-Massey / Kitamasa hot sheet](berlekamp-massey-kitamasa-hot-sheet.md)
- [Gaussian Elimination hot sheet](gaussian-elimination-hot-sheet.md)
- [XOR Basis hot sheet](xor-basis-hot-sheet.md)
- [Sprague-Grundy hot sheet](sprague-grundy-hot-sheet.md)
- [Probability hot sheet](probability-hot-sheet.md)
- [Polynomial / FPS hot sheet](polynomial-fps-hot-sheet.md)
- [Lucas Theorem hot sheet](lucas-hot-sheet.md)
- [Discrete Log hot sheet](discrete-log-hot-sheet.md)
- [Modular Square Root hot sheet](modular-square-root-hot-sheet.md)
- [Primitive Root hot sheet](primitive-root-hot-sheet.md)
- [Pollard-Rho hot sheet](pollard-rho-hot-sheet.md)
- [Mobius hot sheet](mobius-hot-sheet.md)
- [Dirichlet prefix sums hot sheet](dirichlet-prefix-sums-hot-sheet.md)
- [Min_25 / Du Jiao hot sheet](min25-du-jiao-hot-sheet.md)
- [Number theory cheatsheet](number-theory-cheatsheet.md)
- [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md)
- [Chinese Remainder hot sheet](chinese-remainder-hot-sheet.md)
- [String cheatsheet](string-cheatsheet.md)
- [Palindromes hot sheet](palindromes-hot-sheet.md)
- [Eertree hot sheet](eertree-hot-sheet.md)
- [String Hashing hot sheet](string-hashing-hot-sheet.md)
- [Aho-Corasick hot sheet](aho-corasick-hot-sheet.md)
- [Regex / Finite Automata hot sheet](regex-finite-automata-hot-sheet.md)
- [Suffix Tree hot sheet](suffix-tree-hot-sheet.md)
- [Suffix Array / LCP hot sheet](suffix-array-lcp-hot-sheet.md)
- [Geometry cheatsheet](geometry-cheatsheet.md)
- [Half-Plane Intersection hot sheet](half-plane-intersection-hot-sheet.md)
- [Minkowski Sum hot sheet](minkowski-sum-hot-sheet.md)
- [Nearest Pair hot sheet](nearest-pair-hot-sheet.md)
- [Contest checklist](contest-checklist.md)
- [Anti-Hack Workflow](anti-hack-workflow.md)
- [Stress testing workflow](stress-testing-workflow.md)
- [Local judge workflow](local-judge-workflow.md)
- [Many-Valid-Answers / Validator-First Workflow](many-valid-answers-validator-first-workflow.md)
- [Special Judge / Output Protocol Workflow](special-judge-output-protocol-workflow.md)

## Good Pairings

- Fenwick / dynamic prefix counts -> [Fenwick hot sheet](fenwick-hot-sheet.md) + [Data structures cheatsheet](data-structures-cheatsheet.md)
- merge-only components -> [DSU hot sheet](dsu-hot-sheet.md) + [Data structures cheatsheet](data-structures-cheatsheet.md)
- offline add/remove connectivity -> [DSU Rollback hot sheet](dsu-rollback-hot-sheet.md) + [Offline Tricks hot sheet](offline-tricks-hot-sheet.md)
- segment tree under pressure -> [Segment Tree hot sheet](segment-tree-hot-sheet.md) + [Data structures cheatsheet](data-structures-cheatsheet.md)
- online range add + range sum -> [Lazy Segment Tree hot sheet](lazy-segment-tree-hot-sheet.md) + [Segment Tree hot sheet](segment-tree-hot-sheet.md)
- online range `chmin / chmax / add / sum` -> [Segment Tree Beats hot sheet](segment-tree-beats-hot-sheet.md) + [Lazy Segment Tree hot sheet](lazy-segment-tree-hot-sheet.md)
- versioned array queries -> [Persistent Data Structures hot sheet](persistent-data-structures-hot-sheet.md) + [Segment Tree hot sheet](segment-tree-hot-sheet.md)
- versioned split/merge lists -> [Persistent Treap hot sheet](persistent-treap-hot-sheet.md) + [Treap / Implicit Treap hot sheet](treap-hot-sheet.md)
- heaps that must meld online -> [Pairing / Leftist Heap hot sheet](pairing-leftist-heap-hot-sheet.md) + [Data structures cheatsheet](data-structures-cheatsheet.md)
- textbook balanced-BST curiosity / AVL or Red-Black or Scapegoat or SBT compare work -> [Balanced BST hot sheet](balanced-bst-hot-sheet.md) + [Order Statistics Tree hot sheet](order-statistics-tree-hot-sheet.md)
- textbook high-fanout search-tree breadth / split-full-child refresher -> [B-Tree hot sheet](b-tree-hot-sheet.md) + [Balanced BST hot sheet](balanced-bst-hot-sheet.md)
- textbook probabilistic ordered-dictionary breadth -> [Skiplist hot sheet](skiplist-hot-sheet.md) + [Balanced BST hot sheet](balanced-bst-hot-sheet.md)
- bounded-universe predecessor / successor breadth -> [X-Fast / Y-Fast hot sheet](x-fast-y-fast-hot-sheet.md) + [Binary Trie hot sheet](binary-trie-hot-sheet.md)
- dynamic interval overlap queries over one live interval set -> [Interval Tree hot sheet](interval-tree-hot-sheet.md) + [Balanced BST hot sheet](balanced-bst-hot-sheet.md)
- self-adjusting ordered set or a refresher before link-cut tree -> [Splay Tree hot sheet](splay-tree-hot-sheet.md) + [Link-Cut Tree hot sheet](link-cut-tree-hot-sheet.md)
- first-smaller / first-greater boundary scans or fixed-width window extrema -> [Monotonic Stack / Queue hot sheet](monotonic-stack-queue-hot-sheet.md) + [Data structures cheatsheet](data-structures-cheatsheet.md)
- interval partitions that stay viable because assign keeps collapsing runs -> [ODT / Chtholly hot sheet](odt-chtholly-hot-sheet.md) + [Lazy Segment Tree hot sheet](lazy-segment-tree-hot-sheet.md)
- mutable sequence edits by position -> [Treap / Implicit Treap hot sheet](treap-hot-sheet.md) + [Lazy Segment Tree hot sheet](lazy-segment-tree-hot-sheet.md)
- static subarray order statistics -> [Wavelet Tree hot sheet](wavelet-tree-hot-sheet.md) + [Persistent Data Structures hot sheet](persistent-data-structures-hot-sheet.md)
- static idempotent range queries -> [Sparse Table hot sheet](sparse-table-hot-sheet.md) + [Data structures cheatsheet](data-structures-cheatsheet.md)
- reorderable query batches -> [Offline Tricks hot sheet](offline-tricks-hot-sheet.md) + [Data structures cheatsheet](data-structures-cheatsheet.md)
- static range queries with cheap endpoint add/remove -> [Mo's hot sheet](mos-hot-sheet.md) + [Offline Tricks hot sheet](offline-tricks-hot-sheet.md)
- live integer set with maximum xor queries -> [Binary Trie hot sheet](binary-trie-hot-sheet.md) + [Data structures cheatsheet](data-structures-cheatsheet.md)
- live ordered set with online rank / `k`-th queries -> [Order Statistics Tree hot sheet](order-statistics-tree-hot-sheet.md) + [Data structures cheatsheet](data-structures-cheatsheet.md)
- tree path queries -> [HLD hot sheet](hld-hot-sheet.md) + [Graph cheatsheet](graph-cheatsheet.md)
- shortest paths -> [Shortest Paths hot sheet](shortest-paths-hot-sheet.md) + [Graph cheatsheet](graph-cheatsheet.md)
- low-link critical structure -> [Low-Link hot sheet](lowlink-hot-sheet.md) + [Graph cheatsheet](graph-cheatsheet.md)
- use-every-edge-once graph tasks -> [Eulerian hot sheet](eulerian-hot-sheet.md) + [Graph cheatsheet](graph-cheatsheet.md)
- overlap-string construction where every length-`n` window must appear once -> [De Bruijn Sequence hot sheet](de-bruijn-sequence-hot-sheet.md) + [Eulerian hot sheet](eulerian-hot-sheet.md)
- binary clause feasibility -> [Two-SAT hot sheet](two-sat-hot-sheet.md) + [Graph cheatsheet](graph-cheatsheet.md)
- rooted or center-rooted tree shape comparison -> [Tree Isomorphism hot sheet](tree-isomorphism-hot-sheet.md) + [Trees](../topics/graphs/trees/README.md)
- subtree-only tree aggregation -> [Subtree Queries hot sheet](subtree-queries-hot-sheet.md) + [Graph cheatsheet](graph-cheatsheet.md)
- subset-like exact search around `n ≈ 40` -> [Meet-In-The-Middle hot sheet](meet-in-the-middle-hot-sheet.md) + [Complexity And Hardness](../topics/advanced/complexity-and-hardness/README.md)
- marked-subset tree compression -> [Virtual Tree hot sheet](virtual-tree-hot-sheet.md) + [Graph cheatsheet](graph-cheatsheet.md)
- tree problems that want balanced recursive splits -> [Centroid Decomposition hot sheet](centroid-hot-sheet.md) + [Graph cheatsheet](graph-cheatsheet.md)
- dynamic tree path queries -> [Link-Cut Tree hot sheet](link-cut-tree-hot-sheet.md) + [Graph cheatsheet](graph-cheatsheet.md)
- dynamic tree subtree-side queries -> [Euler Tour Tree hot sheet](euler-tour-tree-hot-sheet.md) + [Treap / Implicit Treap hot sheet](treap-hot-sheet.md)
- recover `x` from `a^x ≡ b (mod m)` -> [Discrete Log hot sheet](discrete-log-hot-sheet.md) + [Number Theory cheatsheet](number-theory-cheatsheet.md)
- recover one root from `x^2 ≡ a (mod p)` under one prime modulus -> [Modular Square Root hot sheet](modular-square-root-hot-sheet.md) + [Number Theory cheatsheet](number-theory-cheatsheet.md)
- flow / cuts / transport -> [Flow hot sheet](flow-hot-sheet.md) + [Graph cheatsheet](graph-cheatsheet.md)
- hard plain max-flow benchmark or preflow-engine reopen -> [Push-Relabel hot sheet](push-relabel-hot-sheet.md) + [Flow hot sheet](flow-hot-sheet.md)
- one undirected weighted graph with no designated `s-t`, asking only for the cheapest disconnection cut -> [Global Min-Cut hot sheet](global-min-cut-hot-sheet.md) + [Flow hot sheet](flow-hot-sheet.md)
- many undirected pairwise min-cuts -> [Gomory-Hu hot sheet](gomory-hu-hot-sheet.md) + [Flow hot sheet](flow-hot-sheet.md)
- mandatory lower / upper edge flow bounds -> [Flow With Lower Bounds hot sheet](flow-lower-bounds-hot-sheet.md) + [Flow hot sheet](flow-hot-sheet.md)
- costed transport under capacities -> [Min-Cost Flow hot sheet](min-cost-flow-hot-sheet.md) + [Flow hot sheet](flow-hot-sheet.md)
- bipartite pairing -> [Matching hot sheet](matching-hot-sheet.md) + [Flow hot sheet](flow-hot-sheet.md) when the reduction is ambiguous
- stable one-to-one pairing under strict preferences -> [Stable Marriage hot sheet](stable-marriage-hot-sheet.md) + [Matching hot sheet](matching-hot-sheet.md)
- dense square weighted assignment -> [Hungarian hot sheet](hungarian-hot-sheet.md) + [Matching hot sheet](matching-hot-sheet.md)
- non-bipartite maximum matching -> [General Matching hot sheet](general-matching-hot-sheet.md) + [Matching hot sheet](matching-hot-sheet.md)
- optimal binary prefix-code tree / repeated merge-two-smallest -> [Huffman / Data Compression hot sheet](huffman-hot-sheet.md) + [Greedy](../topics/greedy/README.md)
- digit-counting on large ranges -> [Digit DP hot sheet](digit-dp-hot-sheet.md) + [DP cheatsheet](dp-cheatsheet.md)
- full mask-cube subset/superset aggregates -> [SOS DP hot sheet](sos-dp-hot-sheet.md) + [DP cheatsheet](dp-cheatsheet.md)
- pair-combine two full mask functions under xor, or one exact subset split inside each mask -> [FWHT / XOR Convolution / Subset Convolution hot sheet](fwht-subset-convolution-hot-sheet.md) + [SOS DP hot sheet](sos-dp-hot-sheet.md)
- one huge boolean sum axis or component-size reachability row -> [Bit-Parallelism / Bitset Optimization hot sheet](bit-parallelism-hot-sheet.md) + [Knapsack Family](../topics/dp/knapsack-family/README.md)
- partition DP with monotone split points -> [Divide and Conquer DP hot sheet](divide-and-conquer-dp-hot-sheet.md) + [DP cheatsheet](dp-cheatsheet.md)
- affine DP / online line minimum -> [CHT / Li Chao hot sheet](cht-hot-sheet.md) + [DP cheatsheet](dp-cheatsheet.md)
- convex piecewise-linear position/value DP with hinge penalties -> [Slope Trick hot sheet](slope-trick-hot-sheet.md) + [DP cheatsheet](dp-cheatsheet.md)
- exact-`K` picks / segments via penalty search -> [Aliens Trick hot sheet](aliens-trick-hot-sheet.md) + [DP cheatsheet](dp-cheatsheet.md)
- one small continuous LP in contest max form -> [Simplex hot sheet](simplex-hot-sheet.md) + [Optimization And Duality](../topics/advanced/optimization-and-duality/README.md)
- two independence systems on one explicit ground set -> [Matroid Intersection hot sheet](matroid-intersection-hot-sheet.md) + [Optimization And Duality](../topics/advanced/optimization-and-duality/README.md)
- one first competitive-ratio benchmark with no future knowledge -> [Online Algorithms hot sheet](online-algorithms-hot-sheet.md) + [Randomized Algorithms](../topics/advanced/randomized-algorithms/README.md)
- one linearly separable binary classifier with mistake-driven online updates -> [Machine Learning hot sheet](machine-learning-hot-sheet.md) + [Online Algorithms](../topics/advanced/online-algorithms/README.md)
- one smooth-loss breadth benchmark with deterministic full-batch updates -> [Gradient Descent hot sheet](gradient-descent-hot-sheet.md) + [Machine Learning Algorithms](../topics/advanced/machine-learning-algorithms/README.md)
- one simulator-first quantum breadth benchmark around Hadamard layers and a promise oracle -> [Quantum Algorithms hot sheet](quantum-algorithms-hot-sheet.md) + [FWHT / XOR Convolution / Subset Convolution](../topics/dp/fwht-subset-convolution/README.md)
- one work/span breadth benchmark around Blelloch scan and PRAM-style thinking -> [Parallel Algorithms hot sheet](parallel-algorithms-hot-sheet.md) + [Prefix Sums](../topics/foundations/patterns/prefix-sums/README.md)
- linear systems modulo one prime -> [Gaussian Elimination hot sheet](gaussian-elimination-hot-sheet.md) + [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md)
- linear recurrence under one modulus -> [Linear Recurrence hot sheet](linear-recurrence-hot-sheet.md) + [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md)
- higher-order recurrence jump or recurrence recovery from a prefix -> [Berlekamp-Massey / Kitamasa hot sheet](berlekamp-massey-kitamasa-hot-sheet.md) + [Linear Recurrence hot sheet](linear-recurrence-hot-sheet.md)
- truncated FPS inverse / log / exp under `998244353` -> [Polynomial / FPS hot sheet](polynomial-fps-hot-sheet.md) + [FFT And NTT](../topics/math/fft-ntt/README.md)
- subset xor span / maximum subset xor -> [XOR Basis hot sheet](xor-basis-hot-sheet.md) + [Binary Trie hot sheet](binary-trie-hot-sheet.md) when xor semantics are ambiguous
- impartial normal-play heaps/components -> [Sprague-Grundy hot sheet](sprague-grundy-hot-sheet.md) + [DP cheatsheet](dp-cheatsheet.md)
- finite random processes / exact expectation -> [Probability hot sheet](probability-hot-sheet.md) + [DP cheatsheet](dp-cheatsheet.md)
- small-width grid frontier occupancy -> [Broken Profile hot sheet](broken-profile-hot-sheet.md) + [DP cheatsheet](dp-cheatsheet.md)
- ordered sets / sliding windows -> [Data structures cheatsheet](data-structures-cheatsheet.md)
- modular arithmetic / `nCk` -> [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md) + [Number theory cheatsheet](number-theory-cheatsheet.md)
- symmetry counting up to cyclic rotation -> [Burnside / Pólya hot sheet](burnside-polya-hot-sheet.md) + [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md)
- congruence systems or one inverse under composite modulus -> [Chinese Remainder hot sheet](chinese-remainder-hot-sheet.md) + [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md)
- large `nCk mod p` with `p` prime and small enough for one digit table -> [Lucas Theorem hot sheet](lucas-hot-sheet.md) + [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md)
- gcd/divisor counting over all `d <= MAX` -> [Mobius hot sheet](mobius-hot-sheet.md) + [Number theory cheatsheet](number-theory-cheatsheet.md)
- summatory arithmetic functions that collapse into one divisor-side floor-sum -> [Dirichlet prefix sums hot sheet](dirichlet-prefix-sums-hot-sheet.md) + [Number theory cheatsheet](number-theory-cheatsheet.md)
- implicit prefix sums of `phi` / `mu` on one quotient set `Q_n` -> [Min_25 / Du Jiao hot sheet](min25-du-jiao-hot-sheet.md) + [Number theory cheatsheet](number-theory-cheatsheet.md)
- modular square-root extraction under one prime modulus -> [Modular Square Root hot sheet](modular-square-root-hot-sheet.md) + [Modular Arithmetic hot sheet](modular-arithmetic-hot-sheet.md)
- primitive-root finding under one prime modulus -> [Primitive Root hot sheet](primitive-root-hot-sheet.md) + [Number theory cheatsheet](number-theory-cheatsheet.md)
- 64-bit integer factorization -> [Pollard-Rho hot sheet](pollard-rho-hot-sheet.md) + [Number theory cheatsheet](number-theory-cheatsheet.md)
- one static palindrome scan -> [Palindromes hot sheet](palindromes-hot-sheet.md) + [String cheatsheet](string-cheatsheet.md)
- one append-only distinct-palindrome structure -> [Eertree hot sheet](eertree-hot-sheet.md) + [Palindromes hot sheet](palindromes-hot-sheet.md)
- substring fingerprints -> [String Hashing hot sheet](string-hashing-hot-sheet.md) + [String cheatsheet](string-cheatsheet.md)
- many patterns in one text -> [Aho-Corasick hot sheet](aho-corasick-hot-sheet.md) + [String cheatsheet](string-cheatsheet.md)
- one small regex language matched as an epsilon-NFA -> [Regex / Finite Automata hot sheet](regex-finite-automata-hot-sheet.md) + [String cheatsheet](string-cheatsheet.md)
- one static text as a compressed substring index -> [Suffix Tree hot sheet](suffix-tree-hot-sheet.md) + [String cheatsheet](string-cheatsheet.md)
- exact static suffix structure -> [Suffix Array / LCP hot sheet](suffix-array-lcp-hot-sheet.md) + [String cheatsheet](string-cheatsheet.md)
- polygon and segment geometry -> [Geometry cheatsheet](geometry-cheatsheet.md)
- bounded feasible polygons from directed line constraints -> [Half-Plane Intersection hot sheet](half-plane-intersection-hot-sheet.md) + [Geometry cheatsheet](geometry-cheatsheet.md)
- convex-region addition or scaled point queries after polygon sums -> [Minkowski Sum hot sheet](minkowski-sum-hot-sheet.md) + [Geometry cheatsheet](geometry-cheatsheet.md)
- global nearest distance in one static point set -> [Nearest Pair hot sheet](nearest-pair-hot-sheet.md) + [Geometry cheatsheet](geometry-cheatsheet.md)
- debugging a suspicious implementation -> [Stress testing workflow](stress-testing-workflow.md)
- hack-sensitive constructive or open-hack fragility -> [Anti-Hack Workflow](anti-hack-workflow.md)
- interactive or simulator-style tasks -> [Local judge workflow](local-judge-workflow.md)
- interactive task where the harness exists but the protocol loop still feels fragile -> [Local judge workflow](local-judge-workflow.md) + [Interactive Protocol Clinic 01](../practice/contest-playbooks/interactive-protocol-clinic-01.md)
- many-valid-answers task where the legality contract is still fuzzy -> [Many-Valid-Answers / Validator-First Workflow](many-valid-answers-validator-first-workflow.md)
- predicate-checked batch output or custom-judge legality -> [Special Judge / Output Protocol Workflow](special-judge-output-protocol-workflow.md) + [Local judge workflow](local-judge-workflow.md)

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
