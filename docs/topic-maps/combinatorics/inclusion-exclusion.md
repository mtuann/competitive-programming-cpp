# Combinatorics -> Inclusion-Exclusion

Count by overlaps, complements, and Mobius-style corrections when direct counting double-counts structure.

- Topic slug: `combinatorics/inclusion-exclusion`
- Tutorial page: [Open tutorial](../../../topics/combinatorics/inclusion-exclusion/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/combinatorics/inclusion-exclusion/README.md)
- Repo problems currently tagged here: `3`
- Repo companion pages: `0`
- Curated external problems: `6`

## Microtopics

- PIE
- mobius
- subset-enumeration
- complement-counting
- squarefree
- coprime-pairs

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms inclusion-exclusion](https://cp-algorithms.com/combinatorics/inclusion-exclusion.html) | `Reference` |
| [USACO Guide PIE](https://usaco.guide/plat/PIE) | `Reference` |
| [OI Wiki PIE](https://en.oi-wiki.org/math/combinatorics/inclusion-exclusion/) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [CSES Prime Multiples](https://cses.fi/problemset/task/2185/) | `Practice` |
| [USACO Cowpatibility](https://usaco.org/index.php?page=viewproblem2&cpid=862) | `Practice` |
| [CSES Counting Coprime Pairs](https://cses.fi/problemset/task/2417/) | `Practice` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Christmas Party](https://cses.fi/problemset/task/1717) | `CSES` | `Medium` | Derangements | - | - | Fixed Points; Permutations; Mod Arithmetic | A textbook derangement / inclusion-exclusion task. |
| [Prime Multiples](https://cses.fi/problemset/task/2185) | `CSES` | `Medium` | Number Theory, Subset Counting | Math; Enumeration | Inclusion-Exclusion; LCM Reasoning | Multiples; Primes; Prime Set; LCM | Direct inclusion-exclusion over prime subsets. |
| [Counting Coprime Pairs](https://cses.fi/problemset/task/2417) | `CSES` | `Medium-Hard` | Mobius, Mobius Inversion | Number Theory; Sieving | Inclusion-Exclusion; Divisor Counting | Coprime Pairs; GCD 1; Pair Counting; Number Theory | Mobius-inversion version of inclusion-exclusion on gcds. |

### Practice

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Coprime](https://codeforces.com/problemset/problem/1742/D) | `Codeforces` | `Medium` | GCD | Number Theory; Greedy | Pair Reasoning | Coprime; Number Theory | A lighter coprimality exercise that still rewards divisor-set reasoning. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Coprime Subsequences](https://codeforces.com/problemset/problem/803/F) | `Codeforces` | `Hard` | Mobius | Combinatorics; Number Theory | Inclusion-Exclusion; Prime Factorization | Subsequences; Number Theory | A strong advanced example where inclusion-exclusion is the heart of the solution. |

### Cross-Topic

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Counting Necklaces](https://cses.fi/problemset/task/2209) | `CSES` | `Hard` | Burnside, Symmetry Counting | - | - | Orbit Counting; Pólya; Rotations | Not pure IE, but a strong neighboring symmetry-counting problem. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `LAMP` | Dàn đèn màu | `secondary` | `hard` | density formula; pairwise coprime products; big integer fractions | [Note](../../../practice/ladders/math/number-theory-basics/lamp.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/number-theory-basics/lamp.cpp) |
| `PRIMEMULTIPLES` | Prime Multiples | `primary` | `medium` | subset inclusion exclusion; overflow safe lcm product; count divisible numbers | [Note](../../../practice/ladders/combinatorics/inclusion-exclusion/primemultiples.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/combinatorics/inclusion-exclusion/primemultiples.cpp) |
| `VOSFENCE` | Xay hang rao | `secondary` | `hard` | bounded compositions; run decomposition; gap distribution | [Note](../../../practice/ladders/combinatorics/bounded-compositions/vosfence.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/combinatorics/bounded-compositions/vosfence.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
