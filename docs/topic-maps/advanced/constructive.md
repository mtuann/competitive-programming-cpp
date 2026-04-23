# Advanced -> Constructive

Output-sensitive problems where the main work is proving the existence and structure of a valid construction.

- Topic slug: `advanced/constructive`
- Tutorial page: [Open tutorial](../../../topics/advanced/constructive/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/advanced/constructive/README.md)
- Repo problems currently tagged here: `2`
- Curated external problems: `10`

## Microtopics

- invariants
- parity-constructions
- extremal-arguments
- witness-building
- greedy-construction
- output-sensitive-construction
- case-splits
- existence-proofs

## Learning Sources

| Source | Type |
| --- | --- |
| [IOI Syllabus 2025](https://ioinformatics.org/files/ioi-syllabus-2025.pdf) | `official curriculum` |
| [Tips on Constructive Algorithms](https://codeforces.com/blog/entry/80317) | `trusted tutorial` |
| [CSES books](https://www.cses.fi/book/index.html) | `reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Codeforces constructive algorithms tag](https://codeforces.com/problemset?locale=en&tags=constructive+algorithms) | `problem set` |
| [CSES Problem Set](https://cses.fi/problemset/) | `problem set` |
| [BOI task archive](https://boi.cses.fi/tasks.php) | `contest archive` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Same Parity Summands](https://codeforces.com/problemset/problem/1352/B) | `Codeforces` | `Easy` | - | Construction | Parity | Math | Simple but very clean constructive decomposition logic. |
| [Snow Walking Robot](https://codeforces.com/problemset/problem/1272/B) | `Codeforces` | `Easy` | - | Path Construction | Grid Moves; Cancellation | Paths; Grid | A short constructive path-building problem with neat cancellation ideas. |
| [A-B Palindrome](https://codeforces.com/problemset/problem/1512/C) | `Codeforces` | `Medium` | - | Construction | Symmetry Reasoning | Palindrome | A standard constructive palindrome filling task. |
| [Build the Permutation](https://codeforces.com/problemset/problem/1608/B) | `Codeforces` | `Medium` | - | Greedy Construction | Permutations; Greedy Placement | Permutations | Build-a-valid-structure problems are exactly the constructive sweet spot. |
| [Corrupted Array](https://codeforces.com/problemset/problem/1512/D) | `Codeforces` | `Medium` | - | Reconstruction | Sorting; Multiset Reasoning | Arrays | A good example of reconstructing hidden structure from noisy data. |
| [Beautiful Tree](https://codeforces.com/problemset/problem/2162/G) | `Codeforces` | `Hard` | - | - | - | Tree Construction; Number Theory; Perfect Square | Shows how a constructive proof can be turned into a valid graph output under strong arithmetic constraints. |
| [Multiples and Power Differences](https://codeforces.com/problemset/problem/1485/D) | `Codeforces` | `Hard` | - | - | - | Matrix Construction; Number Theory; Invariants | Classic constructive use of a hidden invariant to force the judge-accepted structure. |
| [Nezzar and Nice Beatmap](https://codeforces.com/problemset/problem/1477/C) | `Codeforces` | `Hard` | - | - | - | Ordering; Geometry; Greedy Construction | Representative output-construction problem where the hard part is discovering the structure, not maintaining data. |
| [Strange Housing](https://codeforces.com/problemset/problem/1470/D) | `Codeforces` | `Hard` | - | - | - | Graph Construction; DFS | Good example of mixing traversal with a constructive certificate. |
| [Cycle Closing](https://codeforces.com/problemset/problem/2150/F) | `Codeforces` | `Very Hard` | - | - | - | Graph Operations; Shortest Paths; Tree Structure | A high-end constructive problem where the implementation follows a delicate existence argument. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `VMCOINS` | Trò chơi với những đồng xu | `primary` | `hard` | promise-driven constructive; translation matching; small residual search | [Note](../../../practice/ladders/advanced/constructive/vmcoins.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/constructive/vmcoins.cpp) |
| `VMMARBLE` | Phân loại bi | `secondary` | `medium` | final-color assignment; residual-state dp; capacity-2 moves | [Note](../../../practice/ladders/dp/bitmask-dp/vmmarble.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/bitmask-dp/vmmarble.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
