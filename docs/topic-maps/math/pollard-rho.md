# Math -> Pollard-Rho

Factor one 64-bit integer into prime factors with deterministic Miller-Rabin first and Pollard-Rho recursive splitting second.

- Topic slug: `math/pollard-rho`
- Tutorial page: [Open tutorial](../../../topics/math/pollard-rho/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/math/pollard-rho/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `4`
- Curated external problems: `1`

## Microtopics

- pollard-rho
- miller-rabin-64bit
- factorize-u64
- prime-multiset
- recursive-splitting
- sorted-prime-factors

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms integer factorization](https://cp-algorithms.com/algebra/factorization.html) | `Reference` |
| [CP-Algorithms Library Factorize](https://lib.cp-algorithms.com/verify/number_theory/factorize.test.cpp.html) | `Reference` |
| [Library Checker Factorize](https://judge.yosupo.jp/problem/factorize) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Pollard-Rho hot sheet](../../../notebook/pollard-rho-hot-sheet.md) | `quick reference` |
| [Factorize](../../../practice/ladders/math/pollard-rho/factorize.md) | `flagship note` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |
| [Primitive Root](../../../topics/math/primitive-root/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Factorize](https://judge.yosupo.jp/problem/factorize) | `Library Checker` | `Hard` | Integer Factorization | Math; Implementation | Modular Arithmetic; Fast Power; Prime Testing | Miller-Rabin; Prime Factorization; 64-Bit | The cleanest verifier for the repo's exact route: deterministic 64-bit primality plus Pollard-Rho recursive splitting with sorted prime-multiset output. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `FACTORIZE` | Factorize | `primary` | `hard` | - | [Note](../../../practice/ladders/math/pollard-rho/factorize.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/pollard-rho/factorize.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
