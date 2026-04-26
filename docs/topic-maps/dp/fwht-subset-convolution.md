# DP -> FWHT / XOR Convolution / Subset Convolution

Boolean-cube transforms beyond plain zeta sweeps, starting with xor convolution via Walsh-Hadamard transform and stretching to subset convolution by popcount layering.

- Topic slug: `dp/fwht-subset-convolution`
- Tutorial page: [Open tutorial](../../../topics/dp/fwht-subset-convolution/README.md)
- Ladder page: [Open ladder](../../../practice/ladders/dp/fwht-subset-convolution/README.md)
- Repo problems currently tagged here: `1`
- Repo companion pages: `5`
- Curated external problems: `2`

## Microtopics

- fwht
- walsh-hadamard
- xor-convolution
- subset-convolution
- boolean-cube-transform
- popcount-layering

## Learning Sources

| Source | Type |
| --- | --- |
| [Competitive Programmer's Handbook](https://www.cses.fi/book/book.pdf) | `Reference` |
| [Guide to Competitive Programming](https://link.springer.com/book/10.1007/978-3-031-61794-2) | `Reference` |
| [Library Checker Bitwise XOR Convolution](https://judge.yosupo.jp/problem/bitwise_xor_convolution) | `Practice` |

## Practice Sources

| Source | Type |
| --- | --- |
| [Library Checker Subset Convolution](https://judge.yosupo.jp/problem/subset_convolution) | `Practice` |

## Repo Companion Material

| Material | Type |
| --- | --- |
| [FWHT / XOR Convolution / Subset Convolution hot sheet](../../../notebook/fwht-subset-convolution-hot-sheet.md) | `quick reference` |
| [Bitwise XOR Convolution note](../../../practice/ladders/dp/fwht-subset-convolution/bitwisexorconvolution.md) | `flagship note` |
| [SOS DP tutorial](../../../topics/dp/sos-dp/README.md) | `compare point` |
| [FFT / NTT tutorial](../../../topics/math/fft-ntt/README.md) | `compare point` |
| [Template Library exact starter route](../../../template-library.md) | `starter route` |

## Curated External Problems

### Core

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Bitwise XOR Convolution](https://judge.yosupo.jp/problem/bitwise_xor_convolution) | `Library Checker` | `Hard` | XOR Convolution, Boolean Cube | Dynamic Programming; Algebra; Implementation | Sos DP; Modular Arithmetic; Power-Of-Two Mask Space | Walsh-Hadamard; Full Cube | The clean first verifier where the entire task is one xor convolution on the full boolean cube and the only intended route is Walsh-Hadamard transform. |

### Stretch

| Problem | Source | Difficulty | Context | Style | Prerequisites | Tags | Why it fits |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Subset Convolution](https://judge.yosupo.jp/problem/subset_convolution) | `Library Checker` | `Hard` | Subset Convolution, Boolean Cube | Dynamic Programming; Algebra; Implementation | Sos DP; Popcount Layering; Modular Arithmetic | Popcount Layers; Zeta Transform; Full Cube | The natural stretch sibling where plain SOS sweeps are no longer enough and the exact subset split must be preserved through popcount-layered transforms. |

## Repo Problems

| Code | Title | Fit | Difficulty | Pattern | Note | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `BITWISEXORCONVOLUTION` | Bitwise XOR Convolution | `primary` | `hard` | - | [Note](../../../practice/ladders/dp/fwht-subset-convolution/bitwisexorconvolution.md) | [Code](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/fwht-subset-convolution/bitwisexorconvolution.cpp) |

## Regeneration

```bash
python3 scripts/generate_problem_catalog.py
```
