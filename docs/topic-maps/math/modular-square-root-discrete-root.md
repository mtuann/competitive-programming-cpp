# Math -> Modular Square Root / Discrete Root

Prime-mod square-root extraction through quadratic-residue tests and Tonelli-Shanks first, with primitive-root and discrete-root machinery kept as the follow-up boundary.

- Topic slug: `math/modular-square-root-discrete-root`
- Tutorial page: [Open tutorial](../../../topics/math/modular-square-root-discrete-root/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/math/modular-square-root-discrete-root/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `4`
- Curated external problems: `2`

## Microtopics

- quadratic-residue
- legendre-symbol
- tonelli-shanks
- modular-square-root
- primitive-root-boundary
- discrete-root-boundary

## Learning Sources

| Source | Type |
| --- | --- |
| [CP-Algorithms Library Sqrt Mod](https://lib.cp-algorithms.com/verify/number_theory/modsqrt.test.cpp.html) | `Reference` |
| [cp-algorithms Discrete Root](https://cp-algorithms.com/algebra/discrete-root.html) | `Reference` |
| [OI Wiki Primitive Root](https://en.oi-wiki.org/math/primitive-root/) | `Reference` |
| [Library Checker Sqrt Mod](https://judge.yosupo.jp/problem/sqrt_mod) | `Practice` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Library Checker K-th Root Mod](https://judge.yosupo.jp/problem/kth_root_mod) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Modular Square Root hot sheet](../../../notebook/modular-square-root-hot-sheet.md) | `quick reference` |
| [Sqrt Mod](../../../practice/ladders/math/modular-square-root-discrete-root/sqrtmod.md) | `flagship note` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |
| [BSGS / Discrete Log](../../../topics/math/bsgs-discrete-log/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Sqrt Mod](https://judge.yosupo.jp/problem/sqrt_mod) | `Library Checker` | `Hard` | Quadratic Residues | Math; Implementation | Modular Arithmetic; Binary Exponentiation; Prime Modulus | Modular Square Root; Tonelli-Shanks; Quadratic Residue; Prime Modulus | The cleanest verifier-style benchmark where the first exact route is just: test quadratic-residue reachability, then recover one root with Tonelli-Shanks. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [K-th Root Mod](https://judge.yosupo.jp/problem/kth_root_mod) | `Library Checker` | `Hard` | Discrete Root | Math; Implementation | Modular Square Root; Discrete Log; Primitive Root | Primitive Root; Bsgs; Linear Congruence In Exponents | The natural follow-up once the square-root lane is trusted and the learner is ready to reduce x^k ≡ a (mod p) to primitive-root and discrete-log machinery. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `SQRTMOD` | Sqrt Mod | `primary` | `hard` | - | [Note](../../../practice/ladders/math/modular-square-root-discrete-root/sqrtmod.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/modular-square-root-discrete-root/sqrtmod.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
