# Math -> XOR Basis / Linear Basis

Gaussian elimination over GF(2) for subset-xor span, representability, maximum subset xor, and cycle-space xor reductions.

- Topic slug: `math/xor-basis`
- Tutorial page: [Open tutorial](../../../topics/math/xor-basis/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/math/xor-basis/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `4`
- Curated external problems: `3`

## Microtopics

- xor-basis
- linear-basis
- gf2-elimination
- maximum-subset-xor
- representability
- cycle-space-xor

## Learning Sources

| Source | Type |
| --- | --- |
| [OI Wiki Linear Basis](https://en.oi-wiki.org/math/basis/) | `Reference` |
| [Competitive Programmer's Handbook](https://usaco.guide/CPH.pdf) | `Reference` |
| [Principles of Algorithmic Problem Solving](https://usaco.guide/PAPS.pdf) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [SPOJ XMAX](https://www.spoj.com/problems/XMAX/) | `Practice` |
| [Codeforces 845G](https://codeforces.com/problemset/problem/845/G) | `Practice` |
| [Codeforces 1101G](https://codeforces.com/contest/1101/problem/G) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [XOR Basis hot sheet](../../../notebook/xor-basis-hot-sheet.md) | `quick reference` |
| [XMAX - XOR Maximization](../../../practice/ladders/math/xor-basis/xmax.md) | `flagship note` |
| [XOR Basis starter route](../../../template-library.md) | `starter route` |
| [Binary Trie / XOR Queries](../../../topics/data-structures/binary-trie-xor/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [XMAX - XOR Maximization](https://www.spoj.com/problems/XMAX/) | `SPOJ` | `Medium` | Bitwise Algebra | Math; Implementation | Bitwise Operations; Greedy Elimination; Subset XOR | Linear-Basis; Maximum-Subset-XOR | The cleanest first benchmark where a linear basis replaces brute-force subset xor search entirely. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Shortest Path Problem?](https://codeforces.com/problemset/problem/845/G) | `Codeforces` | `Hard` | Graphs/Cycle XOR, Bitwise Algebra | Graphs; Math | XOR Basis; DFS; Cycle Reasoning | Cycle-Space; Path-XOR | The flagship bridge from subset xor span to graph cycle-space reductions, where each non-tree edge contributes one xor cycle vector. |

### Challenge

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [ZC's School](https://codeforces.com/contest/1101/problem/G) | `Codeforces` | `Hard` | Prefix XOR, Bitwise Algebra | Math; Observation | XOR Basis; Invariant Reasoning | Dimension | A harder compare point where basis dimension over prefix xor values becomes the real invariant instead of direct maximum-subset-xor extraction. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `XMAX` | XOR Maximization | `primary` | `medium` | - | [Note](../../../practice/ladders/math/xor-basis/xmax.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/xor-basis/xmax.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
