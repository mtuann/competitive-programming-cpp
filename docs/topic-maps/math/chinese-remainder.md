# Math -> Chinese Remainder And Linear Congruences

Congruence systems, gcd-consistent residue merges, and the extended-Euclid doorway from linear congruences to one merged class modulo lcm.

- Topic slug: `math/chinese-remainder`
- Tutorial page: [Open tutorial](../../../topics/math/chinese-remainder/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/math/chinese-remainder/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `3`
- Curated external problems: `2`

## Microtopics

- crt-merge
- non-coprime-moduli
- gcd-consistency
- linear-congruence
- bezout-inverse
- lcm-reconstruction

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms Chinese remainder theorem](https://cp-algorithms.com/algebra/chinese-remainder-theorem.html) | `Reference` |
| [cp-algorithms linear congruence equation](https://cp-algorithms.com/algebra/linear_congruence_equation.html) | `Reference` |
| [Competitive Programmer's Handbook](https://usaco.guide/CPH.pdf) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Kattis General Chinese Remainder](https://open.kattis.com/problems/generalchineseremainder) | `Practice` |
| [Library Checker System of Linear Congruence](https://judge.yosupo.jp/problem/system_of_linear_congruence) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Chinese Remainder hot sheet](../../../notebook/chinese-remainder-hot-sheet.md) | `quick reference` |
| [General Chinese Remainder](../../../practice/ladders/math/chinese-remainder/generalchineseremainder.md) | `flagship note` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [General Chinese Remainder](https://open.kattis.com/problems/generalchineseremainder) | `Kattis` | `Medium` | Congruence Systems | Math; Implementation | GCD; Extended Euclid; Modular Arithmetic | Chinese Remainder Theorem; Extended Euclid; Non-Coprime Moduli | The cleanest first rep for non-coprime congruence merges with an explicit no-solution branch. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [System of Linear Congruence](https://judge.yosupo.jp/problem/system_of_linear_congruence) | `Library Checker` | `Medium` | Congruence Systems | Math; Implementation | Extended Euclid; Congruence Merging | Chinese Remainder Theorem; Linear Congruence; Extended Euclid | A direct benchmark for solving and merging full congruence systems after the two-modulus route is trusted. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `GENERALCHINESEREMAINDER` | Chinese Remainder Theorem (non-relatively prime moduli) | `primary` | `medium` | - | [Note](../../../practice/ladders/math/chinese-remainder/generalchineseremainder.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/chinese-remainder/generalchineseremainder.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
