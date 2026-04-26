# Combinatorics -> Burnside / Pólya / Group Actions

Count colorings up to explicit symmetry by averaging fixed representations over a group action, starting with cyclic rotations on necklaces.

- Topic slug: `combinatorics/burnside-polya`
- Tutorial page: [Open tutorial](../../../topics/combinatorics/burnside-polya/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/combinatorics/burnside-polya/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `3`
- Curated external problems: `2`

## Microtopics

- burnside-lemma
- group-actions
- orbit-counting
- fixed-colorings
- cyclic-rotations
- cycle-index

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms Burnside / Pólya](https://cp-algorithms.com/combinatorics/burnside.html) | `Reference` |
| [Competitive Programmer's Handbook](https://www.cses.fi/book/book.pdf) | `Reference` |
| [Guide to Competitive Programming](https://link.springer.com/book/10.1007/978-3-031-61794-2) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Counting Necklaces](https://cses.fi/problemset/task/2209) | `Practice` |
| [CSES Counting Grids](https://cses.fi/problemset/task/2210) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Burnside / Pólya hot sheet](../../../notebook/burnside-polya-hot-sheet.md) | `quick reference` |
| [Modular Arithmetic hot sheet](../../../notebook/modular-arithmetic-hot-sheet.md) | `adjacent sheet` |
| [Counting Basics](../../../topics/combinatorics/counting-basics/README.md) | `prereq topic` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Counting Necklaces](https://cses.fi/problemset/task/2209) | `CSES` | `Hard` | Group Actions, Orbit Counting | Combinatorics; Math | Basic Counting; Modular Exponentiation; GCD | Necklaces; Rotations; Mod Arithmetic | The clean first Burnside problem: cyclic rotations on one n-cycle with a fixed-coloring count of m^gcd(n, r). |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Counting Grids](https://cses.fi/problemset/task/2210) | `CSES` | `Hard` | Rotation Symmetry | Combinatorics; Math | Burnside Lemma; Modular Exponentiation | Grids; Quarter Turns; Mod Arithmetic | The next rep after necklaces: same orbit-counting worldview, but each rotation creates a different cell-cycle structure. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `COUNTINGNECKLACES` | Counting Necklaces | `primary` | `hard` | burnside lemma; rotation symmetry; orbit counting | [Note](../../../practice/ladders/combinatorics/burnside-polya/countingnecklaces.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/combinatorics/burnside-polya/countingnecklaces.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
