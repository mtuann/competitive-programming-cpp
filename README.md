# cp-cpp

A C++ competitive programming and algorithms hub built to teach theory, implementation, and practice as one system.

This repository is being designed as more than a template dump. The goal is to combine the algorithmic depth of top university syllabi, the problem-solving habits of major contests, and the practicality of the best community learning platforms into one coherent roadmap.

## Quick Links

- [Start Here](#start-here)
- [Learning Model](#learning-model)
- [Progression Ladder](#progression-ladder)
- [Contest Tracks](#contest-tracks)
- [Topic Index](#topic-index)
- [Research Backbone](#research-backbone)
- [Featured References](#featured-references)
- [Repository Map](#repository-map)
- [Roadmap](#roadmap)
- [Contributing](#contributing)

## Start Here

| If you are... | Start with | Goal |
| --- | --- | --- |
| New to competitive programming | `Stage 0 -> Stage 1` in the progression ladder | Build C++ fluency, asymptotics, and basic problem-solving habits |
| Comfortable with data structures but new to contests | `Stage 2 -> Stage 3` | Learn the core CP toolkit: graphs, DP, trees, greedy, prefix techniques |
| Preparing for `USACO` or olympiad-style contests | `Contest Tracks` + `Stage 1 -> Stage 5` | Follow an individual ladder with strong implementation and subtasks mindset |
| Preparing for `ICPC` or team contests | `Contest Tracks` + `Stage 2 -> Stage 6` | Build broad coverage, notebook discipline, and speed under time pressure |
| Contributing tutorials/templates later | `Contributing` + the [source map](docs/source-map.md) | Follow a consistent teaching format and keep the curriculum source-backed |

## What This Repository Will Become

We are aiming for a repository that teaches:

- core algorithms and data structures
- proof ideas, correctness patterns, and complexity analysis
- clean C++ implementations and reusable templates
- topic-based practice ladders and mixed contest drills
- contest strategy for `IOI`, `ICPC`, `USACO`, and olympiad-style tracks

This is intentionally not just a solutions archive and not just a contest notebook. It should eventually work as a syllabus, reference, and training ground at the same time.

## Learning Model

Each mature topic in this repository should eventually follow the same teaching loop:

1. `Intuition`
2. `Recognition cues`
3. `Core idea / proof sketch`
4. `Complexity`
5. `Canonical C++ implementation`
6. `Common mistakes`
7. `Problem ladder`
8. `Related topics`

That structure is deliberate: top courses teach rigor, contests teach pattern recognition, and good CP resources teach fast implementation. We want all three in the same place.

## Progression Ladder

| Stage | Focus | Representative topics | Exit criteria |
| --- | --- | --- | --- |
| `Stage 0` Foundations | Programming + math setup | C++ basics, STL, debugging, recursion, asymptotic notation, proof by induction, counting, modular arithmetic basics | You can write clean solutions for easy implementation and simulation problems without fighting the language |
| `Stage 1` Core Data Structures | Standard tools you should reach for automatically | arrays, strings, sorting, binary search, stacks, queues, linked lists, heaps, hash maps, prefix sums, difference arrays, two pointers | You can solve beginner and early intermediate problems reliably and explain the time complexity |
| `Stage 2` Core Algorithmic Paradigms | The first true CP layer | divide and conquer, greedy algorithms, brute force with pruning, backtracking, basic dynamic programming, BFS, DFS, DSU, trees | You can identify the right paradigm for common problems instead of guessing |
| `Stage 3` Contest-Ready Core | The broad middle of serious CP | shortest paths, MST, topological sort, SCC, tree traversals, Fenwick tree, segment tree, sparse table, rerooting basics, bitmask DP, knapsack family, combinatorics | You can compete comfortably in standard training rounds and upsolve with structure |
| `Stage 4` Advanced Topic Families | Topics that separate strong contestants from casual ones | LCA, heavy-light decomposition, flows, matching, string matching, suffix structures, advanced tree DP, geometry, Möbius-style math, offline queries | You can map unfamiliar problems onto deeper reusable techniques |
| `Stage 5` Advanced Theory and Design | What top syllabi add beyond standard CP lists | randomized algorithms, approximation, LP duality, convex and spectral ideas, complexity, probabilistic method, algorithm engineering | You understand not only what works, but why modern algorithm design looks the way it does |
| `Stage 6` Contest Mastery | Performance under pressure | notebook design, stress testing, debugging workflow, editorial writing, mock contests, upsolving discipline, team communication | You can prepare deliberately for real contests instead of just solving random problems |

## Contest Tracks

| Track | Best for | What it emphasizes | How this repo should respond |
| --- | --- | --- | --- |
| `USACO` | Structured individual progression | Bronze -> Silver -> Gold -> Platinum skill growth, official training, strong implementation habits | Maintain staged ladders, especially for graphs, DP, and mid-level data structures |
| `IOI` / olympiad-style OI | Deep individual problem solving | subtasks, partial scoring, implementation precision, algorithm depth within a syllabus | Write tighter topic pages with stronger proof intuition and harder problem ladders |
| `ICPC` | Team contests and broad coverage | speed, breadth, notebook quality, communication, practical contest engineering | Add notebook-ready templates, mixed drills, and team-focused checklists |
| `NOI` / `APIO` / `CEOI` / `BOI` / `JOI` style training | High-end olympiad preparation | demanding task models, strong C++ execution, broader advanced-topic exposure | Keep advanced sections broad and avoid overfitting only to beginner/interview-style algorithms |

## Topic Index

This root README should stay compact, so the table below is a high-level index rather than a full catalog.

| Area | Representative topics | Theory anchor | Practice anchor | Status |
| --- | --- | --- | --- | --- |
| `Language and STL` | fast I/O, iterators, comparators, templates, policy-based DS, debugging | intro CS + algorithm engineering | AtCoder, beginner USACO, implementation drills | `Planned` |
| `Complexity and Proof Tools` | asymptotics, recurrences, invariants, exchange arguments, induction, amortization | MIT/Stanford/Berkeley foundational algorithm courses | warmup proofs, editorial writeups | `Planned` |
| `Data Structures` | DSU, Fenwick tree, segment tree, sparse table, BSTs, heaps | Princeton COS 226, MIT 6.1210/6.1220 | CSES, Codeforces EDU, USACO Guide | `Planned` |
| `Graph Algorithms` | BFS/DFS, SCC, topological sort, shortest paths, MST, LCA, flows, matching | Stanford CS161, Cornell CS4820/6820, CMU 15-451 | CSES, ICPC archive, USACO, BOI/CEOI style tasks | `Planned` |
| `Dynamic Programming` | 1D/2D DP, knapsack, bitmask DP, tree DP, DP optimization | Stanford CS161, Cornell CS4820, AtCoder DP culture | AtCoder DP, CSES, USACO Guide | `Planned` |
| `Math for CP` | gcd, modular arithmetic, combinatorics, number theory, linear algebra basics, FFT/NTT | MIT 6.1200 + advanced syllabi + olympiad math usage | OI Wiki, CP-Algorithms, harder contest tasks | `Planned` |
| `Strings` | hashing, KMP, Z, trie, suffix array, suffix automaton, Aho-Corasick | CP references + advanced contest training | CSES, OI Wiki, ICPC curriculum topics | `Planned` |
| `Geometry` | vectors, orientation, convex hull, line sweep, circles, half-plane ideas | advanced university electives + CP references | ICPC/AtCoder/OI style geometry sets | `Planned` |
| `Randomized, Optimization, Complexity` | randomized min-cut, LP duality, approximation, spectral methods, hardness | MIT randomized algorithms, Berkeley CS174, Princeton COS521, Cornell CS6820 | advanced ICPC/OI sets and theory-oriented notes | `Planned` |
| `Contest Engineering` | notebook, generators, stress tests, checklist, team roles, upsolving loop | ICPC curriculum + notebook culture | mock contests, archive rounds | `Planned` |

## Research Backbone

This README was designed from a research pass anchored in public official sources dated or current through `April 22, 2026`.

The short version:

- top university syllabi heavily reinforce `graphs`, `dynamic programming`, `flows`, `matchings`, `randomized algorithms`, `approximation`, `optimization`, and `complexity`
- olympiad and contest systems do not all behave the same: `IOI` is the clearest official syllabus, `ICPC` is broader and team-oriented, `USACO` is a staged official progression, and `NOI` has an official but mostly Chinese syllabus
- the best platform mix is not one site doing everything: `USACO Guide` is great for sequencing, `CP-Algorithms` for reference, `CSES` for practice, `AtCoder` for beginner and themed drills, `KACTL` for notebook-quality code, and `ICPC` resources for contest habits

The full source list and rationale live in [docs/source-map.md](docs/source-map.md).

## Featured References

These are the best links to keep attached to the root README. They are intentionally curated; the fuller research set remains in [docs/source-map.md](docs/source-map.md).

### University Syllabi

- [MIT 6.1210 / 6.1220](https://student.mit.edu/catalog/archive/fall/m6a.html)
- [Stanford CS161](https://cs161-stanford.github.io)
- [Berkeley CS170](https://www2.eecs.berkeley.edu/Courses/CS170/index.html)
- [CMU 15-451/651](https://www.cs.cmu.edu/~15451-f25/)
- [Princeton COS 226](https://www.cs.princeton.edu/~cos226)
- [Cornell CS 4820](https://www.cs.cornell.edu/courses/cs4820/2025sp/syllabus/)
- [Cornell CS 6820](https://www.cs.cornell.edu/courses/cs6820/2025fa/syllabus.html)
- [UIUC CS 473](https://courses.grainger.illinois.edu/cs473/)
- [Oxford Design and Analysis of Algorithms](https://www.cs.ox.ac.uk/teaching/courses/2025-2026/algdesign/)

### Official Contest Sources

- [IOI Official Syllabus](https://ioinformatics.org/page/syllabus)
- [ICPC Curriculum Committee](https://curriculum.u.icpc.global/about/)
- [ICPC Problem Archive](https://foundation.icpc.global/archive/)
- [USACO Official Details / FAQ](https://usaco.org/index.php?page=details)
- [USACO Official Training](https://usaco.org/index.php?page=training)
- [NOI China Official Syllabus PDF](https://www.noi.cn/upload/resources/file/2023/03/15/1fa58eac9c412e01ce3c89c761058a43.pdf)
- [HKOI Syllabus](https://hkoi.org/en/competition-syllabus/)

### Practice and Reference Platforms

- [USACO Guide](https://usaco.guide/)
- [CP-Algorithms](https://cp-algorithms.com/)
- [CSES Problem Set](https://cses.fi/)
- [AtCoder](https://atcoder.jp/)
- [Codeforces EDU](https://codeforces.com/edu/courses)
- [KACTL](https://github.com/kth-competitive-programming/kactl)
- [OI Wiki](https://en.oi-wiki.org/)

## Repository Map

The repository is greenfield right now. The structure below is the intended target, not a claim that every directory already exists.

```text
.
├── README.md
├── docs/
│   └── source-map.md
├── topics/
│   ├── foundations/
│   ├── data-structures/
│   ├── graphs/
│   ├── dp/
│   ├── math/
│   ├── strings/
│   ├── geometry/
│   └── advanced/
├── templates/
├── practice/
│   ├── README.md
│   ├── ladders/
│   ├── mixed-rounds/
│   └── contest-playbooks/
└── notebook/
```

## Roadmap

High-value first additions:

- `Foundations`: complexity, STL, binary search, prefix sums, sorting, recursion
- `Graphs`: BFS/DFS, shortest paths, MST, SCC, DSU, LCA
- `Dynamic programming`: classic state design, knapsack family, tree DP, digit DP
- `Math`: modular arithmetic, combinatorics, number theory core
- `Strings`: hashing, KMP, Z-function, trie, suffix array
- `Templates`: DSU, Fenwick tree, segment tree, Dijkstra, MST, flow starter kit
- `Contest playbooks`: USACO ladder, ICPC practice workflow, olympiad-style upsolving checklist

## Contributing

If you add content later, keep it consistent:

- prefer one topic per page and one concept per implementation
- explain `why this works` before showing code
- include complexity and the common failure modes
- keep C++ examples practical and contest-usable
- avoid giant unsorted problem dumps; use progressive ladders
- cite primary sources when a topic is sourced from a course, contest document, or major reference

## Quality Standard

A good tutorial in this repository should help a reader answer four questions quickly:

1. `When should I think of this idea?`
2. `Why is it correct?`
3. `How do I implement it cleanly in C++?`
4. `What should I solve next to make it stick?`

If a page misses one of those, it is not finished yet.
