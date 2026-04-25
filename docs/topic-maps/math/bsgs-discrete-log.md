# Math -> BSGS / Discrete Log

Recover the exponent in a^x ≡ b (mod m) with gcd reduction first and baby-step giant-step second, when square-root storage is still contest-safe.

- Topic slug: `math/bsgs-discrete-log`
- Tutorial page: [Open tutorial](../../../topics/math/bsgs-discrete-log/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/math/bsgs-discrete-log/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `4`
- Curated external problems: `2`

## Microtopics

- discrete-log
- baby-step-giant-step
- meet-in-the-middle
- gcd-reduction
- mod-inverse
- minimum-exponent

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms discrete logarithm](https://cp-algorithms.com/algebra/discrete-log.html) | `Reference` |
| [OI Wiki BSGS](https://en.oi-wiki.org/math/bsgs/) | `Reference` |
| [Library Checker Discrete Logarithm Mod](https://judge.yosupo.jp/problem/discrete_logarithm_mod) | `Practice` |

## Practice Sources

| Source | Type |
| --- | --- |
| [LibreOJ #6542](https://loj.ac/p/6542) | `Practice` |
| [Codeforces problemset](https://codeforces.com/problemset) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Discrete Log hot sheet](../../../notebook/discrete-log-hot-sheet.md) | `quick reference` |
| [Discrete Logarithm Mod](../../../practice/ladders/math/bsgs-discrete-log/discretelogarithmmod.md) | `flagship note` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |
| [Chinese Remainder / Linear Congruences](../../../topics/math/chinese-remainder/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Discrete Logarithm Mod](https://judge.yosupo.jp/problem/discrete_logarithm_mod) | `Library Checker` | `Hard` | Discrete Logarithm | Math; Meet-In-The-Middle; Implementation | Modular Arithmetic; Extended Euclid; Square Root Decomposition | Discrete Log; Meet In The Middle; GCD Reduction | The cleanest verifier for the repo's exact route: general discrete log with gcd reduction and a minimum-answer BSGS implementation. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [LibreOJ #6542](https://loj.ac/p/6542) | `LibreOJ` | `Hard` | Discrete Logarithm | Math; Implementation | Bsgs; Modular Arithmetic | Template; Discrete Log | A classic template-style benchmark once the first verifier route is already trusted. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `DISCRETELOGARITHMMOD` | Discrete Logarithm Mod | `primary` | `hard` | - | [Note](../../../practice/ladders/math/bsgs-discrete-log/discretelogarithmmod.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/bsgs-discrete-log/discretelogarithmmod.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
