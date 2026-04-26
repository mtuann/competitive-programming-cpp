# Foundations -> Bit Tricks

Read bits as structure: masks, parity, subset iteration, and the vocabulary that later feeds bitmask DP, xor, and packed-state tricks.

- Topic slug: `foundations/bit-tricks`
- Tutorial page: [Open tutorial](../../../topics/foundations/bit-tricks/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/foundations/bit-tricks/README.md)
- Repo problems currently tagged here: `0`
- Repo companion pages: `2`
- Curated external problems: `2`

## Microtopics

- masks
- popcount
- lowbit
- subset-iteration
- xor
- powers-of-two

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms bit manipulation](https://cp-algorithms.com/algebra/bit-manipulation.html) | `Reference` |
| [cppreference <bit>](https://en.cppreference.com/w/cpp/utility/bit) | `Primary` |
| [Competitive Programmer's Handbook](https://www.cses.fi/book/book.pdf) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Codeforces bitmasks tag](https://codeforces.com/problemset?tags=bitmasks) | `Practice` |
| [CSES Problem Set](https://cses.fi/problemset) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Foundations cheatsheet](../../../notebook/foundations-cheatsheet.md) | `quick reference` |
| [Bit-Parallelism tutorial](../../../topics/dp/bit-parallelism/README.md) | `related tutorial` |

## Curated External Problems

### Warm-Up

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Gray Code](https://cses.fi/problemset/task/2205) | `CSES` | `Easy` | Bit Manipulation | Implementation | Binary Representation; XOR | Gray-Code; Constructive | A compact bitwise-construction problem that makes binary structure feel concrete. |

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Raising Bacteria](https://codeforces.com/problemset/problem/579/A) | `Codeforces` | `Easy` | Bit Manipulation | Implementation | Bit Counting | Popcount; Greedy View | A famous popcount benchmark and a great first reminder that bits can encode structure, not just syntax. |

## Repo Problems

_No repo problem note is attached yet. Use the repo companion material above for this theory/process-heavy topic._

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
