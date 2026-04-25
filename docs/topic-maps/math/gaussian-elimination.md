# Math -> Gaussian Elimination And Linear Algebra

Solve dense linear systems over one field by pivoting columns, eliminating rows, and reconstructing any valid assignment or detecting inconsistency.

- Topic slug: `math/gaussian-elimination`
- Tutorial page: [Open tutorial](../../../topics/math/gaussian-elimination/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/math/gaussian-elimination/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `4`
- Curated external problems: `2`

## Microtopics

- gaussian-elimination
- augmented-matrix
- pivot-column
- free-variables
- mod-prime-linear-system
- gauss-jordan

## Learning Sources

| Source | Type |
| --- | --- |
| [cp-algorithms Gauss & system of linear equations](https://cp-algorithms.com/linear_algebra/linear-system-gauss.html) | `Reference` |
| [OI Wiki Gaussian elimination](https://en.oi-wiki.org/math/gauss/) | `Reference` |
| [CSES System of Linear Equations](https://cses.fi/problemset/task/3154/) | `Practice` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Library Checker System of Linear Equations](https://judge.yosupo.jp/problem/system_of_linear_equations) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [Gaussian Elimination hot sheet](../../../notebook/gaussian-elimination-hot-sheet.md) | `quick reference` |
| [System of Linear Equations](../../../practice/ladders/math/gaussian-elimination/systemoflinearequations.md) | `flagship note` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |
| [XOR Basis / Linear Basis](../../../topics/math/xor-basis/README.md) | `compare point` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [System of Linear Equations](https://cses.fi/problemset/task/3154/) | `CSES` | `Hard` | Linear Systems | Math; Implementation | Modular Arithmetic; Matrix Modeling; Gaussian Elimination | Linear Algebra; Mod Prime; Free Variables | The cleanest first verifier for the repo's exact route: solve one dense linear system modulo one prime and output any valid assignment. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [System of Linear Equations](https://judge.yosupo.jp/problem/system_of_linear_equations) | `Library Checker` | `Hard` | Linear Systems | Math; Implementation | Gaussian Elimination; Free Variables; Basis Output | Affine Solution Space; Mod Prime | Same elimination worldview, but the output contract is stricter because the full affine solution space must be exposed instead of only one assignment. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `SYSTEMOFLINEAREQUATIONS` | System of Linear Equations | `primary` | `hard` | - | [Note](../../../practice/ladders/math/gaussian-elimination/systemoflinearequations.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/gaussian-elimination/systemoflinearequations.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
