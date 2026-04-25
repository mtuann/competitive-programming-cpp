# Math -> Primitive Root

Find one generator of the nonzero residues modulo prime p by factoring p - 1 and rejecting candidates whose reduced-order powers collapse to 1.

- Topic slug: `math/primitive-root`
- Tutorial page: [Open tutorial](../../../topics/math/primitive-root/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/math/primitive-root/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `4`
- Curated external problems: `2`

## Microtopics

- primitive-root
- generator
- cyclic-group-mod-prime
- factor-p-minus-one
- order-test
- discrete-root-boundary

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms primitive root](https://cp-algorithms.com/algebra/primitive-root.html) | `Reference` |
| [OI Wiki Primitive Root](https://en.oi-wiki.org/math/primitive-root/) | `Reference` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Library Checker Primitive Root](https://judge.yosupo.jp/problem/primitive_root) | `Practice` |
| [Library Checker K-th Root Mod](https://judge.yosupo.jp/problem/kth_root_mod) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Primitive Root hot sheet](../../../notebook/primitive-root-hot-sheet.md) | `quick reference` |
| [Primitive Root](../../../practice/ladders/math/primitive-root/primitiveroot.md) | `flagship note` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |
| [BSGS / Discrete Log](../../../topics/math/bsgs-discrete-log/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Primitive Root](https://judge.yosupo.jp/problem/primitive_root) | `Library Checker` | `Hard` | - | Math; Implementation | Modular Arithmetic; Fast Power; Prime Factorization | Generator; Prime Modulus; Factorization | The cleanest verifier for the repo's exact route: factor p - 1, then reject candidate generators whose reduced-order powers collapse to 1. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [K-th Root Mod](https://judge.yosupo.jp/problem/kth_root_mod) | `Library Checker` | `Hard` | Discrete Root | Math; Implementation | Primitive Root; Discrete Log; Modular Arithmetic | Discrete Log; Linear Congruence In Exponents | The natural follow-up once generator finding is trusted and the learner is ready to reduce x^k ≡ a (mod p) to exponent arithmetic. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `PRIMITIVEROOT` | Primitive Root | `primary` | `hard` | - | [Note](../../../practice/ladders/math/primitive-root/primitiveroot.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/primitive-root/primitiveroot.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
